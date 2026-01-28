#include "hotel.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "yonetici.h"
using namespace std;
const string hotel::dosya = "odatipleri.dat";
const string yonetici::dosya = "odatipleri.dat";


void yonetici::Sayfa()
{
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "+                                               BEYKOZ HOTEL                                                +" << endl;
    cout << "+                                                                                                           +" << endl;
    cout << "+                                                           Kavacık, Muhtar Sk. No: 3, İstanbul             +" <<
    endl;
    cout << "+                                                                                BEYKOZ 34820, TÜRKİYE      +" << endl;
    cout << "+                                                                                                           +" << endl;
    cout << "+ Beykoz Hotel, konforlu konaklama ve güler yüzlü hizmet sunan bir oteldir.                                 +" <<
        endl;
    cout << "+ Otelimiz sakin bir atmosferde dinlenmek isteyenler için mükemmel bir seçenektir.                          +" <<
        endl;
    cout << "+ Beykoz Hotel, misafirlerinin tüm ihtiyaçlarına özenle cevap verir ve onlara güleryüzlü hizmet sunar.      +" << endl;
    cout << "+ Otelimiz, huzur ve konfor dolu bir mola sunarak İstanbul'un stresinden uzaklaşmalarına yardımcı olur.     +" << endl;
    cout << "+                                               OLANAKLAR                                                   +" << endl;
    cout << "+1. Geniş ve konforlu odalar                                                                                +" << endl;
    cout << "+2. Restoran                                                                                                +" << endl;
    cout << "+3. Fitness merkezi                                                                                         +" << endl;
    cout << "+4. Bahçe ve teras                                                                                          +" << endl;
    cout << "+5. Oda servis                                                                                              +" << endl;
    cout << "+6. Toplantı ve etkinlik alanları                                                                           +" << endl;
    cout << "+7. 24 Saat oda servisi                                                                                     +" << endl;
    cout << "+8. Çamaşırhane Hizmeti                                                                                     +" << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "Devam etmek için enter tuşuna basın!!";
    cin.ignore();
    giris();
}
void musterileriGoster(string dosyaAdi, yonetici& frn) {
    ifstream dosya("musteriler.dat");
    string satir;

    if (dosya.is_open()) {
        while (getline(dosya, satir)) {
            cout << satir << endl;
        }
        dosya.close();

        char secim;
        cout << "Menüye dönmek için 'y' basın, çıkmak için 'n' basın: ";
        cin >> secim;

        if (secim == 'y' || secim == 'Y') {
            frn.giris();
        } else if (secim == 'n' || secim == 'N') {
            exit(0);
        } else {
            cout << "Geçersiz giriş. Programdan çıkılıyor..." << endl;
            exit(0);
        }

    } else {
        cout << "Dosya açılamadı!" << endl;
    }
}


void yonetici::giris() {
    int secim;
    cout << " Yönetici girişi için 1'e basınız." << endl;
    cout << " Müşteri girişi için 2'ye basınız." << endl;
    cin >> secim;
    
    if (secim==1) {
        Sayfa(1);
    }
    else if (secim==2){
        musteriSayfa();
    }
    else
        giris();
    
}
void yonetici::Sayfa(int secenek){
    yonetici frn;
    cout<<"Bir Kagegori seçin:\n 1-Oda Ekleme\n 2-Müşterileri Görüntüle\n 3-Müşteri Ekle\n 4-Oda Sil\n 5-Oda No Güncelle"<<endl;
    cin>>secenek;
    switch(secenek){
        case 1:
            odaEkle();
            break;
        case 2:
            musterileriGoster("musteriler.dat",frn);
            break;
        case 3:
            musteriEkle();
            break;
        case 4:
            odaSil();
        case 5:
            odaGuncelle();
             
    }
}

