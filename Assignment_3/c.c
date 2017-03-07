#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 1005
#define ANSSIZE 2005

int main(){
	int t,q,j,i,k;
	scanf("%d",&t);
	while(t--){
		int m=0;
		char *n=(char *)malloc(MAXSIZE*sizeof(char));
		char *cu=(char *)malloc(MAXSIZE*sizeof(char));
		char *result=(char *)malloc(ANSSIZE*sizeof(char));
		for(j=0;j<ANSSIZE;j++)
			result[j]='0';
		scanf("%s",n);
		scanf("%s",cu);
		if(n[0]=='0' || cu[0]=='0'){
			printf("%d\n",0);
			continue;
		}
		int nsize=strlen(n);
		int csize=strlen(cu);
		for(q=csize-1,k=0;q>=0;q--,k++){
			int c=0,w=0,carry=0;
			for(j=nsize-1;j>=0;j--){
				int prod=(n[j]-'0')*(cu[q]-'0');
				int sum=(prod+carry)%10;
				carry=(prod+carry)/10;
				int r=(result[k+w]-'0')+sum+c;
				result[k+w]=r%10+'0';
				c=r/10;
				w++;
				if(k+w>m)
					m=k+w;
			}
			result[k+w]=c+carry+'0';
			if(c+carry!=0){
				w++;
				if(k+w>m)
					m=k+w;
			}
		}
		result[m]='\0';
		for(i=0,j=m-1;i<j;i++,j--){
			char temp=result[i];
			result[i]=result[j];
			result[j]=temp;
		}
		printf("%s\n",result);
		free(n);free(cu);free(result);
	}
	return 0;
}


					
				

		
