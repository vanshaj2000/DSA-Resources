#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int val;
	Node* left;
	Node* right;
	Node(int x)
	{
		val=x;
		left=right=NULL;
	}
};
bool isBST(Node* root)
{
	if(root->left!=NULL)
	{
		if(root->right!=NULL)
		{
			if((root->left->val)<root->val&&(root->right->val)>root->val)
				return isBST(root->left)&&isBST(root->right);
			else
				return false;
		}
		else
		{
			if((root->left->val)<root->val)
				return isBST(root->left);
			else
				return false;
		}
	}
	else
	{
		if(root->right!=NULL)
		{
			if((root->right->val)>root->val)
				return isBST(root->right);
			else
				return false;
		}
		else
			return true;
	}
}