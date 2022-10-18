#include <iostream>
#include <cmath>
using namespace std;

//Matricola s4478234

#define dim 2
#define d0 4                                                                             
#define d1 3                                                                           
#define N2 10*(d1+1)+d0   

//////////// MATRICE TRIDIAGONALE ///////////////////////////////////////////////////////////                                                               
                                                                                         
void setMatriceT(float T[N2][N2],int n)                                                  
{                                                                                        
	for(int i = 0; i < n; ++i)                                                           
	{                                                                                    
		for(int j = 0; j < n; ++j)                                                       
		{                                                                                
			if(i == j)                                                                   
				T[j][i] = 2;                                                             
                                                                                         
			else if(fabs(i-j) == 1)                                                      
				T[j][i] = -1;                                                            
                                                                                         
			else                                                                        
				T[j][i] = 0;                                                             
		}                                                                                
	}                                                                                    
}                                                                                        
                                                                                         
///////////// MATRICE PASCAL ////////////////////////////////////////////////////////////////
#define N1 10                                                                            
                                                                                         
float fattoriale(int n)                                                                  
{                                                                                        
	if(n > 1)                                                                            
		return n*fattoriale(n-1);                                                        
	else                                                                                 
		return 1;                                                                        
}                                                                                        
                                                                                         
void setMatriceP(float P[N2][N2],int n)                                                  
{                                                                                        
	for(int i = 0; i < n; ++i)                                                           
		for(int j = 0; j < n; ++j)                                                       
			P[i][j]=(fattoriale((i+1)+(j+1)-2))/(fattoriale(i)*fattoriale(j));           
                                                                                         
}                                                                                        
                                                                                         
//////////////// CALCOLO TERMINI NOTI //////////////////////////////////////////////////////
                                                                                         
                                                                                         
void prodT(float mat[N2][N2], float mat1[N2],int n)
{                                     
                                                                                         
    for(int i =0; i<n; ++i){                                                             
        float sm=0;                                                                      
        for(int h=0; h<n; ++h)                                                           
            sm+=mat[i][h];                                                               
        mat1[i]=sm;                                                                      
    }                                                                                   
}                                                                                        
                                                                                        
///////////// MATRICE 1 e 2 /////////////////////////////////////////////////////////////////

#define N 4                
                                                           
///////////////////////////////////////// STAMPA ////////////////////////////////////////////
                                                                                         
void stampa(float M[N2],int n){                                                          
    cout<<endl;                                                                          
    for(int i = 0; i < n; ++i)                                                           
        cout<<M[i]<<endl;                                                                
    cout<<endl;                                                                          
}                                                                                        
                                                                                         
////////////////////////////////////// NORMA /////////////////////////////////////////////////////

float calcolo_norma(float T[N2][N2], int n)
{
	float max = 0;
    
    for (int i = 0; i < n; ++i) {
        
        float sum = 0;
        
        for (int j = 0; j < n; ++j) {
            sum += fabs(T[j][i]);
        }
        
        if (sum > max) {
            max = sum;
        }
        
    }
	
	return max;
}

/////////////////// CALCOLO IL VETTORE DI PERTUBAZIONI //////////////////////////////////////

void vettore_perturbazioni(float b[N2], float v[N2], float norma, int n)
{
	int j ;

	for(int i = 0; i < n; ++i)
	{
		j = 0;
		b[i]= b[i]+norma*v[j];
		j++;
		i++;
		b[i]= b[i]+norma*v[j];
	}
}


///////////////////////////////////////////////////////////////////////////////////////////
//                                      GAUSS                                            //
///////////////////////////////////////////////////////////////////////////////////////////

int pivoting_parziale(int j, float m[N2][N2], float t[N2],int n)
{
	int c,r;
	float aux;

	c=j;
	while( c<n && m[c][j]==0 ) 
		++c;

	if( c > n ) 
	{
		cout << "Pivot nullo\n\n";
		return -1;
	}

	if( c!=j )
	{
		for( r=j; r<n; r++ )
		{
			aux = m[j][r];
			m[j][r] = m[c][r];
			m[c][r] = aux;
		}

		aux = t[j];
		t[j] = t[c];
		t[c] = aux;
	}

return 0;
}

void gauss(float c_mat[N2][N2], float tn[N2], int n, int matr)
{
	float pivot, m ;
	float sol[N2];
	
	for(int j = 0; j < n-1; ++j)
	{
		if ( pivoting_parziale(j, c_mat, tn,n) == 0 )
			pivot = c_mat[j][j];
		else
		{
			cout<<"Sistema indeterminato"<<endl;
			return;
		}
	
		for(int i=j+1;i<n; i++)
		{
			m = c_mat[i][j]/pivot;
			
			if(m == 0)
				continue;

			for(int k=j; k<n; k++)
				c_mat[i][k]=c_mat[i][k]-m*c_mat[j][k];
	
			tn[i]=tn[i]-m*tn[j];
		} 

	} 

	if( c_mat[n-1][n-1] == 0)
	{
		cout << "Soluzioni infinite\n\n";
		cout<<"Sistema indeterminato"<<endl;
		return;
	}

	for(int i=n-1; i>=0; i--) 
	{
		float aux = tn[i];
		for(int k=i+1; k<n; k++)
			aux=aux-c_mat[i][k]*sol[k];

		sol[i] = aux/c_mat[i][i];
	}
	
	cout<<endl<<"Soluzioni matrice ";
	
	switch(matr)
	{
		case 0: cout<<"1:"<<endl;
		stampa(sol, n);	
		break;
	
		case 1: cout<<"2:"<<endl;
		stampa(sol, n);
		break;
	
		case 2: cout<<"PASCAL:"<<endl;
		stampa(sol, n);
		break;
	
		case 3: cout<<"TRIDIAGONALE:"<<endl;
		stampa(sol, n);
		break;
		
	}

return;
}

///////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////
//                                          MAIN                                         //
///////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	cout.precision(4);
	cout.setf(ios::fixed);

    float v[dim] = {-0.01, 0.01};

    /* matrice 1 */
    float M1[N2][N2] = {{3,1,-1,0},{0,7,-3,0},{0,-3,9,-2},{0,0,4,-10}};
    float b1[N2];
    prodT(M1,b1,N);
    
    float norma1 = calcolo_norma(M1,N);
    vettore_perturbazioni(b1,v,norma1,N);
	
    int mat = 0;
    gauss(M1, b1, N, mat);
    
    /* matrice 2 */
    float M2[N2][N2] = {{2,4,-2,0},{1,3,0,1},{3,-1,1,2},{0,-1,2,1}};
    float b2[N2];
    prodT(M2,b2,N);

    float norma2 = calcolo_norma(M2,N);
    vettore_perturbazioni(b2,v,norma2,N);

    mat++;
    gauss(M2, b2, N, mat);
	
    /* matrice Pascal */
    float P[N2][N2];
    float b3[N2];
    setMatriceP(P,N1);
    prodT(P,b3,N1);

    float norma3 = calcolo_norma(P,N1);
    vettore_perturbazioni(b3,v,norma3,N1);

    mat++;
    gauss(P, b3, N1, mat);

    /* matrice Tridiagonale */
    float T[N2][N2];
    float b4[N2];
    setMatriceT(T,N2);
    prodT(T,b4,N2);

    float norma4 = calcolo_norma(T,N2);
    vettore_perturbazioni(b4,v,norma4,N2);
 
    mat++;
    gauss(T,b4,N2,mat);
  
}

///////////////////////////////////////////////////////////////////////////////////////////
