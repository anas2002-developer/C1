#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

int postfixEvaluation(string s){
	stack<int> STACK;
	
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9'){
			STACK.push(s[i]-'0');
		}
		else{
			int operand2=STACK.top();
			STACK.pop();
			int operand1=STACK.top();
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
	cout<<postfixEvaluation("46+2/5*7+");
	
	return 0;
}
