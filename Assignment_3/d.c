#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100000

int main(){
	int n,i,j;
	scanf("%d",&n);
	while(n--){
		j=0;
		int top=-1;
		char *expr=(char *)malloc(MAXSIZE*sizeof(char));
		char *result=(char *)malloc(MAXSIZE*sizeof(char));
		char *stack=(char *)malloc(MAXSIZE*sizeof(char));
		int *stack2=(int *)malloc(MAXSIZE*sizeof(int));
		scanf("%s",expr);
		int esize=strlen(expr);
		for(i=0;i<esize;i++){
			if(expr[i]>='0' && expr[i]<='9')
				result[j++]=expr[i];
			else if(expr[i]=='+'||expr[i]=='-'){
				if(stack[top]=='+' || stack[top]=='-'){
					result[j++]=stack[top--];
					stack[++top]=expr[i];
				}
				else
					stack[++top]=expr[i];
			}
			else if(expr[i]=='(')
				stack[++top]='(';
			else if(expr[i]==')'){
				while(stack[top]!='(')
					result[j++]=stack[top--];
				top--;
			}
		}
		while(top!=-1)
			result[j++]=stack[top--];
		result[j]='\0';
		top=-1;
		for(i=0;i<j;i++){
			if(result[i]>='0' && result[i]<='9')
				stack2[++top]=result[i]-'0';
			else if(result[i]=='+'){
				int oper2=stack2[top--];
				int	oper1=stack2[top--];
				stack2[++top]=oper1+oper2;
			}
			else if(result[i]=='-'){
				int oper2=stack2[top--];
				int oper1=stack2[top--];
				stack2[++top]=oper1-oper2;
			}
		}
		int ans=stack2[top];
		printf("%d\n",ans);
		free(expr);
		free(result);
		free(stack);
		free(stack2);
	}
	return 0;
}

				
