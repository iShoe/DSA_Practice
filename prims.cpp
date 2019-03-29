#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, int> PII; 


int prim(int x, int n, vector<PII> adj[]) {
    priority_queue<PII, vector<PII>, greater<PII>> Q;
    long long minCost = 0;
    vector<bool> marked(n+1, false);
    Q.push(make_pair(0, x));
    
    while(!Q.empty()) {
        PII p = Q.top();
        Q.pop();
        
        x = p.second;
        if(marked[x] == true)
            continue;
        minCost += p.first;
        marked[x] = true;
        
        for(auto v : adj[x]) {
            int y = v.second;
            if(marked[y] == false)
                Q.push(v);
        }
    }
    
    return minCost;
}

int main() {
    int n, E;
    cin >> n >> E;
    vector<PII> adj[E];
    for(int i = 0; i < E; i++) {
        int s, d, w;
        cin >> s >> d >> w;
        adj[s].push_back(make_pair(w, d));
        adj[d].push_back(make_pair(w, s));
    }
    
    int minCost = prim(1, n, adj);
    cout << minCost << endl; 
    return 0;
}
