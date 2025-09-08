class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int a = 1; a < n; a++) {
            int b = n - a;
            if (!isContainsZero(a) && !isContainsZero(b)) {
                return {a, b};
            }
        }
        return {0, 0};
    }

private:
    bool isContainsZero(int num) {
        while (num > 0) {
            if (num % 10 == 0) {
                return true;
            }
            num /= 10;
        }
        return false;
    }
};