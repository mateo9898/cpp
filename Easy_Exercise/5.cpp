#include<iostream>
#include<cstdlib>
using namespace std;
int ileWystapienZnakuWNapisie( char z, char * napis ){
	int licznik=0;
	int i=0;
	char mala=tolower(z),wielka=toupper(z);
	while(napis[i]!='\0'){
		if(napis[i]==mala||napis[i]==wielka){
			licznik++;
		}
		i++;
	}
	return licznik;
}
int main(int argc, char ** argv){
	string napis1;
	char z;
	cout<<"Podaj napis: ";
	getline(cin,napis1);
	cout<<"Podaj znak: ";
	cin>>z;
	char *napis=new char[napis1.size()];
	for(int i=0;i<napis1.length();i++){
		napis[i]=napis1[i];
	}
	cout<<endl<<ileWystapienZnakuWNapisie(z,napis );
}
