#include <bits/stdc++.h>
using namespace std;

struct node {
    struct node* letter[26];
    bool  flag;

    bool isEmpty(char ch) {
        return letter[ch - 'a'] != nullptr;
    }

    void put(char ch, struct node* n) {
        letter[ch - 'a'] = n;
    }

    struct node* get(char ch) {
        return letter[ch - 'a'];
    }

    void set_end(){
        flag = true;
    }

    bool is_end(){
        return flag;
    }
};

struct node* root = new node;

void insert(string s)
{
    struct node* ptr = root;

    for(auto vals: s) 
    {
       if(!ptr->isEmpty(vals)) {
            struct node* n = new node();
            ptr->put(vals, n);
       }

       ptr = ptr->get(vals);
    }
    ptr->set_end();
}

bool search(string word)
{
    struct node* ptr = root;

    for(int i = 0;i<word.length();++i){
        if(!ptr->isEmpty(word[i])){
            return false;
        }
        ptr = ptr->get(word[i]);
    }

    if(ptr->is_end())
        return true;
    else
        return false;
}

void solve()
{
   int n;
   cin>>n;

   for(int i = 0;i<n;++i){
    string s;
    cin>>s;
    insert(s);
   }
 
 search("dog")?cout<<"true"<<"\n":cout<<"false"<<"\n";
}

int main()
{
    
    int t = 1;
    while(t--)
    {
    solve();
    }
    return 0;
}
