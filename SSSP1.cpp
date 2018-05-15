#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <set>
#include <map>

#define INF 1e9

using namespace std;
vector<vector<pair<int,int>>> AL; //pair weight,vertex
unordered_map<int,int> dist;
vector<int> visited;

void dijkstra(int v,int numOfV){

    set<pair<int,int>> pq; //weight, vertex
    pq.insert({0,v});
    for (int i = 0; i < numOfV; i++) {
        if(i!=v)
            pq.insert({INF,i});
    }
    while(!pq.empty()){
        pair<int,int> front=*pq.begin();
        pq.erase(pq.begin());
        int d=front.first;
        int u=front.second; //current vertex
        if(visited[u]==1)
            continue;
        visited[u]=1;
        for(auto &v_pair:AL[u]){
            int v_weight=v_pair.first;
            int v_vertex=v_pair.second;
            if(dist[u]+v_weight<dist[v_vertex]){
                pq.erase(pq.find({dist[v_vertex],v_vertex}));
                dist[v_vertex]=dist[u]+v_weight;
                pq.insert({dist[v_vertex],v_vertex});
            }
        }
    }

}

int main(){
    freopen("sssp1.in","r",stdin);
    while(true){
        int n,m,q,s;
        cin>>n>>m>>q>>s;
        if(n+m+q+s==0)
            break;

        AL.assign(n,vector<pair<int,int>>());
        while(m--){
            int u,v,w;
            cin>>u>>v>>w;
            AL[u].push_back({w,v});
        }
        dist.clear();
        visited.clear();

        for(int i=0;i<n;i++){
            dist[i]=INF;
            visited.push_back(0);
        }

        dist[s]=0;
        dijkstra(s,n);

        while (q--){
            int dest;
            cin>>dest;
            int ans=dist[dest];
            if(ans==INF)
                cout<<"impossible"<<endl;
            else
                cout<<ans<<endl;
        }

        cout<<endl;
    }



    return 0;
}