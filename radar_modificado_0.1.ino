const int pinBoton = 2; 
const int pinEjeY = A0; 
const int pinEjeX = A1; 

const int pinLed1 = 3;
const int pinLed2 = 5;
const int pinLed3 = 7;
const int pinAltavoz = 4;

int valorEjeX = 0;
int valorEjeY = 0;
int estadoBoton = 0;
int frecuenciaNota = 440; 
int duracionSonido = 250;
int xObjetivo = 0;
int yObjetivo = 0;
int intervalo = 2000;
bool ejecutarSonido = false;
unsigned long tiempoActual = 0;
unsigned long tiempoAnterior = 0;
int frecuenciasMelodia[] = {
  262, 196, 196, 220, 196, 0, 247, 262
};

int duracionDeNotas[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};
void setup() {
//inicializaciones
  pinMode(pinBoton, INPUT);
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);
  digitalWrite(pinBoton, HIGH);
  Serial.begin(9600);
    iniciarDatosAleatorios();
} //llave del setup
 /*
 * Esta función crea el punto objetivo del juego
 */
void iniciarDatosAleatorios() {

 // Si no ponemos esta línea siempre empieza con los mismos valores
  randomSeed(analogRead(A2));
  
  xObjetivo = random(1023);
  yObjetivo = random(1023);
  Serial.println("Nuevas coordenadas");
  Serial.print("Eje X: ");
  Serial.println(xObjetivo);
  Serial.print("Eje Y: ");
  Serial.println(yObjetivo);

  
}
void loop() {
  leerDatos();
  procesarDatos();
  ejecutarSonidosYLuces();

}
/*
 * Esta función sólo lee datos y los guarda en variables. 
 */
void leerDatos() {
  valorEjeX = analogRead(pinEjeX);
  valorEjeY = analogRead(pinEjeY);
  estadoBoton = digitalRead(pinBoton);
  tiempoActual = millis();
} 
/*
 * Esta función procesa los datos leídos y cambia las variables para la ejecución de sonidos. 
 */
void procesarDatos() {
  // distancia entre dos puntos de coordenadas X Y 
  
  long distanciaX = valorEjeX - xObjetivo;
  Serial.print("Distancia en el eje X: ");
  Serial.println(distanciaX);
  long distanciaY = valorEjeY - yObjetivo;
  Serial.print("Distancia en el eje Y: ");
  Serial.println(distanciaY);
  //esto es la raiz cuadrada de la suma de los cuadrados de diferencia. 
  long distanciaReal = sqrt(sq(distanciaX)+sq(distanciaY));
  Serial.print("Distancia: ");
  Serial.println(distanciaReal);

  if (distanciaX>0){
     digitalWrite(pinLed2,HIGH);
     digitalWrite(pinLed3,LOW);
  }
else{
  digitalWrite(pinLed2,LOW);
     digitalWrite(pinLed3,HIGH);
}
  if (distanciaReal >= 1000)
  {
    intervalo = 2000;
  }
  else if (distanciaReal >= 800 && distanciaReal < 1000) {
    intervalo = 1500;
  }
  else if (distanciaReal >= 600 && distanciaReal < 800) {
    intervalo = 1000;
  } 
  else if (distanciaReal >= 400 && distanciaReal < 600) {
    intervalo = 750;
  }
  else if (distanciaReal >= 200 && distanciaReal < 400) {
    intervalo = 500;
  } 
  else if (distanciaReal >= 120 && distanciaReal < 200) {
    intervalo = 750;
  }
  else if (distanciaReal >= 75 && distanciaReal < 120) {
    intervalo = 250;
  } 
  else if (distanciaReal >= 50 && distanciaReal < 75) {
    intervalo = 100;
  } 
  else { // con menos de 50 de distancia considero que ya se ha acertado el punto
    secuenciaFinal();
  }
} 
/*
 * Esta función en función de las variables anteriores enciende el led y activa el led 
 */
void ejecutarSonidosYLuces() {
  if (tiempoActual - tiempoAnterior >= intervalo) {
     tiempoAnterior = tiempoActual;
     ejecutarSonido = !ejecutarSonido;
     if (ejecutarSonido) {
      tone(pinAltavoz, frecuenciaNota, duracionSonido);
      digitalWrite(pinLed1,HIGH);
     }
     else {
      noTone(pinAltavoz);
      digitalWrite(pinLed1,LOW);
     }
  }
}
/*
 * Esta función toca una melodía y vuelve a iniciar las coordenadas.  
 */
void secuenciaFinal() {
  
  for (int estaNota = 0; estaNota < 8; estaNota++) {


    int duracionNota = 1000 / duracionDeNotas[estaNota];
    tone(pinAltavoz, frecuenciasMelodia[estaNota], duracionNota);
    digitalWrite(pinLed1,LOW);
    int pausaEntreNotas = duracionNota * 1.30;
    delay(pausaEntreNotas);
    digitalWrite(pinLed1,HIGH);
    noTone(pinAltavoz);
  }
  iniciarDatosAleatorios();
}
