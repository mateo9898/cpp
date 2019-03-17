#include<cstdlib>
#include<iostream>
#include<ctime>
#include<cfloat>
using namespace std;
double wariantA(double *tablica, int ileElementow, bool liczMin){
	if(liczMin==true){
		double min=DBL_MAX;
		for(int i=0;i<ileElementow;i++){
			double *w=&tablica[i];
			if(min>*w){
				min=*w;
			}
		}
		return min;
	}
	else{
		double max=DBL_MIN;
		for(int i=0;i<ileElementow;i++){
			double *w=&tablica[i];
			if(max<*w){
				max=*w;
			}
		}
		return max;
	}
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
	cout<<endl<<"Podaj 1 lub 0: ";
	cin>>cos;
	if(cos==1){
		liczMin=true;
	}
	else{
		liczMin=false;
	}
	if(liczMin==true){
		cout<<endl<<"Najmniejszy element: "<<wariantA(tablica,ileElementow,liczMin)<<endl;
	}
	else{
		cout<<endl<<"Najwiekszy element: "<<wariantA(tablica,ileElementow,liczMin)<<endl;
	}
}
