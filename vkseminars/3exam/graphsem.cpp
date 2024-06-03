#include <vector>
#include <queue>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    static void dfs(vector<int>& colors, int currColor, const vector<vector<int> >& graph, int i) {
        if (colors[i] != 0) return;
        colors[i] = currColor;
        for (auto& next : graph[i]) {
            dfs(colors, currColor, graph, next);
        }
    }

    // 1) find all connected components
    static vector<int> findAllIslands(const vector<vector<int> >& graph) {
        vector<int> colors(graph.size(), 0);
        int currColor = 1;
        for (int i = 0; i < graph.size(); ++i) {
            if (colors[i] == 0) {
                dfs(colors, currColor, graph, i);
                ++currColor;
            }
        }
        return colors;
    }

    // 2) has cycle
    static bool hasCycle(const vector<vector<int> >& graph) {
        vector<int> visited(graph.size(), 0);

        for (int i = 0; i < graph.size(); ++i) {
            if (visited[i] != 0) continue;
            if (BoolDfs(visited, graph, i)) return true;
        }

        return false;
    }

    static bool BoolDfs(vector<int>& visited, const vector<vector<int> >& graph, int i) {
        if (visited[i] != 0) return true;
        visited[i] = 1;

        for (auto& next : graph[i]) {
            if (next == i) continue;
            if (BoolDfs(visited, graph, next)) return true; 
        }

        return false;
    }
    
    // 3) is Tree
    static bool isTree(const vector<vector<int> >& graph) {
        vector<int> visited(graph.size(), 0);
        bool has_cycle = BoolDfs(visited, graph, 0);
        if (has_cycle) return false;
        for (int i = 0; i < graph.size(); ++i) {
            if (visited[i] == 0) return false;
        }
        return true;
    }

    // bfs solution
    static bool isTreeBFS(const vector<vector<int> >& graph) {
        unordered_set<int> visited;

        vector<int> parent(graph.size(), 0);

        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int currNode = q.front();
            q.pop();
            for (auto& next : graph[currNode]) {
                if (!visited.count(next)) {
                    q.push(next);
                    parent[next] = currNode;
                } else {
                    if (next != parent[currNode]) return false;
                }
            }
        }

        return visited.size() == graph.size();
    }
    
    // 4) Deigstra
    static vector<int> deigstra(const vector<vector<pair<int, int>> >& graph, int start) {
        priority_queue<pair<int, int> , vector<pair<int, int> >, std::greater<pair<int, int > > > minHeap;
        minHeap.push({0, start});
        
        vector<int> ans(graph.size(), INT_MAX);
        ans[start] = 0;
        
        vector<int> visited(graph.size(), 0);

        while (!minHeap.empty()) {
            while (!minHeap.empty() && visited[minHeap.top().second] == 1) minHeap.pop();
            if (minHeap.empty()) break;

            int currNode = minHeap.top().second;
            minHeap.pop();
            visited[currNode] = 1;

            for (auto& [next, weight] : graph[currNode]) {
                
                if (visited[next]) continue;

                if (ans[next] > ans[currNode] + weight) {
                    ans[next] = ans[currNode] + weight;
                    minHeap.push({ans[next], next});
                }
            }
        }

        return ans;
    }
    

};
