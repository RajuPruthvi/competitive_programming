inline int add(int a, int b) { int ret=((ll)a+b)%modn; if(ret<0) ret+=modn; return ret; }
inline int mul(int a, int b) { int ret=((ll)a*b)%modn; if(ret<0) ret+=modn; return ret; }
template<typename... Args>
inline int add(int a, Args... args) { return add(a, add(args...)); }
template<typename... Args>
inline int mul(int a, Args... args) { return mul(a, mul(args...)); }
inline int addm(int a, int b, int MOD) { int ret=((ll)a+b)%MOD; if(ret<0) ret+=MOD; return ret; }
inline int mulm(int a, int b, int MOD) { int ret=((ll)a*b)%MOD; if(ret<0) ret+=MOD; return ret; }
inline int addm(int a, int b, int c, int MOD) { return addm(a, addm(b, c, MOD), MOD); }
inline int mulm(int a, int b, int c, int MOD) { return mulm(a, mulm(b, c, MOD), MOD); }
int po(int a, int b) {int res=1; for(; b>0; a=mul(a,a), b>>=1) if(b&1) res=mul(res,a); return res; }
int pom(int a, int b, int MOD) {int res=1; for(; b>0; a=mulm(a,a,MOD),b>>=1) if(b&1)res=mulm(res,a,MOD);return res;}
inline int inv(int a) {return po(a, modn-2);}