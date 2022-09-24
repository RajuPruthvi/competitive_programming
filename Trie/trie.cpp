struct TRIE {
	static const int Alpha = 26;
	struct node {
		char ch;
		int cntend;
		int child[Alpha];

		node() {
			ch = '#', cntend = 0;
			memset(child, -1, sizeof(child));
		}
		node(char _ch) {
			ch = _ch, cntend = 0;
			memset(child, -1, sizeof(child));
		}
	};

	vector<node> tree;

	TRIE() {
		tree.push_back(node());
	}

	void insert(string s) {
		int cur = 0;
		for(char ch : s) {
			assert(cur < sz(tree));
			int &to = tree[cur].child[ch - 'a'];
			if(to == -1) {
				to = sz(tree);
				tree.push_back(node(ch));
			}
			cur = to;
		}
		assert(cur < sz(tree));
		tree[cur].cntend++;
	}

	bool check(string s) {
		int cur = 0;
		for(char ch : s) {
			int to = tree[cur].child[ch - 'a'];
			if(to == -1) return false;
			cur = to;
		}
		return tree[cur].cntend > 0;
	}
};