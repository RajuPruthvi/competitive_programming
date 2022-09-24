struct DSU {
	int n;
	vector<int> par, siz;

	DSU() {}
	DSU(int _n) : n(_n) {
		par.resize(n, -1);
		siz.resize(n, 1);
	}

	int getp(int u) {
		if(par[u] == -1) return u;
		return par[u] = getp(par[u]);
	}

	int combine(int u, int v) {
		u = getp(u);
		v = getp(v);
		if(u == v) return 0;

		if(siz[u] > siz[v]) swap(u, v);
		siz[v] += siz[u];
		par[u] = v;
		return 1;
	}
};