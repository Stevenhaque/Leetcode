class Solution {
public:
    bool isFreqSame(int freq[], int freq2[]) {
        for(int i = 0; i < 26; i++) {
            if(freq[i] != freq2[i]) { 
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};

        for(int i = 0; i < s1.length(); i++) { 
            freq[s1[i] - 'a']++;
        }

        int windSize = s1.length(); 

        for(int i = 0; i <= s2.length() - windSize; i++) { 
            int windFreq[26] = {0};

            for(int j = 0; j < windSize; j++) { 
                windFreq[s2[i + j] - 'a']++;
            }

            if (isFreqSame(freq, windFreq)) {
                return true;
            }
        }

        return false; 
    }
};
