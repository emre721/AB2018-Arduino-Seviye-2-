int sensor_mesafe=A0; //Sensorumuz A0 analog pini olarak tanımlandı.
int buton=7;          //Butonumuz digital 5 pini olarak tanımlandı.
int buzzer=5;         //Buzzerrımız digital 5 pini olarak tanımlandı.
int motor=6;          //Motorumuz digital 5 pini olarak tanımlandı.
int mesafe;           //Mesafe adında bir integer oluşturuldu.
int hiz;              //hız adında bir integer oluşturuldu.
int buzzer_pwm;       //buzzer_pwm adında bir integer oluşturuldu.

void setup() 
{
  pinMode(sensor_mesafe,INPUT); //Hangi pinler giriş ya da çıkış olduğu tanımlaması yapıldı.
  pinMode(buton,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(motor,OUTPUT);
  Serial.begin(9600);           //Port ekranıyla haberleşme hızı 9600 olarak belirlendi.
}

void loop() 
{
  
  if(digitalRead(buton)==1)    //Butona basma olayıyla sistemimizi çalışır duruma getiriyoruz
  {
    while(digitalRead(buton)==1){}  // Butondan elimizi çekene kadar  sistemimiz çalışır duruma geçmemektedir.
    while(true)                     // Butondan elimizi çektikten sonra sistem çalışır duruma geçmektedir.
    {
      mesafe=analogRead(sensor_mesafe); //Sensörümüzden mesafe bilgisi okunmaktadır.(sensörümüz 0-40 cm arası ölçüm yapmaktadır.
      
      hiz=map(mesafe,0,40,0,255); //Okunan mesafe bilgisi hız için 0-255 aralığına indirgenmiştir.
      
      buzzer_pwm=map(mesafe,0,40,255,0); //Okunan mesafe bilgisiyle ters orantılı olacak şekilde buzzer için (pwm) oluşturuldu.
      
      analogWrite(motor,hiz);     //Oluşan hız değeri (pwm) motorumuza atanmıştır.
      
      analogWrite(buzzer,buzzer_pwm); //Oluşturulan buzzer_pwm değeri buzzera atandı.
      
      if(mesafe<5)                 //mesafe  5 cm'den fazla olması durumunda port ekranında uyarı mesajı verilmektedir.
      {
        Serial.println("Çok fazla yaklaştınız");
      }
      
      if(digitalRead(buton)==1)
      {
        while(digitalRead(buton)==1){}  // Butondan elimizi çekene kadar  sistemimiz çalışır durumda kalmaktadır.
        
        //sistem durağan konuma getirildi ve sonsuz döngüden  çıkıldı.
        digitalWrite(buzzer,LOW);
        digitalWrite(motor,LOW);
        break;
      }
    }
  }
}
