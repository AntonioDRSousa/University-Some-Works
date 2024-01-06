
clc
clear
close all

A = [2 1 1; 1 2 1; 1 1 2];
b = [4; 4; 4];
x0 = [0; 0; 0];
tol = 1.0e-3;
maxiter = 100;

%n = 500;
%B = randn(n,n);
%A = B*B' + n*eye(n); % symmetric positive definite
%A = ones(n,n) + 2*n*eye(n); % strictly diagonally dominant
%b = A*ones(n,1);
%x0 = zeros(n,1);

tic
xlu = lusolver(A,b);
toc

tic
xchol = cholsolver(A,b);
toc

tic
xjac = jacobi(A,b,x0,tol,maxiter);
toc

tic
xgs = gseidel(A,b,x0,tol,maxiter);
toc