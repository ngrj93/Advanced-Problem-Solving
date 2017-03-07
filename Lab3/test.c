#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 1000004

int main(){
	int t,i,j;
	scanf("%d",&t);
	while(t--){
		long n;
		scanf("%ld",&n);
		char *prime=(char *)malloc(sizeof(char)*MAX);
		for(i=0;i<MAX;i++)
			prime[i]='0';
		prime[1]='1';
		for(i=2;i<n;i++){	
			if(prime[i]=='0'){
				for(j=i+i;j<MAX;j+=i)
					prime[j]='1';
			}
		}
		long num=MAX,count=0;
		if(prime[n]=='0')
			num=n;
		else{
			for(i=n;i<MAX;i++){
				if(prime[i]=='0'){
					num=i;
					break;
				}
			}
		}
		for(i=num;i<MAX;i+=num){
			if(prime[i]=='0')
				count++;
		}
		printf("%ld\n",count);
		free(prime);
	}
	return 0;
}


