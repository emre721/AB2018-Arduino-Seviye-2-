#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX
int led1 = 7;
int led2 = 6;
int led3 = 5;
int led4 = 4;

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  mySerial.begin(9600);
  mySerial.println("LED uygulamasi");
}

void loop()
{
  char ch = mySerial.read();
  if (ch == 'q')
  {
    digitalWrite(led1, !digitalRead(led1));
    if (digitalRead(led1) == HIGH)
    {
      mySerial.println("LED 1 yandi");
    }
    else
    {
      mySerial.println("LED 1 sondu");
    }
  }
  if (ch == 'w')
  {
    digitalWrite(led2, !digitalRead(led2));
    if (digitalRead(led2) == HIGH)
    {
      mySerial.println("LED 2 yandi");
    }
    else
    {
      mySerial.println("LED 2 sondu");
    }
  }
  if (ch == 'e')
  {
    digitalWrite(led3, !digitalRead(led3));
    if (digitalRead(led3) == HIGH)
    {
      mySerial.println("LED 3 yandi");
    }
    else
    {
      mySerial.println("LED 3 sondu");
    }
  }
  if (ch == 'r')
  {
    digitalWrite(led4, !digitalRead(led4));
    if (digitalRead(led4) == HIGH)
    {
      mySerial.println("LED 4 yandi");
    }
    else
    {
      mySerial.println("LED 4 sondu");
    }
  }
  if (ch == 'z')
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    mySerial.println("Tum LED'ler sondu");
  }
  if (ch == 'x')
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    mySerial.println("Tum LED'ler yandi");
  }
}
