#include <stdio.h>
#include <malloc.h>
//#define MAX 300000
#define ll long long  
ll heapsize;
ll c;
void swap(ll **A,ll x,ll y){
	ll temp[1][2];
	temp[0][0]=A[x][0];
	temp[0][1]=A[x][1];
	A[x][0]=A[y][0];
	A[x][1]=A[y][1];
	A[y][0]=temp[0][0];
	A[y][1]=temp[0][1];
}

void minheapify(ll **A,ll i){
	ll left,right,sm;
	left=2*i+1;
	right=2*i+2;
	if(left<heapsize && A[left][1]<A[i][1])
		sm=left;
	else
		sm=i;
	if(right<heapsize && A[right][1] <A[sm][1])
		sm=right;
	if(sm!=i){
		swap(A,i,sm);
		minheapify(A,sm);
	}

}

void buildheap(ll **A){
	ll i;
	for(i=heapsize/2-1;i>=0;i--)
		minheapify(A,i);
}

void deletemin(ll **H){
	//int min=H[0];
	swap(H,0,heapsize-1);
	heapsize--;
	minheapify(H,0);
	//return min;

}
void merg(ll **time,ll low,ll mid,ll high){
	ll temp[c][2],i,j,k=low;
	for(i=low,j=mid+1;i<=mid&&j<=high;){
		if(time[i][0]<=time[j][0]){
			temp[k][0]=time[i][0];
			temp[k++][1]=time[i++][1];
		}	
		else{
			temp[k][0]=time[j][0];
			temp[k++][1]=time[j++][1];
		}	
	}
	while(i<=mid){
		temp[k][0]=time[i][0];
		temp[k++][1]=time[i++][1];
	}
	while(j<=high){
		temp[k][0]=time[j][0];
		temp[k++][1]=time[j++][1];
	}	
	for(i=low;i<=high;i++){
		time[i][0]=temp[i][0];
		time[i][1]=temp[i][1];
	}	
			//printf("%d",time[i]);
	//printf("\n");		
}


void sort(ll **time,ll low,ll high){
	ll mid;	
	if(low<high){
		mid=(low+high)/2;
		sort(time,low,mid);
		sort(time,mid+1,high);
		merg(time,low,mid,high);

	}
}
void display(int A[][2],int c){
	int i;
	for (i=0;i<c;i++)
		printf("%d %d\n",A[i][0],A[i][1]);
}
void displayh(int H[][2]){
	int i;
	for (i=0;i<heapsize;i++){
		printf("%d %d",H[i][0],H[i][1]);
		printf("\n");
	}	

}
int main(){
	ll i;
	scanf("%lld",&c);
	//ll A[c][2],H[c][2];

	ll **A = (ll **)malloc(c * sizeof(ll *));
    for (i=0; i<c; i++)
         A[i] = (ll *)malloc(2 * sizeof(ll));
    ll **H = (ll **)malloc(c * sizeof(ll *));
    for (i=0; i<c; i++)
         H[i] = (ll *)malloc(2 * sizeof(ll));
	for(i=0;i<c;i++){
		scanf("%lld",&A[i][0]);
		scanf("%lld",&A[i][1]);
	}
	sort(A,0,c-1);
	//display(A,c);
	i=0;
	heapsize=0;
	ll burst=0;
	ll waittime=0; 
	
	int flag=0;	
	while(i<c){
		if(heapsize==0&&i<c){
			int j=i;
			while(j<c&&A[j][0]<=A[i][0]){
				H[heapsize][1]=A[j][1];
				H[heapsize][0]=A[j][0];
				heapsize++;
				j++;
			}
			i=j;
			buildheap(H);
			burst=H[0][0]+H[0][1];	
			waittime=waittime+burst-H[0][0];
			deletemin(H);
		}
		while(i<c&&A[i][0]<=burst){
			H[heapsize][1]=A[i][1];
		    H[heapsize][0]=A[i][0];
			heapsize++;
			i++;
			flag=1;
			//H[heapsize-1]=A[i][1];
		}
		if(flag){
			buildheap(H);
			flag=0;
		}	
		//displayh(H);
		//printf("%d %dHillol\n",heapsize,waittime);
		if(heapsize>0){
			burst+=H[0][1];
			waittime+=burst-H[0][0];
			deletemin(H);
		}	
		//displayh(H);
		//printf("%d %dpritam\n",heapsize,waittime);
		
	}
	while(heapsize>0){
		burst+=H[0][1];
		waittime+=burst-H[0][0];
		deletemin(H);
		//displayh(H);
		//printf("%d %ddiptam\n",heapsize,waittime);
	}
	printf("%lld\n",waittime/c );
	return 0;
}
