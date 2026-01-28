#ifndef yonetici_h
#define yonetici_h

using namespace std;


class yonetici :public hotel{
private:
    int odaNo;
    hotel obje2;
    static const string dosya;
public:
    friend void musterileriGoster(string dosyaAdi , yonetici& frn);
    void giris();
    void Sayfa();
    void Sayfa(int admin);
    void odaSil(string dosyaAdi = dosya);
    void odaEkle(string dosyaAdi = dosya);
    void odaGuncelle(string dosyaAdi = dosya);
    void setOdaNo(int no) {
           odaNo = no;
       }

    int getOdaNo() const {
           return odaNo;
       }
    
    yonetici& operator+=(const string& yeniOda) {
            obje1.odaEkle(yeniOda);
            return *this;
        }
};

#endif

// repo cleanup
