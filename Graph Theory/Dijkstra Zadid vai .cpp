struct node{
    int city,dist;


    bool operator < (const node &n) const{
        if(dist==n.dist)
            return city>n.city;
        return dist > n.dist;
    }
};


void dijkstra(int source){
    for(int i = 1; i <= n; i++) d[i] = inf;
    d[source] = 0;
    node u;
    u.city = source;	
    u.dist = 0;
    priority_queue <node> pq;
    pq.push(u);
    while(!pq.empty()){
        node u= pq.top();
        pq.pop();
	//if(vis[u.city]==1) continue;
        for(int i = 0; i < G[u.city].size(); i++){
            node v;
            v.city = G[u.city][i].first;
            v.dist = u.dist + G[u.city][i].second;
            if(d[v.city] > v.dist){
                d[v.city] = v.dist;
                pq.push(v);
            }
        }
    }
}

