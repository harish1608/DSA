//Sieve of eratosthenes
//O(n*log(log(sqrt-n))) for this
//make array global if n>1e7 or use segmented sieve
//is_prime[x] is true if x is prime
//To be included in main function

//The number of prime numbers <= n
//is approximately n/ln(n)

//significant time difference between vector<bool> and vector<char>
//"there exist data structures that automatically do a bit-level compression, such as vector<bool> and bitset<> in C++." - maybe they take 8 times less memory but they take almost 2.5x more time
//"However, such an approach, which is called bit-level compression, will complicate the operations with these bits. Read or write operation on any bit will require several arithmetic operations and ultimately slow down the algorithm."


int n=1e6;
vector<char> is_prime(n+1,true);
is_prime[0]=is_prime[1]=false;
for(int i=2;i*i<=n;i++)
    if(is_prime[i])
        for(int j=i*i;j<=n;j+=i)
            is_prime[j]=false;
for(int i=2;i<n;i++)
    if(is_prime[i])
        primes.push_back(i);