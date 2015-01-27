test_that(
   "Tests for: simplify2array2",
   {
      expect_equal(simplify2array(c(1,3,5)),simplify2array2(c(1,3,5)))
      expect_equal(simplify2array(list(1:3)),simplify2array2(list(1:3)))
      expect_equal(simplify2array(list(1:3,3:5)),simplify2array2(list(1:3,3:5)))
      expect_equal(simplify2array(list(1:3,3)),simplify2array2(list(1:3,3)))
      expect_equal(simplify2array(list(1:3,"a")),simplify2array2(list(1:3,"a")))
      expect_equal(simplify2array2(c()),numeric(0))
      expect_equal(simplify2array2(list()),numeric(0))
   })
