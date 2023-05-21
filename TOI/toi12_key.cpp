#include<bits/stdc++.h>

using namespace std;

const int N = 1005 ;

string a , b ;
int n , m , q ;
bool dp[N][N] ;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> a >> b ;

    n = a.size() , m = b.size() ;
    a = ' ' + a , b = ' ' + b ;

    cin >> q ;
    while(q--){
        string c ;

        cin >> c ;
        c = ' ' + c ;

        memset(dp , false , sizeof(dp));

        dp[0][0] = true ;
        for(int j=0;j<=n;j++){
            for(int k=0;k<=m;k++){
                int i = j + k ;
                if(dp[j-1][k] && a[j] == c[i]){
                    dp[j][k] = true ;
                }
                if(dp[j][k-1] && b[k] == c[i]){
                    dp[j][k] = true ;
                }
            }
        }

        if(dp[n][m]){
            cout << "Yes\n" ;
        }
        else cout << "No\n" ;
    }
}
//keypoint : boolean operator is slow
//dp definition : whether a from 1->i , b from 1->j can form c from 1->i+j
