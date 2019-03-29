#include <bits/stdc++.h>
using namespace std;

void printAdjacencyList(vector<int> adj[], int n) {
    for(int v = 1; v <= n; v++) {
        cout << v << "->";
        
        for(auto x : adj[v]) {
            cout << x << " ";
        }
        
        cout << endl;
    }
}

vector<int> findLevelForEachNode(vector<int> adj[], vector<bool> visited, int n) {
    vector<int> level(n+1);
    
    queue<int> q;
    q.push(1);
    level[1] = 1;
    visited[1] = true;
    
    while(!q.empty()) {
        int p = q.front();
        q.pop();
        
        for(auto x : adj[p]) {
            //cout << x << " ";
            if(visited[x] == false) {
                q.push(x);
                visited[x] = true;
                level[x] = level[p] + 1;
            }
            
        }
        
    }
    
    //for(int i = 1; i < n+1; i++) cout << level[i] << " ";
    
    return level;
}

int main() {
    
    int n;
    cin >> n;
    vector<int> adj[n+1];
    vector<int> level(n+1);
    vector<bool> visited(n+1, 0);
    
    // Creating graph adjacency list
    int u, v;
    for(int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // printAdjacencyList(adj, n);
    
    
    int givenLevel;
    cin >> givenLevel;
    
    // Storing the level of each node 
    level = findLevelForEachNode(adj, visited, n);
    
    // Checking count of nodes whose level equals the given level
    int noOfNodesAtGivenLevel = 0;
    for(int i = 1; i < level.size(); i++) {
        if(givenLevel == level[i]) noOfNodesAtGivenLevel++;
    }
    
    
    cout << noOfNodesAtGivenLevel << endl;
    
    return 0;
}
