#include<bits/stdc++.h>

using namespace std;

using pii = pair<int,int> ;

const int N = 1e6+5 , N2 = 2e9+5 ;

int z , k , n , pc , nc , st , ed , V[N] , ans = -1e9 ;
bitset<N2> vis ;
map<int , pii> mp ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> z >> k >> n ;
    for(int i=1 , x;i<=n;i++){
        cin >> V[i] ;
        vis[V[i]] = vis[V[i] - 1] = true ;
    }
    for(int i=V[1];i<=V[n];i++){
        if(__gcd(i , k) != 1) pc++ ;
        else nc++;

        if(vis[i]){
            mp[i] = {pc , nc} ;
        }
    }

}
