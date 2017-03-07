#include<stdio.h>
#include<stdlib.h>
void mergesort(long [],int,int);
void merge(long [],int,int,int);

void mergesort(long arr[],int first,int last){
	if(first<last){
		int mid=(first+last)/2;
		mergesort(arr,first,mid);
		mergesort(arr,mid+1,last);
		merge(arr,first,mid,last);
	}
}

void merge(long arr[],int start,int mid,int end){
	int left_n=mid-start+1,right_n=end-mid,total_n=end-start+1;
	long *left=(long*)malloc(left_n*sizeof(long));
	long *right=(long*)malloc(right_n*sizeof(long));
	long *new_array=(long*)malloc(total_n*sizeof(long));
	int i,j;
	for(j=0,i=start;i<=mid;i++,j++)
		left[j]=arr[i];
	for(j=0,i=mid+1;i<=end;i++,j++)
		right[j]=arr[i];
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
		arr[i]=new_array[j];
	free(left);
	free(right);
	free(new_array);
}

int main(){
	int t,i,j;
	scanf("%d",&t);
	while(t--){
		int n,k;
		scanf("%d",&n);
		long *start=(long*)malloc(n*sizeof(long));
		long *finish=(long*)malloc(n*sizeof(long));
		for(i=0;i<n;i++)
			scanf("%ld",&start[i]);
		for(i=0;i<n;i++)
			scanf("%ld",&finish[i]);
		scanf("%d",&k);
		mergesort(start,0,n-1);
		mergesort(finish,0,n-1);
		int flag=1,count=0;
		if(k==0){
			printf("%d\n",0);
			continue;
		}
		else{
			for(i=0,j=0;i<n && j<n;){
				if(start[i]<finish[j]){
					count++;i++;
					if(count>k){
						printf("%d\n",0);
						flag=0;
						break;
					}
				}
				else{
					count--;
					j++;
				}
			}
		}
		if(flag)
			printf("%d\n",1);
	}
	return 0;
}

			

