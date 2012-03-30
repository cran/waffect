\name{waffect-package}
\alias{waffect-package}
\docType{package}
\title{
	A package to simulate constrained phenotypes under a disease model H1  
}
\description{
	\pkg{waffect} (pronounced 'double-u affect' for 'weighted affectation') is a package to simulate phenotypic 
	(case or control) datasets under a disease model H1 such that the total number of cases is constant 
	across all the simulations (the constrain in the title). The package also makes it possible to generate 
	phenotypes in the case of more than two classes, so that the number of phenotypes belonging to each 
	class is constant across all the simulations. \pkg{waffect} is used to assess empirically the statistical 
	power of Genome Wide Association studies without generating genotypes for each simulation. The 
	vignette includes a tutorial for performing such power studies.  
}
\details{
	\pkg{waffect} implements three alternative methods to simulate phenotypes with a fixed number of 
	cases and controls and under a given disease model: i) an exact and efficient backward sampling algorithm; ii)  a 
	numerical Markov Chain Monte-Carlo (MCMC) approach; iii) a simple rejection algorithm. The backward 
	algorithm is the default method. The rejection algorithm is deprecated. More details can be found in the 
	companion article [1].
}


\section{Installing and Using}{
	 To install this package, make sure you are connected to the Internet and issue the following command 
	 in the R prompt: \code{install.packages("waffect")} 
          
          To load the package in R: \code{library(waffect)} 
	
	To open the .pdf file of the vignette: \code{vignette("waffect-tutorial")}
}

\section{Citation}{
	If you use \pkg{waffect} in published research, please cite the companion article: 
	
	Perduca V, Sinoquet C, Mourad R, Nuel G: Alternative Methods for H1 Simulations in Genome-Wide Association Studies. Hum Hered 2012;73:95-104. 
	
	Type \code{citation("waffect")} for a BibTeX entry. 

	The authors would be glad to hear how \pkg{waffect} is employed. You are kindly encouraged to notify
	 Gregory Nuel \email{gregory.nuel@parisdescartes.fr} and Vittorio Perduca 
	 \email{vittorio.perduca@parisdescartes.fr} about any work you publish that makes use of \pkg{waffect}.
}

\section{Functions}{
	\describe{
         \item{\code{\link{waffect}}}{ high level function for simulating phenotypes in the binary (case/control) and mulitclass cases} 
         \item{\code{\link{waffectbin}}}{low level function for simulating phenotypes in the binary case (not documented)} 
        }
}

\section{Datasets}{
	This package comes with two datasets to be used for the fictive GWAs power analysis outlined in the 
	vignette:
	\describe{
	\item{\code{\link{ped}}}{ genotypic dataset in \code{.ped} format}
	\item{\code{\link{map}}}{ file in \code{.map} format describing the SNPs in the \code{ped} file}
	}
	The signals of association to be used in the fictive GWAs power analysis are also included:
	\describe{
	\item{\code{\link{p1_H0}}}{ Signal of association of the statistic S1 under H0}
	\item{\code{\link{p1_H1}}}{ Signal of association of the statistic S1 under H1}
	\item{\code{\link{p2_H0}}}{ Signal of association of the statistic S2 under H0}
	\item{\code{\link{p2_H1}}}{ Signal of association of the statistic S2 under H1}
	}
}

\keyword{ package }

\examples{
\dontrun{Typical usage to simulate case/control phenotypes under H1 (in this example: 5 individuals, 2 cases, 3 controls, the probability that individual 1 is a case is 0.5...):}
waffect(prob =  c(0.5, 0.2, 0.9, 0.7, 0.1), count = c(2,3), label = c(1,0))

\dontrun{We can just specify the number of cases:}
waffect(prob =  c(0.5, 0.2, 0.9, 0.7, 0.1), count = 2, label = c(1,0))

\dontrun{We can change the labels:}
waffect(prob =  c(0.5, 0.2, 0.9, 0.7, 0.1), count = 2, label = c("case", "control"))

\dontrun{We can also simulate under H0 just entering the number of cases and controls:}
waffect(count=c(2,3), label = c(1,0))

\dontrun{Simulation of phenotypes in the multiclass case (in this example: 4 individuals and  3 classes, 1 individual in class 1, 2 individuals in class 2, 1 individual in class 3):}
pi = cbind(c(0.5,0.3,0.2), c(0.2,0.2,0.6), c(0.1,0.7,0.2), c(0.4,0.3,0.3))
waffect(prob =  pi, count = c(1,2,1), label = 1:3)
}

\seealso{
	Documentation for the function \code{\link{waffect}}. Useful information can be also found in the vignette: \code{vignette("waffect-tutorial")}.
}

\references{
	[1] Perduca V, Sinoquet C, Mourad R, Nuel G: Alternative Methods for H1 Simulations in Genome-Wide Association Studies. Hum Hered 2012;73:95-104
}