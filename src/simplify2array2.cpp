#include<Rcpp.h>
using namespace Rcpp ;

//' @title simplify2array2
//' @description
//'   This function transforms input list into an array if it is possible.
//'
//' @param x - list
//' @return If input list consists of only numeric vectors of equal length then
//'   the return value is its array version. Otherwise input list is returned.
//'
//' @export
//[[Rcpp::export]]
RObject simplify2array2(const List x) {
   // check if it is a list of numeric vectors of the same lengths
   int correct = 1;
   int length = 0;
   for(int k=0; k<x.size() ; ++k){
      if(!Rf_isNumeric(x[k])) {correct=0; break;}
      if (k==0) {NumericVector tmp(x[k]); length = tmp.size();}
      NumericVector tmp(x[k]);
      if(length != tmp.size()){correct=0; break;}
   }

   if(correct){
      NumericVector out(x.size()*length);
      for(int k=0; k<x.size(); ++k){
         NumericVector tmp(x[k]);
         for(int r=0; r<length; ++r){
            out[k*length+r] = tmp[r];
         }
      }
      if(length > 1) out.attr("dim") = IntegerVector::create(length, x.size());
      return out;
   } else {
      List out = Rcpp::clone(x);
      return out;
   }
}

