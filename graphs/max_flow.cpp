#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>

/*
    Ford-Fulkerson + Edmonds-Karp for max-flow
    O(VE^2)
*/

bool bfs(int source, int sink, vector<vector<int>> &adj, vector<vector<ll>> &capacity, vector<int> &parent) {
    queue<int> q;
    q.push(source);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(int son: adj[node]) {
            // se ha capacità non positiva o è già stato visitato nella bfs
            if(capacity[node][son]<=0 || parent[son] != -1) continue;
            parent[son] = node;
            q.push(son);
        }
    }
    return (parent[sink] != -1); // ho trovato percorso?
}

long long max_flow(vector<vector<int>> adj, vector<vector<ll>> capacity, int source, int sink) {
    int N = adj.size();
    // contiene il precedente di node nel percorso trovato con bfs
    // in più funziona anche come "visitato[n]"
    vector<int> parent(N, -1); 
    long long flow = 0;

    // finche esiste il percorso (poi l'algoritmo finisce)
    while(bfs(source, sink, adj, capacity, parent)) {
        // ho fatto la bfs --> trovo arco minimo
        int node = sink; // parto dalla fine e ripercorro all'indietro
        ll curr_flow = LLONG_MAX;
        while(node != source) {
            curr_flow = min(curr_flow, capacity[parent[node]][node]);
            node = parent[node];
        }

        // ripercorro di nuovo, faccio update delle capacità
        node = sink;
        while(node != source) {
            capacity[parent[node]][node] -= curr_flow;
            capacity[node][parent[node]] += curr_flow;
            node = parent[node];
        }

        flow += curr_flow; // aggiungo miglioramento
        fill(parent.begin(), parent.end(), -1); // update
    }

    return flow;
}

int main() {
    cin.tie(nullptr);ios::sync_with_stdio(false);
    //Remember to use \n<<flush
    
    int N, M;
    cin >> N >> M;

    vector<vector<long long>> capacity(N,  vector<long long>(N)); // matrice NxN con peso archi e inversi
    // solita lista di adiacenza per bfs, tutti i pesi sono considerati 1 e ci sono anche 
    // gli archi inversi
    vector<vector<int>> adj(N); 

    for(int i=0; i<M; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[--a].push_back(--b); // attenzione che sia 1 based
        adj[b].push_back(a);
        capacity[a][b] = c;
        capacity[b][a] = 0; // gli inversi si inizializzano a zero
    }

    cout << max_flow(adj, capacity, 0, N-1) << endl;

    return 0;
}