function [coef,tab] = divdifadd(xdat,ydat,tab)
	n = length(xdat)-1;
	tab = [tab zeros(n,1); ydat(n+1) zeros(1,n)];
	for k=2:n+1
		num = tab(n+1,k-1)-tab(n,k-1);
		den = xdat(n+1)-xdat(n+1-k+1);
		tab(n+1,k) = num/den;
	end
	coef = diag(tab);
return