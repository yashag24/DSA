#include<stdio.h>
int main(){
printf("Enter the no. of lines:");
int n,p;
scanf("%d",&p);
n=2*p-1;
/*if(p%2==0){
    n=p-1;
    printf("Invalid input , showing result for %d lines.\n",n);
}*/
int nst =1,nsp=1;
int ml=n/2+1;
int k=1;
int m =2*n-1;
for(int i = 1;i<=m;i++){

for(int j=1;j<=nst;j++){
    printf(" %d ",nst);

}
printf("\n");
 if(ml>=i+1){
    nst++;
}
else{
    nst--;
}



}
}
