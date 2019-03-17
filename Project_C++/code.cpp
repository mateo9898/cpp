#include<cstdlib>
#include<iostream>
#include<string.h>
#include<string>
#include<fstream>
#include<cctype>
#include <algorithm>
#include <functional>
//#include<conio.h>
using namespace std;
class Praca {
	public:
	int id;
	string typPracy;
	string tytul;
	string nazwiskoAutora;
	string imionaAutora;
	int rok;
	string nazwiskoPromotora;
	string imionaPromotora;
	string slowaKlucze;
	string streszczenie;
};
class Biblioteka{
	public:
	Praca prace[1000];
	int ilePrac;
	void okreslanieWartosci(){//poczatek okreslanieWartosci
		int id1,rok1,takczynie;
		string typPracy1,tytul1,nazwiskoAutora1,imionaAutora1,nazwiskoPromotora1,imionaPromotora1,
		slowaKlucze1,streszczenie1;
		cout<<"Podaj ID: ";
		cin>>id1;
		for(int i=0;i<ilePrac;i++){
			if(prace[i].id==id1){
				cout<<"ID musi byc unikalne !!! Podaj unikalne id: ";
				cin>>id1;
				break;
			}
		}
		prace[ilePrac].id=id1;
		cout<<endl<<"Podaj typ pracy, dopuszczalne wartosci: 'inz', 'lic', 'mgr':";
		cin>>typPracy1;
		while(typPracy1!="inz"&&typPracy1!="lic"&&typPracy1!="mgr")	{
			cout<<endl<<"Podana zostala zla wartosc! Podaj ponownie: ";
			cin>>typPracy1;
		}
		prace[ilePrac].typPracy=typPracy1;
		cout<<endl<<"Podaj tytul pracy: ";
		cin.ignore();
		getline(cin,tytul1);
		prace[ilePrac].tytul=tytul1;
		cout<<endl<<"Podaj nazwisko autora: ";
		cin>>nazwiskoAutora1;
		prace[ilePrac].nazwiskoAutora=nazwiskoAutora1;
		cout<<endl<<"Podaj imiona autora oddzielone przecinkami: ";
		cin.ignore();
		getline(cin,imionaAutora1);
		prace[ilePrac].imionaAutora=imionaAutora1;
		cout<<endl<<"Podaj rok powstania pracy: ";
		cin>>rok1;
		while(rok1<2000){
			cout<<endl<<"Podales zly rok, podaj ponownie: ";
			cin>>rok1;
		}
		prace[ilePrac].rok=rok1;
		cout<<endl<<"Podaj nazwisko promotora: ";
		cin>>nazwiskoPromotora1;
		prace[ilePrac].nazwiskoPromotora=nazwiskoPromotora1;
		cout<<endl<<"Podaj imiona promotora oddzielone przecinkami: ";
		cin.ignore();
		getline(cin,imionaPromotora1);
		prace[ilePrac].imionaPromotora=imionaPromotora1;
		cout<<endl<<"Jesli chcesz dodac slowa klucze wpisz 1 jesli nie, wpisz jakakolwiek liczbe: ";
		cin>>takczynie;
		if(takczynie==1){
			cout<<endl<<"Podaj slowa klucze: ";
			cin.ignore();
			getline(cin,slowaKlucze1);
		}
		else{
			slowaKlucze1=="";
		}
		prace[ilePrac].slowaKlucze=slowaKlucze1;
		cout<<endl<<"Jesli chcesz dodac streszczenie wpisz 1 jesli nie, wpisz jakakolwiek liczbe: ";
		cin>>takczynie;
		if(takczynie==1){
			cout<<endl<<"Podaj strzeszczenie: ";
			cin.ignore();
			getline(cin,streszczenie1);
		}
		else{
			streszczenie1=="";
		}
		prace[ilePrac].streszczenie=streszczenie1;
		ilePrac++;
		interfejsProgramu();
	}//koniec okreslanieWartosci
	void skroconeWyswietlanie(){//poczatek skroconeWyswietlanie
	int numer,pozycja=0,licznik=0;
	cout<<"Podaj numer tablicy ktory ma zostac wyswietlony: ";
	cin>>numer;
	cout<<endl<<prace[numer].id<<" "<<prace[numer].typPracy<<" ";
	string slowo = prace[numer].imionaAutora;
	char input[slowo.length()];
	for(int i=0;i<slowo.length();i++){
		input[i]=slowo[i];
		licznik++;
	}
	string slowa[licznik];
 	char *token;
 	token = strtok(input," ,.");
	licznik=0;
 	while(token != NULL)
 	{
 		slowa[licznik]=token;
   		licznik++;
   		token = strtok(NULL, " ,.");
 	}
 	for(int i=0;i<licznik-1;i++){
 		cout<<slowa[i][0]<<". ";
	}
	cout<<prace[numer].nazwiskoAutora<<" "<<prace[numer].tytul<<
	" "<<prace[numer].rok<<endl;
	int x;
	cout<<endl<<"Podaj jakakowliek liczbe aby powrocic do menu: ";
	cin>>x;
	switch(x){
		default:{
			interfejsProgramu();
			break;
		}
	}
	}//koniec skroconeWyswietlanie
	void wyswietlanieWPelnymFormacie(){//poczatek wyswietlanieWPelnymFormacie
	int numer,pozycja=0,licznik=0;
	cout<<"Podaj numer tablicy ktory ma zostac wyswietlony: ";
	cin>>numer;
	cout<<"---------------------------------------------------------------"<<endl<<
	"Id: "<<prace[numer].id<<endl<<"Typ: "<<prace[numer].typPracy<<endl<<"Autor: ";
	string slowo = prace[numer].imionaAutora;
	char input[slowo.length()];
	for(int i=0;i<slowo.length();i++){
		input[i]=slowo[i];
		licznik++;
	}
	string slowa[licznik];
 	char *token;
 	token = strtok(input," ,.");
	licznik=0;
 	while(token != NULL)
 	{
 		slowa[licznik]=token;
   		licznik++;
   		token = strtok(NULL, " ,.");
 	}
 	for(int i=0;i<licznik-1;i++){
 		cout<<slowa[i]<<" ";
	}
	cout<<" "<<prace[numer].nazwiskoAutora<<endl<<"Tytul: "<<prace[numer].tytul<<endl;
	if(prace[numer].slowaKlucze.length()>1){
		cout<<"Slowa kluczowe: "<<prace[numer].slowaKlucze<<endl;
	}
	cout<<"Rok: "<<prace[numer].rok<<endl<<"Promotor: ";
	licznik=0;
	slowo = prace[numer].imionaPromotora;
	input[slowo.length()];
	for(int i=0;i<slowo.length();i++){
		input[i]=slowo[i];
		licznik++;
	}
	slowa[licznik];
 	*token;
 	token = strtok(input," ,.");
	licznik=0;
 	while(token != NULL)
 	{
 		slowa[licznik]=token;
   		licznik++;
   		token = strtok(NULL, " ,.");
 	}
 	for(int i=0;i<licznik-1;i++){
 		cout<<slowa[i]<<" ";
	}
	cout<<prace[numer].nazwiskoPromotora<<endl;
	if(prace[numer].streszczenie.length()>1){
		cout<<"Streszczenie: "<<prace[numer].streszczenie<<endl;
	}
	cout<<"---------------------------------------------------------------";
	int x;
	cout<<endl<<"Podaj jakakowliek liczbe aby powrocic do menu: ";
	cin>>x;
	switch(x){
		default:{
			interfejsProgramu();
			break;
		}
	}
	}//koniec wyswietlanieWPelnymFormacie	
	void edycjaWartosci(){//poczatek edycjaWartosci
		int idedycja,nrpracy,nrcorobic;
		cout<<"Podaj id do edycji: ";
		cin>>idedycja;
		for(int i=0;i<ilePrac;i++){
			if(prace[i].id==idedycja){
				nrpracy=i;
				break;
			}
			if(i==999){
				bool x=false;
				while(x==false){
					cout<<endl<<"Podales zle id, podaj ponownie: ";
					cin>>idedycja;
					for(int i=0;i<ilePrac;i++){
						if(prace[i].id==idedycja){
							nrpracy=i;
							x=true;
							break;
						}
					}
				}
			}
		}
		cout<<endl<<"Co chcesz edytowac: "<<endl<<"1. Imiona autora"<<endl<<"2. Nazwisko Autora"<<endl
		<<"3. Typ pracy"<<endl<<"4. Rok powstania"<<endl<<"5. Tytul"<<endl<<"6. Slowa klucze."<<
		endl<<"7. Streszczenie"<<endl<<"Wybieraj: ";
		cin>>nrcorobic;
		switch (nrcorobic){
			case 1:{
				string pom;
				cin.ignore();
				cout<<endl<<"Edytujesz imiona autora. Wpisz nowe imiona: ";
				getline(cin,pom);
				prace[nrpracy].imionaAutora=pom;
				break;
			}
			case 2:{
				string pom;
				cout<<endl<<"Edytujesz nazwisko autora. Wpisz nowe nazwisko: ";
				cin>>pom;
				prace[nrpracy].nazwiskoAutora=pom;
				break;
			}
			case 3:{
				string pom;
				cout<<endl<<"Edytujesz typ pracy. Wpisz nowy typ pracy: ";
				cin>>pom;
				if(pom!="inc"&&pom!="mgr"&&pom!="inz"){
					cout<<endl<<"Niestety podales zly typ. Danie nie zostaly zmienione. ";
				}
				prace[nrpracy].typPracy=pom;
				break;
			}
			case 4:{
				int pom;
				cout<<endl<<"Edytujesz rok. Wpisz nowy rok: ";
				cin>>pom;
				if(pom<2000){
					cout<<endl<<"Niestety podales zly rok. Danie nie zostaly zmienione. ";
					break;
				}
				prace[nrpracy].rok=pom;
				break;
			}
			case 5:{
				string pom;
				cin.ignore();
				cout<<endl<<"Edytujesz tytul. Wpisz nowy tytul: ";
				getline(cin,pom);
				prace[nrpracy].tytul=pom;
				break;
			}
			case 6:{
				string pom;
				cin.ignore();
				cout<<endl<<"Edytujesz slowa klucze. Wpisz nowe slowa klucze: ";
				getline(cin,pom);
				prace[nrpracy].slowaKlucze=pom;
				break;
			}
			case 7:{
				string pom;
				cin.ignore();
				cout<<endl<<"Edytujesz streszczenie. Wpisz nowe streszczenie: ";
				getline(cin,pom);
				prace[nrpracy].streszczenie=pom;
				break;
			}
			default:{
				cout<<endl<<"Niestety podales cyfre ktora nie byla dostepna. ";
				break;
			}
		}
		interfejsProgramu();
	}//koniec edycjaWartosci
	void wyszukiwanieWartosci(){//pocatek wyszukiwanieWartosci
		int nrcorobic;
		cout<<endl<<"Po czym chcesz szukac: "<<endl<<"1. Nazwisko Autora"<<endl<<"2. Nazwisko Promotora"<<endl
		<<"3. Tytul"<<endl<<"4. Slowa klucze"<<endl<<"5. Streszczenie"<<endl<<"6. Rok"<<endl<<"Wybieraj: ";
		cin>>nrcorobic;
		switch(nrcorobic){
			case 1:{
				string slowopom;
				cin.ignore();
				cout<<endl<<"Podaj cale lub fragment nazwiska autora: ";
				getline(cin,slowopom);
				for(int i=0;i<ilePrac;i++){
					for(int j=0;j<prace[i].nazwiskoAutora.length();j++){
						bool cos=false;
						if(slowopom[0]==prace[i].nazwiskoAutora[j]){
							int pom=j;
							for(int k=0;k<slowopom.length();k++){
								if(slowopom[k]!=prace[i].nazwiskoAutora[pom]){
									break;
								}
								if(k==slowopom.length()-1){
									cos=true;
									wyswietlanieWartosciDoWyszukiwania(i);
								}
								pom++;
							}
						}
						if(cos==true){
							break;
						}
					}
				}
				break;
			}
			case 2:{
				string slowopom;
				cin.ignore();
				cout<<endl<<"Podaj cale lub fragment nazwiska promotora: ";
				getline(cin,slowopom);
				for(int i=0;i<ilePrac;i++){
					for(int j=0;j<prace[i].nazwiskoPromotora.length();j++){
						bool cos=false;
						if(slowopom[0]==prace[i].nazwiskoPromotora[j]){
							int pom=j;
							for(int k=0;k<slowopom.length();k++){
								if(slowopom[k]!=prace[i].nazwiskoPromotora[pom]){
									break;
								}
								if(k==slowopom.length()-1){
									cos=true;
									wyswietlanieWartosciDoWyszukiwania(i);
								}
								pom++;
							}
						}
						if(cos==true){
							break;
						}
					}
				}
				break;
			}
			case 3:{
				string slowopom;
				cin.ignore();
				cout<<endl<<"Podaj cale lub fragment tytulu: ";
				getline(cin,slowopom);
				for(int i=0;i<ilePrac;i++){
					for(int j=0;j<prace[i].tytul.length();j++){
						bool cos=false;
						if(slowopom[0]==prace[i].tytul[j]){
							int pom=j;
							for(int k=0;k<slowopom.length();k++){
								if(slowopom[k]!=prace[i].tytul[pom]){
									break;
								}
								if(k==slowopom.length()-1){
									cos=true;
									wyswietlanieWartosciDoWyszukiwania(i);\
								}
								pom++;
							}
						}
						if(cos==true){
							break;
						}
					}
				}
				break;
			}
			case 4:{
				string slowopom;
				cin.ignore();
				cout<<endl<<"Podaj cale lub fragment slowa klucze: ";
				getline(cin,slowopom);
				for(int i=0;i<ilePrac;i++){
					for(int j=0;j<prace[i].slowaKlucze.length();j++){
						bool cos=false;
						if(slowopom[0]==prace[i].slowaKlucze[j]){
							int pom=j;
							for(int k=0;k<slowopom.length();k++){
								if(slowopom[k]!=prace[i].slowaKlucze[pom]){
									break;
								}
								if(k==slowopom.length()-1){
									cos=true;
									wyswietlanieWartosciDoWyszukiwania(i);\
								}
								pom++;
							}
						}
						if(cos==true){
							break;
						}
					}
				}
				break;
			}
			case 5:{
				string slowopom;
				cin.ignore();
				cout<<endl<<"Podaj cale lub fragment streszczenia: ";
				getline(cin,slowopom);
				for(int i=0;i<ilePrac;i++){
					for(int j=0;j<prace[i].streszczenie.length();j++){
						bool cos=false;
						if(slowopom[0]==prace[i].streszczenie[j]){
							int pom=j;
							for(int k=0;k<slowopom.length();k++){
								if(slowopom[k]!=prace[i].streszczenie[pom]){
									break;
								}
								if(k==slowopom.length()-1){
									cos=true;
									wyswietlanieWartosciDoWyszukiwania(i);\
								}
								pom++;
							}
						}
						if(cos==true){
							break;
						}
					}
				}
				break;
			}
			case 6:{
				int rok;
				cout<<endl<<"Podaj rok: ";
				cin>>rok;
				for(int i=0;i<ilePrac;i++){
					if(prace[i].rok==rok){
						wyswietlanieWartosciDoWyszukiwania(i);
					}
				}
				break;
			}
			default:{
				cout<<endl<<"Niestety podales numer ktory nie byl do wyboru. ";
				break;
			}
	}
	int x;
	cout<<endl<<"Podaj jakakowliek liczbe aby powrocic do menu: ";
	cin>>x;
	switch(x){
		default:{
			interfejsProgramu();
			break;
		}
	}
	}//koniec wyszukiwanieWartosci
	void wyswietlanieWartosciDoWyszukiwania(int nrwtablicy){//poczatek wyswietlanieWartosciDoWyszukiwania
	cout<<endl<<prace[nrwtablicy].id<<" "<<prace[nrwtablicy].typPracy<<" ";
	int licznik=0;
	string slowo = prace[nrwtablicy].imionaAutora;
	char input[slowo.length()];
	for(int j=0;j<slowo.length();j++){
		input[j]=slowo[j];
		licznik++;
	}
	string slowa[licznik];
	char *token;
 	token = strtok(input," ,.");
	licznik=0;
 	while(token != NULL)
 	{
		slowa[licznik]=token;
   		licznik++;
   		token = strtok(NULL, " ,.");
 	}
 	for(int j=0;j<licznik-1;j++){
 		cout<<slowa[j]<<" ";
	}
	cout<<prace[nrwtablicy].nazwiskoAutora<<" "<<prace[nrwtablicy].tytul<<
	" "<<prace[nrwtablicy].rok;
	}//koniec wyswietlanieWartosciDoWyszukiwania
	void interfejsProgramu(){//poczatek interfejsProgramu
	int wybor;
	system("cls");
	cout<<"Witaj w naszej bibliotece!!! "<<endl
	<<"---------------------------------------------------------------"<<endl
	<<"Dostepne opcje: "<<endl<<"1. Dodanie nowej pracy dyplomowej."<<endl<<
	"2. Edycja danych. "<<endl<<"3. Wyswietlenie pojedynczych danych w skrocony sposob."<<
	endl<<"4. Wyswietlenie pojedynczych danych w rozbudowany sposob."<<endl<<
	"5. Szukanie danych wedlug kryteriow. "<<endl<<"6. Wyjscie z programu. "<<endl<<"7. Dodatkowe menu. "<<
	endl<<"Twoj wybor: ";
	cin>>wybor;
	switch (wybor){
		case 1:{
			system("cls");
			okreslanieWartosci();
			break;
		}
		case 2:{
			system("cls");
			edycjaWartosci();
			break;
		}
		case 3:{
			system("cls");
			skroconeWyswietlanie();
			break;
		}
		case 4:{
			system("cls");
			wyswietlanieWPelnymFormacie();
			break;
		}
		case 5:{
			system("cls");
			wyszukiwanieWartosci();
			break;
		}
		case 6:{
			const char *sciezka="C:\\Users\\Mateusz\\Desktop\\Projekt Programowanie Mateusz Wrzo³ G13\\dane.txt";
			zapiszWPliku(sciezka);
			break;
		}
		case 7:{
			system("cls");
			dodatkoweMenu();
			break;
		}
		default:{
			cout<<"Podales zla liczbe!!! Podaj jeszcze raz. ";
			interfejsProgramu();
			break;
		}
	}
	}//koniec interfejsProgramu
	void dodatkoweMenu(){//poczatek dodatkoweMenu
		int wybor;
		cout<<"Dodatkowe menu. "<<endl<<
		"---------------------------------------------------------------"<<endl<<
		"Dostepne opcje: "<<endl<<"1. Szukanie wedlug typu pracy. "<<endl<<
		"2. Liczba prac dla poszczegolnych promotorow. (srednio dziala)"<<endl<<
		"3. Najczesciej powtarzajace sie slowa kluczowe.(nie dziala) "<<endl<<"4. Powrot do menu glownego. "<<
		endl<<"Wybieraj: ";
		cin>>wybor;
		switch(wybor){
			case 1:{
				system("cls");
				string typ;
				cout<<"Podaj typ pracy: ";
				cin>>typ;
				for(int i=0;i<ilePrac;i++){
					if(prace[i].typPracy==typ){
						wyswietlanieWartosciDoWyszukiwania(i);
					}
				}
				int liczba;
				cout<<endl<<"Podaj liczbe aby powrocic do podmenu: ";
				cin>>liczba;
				switch(liczba){
					default:{
						system("cls");
						dodatkoweMenu();
						break;
					}
				}
				break;
			}
			case 2:{
				system("cls");
				string tabpomzewszystkim[ilePrac];
				for(int i=0;i<ilePrac;i++){
					tabpomzewszystkim[i]=prace[i].nazwiskoPromotora+","+prace[i].imionaPromotora;
				}
				sort(tabpomzewszystkim,tabpomzewszystkim+ilePrac);
				cout<<tabpomzewszystkim[2];
				for(int i=0;i<ilePrac;i++){
					int licznikprac=0;
					string pom=tabpomzewszystkim[i];
					string slowo="";
					for(int j=i;j<ilePrac;j++){
						if(pom!=tabpomzewszystkim[j]){
							int licznik=0;
							cout<<endl<<"Nazwisko i imiona promotora: ";
							slowo = pom;
							char input[slowo.length()];
							for(int k=0;k<slowo.length();k++){
							input[k]=slowo[k];
							licznik++;
							}
							string slowa[licznik];
 							char *token;
 							token = strtok(input," ,.");
							licznik=0;
 							while(token != NULL)
 							{
 								slowa[licznik]=token;
   								licznik++;
   								token = strtok(NULL, " ,.");
 							}
 							for(int m=0;m<licznik;m++){
 							cout<<slowa[m]<<" ";
							}
							cout<<"Ilosc prac: "<<licznikprac;
							i=j-1;
							licznikprac=0;
							break;
						}
						else{
							licznikprac++;
						}
					}
				}
				int liczba;
				cout<<endl<<"Podaj liczbe aby powrocic do podmenu: ";
				cin>>liczba;
				switch(liczba){
					default:{
						system("cls");
						dodatkoweMenu();
						break;
					}
				}
				break;
			}
			case 3:{
				system("cls");
				cout<<endl<<"Najczêstsze slowa klucze: ";
				string tab[10];
				/*for(int i=0;i<ilePrac;i++){
					int licznik=0;
					string slowo = prace[i].slowaKlucze;
					char input[slowo.length()];
					for(int k=0;k<slowo.length();k++){
					input[k]=slowo[k];
					licznik++;						}
					string slowa[licznik];
 					char *token;
 					token = strtok(input," ,.;");
					licznik=0;
 					while(token != NULL)
 					{
 					slowa[licznik]=token;
  					licznik++;
   					token = strtok(NULL, " ,.;");
 					}
 					int licznikwystapien[licznik];
 					for(int i=0;i<licznik;i++){
 						licznikwystapien[i]=0;
					 }
 					for(int i=0;i<licznik;i++){
 						for(int j=0;j<ilePrac;j++){
 							if()
						}
					}
				}
				int liczba;
				cout<<endl<<"Podaj liczbe aby powrocic do podmenu: ";
				cin>>liczba;
				switch(liczba){
					default:{
						system("cls");
						dodatkoweMenu();
						break;
					}
				}*/
				break;
			}
			case 4:{
				interfejsProgramu();
				break;
			}
			default:{
				system("cls");
				dodatkoweMenu();
				break;
			}
		}
	}//koniec dodatkoweMenu
	void wczytajZPliku(const char*nazwaPliku) {//poczatek wczytajZPliku
    int nrLini = 0;
    int nrPracy = 0;
    ifstream odczyt (nazwaPliku, std::ios::out);
    if(odczyt.is_open()) {

        string wiersz;

        while(getline(odczyt, wiersz)) {
            switch(nrLini) {
            case 0:{
				prace[nrPracy].id =  atoi(wiersz.c_str());   
				break;
			}
            case 1:{
                prace[nrPracy].typPracy = wiersz;
				break;
			}
            case 2:{
            	prace[nrPracy].tytul = wiersz;
				break;
			}
            case 3:{
				prace[nrPracy].nazwiskoAutora = wiersz;
				break;
			}
            case 4:{
            	prace[nrPracy].imionaAutora = wiersz;
				break;
			}
            case 5:{
            	prace[nrPracy].rok = atoi(wiersz.c_str());
				break;
			}
            case 6:{
            	prace[nrPracy].nazwiskoPromotora = wiersz;
				break;
			}
            case 7:{
            	prace[nrPracy].imionaPromotora = wiersz;
				break;
			}
            case 8:{
            	prace[nrPracy].slowaKlucze = wiersz;
				break;
			}
            case 9:{
            	prace[nrPracy].streszczenie = wiersz;
				break;
			}
            }

            if(nrLini == 9) {
                nrLini = -1;
                nrPracy++;
                ilePrac++;
            }
            nrLini++;
        }
    ilePrac=nrPracy;
	odczyt.close();
	interfejsProgramu();
    }
	}//koniec wczytajZPliku
	void zapiszWPliku(const char *sciezka){//poczatek zapiszWPliku
		ofstream wy(sciezka);
		if(wy.is_open()){
			for(int i=0;i<ilePrac;i++){
				ios::ate;
				wy<<prace[i].id<<endl<<prace[i].typPracy<<endl<<prace[i].tytul<<endl
				<<prace[i].nazwiskoAutora<<endl<<prace[i].imionaAutora<<endl<<
				prace[i].rok<<endl<<prace[i].nazwiskoPromotora<<endl<<
				prace[i].imionaPromotora<<endl<<prace[i].slowaKlucze<<endl<<
				prace[i].streszczenie<<endl;
			}
		}
		wy.close();
	}//koniec zapiszWPliku
};

int main(int argc, char ** argv){
	Biblioteka p1;
	const char *sciezka="C:\\Users\\Mateusz\\Desktop\\Projekt Programowanie Mateusz Wrzo³ G13\\dane.txt";
	p1.wczytajZPliku(sciezka);
}
