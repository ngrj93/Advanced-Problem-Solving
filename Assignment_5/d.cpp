#include<bits/stdc++.h>
#define s second
#define f first
using namespace std;

class Graph{
public:
	
	vector< vector<pair<int,pair<int,int> > > > adj;
	int v,e;

	void input(){
		cin>>v>>e;
		adj.resize(v);
		int x,y,r;
		for(int i=0;i<e;i++){
			cin>>x>>y>>r;
			x--,y--;
			adj[x].push_back(make_pair(-r,make_pair(x,y)));
			adj[y].push_back(make_pair(-r,make_pair(y,x)));
		}
	}
	
	void prims(){
		long long total=0;
		priority_queue<pair< int,pair<int,int> > > q;
		set<int> unvisited;
		for(int i=1;i<v;i++)
			unvisited.insert(i);
		for(unsigned int i=0;i<adj[0].size();i++)
			q.push(adj[0][i]);
		while(!unvisited.empty()){
			pair<int,pair<int,int> > temp=q.top();
			q.pop();
			while(!unvisited.count(temp.s.s)){
				temp=q.top();
				q.pop();
			}
			total+=temp.f;
			unvisited.erase(temp.s.s);
			for(unsigned int i=0;i<adj[temp.s.s].size();i++){
				if(unvisited.count(adj[temp.s.s][i].s.s))
					q.push(make_pair(adj[temp.s.s][i].f, make_pair(adj[temp.s.s][i].s.f,adj[temp.s.s][i].s.s)));
			}
		}
		cout<<-total<<endl;
	}
};

int main(){
	Graph g;
	g.input();
	g.prims();
	return 0;
}

