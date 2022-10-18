%matricola : s4516855
d0 = 5;
d1 = 5;
m = 10*(d0+1)+d1;

%Creazione matrice
A = ones(m, 3);

    for i=1:m
       A(i,2) = i/m;
	  A(i,3) = A(i,2)^2;
    end

%Calcolo matrice trasposta
At = A';

%Calcolo le decomposizioni ai valori singolari di A e della sua trasposta
[U,svdA,V]=svd(A)
[Ut, svdAt, Vt]=svd(A');

%Calcolo autovalori
autovalAAt = eig(A*At);         
autovalAtA = eig(At*A);       

%Confronto l’immagine di A con la matrice dei vettori singolari sinistri di A rispetto la sua trasposta
immagineA = orth(A);
immagineAt = orth(A');
             
%Confrontare il nucleo di A con la matrice dei vettori singolari destri di A rispetto la sua trasposta
nucleoA = null(A);             
nucleoAt = null(A');       
 


                           
