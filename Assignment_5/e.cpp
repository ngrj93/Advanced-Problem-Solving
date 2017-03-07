#include<bits/stdc++.h>
using namespace std;

int m,n;
int x_d[]={1,0,-1,0};
int y_d[]={0,1,0,-1};

void dfs(int y,int x,int **arr){
	arr[y][x]=0;
	for(int k=0;k<4;k++){
		if(x+x_d[k]>=0 && x+x_d[k]<m && y+y_d[k]>=0 && y+y_d[k]<n && arr[y+y_d[k]][x+x_d[k]]==1)
			dfs(y+y_d[k],x+x_d[k],arr);
	}
}

int main(){
	cin>>n>>m;
	int **arr=new int*[n];
	for(int i=0;i<n;i++)
		arr[i]=new int[m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char c;
			cin>>c;
			arr[i][j]=(int)(c-48);
		}
	}
	int count=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]==1){
				count++;
				dfs(i,j,arr);
			}
		}
	}
	cout<<count<<endl;
	for(int i=0;i<n;i++)
		delete arr[i];
	delete [] arr;
	return 0;
}


