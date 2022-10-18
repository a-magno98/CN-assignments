%Set dimensione
n = 11;

%Creazione matrice di adiacenza A con valori nulli
A = zeros(n);

%Creazione vettore nodi adiacenti
adj_nodes = [1 7;1 6;1 5;1 2;1 3;1 4;3 10;10 11;10 4;4 5;5 6;5 8;6 8;8 9];

%Set adiacenza nella matrice
for i=1:14
	A(adj_nodes(i,1),adj_nodes(i,2))=1;
	A(adj_nodes(i,2),adj_nodes(i,1))=1;
end
 
%Creazione matrice diagonale
D = diag(sum(A));

%Calcolo matrice G
G = A*inv(D)

%Calcolo autovalori e autovettori
[V,D] = eig(G)

%Separo la prima colonna
x = V(:,1);

%Normalizzo in modo che la somma delle "importanze" sia uguale a 1
x = x/sum(x)
