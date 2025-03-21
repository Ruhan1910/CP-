///Using edge vector

//In a graph from source node to destination node it can have maximum n-1 node.
//So we need to relax the path maximum n-1 time. after that all node will have
//minimum distance from source node. If negative cycle exist then the distance 
//will be negative.

void bellman_ford(int s){
	for(int i = 1; i <= n; i++){
        dis[i] = INF;
	}
	dis[s] = 0;
	for(int i = 1; i < n; i++){
        for(auto [uv, w] : edge){ //Here edge is the edge vector (u->v, w)
            int u = uv.first;
            int v = uv.second;
            if(dis[u] + w < dis[v]){
                dis[v] = dis[u] + w;
            }
        }
	}
}