void hotel::musteriSayfa(){
    cout << "Bir Kagegori seçin:\n\n1. Oda Özellikleri\n2. Rezervasyon" <<endl;
    int secenek;
    cin>>secenek;
    switch(secenek){
        case 1:
            odaOzellikleri();
            break;
        case 2:
            rezervasyon();
            break;
    }
             
}
void yonetici::odaEkle(string dosyaAdi) {
    cout << "Lütfen eklemek istediğiniz oda tipini seçiniz" << endl;
    cout << "1- Özel Lüks\n2- Deluks\n3- Normal\n4- Çift Kişilik\n5- Çift Kişilik Lüks" << endl;
    int secim;
    cin >> secim;

    if (secim >= 1 && secim <= 5) {
        switch (secim) {
            case 1:
                obje2.setOdaTipi("OzelLuks");
                break;
            case 2:
                obje2.setOdaTipi("Deluks");
                break;
            case 3:
                obje2.setOdaTipi("Normal");
                break;
            case 4:
                obje2.setOdaTipi("Çift Kişilik");
                break;
            case 5:
                obje2.setOdaTipi("Çift Kişilik Lüks");
                break;
        }

        ifstream dosyaOku(dosyaAdi);
        if (dosyaOku.is_open()) {
            string satir;
            while (getline(dosyaOku, satir)) {
                obje1.odaEkle(satir);
            }
            dosyaOku.close();
        } else {
            cerr << "Dosya açma hatası!" << endl;
            return;
        }

        string yeniVeri;
        bool odaMevcut;

        do {
               odaMevcut = false;
               cout << "Eklemek istediğiniz oda numarasını girin: ";
               cin >> odaNo;
               yeniVeri = obje2.getOdaTipi() + " " + to_string(odaNo);

               for (const string& satir : obje1.getOdaListesi()) {
                   if (satir.find(yeniVeri) != string::npos) {
                       odaMevcut = true;
                       cout << "Bu oda numarası zaten mevcut. Lütfen başka bir oda numarası girin." << endl;
                       break;
                   }
               }
           } while (odaMevcut);
            *this += yeniVeri;
           bool satirBulundu = false;
           for (string& satir : obje1.getOdaListesi()) {
               if (satir.rfind(obje2.getOdaTipi(), 0) == 0) {
                   satir += ", " + yeniVeri;
                   satirBulundu = true;
                   break;
               }
           }

           if (!satirBulundu) {
               obje1.getOdaListesi().push_back(obje2.getOdaTipi() + " " + yeniVeri);
           }

        ofstream dosyaYaz(dosyaAdi);
        if (dosyaYaz.is_open()) {
            for (const string& satir : obje1.getOdaListesi()) {
                dosyaYaz << satir << "\n";
            }
            dosyaYaz.close();
            cout << "Oda başarıyla eklendi." << endl;
        } else {
            cerr << "Dosya yazma hatası!" << endl;
        }
    } else {
        cerr << "Geçersiz oda tipi seçimi!" << endl;
    }
}


void yonetici::odaSil(string dosyaAdi) {
    cout << "Lütfen silmek istediğiniz oda tipini seçiniz" << endl;
    cout << "1- Özel Lüks\n2- Deluks\n3- Normal\n4- Çift Kişilik\n5- Çift Kişilik Lüks" << endl;
    int secim;
    cin >> secim;

    if (secim < 1 || secim > 5) {
        cerr << "Geçersiz oda tipi seçimi!" << endl;
        return;
    }

    switch (secim) {
        case 1: obje2.setOdaTipi("OzelLuks") ; break;
        case 2: obje2.setOdaTipi("Deluks"); break;
        case 3: obje2.setOdaTipi("Normal"); break;
        case 4: obje2.setOdaTipi("Çift Kişilik"); break;
        case 5: obje2.setOdaTipi("Çift Kişilik Lüks"); break;
    }

    ifstream dosyaOku(dosyaAdi);
    if (!dosyaOku.is_open()) {
        cerr << "Dosya açma hatası!" << endl;
        return;
    }

    string satir;
    while (getline(dosyaOku, satir)) {
        obje1.getOdaListesi().push_back(satir);
    }
    dosyaOku.close();

    bool odaBulundu = false;
    cout << "Silmek istediğiniz oda numarasını girin: ";
    cin >> secim;
    string aranacakVeri = obje2.getOdaTipi() + " " + to_string(secim);

    for (size_t i = 0; i < obje1.getOdaListesi().size(); ++i) {
        size_t pos = obje1.getOdaListesi()[i].find(aranacakVeri);
        if (pos != string::npos) {
            odaBulundu = true;
            obje1.getOdaListesi()[i].erase(pos, aranacakVeri.length());
            if (pos > 0 && obje1.getOdaListesi()[i][pos - 1] == ',') {
                obje1.getOdaListesi()[i].erase(pos - 2, 2);
            }
            break;
        }
    }

    if (!odaBulundu) {
        cout << "Belirtilen oda numarası bulunamadı." << endl;
        return;
    }

    ofstream dosyaYaz(dosyaAdi);
    if (!dosyaYaz.is_open()) {
        cerr << "Dosya yazma hatası!" << endl;
        return;
    }

    for (const auto& odalar : obje1.getOdaListesi()) {
        dosyaYaz << odalar << "\n";
    }
    dosyaYaz.close();
    cout << "Oda başarıyla silindi." << endl;
}

