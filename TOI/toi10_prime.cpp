#include<bits/stdc++.h>

using namespace std;

using ll = long long ;

const int N = 1e7 ;

int q ;
vector<ll> ans ; bool vis[N+5] ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> q ;

    for(int i=2 ; i<=N;i++){
        if(vis[i]){
            continue;
        }
        ans.push_back(i);
        for(int j=i+i;j<=N;j+=i){
            vis[j] = true ;
        }
    }

    cout << ans[q-1] ;
}
