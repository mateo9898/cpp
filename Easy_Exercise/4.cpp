#include<cstdlib>
#include<iostream>
#include<ctime>
using namespace std;
int kopiujPowyzejSredniej( double * d, double * z, int ileElementow ) {
	int licznik=0;
	double srednia,suma=0;
	for(int i=0;i<ileElementow;i++){
		double *w=&z[i];
		suma+=*w;
	}
	srednia=suma/ileElementow;
	for(int i=0;i<ileElementow;i++){
		double *w=&z[i];
		double *w1=&d[licznik];
		if(*w>srednia){
			*w1=*w;
			licznik++;	
		}
	}
	return licznik;
}
int main(int argc, char ** argv){
	int ileElementow,liczba;
	double min=1.0,max=9.0;
	cout<<"Podaj liczbe elementow: ";
	cin>>ileElementow;
	double *d,*z;
	d=new double[ileElementow];
	z=new double[ileElementow];
	srand(time(NULL));
	for(int i=0;i<ileElementow;i++){
		z[i]=rand()/(RAND_MAX+1.0);
		z[i]=z[i]*(max-min)+min;
		cout<<z[i]<<", ";
	}
	cout<<endl<<"Powyzej sredniej: "<<kopiujPowyzejSredniej(d,z,ileElementow )<<endl;
	for(int i=0;i<kopiujPowyzejSredniej(d,z,ileElementow );i++){
		cout<<d[i]<<", ";
	}
}
