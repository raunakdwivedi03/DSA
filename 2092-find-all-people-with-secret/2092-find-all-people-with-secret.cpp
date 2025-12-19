class Solution {
public:
    typedef pair<int,int> P;

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // time -> list of meetings
        map<int, vector<P>> timeMeeting;

        for (auto &meeting : meetings) {
            int person1 = meeting[0];
            int person2 = meeting[1];
            int time = meeting[2];
            timeMeeting[time].push_back({person1, person2});
        }

        vector<bool> knowsSecret(n, false);
        knowsSecret[0] = true;
        knowsSecret[firstPerson] = true;

        // Process meetings time-wise
        for (auto &it : timeMeeting) {
            vector<P> &meets = it.second;

            unordered_map<int, vector<int>> adj;
            unordered_set<int> involved;

            // Build graph for same-time meetings
            for (auto &p : meets) {
                int u = p.first;
                int v = p.second;
                adj[u].push_back(v);
                adj[v].push_back(u);
                involved.insert(u);
                involved.insert(v);
            }

            queue<int> q;
            unordered_set<int> visited;

            // Start BFS from people who already know the secret
            for (int person : involved) {
                if (knowsSecret[person]) {
                    q.push(person);
                    visited.insert(person);
                }
            }

            // BFS to spread the secret
            while (!q.empty()) {
                int person = q.front();
                q.pop();

                for (int nextPerson : adj[person]) {
                    if (!visited.count(nextPerson)) {
                        visited.insert(nextPerson);
                        knowsSecret[nextPerson] = true;
                        q.push(nextPerson);
                    }
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (knowsSecret[i]) {
                result.push_back(i);
            }
        }
        return result;
    }
};
