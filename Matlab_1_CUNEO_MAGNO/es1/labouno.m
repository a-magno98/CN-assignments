%matricola : s4478234
d0=4;
d1=3;

%Calcolo dimensione
n=10*(d1+1)+d0;

%Creazione blocco di Jordan
A=diag(ones(1,n-1),1)+eye(n);

%Creazione matrice con valori nulli escluso E(n,1)=10^-n;
E=zeros(size(A));
E(n,1)=10^-n;

%Calcolo matrice perturbata
B=A+E;

%Calcolo autovalori A e B
VA=eig(A);
VB=eig(B);

%Confronto autovalori A e B
errore_relativo1=norm(B-A)/norm(A)
errore_relativo2=norm(VB-VA)/norm(VA) 

%Creazione matrici At*A e Bt*B
AtA=A'*A;
BtB=B'*B;

%Calcolo autovalori matrici trasposte
VAtA=eig(AtA);
VBtB=eig(BtB);

%Confronto autovalori A e B trasposte 
errore_relativo3=norm(BtB-AtA)/norm(AtA)
errore_relativo4=norm(VBtB-VAtA)/norm(VAtA) 
