class segTree
{
public:
	struct node {
		int a;

		node() {
			a = 0;
		}

		node(int _a) {
			a = _a;
		}

	};

    int n;
    vector<node> st;

    segTree() {}
    segTree(int _n) {
        n = _n;
        st.resize(4*n);
    }

    node combine(node& n1, node& n2)
    {
       	return node(n1.a + n2.a);
    }
    
    void build(int v, int tl, int tr)
    {
        if(tl == tr) {
            st[v] = node();
            return;
        }
        
        int tm = (tl+tr) / 2;
        build(2 * v + 1, tl, tm);
        build(2 * v + 2, tm + 1, tr);
        st[v] = combine(st[2 * v + 1], st[2 * v + 2]);
    }

    auto query(int v, int tl, int tr, int l, int r)
    {
        if(tl > r or tr < l) return node();
        if(tl >= l and tr <= r) {
            return st[v];
        }
        int tm = (tl + tr) / 2;
        auto ans1 = query(2 * v + 1, tl, tm, l, r);
        auto ans2 = query(2 * v + 2, tm + 1, tr, l, r);
        return combine(ans1, ans2);
    }

    void update(int v, int tl, int tr, int pos, node new_val)
    {
        if(tl == tr) {
            st[v] = new_val;
            return;
        }
        int tm = (tl + tr) / 2;
        if(pos <= tm) {
            update(2 * v + 1, tl, tm, pos, new_val);
        }
        else {
            update(2 * v + 2, tm + 1, tr, pos, new_val);
        }
        st[v] = combine(st[2 * v + 1], st[2 * v + 2]);
    }

    void update(int pos, int val) {
		node new_val(val);
        update(0, 0, n - 1, pos, new_val);
    }

    auto query(int l, int r) {
    	return query(0, 0, n - 1, l, r).a;
    }
};