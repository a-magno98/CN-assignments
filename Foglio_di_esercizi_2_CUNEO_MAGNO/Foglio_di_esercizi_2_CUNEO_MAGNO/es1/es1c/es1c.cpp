#include <iostream>
#include <cmath>

using namespace std;

//Matricola s4478234
#define d0 4
#define d1 3
#define N 10*(d1+1)+d0

int calcolo_norma(int T[N][N])
{
	int max = 0;
    
    for (int i = 0; i < N; ++i)
    {
        
        int sum = 0;
        
        for (int j = 0; j < N; ++j)
            sum += fabs(T[i][j]);
        
        if (sum > max)
            max = sum;

    }

	return max;
}

void setMatrice(int T[][N])
{
	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			if(i == j)
				T[i][j] = 2;

			else if(fabs(i-j) == 1)
				T[i][j] = -1;
			
			else
				T[i][j] = 0;
		}
	}
}
	
int main()
{
	int T[N][N];
	
	setMatrice(T);
    
	cout<<endl<<"La norma infinto della matrice: "<<calcolo_norma(T)<<endl<<endl;

}
	
	
	
	

