#include<bits/stdc++.h>

using namespace std;

using ll = long long ;
using pii = pair<ll , ll> ;
using i3 = tuple<ll , ll , ll> ;

const int N = 1e5+5 , M = 1e4+5 ;
const int MOD = 1e9+7 ;

int n , k , t , color[N] , cnt , ans = -1 ;

bool flg ;

vector<int> G[N] , lvl[M] ;

void dfs(int u){
    if(color[u] == 2){ // already did
        return ;
    }
    if(color[u] == 1){
        flg = true ;
        return ;
    }
    color[u] = 1 ;

    cnt++;
    for(int v : G[u]){
        dfs(v);
    }
    color[u] = 2 ;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k >> t ;

    for(int i=1;i<=n;i++){
        int l , p ;
        cin >> l >> p ;
        lvl[l].push_back(i);
        for(int j=1 , v;j<=p;j++){
            cin >> v ;
            G[i].push_back(v);

            //reverse edge
        }
    }

    for(int i=1;i<=k;i++){
        flg = false ;
        for(int x : lvl[i]){
            dfs(x);
        }
        // ถ้าจะทำระดับ i ให้ครบ ต้องทำทุกตัวที่อยู่ในระดับ i และทำตัวที่ต้องทำก่อน ของทุกตัวในระดับ i ด้วย

        if(flg || cnt > t){
            ans = i-1 ;
            break;
        }
    }
    if(!ans) ans = -1 ;
    cout << ans ;
}

