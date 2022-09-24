struct centroidDecompostion
{
	int n;
	vector<set<int>> adj;
	vector<int> parent;
	vector<int> siz;
	
	centroidDecompostion() {}
	centroidDecompostion(vector<set<int>> &a): adj(a) {}
	centroidDecompostion(vector<vector<int>> &a)  {
		adj.resize(sz(a));
		for(int i=0; i<sz(a); i++) {
			for(int val:a[i]) {
				adj[i].insert(val);
			}
		}
	}
	
	void dfs(int u, int pr)
	{
		siz[u]=1;
		for(int v:adj[u]) {
			if(v!=pr) {
				dfs(v, u);
				siz[u]+=siz[v];
			}
		}
	}
	
	int findCentroid(int u, int pr, int rootsiz)
	{
		for(int v:adj[u]) {
			if(v==pr) continue;
			if(siz[v]>rootsiz/2) {
				return findCentroid(v, u, rootsiz);
			}
		}
		return u;
	}
	
	int decompose(int u, int pr)
	{
		dfs(u, pr);
		int cnode=findCentroid(u, pr, siz[u]);
		parent[cnode]=pr;
		
		vector<int> tmp(all(adj[cnode]));
		for(int v:tmp) {
			adj[cnode].erase(v);
			adj[v].erase(cnode);
			
			int cv=decompose(v, cnode);
			
			adj[cnode].insert(cv);
			adj[cv].insert(cnode);
		}
		
		return cnode;
	}
	
	void init()
	{
		n=adj.size();
		parent.resize(n);
		siz.resize(n);
		
		//~ printVSet(adj);
		decompose(0, -1);
	}
	
};
