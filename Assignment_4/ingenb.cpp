#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(){
	cout<<300000<<endl;
	srand(time(NULL));
	for(int i=0;i<300000;i++)
		cout<<rand()%1000000001<<" "<<rand()%100000000+1<<endl;
	return 0;
}

