class Solution {
public:
    void solve(vector<string>&ans,string output,string digits,map<int,string>mpp,int index){
        if(index>=digits.length()){
            ans.push_back(output);
            return;
        }
        int num = digits[index]-'0';
        string s = mpp[num];

        for(int i=0;i<s.length();i++){
            output.push_back(s[i]);
            solve(ans,output,digits,mpp,index+1);
            output.pop_back();
        }

    } 
    vector<string> letterCombinations(string digits) {
        map<int,string>mpp{{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"}, {7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
        int index=0;
        string output;
        vector<string> ans;
        if(digits.length()==0){
            return ans;
        }
        
        solve(ans,output,digits,mpp,index);
        return ans;
        

        

    }
};