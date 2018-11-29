#include <SD.h>                      
#include <SPI.h>              
#include <TMRpcm.h>           

#define SD_ChipSelectPin 4  
TMRpcm Audio;  

int CNY_Val1, CNY_Val2, CNY_Val3, CNY_Val4;             // Variables de almacenamiento de los Sensores CNY 70 -Sigue Lineas
String estadoSensores,drums,bass,guitar,piano;
int blanco=600;
int negro=700;
void setup() {   
  Audio.speakerPin = 9; 
  Audio.quality(1); 
  Audio.setVolume(5);  

  Serial.begin(9600); 
  if (!SD.begin(SD_ChipSelectPin)) {  
    return;   // prgram finishes if card is missed
  }
  else{
    Serial.println("SD inicializada!");
      }
      
  }
  void loop()
  {
    solos();
    }
    void solos()
    {
      CNY_Val1= analogRead(A1);           
      CNY_Val2= analogRead(A2);           
      CNY_Val3= analogRead(A3);           
      CNY_Val4= analogRead(A4); 
      estadoSensores="";

      if(CNY_Val1< negro)
      {
        drums="1";
        }
      else if(CNY_Val1> blanco)
      {
        drums="0";
        }
       if(CNY_Val2< negro)
      {
        bass="1";
        }
      else if(CNY_Val2> blanco)
      {
        bass="0";
        }
        if(CNY_Val3< negro)
      {
        guitar="1";
        }
      else if(CNY_Val3> blanco)
      {
        guitar="0";
        }
       if(CNY_Val4< negro)
      {
        piano="1";
        }
      else if(CNY_Val4> blanco)
      {
        piano="0";
        }
        estadoSensores.concat(drums);
        estadoSensores.concat(bass);
        estadoSensores.concat(guitar);
        estadoSensores.concat(piano);

        if(estadoSensores=="1000"){Audio.play("1.wav");}
        if(estadoSensores=="0100"){Audio.play("2.wav");}
        if(estadoSensores=="0010"){Audio.play("4.wav");}
        if(estadoSensores=="0001"){Audio.play("3.wav");}
        if(estadoSensores=="0000"){}
      }
