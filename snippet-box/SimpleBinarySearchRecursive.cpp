//a[]: ascending sorted array
//s: search item
//l: left bound
//r: right bound
//both bounds included
//returns 0 if found, else -1

//Tip: Can use lower/upper_bound instead

int binary(int a[],int s,int l,int r) {
    int m=(l+r)/2;
    if(r>=l) {
        if(a[m]==s)
            return 0;
        if(s>a[m])
            binary(a,s,m+1,r);
        else if(s<a[m])
            binary(a,s,l,m-1);
    }
    else
        return -1;
}