int subarray(int *A,int start,int end)
{
    int i,sum=0;
    for(i=start;i<=end;i++)
        sum+=A[i];
    return sum;
}
int numOfStudents(int *A,int n1,int maxlen)
{
    int total=0,studs=1,i;
    for(i=0;i<n1;i++)
    {
        total+=A[i];
        if(total>maxlen)
        {
            studs++;
            total=A[i];
        }
    }
    return studs;
}
int minimise(int *A,int n1,int B,int start,int end)
{
   while(start<end)
   {
       int mid=start+(end-start)/2;
       int required=numOfStudents(A,n1,mid);
       if(required<=B)
            end=mid;
        else
            start=mid+1;
   }
   return start;
}
int books(int* A, int n1, int B) {
    if(B>n1)
        return -1;
    int max=subarray(A,0,n1-1);
    int min=A[0],i;
    for(i=1;i<n1;i++)
        if(min<A[i])
            min=A[i];
    return minimise(A,n1,B,min,max);
}
