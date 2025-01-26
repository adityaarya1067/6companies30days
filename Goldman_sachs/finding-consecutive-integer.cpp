class DataStream {
public:
    int target = 0, limit = 0;
    int count = 0;

    DataStream(int value, int k) {
        target = value;
        limit = k;
    }
    
    bool checkConsecutive(int number) {
        if (number == target)
            count++;
        else
            count = 0;
        return count >= limit;
    }
};
