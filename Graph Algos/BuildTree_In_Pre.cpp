#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int key; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      key=k;
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
		cout<<root->key<<" ";
		tranIn(root->right);
	}
}
int g=0;
Node* buildTree(vector<int> Tin,vector<int> Tpre,int s,int e)
{
	if(s>e)
		return NULL;
	Node* nr=new Node(Tpre[g++]);
	int ind;
	for(int i=s;i<=e;i++)
	{
		if(Tin[i]==nr->key)
		{
			ind=i;
			break;
		}
	}
	nr->left=buildTree(Tin,Tpre,s,ind-1);
	nr->right=buildTree(Tin,Tpre,ind+1,e);
	return nr;
}
int main()
{
	int n;
	cin>>n;
	vector<int> in(n);
	vector<int> pre(n);
	for(int i=0;i<n;i++)
		cin>>in[i];
	for(int i=0;i<n;i++)
		cin>>pre[i];
	Node* ans=buildTree(in,pre,0,n-1);
	tranIn(ans);
}