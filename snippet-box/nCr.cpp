//Calculate nCr % p 
//O(1) retrieval with O(maxN) precomputation
//First, calculate all factorials % p till MAXN- O(MAXN)
//Then, there are two paths:
//Either, calculate all inverse factorial% p in O(MAXN), and return ans in O(1)
//Or, calculate inverse instantly and return answer in O(logP)
//https://cp-algorithms.com/combinatorics/binomial-coefficients.html

typedef long long ll;
const int maxN=2e5;

int fact[maxN+1]; //n! % p
void preFact(int p) {
    fact[0]=1;
    for(int i=1;i<=maxN;i++) {
        ll t=1LL*fact[i-1]*i;
        if(t>=p)    t%=p;
        fact[i]=t;
    }
}

//calulate inverse of every number % p from 1 to maxN
//p is prime, maxN<p
void preinv(int inv[],int p) {
    inv[1]=1;
    for(int i=2;i<=maxN;i++) {
        ll t=1LL * p/i * inv[p%i];
        if(t>=p)    t%=p;
        inv[i]=p-t;
    }
}

int invfact[maxN+1]; //(n!)^-1 % p
void preInvfact(int p) {
    int inv[maxN+1];
    preinv(inv,p);
    invfact[0]=1;
    for(int i=1;i<=maxN;i++) {
        ll t=1LL*invfact[i-1]*inv[i];
        if(t>=p)    t%=p;
        invfact[i]=t;
    }
}

int nCr(int n, int r, int p) {
    if(n<r) return 0;
    ll t=((1LL*fact[n]*invfact[r])%p * invfact[n-r]) % p;
    return t;
}

// Another way - O(logp) retrieval
// Include fastExpo and prefact
int nCr(int n, int r, int p) {
    if(n<r) return 0;
    ll t=(1LL*fact[n]*fastExpo(fact[r],p-2,p))%p;
    t=(t * fastExpo(fact[n-r],p-2,p)) % p;
    return t;
}