class Solution {
public:
    int minJumps(vector<int>& nums) {
        unordered_map<int, vector<int>> tport;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int t = nums[i];
            for (int d = 2; d * d <= t; d++) {
                if (t % d == 0) {
                    tport[d].push_back(i);
                    while (t % d == 0) {
                        t /= d;
                    }
                }
            }

            if (t > 1) {
                tport[t].push_back(i);
            }

        }
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int i = q.front();
                q.pop();
                int num = nums[i];
                if (visited[i]) 
                    continue;
                visited[i] = true;
                if (i == n - 1) 
                    return steps;
                if (tport.count(num)) {
                    for (int nei : tport[num]) {
                        q.push(nei);
                    }
                    tport.erase(num);
                }
                if (i + 1 < n) {
                    q.push(i + 1);
                }
                if (i - 1 >= 0) {
                    q.push(i - 1);
                }
            }
            steps++;
        }
        return steps;
    }
};