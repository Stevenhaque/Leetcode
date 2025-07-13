class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size(), m = trainers.size();
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int j = 0, ans = 0;
        for(int i=0;i<n;i++){
            while(j<m && players[i]>trainers[j]) j++;
            if(j<m) ans++,j++;
        }
        return ans;
    }
};