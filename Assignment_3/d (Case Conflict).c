#include<stdio.h>
#include<string.h>
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		char str[100001]={'\0'};
		int i,top=-1,opt,ans;
		scanf("%s",str);
		//printf("input = %s",str);
		int stack[strlen(str)],op1,op2;
		for(i=0;i<strlen(str);i++){
			if(str[i]=='(' || str[i]=='+' || str[i]=='-'){
				if(str[i]>='0' && str[i]<='9')
					str[i]-='0';
				stack[++top] = str[i];
			}
			else if(str[i]==')'){
				while(stack[top]!='('){
					ans = stack[top];
					if(stack[top-1]=='(') break;
					op2 = stack[top--];
					opt = stack[top--];
					op1 = stack[top];
					if(opt=='+') ans = op1 + op2;
					else ans = op1 - op2;
					stack[top] = ans;
				}
				stack[--top] = ans;
				while(top>=0 && stack[top]!='('){
					op2=stack[top--];
					if(stack[top]=='+' || stack[top]=='-'){
						if(top<0) break;
						opt = stack[top--];
						op1 = stack[top];
						if(opt=='+') stack[top] = op1 + op2;
						else stack[top] = op1 - op2;
					}
					else if(stack[top]=='(' || top<0 || stack[top]==')'){
						stack[++top] = op2;
						break;
					}
				}
			}
			else if(stack[top]=='+' || stack[top]=='-'){
				op2 = str[i] - '0';
				opt = stack[top--];
				op1 = stack[top];
				if(opt=='+') stack[top] = op1 + op2;
				else stack[top] = op1 - op2;
			}
			else {
				stack[++top] = str[i]-'0';
			}
		}
		while(top>=0){
			op2=stack[top--];
			if(top<0) break;
			opt = stack[top--];
			op1 = stack[top];
			if(opt=='+') stack[top] = op1 + op2;
			else stack[top] = op1 - op2;
		}
		printf("%d\n",op2);
	}
	return 0;
}