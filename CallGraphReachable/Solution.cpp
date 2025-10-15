#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool areAllFunctionsReachable(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, false);
        stack<int> st;

        st.push(0);
        visited[0] = true;
        int reached = 1;

        while (!st.empty()) {
            int node = st.top();
            st.pop();

            for (int next : graph[node]) {
                if (!visited[next]) {
                    visited[next] = true;
                    st.push(next);
                    ++reached;
                }
            }
        }

        return reached == n;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> graph1 = {{1, 2}, {3}, {4}, {}, {}};
    vector<vector<int>> graph2 = {{1}, {2}, {0, 3}, {}, {5}};
    vector<vector<int>> graph3 = {{1, 2, 3}, {2}, {1}, {}};

    cout << boolalpha;
    cout << solution.areAllFunctionsReachable(graph1) << '\n'; // true
    cout << solution.areAllFunctionsReachable(graph2) << '\n'; // false
    cout << solution.areAllFunctionsReachable(graph3) << '\n'; // true

    return 0;
}
