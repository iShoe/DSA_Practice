#include <bits/stdc++.h>
using namespace std;

class Edge {
    public:
        int source;
        int destination;
        int weight;
};

bool compare(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}

int findParent(int v, int *parent) {
    if(parent[v] == v) return v;
    
    return findParent(parent[v], parent);
}

int krushkals(Edge *input, int n, int E) {
    // sorting the weights according to asending order
    sort(input, input + E, compare);
    
    Edge *output = new Edge[n-1];
    int *parent = new int[n+1];
    
    
    // initialize parent
    for(int i = 0; i < n+1; i++)
        parent[i] = i;
        
    
    int count = 0;
    int i = 0;
    while(count != n-1) {
        Edge currentEdge = input[i];
        
        int sourceParent = findParent(currentEdge.source, parent);
        int destinationParent = findParent(currentEdge.destination, parent);
        
        
        if(sourceParent != destinationParent) {
            output[count] = currentEdge;
            count++;
            parent[sourceParent] = destinationParent;
        }
        
        i++;
    }
    
    int minCost = 0;
    for(int i = 0; i < n-1; i++) {
        minCost += output[i].weight;
    }
    
    return minCost;
    
}

int main() {
    int n, E;a
    cin >> n >> E;
    
    // Taking in input
    Edge *input = new Edge[E];
    for(int i = 0; i < E; i++) {
        int s, d, w;
        cin >> s >> d >> w;
        input[i].source = s;
        input[i].destination = d;
        input[i].weight = w;
        
    }
    
    cout << krushkals(input, n, E) << endl;
    
    
    return 0;
}
