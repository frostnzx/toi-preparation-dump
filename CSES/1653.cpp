#include<bits/stdc++.h>

using namespace std;

using ll = long long ;
using pii = pair<ll,ll> ;
using i3 = tuple<ll,ll,ll> ;

const int N = 25 ;

//key observation : N is low can we try bit masking?

int n , w , v[N] ;
pii dp[1 << N] ;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> w ;
	for(int i=0;i<n;i++){
        cin >> v[i] ;
	}

	for(int mask = 0 ; mask < (1 << n) ; mask++){
        dp[mask] = {n+1 , w+1} ;
	}

    dp[0] = {1 , 0} ;
	for(int mask = 0 ; mask < (1 << n) ; mask++){
        for(int i=0;i<n;i++){
            if(mask & (1 << i)){
                continue ;
            }
            int n_mask = mask | (1 << i) ,
            rides = dp[mask].first , weight = dp[mask].second ;
            if(weight + v[i] <= w){
                weight += v[i] ;
            }
            else {
                weight = v[i] ;
                rides++;
            }

            dp[n_mask] = min(dp[n_mask] , pii(rides , weight));
        }
	}

	cout << dp[(1 << n) - 1].first ;
}
