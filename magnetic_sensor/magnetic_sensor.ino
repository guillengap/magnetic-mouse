#include <Tle493d_w2b6.h>

Tle493d_w2b6 Tle493dMagnetic3DSensor = Tle493d_w2b6();
void setup() {
  Serial.begin(9600);
  pinMode (4,OUTPUT);
  pinMode (5,OUTPUT);
  while (!Serial);
  Tle493dMagnetic3DSensor.begin();
  Tle493dMagnetic3DSensor.enableTemp();
}

void loop() {
  Tle493dMagnetic3DSensor.updateData();
  float angle = Tle493dMagnetic3DSensor.getAzimuth() * 57.3;
  int angle1 = angle;
  float Norm = Tle493dMagnetic3DSensor.getNorm();

  if ((angle1>=165 && angle1<=180 && Norm>=90)||(angle1>=-180 && angle1<=-165 && Norm>=90)){    // STOP
        Serial.print(angle1);
        Serial.println(" = STOP");
        digitalWrite (4,LOW);
        digitalWrite (5,LOW);
        delay (10);
    }  

  else if (angle1>=-105 && angle1<=-75 && Norm>=90){    // RIGHT
        Serial.print(angle1);
        Serial.println(" = RIGHT");
        digitalWrite (4,LOW);
        digitalWrite (5,HIGH);
        delay (10);
    }  

  if (angle1>=-15 && angle1<=15 && Norm>=90){    // FORWARD
        Serial.print(angle1);
        Serial.println(" = FORWARD");
        digitalWrite (4,HIGH);
        digitalWrite (5,LOW);
        delay(10);
    }

  else if (angle1>=75 && angle1<=105 && Norm>=90){    // LEFT
        Serial.print(angle1);
        Serial.println(" = LEFT");
        digitalWrite (4,HIGH);
        digitalWrite (5,HIGH);
        delay (10);
    }  
}
