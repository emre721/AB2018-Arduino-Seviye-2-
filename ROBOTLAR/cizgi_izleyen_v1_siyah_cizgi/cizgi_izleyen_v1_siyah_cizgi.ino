 //int sensor_sol=A0;    //Yesil Kablo en sol
int three=A1;   //Sari Kablo orta
int four=A2;   //Kirmizi Kablo
int two=A3;    //Beyaz Kablo en sag
int one=A4;  // Turuncu Kablo
int five=A5;  // Mavi Kablo


// 600 Siyah , 400 Beyaz
//int sol_deger;
int one_deger;
int two_deger;
int three_deger;
int four_deger;
int five_deger;

int motor_1=11;
int motor_1_2=10;
int motor_2=5;
int motor_2_2=6;

int ledpin=13;


void setup()
{
  //pinMode(sensor_sol,INPUT);
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
  /*sol_deger=analogRead(sensor_sol);
  sol_deger=constrain(sol_deger,400,600);
  Serial.print("sol_sensor");
  Serial.println(sol_deger);
  */
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
  
  if ( (three_deger> 500))  // orta siyah ise 
  {
    analogWrite(motor_1,100);
    //digitalWrite(motor_1,HIGH);
   digitalWrite(motor_1_2,LOW);
   analogWrite(motor_2,100);
   //digitalWrite(motor_2,HIGH);
   digitalWrite(motor_2_2,LOW);
  }
  else if ((one_deger>500)||(two_deger>500)) // sol yan siyahdan cikmis ise sol motor ileri
  {
    
    digitalWrite(motor_1,LOW);
    digitalWrite(motor_1_2,LOW);
 /*
    for(int i=10; i<101;i=i+10)
    {
      analogWrite(motor_2, i);
    }
    */
    
   analogWrite(motor_2,100);
   //digitalWrite(motor_2,HIGH);
   digitalWrite(motor_2_2,LOW);
    
  
  
  }

  else if ((four_deger>500)||(five_deger>500))  // sag yan siyahdan cikmis ise sag motor ileri
  {
  
      /*for(int i=10; i<101;i=i+10)
     {
      analogWrite(motor_1, i);
    }
    */
    
   analogWrite(motor_1,100);
  //digitalWrite(motor_1,HIGH);
  digitalWrite(motor_1_2,LOW);
  
  digitalWrite(motor_2,LOW);
  digitalWrite(motor_2_2,LOW);
  
  }
  
  else if ((one_deger <500)&&(two_deger<500)&&(three_deger<500)&&(four_deger<500)&&(five_deger<500))
 {
   digitalWrite(motor_1,LOW);
   digitalWrite(motor_1_2,LOW);
   digitalWrite(motor_2,LOW);
   digitalWrite(motor_2_2,LOW);
 }
  }
