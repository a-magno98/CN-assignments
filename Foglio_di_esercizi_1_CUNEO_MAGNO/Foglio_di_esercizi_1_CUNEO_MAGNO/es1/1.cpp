#include <iostream>
#include <cmath>
using namespace std;


//Studente s4516855

int main()
{

 double d0 = 5;
 double d1 = 5;
 
 double a = 0;
 double b = 0;
 double c = 0;
 double res = 0;
 double res1 = 0;
 
 double mid = 0;
 double mid1 = 0;
 

 mid1 = pow(10, 20);
 b = (d1+1)*mid1;
 c = -b;
 
 for(int i = 0; i<7; ++i)
 {
	
	mid = pow(10, i);
	a = (d0 + 1)*mid;

	res = (a+b)+c;
	res1 = a+(b+c);
	
	cout<<"variabile a con i="<<i<<" :"<<a<<endl;
	cout<<"variabile b --> "<<b<<endl;

	cout<<"risultato op.1 --> (a+b)+c --> "<<res<<endl;
	cout<<"risultato op.2 --> a+(b+c) --> "<<res1<<endl;
	cout<<endl;
 }
 
 return 0;

}
