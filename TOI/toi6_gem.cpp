#include<bits/stdc++.h>

using namespace std;

using pii = pair<int,int> ;

const int N = 1e5+5 ;

int n , m , q = 5 ;

bool vis[N] ;
vector<pii> vec(N) ;
vector<int> G[N] ;
unordered_map<int ,int> mp ;

bool dfs(int u , int i){
    //cout << "i = " << i << " u = " << u << "\n" ;
    if(i == n){
        return true ;
    }
    vis[mp[u]] = true ;

    bool ans = false ;
    for(int v : G[u]){
        if(!vis[v] && (u == vec[i].first || u == vec[i].second)){
            ans = ans || dfs(v , i+1) ;
        }
    }
    return ans ;
}

void solve(){
    mp.clear();
    for(int i=1;i<=m;i++){
        G[i].clear() ;
    }
    memset(vis , false , sizeof(vis));

    cin >> n >> m ;

    for(int i=1;i<=n;i++){
        int a , b ; cin >> a >> b ;
        vec[i] = {a , b} ;
    }
    for(int i=1;i<n;i++){
        G[vec[i].first].push_back(vec[i+1].first) ;
        G[vec[i].first].push_back(vec[i+1].second) ;
        G[vec[i].second].push_back(vec[i+1].first) ;
        G[vec[i].second].push_back(vec[i+1].second) ;
    }

    for(int i=1;i<=(m/2);i++){
        int a , b ; cin >> a >> b ;
        mp[a] = b ; mp[b] = a ;
    }

    if(dfs(vec[1].first , 1) || dfs(vec[1].second , 1)){
        cout << "Y" ;
    }
    else cout << "N" ;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    while(q--){
        solve() ;
    }
}


// SCC tarjan do it later na
