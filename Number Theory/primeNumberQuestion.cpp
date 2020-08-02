// Algos to find Prime Number till n in n*n , sqr(n)*n , n(seive algo)

#include<bits/stdc++.h>

using namespace std;

int * primeUptoNNiave(int n ){
    int * primes = new int[n/2];
        int k = 0;
    for(int i = 2 ; i <= n ; i++){
        bool   flag = true;
        for(int j = 2 ; j < i ; j++ ){
            if(i%j == 0){
                flag = false;
            }
        }
        if(flag){
                primes[k] = i;
                k++;
            }
    }
    return primes;
}

int * primeUptoNBetter(int n ){
    int * primes = new int[n/2];
        int k = 0;
    for(int i = 2 ; i <= n ; i++){
        bool   flag = true;
        for(int j = 2 ; j*j <= i ; j++ ){
            if(i%j == 0){
                flag = false;
            }
        }
        if(flag){
                primes[k] = i;
                k++;
            }
    }
    return primes;
}

int count1;

int * primeUptoNBest(int n){
    int a[n+1] = {0};
    a[0] = 1;
    a[1] = 1;
    for(int i = 2 ; i <= n ; i++){
        if(a[i] == 0){
                bool flag = true;
            for(int j = 2 ; j*j <= i ; j++ ){
                if(i%j == 0){
                    flag = false;
                }
            }
            if(flag){
               a[i] = 1;
                int j = 2;
                while(i*j <= n){
                    a[i*j] = i;
                    j++;
                }    
            }
        }
    }
    count1 = 0;
    for(int i = 2 ; i <= n ; i++){
        if(a[i] == 1){
            count1++;
        }
    }
    int * primes = new int[count1];
    for(int i = 2 , j = 0 ; i < n , j < count1 ; i++){
        if(a[i] == 1){
            primes[j] = i;
            j++;
        }
    }
    return primes;
}

int main(){
    int n = 10;
    int * prime;
    prime = primeUptoNBest(n);
    int i = 1;
    for(int i = 0 ; i < count1 ; i++){
        cout << prime[i] << endl;
    }
    return 0;
}
