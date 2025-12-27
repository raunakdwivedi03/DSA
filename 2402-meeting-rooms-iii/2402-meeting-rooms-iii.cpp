class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        // free rooms (smallest index first)
        priority_queue<int, vector<int>, greater<int>> freeRooms;

        // busy rooms: (endTime, roomIndex)
        priority_queue<pair<long long,int>,
                       vector<pair<long long,int>>,
                       greater<pair<long long,int>>> busyRooms;

        vector<int> count(n, 0);

        for(int i = 0; i < n; i++)
            freeRooms.push(i);

        for(auto &m : meetings) {
            long long start = m[0];
            long long end = m[1];
            long long duration = end - start;

            // free up rooms that are done before start
            while(!busyRooms.empty() && busyRooms.top().first <= start) {
                freeRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }

            if(!freeRooms.empty()) {
                // assign immediately
                int room = freeRooms.top();
                freeRooms.pop();
                busyRooms.push({end, room});
                count[room]++;
            } else {
                // delay meeting
                auto [freeTime, room] = busyRooms.top();
                busyRooms.pop();
                busyRooms.push({freeTime + duration, room});
                count[room]++;
            }
        }

        // find room with max meetings
        int ans = 0;
        for(int i = 1; i < n; i++) {
            if(count[i] > count[ans])
                ans = i;
        }
        return ans;
    }
};
