#include<stdio.h>
//lucky.c
void sort(int number[],int start,int end){
	int j;
	int key=0;
	while(key!=end){
		for(j=0;j<key;j++){
			if(number[j]>number[key]){
				int ch=number[key];
				int k,temp=number[j+1],temp2=number[j];
				for(k=j;k<key;k++){
					temp=number[k+1];
					number[k+1]=temp2;
					temp2=temp;
				}
				number[j]=ch;
			}
		}
		key++;
	}
}

void previous_permutation(int number[],int size){
	int i;
	for(i=0;i<size-1;i++){
		if(number[i]<number[i+1]){
			int max=0,j=0;
			for(j=0;j<=i;j++){
				if(number[j]<number[i+1] && (number[j]>number[max]||number[max]>=number[i+1])){
					max=j;
				}
			}
			int temp=number[max];
			number[max]=number[i+1];
			number[i+1]=temp;
			sort(number,0,i+1);
			break;
		}
	}
	for(i=size-1;i>=0;i--)
		if(number[i]!=0)	
			break;
	for(;i>=0;i--)
		printf("%d",number[i]);
	printf("\n");
}

int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int number[10]={0};
		int i=0;
		if(n==0)
			printf("%d\n",0);
		else{
			while(n!=0){
				number[i++]=n%10;
				n/=10;
			}
			previous_permutation(number,i);
		}
	}
	return 0;
}

