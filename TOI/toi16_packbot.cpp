#include<bits/stdc++.h>

using namespace std;

const int N = 1e4+5 ;

const int percent[4] = {0 , 4 , 8 , 16} ;

string in ;
vector<int> s ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> in ;
    int n = in.size() ;
    for(int i=0;i<n;i++){
        int v ;
        if(in[i] >= 'A' && in[i] <= 'Z'){
            v = 20 ;
        }
        else if(in[i] == '['){
            v = -1 ;
        }
        else if(in[i] == ']'){
            v = -2 ;
        }
        else if(in[i] >= '1' && in[i] <= '3'){
            v = in[i] - '0' ;
        }
        s.push_back(v);
    }

    while(s.size() > 1){
        int pos , mxprio = -1e9 , st = 0 , ed = s.size() - 1 ;

        for(int i=0;i<s.size();i++){
            if(s[i] == -1){
                st = i ;
            }
            if(s[i] == -2){
                ed = i ;
                break ;
            }
        }
        if(s[st] == -1 && s[ed] == -2 && ed - st + 1 == 3){
            int nval = s[st+1] ;

            s.erase(s.begin() + st , s.begin() + ed+1) ;
            s.insert(s.begin() + st , nval) ;

            continue ;
        }
        for(int i=st;i<=ed;i++){
            if(s[i] >= 1 && s[i] <= 3){
                if(s[i] > mxprio){
                    mxprio = s[i] ;
                    pos = i ;
                }
            }
        }
        int nval = ((s[pos-1] + s[pos+1]) * percent[s[pos]] / 100) + s[pos-1] + s[pos+1] ;


        s.erase(s.begin() + pos-1 , s.begin() + pos+2) ;
        s.insert(s.begin()+ pos - 1 , nval);
    }

    cout << s[0] ;
}
