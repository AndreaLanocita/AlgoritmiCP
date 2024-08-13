vector<int> link;
vector<int> sizee;
void init(int N) {
    link.resize(N);
    sizee.resize(N);
    for(int i=0; i<N; i++) {
        sizee[i] = 0;
        link[i] = i;
    }
}
int find(int a) {
    while(link[a]!=a) a=link[a];
    return a;
}
void unionn(int a, int b) {
    a = find(a);
    b= find(b);
    if(a==b) return;

    if(sizee[a] < sizee[b]) {
        link[a] = b;
        sizee[b] += sizee[a];
    } else {
        link[b] = a;
        sizee[a] += sizee[b];
    }
}

int kruskal(vp adj[]) {
    sort(lista.begin(), lista.end());
    int res = 0;
    init(N);
    for(pair<int, pair<int, int>> arco: lista) {
        if(find(arco.second.first) == find(arco.second.second)) continue;
        unionn(arco.second.first, arco.second.second);
        res += arco.first;
    }

    return res;
}
