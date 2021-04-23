# SOLDADURA REVERTE

## Primer contacto (desoldar circutos y soldar)

Hoy hemos empezado a soldar y la verdad que me a gustado bastante, lo unico que se me a hecho conplicado el final ya que el soldador era basico y tardava en calentar


## Desmontaje ordenador

[Enlace al sitio donde lo explico](https://github.com/reverte04/Soldadura-y-disegn-3.eva/blob/main/PC%20CONFIG.MD)

![](https://user-images.githubusercontent.com/78345753/115833869-d41e7880-a414-11eb-8bb7-0e65da6e98aa.png) Esta es la primera prueba de soldadura.


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

![](https://github.com/reverte04/Soldadura-y-disegn-3.eva/blob/main/nose.jpeg) Este es el esquema que he programado en el arduino y vamos a hacer soldando.
