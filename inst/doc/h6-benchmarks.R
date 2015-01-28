## ----, include=FALSE-----------------------------------------------------
library(h6)
library(microbenchmark)

## ------------------------------------------------------------------------
mode2 <- function(x) {
  ux <- unique(x)
  ux[which.max(tabulate(match(x, ux)))]
}

## ----, cache=TRUE--------------------------------------------------------
microbenchmark(mode(c(1:10000,5)), mode2(c(1:10000,5)))
microbenchmark(mode(c(1:100000,5)), mode2(c(1:100000,5)))
microbenchmark(mode(c(1:1000000,5)), mode2(c(1:1000000,5)))

## ----, cache=TRUE--------------------------------------------------------
microbenchmark(simplify2array2(list(1:100000,1:100000)), simplify2array(list(1:100000,1:100000)))
microbenchmark(simplify2array2(list(1:1000000,1:1000000)), simplify2array(list(1:1000000,1:1000000)))

## ----, cache=TRUE--------------------------------------------------------
microbenchmark(simplify2array2(list(rep("a",1000000),1:1000000)), simplify2array(list(rep("a",1000000),1:1000000)))

## ----, cache=TRUE--------------------------------------------------------
library(gtools)
microbenchmark(perms(5), permutations(5,5,1:5))
microbenchmark(perms(6), permutations(6,6,1:6))
microbenchmark(perms(7), permutations(7,7,1:7))

