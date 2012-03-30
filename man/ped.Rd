\name{ped}
\docType{data}
\alias{ped}
\title{Genotypic dataset in PED format}
\description{
  This dataset contains the genotypes of 2000 SNPs to be used with the tutorial for
  assessing the statistical power of GWAs with waffect (see the vignette). It has 100 rows (one
  for each individual) and 2007 columns:
  \itemize{
    \item fam_id: family ID, here an integer from 1 to 100
    \item ind_id: individual ID, an integer from 1 to 100
    \item pat_id: paternal ID, here a dummy variable set to 0 for all individuals
    \item mat_id: maternal ID, dummy variable
    \item sex: all females (coded by 2)
    \item pheno: observed phenotypes; codes: case = 2, control = 1. 
  }
  Genotypes (column 7 onwards) are biallelic, one allele for each column. For instance, 
  columns 7 and 8 contain the two alleles for SNP1 and columns 9 and 10 contain the alleles
  for SNP2. Before using this dataset with PLINK it is necessary to save it into a file with 
  extension .ped (see the vignette). The genotypes were obtained from public data released by 
  the \emph{1000 Genomes Projects}. 
}
\usage{data(ped)}
\format{A table with 100 rows and 2007 columns.}
\source{1000 Genomes, A Deep Catalogue of Human Genetic Variation; http://www.1000genomes.org}
\keyword{datasets}