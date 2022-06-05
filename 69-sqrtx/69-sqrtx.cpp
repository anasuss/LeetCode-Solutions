class Solution {
public:
    int mySqrt(int x) {
      double start = 0 ;
    double e = x ;
    double EPS = 1e-11 ;
    while(fabs(start-e)>EPS){
        double mid = start + (e-start)/2.00 ;

        if (mid*mid<=x)
            start = mid ;
        else
            e = mid ;
    }
    start+=EPS ;
    return (int)start ;
    }
};