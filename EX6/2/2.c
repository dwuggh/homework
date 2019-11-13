#include <stdio.h>
#define GCD2
#define GLOBAL


#ifdef GLOBAL
long m, n;
long Gcd(){
    

    int min = (m<n?m:n);
    for(long i = min; i >= 5; i--){    
        if(m%i == 0 && n%i == 0) return i;
    }

    
}
long Lcm(long gcd){
    return m*(n / gcd);
}
#endif


#ifndef GLOBAL
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

long Lcm(long m, long n, long gcd){
    return m*(n / gcd);
}
#endif
int main(){
#ifndef GLOBAL
    long m, n;
#endif
    scanf("%ld%ld", &m, &n);
    
#ifdef GLOBAL
    long gcd = Gcd();
    long lcm = Lcm(gcd);
#endif
#ifndef GLOBAL
    long gcd = Gcd(m ,n);
    long lcm = Lcm(m, n, gcd);
#endif
    printf("gcd: %ld\tlcm: %ld\n",gcd, lcm);
    return 0;
}