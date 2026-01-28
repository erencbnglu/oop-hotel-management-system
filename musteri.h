#ifndef musteri_h
#define musteri_h
using namespace std;


class musteri {
private:
    string isim;
    string soyisim;
    string telNo;
    int odaNumarasi;
    vector<string>odaListesi;
public:
    void setAd(string ad){
        this -> isim=ad;
    }
    void setSoyad(string soyisim){
        this -> soyisim=soyisim;
    }
    void setTelno(string telNo){
        this -> telNo=telNo;
    }
    void setOdaListesi(string liste, int index){
        odaListesi[index]+=liste;
    }
    string getAd(){
        return isim;
    }
    string getSoyad(){
        return soyisim;
    }
    string getTelno(){
        return telNo;
    }
    
    vector<string>&getOdaListesi() {
        return odaListesi;
    }

    
    void odaEkle(string ekle){
        odaListesi.push_back(ekle);
    };
    void musteriBilgileri();
    void bilgileriKaydet();
    
    
};




#endif

// repo cleanup
