//a[]: input array
//l: left bound
//r: right bound
//both bounds included
//sorts in ascending order
//change sign on line 15 to reverse order (default: <)

//part the array w.r.t a[l]
int partition(int a[],int l,int r)
{
    int i,j,t;
    i=l+1;
    for(j=l+1;j<=r;j++)
    {
        if(a[j]<a[l])
        {
            if(j>i)
            {
                t=a[j];
                a[j]=a[i];
                a[i]=t;
            }
            i++;
        }
    }
    i--;
    t=a[i];
    a[i]=a[l];
    a[l]=t;
    return i;
}

void quicksort(int a[],int l,int r)
{
    if(l<r)
    {
        int p=partition(a,l,r);
        quicksort(a,l,p-1);
        quicksort(a,p+1,r);
    }
}