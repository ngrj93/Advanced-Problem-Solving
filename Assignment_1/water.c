#include<stdio.h>
int gcd(int a,int b);

int gcd(int a,int b){
	return b>0?gcd(b,a%b):a;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		int bigger=x>y?x:y;
		int smaller=x<y?x:y;
		if(z==0)
			printf("%d\n",1);
		else if(bigger==0)
			printf("%d\n",0);
		else if(smaller==0){
			if(bigger==z)
				printf("%d\n",1);
			else
				printf("%d\n",0);
		}
		else if(z>bigger)
			printf("%d\n",0);
		else{
			int hcf=gcd(bigger,smaller);
			if(!(z%hcf))
				printf("%d\n",1);
			else
				printf("%d\n",0);
		}
	}
	return 0;
}
