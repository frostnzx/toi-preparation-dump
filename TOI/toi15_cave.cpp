#include<bits/stdc++.h>

#define ll long long

using namespace std;

using pii = pair<int,int> ; 
using iii = tuple<int,int,int> ; // dist , node , countnode

const int N = 2e3+5 ; 
const int INF = 1e9+7 ; 

int n,m,a,b , q ; 

vector<pii> G[N] ; 
ll dist[N][N] ; // node , countnode 
bool vis[N][N] ; 
priority_queue<iii ,vector<iii> , greater<iii> > pq ;

vector<pii> path ;

void solve(){
    for(int i=0;i<=n;i++)
        for(int k=0;k<=n;k++)
            dist[i][k] = INF ; 
    dist[a][0] = 0 ; 
    pq.push({dist[a][0] , a , 0});
    while(!pq.empty()){
        int d , u , c ; tie(d,u,c) = pq.top() ; 
        pq.pop();
        if(vis[u][c])
            continue;
        vis[u][c] = true ; 
        if(u == b){
            path.push_back({dist[u][c] , c});
            continue;
        }
        for(auto vw : G[u]){
            int v,w ; tie(v,w) = vw ; 
            bool able = true ; 
            for(auto i : path){
                int iw , ic ; tie(iw,ic) = i ;
                if(iw <= dist[u][c] + w && ic <= c+1) // ดัก case ไม่เป็น optimal minimum distance ของระดับน้ำนั้นใดๆเลย
                    able = false ;
                    break ; 
            }
            if(!able) continue;
            if(!vis[v][c+1] && dist[u][c] + w < dist[v][c+1]){
                dist[v][c+1] = dist[u][c] + w ; 
                pq.push({dist[v][c+1] , v , c+1});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> a >> b >> m ; 
    for(int i=0;i<m;i++){
        ll u,v,w ; 
        cin >> u >> v >> w ; 
        G[u].push_back({v,w});
    }
    solve();
    cin >> q ; 
    while(q--){
        int x ; cin >> x ; 
        int ans = INF ; 
        for(auto i : path){
            int w , c ; tie(w,c) = i ; 
            ans = min(ans , w + (c-1)*x);
        }
        cout << ans << " " ;
    }
}