#include<bits/stdc++.h>

using namespace std;

using ll = long long ;
using pii = pair<ll,ll> ;
using i3 = tuple<ll , ll , ll> ;

const int N = 2e5+5 ;

int n , m , dp[N] ;
vector<int> G[N] ;

int solve(int u){
    if(dp[u] != -1){
        return dp[u] ;
    }
    dp[u] = 1 ;
    for(int v : G[u]){
        solve(v);
        dp[u] += dp[v] ;
    }
    return dp[u] ;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n ;
    for(int i=2 , x;i<=n;i++){
        cin >> x ; G[x].push_back(i);
    }
    memset(dp , -1  ,sizeof(dp));
    solve(1);
    for(int i=1;i<=n;i++){
        cout << dp[i] - 1 << " " ;
    }
}
