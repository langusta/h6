test_that(
   "Tests for: mode",
   {
      expect_equal(mode(numeric(0)),NA_integer_)
      expect_equal(mode(c(1)),1)
      expect_equal(mode(c(1,2,3,3)),3)
      expect_equal(mode(c(1,2,2,3,3,2)),2)
   })
