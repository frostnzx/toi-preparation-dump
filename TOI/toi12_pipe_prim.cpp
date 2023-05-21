#include<bits/stdc++.h>
#define DEBUG 0

using namespace std;

const int N = 15005 ;

using pii = pair<int,int> ;

pii ho[N] ;

int n , k , dist[N] ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k ;
    for(int i=1 , x, y;i<=n;i++){
        cin >> x >> y ;
        ho[i] = {x , y} ;
        dist[i] = 1e9 ;
    }

    int ans = 0 ;

    dist[1] = 0 ;
    for(int i=1;i<n;i++){ // run for v-1
        int mn = 1e9 , idx ;

        for(int v=i+1;v<=n;v++){ // can skip 1->i because they're already in MST
            dist[v] = min(dist[v] , abs(ho[v].first - ho[i].first) + abs(ho[v].second - ho[i].second)) ;
            if(dist[v] < mn){
                idx = v , mn = dist[v] ;
            }
        }
        ans += dist[idx] ;

        //swap to keep idx in MST and maintain 1->idx to still be MST

        // dist[i+1] will be the minimum dist for next
        swap(ho[i+1] , ho[idx]);
        swap(dist[i+1] , dist[idx]);
    }
    sort(dist+1 , dist+n+1 , greater<int>());

    //increase component from 1 to k by remove biggest edges k-1 times
    for(int i=1;i<k;i++){
        ans -= dist[i] ;
    }

    cout << ans ;
}

//keypoint : Dense graph so use prim's MST O(V^2) instead of kruskal

//implementation trick : keep maintain dist from 1->i to be MST
// so that we don't have to keep linear search 1->n everytime only
// need search from i+1 -> n
