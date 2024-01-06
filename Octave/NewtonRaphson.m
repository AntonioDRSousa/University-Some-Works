function x = NewtonRaphson(F,DF,x0,tol,maxiter)
	  iter = 0;
    error = inf;
    b = zeros(size(x0)); # gera uma matriz de zeros com a dimensao de x0
    
    while error> tol && iter < maxiter
        iter=iter + 1;#incrementa
        
        if det(DF(x0))==0 #verifica se a matriz DF e' invertivel
          fprintf("extremo local\n");
          break;
        endif
        
        D=inv(DF(x0));#inverte a matriz jacobiana
        dx=D*F(x0);
        x=x0-dx;
        
        n= norm(x-x0);#norma
        if error < n #verifica se o erro atual e' maior que o anterior, ou seja, se houve uma divergencia
          fprintf("Divergiu \n");
          break;
        endif
        
        error = n; # o erro e' calculado pela norma da diferenca entre x e x0
        x0=x;
        
        fprintf('n = %3d     error = %f\n',iter,error); #printa a iteracao e o erro
        #printa valores da matriz x
        for i = 1:size(x)
          fprintf('   x(%d) = %f\n',i,x(i));
        endfor
        
        if iter==maxiter && error>tol #verifica se o metodo convergiu em maxiter iteracao
          fprintf("Nao atingiu um erro menor ou igual a tolerancia %f em %d iteracoes\n",tol, maxiter);
        endif      
    end
    if error > tol #atribui valor "not a number" para valores com erros maior que a tolerancia
        x = NaN;
    endif
return