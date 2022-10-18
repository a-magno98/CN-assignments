%%Metodo delle potenze

%Creazione matrice con valori
A = [1 -1 2;-2 0 5;6 -3 6];

%Creazione vettori trasposti
v1 = [1 1 1]';
v2 = [3 10 40]';

%Set tolleranza
tol = 10^-8;

%Set numero massimo di iterazioni
Max_Iter = 100;

%Variabili utilizzati per i contatori
k = 0;
i = 0;

%Autovalori da approssimare
lambda = 0;
lambda2 = 0;

%Normalizzo i vettori
q = v1/norm(v1);
q2 = v2/norm(v2);

	while true
	  
	   %iterazione
        k = k + 1;
	   prev_lambda = lambda;
     
        %Calcolo autovettore
        x = A * q;
	   %Normalizzo il vettore
        q = x/norm(x);
        %Calcolo autovalore
        lambda = q' * x
	
	   %Valore assoluto della differenza tra autovalore e il precedente
        valdif = abs ( lambda - prev_lambda );
	   
	   %Condizione
        if(or(valdif < tol*abs(lambda),k > Max_Iter)) 
          break;
        end
    end

    
    while true
	    %iterazione
         i = i + 1;
	    prev_lambda2 = lambda2;
     
        %Calcolo autovettore
        x2 = A * q2;
	   %Normalizzo il vettore
        q2 = x2/norm(x2);
        %Calcolo autovalore
        lambda2 = q2' * x2

	   %Valore assoluto della differenza tra autovalore e il precedente
        valdif2 = abs ( lambda2 - prev_lambda2 );
        
	   %Condizione
        if(or(valdif2 < tol*abs(lambda2), i > Max_Iter)) 
          break;
        end
    end
