#include<bits/stdc++.h>
using namespace std;
struct Node{
	int x;
	struct Node* left=NULL;
	struct Node* right=NULL;
	Node(int k){
    x=k;
    left=right=NULL;
  }
};
void tranIn(Node* root)
{
	if(root==NULL)
		return;
	else
	{
		tranIn(root->left);
		cout<<root->x<<" ";
		tranIn(root->right);
	}
}
Node* insertBST(Node* root,int key)
{
	if(root==NULL)
		return new Node(key);
	else if((root->x)<key)
		root->right=insertBST(root->right,key);
	else if((root->x)>key)
		root->left=insertBST(root->left,key);
	return root;
}
Node* findNode(Node* root,int v)
{
	if(root==NULL)
		return NULL;
	else if(root->x==v)
		return root;
	else if(root->x>v)
		return findNode(root->left,v);
	else if(root->x<v)
		return findNode(root->right,v);
	return root;
}
Node* getSuccessor(Node* c)
{
	c=c->right;
	while(c!=NULL&&c->left!=NULL)
		c=c->left;
	return c;
}
Node* deleteBST(Node* root,int val)
{
	//cout<<"Hello"<<endl;
	if(root==NULL)
		return root;
	else if((root->x)>val)
		root->left=deleteBST(root->left,val);
	else if((root->x)<val)
		root->right=deleteBST(root->right,val);
	else
	{
		if(root->left==NULL)
		{
			//cout<<"Hello";
			Node* t=root->right;
			delete root;
			return t;
		}
		else if(root->right==NULL)
		{
			Node* t=root->left;
			delete root;
			return t;
		}
		else
		{
			//cout<<"Hello";
			Node* suc=getSuccessor(root);
			root->x=suc->x;
			root->right=deleteBST(root->right,suc->x);
		}
	}
	return root;
}
int main()
{
	int n;
	cin>>n;
	Node* root=NULL;
	for(int i=0;i<n;i++)
	{
		//cout<<"Hell"<<endl;
		int y;
		cin>>y;
		root=insertBST(root,y);
	}
	//tranIn(root);
	int j;
	cin>>j;
	Node* toD=findNode(root,j);
	//cout<<toD->x;
	if(toD!=NULL)
	{
		//cout<<"Hello";
		root=deleteBST(root,j);
		tranIn(root);
	}
	else
		tranIn(root);
}