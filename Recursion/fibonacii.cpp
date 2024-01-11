#include <iostream>
#include <map>
using namespace std;

map<int,long long> cache;

long long fib(int num){
    if (num == 0) return 0;
    else if (num == 1) return 1;

    if (cache.find(num) == cache.end()){
        long long fibo1 = fib(num-1);
        long long fibo2 = fib(num - 2);

        cache[num-1] = fibo1;
        cache[num-2] = fibo2;

        return fibo1 + fibo2;
    }
    return cache[num];
}

int main(){
    cout << fib(43) << endl;
    return 0;
}