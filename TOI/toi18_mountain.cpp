#include<bits/stdc++.h>

using ll = long long ;

using namespace std;

const int N = 2e5+5 ;

ll n , m , a , b , dp[N][505] , V[N] ;

struct P{
    ll x , y , w ;

    bool operator<(const P &other) const{
        return w < other.w ;
    }
};

vector<P> vec ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m ;

    cin >> a >> b ;
    vec.push_back({a , b , 0});
    for(int i=1;i<=n-1;i++){
        ll x , y , w ;
        cin >> x >> y ;

        w = abs(a - x) + abs(b - y) ;

        vec.push_back({x , y , w});
    }

    sort(vec.begin() , vec.end());

    for(int i=1;i<=m;i++){
        cin >> V[i] ;
    }

    for(int i=1;i<=m;i++){
        dp[i][0] = 0 ;
        for(int j=1;j<n;j++){
            dp[i][j] = 1e18 ;
            for(int pre=0;pre<j;pre++){
                if(abs(vec[j].x - vec[pre].x) + abs(vec[j].y - vec[pre].y) <= V[i]){
                    dp[i][j] = min(dp[i][j] , dp[i][pre] + 1) ;
                }
            }
        }
    }
    ll ans = 0 ;
    for(int i=1;i<=m;i++){
        ans += dp[i][n-1] ;
    }

    cout << ans ;
}

