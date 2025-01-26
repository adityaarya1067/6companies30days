class Solution{   
public:
    string printMinNumberForPattern(string S){
        int n = S.size() ;
        stack<int>stk ; 
        string ans = "" ;
        
        for(int i=0 ; i<=n ; i++){
            stk.push(i+1) ; 
            if(i == n || S[i] == 'I'){
                while(!stk.empty()){
                    ans += to_string(stk.top()) ;
                    stk.pop() ;
                }
            }
        }
        return ans ;
    }
};