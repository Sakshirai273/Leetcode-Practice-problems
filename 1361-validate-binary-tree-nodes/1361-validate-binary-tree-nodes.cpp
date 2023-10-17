class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> inDegree(n, 0);

        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                inDegree[leftChild[i]]++;
            }
            if (rightChild[i] != -1) {
                inDegree[rightChild[i]]++;
            }
        }

        int rootCount = 0;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] > 1) {
                return false; // More than one incoming edge to a node
            }
            if (inDegree[i] == 0) {
                rootCount++;
                if (rootCount > 1) {
                    return false; // More than one root node
                }
            }
        }

        if (rootCount == 0) {
            return false; // No root node found
        }

        vector<bool> visited(n, false);
        stack<int> topoSort;

        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                topoSort.push(i);
            }
        }

        while (!topoSort.empty()) {
            int node = topoSort.top();
            topoSort.pop();
            if (visited[node]) {
                return false; // Cycle detected
            }
            visited[node] = true;

            if (leftChild[node] != -1) {
                topoSort.push(leftChild[node]);
            }
            if (rightChild[node] != -1) {
                topoSort.push(rightChild[node]);
            }
        }

        return count(visited.begin(), visited.end(), true) == n;
    }
};