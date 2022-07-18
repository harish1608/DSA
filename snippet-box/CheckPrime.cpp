//check prime in O(sqrt(N))
//returns 1 if prime else 0

int checkprime(int n) {
	if(n==1)
		return 0;
	for(int i=2;i*i<=n;i++)
		if(n%i==0)
			return 0;
	return 1;
}

//slightly better method
//sqrt(n)/6 operations

int checkprime(int n) {
    if(n<=3) {
        if(n==1)
            return 0;
        return 1;
    }
    else if(n%3==0||n%2==0)
        return 0;
    else {
        for(int i=5;i*i<=n;i+=6)
            if(n%i==0||n%(i+2)==0)
                return 0;
        return 1;
    }
}