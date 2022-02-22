//Vize Ödevi -15260574-Alparslan KOÇ

//Potentiometer pinleri
int pot1Pin = A0;
int pot2Pin = A1;
int pot3Pin = A2;

//5.0 Volt / 1023.0 = 0.00488 Volt 
//Potentiometer degerleri
  int  pot1Val ; 
  int  pot2Val ;
  int  pot3Val ;

//Pot-Voltage Degerleri
float voltage1=0;
float voltage2=0;
float voltage3=0;  

//Start butonun baglı oldugu pin
int StartButton = 5;


//butona basıldığında gecen zaman
unsigned long degisen_Zaman;
long rastgele_sayi_1=random(0.0,1023.0);
long rastgele_sayi_2=random(0.0,1023.0);
long rastgele_sayi_3=random(0.0,1023.0);
long hata_payi_1 ;
long hata_payi_2 ;
long hata_payi_3 ;

void setup() {

  Serial.begin(9600);

  pinMode(StartButton, INPUT);
  pinMode(pot1Pin, INPUT);
  pinMode(pot2Pin, INPUT);
  pinMode(pot3Pin, INPUT);

  
}

void loop() {

  //Start butonuna basıldıktan 20 sn sonra masuraların agırlıkları olculecek
  int state_Sbutton = digitalRead(StartButton);
 
  //Potentiometer den okunan degerler
  pot1Val=analogRead(pot1Pin);
  pot2Val=analogRead(pot2Pin);
  pot3Val=analogRead(pot3Pin);
  //Potentiometer ların voltaj degerini hesaplıyoruz
  voltage1=(5.0/rastgele_sayi_1)*pot1Val; //5.0/1023.0
  voltage2=(5.0/rastgele_sayi_2)*pot2Val;
  voltage3=(5.0/rastgele_sayi_3)*pot3Val;
  
  if (state_Sbutton == HIGH) {
    Serial.println("Butona basildi...");
  }
  

  if (state_Sbutton == HIGH && (millis() - degisen_Zaman) < 20000) { //20000
    //Aciklama : 5Volt =1023 ise x Volt =70 esitliginden x=0.34 Volt bulunur
    //Aciklama-Devam : bu formulu kullanarak y Volt = 75 ise y=0.36 Volt bulunur
    Serial.println("buton + 20000 ms kosuluna girdi");

    //Potentiometer 1 in olctugu Mesura agirligi kontrolu
    if (pot1Val < 70) { 
      hata_payi_1 = 70 - pot1Val;
      Serial.print("Pot1 Hata payi : ");
      Serial.print(hata_payi_1);
      Serial.println(" gr ");
      delay(100);
    } else if ( pot1Val > 75) {
      hata_payi_1 = pot1Val - 75;
      Serial.print("Pot1 de Bos a Giden Ip : ");
      Serial.println(hata_payi_1);
      Serial.println(" gr ");
      delay(100);
    } else if (70 < pot1Val && pot1Val < 75) {
      Serial.println("Pot1 Hatali Masura Yok..");
      delay(100);
    }

    //Potentiometer 2 in olctugu Mesura agirligi kontrolu
    if (pot2Val < 70) {
      hata_payi_2 = 70 - pot2Val;
      Serial.print("Pot2 de Hata payi : ");
      Serial.print(hata_payi_2);
      Serial.println(" gr ");
      delay(100);
    } else if ( pot2Val > 75) {
      hata_payi_2 = pot2Val - 75;
      Serial.print("Pot2 de Bos a Giden Ip : ");
      Serial.print(hata_payi_2);
      Serial.println(" gr ");
      delay(100);
    } else if (70 < pot2Val && pot2Val < 75) {
      Serial.println("Pot2 de Hatali Masura Yok..");
      delay(100);
    }

    //Potentiometer 3 in olctugu Mesura agirligi kontrolu
    if (pot3Val < 70) {
      hata_payi_3 = 70 - pot3Val;
      Serial.print("Pot3 de Hata payi : ");
      Serial.print(hata_payi_3);
      Serial.println(" gr ");
      delay(100);
    } else if ( pot3Val > 75) {
      hata_payi_3 = pot3Val - 75;
      Serial.print("Pot3 de Bos a Giden Ip : ");
      Serial.print(hata_payi_3);
      Serial.println(" gr ");
      delay(100);
    } else if (70 < pot3Val && pot3Val < 75) {
      Serial.println("Pot3 de Hatali Masura Yok..");
      delay(100); //300
    }
    degisen_Zaman = millis();
    delay(100);
  }
  
}
