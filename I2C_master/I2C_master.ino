#include "Wire.h" // I2C haberleşme kütüphanesi programa aktarılıyor
int led_no=4; // integer tipinde değişken oluşturuldu.
 
void setup() 
{
  Wire.begin(); // I2C haberleşeme master için başlatılıyor.
}
 
void loop() 
{
  Wire.beginTransmission(10);            // 10 numaralı adrese sahip slave ile iletişim başlatılıyor    
  Wire.write("ilgili Led");    // Slave için bilgiler gönderiliyor.
  Wire.print(led_no);          // Karakter değil integer veri gönderdiğimiz için print() komudu kullanıldı.
  Wire.endTransmission();                // Slave ile iletişim durduruluyor.
  delay(1000); // 1 saniyelik bir bekleme yapılmaktadır.
  led_no++; // bir sonraki led yakılması için led_no bilgisi arttırılıyor.
   
  // slave tarafında sadece 2 led üzerinde oynama yapılacağından tekrar led_no bilgisi başlangıç konuma geçiriliyor.
  if(led_no==6) {led_no=4;} 
}
