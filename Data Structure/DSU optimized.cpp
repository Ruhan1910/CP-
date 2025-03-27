const int N = 1e5 + 5;
struct disjoint{
    int p[N], sz[N];
    void Build(int n){
        for(int i = 0; i <= n; i++){
            p[i] = i, sz[i] = 1;
        }
    }
    int Find(int x){
        if(x == p[x]) return x;
        return p[x] = Find(p[x]);
    }
    void Union(int a, int b){
        a = Find(a);
        b = Find(b);
        if(a == b) return;
        if(sz[a] < sz[b]) swap(a,b);
        p[b] = a;
        sz[a] += sz[b];
    }
};
