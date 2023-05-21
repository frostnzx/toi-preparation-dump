#include<bits/stdc++.h>

using namespace std;

using ll = long long ;
using pii = pair<ll,ll> ;
using i3 = tuple<ll,ll,ll> ;

const int N = 2e4+5 ;

ll n , m , k , p ;

ll dist[N][35] ;
bitset<35> vis[N] ;

struct warp{
    int y1 , x1 , y2 , x2 ;
};
vector<warp> vec ;
vector<pii> G[N] ;

priority_queue<i3 , vector<i3> , greater<i3>> pq ;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> k >> p ;

	vec.push_back({1 , 1 , 1 , 1});
	for(int i=1;i<=k;i++){
        ll y1 , x1 , y2 , x2 ;
        cin >> y1 >> x1 >> y2 >> x2 ;
        vec.push_back({y1 , x1 , y2 , x2}) ;
	}
	vec.push_back({n , m , n , m});

	int V = k + 2 ;

    // convert to complete graph with coord compression

    for(int i=0;i<V;i++){
        // i->j
        for(int j=0;j<V;j++){
            if(i == j){
                continue ;
            }
            G[i].push_back({j , abs(vec[i].x2 - vec[j].x1) + abs(vec[i].y2 - vec[j].y1)}) ;
        }
    }

    for(int i=0;i<V;i++){
        for(int j=0;j<=p;j++){
            dist[i][j] = 1e18 ;
        }
    }

    dist[0][0] = 0 ;
    pq.push({0 , 0 , 0});

    while(!pq.empty()){
        auto[d , u , nodes] = pq.top();
        pq.pop();

        if(vis[u][nodes]){
            continue ;
        }
        vis[u][nodes] = true ;

        for(auto [v , w] : G[u]){
            if(v == 0 || v == V - 1){ // these 2 spots aren't warp
                if(dist[u][nodes] + w < dist[v][nodes]){
                    dist[v][nodes] = dist[u][nodes] + w ;
                    pq.push({v , dist[v][nodes] , nodes});
                }
                continue ;
            }
            if(nodes + 1 > p) continue ;
            if(dist[u][nodes] + w < dist[v][nodes + 1]){
                dist[v][nodes + 1] = dist[u][nodes] + w ;
                pq.push({dist[v][nodes + 1] , v , nodes + 1});
            }
        }
    }

    ll ans1 = 1e18 , ans2 ;
    for(int i=0;i<=p;i++){
        if(dist[V - 1][i] < ans1){
            ans1 = dist[V - 1][i] , ans2 = i ;
        }
    }

    cout << ans1 << " " << ans2 ;
}
