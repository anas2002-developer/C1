#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int PRECEDENCE(char c){
	if (c=='^')
		return 3;
	else if (c=='*' || c=='/') 
		return 2;
	else if (c=='+' || c=='-')
		return 1;
	else
		return -1;
}

string INFIX2PREFIX(string s){
	reverse(s.begin(),s.end());
	stack<char> STACK;
	string RESULT;
	
	for(int i=0;i<s.length();i++){
		if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
			RESULT+=s[i];
		}
		else if(s[i]==')'){
			STACK.push(')');
		}
		else if(s[i]=='('){
			while(!STACK.empty() && STACK.top()!=')'){
				RESULT+=STACK.top();
				STACK.pop();
			}
			STACK.pop();
		}
		else{
			while(!STACK.empty() && PRECEDENCE(s[i])<PRECEDENCE(STACK.top())){
				RESULT+=STACK.top();
				STACK.pop();
			}
			STACK.push(s[i]);
		}
	}
	while(!STACK.empty()){
		RESULT+=STACK.top();
		STACK.pop();
	}
	reverse(RESULT.begin(),RESULT.end());
	return RESULT;
}

int main(){
	cout<<INFIX2PREFIX("A+(B*C)")<<endl;
	
	return 0;
}
