//Traditional method
//O(min(r,n-r) logp) retrieval with no precomputation
//n!/(r!*(n-r)!)
//First calculate n!/(n-r)! % p in O(r)
//Then multiply by (r!)^-1 % p in O(rlogp)
//generally used for large n(>2e5) and small r(<2e6)

typedef long long ll;

ll nCr(ll n, ll r, ll p) {
    if(r>n-r) r=n-r;
    ll t=1,f=1;
    for(ll i=n-r+1;i<=n;i++)
        t=(t*(i%p))%p;
    for(ll i=1;i<=r;i++)
        f=f*i%p;
    t=t*(fastExpo(f,p-2,p))%p;
    return t;
}