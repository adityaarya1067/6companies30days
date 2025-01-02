class Solution {
public:
    string getHint(string secret, string guess) {
        int num1= 0 ;
        int  n = secret.size();
        int num2 = 0;
        map<int,int>mpp1;
        map<int,int>mpp2;
        
        for(int i=0;i<n;i++){
            if(secret[i]!=guess[i]){
                mpp1[secret[i]]++;
                mpp2[guess[i]]++;
            }
            else{
                num1++;
            }
        }
        for(const auto &it:mpp1){
            int real = it.first;
            if(mpp2.find(real)!=mpp2.end()){
                auto it2 =mpp2.find(real);
                num2 += min(it.second,it2->second);
            }
        }
        string ans = to_string(num1)+"A"+to_string(num2)+"B";
        return ans;
    }
};