#include<bits/stdc++.h>
using namespace std;

// macros
#define int long long 
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define all(c) c.begin(), c.end()
#define PB push_back
#define MP make_pair
#define bitcount __builtin_popcount
#define watch(x) cerr<< (#x) << " is " << (x) <<"\n";
#define sz(x) ((int)((x).size()))
#define UNIQUE(c) (c).resize(unique(all(c)) - (c).begin())
#define pii2ll(p) ((ll)(p).first<<32 | (p).second)

// type definitions
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector< vi > vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef long double ld;

// template functions
template < typename A, typename B >
ostream& operator << ( ostream& os, const pair< A, B > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}
template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
    os << "[";
    typename vector< T > :: const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}
template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
    os << "{";
    typename set< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "}";
}
template < typename A, typename B >
ostream &operator << ( ostream & os, const map< A, B > &v ) {
    os << "[";
    typename map< A, B >::const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << it -> first << " -> " << it -> second ;
    }
    return os << "]";
}
template <typename T>
inline void printV(vector<T>& a, int n) { for(int i=0; i<n; i++) { cerr<<a[i]<<" "; } cerr<<"\n"; }
template <typename T>
inline void printVV(vector<vector<T> >& a) { for(int i=0; i<sz(a); i++) { cerr<<a[i]<<"\n"; } cerr<<"\n"; }
template <typename T>
inline void clearVV(vector<vector<T> >& a) { for(auto &x : a) { x.clear(); } a.clear(); }
template <typename T>
inline void assignVV(vector<vector<T> > &a, T val) { for(int i=0; i<sz(a); i++) { a[i].assign(sz(a[i]), val); } }
template<typename T>
T gcd(T a, T b) { if(a==0 or b==0) return a+b; return gcd(b, a%b) ; }
template<typename T>
T lcm(T a, T b) { if(a==0 or b==0) return 0; return a/gcd(a, b)*b; }

// random number generation
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// constants
const long double eps = LDBL_EPSILON;
const int inf = 5e8;
const int modn = 1e9+7;
const int maxn = 1e5;

vector<int> sort_cyclic_shifts(string const& s) 
{
    int n = s.size();
    const int alphabet = 256;

    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }

    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int> suffix_array_construction(string s) {
    s += "$";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Your code here
    string s;
    cin>>s;
    cout<<suffix_array_construction(s)<<"\n";
    return 0;
}

