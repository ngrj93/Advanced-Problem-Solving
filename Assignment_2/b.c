#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100005

int main(){
	int t,i,j,n;
	scanf("%d",&t);
	int *sieve=(int*)calloc(MAXSIZE,sizeof(int));
	sieve[0]=sieve[1]=1;
	for(i=2;i<MAXSIZE;i++){
		if(!sieve[i]){
			for(j=i+i;j<MAXSIZE;j+=i)
				sieve[j]=1;
		}
	}
	while(t--){
		scanf("%d",&n);
		int flag=1;
		for(i=3;i<n;i+=2){
			if(!sieve[i] && !sieve[n-i] && (n-i)!=2){
				printf("%d %d\n",i,n-i);
				flag=0;
				break;
			}
		}
		if(flag)
			printf("%d\n",-1);
	}
	free(sieve);
	return 0;
}

			
