struct pt {
    ll x, y;
    pt(ll x, ll y): x(x), y(y) {};
};
// cout
ostream& operator <<(ostream& out, pt A) {
    out << "{" << A.x << ", " << A.y << "}";
    return out;
}

pt operator +(pt A, pt B) { return {A.x+B.x, A.y+B.y};}
pt operator -(pt A, pt B) { return {A.x-B.x, A.y-B.y};}
ll operator ^(pt A, pt B) { return A.x*B.y - A.y*B.x;}