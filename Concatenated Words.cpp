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

struct node* root;

class Solution {

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

bool stringSearchUtil(string word, int &x)
{
    if(word.length() == 0) {return true;}
    x++;
    for(int i = 1; i <= word.length(); ++i) {
        if(search(word.substr(0, i)) and stringSearchUtil(word.substr(i, word.length()), x)) {
            return true;
        }
    }
    x--;

    return false;
}
    
public:
    Solution() {
        root = new node();
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {

        for(auto vals: words) {
            insert(vals);
        }

        vector<string> ans;
        for(auto vals: words) {
            int x = 0;
            if(stringSearchUtil(vals, x)) {
                if(x > 1)
                    ans.push_back(vals);
                x = 0;
            }
        }
        
        return ans;
    }
};
