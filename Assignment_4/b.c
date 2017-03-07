#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Order Order;

long long curtime=0;
long long holdontime=0;

struct Order{
	long long t;
	long long l;
};

void mergesort(Order [],int,int);
void merge(Order [],int,int,int);
void add_heap(Order [],Order,int *);
void min_heapify(Order [],int,int);
void extract_min(Order [],int*);

void mergesort(Order input[],int start,int end){
	if(start<end){
		int q=start+(end-start)/2;
		mergesort(input,start,q);
		mergesort(input,q+1,end);
		merge(input,start,q,end);
	}
}

void merge(Order input[],int start,int mid,int end){
	int i,j,k;	
	int left_count=mid-start+1;
	int right_count=end-mid;
	int total_count=left_count+right_count;
	Order *left=(Order*)malloc(sizeof(Order)*left_count);
	Order *right=(Order*)malloc(sizeof(Order)*right_count);
	for(i=0;i<left_count;i++)
		left[i]=input[start+i];
	for(i=0;i<right_count;i++)
		right[i]=input[mid+1+i];
	i=0,j=0,k=0;
	Order *total_array=(Order*)malloc(sizeof(Order)*total_count);
	while(i<left_count && j<right_count){
		if(left[i].t<right[j].t){
			total_array[k]=left[i];
			i++;k++;
		}
		else if(left[i].t>right[j].t){
			total_array[k]=right[j];
			j++;k++;
		}
		else{
			if(left[i].l<=right[j].l){
				total_array[k]=left[i];
				i++;k++;
			}
			else{
				total_array[k]=right[j];
				j++;k++;
			}
		}
	}
	while(i<left_count){
		total_array[k]=left[i];
		i++;k++;
	}
	while(j<right_count){
		total_array[k]=right[j];
		j++;k++;
	}
	for(i=0;i<total_count;i++)
		input[start+i]=total_array[i];
	free(left);
	free(right);
	free(total_array);
}

void add_heap(Order heap[],Order element,int *heapsize){
	heap[*heapsize]=element;
	(*heapsize)++;
	if(*heapsize==1)
		return;
	int parent=(*heapsize)/2-1;
	int i=*heapsize-1;
	int flag=1;
	while(flag && parent>=0 && heap[i].l<heap[parent].l){
		if(parent==0)
			flag=0;
		Order temp=heap[i];
		heap[i]=heap[parent];
		heap[parent]=temp;
		i=parent;
		if(parent%2)
			parent=parent/2;
		else
			parent=parent/2-1;
	}
}

void min_heapify(Order heap[],int current,int heapsize){
	int smallest=current;
	int left=2*current+1;
	int right=2*current+2;
	if(left<heapsize && heap[left].l<heap[smallest].l)
		smallest=left;
	if(right<heapsize && heap[right].l<heap[smallest].l)
		smallest=right;
	if(smallest!=current){
		Order temp=heap[current];
		heap[current]=heap[smallest];
		heap[smallest]=temp;
		min_heapify(heap,smallest,heapsize);
	}
}
	
void extract_min(Order heap[],int *heapsize){
	holdontime+=curtime+heap[0].l-heap[0].t;
	curtime+=heap[0].l;
	heap[0]=heap[*heapsize-1];
	(*heapsize)--;
	min_heapify(heap,0,*heapsize);
}

int main(){
	int c,i;
	scanf("%d",&c);
	Order *input=(Order *)malloc(sizeof(Order)*c);
	for(i=0;i<c;i++)
		scanf("%lld%lld",&input[i].t,&input[i].l);
	mergesort(input,0,c-1);
	Order *heap=(Order *)malloc(sizeof(Order)*c);
	int heapsize=0;
	curtime=input[0].t;
	i=0;
	while(i<c){
		if(input[i].t<=curtime){
			add_heap(heap,input[i],&heapsize);
			i++;
		}
		else if(heapsize==0){
			curtime=input[i].t;
			add_heap(heap,input[i],&heapsize);
			i++;
		}
		else
			extract_min(heap,&heapsize);
	}
	while(heapsize>0)
		extract_min(heap,&heapsize);
	printf("%lld\n",holdontime/c);
	free(input);
	free(heap);
	return 0;
}
