function y = interplagrange(xdat,ydat,x)	n = length(xdat);	L = ones(n,length(x));	for i = 1:n    	for j = 1:n			if i ~= j				L(i,:) = L(i,:).*(x-xdat(j))./(xdat(i)-xdat(j));			end 
		end	end	y = ydat'*L;
return