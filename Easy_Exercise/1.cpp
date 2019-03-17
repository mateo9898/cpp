#include<cstdlib>
#include<iostream>
#include<ctime>
using namespace std;
int wariantA(int *tablica, int ileElementow, int liczba){
	int licznik=0;
	for(int i=0;i<ileElementow;i++){
		int *w=&tablica[i];
		if(*w>liczba){
			licznik++;
		}
		else if(*w<liczba){
			*w=0;
		}
	}
	return licznik;
}
int main(int argc, char ** argv){
	int ileElementow,liczba;
	cout<<"Podaj liczbe elementow: ";
	cin>>ileElementow;
	int *tablica;
	tablica=new int[ileElementow];
	srand(time(NULL));
	for(int i=0;i<ileElementow;i++){
		tablica[i]=rand()%10+1;
		cout<<tablica[i]<<", ";
	}
	cout<<endl<<"Podaj liczbe: ";
	cin>>liczba;
	cout<<endl<<"Liczba elementow wiekszych od liczby: "<<wariantA(tablica,ileElementow,liczba)<<endl;
	for(int i=0;i<ileElementow;i++){
		cout<<tablica[i]<<", ";
	}
}
