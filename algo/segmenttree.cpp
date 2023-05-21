#include<bits/stdc++.h>

using namespace std;

const int N = 3e5+5 ;

int n , q , seg[2 * N] , a[N] ;

// range sum query
void build(int l , int r , int idx){
    // l = 1 , r = n , idx = 1
    if(l == r){
        seg[idx] = a[l] ;
        return ;
    }
    int mid = (l+r)/2 ;

    build(l , mid , idx*2) ;
    build(mid+1 , r , idx*2 + 1);

    seg[idx] = seg[idx*2] + seg[idx*2 + 1] ;
}

void add(int idx , int val , int l , int r , int node){
    // idx = our pos , val = val , l = 1 , r = n , node = 1
    if(l > idx || r < idx) {
        return ;
    }
    if(l == r){
        seg[node] = val ;
        return ;
    }

    int mid = (l+r)/2 ;

    add(idx , val , l , mid , node * 2);
    add(idx , val , mid+1 , r , node*2 + 1) ;

    seg[node] = seg[node * 2] + seg[node*2 + 1] ;
}


int query(int st , int ed , int l , int r , int node){
    //st = start point of sum , ed = end point of sum , l = border_left , r = border_right , node
    if(l > ed || r < st){
        return 0;
    }
    if(st <= l && r <= ed){
        return seg[node] ;
    }
    int mid = (l+r)/2 ;
    return query(st , ed , l , mid , node*2) + query(st , ed , mid+1 , r , node*2 + 1) ;
}

int main(){
    cin >> n >> q;

    for(int i=1 , x;i<=n;i++){
        cin >> a[i] ;
    }
    build(1 , n , 1);

    while(q--){
        int ty ; cin >> ty ;

        if(ty == 1){
            int idx ,val ; cin >> idx >> val ; // new val not old + new
            add(1 , n , idx , val , 1);
        }
        else {
            int l , r ; cin >> l >> r ;
            cout << query(l , r , 1 , n , 1) << "\n" ;
        }
    }
}
