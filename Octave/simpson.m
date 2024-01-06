function I = simpson(f,a,b,N)
	if b<a
    	error('Intervalo invalido');
	end
	if N<1
    	error('N deve ser maior do que 1');
	end
	if mod(N,2) ~= 0
    	error('N deve ser par');
	end
	dx = (b-a)/N;
	I = 0.0;
	for n=1:N/2
		x2nm2 = a + (2*n-2)*dx;
		x2nm1 = a + (2*n-1)*dx;
		x2n   = a + 2*n*dx;
    	I = I + (dx/3)*(f(x2nm2) + 4*f(x2nm1) + f(x2n));
	end
return