#include<bits/stdc++.h>

using namespace std;

using ll = long long ;

const int N = 15 ;

ll n , t , sz[N] , LCM[N] , ans = 1e18 ;
string s[N] ;

void solve(ll cur , int lvl){
    if(lvl == n+1){
        if(cur != 0)
            ans = min(ans , cur) ;
        return ;
    }

    for(ll now = cur ; now < LCM[lvl] ; now += LCM[lvl-1]){
        if(now > ans){
            // no way it would be the answer
            break;
        }
        if(s[lvl][now % sz[lvl]] - '0' == t){
            solve(now , lvl+1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> n >> t ;

    LCM[0] = 1 ;
    for(int i=1;i<=n;i++){
        cin >> s[i] ;
        sz[i] = s[i].size() ;
        LCM[i] = (LCM[i-1] * sz[i]) / __gcd(LCM[i-1] , sz[i]) ;
    }
    solve(0 , 1) ;

    cout << ans ;
}

//keypoint : CRT and notes in my ipad would explain it clearly
