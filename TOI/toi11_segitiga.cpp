#include<bits/stdc++.h>

using namespace std;

const int N = 260 ;

int n ;
bool dp[N][N][3] ;

void solve(){
    cin >> n ;

    char s[N] ;
    for(int i=1;i<=n;i++){
        cin >> s[i] ;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j][0] = false ;
            dp[i][j][1] = false ;
            dp[i][j][2] = false ;
        }
    }

    for(int i=1;i<=n;i++){
        dp[i][i][s[i] - '0'] = true ;
    }

    for(int z=1;z<=n;z++){
        for(int l=1;l<=n-z+1;l++){
            int r = l+z-1 ;
            if(z == 1){
                continue;
            }
            for(int k=l;k<r;k++){
                if(dp[l][k][0] && dp[k+1][r][1]){
                    dp[l][r][1] = true ;
                }
                if(dp[l][k][1] && dp[k+1][r][1]){
                    dp[l][r][1] = true ;
                }
                if(dp[l][k][1] && dp[k+1][r][2]){
                    dp[l][r][1] = true ;
                }
                if(dp[l][k][2] && dp[k+1][r][0]){
                    dp[l][r][1] = true ;
                }
                if(dp[l][k][2] && dp[k+1][r][2]){
                    dp[l][r][1] = true ;
                }
                if(dp[l][k][0] && dp[k+1][r][0]){
                    dp[l][r][2] = true ;
                }
                if(dp[l][k][1] && dp[k+1][r][0]){
                    dp[l][r][2] = true ;
                }
                if(dp[l][k][2] && dp[k+1][r][1]){
                    dp[l][r][2] = true ;
                }
                if(dp[l][k][0] && dp[k+1][r][2]){
                    dp[l][r][0] = true ;
                }
            }
        }
    }

    if(dp[1][n][0]){
        cout << "yes\n" ;
    }
    else cout << "no\n" ;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tc = 20 ;
    while(tc--){
        solve();
    }
}


//keypoint : เพิ่มมาอีก state เพื่อดูว่าจากช่วง l ถุึง r จะสามารถสร้าง c ได้ไหม
