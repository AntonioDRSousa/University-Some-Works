function [x,iter] = bisection(f,a,b,tol)
	iter = 0;
    error = inf;
    while error > tol
        x = 0.5*(a+b);
        fa = f(a);
        fx = f(x);
        error = abs(b-a);
        fprintf('n = %3d x = %f error = %f \n',iter,x,error);
        if fa*fx < 0
            b = x;
        else
            a = x;
        end
        iter = iter + 1;
    end
return