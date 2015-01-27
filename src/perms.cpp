#include<Rcpp.h>
#include<algorithm>
using namespace Rcpp;

//' @title perms
//' @description
//'   This function returns matrix with all permutations of sequence 1,2,...,n
//'   where n is given as input.
//'
//' @param n - number of elements to permute
//' @return - matrix with all permutations of 1,2,...,n sequence
//'
//' @export
//[[Rcpp::export]]
NumericMatrix perms(const int n) {
   if (n<0) stop("PERMS: n<0!");
   if (n==0) return NumericMatrix(0,0);

   int n_f = 1;
   for (int k=2; k<n+1;++k) n_f*=k;

   NumericMatrix out(n_f,n);
   if(n==1) {out[0]=1;return out;}

   NumericMatrix smaller = perms(n-1);

   for(int k=0;k<n;++k){ // for each position
      for(int r=0; r<smaller.nrow(); ++r){ // for each row
         // add "n" on k-th position
         for(int c=0; c < k ; ++c) out(k*smaller.nrow()+r,c) = smaller(r,c);
         out(k*smaller.nrow()+r,k) = n;
         for(int c=k+1; c < n ; ++c) out(k*smaller.nrow()+r,c) = smaller(r,c-1);
      }
   }
   return out;
}

