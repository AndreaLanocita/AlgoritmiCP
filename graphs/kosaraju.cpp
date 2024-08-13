vi ordine;

void dfs1(int n, vi adj[], int visitato[]) {
    visitato[n] = 1;
    for(int vicino: adj[n]) 
        if(visitato[vicino] == 0) dfs1(vicino, adj, visitato);
    
    ordine.push_back(n);
}

void dfs2(int n, vi adj[], int scc[], int counter) {
    scc[n] = counter;

    for(int vicino: adj[n])
        if(scc[vicino] == 0) dfs2(vicino, adj, scc, counter);
}