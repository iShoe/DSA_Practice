#include <bits/stdc++.h>
using namespace std;

int iterativeDFS(int headNode, vector<int> adj[], int n) {
    stack <int> S;
    vector<bool> visited(n+1, false);
    
    S.push(headNode);
    visited[headNode] = true;
    int connectedNodes = 1;
    
    while(!S.empty()) {
        int p = S.top();
        S.pop();
        
        for(auto x : adj[p]) {
            if(visited[x] == false) {
                S.push(x);
                visited[x] = true;
                connectedNodes++;
            }
        }
    }
    
    return connectedNodes;
}


int main() {
    int nodes, edges, x, y, headNode;
    
    cin >> nodes >> edges;
    
    vector<int> adj[nodes+1];
    
    for(int i = 0; i < edges; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    cin >> headNode;
    
    int noOfHeadConnectedNodes = iterativeDFS(headNode, adj, nodes);
    
    int noOfNotConnectedToHeadNodes = nodes - noOfHeadConnectedNodes;
    cout << noOfNotConnectedToHeadNodes << endl;
    
    return 0;
}
