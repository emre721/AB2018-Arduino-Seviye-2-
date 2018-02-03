#include <Servo.h>
#include <EEPROM.h>

Servo servoMotor;

int servoAcisi;
int donusYonu = 0; /* 0 ise servo ileri, 1 ise geri yönde dönmektedir. */

void setup()
{
  servoMotor.attach(9); /* Servo Arduinonun 9 numaralı pinine takıldı */
  
  servoAcisi = EEPROM.read(1); /* Servonun kaldığı yer EEPROMdan alınıyor */
  if(servoAcisi < 1 || servoAcisi > 179){ /* EEPROMda servo açısı yerine başka bir veri varsa */
    servoAcisi = 1; /* Motor ilk konumuna donsun */
  }
  donusYonu = EEPROM.read(0);
  if(donusYonu != 1 && donusYonu != 0){ /* EEPROMda dönüş yönü yerine başka bir veri varsa */
    donusYonu = 0;  /* Motor ileri yönde donsun */
  }
}
void loop()
{                         
  servoMotor.write(servoAcisi); /* Servo motoru kontrol ediyoruz */              
  EEPROM.write(1,servoAcisi); /* Son açıyı EEPROMa kaydediyoruz */
  
  if(donusYonu == 0){ /* Motor ileri önde donuyorsa */
    servoAcisi = servoAcisi + 5; /* 5 derece döndürelim */
    if(servoAcisi > 179){ /* Motor ileri yönde sona ulaştıysa */
       servoAcisi = 179;
       donusYonu = 1; /* Geri yönde dönmeye basla */   
       EEPROM.write(0,donusYonu); /* Yon bilgisi EEPROMa kaydedildi */
    }
  }else{ /* Motor geri yönde donuyorsa */
    servoAcisi = servoAcisi - 5; /* 5 derece geri don */
    if(servoAcisi < 1){ /* Motor geri yönde sona ulaştıysa */
       servoAcisi = 1;
       donusYonu = 0; /* ileri yönde dönmeye basla */
       EEPROM.write(0,donusYonu); /* Yon bilgisi EEPROMa kaydediliyor */
    }
  }
  
  delay(15); /* Motorun konumunu alması için biraz bekleme */
}
