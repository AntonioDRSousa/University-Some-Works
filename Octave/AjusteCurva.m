#linha azul -> polinomio de grau 3
#linha vermelha -> polinomio de grau 2
#linha amarela -> polinomio de grau 1
#linha roxa -> funcao seno

clc 
x=[0 pi/6 pi/3 pi/2 3*pi/4 4*pi/3 2*pi] #valores de x
y=[0 1/2 sqrt(3)/2 1 sqrt(2)/2 -sqrt(3)/2 0] #valores de y

A=vander(x,4)
b=y'
c=(A'*A)\(A'*b)#coeficientes do polinomio de grau 3
xgrid = 0:0.1:7;#eixo x vai de 0 ate' 7
p = @(z) polyval(c, z);
ygrid = p(xgrid);
plot(xgrid,ygrid)#plota polinomio de grau 3
hold on

A=vander(x,3)
c=(A'*A)\(A'*b)#coeficientes do polinomio de grau 2
p = @(z) polyval(c, z);
ygrid = p(xgrid);
plot(xgrid,ygrid)#plota polinomio de grau 2
hold on

A=vander(x,2)
c=(A'*A)\(A'*b)#coeficientes do polinomio de grau 1
p = @(z) polyval(c, z);
ygrid = p(xgrid);
plot(xgrid,ygrid)#plota polinomio de grau 1
hold on

plot(xgrid,sin(xgrid))#plota funcao seno
hold on

#observa-se que o polinomio de grau 3 é um bom ajuste da funcao seno para valores de x entre 0 e 7
