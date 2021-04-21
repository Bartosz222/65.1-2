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
	void zapisz(int counter);
	void licz();
	int NWD(int x, int y);
};
void ulamki::wczytaj(){
	for (int i = 0; i < SIZE; i++) {
    wejscie >> tab[i][0] >> tab[i][1];
  	}
}
int ulamki::NWD(int x, int y){
	if (x < y) return NWD(y, x);
  	if (y == 0) return x;
  	return NWD(y, x % y);
}
void ulamki::licz(){
	int counter = 0;
  	for (int i = 0; i < SIZE; i++) {
    	if (NWD(tab[i][0], tab[i][1]) > 1) continue;
    	counter++; 
  	}
  	zapisz(counter);
}
void ulamki::zapisz(int counter){
	wyjscie<<counter<<endl;
}
int main(int argc, char** argv) {
	pliki p1;
  ulamki u1;
  if(!p1.sprawdz()) exit(0);
  else{
  	u1.wczytaj();
  	u1.licz();
  }
}
