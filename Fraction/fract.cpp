struct fract {
    int a, b;

    fract() {}
    fract(int _a, int _b) {
        a = _a;
        b = _b;
        if(b < 0) {
            // denominator is always +ve
            a *= -1;
            b *= -1;
        }
        int g = gcd(abs(a), b);
        if(g!=0) {
            a/=g, b/=g;
        }
    }
	long double get() { return (long double)a/b; }
    bool operator < (const fract &f) const{ return a*f.b < b*f.a; }
    bool operator <= (const fract &f) const{ return a*f.b <= b*f.a; }
    bool operator > (const fract &f) const{ return a*f.b > b*f.a; }
    bool operator >= (const fract &f) const{ return a*f.b >= b*f.a; }
    bool operator == (const fract &f) const{return a*f.b == b*f.a; }
    fract operator + (const fract &f) { 
        if(b==0 or f.b==0) return fract(a*f.b + b*f.a, 0);
        int l = lcm(b, f.b); return fract(l/b*a + l/f.b*f.a, l); 
    }
    fract operator - (const fract &f) { 
        if(b==0 or f.b==0) return fract(a*f.b - b*f.a, 0);
        int l = lcm(b, f.b); return fract(l/b*a - l/f.b*f.a, l); 
    }
    fract operator * (const fract &f) { return fract(a*f.a, b*f.b); }
    fract operator / (const fract &f) { return fract(a*f.b, b*f.a); }
    void operator += (const fract &f) { *this = *this + f; }
    void operator -= (const fract &f) { *this = *this - f; }
    void operator *= (const fract &f) { *this = *this * f; }
    void operator /= (const fract &f) { *this = *this / f; }
    fract operator + (const int &f) { return fract(a + b*f, b); }
    fract operator - (const int &f) { return fract(a - b*f, b); }
    fract operator * (const int &f) { return fract(a*f, b); }
    fract operator / (const int &f) { return fract(a, b*f); }
    void operator += (const int &f) { *this = *this + f; }
    void operator -= (const int &f) { *this = *this - f; }
    void operator *= (const int &f) { *this = *this * f; }
    void operator /= (const int &f) { *this = *this / f; }
    bool operator < (const int &f) const{ return a < b*f; }
    bool operator <= (const int &f) const{ return a <= b*f; }
    bool operator > (const int &f) const{ return a > b*f; }
    bool operator >= (const int &f) const{ return a >= b*f; }
    bool operator == (const int &f) const{return a == b*f; }
    void print() { cout << "{" << a << ", " << b << "}"; }
};
ostream& operator << (ostream& os, fract& f) {
    return os << "{" << f.a << ", " << f.b << "}";
}