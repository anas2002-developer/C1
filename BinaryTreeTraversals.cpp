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

Node* buildTree(Node* root){
	int data;
	cin>>data;
	root=new Node(data);
	
	cout<<"Enter data "<<endl;
	if(data==-1){
		return NULL;
	}
	
	cout<<"Enter left Node of "<<data<<" : "<<endl;
	root->left=buildTree(root->left);
	cout<<"Enter right Node of "<<data<<" : "<<endl;
	root->right=buildTree(root->right);
	return root;
}

void inorder(Node* root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void preorder(Node* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(Node* root){
	if(root==NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}


int main(){
	Node* root=NULL;
	cout<<"Enter Root Node : ";
	root=buildTree(root);
	
	cout<<"INORDER : ";
	inorder(root);
	
	cout<<"\nPREORDER : ";
	preorder(root);
	
	cout<<"\nPOSTORDER : ";
	postorder(root);
	
	return 0;
}
