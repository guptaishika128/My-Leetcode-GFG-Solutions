class Solution {
public:
   // Function for traversing the graph and finding the product of all values from source to destination node.
double dfs(string &curr, string &destination, unordered_map<string, vector<pair<string, double>>> &edges, unordered_set<string> &visited) {
    // If the current node is same as destination node.
    if (curr == destination) {
        return 1.0;
    }

    visited.insert(curr);

    // Iterate through the edges of the current node.
    for (pair<string, double> i : edges[curr]) {
        if (visited.find(i.first) == visited.end()) {
            double val = dfs(i.first, destination, edges, visited);
            if (val != -1) {
                return (val * i.second);
            }
        }
    }
    return -1.0;
}
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
         // To store the edges in the form of an adjacency list.
    unordered_map<string, vector<pair<string, double>>> edges;

    // Insert edges into the adjacency list.
    for (int i = 0; i < equations.size(); i++) {
        edges[equations[i][0]].push_back({equations[i][1], values[i]});
        edges[equations[i][1]].push_back({equations[i][0], (1.0 / values[i])});
    }

    // For storing the result of queries.
    vector<double> ans;

    // Iterate through the queries.
    for (auto i : queries) {
        // If the numerator or the denominator string does not exist in the graph then the answer is -1.
        if (edges.find(i[0]) == edges.end() || edges.find(i[1]) == edges.end()) {
            ans.push_back(-1.0);
        }
        else {
            // For storing all the visited nodes of the graph.
            unordered_set<string> visited;

            // Do a DFS from the numerator and search for the denominator.
            double val = dfs(i[0], i[1], edges, visited);

            ans.push_back(val);
        }
    }
    return ans;
    }
};