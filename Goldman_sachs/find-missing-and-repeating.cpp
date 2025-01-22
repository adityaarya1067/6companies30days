 vector<int> findTwoElement(vector<int>& arr) {
        // code 
        map<int,int> mpp;
        int n =arr.size();
        vector<int> ans;
        for(int i=1;i<=n;i++){
            mpp[i]=0;
        }
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
        }
        int a = 0;int b =0;
        for(const auto it:mpp){
            if(it.second==0)a=it.first;
            if(it.second==2)b=it.first;
        }
        return {b,a};
    }