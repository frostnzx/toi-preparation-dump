#include<bits/stdc++.h>

using namespace std;

const int N = 5e5+5 ;

int n , m , dp[N] ;

bool vis1[N] , vis2[N] , vis3[N] , chk[N] , found ;

vector<int> G[N] ;
stack<int> st ;

void dfs1(int u , int p){
    vis1[u] = true ;

    st.push(u) ;
    for(int v : G[u]){
        if(v == p){
            continue;
        }
        if(vis1[v] && !found){
            found = true ;
            while(!st.empty()){
                int tp = st.top() ;
                st.pop();

                if(tp == v){
                    chk[tp] = true ;
                    break;
                }
                chk[tp] = true ;

            }

            break;
        }
        else if(!vis1[v]){
            dfs1(v , u);
        }
    }
    if(!st.empty()){
        st.pop();
    }
}

void dfs2(int u){
    vis2[u] = true ;
    for(int v : G[u]){
        if(vis2[v])continue;
        dfs2(v);
        if(!chk[v]){
            dp[u] += dp[v] + 1 ;
        }
    }
}

void dfs3(int u){
    vis3[u] = true ;
    for(int v : G[u]){
        if(vis3[v])continue;
        dfs3(v) ;
        dp[u] += dp[v] + 1 ;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m ;

    for(int i=1 , u , v;i<=n;i++){
        cin >> u >> v ;
        G[u].push_back(v) , G[v].push_back(u) ;
    }
    dfs1(m , -1);


    if(chk[m]){
        dfs2(m) ;
    }
    else {
        dfs3(m) ;
    }


    int idx , mx = -1e9 ;
    for(int i=1;i<=n;i++){
        if(i == m){
            continue ;
        }
        if(dp[i] > mx){
            mx = dp[i] ;
            idx = i ;
        }
    }

    cout << idx << "\n" << mx ;
}

//observation : E == V ดังนั้นจะมี 1 cycle

//keypoint : แยกกรณี 1. ถ้า m อยู่ใน cycle การทำลาย node ที่อยู่ใน cycle จะไม่ทำให้ node ใน cycle ตัวอื่น disconnect กับ m
// 2. ถ้า m ไม่อยู่ใน cycle การทำลาย node ใดๆไปก็จะไม่สามารถไปถึง child node ของ node นั้นๆได้

//important : เจอข้อ graph traversal ตำแหน่งจุดเริ่มต้นสำตัญ
