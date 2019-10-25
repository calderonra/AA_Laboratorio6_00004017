#include <iostream>
#include <string>

using namespace std;

void fastestway( int a[][3], int t[][2], int e[2], int x[2], int n){

    int f1[n], f2[n];
    string camino1[n], camino2[n];

    f1[0] = e[0] + a[0][0];
    camino1[0] = "e11 |f1";
    f2[0] = e[1] + a[1][0];
    camino2[0] = "e12 |f2";

    for (int j = 1; j < n; j++){
        if((f1[j -1] + a[0][j]) <= (f2[j-1]+ t[1][j-1]+ a[0][j]) ){
            f1[j] = f1[j-1]+ a[0][j]; 
            camino1[j] = to_string(j-1)+" "+"a0"+to_string(j)+" ";
        }
        else{
            f1[j] = f2[j-1] + t[1][j-1] + a[0][j];            
            camino1[j] = to_string(j-1)+" "+"t1"+to_string(j-1)+" "+"a0"+to_string(j)+" ";
        }

        if((f2[j-1]+a[1][j]) <= (f1[j-1]+t[0][j-1]+a[1][j])){
            f2[j] = f2[j-1]+a[1][j];
            camino2[j] = to_string(j-1)+" "+"a1"+to_string(j)+ " ";
        
        }
        else{
            f2[j] = f1[j-1] + t[0][j-1]+a[1][j];
            camino2[j] = to_string(j-1)+" "+"t0"+to_string(j-1)+" "+"a1"+to_string(j)+ " ";
        }
    }
    int f = 0;
    if((f1[n-1] + x[0]) <= f2[n-1]+x[1]){
        f1[n-1] = f1[n-1] + x[0];
        f = f1[n-1];
        cout<<"F1[n]: "<<f<<endl;
        for (int k = 0; k<n;k++){
            cout<<camino1[k];
        }
    }else{
        f2[n-1] = f2[n-1] + x[1];
        f = f2[n-1];
        cout<<"F2[n]: "<<f<<endl;

        for (int l = 0; l<n;l++){
            cout<<camino2[l];
        }
    }




}


int main(){
int n = 3;
    int t[2][2], a[2][3], e[2],x[2];
    t[0][0] = 2;
    t[0][1] = 2;
    t[1][0] = 1;
    t[1][1] = 3;

    a[0][0] = 8;
    a[0][1] = 4;
    a[0][2] = 6;
    a[1][0] = 5;
    a[1][1] = 7;
    a[1][2] = 5;

    e[0] = 3;
    e[1] = 1;

    x[0] = 3;
    x[1] = 3;
    fastestway(a, t, e, x, n);
    return 0;
}