#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

//1<=l<=r
//generate primes from [l...r] where r can be very large 
//r-l+1 approx 1e7, sqrt(r)<1e8
//O((r-l+1)log(log(r)) + sqrt_r*log(log(sqrt_r)))
void segmentedSieve(ll l, ll r) {
    //generate all primes upto sqrt(r)
    vector<ll> primes;
    ll rsqrt=sqrt(r);
    vector<char> is_prime(rsqrt+1,true);
    is_prime[0]=is_prime[1]=false;
    for(ll i=2;i<=rsqrt;i++) {
        if(is_prime[i]) {
            primes.push_back(i);
            for(ll j=i*i;j<=rsqrt;j+=i)
                is_prime[j]=false;
        }
    }
    vector<char> isPrime(r-l+1,true);
    for(ll p: primes)
        for(ll i=max(p, (l+p-1)/p)*p; i<=r; i+=p)
            isPrime[i-l]=false;
    if(l==1)
        isPrime[0]=false;

    //process
    //isPrime[i-l] is true if i is a prime number
    //Careful: Do not use is_prime
    //l<=i<=r
}



//-----------Method2---------------

//O((r-l+1)log(sqrt_r)+sqrt_r)
void segmentedSieve(ll l,ll r) {
    vector<char> isPrime(r-l+1, true);
    for(ll i=2;i*i<=r;i++)
        for(ll j=max(i,(l+i-1)/i)*i;j<=r;j+=i)
            isPrime[j-l]=false;
    if(l==1)
        isPrime[0]=false;
    //process;
    //isPrime[i-l] is true if i is a prime number
    //l<=i<=r
}
// One above this works faster