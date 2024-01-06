function [x,k] = gseidel(A,b,x0,tol,maxiter) 
    L = tril(A);
    U = triu(A,1);
    M = -L\U;
    c = L\b;
    k = 0;
    while norm(b-A*x0)>tol && k<maxiter
        k = k+1;
        x0 = M*x0+c;
    end
    if k == maxiter
        x = x0;
        disp('Gauss-Seidel method does not converge');
        return
    end
    
    x = x0;
return