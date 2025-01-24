class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        
        for (int i = 0; i < startWords.size(); i++) {
            sort(startWords[i].begin(), startWords[i].end());    
        }
        sort(startWords.begin(), startWords.end());
        int count = 0;
        for (int i = 0; i < targetWords.size(); i++) {
            string s = targetWords[i];
            for (int j = 0; j < s.length(); j++) {
                string str = s;
                str.erase(str.begin() + j);
                sort(str.begin(), str.end());
                if (binary_search(startWords.begin(), startWords.end(), str)) {
                    count++;
                    break;
                }
            }
        }
        
        return count;
    }
};