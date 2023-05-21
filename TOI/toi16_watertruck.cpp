#include<bits/stdc++.h>

using namespace std;

using ll = long long ;
using pii = pair<ll,ll> ;

const int N = 5e4+5 ;

ll n , m , pre[N] , ans , cycnt = 1 , cynum[N] ;
bool vis[2][N] , cycle[N] , head[N] , cyvis[N];
vector<pii> G[N] ;

stack<int> path ;

void dfs1(int u , int p){
    if(vis[0][u]){
        if(cynum[u] != 0)return ;
        while(!path.empty() && path.top() != u){
            cycle[path.top()] = true ;
            cynum[path.top()] = cycnt ;
            path.pop();
        }
        head[u] = true ;
        cycnt++;
        return ;
    }
    vis[0][u] = true ;
    path.push(u) ;
    for(auto [v , w] : G[u]){
        if(v == p){
            continue ;
        }
        dfs1(v , u);
    }
    if(!path.empty()){
        path.pop() ;
    }
}

void dfs2(int u , int pa){
    vis[1][u] = true ;

    for(auto [v , w] : G[u]){
        if(head[u] && cyvis[cynum[v]])continue;
        if(v == pa)continue;
        if(vis[1][v]){
            //back to head
            if(cycle[u] && head[v]){
                ans += w ;
            }
            continue ;
        }
        if(head[u] && cycle[v]){
            //first head to cycle
            ans += w , cyvis[cynum[v]] = true ;
        }
        else if(cycle[u] && cycle[v]){
            ans += w ;
        }
        else {
            ans += w*2 ;
        }
        dfs2(v , u);
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n ;
    for(int i=1 , u , v , w;i<=m;i++){
        cin >> u >> v >> w ;
        G[u].push_back({v , w}) , G[v].push_back({u , w});
    }


    dfs1(0 , -1);
    dfs2(0 , -1);

    cout << ans ;
}


//this solve can only solve for the case if 0 isn't in any cycle
