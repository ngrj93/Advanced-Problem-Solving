#include<bits/stdc++.h>
#define MAXSIZE 1001
using namespace std; 
char grid[MAXSIZE][MAXSIZE];
int h,w;
int x_d[]={0,0,1,1,1,-1,-1,-1};
int y_d[]={1,-1,0,1,-1,0,-1,1};

int dfs(int y,int x,int visited[MAXSIZE][MAXSIZE]){
	int count=0;
	if(visited[y][x]!=-1)
		return visited[y][x];
	if(grid[y][x]=='Z'){
		visited[y][x]=1;
		return visited[y][x]; 
	}
	for(int i=0;i<8;i++){
		if(x+x_d[i]>=0 && x+x_d[i]<w && y+y_d[i]>=0 && y+y_d[i]<h && grid[y+y_d[i]][x+x_d[i]]==grid[y][x]+1){
			int temp_count=dfs(y+y_d[i],x+x_d[i],visited);
			count=max(count,temp_count);
		}
	}
	return (visited[y][x]=1+count);
}

int main(){
	cin>>h>>w;
	while(h!=0 || w!=0){
		int visited[MAXSIZE][MAXSIZE];
		vector<pair<int,int> > position_of_A;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				scanf(" %c",&grid[i][j]);
				if(grid[i][j]=='A')
					position_of_A.push_back(make_pair(i,j));
				visited[i][j]=-1;
			}
		}
		int longest_path=0;
		for(unsigned int i=0;i<position_of_A.size();i++){
			int temp=dfs(position_of_A[i].first,position_of_A[i].second,visited);
			longest_path=max(longest_path,temp);
		}
		cout<<longest_path<<endl;
		cin>>h>>w;
	}
	return 0;
}
		

