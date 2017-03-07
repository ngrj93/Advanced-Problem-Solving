#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 100005
int list_primes(int[],long,long,int);

int list_primes(int sieve[],long m,long n,int len){
	int prime_count=0,i,j;
	while(m<MAX && m<=n){
		if(!sieve[m])
			prime_count++;
		m++;
		len--;
	}
	if(m<n){
		int *temp=(int*)calloc(len,sizeof(int));
		int b=(int)((long)ceil((double)m/2)*2-m);
		int ub=(int)sqrt(n);
		for(i=b;i<len;i+=2)
			temp[i]=1;
		for(i=3;i<=ub;i+=2){
			if(!sieve[i]){
				b=(int)((long)ceil((double)m/i)*i-m);
				for(j=b;j<len;j+=i)
					temp[j]=1;
			}
		}
		for(i=0;i<len;i++){
			if(!temp[i])
				prime_count++;
		}
		free(temp);
	}
	return prime_count;
}

int main(){
	int t,i,j;
	scanf("%d",&t);
	int* sieve=(int*)calloc(MAX,sizeof(int));
	sieve[0]=sieve[1]=1;
	for(i=2;i<MAX;i++){
		if(!sieve[i]){
			for(j=i+i;j<MAX;j+=i)
				sieve[j]=1;
		}
	}
	while(t--){
		long low,high;
		scanf("%ld%ld",&low,&high);
		int ans=list_primes(sieve,low,high,high-low+1);
		printf("%d\n",ans);
	}
	free(sieve);
	return 0;
}

		


