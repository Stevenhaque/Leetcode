class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        
        std::vector<bool> composites(n, false);
        int limit = sqrt(n);
        
        for (int i = 2; i <= limit; ++i) {
            if (!composites[i]) {
                for (int j = i * i; j < n; j += i) {
                    composites[j] = true;
                }
            }
        }
        
        int count = 0;
        for (int i = 2; i < n; ++i) {
            if (!composites[i]) count++;
        }
        
        return count;
    }
};
