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
map<int,vector<Node*>> findHorizontalDistance(Node* root)
{
	map<int,vector<Node*>> mp;
	queue<pair<Node*,int>> q;
	q.push({root,0});
	while(q.size()!=0)
	{
		pair<Node*,int> pr=q.front();
		int hd=pr.second;
		vector<Node*> v=mp[pr.second];
		v.push_back(pr.first);
		mp[pr.second]=v;
		if((pr.first)->left!=NULL)
			q.push({(pr.first)->left,hd-1});
		if((pr.first)->right!=NULL)
			q.push({(pr.first)->right,hd+1});
		q.pop();
	}
	return mp;
}
void printTopView(map<int,vector<Node*>> m)
{
	for(auto it:m)
	{
		vector<Node*> v=it.second;
		cout<<v[0]->x<<" ";
	}
}
void printBottomView(map<int,vector<Node*>> m)
{
	for(auto it:m)
	{
		vector<Node*> v=it.second;
		cout<<v[v.size()-1]->x<<" ";
	}
}
int main()
{
	int n;
	cin>>n;
	Node* root=NULL;
	for(int i=0;i<n;i++)
	{
		int y;
		cin>>y;
		root=insertBST(root,y);
	}
	map<int,vector<Node*>> m=findHorizontalDistance(root);
	printTopView(m);
	cout<<endl;
	printBottomView(m);
}