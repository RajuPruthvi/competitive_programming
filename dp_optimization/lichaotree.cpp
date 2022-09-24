struct pt {
    int x, y;

    pt() { x = 0, y = 0; }
    pt(int _x, int _y)  { x = _x, y = _y; }
    pt operator+(const pt& a) { return pt(x+a.x, y+a.y); }
    pt operator-(const pt& a) { return pt(x-a.x, y-a.y); }
    pt operator*(const int& a) { return pt(x*a, y*a); }
    pt operator/(const int& a) { return pt(x/a, y/a); }
    void operator+=(const pt& a) { x+=a.x, y+=a.y; }
    void operator-=(const pt& a) { x-=a.x, y-=a.y; }
    void operator*=(const int& a) { x*=a, y*=a; }
    void operator/=(const int& a) { x/=a, y/=a; }
};
ostream& operator << (ostream& os, const pt& p) {
    return os << "(" << p.x << ", " << p.y << ")";
}
int dot(pt a, pt b) { return a.x*b.x + a.y*b.y; }
int cross(pt a, pt b) { return a.x*b.y - b.x*a.y; }

struct lichaotree {
    int n;
    vector<pt> line;

    lichaotree() {}
    lichaotree(int _n) {
        n = _n;
        line.resize(4*n, pt(0, inf)); // replace inf by -inf
    }

    int f(pt p, int a) { return dot(p, pt(a, 1)); }

    void add_line(pt nw, int v, int l, int r) {
        int m = (l + r) / 2;
        bool lef = f(nw, l) < f(line[v], l); // replace < by >
        bool mid = f(nw, m) < f(line[v], m); // replace < by > 
        if(mid) {
            swap(line[v], nw);
        }
        if(l==r) {
            return;
        } else if(lef != mid) {
            add_line(nw, 2*v+1, l, m);
        } else {
            add_line(nw, 2*v+2, m+1, r);
        }
    }

    int get(int x, int v, int l, int r) {
        int m = (l + r) / 2;
        if(l==r) {
            return f(line[v], x);
        } else if(x <= m) {
            return min(f(line[v], x), get(x, 2*v+1, l, m)); // replace min by max
        } else {
            return min(f(line[v], x), get(x, 2*v+2, m+1, r)); // replace min by max
        }
    }

    void add_line(pt nw) {
        add_line(nw, 0, 0, n-1);
    }
    int get(int x) {
        return get(x, 0, 0, n-1);
    }
};