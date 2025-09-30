
struct Point{
    ll x, y;
};

int orientation(Point a, Point b, Point c){ //pii means pair<int, int>
    ll val = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x); // cross product of ab and bc vector

    if(val == 0) return 0; //collinear
    if(val < 0) return 1; //clockwise
    else return 2; //counterClockwise
}

bool onSegment(Point a, Point b, Point c){
    if((c.x < min(a.x, b.x)) || (c.x > max(a.x, b.x))) return false;
    if((c.y < min(a.y, b.y)) || (c.y > max(a.y, b.y))) return false;
    return true;
}

bool Intersect(Point a, Point b, Point x, Point y){
    int o1 = orientation(a, b, x);
    int o2 = orientation(a, b, y);
    int o3 = orientation(x, y, a);
    int o4 = orientation(x, y, b);

    if(o1 != o2 && o3 != o4) return true;

    if(o1 == 0 && onSegment(a, b, x)) return true;
    if(o2 == 0 && onSegment(a, b, y)) return true;
    if(o3 == 0 && onSegment(x, y, a)) return true;
    if(o4 == 0 && onSegment(x, y, b)) return true;

    return false;
}
