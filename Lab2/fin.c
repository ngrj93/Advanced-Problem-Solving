#include<stdio.h>
#include<stdlib.h>
void mergesort(int,int);
void merge(int,int,int);
long int inversion_count=0;
long int *el;

void mergesort(int start,int end){
	if(start<end){
		int mid=(start+end)/2;
		mergesort(start,mid);
		mergesort(mid+1,end);
		merge(start,mid,end);
	}
}

void merge(int start,int mid,int end){
	int left_n=mid-start+1,right_n=end-mid,total_n=end-start+1;
	int *left=(int*)malloc(left_n*sizeof(int));
	int *right=(int*)malloc(right_n*sizeof(int));
	int *new_array=(int*)malloc(total_n*sizeof(int));
	int i,j;
	for(j=0,i=start;i<=mid;i++,j++)
		left[j]=el[i];
	for(j=0,i=mid+1;i<=end;i++,j++)
		right[j]=el[i];
	int k=0,l=0;
	for(i=0;k<left_n && l<right_n;i++){
		if(right[l]<left[k]){
			inversion_count+=left_n-k;
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
	int n,i;
	scanf("%d",&n);
	el=(long int*)malloc(n*sizeof(long int));
	for(i=0;i<n;i++)
		scanf("%ld",&el[i]);
	mergesort(0,n-1);
	printf("%ld\n",inversion_count);
	return 0;
}

