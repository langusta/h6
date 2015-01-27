#include<Rcpp.h>
#include<algorithm>
using namespace Rcpp ;

//' @title mode
//' @description
//'   This function returns the most frequently occuring value in an integer vector (mode).
//'   If there are more than one values satusfying this definition, it returns one of them
//'   (but there is no rule which one).
//'
//' @param x - an integer vector
//' @return - the most frequently occuring value
//'
//' @export
//[[Rcpp::export]]
int mode (const IntegerVector x) {

  if (x.size() == 0) return NA_INTEGER;

  IntegerVector y = clone(x);
  std::sort(y.begin(), y.end());

  int mode = NA_INTEGER;
  int mode_licznik = 0;
  int ost = y[0];
  int licznik = 0;


  for (int k=0; k<y.size(); ++k){
    if(y[k] == ost){
      ++licznik;
    }else{
      if(licznik > mode_licznik) {
        mode = ost;
        mode_licznik = licznik;
      }
      ost = y[k];
      licznik = 1;
    }
  }

  if(licznik > mode_licznik) {
    mode = ost;
  }

  return mode;
}
