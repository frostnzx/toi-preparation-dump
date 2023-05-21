#include<bits/stdc++.h>

using namespace std;

const int N = 2005 ;

using ll = long long ;
using pii = pair<int,ll> ;
using i3 = tuple<ll,int,int> ;


ll n , m , s , e , dist[N][N];
vector<pii> G[N] , way ;
priority_queue<i3 , vector<i3> , greater<i3>> pq ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> s >> e >> m ;
    for(int i=1 , u , v , w;i<=m;i++){
        cin >> u >> v >> w ;
        G[u].push_back({v , w});
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dist[i][j] = 1e9 ;
        }
    }

    dist[s][0] = 0 ;
    pq.push({dist[s][0] , s , 0});
    while(!pq.empty()){
        auto[d , u , cnt] = pq.top();
        pq.pop();
        if(d > dist[u][cnt]){
            continue;
        }
        for(auto [v , w] : G[u]){
            if(dist[u][cnt] + w < dist[v][cnt+1]){
                dist[v][cnt+1] = dist[u][cnt] + w ;
                pq.push({dist[v][cnt+1] , v , cnt+1}) ;
            }
        }
    }

    for(int i=0;i<=n;i++){
        if(dist[e][i] == 1e9){
            continue ;
        }
        bool cont = false ;
        for(auto [d , cnt] : way){
            if(d <= dist[e][i] && cnt <= i){
                cont = true ;
                break;
            }
        }
        if(cont){
            continue ;
        }
        way.push_back({dist[e][i] , i});
    }

    int q , x;
    cin >> q ;
    while(q--){
        cin >> x ;

        ll ans = 1e18 ;
        for(auto [d , cnt] : way){
            ans = min(ans , d + x * (cnt-1)) ;
        }
        cout << ans << " " ;
    }
}

// keypoint : หาทุกวิธี ที่จะไปถึง จุดหมายสั้นที่สุด ของการใช้ เส้นทุกจำนวน และตัดวิธีที่ไม่มีทางเป็นไปได้
