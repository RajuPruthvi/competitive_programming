vector<vector<int>> matmul(vector<vector<int>> &a, vector<vector<int>> &b)
{
	// p X q, q X r
	int p=a.size(), _q=a[0].size(), q=b.size(), r=b[0].size(); assert(_q==q);
	
	vector<vector<int>> c(p, vector<int>(r));
	for(int i=0; i<p; i++) {
		for(int j=0; j<r; j++) {
			for(int k=0; k<q; k++) {
				c[i][j]=add(c[i][j], mul(a[i][k], b[k][j]));
			}
		}
	}
	return c;
}

vector<vector<int>> matpo(vector<vector<int>> a, long long k)
{
	// compute a ** k
	int n=a.size(), _n=a[0].size(); assert(_n==n);
	
	vector<vector<int>> res(n, vector<int>(n));
	for(int i=0; i<n; i++) res[i][i]=1;
	
	while(k>0) {
		if(k&1) {
			res=matmul(res, a);
		}
		a=matmul(a, a);
		k>>=1;
	}
	return res;
}