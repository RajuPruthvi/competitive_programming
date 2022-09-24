namespace FFT {

  using cd = complex<ld>;
  typedef vector<cd> vcd;
 
  const int LOG = 18;
  const int N = 1 << LOG;
  const ld pi = acosl(-1);
 
  int rev[N];
  cd root_[N];
 
  inline cd root(int k, int n) {
    return root_[k * (N / n)];
  }
 
  void precalc() {
    rev[0] = 0;
    int hb = -1;
    for (int i = 1; i < N; ++i) {
      if  ((i & (i - 1)) == 0) {
        ++hb;
      }
      rev[i] = rev[i ^ (1 << hb)] | (1 << (LOG - hb - 1));
    }
 
    for(int i=0; i<N; i++) {
      ld ang = pi * i * 2.0 / N;
      root_[i] = cd(cosl(ang), sinl(ang));
    }
  }
 
  void fft_rec(cd* a, int n) {
    if  (n == 1) {
      return;
    }
 
    fft_rec(a, n / 2);
    fft_rec(a + n / 2, n / 2);
   
    for(int k=0; k<n/2; k++) {
      cd w = root(k, n);
      cd x = a[k];
      cd y = w * a[k + n / 2];
      a[k] = x + y;
      a[k + n / 2] = x - y;
    }
  }
 
  void fft(vcd& a) {
    int n = sz(a);
    vcd na(n, cd(0, 0));
    for(int i=0; i<n; i++) na[i] = a[rev[i]];
    na.swap(a);
 
    fft_rec(&a[0], n);
  }
 
  void fft_inv(vcd& a) {
    fft(a);
    int n = sz(a);
    reverse(a.begin() + 1, a.end());
    for(int i=0; i<n; i++) {
      a[i] /= n;
    }
  }
 
  vi mult(const vi& a, const vi& b) {
//    TimeStamp t("mult");
    vcd A(N, cd(0, 0));
    vcd B(N, cd(0, 0));
    for(int i=0; i<sz(a); i++) A[i] = a[i];
    for(int i=0; i<sz(b); i++) B[i] = b[i];
 
    fft(A);
    fft(B);
 
    for(int i=0; i<N; i++) A[i] *= B[i];
 
    fft_inv(A);
 
    vi c(N, 0);
    for(int i=0; i<N; i++) c[i] = ((ll) (A[i].real() + 0.5)) % modn;
 
    return c;
  }
 
  vi multmod(const vi& a, const vi& b) {
    // a = a0 + sqrt(modn) * a1
    // a = a0 + base * a1
    int base = (int) sqrtl(modn);
   
    vi a0(sz(a)), a1(sz(a));
    for(int i=0; i<sz(a); i++) {
      a0[i] = a[i] % base;
      a1[i] = a[i] / base;
      assert(a[i] == a0[i] + base * a1[i]);
    }
 
    vi b0(sz(b)), b1(sz(b));
    for(int i=0; i<sz(b); i++) {
      b0[i] = b[i] % base;
      b1[i] = b[i] / base;
      assert(b[i] == b0[i] + base * b1[i]);
    }
 
    vi a01 = a0;
    for(int i=0; i<sz(a); i++) {
      a01[i] = add(a01[i], a1[i]);
    }
 
    vi b01 = b0;
    for(int i=0; i<sz(b); i++) {
      b01[i] = add(b01[i], b1[i]);
    }
 
    vi C = mult(a01, b01);  // 1
 
    vi a0b0 = mult(a0, b0); // 2
    vi a1b1 = mult(a1, b1); // 3
   
    vi mid = C;
    for(int i=0; i<N; i++) {
      mid[i] = add(mid[i], -a0b0[i]);
      mid[i] = add(mid[i], -a1b1[i]);
    }
 
    vi res = a0b0;
    for(int i=0; i<N; i++) {
      res[i] = add(res[i], mul(base, mid[i]));
    }
 
    base = mul(base, base);
    for(int i=0; i<N; i++) {
      res[i] = add(res[i], mul(base, a1b1[i]));
    }

    return res;
  }
};