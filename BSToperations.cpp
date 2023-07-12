#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
		
		Node(int data){
			this->data=data;
			this->left=NULL;
			this->right=NULL;
		}
};

Node* Insert(Node* &root,int data){
	if(root==NULL){
		root=new Node(data);
		return root;
	}
	else if(data<root->data){
		root->left=Insert(root->left,data);
	}
	else{
		root->right=Insert(root->right,data);
	}
	return root;
}

Node* miniSuccessor(Node* &root){
	Node* curr=root;
	
	while(curr->left!=NULL){
		curr=curr->left;
	}
	return curr;
}

Node* Delete(Node* &root,int data){
	if(root==NULL){
		return root;
	}
	else if(root->data==data){
		if(root->left==NULL && root->right==NULL){
			delete root;
			return NULL;
		}
		else if(root->left!=NULL && root->right==NULL){
			Node* temp=root->left;
			delete root;
			return temp;
		}
		else if(root->left==NULL && root->right!=NULL){
			Node* temp=root->right;
			delete root;
			return temp;
		}
		else{
			int mini=miniSuccessor(root->right)->data;
			root->data=mini;
			root->right=Delete(root->right,mini);
			return root;
		}
	}
	else if(data<root->data){
		root->left=Delete(root->left,data);
		return root;
	}
	else{
		root->right=Insert(root->right,data);
		return root;
	}
}

bool SearchRecursion(Node* &root, int x){
	if(root==NULL){
		return false;
	}
	else if(x==root->data){
		return true;
	}
	else if(x<root->data){
		return SearchRecursion(root->left,x);
	}
	else{
		return SearchRecursion(root->right,x);
	}
}

bool SearchIteration(Node* &root, int x){
	Node* curr=root;
	
	while(curr!=NULL){
		if(curr==NULL){
			return false;
		}
		else if(x==curr->data){
			return true;
		}
		else if(x<curr->data){
			curr=curr->left;
		}
		else{
			curr=curr->right;
		}
	}
	return false;
}

void inorder(Node* root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}


void inputValues(Node* &root){
	int data;
	cin>>data;
	
	while(data!=-1){
		Insert(root,data);
		cin>>data;
	}
}


int main(){
	Node* root=NULL;
	cout<<"Insert values :\n";
	inputValues(root);
	
	cout<<endl;
	cout<<SearchRecursion(root,5)<<endl;
	cout<<SearchIteration(root,10)<<endl;
	
	root=Delete(root,20);
	
	cout<<"INORDER : ";
	inorder(root);
	
	return 0;
}

//functions -
//1. Insert
//2. MiniSuccessor
//3. Delete
//4. SearchRecursion
//5. SearchIteration
//6. Inorder
//7. InputValues
