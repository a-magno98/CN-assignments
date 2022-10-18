#include <iostream>
#include <cmath>

using namespace std;

#define N 10

float calcolo_norma(float P[][N])
{
	float max = 0;
    
    for (int i = 0; i < N; ++i)
    {
        
        float sum = 0;
        
        for (int j = 0; j < N; ++j)
            sum += fabs(P[i][j]);
        
        if (sum > max
            max = sum;
    }

	return max;
}

float fattoriale(int n)
{
	if(n > 1)
		return n*fattoriale(n-1);
	else
		return 1;
}

void setMatrice(float P[][N])
{
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			P[i][j]=(fattoriale((i+1)+(j+1)-2))/(fattoriale(i)*fattoriale(j));
	
}

int main()
{
	
	float P[N][N];
	
	setMatrice(P);
    
	cout<<endl<<"Norma matrice Pascal: "<<calcolo_norma(P)<<endl<<endl;
}
	
