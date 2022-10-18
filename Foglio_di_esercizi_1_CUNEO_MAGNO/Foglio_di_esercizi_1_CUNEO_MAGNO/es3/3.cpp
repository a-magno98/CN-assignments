#include <iostream>
using namespace std;
#include <cmath>

//////////////////////////////// DOUBLE /////////////////////////////////////////////////////////////////////////

double powerd (double x, int n){

	int i;
	double p = 1;
     
	for (i=+1; i<=-n; ++i)
		p=p*x;
     
	double r = 1/p;
	return r;
	
}

////////////////////////////////// FLOAT ////////////////////////////////////////////////////////////////////////
	
float powerf (float x, int n){

	int i;
	float p = 1;
     
	for (i=+1; i<=-n; ++i)
		p=p*x;
     
	float r = 1/p;
	return r;
	
}

///////////////////////////////////// MAIN //////////////////////////////////////////////////////////////////////

int main(){
   
   int d=0;
   
   double epsd = 0;
   double resd=0;
   
   float epsf = 0;
   float resf = 0;
   
   
   
   while( (epsd = (1 + powerd(2,d))) > 1 )
   {
	resd = powerd(2,d);
	--d;
   }
	
   d = 0;	
	
   while( (epsf = (1 + powerf(2,d))) > 1 )
   {	
	resf = powerf(2,d);
	--d;
   }
  
   cout << endl << "RISULTATO DOUBLE: " <<  resd << endl;
   cout << endl<< "RISULTATO FLOAT: " <<  resf << endl<<endl;


   return 0;   
   
}
