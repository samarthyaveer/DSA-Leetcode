class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if (arr[start] == 0) return true;

        queue<int> q;
        q.push(start);

        vector<bool> visited(arr.size(), false);
        visited[start] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (arr[u] == 0) {
                return true;
            }

            int left = u - arr[u];
            int right = u + arr[u];

            if (left >= 0 && !visited[left]) {
                visited[left] = true;
                q.push(left);
            }

            if (right < arr.size() && !visited[right]) {
                visited[right] = true;
                q.push(right);
            }
        }

        return false;
    }
};