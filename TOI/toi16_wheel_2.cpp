#include<bits/stdc++.h>

using namespace std;

const int N = 15 ;

using ll = long long ;

struct Con{
    ll a , m ;
};

ll n , t , len[N] , LCM[N] , ans = 1e18;
Con con[N] ;

string ss ;

vector<int> Tpoints[N] ;

void solve(int lvl){
    if(lvl == n+1){
        ll res = con[1].a ;
        for(int i=2;i<=n;i++){
            while(res % con[i].m != con[i].a){
                res += LCM[i-1] ;
            }
        }
        ans = min(res , ans);
        return ;
    }
    for(int cur : Tpoints[lvl]){
        con[lvl].a = cur ;
        solve(lvl+1);
    }
}

int main(){
    cin >> n >> t ;

    LCM[0] = 1 ;
    for(int i=1;i<=n;i++){
        cin >> ss ;
        len[i] = ss.size() ;
        con[i].m = len[i] ;

        for(int j=0;j<len[i];j++){
            if(ss[j] - '0' == t){
                Tpoints[i].push_back(j) ;
            }
        }
        LCM[i] = LCM[i-1] * len[i] / __gcd(LCM[i-1] , len[i]) ;
    }

    solve(1);

    cout << ans ;
}
