#ifndef hotel_hpp
#define hotel_hpp
#include <string>
#include <iostream>
#include "musteri.h"
class hotel:public musteri
{
private:
    int odaNumarasi;
    int odaEkleme;
    string odaTipi;
    static const string dosya;
protected:
    musteri obje1;

public:
    void musteriSayfa();
    void odaOzellikleri();
    void rezervasyon(string dosyaAdi = dosya);
    void odaNumaralari(string dosyaAdi = dosya);
    void musteriEkle() {
            musteriBilgileri();
            bilgileriKaydet();
        }
    int getOdaNumarasi() const {
           return odaNumarasi;
       }

       void setOdaNumarasi(int numara) {
           odaNumarasi = numara;
       }

       string getOdaTipi() const {
           return odaTipi;
       }

       void setOdaTipi(const string& tip) {
           odaTipi = tip;
       }
};




#endif
