#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
bool jestPalindromem( char * napis )  {
	int licznik=0,licznik1=(strlen(napis)-1);
	char *w=&napis[licznik];
	char *w1=&napis[licznik1];
	while(*w!='\0'){
		if(*w!=*w1){
			return false;	
		}
		licznik++;
		licznik1--;
		w=&napis[licznik];
		w1=&napis[licznik1];
		while(*w==' '||*w1==' '){
			if(*w==' '){
				licznik++;
				w=&napis[licznik];
			}
			if(*w1==' '){
				licznik1--;
				w1=&napis[licznik1];
			}
		}
	}
	return true;
}
int main(int argc, char ** argv){
	string napis1;
	char z;
	cout<<"Podaj napis: "<<endl;
	getline(cin,napis1);
	char *napis=new char[napis1.size()];
	for(int i=0;i<napis1.length();i++){
		napis[i]=napis1[i];
	}
	if(jestPalindromem(napis) ==true){
		cout<<endl<<"Jest palindronem. ";
	}
	else{
		cout<<endl<<"Nie jest palindronem. ";
	}
}
