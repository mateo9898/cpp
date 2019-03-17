#include<ctime>
#include<iostream>
#include<cstdlib>
using namespace std;
int kopiujLiczby(int *d, int *z){
	int liczba=0;
	while(*z!=0){
		if(*z>0){
			*d=*z;
			*d++;
			liczba++;
		}
		*z--;
	}
	*d=0;
	liczba++;
	return liczba;
}
int main (int argc, char ** argv){
	int liczba;
	cout<<"Podaj liczbe elementow: ";
	cin>>liczba;
	int tab[liczba];
	srand(time(NULL));
	cout<<endl;
	for(int i=0;i<liczba-1;i++){
		tab[i]=rand()%10-5;
		if(tab[i]==0){
			tab[i]++;
		}
		cout<<tab[i]<<", ";
	}
	tab[liczba-1]=0;
	int tab2[liczba];
	int *wsk=&tab[liczba-2];
	int *wsk2=&tab2[0];
	int wynik=kopiujLiczby(wsk2, wsk);
	cout<<endl<<"Liczba przekopiowanych elementow: "<<wynik;
	cout<<endl;
	for(int i=0;i<=wynik-1;i++){
		cout<<tab2[i]<<", ";
	}
}
