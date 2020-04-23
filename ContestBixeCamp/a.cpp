#include<bits/stdc++.h>
using namespace std;

int x[5] = {0, 1, -1, 1, -1};
int y[5] = {0, 1, -1, -1, 1};

int n;
char m[510][510];

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> m[i][j];
        }
    }

    int resp = 0;

    for(int i = 2; i <= n-1; i++){
        for(int j = 2; j <= n-1; j++){
            int achou = 1;

            /*
            if(m[i-1][j-1] == 'X' && m[i-1][j+1] == 'X' && m[i+1][j-1] == 'X' 
            && m[i+1][j+1] == 'X' && m[i][j] == 'X'){
                resp++;
            }
            */

            /*
                int x[5] = {0, 1, -1, 1, -1};
                int y[5] = {0, 1, -1, -1, 1};     
            */

            for(int k = 0; k < 5; k++){
                if(m[i + x[k]][j + y[k]] == '.'){
                    achou = 0;
                    break;
                }
            }



            if(achou == 1){
                resp++;
            }
        }
    }

    cout << resp << endl;
}