#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		int numbers[10]={0};
		cin>>n;
		int j=0;
		while(n!=0){
			numbers[j++]=n%10;
			n/=10;
		}
		prev_permutation(numbers,numbers+j);
		prev_permutation(numbers,numbers+j);
		for(int i=0;i<j;i++)
			cout<<numbers[i];
		cout<<endl;
	}
	return 0;
}	
