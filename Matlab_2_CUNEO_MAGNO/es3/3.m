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

%Set vettore 
y = sin(A(:,2));

%Calcolo AtA, Aty:
AtA = A'*A;
Aty = A'*y;

%Calcolo delle soluzioni del sistema:

 %-per mezzo della decomposizione ai valori singolari calcolata all'esercizio 1
   r0 = svd([AtA Aty])

 %-per mezzo della decomposizione QR
   r1 = qr([AtA Aty])

 %-per mezzo delle equazioni normali AtAc=Aty
   r2 = Aty\AtA

 %-per mezzo del comando matlab c=A/y
   r3 = A\y
