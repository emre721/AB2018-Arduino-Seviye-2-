// arduonik.blogspot.com
// Bu örnekte Arduino kartımızda dahili bulunan ve 13. pine bağlı led kullanacağız
int led = 13;  // pinimize "led" adını veriyoruz


void ac_kapa(int bekleme_acik,int bekleme_kapali){ //daha sonra "ac_kapa" adında bir fonksiyon oluşturuyoruz ama daha önceki parantez içinin aksine burada 
//bekleme_acik ve bekleme_kapali adında iki int değişken ekliyoruz
// fonksiyonu kullanırken bu değişkenler yerine istediğimiz değeri yazarsak  bu fonksiyon içinde kullanılan bekleme_acik ve bekleme_kapali değişkenleri yazdığımız değerleri alacak
    digitalWrite(led, HIGH);   // ilk başta ledimizi açık duruma getiriyoruz
  delay(bekleme_acik);               // ve bekleme_acik değişkeni kadar bekliyoruz
  digitalWrite(led, LOW);    // ardından ledi kapatiyoruz
  delay(bekleme_kapali);            // ve led kapalıyken bekleme_kapali değişkeninin değeri kadar bekliyoruz
}  // fonksiyonu kapatmayı unutmayın :)
//kendi fonksiyonumuzdan sonra Setup fonksiyonunu oluşturuyoru
void setup() {

  pinMode(led, OUTPUT);  //led olarak adlandırdığımız 13 nolu pini çıkış pini olarak ayarlıyoruz
}

// Daha sonrada loop fonksiyonuna geçiyoruz
void loop() {
ac_kapa(500,250);             // ac_kapa fonksiyonunu çalıştırıyoruz ve bekleme_acik değişkenini 500, bekleme_kapalı değişkenini 250 yapıyoruz yani her iki delay da farklı olacak
}
