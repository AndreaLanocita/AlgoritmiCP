int bfsGraphColoring(int N, int m, vector<int> adj[], int visitato[], vector<int> &colors) {
	// return 0 if possible, 1 if not
	int maxColours = 1, n;
	for(int nodo = 0; nodo<N; nodo++) {
		if(visitato[nodo] == 1) continue; // takes into account the fact that the graph might not be interconnected

		visitato[nodo] = 1;
		queue<int> q;
		q.push(nodo);

		while(!q.empty()) {
			n = q.front();
			q.pop();

			for(int vicino: adj[n]) {
				if(colors[vicino] == colors[n]) { // controllo che i vicini non abbiamo lo stesso colore
					colors[vicino] += 1; // se si, aumento di 1 il colore del vicino
					maxColours = max(maxColours, colors[vicino]);	// controllo di non aver sforato m
					if(maxColours > m) return 1;
				}

				if(visitato[vicino] == 0) {
					q.push(vicino);
					visitato[vicino] = 1;
				}
			}
		}
	}
	return 0;
}