class Solution {
public:
    long long MOD = 1e9+7 ; 
    long long power(long long x , long long p){
        if (p == 0)
            return 1 ; 
        if (p == 1)
            return x ; 
        if (p%2 == 1)
            return (x%MOD*power(x,p-1)%MOD)%MOD;  
        long long res = power(x,p/2) ; 
        return (res%MOD*res%MOD)%MOD ; 
    }
    int countGoodNumbers(long long n){
        long long even = n-n/2 ; 
        long long odd = n/2 ;
        long long x = 1 , y = 1 ; 
        if (even != 0)
            x = power(5LL,even) ; 
        if (odd != 0)
            y = power(4LL,odd) ; 
        long long ans = (x%MOD*y%MOD)%MOD ; 
        return (int)(ans) ; 
    }
};