#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
const int SIZE = 1000;
float tab[SIZE][2];
class pliki{
	public:
		ifstream wejscie;
		ofstream wyjscie;
	pliki();
	~pliki();
	bool sprawdz();
};
pliki::pliki(){
	wejscie.open("dane_ulamki.txt");
	wyjscie.open("wynik.txt");
}
pliki::~pliki(){
	wejscie.close();
	wyjscie.close();
}
bool pliki::sprawdz(){
	if(wejscie.good()&&wyjscie.good()) return true;
	else return false;
}
class ulamki:public pliki{
	public:
		
		float licznik = 999999999, mianownik = 999999999, MinUlamek = 999999999;
	  	float ulamek;
	void wczytaj();
	void licz();
	void zapisz();
};
void ulamki::wczytaj(){
	for (int i = 0; i < SIZE; i++) {
    wejscie >> tab[i][0] >> tab[i][1];
  	}
}
void ulamki::licz(){
	for (int i = 0; i < SIZE; i++) {
	    ulamek = tab[i][0] / tab[i][1];
	    if (ulamek <= MinUlamek) {
		    if (ulamek == MinUlamek && tab[i][1] > mianownik) continue;
		    MinUlamek = ulamek;
		    licznik = tab[i][0];
		    mianownik = tab[i][1];
    	}
  	}
  	zapisz();
}
void ulamki::zapisz(){
	wyjscie<<"Licznik: "<<licznik<<","<<" Mianownik: "<< mianownik << endl;
}
int main() {
  pliki p1;
  ulamki u1;
  if(!p1.sprawdz()) exit(0);
  else{
  	u1.wczytaj();
  	u1.licz();
  }
}
