int find(vector<int> parent, int i){
    if(parent[i] == -1) return i;

    return find(parent, parent[i]);
}

void union_(vector<int> &parent, int x, int y){
    int xset = find(parent, x);
    
    int yset = find(parent, y);

    if(xset != yset)
        parent[xset] = yset;
  
}
