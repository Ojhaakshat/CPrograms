int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,list<pair<int,int>>> adj;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i = 0; i < times.size(); i++) {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
//         int parent[n+1];
        bool visit[n+1];
        memset(visit, false, sizeof(visit));
        vector<int> time(n+1,INT_MAX);
        pq.push({0,k});
        visit[k] = true;
        time[k] = 0;
//         parent[k] = -1;
        while(!pq.empty()) {
            auto f = pq.top();
            pq.pop();
            visit[f.second] = true;
            for(auto child : adj[f.second]) {
                if(visit[child.first] == false and time[child.first] > f.first + child.second) {
                    time[child.first] = f.first+child.second;
//                     parent[child.first] = f.second;
                    pq.push({f.first+child.second,child.first});
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(time[i] == INT_MAX) {
                return -1;
            }
            ans = max(ans, time[i]);
        }
        return ans;
    }
// to get path we can create a parent array and wenever a distance is updated we can updated the parent array(base case parent[k] = -1)
