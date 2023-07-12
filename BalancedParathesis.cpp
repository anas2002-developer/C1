#include<iostream>
#include<stack>
using namespace std;

bool BalancedParanthesis(string s){
	stack<char> stac;
	for(int i=0;i<s.size();i++){
		if (s[i]=='(' || s[i]=='[' || s[i]=='{'){
			stac.push(s[i]);
		}
		else if ((s[i]==')' && stac.top()=='(') || (s[i]==']' && stac.top()=='[') || (s[i]=='}' && stac.top()=='{')){
			stac.pop();
		}
		else{
			return false;
		}
	}
	return true;
}

int main(){
	cout<<BalancedParanthesis("{[()]([])}");
	return 0;
}
