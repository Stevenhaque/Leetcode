class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        for (int i = 0; i < n; ++i) freeRooms.push(i);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busyRooms;
        vector<int> roomMeetings(n, 0);

        for (auto& meeting : meetings) {
            long long start = meeting[0], end = meeting[1];
            while (!busyRooms.empty() && busyRooms.top().first <= start) {
                freeRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }

            if (!freeRooms.empty()) {
                int room = freeRooms.top(); freeRooms.pop();
                ++roomMeetings[room];
                busyRooms.push({end, room});
            } else {
                auto [nextAvailableTime, room] = busyRooms.top(); busyRooms.pop();
                ++roomMeetings[room];
                long long duration = end - start;
                busyRooms.push({nextAvailableTime + duration, room});
            }
        }

        int maxMeetings = 0, answerRoom = 0;
        for (int i = 0; i < n; ++i) {
            if (roomMeetings[i] > maxMeetings) {
                maxMeetings = roomMeetings[i];
                answerRoom = i;
            }
        }

        return answerRoom;
    }
};
