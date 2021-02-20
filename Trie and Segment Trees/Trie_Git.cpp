#include<bits/stdc++.h>
using namespace std;
class Trie
{
private:
    Trie* next[26]={};
    bool isEnd;
public:
    Trie()
    {
        isEnd=false;
    }
    void insert(string word)
    {
        Trie* root=this;
        for(int i=0;i<word.size();i++)
        {
            if(root->next[word[i]-'a']==NULL)
                root->next[word[i]-'a']=new Trie();
            root=root->next[word[i]-'a'];
        }
        root->isEnd=true;
    }
    bool search(string word)
    {
        Trie* root=this;
        for(int i=0;i<word.size();i++)
        {
            if(root->next[word[i]-'a']==NULL)
                return false;
            root=root->next[word[i]-'a'];
        }
        return root->isEnd;
    }
    bool startsWith(string word)
    {
        Trie* root=this;
        for(int i=0;i<word.size();i++)
        {
            if(root->next[word[i]-'a']==NULL)
                return false;
            root=root->next[word[i]-'a'];
        }
        return true;
    }
};
int main()
{
  Trie* obj = new Trie();
  obj->insert("vanshaj");
  obj->insert("pranjal");
  obj->insert("dictionary");
   if(obj->search("vansh"))
    cout<<"Present"<<endl;
  else
    cout<<"Not present"<<endl;
  if(obj->startsWith("vansh"))
    cout<<"Present"<<endl;
  else
    cout<<"Not present"<<endl;
  return 0;
}