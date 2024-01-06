function [x,iter] = newton(f,df,x0,tol,maxiter)
	iter = 0;
    error = inf;
    while error > tol && iter < maxiter
        iter = iter + 1;
        dx = - f(x0)/df(x0);
        x = x0 + dx;
        if error < abs(x-x0) #quando o metodo newton diverge
          fprintf("Divergiu \n");
          break;
        end
        if df(x0)=0
          fprintf("extremo local\n");
          break;
        endif
        error = abs(x-x0);
        x0 = x;
        fprintf('n = %3d x = %f error = %f \n',iter,x,error);
    end
    if error > tol
        x = NaN;
        fprintf("O erro nao esta' dentro da tolerancia esperada!\n");
    end
return