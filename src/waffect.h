#ifndef _waffect_WAFFECT_H
#define _waffect_WAFFECT_H

#include <Rcpp.h>
//#include <RcppClassic.h>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <time.h>
#include "xdouble.h"


/* return true with probability prob, false else */
bool draw(xdouble prob);
bool draw(double prob);

/* compute backward quantities ... */
size_t backward(size_t r,size_t h,size_t j,Rcpp::NumericVector &pi,std::vector<std::vector<xdouble> > &B);

void print(std::vector<std::vector<xdouble> > &B);

//SEXP waffectbin(std::vector<xdouble> &pi,size_t r,size_t h=0,bool verbose=false);
RcppExport SEXP waffectbin(SEXP rpi, SEXP rr, SEXP rh);
RcppExport SEXP waffectbin_mcmc(SEXP rpi, SEXP rr, SEXP rburnin);
RcppExport SEXP waffectbin_reject(SEXP rpi, SEXP rr);

/*
 * note : RcppExport is an alias to `extern "C"` defined by Rcpp.
 *
 * It gives C calling convention to the rcpp_hello_world function so that 
 * it can be called from .Call in R. Otherwise, the C++ compiler mangles the 
 * name of the function and .Call can't find it.
 *file://localhost/Users/vittorioperduca/Documents/R/waffect/R/waffectbin.R
 * It is only useful to use RcppExport when the function is intended to be called
 * by .Call. See the thread http://thread.gmane.org/gmane.comp.lang.r.rcpp/649/focus=672
 * on Rcpp-devel for a misuse of RcppExport
 */

#endif 
