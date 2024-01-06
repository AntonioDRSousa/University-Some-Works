function [coef,tab] = divdif(xdat,ydat)
	n = length(xdat)-1;
	tab = zeros(n+1,n+1); 
	xdat = shiftdim(xdat); 
	ydat = shiftdim(ydat);
	tab(1:n+1,1) = ydat;
	for k = 2:n+1
		num = tab(k:n+1,k-1)-tab(k-1:n,k-1);
		den = xdat(k:n+1)-xdat(1:n+1-k+1);
    	tab(k:n+1,k) = num./den;
	end
	coef = diag(tab);
return