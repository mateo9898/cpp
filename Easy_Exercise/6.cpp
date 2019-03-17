#include<iostream>
#include<cstdlib>
using namespace std;
char najczesciejWystepujacaLitera( char * napis ) {
	int licznik=0,licznikwystapien=0,licznik1=0,licznikwystapien1=0;;
	char wielka,mala,najwiecejwystepujaca='\0';
	char *w=&napis[licznik];
	char *w1=&napis[licznik1];
	while(*w!='\0'){
		wielka=toupper(*w);
		mala=tolower(*w);
		while(*w1!='\0'){
			if(*w1==mala||*w1==wielka){
				licznikwystapien++;
			}
			licznik1++;
			w1=&napis[licznik1];
		}
		licznik1=0;
		if(licznikwystapien>licznikwystapien1){
			licznikwystapien1=licznikwystapien;
			najwiecejwystepujaca=*w;
		}
		licznik++;
		w=&napis[licznik];
	}
	return najwiecejwystepujaca;
}
int main(int argc, char ** argv){
	string napis1;
	char z;
	cout<<"Podaj napis: ";
	getline(cin,napis1);
	char *napis=new char[napis1.size()];
	for(int i=0;i<napis1.length();i++){
		napis[i]=napis1[i];
	}
	cout<<endl<<"Najczesciej wystepujaca: "<<najczesciejWystepujacaLitera(napis);
}
