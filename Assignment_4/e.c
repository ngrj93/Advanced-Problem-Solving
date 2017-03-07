#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void mergesort(int [],int,int);
void merge(int[],int,int,int);
void max_heapify(int [],int,int);
int extract_max(int [],int *);

void mergesort(int arr[],int first,int last){
	if(first<last){
		int mid=(first+last)/2;
		mergesort(arr,first,mid);
		mergesort(arr,mid+1,last);
		merge(arr,first,mid,last);
	}
}

void merge(int arr[],int start,int mid,int end){
	int left_n=mid-start+1,right_n=end-mid,total_n=end-start+1;
	int *left=(int*)malloc(left_n*sizeof(int));
	int *right=(int*)malloc(right_n*sizeof(int));
	int *new_array=(int*)malloc(total_n*sizeof(int));
	int i,j;
	for(j=0,i=start;i<=mid;i++,j++)
		left[j]=arr[i];
	for(j=0,i=mid+1;i<=end;i++,j++)
		right[j]=arr[i];
	int k=0,l=0;
	for(i=0;k<left_n && l<right_n;i++){
		if(right[l]>left[k]){
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

int extract_max(int arr[],int *heapsize){
	int val=arr[0]--;	
	if(arr[0]==0){
		arr[0]=arr[*heapsize-1];
		(*heapsize)--;
	}
	max_heapify(arr,0,*heapsize);
	return val;
}

void max_heapify(int arr[],int cur,int heapsize){
	int largest=cur;
	int left=2*cur+1;
	int right=2*cur+2;
	if(left<heapsize && arr[left]>arr[largest])
		largest=left;
	if(right<heapsize && arr[right]>arr[largest])
		largest=right;
	if(largest!=cur){
		int temp=arr[cur];
		arr[cur]=arr[largest];
		arr[largest]=temp;
		max_heapify(arr,largest,heapsize);
	}
}

int main(){
	int m,n,i;
	scanf("%d%d",&m,&n);
	int *arr=(int*)malloc(sizeof(int)*m);
	for(i=0;i<m;i++)
		scanf("%d",&arr[i]);
	mergesort(arr,0,m-1);
	long long total=0;
	int heapsize=m;
	for(i=0;i<n;i++)
		total+=extract_max(arr,&heapsize);
	printf("%lld\n",total);
	free(arr);
	return 0;
}
