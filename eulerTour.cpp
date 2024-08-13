int first[MAXN]; 
vi euler; 
int height[MAXN];

struct Node{
	int mi, n;
	Node() : mi(INT_MAX), n(-1) {};

	void join(Node &l, Node &r) {
		if(l.mi < r.mi) n = l.n;
		else n = r.n;
		mi = min(l.mi, r.mi);
	}
};

int real_size, fake_size;
vector<Node> nodes;

void build(int u, int l, int r) {
	if(r-l<=1) {
		if(l<euler.size()) {
			nodes[u].mi = height[euler[u]];
			nodes[u].n = euler[u];
		}
	}
	else {
		build(2*u, l, (l+r)/2);
		build(2*u+1, (l+r)/2, r);
		nodes[u].join(nodes[2*u], nodes[2*u+1]);
	}
}

void init() {
	fake_size = euler.size();
	real_size = 1;
	while(real_size < fake_size) real_size *= 2;
	nodes.assign(2*real_size, Node());
	build(1, 0, real_size);
}

pi get_min(int u, int l, int r, int x, int y) {
	if(l>=y || r<=x) return {-1, INT_MAX};
	if(l>=x && r<=y) return {nodes[u].n, nodes[u].mi};
	pi a = get_min(2*u, l, (l+r)/2, x, y);
	pi b = get_min(2*u+1, (l+r)/2, r, x, y);
	if(a.second < b.second) return a; return b;
}

int dfs(int n, int pre, vi adj[], int h=0) {
    first[n] = euler.size(); // it increases after being assigned
    euler.push_back(n);
    height[n] = h;

    for(int vicino: adj[n]) {
        if(vicino==pre) continue;
        dfs(vicino, n, adj, h++);
        euler.push_back(vicino);
    }
}

int lca(int a, int b) {
	init(); // segtree
	get_min(1, 0, real_size, first[a], first[b]); // its a RMQ on the height
}

int eulerTour(int N, vi adj[]) {
    dfs(0, -1, adj);   
    // queries 
}