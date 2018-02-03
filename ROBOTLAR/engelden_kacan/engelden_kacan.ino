#include<Servo.h>
int mot_1_1=11;
int mot_1_2=10;
int mot_2_1=5;
int mot_2_2=6;
Servo uzaklik;
float sensor= A3;
float mesafe_1; // SAĞ TARAFTAN ALINAN
float mesafe_2; // SOL TARAFTAN ALINAN
float mesafe;

void setup()
{
  uzaklik.attach(9);
  Serial.begin(9600);
  pinMode(sensor,INPUT);
  pinMode(mot_1_1,OUTPUT);
  pinMode(mot_1_2,OUTPUT);
  pinMode(mot_2_1,OUTPUT);
  pinMode(mot_2_2,OUTPUT);
  uzaklik.write(90);
  delay(700);
}

void loop()
{
  mesafe=analogRead(sensor)*0.00322265624;
  mesafe=12.21*pow(mesafe,-1.15);
  Serial.print(mesafe);
  Serial.println (" cm");
  delay(250);
  if (mesafe < 10)
  
  {
    durma();
    geri();
    uzaklik.write(170);
    mesafe_2=analogRead(sensor)*0.00322265624;
    mesafe_2=12.21*pow(mesafe_2,-1.15);
    Serial.print(mesafe_2);
    Serial.println("sol mesafe");
    delay(700);
    uzaklik.write(90);
    delay(700);
    uzaklik.write(10);
    mesafe_1=analogRead(sensor)*0.00322265624;
    mesafe_1=12.21*pow(mesafe_1,-1.15);
    Serial.print(mesafe_1);
    Serial.println("sag mesafe");
    delay(700);
    uzaklik.write(90);
    delay(700);
    if( ((mesafe_1 >= mesafe_2)) && (mesafe_1>13))
    {
      donme_sag();
    }
    else if ((mesafe_2 > mesafe_1) && (mesafe_2>13))
    {
      donme_sol();
    }
    else if (mesafe_1 < 11 && mesafe_2 < 11)
    {
      while(1)
      {
        geri();
        durma();
        uzaklik.write(170);
        mesafe_2=analogRead(sensor)*0.00322265624;
        mesafe_2=12.21*pow(mesafe_2,-1.15);
        Serial.print(mesafe_2);
        Serial.println("geri sol mesafe");
        delay(700);
        uzaklik.write(90);
        delay(700);
        uzaklik.write(10);
        mesafe_1=analogRead(sensor)*0.00322265624;
        mesafe_1=12.21*pow(mesafe_1,-1.15);
        Serial.print(mesafe_1);
        Serial.println("geri sag mesafe");
        delay(700);
        uzaklik.write(90);
        delay(700);
        if ((mesafe_1<11) && (mesafe_2<11))
        {
         continue;
        }
        else if ( (mesafe_1>mesafe_2) && (mesafe_1> 13))
        {
          donme_sag();
          break;
        }
        else if ((mesafe_2>13)&& (mesafe_2> mesafe_1))
        {
          donme_sol();
          break ;
        }
      }
    }
  }
  else if (mesafe > 10)
  {
    ileri();
  }
  
}

  void ileri()
  {
    analogWrite(mot_1_1,140);
    analogWrite(mot_1_2,0);
    analogWrite(mot_2_1,140);
    analogWrite(mot_2_2,0);
  }
  void geri()
  {
    analogWrite(mot_1_1,0);
    analogWrite(mot_1_2,200);
    analogWrite(mot_2_1,0);
    analogWrite(mot_2_2,200);
    delay(500);
  }
  void durma()
  {
    analogWrite(mot_1_1,0);
    analogWrite(mot_1_2,0);
    analogWrite(mot_2_1,0);
    analogWrite(mot_2_2,0);
    delay(500);
  }
  
  void donme_sag()
  {
    analogWrite(mot_1_1,0);
    analogWrite(mot_1_2,225);
    analogWrite(mot_2_1,0);
    analogWrite(mot_2_2,0);
    delay(1000);
  }
  void donme_sol()
  {
    analogWrite(mot_1_1,0);
    analogWrite(mot_1_2,0);
    analogWrite(mot_2_1,0);
    analogWrite(mot_2_2,225);
    delay(1000);
  }
  
  
  
  
  
  
  
