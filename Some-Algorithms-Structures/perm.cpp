#include<stdio.h>
#include<iostream>
using namespace std;

int p[105];
int s[105];
int n;
int np=-1;
int num=0;

void perm(){
    int i,j;
    for(i=1;i<=n;i++){
        if(s[i]==0){
            np++;
            p[np]=i;
            s[i]=1;
            if(np==(n-1)){
                num++;
                for(j=0;j<n;j++){
                    cout<<p[j]<<" ";
                }
                cout<<endl;
           }
           else{
                perm();
           }
           np--;
           s[i]=0;
       }
    }
}

int main(){
    int i;
    cout<<"n = ";
    cin>>n;
    for(i=0;i<105;i++){
        p[i]=0;
        s[i]=0;
   }
    perm();
    cout<<endl<<endl<<"numero permutacoes = "<<num<<endl;
    return 0;
}
           
