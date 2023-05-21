#include<bits/stdc++.h>

using namespace std;

const int N = 105 ;

int n , s , t ;
bool G[N][N] ;
vector<int> ans ;

void solve(int i , int lane){
    if(i == t){
        for(int x : ans){
            cout << x << "\n" ;
        }
        return ;
    }
    if(lane-1 >= 1 && G[i+1][lane-1]){
        ans.push_back(1); solve(i+1 , lane-1) ;
        ans.pop_back();
    }
    if(G[i+1][lane]){
        ans.push_back(3); solve(i+1 , lane) ;
        ans.pop_back();
    }
    if(G[i+1][lane+1]){
        ans.push_back(2); solve(i+1 , lane+1) ;
        ans.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> s >> t ;

    for(int i=1;i<=t;i++){
        for(int j=1;j<=n;j++){
            bool x ; cin >> x ;
            G[i][j] = !x ;
        }
    }
    solve(0 , s) ;
}