void musteri::musteriBilgileri(){
    cout<<"İsim: "<<endl;
    cin>>isim;
    setAd(isim);
    cout<<"Soyisim: "<<endl;
    cin>>soyisim;
    setSoyad(soyisim);
    cout<<"Telefon No: "<<endl;
    cin>>telNo;
    setTelno(telNo);
    
}
void musteri::bilgileriKaydet() {
    ofstream dosya("musteriler.dat", ios::app);
    if (dosya.is_open()) {
        dosya << "İsim: " << getAd() << ", "
              << "Soyisim: " << getSoyad() << ", "
              << "Telefon No: " << getTelno() << endl;
        dosya.close();
    } else {
        cout << "Dosya açılamadıı!";
    }
}

void hotel::odaNumaralari(string dosyaAdi){
    ifstream dosyaOku(dosyaAdi);
            if (dosyaOku.is_open()) {
                string satir;
                while (getline(dosyaOku, satir)) {
                    cout << satir << endl;
                }
                dosyaOku.close();
            } else {
                cerr << "Dosya açma hatası!" << endl;
            }
}
             
void hotel::odaOzellikleri()
{
odaOzellikleri2:
    int sec;
    cout<<"------------------------------------------------------------"<<endl;
    cout<<"Oda tipiniz seçiniz:"<<endl;
    cout<<"1-Özel Lüks\n 2- Deluks\n 3-Normal\n 4-Çift Kişilik\n 5- Çift Kişilik Lüks"<<endl;
    cin>>sec;
    if(sec<6 && sec>0){
        switch(sec){
            case 1:
                cout<<"\n                 ODANIN ÖZELLİKLERİ       ";
                cout<<"\n ---------------------------------------------------";
                cout<<"\n Oda Tipi         >>> Özel Lüks";
                cout<<"\n Oda Fiyatı       >>> Günlük 10000₺";
                cout<<"\n Yatak Sayısı     >>> 1 Adet";
                cout<<"\n Balkon Mevcut";
                cout<<"\n ---------------------------------------------------";
                cout<<"\n                 EK ÖZELLİKLER";
                cout<<"\n ---------------------------------------------------";
                cout<<"\n Sabah kahvaltısı - Öğle yemeği - Akşam yemeği ÜCRETSİZ";
                cout<<"\n TV ";
                cout<<"\n İnternet";
                cout<<"\n ";
                break;
            case 2:
                cout<<"\n                 ODANIN ÖZELLİKLERİ       ";
                cout<<"\n ---------------------------------------------------";
                cout<<"\n Oda Tipi         >>> Delüks";
                cout<<"\n Oda Fiyatı       >>> Günlük 7000₺";
                cout<<"\n Yatak Sayısı     >>> 1 Adet";
                cout<<"\n Balkon Mevcut";
                cout<<"\n ---------------------------------------------------";
                cout<<"\n                 EK ÖZELLİKLER";
                cout<<"\n ---------------------------------------------------";
                cout<<"\n Sabah kahvaltısı - Öğle yemeği - Akşam yemeği ÜCRETSİZ";
                cout<<"\n TV ";
                cout<<"\n İnternet";
                cout<<"\n ";
                break;
            case 3:
                cout<<"\n                 ODANIN ÖZELLİKLERİ       ";
                cout<<"\n ---------------------------------------------------";
                cout<<"\n Oda Tipi         >>> Normal";
                cout<<"\n Oda Fiyatı       >>> Günlük 3000₺";
                cout<<"\n Yatak Sayısı     >>> 1 Adet";
                cout<<"\n Balkon Mevcut";
                cout<<"\n ---------------------------------------------------";
                cout<<"\n                 EK ÖZELLİKLER";
                cout<<"\n ---------------------------------------------------";
                cout<<"\n Sabah kahvaltısı  ÜCRETSİZ";
                cout<<"\n TV ";
                cout<<"\n İnternet";
                cout<<"\n ";
                break;
            case 4:
                cout<<"\n                 ODANIN ÖZELLİKLERİ       ";
                cout<<"\n ---------------------------------------------------";
                cout<<"\n Oda Tipi         >>> Çift Kişilik";
                cout<<"\n Oda Fiyatı       >>> Günlük 4500₺";
                cout<<"\n Yatak Sayısı     >>> 2 Adet";
                cout<<"\n Balkon Mevcut";
                cout<<"\n ---------------------------------------------------";
                cout<<"\n                 EK ÖZELLİKLER";
                cout<<"\n ---------------------------------------------------";
                cout<<"\n Sabah kahvaltısı ÜCRETSİZ";
                cout<<"\n TV ";
                cout<<"\n İnternet";
                cout<<"\n ";
                break;
            case 5:
                cout<<"\n                 ODANIN ÖZELLİKLERİ       ";
                cout<<"\n ---------------------------------------------------";
                cout<<"\n Oda Tipi         >>> Çift Kişilik Lüks";
                cout<<"\n Oda Fiyatı       >>> Günlük 7000₺";
                cout<<"\n Yatak Sayısı     >>> 2 Adet";
                cout<<"\n Balkon Mevcut";
                cout<<"\n ---------------------------------------------------";
                cout<<"\n                 EK ÖZELLİKLER";
                cout<<"\n ---------------------------------------------------";
                cout<<"\n Sabah kahvaltısı - Öğle yemeği - Akşam yemeği ÜCRETSİZ";
                cout<<"\n TV ";
                cout<<"\n İnternet";
                cout<<"\n ";
                break;
                
        }
        cout<<"1- Rezervasyon\n 2- Odalar\n 3- Menu"<<endl;
        cin>>sec;
        if(sec==1)
            rezervasyon();
        else if(sec==2)
            odaOzellikleri();
        else if(sec==3)
            musteriSayfa();
        
    }
}
void hotel::rezervasyon(string dosyaAdi) {
    ifstream dosyaOku(dosyaAdi);
    if (dosyaOku.is_open()) {
        string satir;
        
        while (getline(dosyaOku, satir)) {
            stringstream ss(satir);
            string kelime;
            while (getline(ss, kelime, ',')) {
                stringstream kelimeStream(kelime);
                string odaTipi, odaNumarasiStr;
                kelimeStream >> odaTipi >> odaNumarasiStr;
                obje1.getOdaListesi().push_back(odaNumarasiStr);
            }
        }
        dosyaOku.close();
    } else {
        cerr << "Dosya açılamadı!" << endl;
        return;
    }

    bool odaBulundu = false;
    while (!odaBulundu) {
        odaNumaralari();
        cout << "Lütfen oda numarasını giriniz: ";
        cin >> odaNumarasi;
        string secilenOdaNumarasi = to_string(odaNumarasi);

        if (find(obje1.getOdaListesi().begin(), obje1.getOdaListesi().end(), secilenOdaNumarasi) != obje1.getOdaListesi().end()) {
            cout << secilenOdaNumarasi << " numaralı oda için rezervasyon yapılıyor..." << endl;
            odaBulundu = true;
            musteriBilgileri();
            bilgileriKaydet();
        } else {
            cout << "Geçersiz oda numarası. Lütfen geçerli bir oda numarası giriniz." << endl;
        }
    }
}

