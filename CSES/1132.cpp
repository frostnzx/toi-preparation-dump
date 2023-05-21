#include<bits/stdc++.h>

using namespace std;

using ll = long long ;
using pii = pair<ll,ll> ;
using i3 = tuple<ll , ll , ll> ;

const int N = 2e5+5 ;

int n , m , depth[N] , ans[N];

vector<int> G[N] ;

// re rooting technique also know as in-out dp on tree
// usually store in[N] , out[N] array but this this code only store in ( depth )

void cal_depth(int u , int p){
    for(int v : G[u]){
        if(v == p){
            continue ;
        }
        cal_depth(v , u);
        depth[u] = max(depth[u] , depth[v] + 1) ;
    }
}

void solve(int u , int p , int pv_ans){
    vector<int> prefix(1 , -1) , suffix(1 , -1) ;

    int child = 0 ;
    for(int v : G[u]){
        if(v == p){
            continue ;
        }
        prefix.push_back(depth[v]) , suffix.push_back(depth[v]) ;
        ++child ;
    }
    prefix.push_back(-1);
    suffix.push_back(-1);

    for(int i=1;i<=child;i++){
        prefix[i] = max(prefix[i] , prefix[i-1]) ;
    }
    for(int i=child;i>=1;i--){
        suffix[i] = max(suffix[i] , suffix[i+1]) ;
    }

    int idx = 1 ;
    for(int v : G[u]){
        if(v == p){
            continue ;
        }
        int uans = 1 + max(pv_ans , max(prefix[idx-1] , suffix[idx+1])) ;
        solve(v , u , uans);
        idx++;
    }
    if(depth[u] == 0){ // u is leaf
        ans[u] = 1 + pv_ans ; // goes back to parent
    }
    else {
        ans[u] = max(depth[u] , pv_ans + 1) ;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n ;
    for(int i=1;i<=n-1;i++){
        ll u , v , w ;
        cin >> u >> v ;
        G[u].push_back(v) , G[v].push_back(u) ;
    }

    cal_depth(1 , 1);
    solve(1 , 1 , -1) ;

    for(int i=1;i<=n;i++){
        cout << ans[i] << " " ;
    }
}

