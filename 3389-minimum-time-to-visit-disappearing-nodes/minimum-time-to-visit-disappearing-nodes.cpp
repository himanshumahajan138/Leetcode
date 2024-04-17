using namespace std;

class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        // Create adjacency list representation of the graph
        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            // Skip self-loop condition
            if (u != v) {
                graph[u].push_back({v, w});
                graph[v].push_back({u, w});
            }
        }
        
        // Priority queue for Dijkstra's algorithm
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0}); // {distance, node}
        
        // Initialize distances array with infinity
        vector<int> distances(n, INT_MAX);
        
        while (!pq.empty()) {
            auto [dist, curr] = pq.top();
            pq.pop();
            
            // Skip processing if node has already disappeared
            if (dist > distances[curr] || dist >= disappear[curr]) continue;
            
            distances[curr] = dist;
            
            // Traverse neighbors
            for (auto& neighbor : graph[curr]) {
                int nextNode = neighbor.first;
                int weight = neighbor.second;
                
                // Calculate new distance
                int newDist = dist + weight;
                
                // Update distance if shorter path is found
                if (newDist < distances[nextNode]) {
                    pq.push({newDist, nextNode});
                }
            }
        }
        
        // Adjust unreachable nodes to -1
        for (int i = 0; i < n; ++i) {
            if (distances[i] == INT_MAX) {
                distances[i] = -1;
            }
        }
        
        return distances;
    }
};
