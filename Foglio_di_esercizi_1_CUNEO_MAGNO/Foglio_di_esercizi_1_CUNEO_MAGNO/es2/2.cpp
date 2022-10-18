#include <iostream>
#include <cmath>
using namespace std;
#define N1 4
#define N2 5

double fattoriale (int n)
{
	if(n>1)
		return n*fattoriale(n-1);
	else return 1;
	
}

int main()
{
    double x[N1]={0.5,30,-0.5,-30};
    int n[N2]={3,10,50,100,150};
    double f;
    
    cout<<endl<<"Calcolo con Algoritmo 1:"<<endl;

    for(int h=0; h<N1; ++h)
    {
        
        cout<<endl<<"\tValore X="<<x[h]<<endl;
        
        cout<<endl<<"*************************************************"<<endl<<endl;

        for(int g=0; g<N2; ++g)
	   {
            
           
            cout<<"CALCOLO CON X="<<x[h]<<" E N="<<n[g]<<endl<<endl;
		
            f=0;
	
            for(int k=0; k<=n[g]; ++k)
                f = f + pow(x[h], k) / fattoriale(k);
		
	
            cout<<"Approssimato: "<<f<<endl;
            cout<<"Calcolato con exp: "<<exp(x[h])<<endl;
            cout<<"Errore assoluto: "<<(double)abs(f-exp(x[h]))<<endl;
	   	  cout<<"Errore relativo: "<<(double)abs(f-exp(x[h]))/exp(x[h])<<endl;
	
		  cout<<endl<<"*******************************************************"<<endl<<endl;
        
        }
    }
    
    cout<<"############################################################################"<<endl;
    cout<<endl<<"Calcolo f(-0.5) e f(-30) con Algoritmo 2"<<endl;

    cout<<endl<<"\tValore X="<<x[3]<<endl;

    cout<<endl<<"*************************************************"<<endl<<endl;

    for(int c=0; c<N2; ++c)
    {
        
        f=0;
        for(int k=0; k<=n[c]; ++k)
		  f = f + pow(x[1], k) / fattoriale(k);

        cout<<"CALCOLO CON X=-"<<x[1]<<" E N="<<n[c]<<endl<<endl;
	   cout<<"Approssimato: "<<1/f<<endl;
        cout<<"Calcolato con exp: "<<exp(x[3])<<endl;
        cout<<"Errore assoluto: "<<(double)abs(f-exp(x[3]))<<endl;
	   cout<<"Errore relativo: "<<(double)abs(f-exp(x[3]))/exp(x[3])<<endl;

        cout<<endl<<"*************************************************"<<endl<<endl;
        
    }
        
        cout<<endl<<"\tValore X="<<x[2]<<endl;
        
        cout<<endl<<"*************************************************"<<endl<<endl;

        for(int c=0; c<N2; ++c)
	   {
      	 f=0;
        	 for(int k=0; k<=n[c]; ++k)
                f = f + pow(x[0], k) / fattoriale(k);
                
        
		   cout<<"CALCOLO CON X=-"<<x[0]<<" E N="<<n[c]<<endl<<endl;
		   cout<<"Approssimato: "<<1/f<<endl;
        	   cout<<"Calcolato con exp: "<<exp(x[2])<<endl;
		   cout<<"Errore assoluto: "<<(double)abs(f-exp(x[2]))<<endl;
		   cout<<"Errore relativo: "<<(double)abs(f-exp(x[2]))/exp(x[2])<<endl;

		   cout<<endl<<"*************************************************"<<endl<<endl;
        }

}
