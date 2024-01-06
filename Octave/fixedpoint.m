function [x,iter] = fixedpoint(g,x0,tol,maxiter)
	iter = 0;
    error = inf;
    while error > tol && iter < maxiter
        iter = iter + 1;
        x = g(x0);
        error = abs(x-x0);
        x0 = x;
        fprintf('n = %3d x = %f error = %f \n',iter,x,error);
    end
return