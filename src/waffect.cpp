
#include "waffect.h"


using std::vector;
using std::cout;
using std::endl;

using namespace Rcpp;


bool draw(xdouble prob) {
  if ((xdouble)rand()/(xdouble)RAND_MAX<prob)
    return true;
  else
    return false;
};

bool draw(double prob) {
  if ((double)rand()/(double)RAND_MAX<prob)
    return true;
  else
    return false;
};

//size_t backward(size_t r,size_t h,size_t j,Rcpp::RcppVector<xdouble> &pi,std::vector<std::vector<xdouble> > &B) {
size_t backward(size_t r,size_t h,size_t j,NumericVector &pi,vector<vector<xdouble> > &B) {
  size_t q=pi.size();
  size_t currentpos,previouspos;
  currentpos=h-1;

  // initialize B
  for (size_t i=0; i<h; i++)
    for (size_t m=0; m<=r+1; m++) {
      B[i][m]=0.0;
    }
  B[h-1][r]=1.0;

  for (size_t i=q-2; i!=j-1; i--) {
    //cout<<"i="<<i<<endl;
    // update circular positions
    previouspos=currentpos;
    currentpos--;
    if (currentpos==-1)
      currentpos+=h;
    //cout<<"previouspos="<<previouspos<<" currentpos="<<currentpos<<endl;
    // update B
    for (size_t m=0; m<=r; m++)
		B[currentpos][m]=pi[i+1]*B[previouspos][m+1]+(1.0-pi[i+1])*B[previouspos][m];    
  }
  return currentpos;
};

void print(vector<vector<xdouble> > &B) {
  //for (size_t i=0; i<B.size(); i++) {
    //cout<<"B["<<i<<"]: ";
    //for (size_t m=0; m<B[i].size(); m++)
      //cout<<B[i][m]<<" ";
    //cout<<endl;
  //}
};

SEXP waffectbin(SEXP rpi, SEXP rr, SEXP rh) {
	
  NumericVector pi(rpi);
  size_t r=*INTEGER(rr);
  size_t h=*INTEGER(rh);
  size_t q=pi.size();
  LogicalVector res(q);

  // min size for h is 2, if lower, q by default
  if (h<1) {
    h=q;
  };

  // allocate B size h x (r+2)
  vector<vector<xdouble> > B;
  { 
    vector<xdouble> tmp(r+2);
    for (size_t i=0; i<h; i++)
      B.push_back(tmp);
  }

  // compute B0 ... Bh
  size_t currentpos=backward(r,h,0,pi,B);
  size_t largest=h-1;

  size_t N=0;
  size_t i=0;


  //sample res[0]
  {
    xdouble prob0,prob1;
    prob0=(1.0-pi[0])*B[currentpos][0];
    prob1=pi[0]*B[currentpos][1];
    
    res[0]=draw(prob1/(prob0+prob1));
    
    if (res[0])
      N++;
    i++;
  }

  // main loop
  size_t previouspos;
  while (i<q) {
    // update B if needed
    if (i>largest) {
      currentpos=backward(r,h,i,pi,B);
      largest=i+h-1;
      
      xdouble prob0,prob1;
      prob0=(1.0-pi[i])*B[currentpos][N];
      prob1=pi[i]*B[currentpos][N+1];
    
      res[i]=draw(prob1/(prob0+prob1));
        
      if (res[i])
	N++;
      i++;
      
    }
    if (i<=largest) {
      // update circular position
      previouspos=currentpos;
      currentpos++;
      if (currentpos>h-1)
	currentpos-=h;
      
      res[i]=draw(pi[i]*B[currentpos][N+1]/B[previouspos][N]);
      // update N
      if (res[i])
	N++;
      // update i
      i++;
    }
  }
  
  return res;
};



SEXP waffectbin_mcmc(SEXP rpi, SEXP rr, SEXP rburnin) {
	
  NumericVector pi(rpi);
  size_t r=*INTEGER(rr);
  size_t burnin=*INTEGER(rburnin);
  size_t q=pi.size();
  LogicalVector res(q);

  vector<size_t> cases,controls;

  // start with a valid configuration
  for (int i=0; i<r; i++) {
    res[i]=true;
    cases.push_back(i);
  }
  for (int i=r; i<q; i++) {
    res[i]=false;
    controls.push_back(i);
  }

  for (int iter=0; iter<burnin; iter++) {
    // propose move
    int pos0=floor((double)rand()/(double)RAND_MAX*(double)(q-r));
    int pos1=floor((double)rand()/(double)RAND_MAX*(double)r);
    int i1=cases[pos1];
    int i0=controls[pos0];

    // compute accept ratio
    double alpha=pi[i0]*(1.0-pi[i1])/(pi[i1]*(1.0-pi[i0]));
    
    if (draw(alpha)) {
      // accept move
      cases[pos1]=i0;
      controls[pos0]=i1;
      res[i0]=true;
      res[i1]=false;
    }

  };
  
  return res;
};



SEXP waffectbin_reject(SEXP rpi, SEXP rr) {
	
  NumericVector pi(rpi);
  size_t r=*INTEGER(rr);
  size_t q=pi.size();
  LogicalVector res(q);

  size_t ncases=0;

  while (ncases!=r) {
    ncases=0;
    for (size_t i=0; i<q; i++) {
      res[i]=draw(pi[i]);
      if (res[i])
	ncases++;
    }
  };
  
  return res;
};
