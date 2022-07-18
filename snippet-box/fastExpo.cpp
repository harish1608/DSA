//(a^n)%p in O(logN)

ll fastExpo(ll a, ll n, ll p) {
	ll res=1;
	a=a%p;
	while(n>0) {
		if(n&1) res=(res*a)%p;
		n=n>>1;
		a=(a*a)%p;
	}
	return res;
}