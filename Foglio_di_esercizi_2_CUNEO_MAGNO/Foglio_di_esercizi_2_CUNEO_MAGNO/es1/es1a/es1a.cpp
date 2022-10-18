#include <iostream>
#include <cmath>

using namespace std;;

#define N 4

int calcolo_norma(int M[N][N])
{
	int max = 0;
    
    for (int i = 0; i < N; ++i)
    {
        
        int sum = 0;
        
        for (int j = 0; j < N; ++j)
            sum += fabs(M[i][j]);
        
        if (sum > max)
            max = sum;
        
    }

	return max;
}

int main()
{
	
	int M1[N][N] = { {3, 1 -1, 0},
                     {0, 7, -3, 0},
                     {0, -3, 9, -2},
                     {0, 0, 4, -10} };
                     
	int M2[N][N] = { {2, 4, -2, 0},
                     {1, 3, 0, 1},
                     {3, -1, 1, 2},
                     {0, -1, 2, 1} };
                     
	
	cout<<"Calcolo norma matrice 1 è : "<<calcolo_norma(M1)<<endl;
	cout<<"Calcolo norma matrice 2 è : "<<calcolo_norma(M2)<<endl;
	return 0;
}
	
	
