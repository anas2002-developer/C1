#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

int prefixEvaluation(string s){
	stack<int> STACK;
	
	for(int i=s.length()-1;i>=0;i--){
		if(s[i]>='0' && s[i]<='9'){
			STACK.push(s[i]-'0');
		}
		else{
			int operand1=STACK.top();
			STACK.pop();
			int operand2=STACK.top();
			STACK.pop();
			switch(s[i]){
				case '+':
					STACK.push(operand1+operand2);
					break;
				case '-':
					STACK.push(operand1-operand2);
					break;
				case '*':
					STACK.push(operand1*operand2);
					break;
				case '/':
					STACK.push(operand1/operand2);
					break;
				case '^':
					STACK.push(pow(operand1,operand2));
					break;
			}
		}
	}
	return STACK.top();
}

int main(){
	cout<<prefixEvaluation("-+7*45+20");
	
	return 0;
}
