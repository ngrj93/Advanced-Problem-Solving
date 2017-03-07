#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 1000004

int main(){
	int t,i,j,k=0;
	scanf("%d",&t);
	char *prime=(char *)malloc(sizeof(char)*MAX);
	long arr[168][2];
	for(i=0;i<168;i++){
		arr[i][0]=0;
		arr[i][1]=1;
	}
	for(i=0;i<MAX;i++)
		prime[i]='0';
	prime[1]='1';
	arr[k][0]=2;
	for(i=4;i<MAX;i+=2){
		prime[i]='1';
		arr[k][1]++;
	}
	k++;
	for(i=3;i<MAX;i+=2){
		if(prime[i]=='0'){
			if(k<168)
				arr[k][0]=i;
			for(j=i+i;j<MAX;j+=i){
				if(prime[j]=='0' && k<168)
					arr[k][1]++;
				prime[j]='1';
			}
			k++;
		}
	}
	while(t--){
		long n;
		scanf("%ld",&n);
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
		if(num>=1000)
			count=1;
		else{
			for(i=0;i<168;i++){
				if(arr[i][0]==num){
					count=arr[i][1];
					break;
				}
			}	
		}
		printf("%ld\n",count);
	}
	return 0;
}

