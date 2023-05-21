#include<bits/stdc++.h>

using namespace std;

using ll = long long ;
using pii = pair<ll , ll> ;
using i3 = tuple<ll , ll , ll> ;

const int N = 8e4+5;

int n ;
vector<pii> G[N] ;
vector<int> weight ;

// this should only be working on subtask 4

void dfs(int u , int p){
    for(auto[v , w] : G[u]){
        if(v == p) {
            continue ;
        }
        dfs(v , u);
        weight.push_back(w);
    }
}

bool solve(int mid){
    int cnt = 0 , sum = 0 ;

    for(int x : weight){
        sum += x ;
        if(sum >= mid){
            sum = 0 ;
            cnt++;
        }
    }

    return (cnt >= 3) ;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n ;
    for(int i=1 , u , v , w;i<=n;i++){
        cin >> u >> v >> w ;
        G[u].push_back({v , w}) , G[v].push_back({u , w}) ;
    }

    for(int i=0;i<=n;i++){
        if(G[i].size() == 1){
            dfs(i , i);
            break;
        }
    }

    /*
    swap(weight[2] , weight[3]) ;
    swap(weight[3] , weight[4]) ;
    */

    for(int x : weight){
        cout << x << " " ;
    }
    cout << "\n" ;

    int l = 1 , r = 1e12 , ans ;
    while(l <= r){
        int mid = (l+r)/2 ;
        if(solve(mid)){
            l = mid+1 ;
            ans = mid ;
        }
        else {
            r = mid-1 ;
        }
    }

    cout << ans ;
}
