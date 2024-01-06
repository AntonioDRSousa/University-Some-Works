function x = lusolver(A,b)
	[L,U]= ludecomp(A);
	y = forwardsub(L,b);
	x = backwardsub(U,y);
return