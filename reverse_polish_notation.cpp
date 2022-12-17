class Solution {
    bool is_oper(string s)
    {
        bool x = s == "*" || s == "+" || s == "/" || s == "-";
        return x;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long int> st;

        for(auto vals: tokens) 
        {
            if(is_oper(vals)) {
                long long int a = st.top();
                st.pop();
                long long int b = st.top();
                st.pop();

                if(vals == "+") {
                    st.push(b + a);
                }
                
                else if(vals == "*") {
                    st.push(b * a);
                }
                
                else if(vals == "/") {
                    st.push(b / a);
                }
                
                else if(vals == "-") {
                    st.push(b - a);
                }
            }
            else {
                st.push(stoll(vals));
            }
        }

        return st.top();
    }
};
