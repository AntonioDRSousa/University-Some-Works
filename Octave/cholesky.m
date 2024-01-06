function G = cholesky(A)
    n=size(A,1);
    G=tril(A);
    for k=1:n
        G(k,k)=sqrt(G(k,k));
        G(k+1:n,k) = G(k+1:n,k)/G(k,k);
        for j=k+1:n
            G(j:n,j)=G(j:n,j)-G(j:n,k)*G(j,k);
        end
    end
return