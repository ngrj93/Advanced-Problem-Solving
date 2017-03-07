#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(const pair<int,pair<int,int> > & a,const pair<int,pair<int,int> > & b) {
	return (a.first > b.first);
};

int main(){

	int t,n,l,w;
	cin>>t;
	while(t--){
		cin>>n;
		vector<pair<int,pair<int,int> > > v;
		int overlap[10001];

		for(int i=0;i<n;i++)
			overlap[i] = 1;
		for (int i = 0; i < n; ++i)
		{
			cin>>l>>w;
			v.push_back(make_pair(l*w,make_pair(l,w)));
		}
		sort(v.begin(),v.end(),compare);
		int max_l=0,max_w=0;

		for (int i = 1; i < n; ++i)
		{
			max_l = v[i].second.first;
			max_w = v[i].second.second;
			for (int j = 0; j < i; ++j)
			{
				if(max_l < v[j].second.first  && max_w < v[j].second.second ){

					if(overlap[i] < overlap[j]+1)
						overlap[i]=overlap[j]+1;
				}
			}
		}
		max_l=0;
		for (int i = 0; i < n; ++i)
			if(max_l < overlap[i])
				max_l=overlap[i];
		cout<<max_l<<endl;
	}
	return 0;
}