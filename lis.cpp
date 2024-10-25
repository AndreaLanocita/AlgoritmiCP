int lis(vector<int> &a) {
    int n = a.size();
    int INF = LLONG_MAX;
    vector<int> d(n+1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        int l = upper_bound(d.begin(), d.end(), a[i]) - d.begin(); // prendo primo elemento maggiore di a[i]
        if (d[l-1] < a[i] && a[i] < d[l]) // la prima parte serve solo se voglio che sia strettamente crescente
            d[l] = a[i];
    }
  
    int ans = 0;
    for (int l = 0; l <= n; l++) {
        if (d[l] < INF)
            ans = l;
    }
    return ans; // NB, in d non c'è la lista!!
}
