\name{map}
\docType{data}
\alias{map}
\title{SNP description in MAP format}
\description{
  This dataset describes the SNPs to be considered in the tutorial for assessing the statistical power 
  of GWAs with waffect (see the vignette). There are 1000 rows, one for each marker, and 4 columns: 
  \itemize{ 
   \item chr: the chromosome, here all the SNPs are on X
   \item SNP_id: the SNP identifier, here an integer from 1 to 1000
   \item  dist: the genetic distance, here a dummy variable set to 0 for all the SNPs
   \item  bp_pos: the base-pair position, here an integer from 1 to 1000. 
  }   
   Before using this dataset with PLINK it is necessary to save it into a file with extension .map
  (see the vignette).
}
\usage{data(map)}
\format{A table with 1000 rows and 4 columns.}
\keyword{dataset}