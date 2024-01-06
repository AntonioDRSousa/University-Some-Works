function [x,iter] = t1(F,DF,x0,tol,maxiter)
	  iter = 0;
    error = inf;
    ##A = @(array) [x+y x-y; x*y x^2] comando do octave
    b = zeros(size(x0)); ## gera uma matriz de zeros com a dimensao de x0
    ##x=x0;
    for i = 1:size(x0)
          fprintf('   x0(%d) = %f\n',i,x0(i));
    endfor
    while error> tol && iter < maxiter 
        iter=iter + 1;
        D=inv(DF(x0));##inverte a matriz jacobiana
        dx=-(D*F(x0));
        x=x0+dx;;
        error = norm(x-x0); ## o erro e' calculado pela norma da diferenca entre x e x0
        x0=x;
        fprintf('n = %3d     error = %f\n',iter,error);
        for i = 1:size(x)
          fprintf('   x(%d) = %f\n',i,x(i));
        endfor
    end
    if error > tol
        x = NaN;
    end
    ##iter = iter + 1;
        ##dx = - f(x0)/df(x0);
        ##x = x0 + dx;
        ##error = abs(x-x0);
        ##x0 = x;
        ##fprintf('n = %3d x = %f error = %f \n',iter,x,error);
return