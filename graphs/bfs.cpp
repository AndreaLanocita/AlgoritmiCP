int bfs(int a, int b, vi adj[]) { // cammino minimo tra nodo a e b
    queue<int> q;
    q.push(a);
    int visitato[N] = { }; visitato[a] = 1;
    int distanze[N];

    while(!q.empty()) {
        int n = q.front();
        q.pop();
        //cout << n << ' ' << distanze[n] << endl;
        if(n==N-1) break;

        for(int vicino: adj[n]) {
            if(visitato[vicino]) continue;
            visitato[vicino] = 1;
            q.push(vicino);
            distanze[vicino] = distanze[n] + 1;
        }
    }
    return distanze[b];
}