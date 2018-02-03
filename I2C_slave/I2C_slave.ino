#include "Wire.h"
int led_4=4;  // digital 4 nolu pin değişkene atandı
int led_5=5;  // digital 5 nolu pin değişkene atandı
 
void setup() 
{
  pinMode(led_4,OUTPUT); // digital pinler çıkış olarak ayarlandı.
  pinMode(led_5,OUTPUT);
   
  // Master tarafında iletişim kurulacak slave adresi 10 dediğimiz için
  // iletişim 10 nolu adres ile slave aygıtta başlatılmaktadır.
  Wire.begin(10); 
   
  //ilk parametre gidilecek fonksiyondur ve iletişim olduğunda fonksiyona gidilmektedir.
  Wire.onReceive(iletisim_dongu); 
   
  Serial.begin(9600); // seri haberleşme iletişim hızı belirlenip başlatıldı.
}
void loop() 
{
  
}
 
void iletisim_dongu(int byte_sayisi)  
{
  String gelen_bilgi=""; // yeni gelen bilgi için string siliniyor
  while (Wire.available() >0)  // haberleşme boyunca döngü içinde kalmasını istiyoruz
  { 
    char karakter_bilgi = Wire.read();             // gelen veri okunmaktadır.(byte byte şeklinde)
    gelen_bilgi=gelen_bilgi+String(karakter_bilgi); // gelen bilgiler birleştirilmektedir.
  }
  Serial.println(gelen_bilgi); // oluşan bilgi seri porta yazdırılmaktadır.
   
  // led yakma olayı için string veriyi parçalamak gerekli ve bunun için substring() ifadesi kullanılmaktadır.
  // gelen veri 11 karakterden oluşmaktadır ve bizim için son gelen veri önemli onu parçalayacağız.
  if(gelen_bilgi.substring(10,11)=="4") // ilgili led 4  ise
  {
    digitalWrite(led_4,HIGH); // ilgili ledimiz on durumuna diğer ledimiz off duruma çekiliyor
    digitalWrite(led_5,LOW);
  }
  else if(gelen_bilgi.substring(10,11)=="5") // ilgili led 5  ise
  {
    digitalWrite(led_5,HIGH);
    digitalWrite(led_4,LOW);
   }
   
}
