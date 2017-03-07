#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAXSIZE 1000001

void mergesort(long long [], int,int);
void merge(long long [],int,int,int);

void mergesort(long long el[],int start,int end){
	if(start<end){
		int mid=(start+end)/2;
		mergesort(el,start,mid);
		mergesort(el,mid+1,end);
		merge(el,start,mid,end);
	}
}

void merge(long long el[],int start,int mid,int end){
	int left_n=mid-start+1,right_n=end-mid,total_n=end-start+1;
	long long *left=(long long*)malloc(left_n*sizeof(long long));
	long *right=(long*)malloc(right_n*sizeof(long long));
	long *new_array=(long*)malloc(total_n*sizeof(long long));
	int i,j;
	for(j=0,i=start;i<=mid;i++,j++)
		left[j]=el[i];
	for(j=0,i=mid+1;i<=end;i++,j++)
		right[j]=el[i];
	int k=0,l=0;
	for(i=0;k<left_n && l<right_n;i++){
		if(right[l]<left[k]){
			new_array[i]=right[l];
			l++;
		}
		else{
			new_array[i]=left[k];
			k++;
		}
	}
	while(k<left_n){
		new_array[i]=left[k];
		i++;k++;
	}
	while(l<right_n){
		new_array[i]=right[l];
		i++;l++;
	}
	for(j=0,i=start;i<=end;i++,j++)
		el[i]=new_array[j];
	free(new_array);
	free(left);
	free(right);
}

int main(){
	int t,i,j,q=0;
	scanf("%d",&t);
	char *sieve=(char *)calloc(MAXSIZE,sizeof(char));
	int *primes=(int*)malloc(80000*sizeof(int));
	sieve[0]=sieve[1]='1';
	primes[q++]=2;
	for(i=4;i<MAXSIZE;i+=2)
		sieve[i]='1';
	for(i=3;i<MAXSIZE;i+=2){
		if(sieve[i]=='\0'){
			primes[q++]=i;
			for(j=i+i;j<MAXSIZE;j+=i)
				sieve[j]='1';
		}
	}
	while(t--){
		int n,k=0;
		scanf("%d",&n);
		long long num[n];
		for(i=0;i<n;i++)
			scanf("%lld",&num[i]);
		long long factors[5000]={0};
		char *visited=(char *)calloc(MAXSIZE,sizeof(char));
		for(j=0;j<n;j++){
			for(i=0;i<q && ((long long)primes[i]*(long long)primes[i])<=num[j];i++){
				while(!(num[j]%primes[i])){
					num[j]/=primes[i];
					if(visited[primes[i]]=='\0'){
						factors[k++]=primes[i];
						visited[primes[i]]='1';
					}
				}
			}
			if(num[j]>1)
				factors[k++]=num[j];
		}
		mergesort(factors,0,k-1);
		int ans=0;
		for(j=0;j<k-1;j++){
			if(factors[j+1]!=factors[j])
				ans++;
		}
		if(k!=0)
			ans++;
		printf("%d\n",ans);
		for(i=0;i<k-1;i++){
			if(factors[i+1]!=factors[i])
				printf("%lld\n",factors[i]);
		}
		if(k!=0)
			printf("%lld\n",factors[i]);
		free(visited);
	}
	free(sieve);
	free(primes);
	return 0;
}
