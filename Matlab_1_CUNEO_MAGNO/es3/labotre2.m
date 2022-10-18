%Metodo delle potenze inverse

A = [1 -1 2;-2 0 5;6 -3 6];
v1 = [1 1 1]';
v2 = [3 10 40]';
tol = 10^-8;
I = [1 0 0;0 1 0;0 0 1];

lambda = 0;
lambda2 = 0;

p = 7;

x = v1/norm(v1);
x2 = v2/norm(v2);

k = 0;
i = 0;
Max_Iter = 100;

  while true
    k = k + 1;
    prev_lambda = lambda;

    x = (A-p*I)^-1 *x;

    x = x/norm(x);
    lambda = x'*A*x

    valdif = abs ( lambda - prev_lambda );
    
        if(or(valdif < tol*abs(lambda),k > Max_Iter)) 
          break;
        end
    end
    
   while true
    	i = i + 1;
    	prev_lambda = lambda2;

    	x2 = (A-p*I)^-1 *x2;
    	x2 = x2/norm(x2);
    	lambda2 = x2'*A*x2

    	valdif2 = abs ( lambda2 - prev_lambda );

        if(or(valdif2 < tol*abs(lambda2),i > Max_Iter)) 
          break;
        end
   end
    
