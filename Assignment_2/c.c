#include<stdio.h>
#include<stdlib.h>
void mergesort(int [],int,int);
void merge(int [],int,int,int);
int lower_binary_search(int [],int,int);
int upper_binary_search(int [],int,int);

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

int lower_binary_search(int arr[],int n,int elem){
	int start=0;
	int end=n-1;
	int mid,best=-1;
	while(start<=end){
		mid=(start+end)/2;
		if(arr[mid]<elem)
			start=mid+1;
		else if(arr[mid]==elem){
			best=mid;
			end=mid-1;
		}
		else
			end=mid-1;
	}
	return best;
}

int upper_binary_search(int arr[],int n,int elem){
	int start=0;
	int end=n-1;
	int mid,best=-1;
	while(start<=end){
		mid=(start+end)/2;
		if(arr[mid]<elem)
			start=mid+1;
		else if(elem==arr[mid]){
			best=mid;
			start=mid+1;
		}
		else
			end=mid-1;
	}
	return best;
}

int main(){
	int t,i;
	scanf("%d",&t);
	while(t--){
		int n,q;
		scanf("%d",&n);
		int *arr=(int *)malloc(n*sizeof(int));
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		mergesort(arr,0,n-1);
		scanf("%d",&q);
		while(q--){
			int denom;
			scanf("%d",&denom);
			int low=lower_binary_search(arr,n,denom);
			int up=upper_binary_search(arr,n,denom);
			if(low==-1)
				printf("%d\n",-1);
			else
				printf("%d\n",up-low+1);
		}
		free(arr);
	}
	return 0;
}
