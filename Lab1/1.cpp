#include<cstdio>
#include<iostream>

using namespace std;

int main(){
	int s,e,n,i,j;
	scanf("%d%d%d",&s,&e,&n);
	int time[n+1][2];
	for(i=0;i<n;i++)
		scanf("%d%d",&time[i][0],&time[i][1]);
	for(i=0;i<n;i++){
		if(time[i][1]>e && time[i][0]>=s){
			int t1=time[i][0],t2=time[i][1];
			time[i][0]=s,time[i][1]=e;
			for(j=i+1;j<n+1;j++){
				int t3=time[j][0],t4=time[j][1];
				time[j][0]=t1,time[j][1]=t2;
				t1=t3,t2=t4;
			}
			break;
		}
	}
	if(i==n){
		time[i][0]=s;
		time[i][1]=e;
	}
	for(int i=0;i<n+1;i++)
		cout<<time[i][0]<<" "<<time[i][1]<<endl;
	int c=0;
	for(i=0;i<n;i++){
		if(time[i][1]<time[i+1][0] && (time[i][1]<s||time[i][1]>=e))

	return 0;
}



