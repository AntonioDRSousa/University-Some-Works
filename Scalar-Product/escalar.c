
float escalar(float a[],float b[],int n){
	if(n==0){
		return a[n]*b[n];
	}
	else{
		return a[n]*b[n]+escalar(a,b,n-1);
	}
}
