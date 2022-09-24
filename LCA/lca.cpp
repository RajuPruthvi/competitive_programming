struct LCA {
	int n;
	vector<vector<int>> adj;
	vector<vector<int>> par;
	vector<int> depth, start, end;
	int tim = 0;
	const int LOG = 21;
 
	LCA() {}
	LCA(const vector<vector<int>> &a) {
		adj = a;
		n = adj.size();
		par = vector<vector<int>>(n, vector<int>(LOG, -1));
		depth.resize(n), start.resize(n), end.resize(n);
		dfs(0, -1);
	}
 
	void dfs(int u, int pr) {
		start[u] = tim++;
		par[u][0] = pr;
		for(int j = 1; j < LOG; j++) {
			if(par[u][j - 1] == -1) break;
			par[u][j] = par[par[u][j - 1]][j - 1];
		}
		for(int v : adj[u]) {
			if(v == pr) continue;
			depth[v] = depth[u] + 1;
			dfs(v, u);
		}
		end[u] = tim++;
	}
 
	bool is_anc(int u, int v) {
		if(u == -1) return true;
		return start[u] <= start[v] and end[u] >= end[v];
	}
 
	int lca(int u, int v) {
		if(is_anc(u, v)) return u;
		if(is_anc(v, u)) return v;
		for(int j = LOG - 1; j >= 0; j--) {
			if(!is_anc(par[u][j], v)) {
				u = par[u][j];
			}
		}
		return par[u][0];
	}
 
	int dist(int u, int v) {
		return depth[u] + depth[v] - 2 * depth[lca(u, v)];
	}
};