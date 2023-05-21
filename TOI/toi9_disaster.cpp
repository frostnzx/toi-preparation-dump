#include<bits/stdc++.h>

using namespace std;

using pii = pair<int,int> ;

const int N = 35 ;

int n ;
set<int> G[N] , vertex ;
vector<int> ans ;

void solve(int s){
    //fleury algorithm

    stack<int> st ;
    st.push(s);

    while(!st.empty()){
        int v = st.top();
        if(G[v].empty()){
            ans.push_back(v);
            st.pop();
        }
        else {
            int x = *G[v].begin() ;
            G[v].erase(x);
            G[x].erase(v);
            st.push(x);
        }
    }

    for(int x : ans){
        cout << char(x + 'A') << " " ;
    }
    cout << "\n" ;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n ;

    for(int i=1;i<=n;i++){
        string x ; cin >> x ;
        int u = x[0] - 'A' , v = x[1] - 'A' ;
        G[u].insert(v);
        G[v].insert(u);

        vertex.insert(u) , vertex.insert(v) ;
    }

    int odd_cnt = 0 , s ;
    for(int i : vertex){
        if(G[i].size() % 2 == 1){
            odd_cnt ++ , s = i ;
        }
    }
    if(odd_cnt == 0){ //euler curcuit
        solve(*vertex.begin());
    }
    else if(odd_cnt == 2){ //euler path
        solve(s);
    }
}


//keypoint : find euler path/curcuit
// https://www.youtube.com/watch?v=b8CWF8Helx4&ab_channel=ContemporaryMath