void yonetici::odaGuncelle(string dosyaAdi) {
    cout << "Lütfen güncellemek istediğiniz oda tipini seçiniz" << endl;
    cout << "1- Özel Lüks\n2- Deluks\n3- Normal\n4- Çift Kişilik\n5- Çift Kişilik Lüks" << endl;
    int secim;
    cin >> secim;
    if (secim < 1 || secim > 5) {
        cerr << "Geçersiz oda tipi seçimi!" << endl;
        return;
    }
    switch (secim) {
        case 1: obje2.setOdaTipi("OzelLuks") ; break;
        case 2: obje2.setOdaTipi("Deluks"); break;
        case 3: obje2.setOdaTipi("Normal"); break;
        case 4: obje2.setOdaTipi("CiftKisilik"); break;
        case 5: obje2.setOdaTipi("CiftKisilikLuks"); break;
    }

    ifstream dosyaOku(dosyaAdi);
    if (!dosyaOku.is_open()) {
        cerr << "Dosya açma hatası!" << endl;
        return;
    }

    string satir;
    while (getline(dosyaOku, satir)) {
        obje1.getOdaListesi().push_back(satir);
    }
    dosyaOku.close();

    int eskiOdaNumarasi, yeniOdaNumarasi;
    cout << "Güncellemek istediğiniz eski oda numarasını girin: ";
    cin >> eskiOdaNumarasi;
    string eskiVeri = obje2.getOdaTipi() + " " + to_string(eskiOdaNumarasi);

    bool odaBulundu = false;
    for (size_t i = 0; i < obje1.getOdaListesi().size(); ++i) {
        size_t pos = obje1.getOdaListesi()[i].find(eskiVeri);
        if (pos != string::npos) {
            odaBulundu = true;
            cout << "Yeni oda numarasını girin: ";
            cin >> yeniOdaNumarasi;
            string yeniVeri = obje2.getOdaTipi() + " " + to_string(yeniOdaNumarasi);
            obje1.getOdaListesi()[i].replace(pos, eskiVeri.length(), yeniVeri);
            break;
        }
    }

    if (!odaBulundu) {
        cout << "Belirtilen eski oda numarası bulunamadı." << endl;
        return;
    }

    ofstream dosyaYaz(dosyaAdi);
    if (!dosyaYaz.is_open()) {
        cerr << "Dosya yazma hatası!" << endl;
        return;
    }
    
    for (const auto& odalar : obje1.getOdaListesi()) {
        dosyaYaz << odalar << "\n";
    }
    dosyaYaz.close();
    cout << "Oda başarıyla güncellendi." << endl;
}





// repo cleanup
