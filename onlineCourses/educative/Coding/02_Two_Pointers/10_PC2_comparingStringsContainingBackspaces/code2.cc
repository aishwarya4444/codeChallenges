class Solution {
public:
    string build(string &s) {
        stack<char> st;
        string result;
        for(auto chr: s) {
            if(chr=='#' && st.size()) {
                st.pop();
            } else if(chr != '#') {
                st.push(chr);
            }
        }
        while(st.size()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
    bool backspaceCompare(string S, string T) {
        string s=build(S), t=build(T);
        return s.compare(t) ==0;
    }
};
