#include<bits/stdc++.h>
#define MAXSIZE 100001
#define MOD 1000000007
using namespace std;

int n,c;
int parent[MAXSIZE];
map<int,int> count_of_nodes;
int dp[MAXSIZE];
int max_value=0;

int factorial(int val){
	if(val==1){
		dp[val]=1;
		return 1;
	}
	else{
		dp[val]=(int)(((long long)val*(factorial(val-1)%MOD))%MOD);
		return dp[val];
	}
}

int find(int i){
	if(parent[i]==i)
		return i;
	else{
		parent[i]=find(parent[i]);
		return parent[i];
	}
}

void union_set(int x,int y){
	int p1=find(x);
	int p2=find(y);
	parent[p1]=p2;
}

int main(){
	cin>>n>>c;
	for(int i=0;i<n;i++)
		parent[i]=i;
	while(c--){
		int x,y;
		cin>>x>>y;
		union_set(x,y);
	}
	for(int i=0;i<n;i++){
		int index=find(i);
		if(!count_of_nodes.count(index))
			count_of_nodes[index]=1;
		else
			count_of_nodes[index]++;
		max_value=max(max_value,count_of_nodes[index]);
	}	
	factorial(max_value);
	dp[0]=1;
	long long total=1;
	for(map<int,int>::iterator it=count_of_nodes.begin();it!=count_of_nodes.end();it++)
		total=((total%MOD)*(dp[it->second]%MOD))%MOD;
	cout<<total<<endl;
	return 0;
}
