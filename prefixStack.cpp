#include<iostream>
#include<math.h>
#include<stack>				//stack is class in c++
using namespace std;

int prefix(string s){
	stack<int> stac;
	for(int i=s.length()-1;i>=0;i--){
		if (s[i]>='0' && s[i]<='9'){
			stac.push(s[i]-'0');
		}
		else{
			int operand1=stac.top();
			stac.pop();
			int operand2=stac.top();
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
	cout<<prefix("-+7*45+20");
	return 0;
}

//push()	adds an element into the stack
//pop()	removes an element from the stack
//top()	returns the element at the top of the stack
//size()	returns the number of elements in the stack
//empty()	returns true if the stack is empty
