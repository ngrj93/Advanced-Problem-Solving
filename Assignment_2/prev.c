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
	int t,i,j;
	scanf("%d",&t);
	char *sieve=(char *)calloc(MAXSIZE,sizeof(char));
	sieve[0]=sieve[1]='1';
	for(i=2;i<MAXSIZE;i++){
		if(!sieve[i]){
			for(j=i+i;j<MAXSIZE;j+=i)
				sieve[j]='1';
		}
	}
	while(t--){
		int n;
		scanf("%d",&n);
		long long num[n];
		for(i=0;i<n;i++)
			scanf("%lld",&num[i]);
		long long factors[5000]={0};
		int upper_bound=0;
		for(i=0;i<n;i++){
			int temp=(int)sqrt(num[i]);
			upper_bound=temp>upper_bound?temp:upper_bound;
		}
		int k=0,mflag=0,zflag=1;
		for(j=0;j<n;j++){
			while(!(num[j]%2)){
				num[j]/=2;
				mflag=1;
				factors[k]=2;
			}
		}
		if(mflag)
			k++;
		for(i=3;i<=upper_bound;i+=2){
			mflag=0,zflag=1;
			if(sieve[i]=='\0'){
				for(j=0;j<n;j++){
					if(num[j]!=1){
						zflag=0;
						while(!(num[j]%i)){
							mflag=1;
							num[j]/=i;
							factors[k]=i;
						}
					}
				}
				if(mflag)
					k++;
				if(zflag)
					break;
			}
		}
		mergesort(num,0,n-1);
		for(j=0;j<n;j++){
			if(num[j]!=1){
				factors[k]=num[j];
				k++;
			}
		}
		int ans=0;
		for(i=0;i<k;i++){
			if(factors[i]!=factors[i+1])
				ans++;
		}
		printf("%d\n",ans);
		for(i=0;i<k;i++){
			if(factors[i]!=factors[i+1])
				printf("%lld\n",factors[i]);
		}
	}
	free(sieve);
	return 0;
}
