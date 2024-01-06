function I = rectangle(f,a,b,N)
	if b<a
    	error('Intervalo invalido');
	end
	if N<1
    	error('N deve ser maior do que 1');
	end
	dx = (b-a)/N;
	I = 0.0;
	for n=1:N-1
		xn = a + (n-1)*dx;
    	I = I + dx*f(xn);
	end
return