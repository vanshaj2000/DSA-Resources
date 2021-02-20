#include<bits/stdc++.h>
using namespace std;
struct Trie_Node
{
    Trie_Node *c[26];
    bool isEnd;
    Trie_Node()
    {
        isEnd=false;
        for(int i=0;i<26;i++)
            c[i]=NULL;
    }
};
Trie_Node *root;
bool search(string str)
{
    Trie_Node* curr=root;
    for(int i=0;i<str.size();i++)
    {
        if((curr->c)[str[i]-'a']==NULL)
            return false;
        else if(i==str.size()-1)
            return curr->c[str[i]-'a']==NULL?false:((curr->c)[str[i]-'a'])->isEnd;
        else
            curr=(curr->c)[str[i]-'a'];
    }
}
void insert(string str)
{
    Trie_Node* curr=root;
    for(int i=0;i<str.size();i++)
    {
        if(curr->c[str[i]-'a']==NULL)
            curr->c[str[i]-'a'];
        else
            curr=curr->c[str[i]-'a'];
    }
    curr->isEnd=true;
}
bool isEmpty(Trie_Node *root)
{
    for(int i=0;i<26;i++)
    {
        if(root->c[i]!=NULL)
            return false;
    }
    return true;
}
Trie_Node* deleteNode(Trie_Node* root,string &key,int ind)
{
    if(root==NULL)
        return NULL;
    if(ind==key.size())
    {
        root->isEnd=false;
        if(isEmpty(root)==true)
        {
            delete(root);
            root=NULL;
        }
        return root;
    }
    int index=key[ind]-'a';
    root->c[index]=deleteNode(root->c[index],key,ind+1);
    if(isEmpty(root)&&root->isEnd==false)
    {
        delete(root);
        root=NULL;
    }
    return root;
}
int main()
{
    Trie_Node* temp=new Trie_Node();
    root=temp;
}