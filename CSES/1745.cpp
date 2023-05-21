#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+5 ;

int n , s , coins[N] , ans ;
bool dp[N] ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n ;
    for(int i=1;i<=n;i++){
        cin >> coins[i] ;
        s += coins[i] ;
    }

    dp[0] = true ;
    for(int i=1;i<=n;i++){
        for(int j=s;j>=1;j--){ // reverse index so that every dp[j - 1 ... 1] never use coins[i]
            // only dp[j+1 ... n] used coins[i]
            if(j - coins[i] >= 0 && dp[j - coins[i]]){
                if(!dp[j]) ans++;
                dp[j] = true ;
            }
        }
    }

    cout << ans << "\n" ;
    for(int i=1;i<=s;i++){
        if(dp[i]) cout << i << " " ;
    }
}
