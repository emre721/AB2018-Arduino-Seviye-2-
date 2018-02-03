// Sistem için Kullanılacak pinler tanımlanmaktadır
int motor_pin=6;    // pwm pini seçilmiştir
int basla_led_pin=7;
int dur_led_pin=4;
int basla_pin=8;
int buzzer_pin=12;
int dur_pin=2;
 
void setup() 
{
   
  Serial.begin(9600); // Haberleşme hızı 9600 bps ile başlatılmaktadır.
   
  // Giriş çıkış pinleri tanımlanmaktadır.
  pinMode(motor_pin,OUTPUT);
  pinMode(basla_led_pin,OUTPUT); // çıkış pini
  pinMode(dur_led_pin,OUTPUT);
  pinMode(buzzer_pin,OUTPUT);
  pinMode(basla_pin,INPUT); // giriş pini
   
  // kesme ayarları yapılmaktadır ve kesme pini olarak 2 numaralı digital pin kullanılmaktadır
  // kesmeye geçme durumu yükselen kenar.
  attachInterrupt(0,sistem_stop,RISING);
 
}
 
void loop() 
{
   
 if(digitalRead(basla_pin)==1) // Sitem baslatma butonunun sorgusu yapılmaktadır
 {
   while(digitalRead(basla_pin)==1){} // butondan elinizi çekene kadar bu satırda durmaktadı.
    
   // port ekranına sistem durum bilgisi yazılmakta ve pinlere atama işlemi yapılmaktadır.
   Serial.println("Sistem Baslatildi");
   analogWrite(motor_pin,125);
   digitalWrite(basla_led_pin,HIGH);
   digitalWrite(dur_led_pin,LOW);
   digitalWrite(buzzer_pin,LOW);
 }
  
}
 
// Oluşturulan kesme fonksiyonu, kesme oluştuğunda bu fonksiyona programın hangi satırında 
// olunulursa olsun hemen geçiş yapılmaktadır..
void sistem_stop()
{
  if(digitalRead(dur_pin)==1)
  {
     // Sitem durum mesajı verilmektedir ve pimlere atama işlemleri gerçekleştirilmektedir.
     Serial.println("Sistem durduruldu ACIL DURUM !!!");
     analogWrite(motor_pin,0);
     digitalWrite(basla_led_pin,LOW);
     digitalWrite(dur_led_pin,HIGH);
     digitalWrite(buzzer_pin,HIGH);
  }
}
