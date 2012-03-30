\name{waffect}
\alias{waffect}
\docType{package}
\title{
Simulation of phenotypes in the binary (case/control) and multiclass cases.
}
\description{
This is the main function of the \pkg{waffect} package. Given a vector (matrix) of probabilities and the desired total number of cases and controls (resp.: individuals in each class) \code{waffect} outputs a simulated phenotypic dataset. 
}
\usage{
waffect(prob, count, label, method, burnin)	
}
\arguments{
  \item{prob}{a vector of probabilities corresponding to the disease model H1: the i-th entry is the probability that the i-th individual is a  case. Alternatively, a matrix with k rows and n columns where K = number of classes and n = total number of individuals. In this case, the entry in the k-th row and j-th column is the probability that the phenotype of the j-th individual is in the k-th class. If \code{prob} is missing and \code{count} is a vector of length 2, then the constant vector of probabilities \code{rep(0.1, sum(count))} is assumed, thus resulting in simulating phenotypes under the null  hypothesis H0. If \code{prob} is missing and \code{count}  is a vector with length greater or equal than 3, then for each individual the probability to be in the first class is 0.1 and the probability to be in each of the other classes is 0.9/(K-1).} 
  \item{count}{either an integer (the total number of cases), or a vector of length two (number of cases and number of controls), or, in the multiclass case, a vector of length greater or equal than 3 (number of individuals in each class).}
  \item{label}{a list with either the labels for cases and controls or, in the multiclass case, the codes for each class. In the binary case  the first entry must be the label for cases. By default \code{label = c(1,0)} in the binary case and \code{label = 1:K}, where \code{K} is the total number of classes.}
  \item{method}{the method to be implemented for the simulation. Three methods are available: \code{"backward"}, \code{"mcmc"}, 
  \code{"reject"}. The default method is \code{"backward"}; \code{"reject"} is deprecated.}
  \item{burnin}{the burn-in step if method is \code{"reject"}; by default \code{burnin = 1e+05 * n}, where \code{n} is the total number of individuals.}
}
\value{
  \item{  }{A list of phenotypes coded by the entries in \code{label}.}
}
\examples{
\dontrun{Typical usage to simulate case/control phenotypes under H1 (in this example: 12 individuals, 7 cases, 5 controls, the probability that individual 1 is a case is 0.2...):}
waffect(prob =  c(0.2, 0.4, 0.9, 0.6, 0.9, 0.1, 0.4, 0.6, 0.6, 0.3, 0.8, 0.1), count=c(7,5), label=c(1,0))

\dontrun{By rerunning the command we obtain another simulation:}
waffect(prob =  c(0.2, 0.4, 0.9, 0.6, 0.9, 0.1, 0.4, 0.6, 0.6, 0.3, 0.8, 0.1), count=c(7,5), label=c(1,0))

\dontrun{We can just specify the number of cases:}
waffect(prob =  c(0.2, 0.4, 0.9, 0.6, 0.9, 0.1, 0.4, 0.6, 0.6, 0.3, 0.8, 0.1), count=7, label=c(1,0))

\dontrun{It is possible to change the default code for cases and controls:}
pi <- runif(100)
waffect(prob = pi, c(50,50), label = c("case","control"))

\dontrun{If prob is not specified then a constant vector of probabilities is assumed by default. This is equivalent to simulate phenotypes under the null hypothesis H0:}
waffect(count = c(20,30), label=c(1,0))  

\dontrun{Example with 6 individuals and 3 classes:}
pi1 = c(0.3,0.4,0.3)
pi2 = c(0.3,0.5,0.2)
pi3 = c(0.1,0.2,0.7)
pi4 = c(0.1,0.6,0.3)
pi5 = c(0.1,0.7,0.2)
pi6 = c(0.4,0.1,0.5)
pi = cbind(pi1,pi2,pi3,pi4,pi5,pi6)
waffect(prob = pi, count = c(1,2,3))

}

\seealso{
	Package documentation: \code{\link{waffect-package}}. Useful information can be also found in the vignette: \code{vignette("waffect-tutorial")}. 
}