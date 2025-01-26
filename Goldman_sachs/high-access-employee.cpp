class Solution {
public:
    vector<string> highAccessEmployees(vector<vector<string>>& records) {
        map<string, vector<int>> accessMap;

        for (auto record : records) {
            string employee = record[0];
            int time = stoi(record[1]);
            accessMap[employee].push_back(time);
        }

        vector<string> result;

        for (auto &[employee, times] : accessMap) {
            sort(begin(times), end(times));
            int count = times.size();
            bool exceedsLimit = false;

            for (int i = 0; i + 3 <= count; ++i)
                exceedsLimit |= times[i + 2] < times[i] + 100;

            if (exceedsLimit) result.push_back(employee);
        }

        return result;
    }
};
