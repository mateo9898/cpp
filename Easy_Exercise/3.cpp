#include<cstdlib>
#include<iostream>
#include<ctime>
#include<math.h>
using namespace std;
double wariantA(double *tablica, int ileElementow){
	double suma=0,suma1=0,srednia,wariancja=100;
	for(int i=0;i<ileElementow;i++){
		double *w=&tablica[i];
		suma1+=*w;
	}
	srednia=suma1/ileElementow;
	for(int i=0;i<ileElementow;i++){
		double *w=&tablica[i];
		suma+=pow((*w-srednia),2);
	}
	wariancja=1.0/ileElementow*suma;
	return sqrt(wariancja);
}
int main(int argc, char ** argv){
	int ileElementow,cos;
	bool liczMin;
	double min=1.0,max=9.0;
	cout<<"Podaj liczbe elementow: ";
	cin>>ileElementow;
	double *tablica;
	tablica=new double[ileElementow];
	srand(time(NULL));
	for(int i=0;i<ileElementow;i++){
		tablica[i]=rand()/(RAND_MAX-1.0);
		tablica[i]=tablica[i]*(max-min)+min;
		cout<<tablica[i]<<", ";
	}
	cout<<endl<<"Wariancja wynosi: "<<wariantA(tablica,ileElementow);
}
