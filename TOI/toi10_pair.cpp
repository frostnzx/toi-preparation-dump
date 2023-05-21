#include<bits/stdc++.h>

using namespace std;

const int N = 1005 ;

int n , dp[N][N] ;
char c[N] ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n ;
    for(int i=1;i<=n;i++){
        cin >> c[i] ;
    }

    for(int z=1;z<=n;z++){
        for(int l=1;l<=n-z+1;l++){
            int r = l+z-1 ;
            if(z == 1){
                dp[l][r] = 0 ; //if just 1 card just destroy
                continue;
            }
            if(c[l] == c[r]){
                dp[l][r] = dp[l+1][r-1] + 1 ; // if l card and r card match find most efficient way to destroy all between them and then destroy l and r
            }
            for(int k=l;k<r;k++){
                dp[l][r] = max(dp[l][r] , dp[l][k] + dp[k+1][r]); // find every possible substring to destroy l to r card
            }
        }
    }

    cout << dp[1][n] ;
}

//keypoint : MCM
