struct hld
{
	int n;
	vector<int> t;
	vector<int> head;
	vector<vector<int> > adj;
	vector<int> heavy;
	vector<int> pos;
	vector<int> parent;
	vector<int> depth;
	int spos;
	
	hld() {}
	hld(vector<vector<int> > &a): adj(a) {}
	
	int dfs(int u, int pr)
	{
		int siz=1;
		int maxvsiz=0;
		parent[u]=pr;
		for(int v:adj[u]) {
			if(v!=pr) {
				depth[v]=depth[u]+1;
				int vsiz=dfs(v, u);
				siz+=vsiz;
				if(vsiz>maxvsiz) {
					maxvsiz=vsiz;
					heavy[u]=v;
				}
			}
		}
		return siz;
	}
	
	void decompose(int u, int h, int pr)
	{
		pos[u]=spos++;
		head[u]=h;
		if(heavy[u]!=-1) {
			decompose(heavy[u], h, u);
		}
		for(int v:adj[u]) {
			if(v==pr or v==heavy[u]) continue;
			decompose(v, v, u);
		}
	}
	
	void init() 
	{
		n=adj.size();
		spos=0;
		t.assign(4*n+1, 0);
		head.assign(n, 0);
		heavy.assign(n, -1);
		pos.assign(n, 0);
		parent.assign(n, 0);
		depth.assign(n, 0);
		
		dfs(0, -1);
		decompose(0, 0, -1);
	}
	
	int lca(int a, int b)
	{
		while(head[a]!=head[b]) {
			if(depth[head[a]]>depth[head[b]]) {
				swap(a, b);
			}
			b=parent[head[b]];
		}
		return (depth[a]<depth[b]?a:b);
	}
};
