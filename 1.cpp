#include <stdio.h>
//#define gcd2

#ifndef gcd2
long Gcd(long m, long n){
    if(m%2 == 0 && n%2 == 0) return 2*Gcd(m/2, n/2);
    else if(m%3 == 0 && n%3 == 0) return 3*Gcd(m/3, n/3);//一些简单优化
    long r = m % n;
    if(r == 0) return n;
    else return Gcd(n, r);
}
#endif
#ifdef gcd2
long Gcd(long m, long n){
    if(m%2 == 0 && n%2 == 0) return 2*Gcd(m/2, n/2);
    else if(m%3 == 0 && n%3 == 0) return 3*Gcd(m/3, n/3);
    else
    {
        int min = (m<n?m:n);
        for(long i = min; i >= 5; i--){
            if(m%i == 0 && n%i == 0) return i;
        }
    }
    
}
#endif
long Lcm(long m, long n, long gcd){
    return m*(n / gcd);
}

int main(){
    long m,n,gcd,lcm;
    scanf("%ld%ld",&m, &n);
    gcd = Gcd(m, n);
    lcm = Lcm(m, n, gcd);
    printf("Gcd = %ld\tLcm = %ld\n",gcd, lcm);
    return 0;
}

