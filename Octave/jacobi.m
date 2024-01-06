function [x,k] = jacobi(A,b,x0,tol,maxiter) 
    n = size(A,1);
    D = diag(diag(A));
    M = eye(n)-D\A;
    c = D\b;
    k = 0;
    while norm(b-A*x0)>tol && k<maxiter
        k = k+1;
        x0 = M*x0+c;
    end
    if k == maxiter
        x = x0;
        disp('Jacobi method does not converge');
        return
    end
    x = x0;
return