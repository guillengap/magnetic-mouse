// AUTHOR: GUILLERMO PEREZ GUILLEN

#include <Mouse.h> // Special Library

void setup()
{
    Serial.begin(9600);    
    pinMode (6,INPUT_PULLUP);
    pinMode (7,INPUT_PULLUP);
    pinMode (8,INPUT_PULLUP);
    pinMode (9,INPUT_PULLUP);
    pinMode (10, INPUT_PULLUP);
}

void loop()
{
//char dato[1];
int SWITCH1 = digitalRead(6);
int SWITCH2 = digitalRead(7);
int SWITCH3 = digitalRead(8);
int SWITCH4 = digitalRead(9);
int SWITCH5 = digitalRead(10); // CLICK

     if (SWITCH5 == LOW) {   // CLICK      
      Serial.println("CLICK");
      Mouse.click();
     }

     if (SWITCH1 == HIGH) {   // UP      
      Serial.println("UP");
      Mouse.move(0, 5, 0);
     }

     if (SWITCH2 == HIGH) {   // RIGHT
      Serial.println("RIGHT");
      Mouse.move(-5, 0, 0);
     }

     if (SWITCH3 == HIGH) {   // RIGHT
      Serial.println("DOWN");     
      Mouse.move(0, -5, 0);
     }

     if (SWITCH4 == HIGH) {   // RIGHT
      Serial.println("LEFT");
      Mouse.move(5, 0, 0);
     }

     else {
      Serial.println("STOP");
      Mouse.move(0, 0, 0);
     }     
    delay(100);
}
