test_that(
   "Tests for: perms",
   {
      expect_error(perms("a"))
      expect_equal(perms(1), matrix(1))
      expect_equal(perms(2), matrix(c(2,1,1,2), ncol = 2))
      expect_equal(perms(3), matrix(c(3,3,2,1,2,1,2,1,3,3,1,2,1,2,1,2,3,3), ncol = 3))
   }
)
