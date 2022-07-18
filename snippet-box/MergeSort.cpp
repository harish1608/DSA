//a[]: input array
//l: left bound
//r: right bound
//both bounds included
//sorts in ascending order
//change sign on line 20 to change order (default: <)

void sort(int a[],int l,int r) {
    int j,k,i,m=(l+r)/2;
    if(l<r) {
        sort(a,l,m);
        sort(a,m+1,r);

        int ar[r-l+1];
        j=l;
        k=m+1;
        for(i=0;i<=(r-l);i++) {

            if(j<=m&&k<=r) {
                if(a[j]<a[k])
                    ar[i]=a[j++];
                else
                    ar[i]=a[k++];    
            }
            else {
                if(j>m)
                    ar[i]=a[k++];
                else
                    ar[i]=a[j++];            
            }
        }
        j=l;
        for(i=0;i<=(r-l);i++)
            a[j++]=ar[i];
    }
}