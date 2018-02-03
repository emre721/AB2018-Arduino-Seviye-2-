#include <EEPROM.h> /* EEPROM fonksiyonları için kütüphane dahil edilmelidir. */

int kayitAdresi , kaydedilecekVeri; 
int okunacakAdres, okunanVeri;

void setup()
{
 Serial.begin(9600); /* Bilgisayara veri göndermek için */
}

void loop()
{
 /* EEPROMa veri kaydediyoruz */
 kayitAdresi = 10; /* Verinin yazılacağı EEPROM adresi */ 
 kaydedilecekVeri = 50; /* EEPROMA kaydedilecek veri */
 EEPROM.write(kayitAdresi, kaydedilecekVeri); /* EEPROMun 10 adresine 50 verisi yazdırıldı. */
 delay(10);
 
 /* EEPROMa kaydedilmiş verileri okuyalım */
 okunacakAdres = 10; // 10 adresini okuyacağız
 okunanVeri = EEPROM.read(okunacakAdres ); /* EEPROMun 10 adresindeki veri okunanVeri değişkenine aktarılıyor. */
 delay(10);
 
/* Sonuçlar bilgisayar ekranına yazdırıldı */
 Serial.print("EEPROMun ");
 Serial.print(okunacakAdres);
 Serial.print(" Adresindeki Deger= ");
 Serial.print(okunanVeri);
 Serial.println();
 delay(1000); // biraz bekleyelim
}
