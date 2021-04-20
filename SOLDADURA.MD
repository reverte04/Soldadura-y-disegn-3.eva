# SOLDADURA REVERTE

## Primer contacto (desoldar circutos y soldar)

Hoy hemos empezado a soldar y la verdad que me a gustado bastante, lo unico que se me a hecho conplicado el final ya que el soldador era basico y tardava en calentar


## Desmontaje ordenador

## Circuito de prueba 



![CIRCUITO DE PRUEBA](https://github.com/reverte04/Soldadura-y-disegn-3.eva/blob/main/TUMADRE.jpeg) Hemos hecho este circuito de prueba para despues soldarlo a parte, es un led con boton que se enchega automaticamente y si pulsas el boton se apaga.

el codigo es:

``` C++
const int LED=13;
const int BOTON=7;
int val;
void setup(){
pinMode(LED,OUTPUT);
pinMode(BOTON,INPUT);
}
void loop(){
val=digitalRead(BOTON);
if  (val==HIGH){
digitalWrite(LED,HIGH);
}
else { digitalWrite(LED,LOW);
}
}
```
