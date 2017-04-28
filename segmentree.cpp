
# segment trees
#include <bits/stdc++.h>
using namespace std;
vector<long long > st(100009,0);
void updateValue( int start, int end, int i, long long  diff, int idx)
{
    // Base Case: If the input index lies outside the range of 
    // this segment
    if (i < start || i > end)
        return;
 
    // If the input index is in range of this node, then update 
    // the value of the node and its children
    st[idx] +=  diff;
    if (se != ss)
    {
        int mid = getMid(ss, se);
        updateValue( start, mid, i, diff, 2*idx + 1);
        updateValue( mid+1, end, i, diff, 2*idx + 2);
    }
}
 
// The function to update a value in input array and segment tree.
// It uses updateValue() to update the value in segment tree
void update(vector<long long >&int arr,  int i, int new_val)
{
   
 
    // Get the difference between new value and old value
    long long diff = new_val - arr[i];
 
    // Update the value in array
    arr[i] = new_val;
 
    // Update the values of nodes in segment tree
    updateValue( 0, n-1, i, diff, 0);


# this function builds segment tree recursively.
void  buildtree(vector<long long >& arr, int start,int end,int idx)
{
         if(start==end)         
         {
             st[idx]=arr[start];
             return ;
         }
         
         int mid= start +(end-start)/2;
         buildtree(arr,start,mid,2*idx+1);
         buildtree(arr,mid+1,end,2*idx+2);
         st[idx]=st[(2*idx)+1]+st[(2*idx)+2];

}
long long  sumQ(vector<long long > & arr,int Qs,int Qe,int start,int end,int idx)
{

            if(Qs<=start&& Qe>=end)
           return st[idx];
            if(Qe<start ||Qs>end)
            return 0;
            int mid= start +(end-start)/2;
            return sum(arr,Qs,Qe,start,mid,2*idx+1)+ sum(arr,Qs,Qe,start,mid,2*idx+2);
           
                         
}

