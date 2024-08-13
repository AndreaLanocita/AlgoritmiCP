long long dijikstra(int N, int M, vector<long long>& H, vector<int>& A, vector<int>& B, vector<int>& C) {
    vpl adj[N];
    for(int i=0; i<M; i++) adj[A[i]].pb({B[i], C[i]});

    ll distanze[N]; int visitato[N] = { };
    for(int i=0; i<N; i++) distanze[i] = H[i];

    pq p;
    for(int i=0; i<N; i++) p.push({H[i], i});

    ll res = 0; int n;
    for(int i=0; i<N; i++) {
        while(!p.empty()) {
            n = p.top().second;
            if(visitato[n]==0 || distanze[n] == p.top().first) break;
            p.pop();
        }
        if(p.empty()) break;
        p.pop();

        visitato[n] = 1;
        res += distanze[n];
        for(pl vicino: adj[n]) {
            if(visitato[vicino.first] == 1) continue;
            if(distanze[vicino.first] > distanze[n] + vicino.second) {
                distanze[vicino.first] = distanze[n] + vicino.second;
                p.push({distanze[vicino.first], vicino.first});
            }
        }
    }

    return res;
}