
int three=A1;   //Sari Kablo orta
int four=A2;   //Kirmizi Kablo
int two=A3;    //Beyaz Kablo en sag
int one=A4;  // Turuncu Kablo
int five=A5;  // Mavi Kablo

int one_deger;
int two_deger;
int three_deger;
int four_deger;
int five_deger;

int motor_1=11;
int motor_1_2=10;
int motor_2=5;
int motor_2_2=6;

void setup()
{
  pinMode(one,INPUT);
  pinMode(two,INPUT);
  pinMode(three,INPUT);
  pinMode(four,INPUT);
  pinMode(five,INPUT);
  
  pinMode(motor_1,OUTPUT);
  pinMode(motor_1_2,OUTPUT);
  pinMode(motor_2,OUTPUT);
  pinMode(motor_2_2,OUTPUT);
  
  Serial.begin(9600);
}

void loop()

{
  one_deger=analogRead(one);
  one_deger=constrain(one_deger,400,600);
  Serial.print("sag");
  Serial.println(one_deger);
  
  two_deger=analogRead(two);
  two_deger=constrain(two_deger,400,600);
  Serial.print("saglar");
  Serial.println(two_deger);
  
  three_deger=analogRead(three);
  three_deger=constrain(three_deger,400,600);
  Serial.print("orta");
  Serial.println(three_deger);
  
  four_deger=analogRead(four);
  four_deger=constrain(four_deger,400,600);
  Serial.print("sol");
  Serial.println(four_deger);
  
  five_deger=analogRead(five);
  five_deger=constrain(five_deger,400,600);
  Serial.print("sollar ");
  Serial.println(five_deger);
  
  if ( (three_deger< 500))  // orta sensör BEYAZ ise 
  {
   analogWrite(motor_1,150);
   digitalWrite(motor_1_2,LOW);
   analogWrite(motor_2,150);
   digitalWrite(motor_2_2,LOW);
  }

  else if ((one_deger<500)||(two_deger<500)) // sag sensörler BEYAZ görmüş ise
  {
    digitalWrite(motor_1,LOW);
    digitalWrite(motor_1_2,LOW); 
    analogWrite(motor_2,100);
    digitalWrite(motor_2_2,LOW);
  }

  else if ((four_deger<500)||(five_deger<500))  // sol sensörler BEYAZ görmüş ise
  {
    
   analogWrite(motor_1,100);
   digitalWrite(motor_1_2,LOW);
   digitalWrite(motor_2,LOW);
   digitalWrite(motor_2_2,LOW);
  }
  else if((one_deger>500)&&(two_deger>500)&&(three_deger>500)&&(four_deger>500)&&(five_deger>500))
  {
   analogWrite(motor_1,150);
   digitalWrite(motor_1_2,LOW);
   analogWrite(motor_2,150);
   digitalWrite(motor_2_2,LOW);
  }
  else if((three_deger<500)&&(one_deger<500)||(two_deger<500)) // KISAYOL SAĞA DÖNÜŞ 
  {
    digitalWrite(motor_1,LOW);
    digitalWrite(motor_1_2,LOW); 
    analogWrite(motor_2,100);
    digitalWrite(motor_2_2,LOW);
  }
   else if((three_deger<500)&&(four_deger<500)||(five_deger<500)) // KISAYOL SOLA DÖNÜŞ
  {
    digitalWrite(motor_1,100);
    digitalWrite(motor_1_2,LOW); 
    analogWrite(motor_2,LOW);
    digitalWrite(motor_2_2,LOW);
  }
  }
