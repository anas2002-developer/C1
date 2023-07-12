 #include<iostream>
#include<math.h>
#include<stack>
using namespace std;

int postfix(string s){
	stack<int> stac;
	for(int i=0;i<s.length();i++){
		if (s[i]>='0' && s[i]<='9'){
			stac.push(s[i]-'0');
		}
		else{
			int operand2=stac.top();
			stac.pop();
			int operand1=stac.top();
			stac.pop();
			
			switch(s[i]){
				case '+':
					stac.push(operand1+operand2);
					break;
				case '-':
					stac.push(operand1-operand2);
					break;
				case '*':
					stac.push(operand1*operand2);
					break;
				case '/':
					stac.push(operand1/operand2);
					break;
				case '^':
					stac.push(pow(operand1,operand2));
					break;
			}
		}
	}
	return stac.top();
}

int main(){
	cout<<postfix("46+2/5*7+");
	return 0;
}

//push()	adds an element into the stack
//pop()	removes an element from the stack
//top()	returns the element at the top of the stack
//size()	returns the number of elements in the stack
//empty()	returns true if the stack is empty
