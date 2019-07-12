// https://www.geeksforgeeks.org/count-number-nodes-given-level-using-bfs/

#include <bits/stdc++.h>
using namespace std;


int main(){
	int v;
	cin >> v;
	int e = v-1;
	vector<int> adj[v];

	for(int i = 0; i < e; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int l;
	cin >> l;

	queue<int> q;
	vector<bool>visited(v, false);
	vector<int>level(v, 0);

	q.push(0);
	visited[0] = true;

	while(!q.empty()){
		int s = q.front();
		q.pop();

		for(int x : adj[s]){
			if(!visited[x]){
				q.push(x);
				visited[x] = true;
				level[x] = level[s] + 1;
			}
		}
	}

	int count = 0;
	for(int x : level){
		if(x == l) count++;
	}


	cout << "Count: " << count << endl;

	return 0;
}