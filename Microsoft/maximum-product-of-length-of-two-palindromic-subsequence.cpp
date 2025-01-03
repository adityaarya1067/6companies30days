class Solution {
public:
    bool isPalindrome(string str) {
        int length = str.size();
        for (int i = 0; i < length / 2; i++) {
            if (str[i] != str[length - i - 1]) {
                return false;
            }
        }
        return true;
    }

    void findMaxProduct(string original, string part1, string part2, int index, int& maximum, int size) {
        if (index == size) {
            if (isPalindrome(part1) && isPalindrome(part2)) {
                maximum = max(maximum, (int)(part1.size() * part2.size()));
            }
            return;
        }
        
        findMaxProduct(original, part1, part2, index + 1, maximum, size);

        part1.push_back(original[index]);
        findMaxProduct(original, part1, part2, index + 1, maximum, size);
        part1.pop_back();

        part2.push_back(original[index]);
        findMaxProduct(original, part1, part2, index + 1, maximum, size);
        part2.pop_back();
    }

    int maxProduct(string str) {
        string part1 = "", part2 = "";
        int maximum = 0, size = str.size();
        findMaxProduct(str, part1, part2, 0, maximum, size);
        return maximum;
    }
};
