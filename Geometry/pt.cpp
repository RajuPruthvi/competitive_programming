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