#include<bits/stdc++.h>

using namespace std;

const int N = 1e6+5 ;

int n , m ; bool vis[N] ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m ;

    int pos = 1 ;
    for(int i=1;i<=n;i++){
        int c = 0 ;
        while(c < m){
            if(!vis[pos]){
                c++;
            }
            if(c < m)pos++;
            if(pos == n+1){
                pos = 1 ;
            }
        }
        cout << pos << " " ;
        vis[pos] = true ;
        while(vis[pos] && i < n-1){
            pos++;
            if(pos == n+1){
                pos = 1 ;
            }
        }
    }
}
