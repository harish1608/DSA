//All below functions work in O(logN)

// [l,r]
// returns index of target element if it exists, else -1
// stl binary_search returns true/false
int binary_search(int ar[], int l, int r, int val) {
    int mid;
    while(l<=r) {
        mid=l+(r-l)/2;
        if(val==ar[mid])
            return mid;
        else if(val>ar[mid])
            l=mid+1;
        else
            r=mid-1;
    }
    return -1;
}

// [l,r]
// returns the first index of val if it EXISTS, else -1
// At the end of loop, l is such that, ar[l]>=val
int lowerBound(int ar[], int l, int r, int val) {
    int mid;
    while(l<r) {
        mid=l+(r-l)/2;
        if(val<=ar[mid])
            r=mid;
        else
            l=mid+1;
    }
    if(ar[l]==val)
        return l;
    return -1;
}

// [l,r]
// returns the last index of val if it EXISTS else -1 
// At the end of loop, r is such that ar[r] <=val
int upperBound(int ar[], int l, int r, int val) {
    int mid;
    while(l<r) {
        mid=l+(r-l+1)/2;
        if(val>=ar[mid])
            l=mid;
        else
            r=mid-1;
    }
    if(ar[r]==val)
        return r;
    return -1;
}

// [l,r]
// Exactly mimics stl lower_bound
// returns index of first element >= val
// At the end of loop, l is such that, ar[l]>=val
int lowerBound(int ar[], int l, int r, int val) {
    if(val>ar[r])
        return r+1;

    int mid;
    while(l<r) {
        mid=l+(r-l)/2;
        if(val<=ar[mid])
            r=mid;
        else
            l=mid+1;
    }
    return l;
}

// [l,r]
// Exactly mimics stl upper_bound
// returns index of first elements > val
// At the end of loop, r is such that ar[r]<=val
int upperBound(int ar[], int l, int r, int val) {
    if(val<ar[l])
        return l;

    int mid;
    while(l<r) {
        mid=l+(r-l+1)/2;
        if(val>=ar[mid])
            l=mid;
        else
            r=mid-1;
    }
    return r+1;
}

/* 
Key Points in bounds functions:
1. When the loop terminates? //Above function terminates at l==r;
2. How the mid is calculated, i.e. floor or ceil? //Above is ceil
3. How the boundary changes? // In above function ar[mid] is always included in the range.
4. Pre/Post-processing if any. //ex: r+1 in above
*/