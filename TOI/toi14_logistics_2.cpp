#include<bits/stdc++.h>

using namespace std;

using ll = long long ;

using pii = pair<int,int> ;
using i4 = tuple<ll,int,int,int> ;

const int N = 105 ;

int n , m , price[N] , s , e , f ;
ll dist[N][105][2] , ans = 1e9 ;

vector<pii> G[N] ;
priority_queue<i4 , vector<i4> , greater<i4>> pq ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n ;
    for(int i=1;i<=n;i++){
        cin >> price[i] ;
    }
    cin >> s >> e >> f >> m ;

    for(int i=1 , u , v , w;i<=m;i++){
        cin >> u >> v >> w ;
        G[u].push_back({v , w}) , G[v].push_back({u , w});
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=100;j++){
            dist[i][j][0] = dist[i][j][1] = 1e9 ;
        }
    }

    pq.push({0 , s , 0 , 0});
    dist[s][0][0] = 0 ;

    while(!pq.empty()){
        auto[d , u , fuel , ticket] = pq.top();
        pq.pop();

        if(d > dist[u][fuel][ticket]){
            continue;
        }

        for(auto [v , w] : G[u]){
            for(int nfuel = max(fuel , w) ; nfuel <= f ; nfuel++){
                ll nd = (nfuel - fuel) * price[u] + d ;
                if(nd < dist[v][nfuel - w][ticket]){
                    dist[v][nfuel - w][ticket] = nd ;
                    pq.push({nd , v , nfuel - w , ticket});
                }
            }
            if(ticket == 0 && d < dist[v][f - w][1]){
                dist[v][f - w][1] = d ;
                pq.push({d , v , f - w , 1});
            }
        }
    }

    for(int i=0;i<=f;i++){
        ans = min({ans , dist[e][i][1] + (f - i)*price[e] , dist[e][i][0]}) ;
    }

    cout << ans ;
}
