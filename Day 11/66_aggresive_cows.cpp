/*
Link: https://www.spoj.com/problems/AGGRCOW/
Method: Binary Search
Time Complexity: O(logn)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std ;

int T, n, c, maxm, ans, mid, cows, temp ;
vector<int> x ;

// check if it is possible to set all the cows as min diff of 'mid'
bool check(int k)
  {
    cows=1 ;
    temp=x[0] ;
    for(int i=1 ; i<n ; i++)
      {
        if(x[i]-temp>=k)
          {
            cows++ ;
            temp=x[i] ;
          }
      }
    if(cows>=c) return true ;
    return false ;
  }

void bs(int l, int u)
  {
    ans=-1 ;
    while(l<=u)
      {
        mid=(l+u)/2 ;
        if(check(mid))
          {
            if(mid>ans) 
              ans=mid ;
            l=mid+1 ;           // keep trying for larger difference
          }
        else
            u=mid-1 ;
      }
  }

int main()
  {
    cin>> T ;
    while(T--)
      {
        cin>> n >> c ;
        x.clear() ;
        x.resize(n) ;
        for(int i=0 ; i<n ; i++)
          cin>> x[i] ;
        sort(x.begin(), x.end()) ;
        bs(0, x[n-1]) ;     // binary search
        cout<< ans << endl ;
      }
  }