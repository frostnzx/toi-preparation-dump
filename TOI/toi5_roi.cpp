#include<bits/stdc++.h>

using namespace std;

double c ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> c ;

    double p = 1000.00 , inv = 100.00 ;

    int a1 , a2 ; double a3 = 1e9 ;

    while(p <= 15000){
        for(int i = 74;i <= 144 ; i++){
            double price = i * 1.00 ;
            double D = price - 100 ;
            double sell = ((100 - (0.8569 * exp(0.09 * D)))) * p / 100.00 ;
            double in = sell * price ;
            double pro = in - (c + p*inv) ;

            if(pro > 0){
                if(pro < a3){
                    a1 = p , a2 = price , a3 = pro ;
                }

            }
        }
        p += 500.00 ;
        inv -= 1.0 ;
    }

    cout << a1 << "\n" << a2 << fixed << setprecision(2) << "\n" << a3 ;
}
