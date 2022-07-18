//returns gcd of two integers a and b

//can use __gcd(a,b) in <algorithm> c++14
//can use gcd(a,b) or lcm(a,b) in <numeric> c++17

int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int gcd(int a, int b) {
    int t;
    while(b!=0) {
        t=a%b;
        a=b;
        b=t;
    }
    return a;
}