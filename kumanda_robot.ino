#include <Servo.h>
#include <IRremote.h>

Servo servo1;
Servo servo2;
Servo servo3;

IRrecv irrecv(12);

decode_results results;

#define BUTON1  0xFFA25D
#define BUTON2  0xFF629D
#define BUTON3  0xFFE21D
#define BUTON4  0xFF22DD
#define BUTON5  0xFF02FD
#define BUTON6  0xFFC23D
#define BUTON7  0xFFE01F
#define BUTON8  0xFFA857
#define BUTON9  0xFF906F
#define BUTON0  0xFF9867
#define YILDIZ  0xFF6897
#define KARE    0xFFB04F
#define YUKARI  0xFF18E7
#define ASAGI   0xFF4AB5
#define SOL     0xFF10EF
#define SAG     0xFF5AA5
#define OK      0xFF38C7
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  servo1.attach(4);
  servo2.attach(5);
  servo3.attach(6);
}

String kumandaHEX = String(13, HEX);
String yon="";

void loop()
{

  if(irrecv.decode(&results))
  {
    kumandaHEX=results.value,HEX;
    
    if(results.value==ASAGI){
      Serial.print("asagi");
      yon="asagi";
    }
    else if(results.value==YUKARI){
      Serial.print("yukari");
      yon="yukari";
    }
    else if(results.value==SOL){
      Serial.print("sol");
      yon="sol";
    }
    else if(results.value==SAG){
      Serial.print("sag");
      yon="sag";
    }
     else if(results.value==BUTON2){
      Serial.print("buton2");
      yon="buton2";
    }

     else if(results.value==BUTON8){
      Serial.print("buton8");
      yon="buton8";
    }
    
    
    else if(kumandaHEX=="4294967295"){ //basılı algılama

      if(yon=="sol"){
        servo1.attach(4);
        servo1.write(150);
        
      }else if(yon=="sag"){
        servo1.attach(4);
        servo1.write(30);
      }
      else if(yon=="yukari"){
        servo2.attach(5);
        servo2.write(30);
      }
      else if(yon=="asagi"){
        servo2.attach(5);
        servo2.write(150);
      }
      
      else if(yon=="buton2"){
        servo3.attach(6);
        servo3.write(30);
      }
      else if(yon=="buton8"){
        servo3.attach(6);
        servo3.write(150);
      }
      
      else{
        yon="yok";
        servo1.detach();
        servo2.detach();
        servo3.detach();
      }
      Serial.print("basili");
    }else{
      yon="yok";
      servo1.detach();
      servo2.detach();
      servo3.detach();
    }
    
    irrecv.resume();
  }


    
}
