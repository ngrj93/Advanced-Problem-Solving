#include<stdio.h>
#include<stdlib.h>

int main(){
	int n;
	scanf("%d",&n);
	while(n!=0){
		int arr[n],i,temp[n],j=-1;
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		int count=1,flag=1;
		i=0;
		while(i<n){
			if(arr[i]==count){
				i++;
				count++;
			}
			else if(j>=0 && temp[j]==count){
				count++;
				j--;
			}
			else{
				temp[++j]=arr[i];
				if(j>0 && temp[j]>temp[j-1]){
					printf("no\n");
					flag=0;
					break;
				}
				i++;
			}
		}
		if(flag)
			printf("yes\n");
		scanf("%d",&n);
	}
	return 0;
}


