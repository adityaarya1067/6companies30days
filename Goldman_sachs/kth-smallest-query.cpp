class Solution {
public: 
    struct Data {
        string value;
        int pos;
        Data(string value, int pos) : value(value), pos(pos) {}
    };

    vector<int> smallestTrimmedNumbers(vector<string>& numbers, vector<vector<int>>& requests) {
        unordered_map<int, vector<Data>> storage;
        
        for (int i = 0; i < numbers.size(); i++) {
            string num = numbers[i];
            int len = num.size();
            int trimSize = len;
            for (int j = 0; j < len; j++) {
                storage[trimSize].emplace_back(num.substr(j), i);
                trimSize--;
            }
        }

        vector<int> result(requests.size());
        int idx = 0;

        for (auto query : requests) {
            int kth = query[0];
            int trim = query[1];

            vector<Data>& entries = storage[trim];

            sort(entries.begin(), entries.end(), [](const Data& a, const Data& b) {
                if (a.value == b.value) return a.pos < b.pos;
                return a.value < b.value;
            });

            result[idx++] = entries[kth - 1].pos;
        }

        return result;
    }
};
