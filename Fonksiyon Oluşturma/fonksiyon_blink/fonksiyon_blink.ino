int led = 13; // 13. pinimizin adını led olarak belirliyoruz
void setup() {
  // sadece bir defa çalışacak kurulum kodlarımızı yazıyoruz(pin mod, seri bağlantı başlangıcı gibi)
  pinMode(led, OUTPUT); // led pinini çıkış pini olarak ayarlıyoruz
}

void loop() {
  //sürekli döngü içinde çalışacak kodumuzu yazıyoruz
ac_kapa();//ac kapa fonksiyonunu çalıştırıyoruz fonksiyon loop içinde olduğu için 
}

void ac_kapa(){
  //kendimize ait bir fonksiyon yazıyoruz
  digitalWrite(led, HIGH);   // Ledi yakıyoruz
  delay(1000);                  // bir saniye led açık durumda bekliyoruz
  digitalWrite(led, LOW);    // ledi kapıyoruz
  delay(1000);                  // bir saniye daha bekliyoruz
  }
