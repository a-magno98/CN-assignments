
n = 5;

for i=1:n

  A3 = zeros(n);	
	 for j=1:i
            for k=1:i
                if j==k
                    A3(j,k)=1;
                elseif j<k
                    A3(j,k) = -1;
                end
            end
        end

                               
	sv3 = svd(A3);


        A3pt = A3;
    
        for l=1:i
            A3pt(l,1)=A3pt(l,1)-2^(2-l);
        end
        
        A3p = eig(A3pt);

        
        if i==1
            A0=A3
            sv0=sv3
            A0p=A3p
        elseif i==2
            A1=A3
            sv1=sv3
            A1p=A3p
        elseif i==3
            A2=A3
            sv2=sv3
            A2p=A3p
        elseif i==4
            A3
            sv3
            A3p
        end
    
end
