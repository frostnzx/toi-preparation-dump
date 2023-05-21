#include<bits/stdc++.h>

using namespace std;

using ll = long long ;
using pii = pair<ll , ll> ;
using i3 = tuple<ll , ll , ll> ;

const int N = 5005 ;
const int MOD = 1e9+7 ;

ll n , A[N] , dp[N][N] , ans[N] ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n ;
    for(int i=1;i<=n;i++){
        cin >> A[i] ;
    }

    // pre compute all possible eating subarray

    for(int i=n;i>=1;i--){
        for(int j=i;j<=n;j++){
            dp[i][j] = -1e18 ;
            dp[i][j] = max(dp[i][j] , dp[i+1][j] + A[i] + abs(A[i] - A[j]));
            dp[i][j] = max(dp[i][j] , dp[i][j-1] + A[j] + abs(A[i] - A[j]));
        }
    }

    // re calculate each subarray if it's better to cut in between them
    /*
    for(int z=2;z<=n;z++){
        for(int l=1;l<=n-z+1;l++){
            int r = l+z-1 ;
            for(int k=l;k<r;k++){
                dp[l][r] = max(dp[l][r] , dp[l][k] + dp[k+1][r]);
            }
        }
    }
    */

    for(int i=1;i<=n;i++){
        ans[i] = dp[1][i] ; // no cut
        for(int k=1;k<i;k++){
            ans[i] = max(ans[i] , ans[k] + dp[k+1][i]) ;
            // ans[k] = already cutted subarray
            // dp[k+1][i] = hasn't cut any
        }
    }

    cout << ans[n] ;

}


// tricks : optimize MCM in to n square by redefine answer array
