class Solution {
  public:
    string encode(string s) {
        // code here
        stack<char> st;
        string ans = "";
        int count = 1;
        for(int i=0;i<s.length();i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else if(st.top()!=s[i]){
                char temp = st.top();
                st.pop();
                
                ans.push_back(temp);
             ans+= to_string(count);
             st.push(s[i]);
             count=1;
            }
            else count++;
            
        }
        ans+= st.top();
        ans+=to_string(count);
        return ans;
    }
};