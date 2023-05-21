#include<bits/stdc++.h>

using namespace std;

using ll = long long ;
using pii = pair<ll,ll> ;

const int N = 5e5+5 ;

ll n , k , p[N] , dp[N] ;
deque<pii> q ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k ;
    for(int i=1;i<=n;i++){
        cin >> p[i] ;
    }

    dp[1] = p[1] ;
    q.push_back({dp[1] , 1});

    for(int i=2;i<=n;i++){
        while(!q.empty() && i - q.front().second > k){
            q.pop_front() ;
        }
        dp[i] = q.front().first + p[i] ;
        while(!q.empty() && q.back().first >= dp[i]){
            q.pop_back() ;
        }
        q.push_back({dp[i] , i});
    }
    cout << dp[n] ;
}
