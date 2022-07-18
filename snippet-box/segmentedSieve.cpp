#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

//To generate primes <=n n~5e7
//Advantage: Uses less memory compared to regular sieve and "cache friendly"
//Mem: O(sqrt_n + S) vs O(n)
//S is the size of block- recommended somewhere between 1e4~1e5
//running time is similar- O(Nlog(logN))
void segmentedSieve(int n) {
    int s=sqrt(n); //include <cmath>

    vector<int> primes;
    int nsqrt=sqrt(n);
    vector<char> is_prime(nsqrt+1,true);
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=nsqrt;i++) {
        if(is_prime[i]) {
            primes.push_back(i);
            for(int j=i*i;j<=nsqrt;j+=i)
                is_prime[j]=false;
        }
    }

    //accumulates all primes in [1...n]
    //return it or reference it in input
    vector<int>allprimes;

    vector<char> block(s);
    for(int k=0;k*s<=n;k++) {
        fill(block.begin(),block.end(),true);
        int start=k*s; //gives the actual number at first of block
        for(int p: primes) {
            int start_idx=(start+p-1)/p; //when multiplied with p gives the first multiple of p in block
            int j=max(start_idx,p)*p-start; //corresponds to the index in block for that number 
            while(j<s) {
                block[j]=false;
                j+=p;
            }
        }
        if(k==0)
            block[0]=block[1]=false;
        int i=0;
        while(i<s && start+i<=n) {
            if(block[i])
                allprimes.push_back(start+i);
            i++;
        }
    }
    //process allprimes;
    //put count++ in place of push_back to just count number of primes in [l,r]
}