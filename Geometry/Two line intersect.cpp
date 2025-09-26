int orinetation(pii a, pii b, pii c){ //pii means pair<int, int>
    int val = (b.sc - a.sc) * (c.fi - b.fi) - (b.fi - a.fi) * (c.sc - b.sc);

    if(val == 0) return 0; //collinear
    if(val > 0) return 1; //clockwise
    else return 2; //counterClockwise
}

bool onSegment(pii a, pii b, pii c){
    if((c.fi < min(a.fi, b.fi)) || (c.fi > max(a.fi, b.fi))) return false;
    if((c.sc < min(a.sc, b.sc)) || (c.sc > max(a.sc, b.sc))) return false;
    return true;
}

bool Intersect(pii a, pii b, pii x, pii y){
    int o1 = orinetation(a, b, x);
    int o2 = orinetation(a, b, y);
    int o3 = orinetation(x, y, a);
    int o4 = orinetation(x, y, b);

    if(o1 != o2 && o3 != o4) return true;

    if(o1 == 0 && onSegment(a, b, x)) return true;
    if(o2 == 0 && onSegment(a, b, y)) return true;
    if(o3 == 0 && onSegment(x, y, a)) return true;
    if(o4 == 0 && onSegment(x, y, b)) return true;

    return false;
}
