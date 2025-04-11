include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.16.x
  GIT_SHALLOW    1 # avoid cloning unneeded branches
)

FetchContent_MakeAvailable(googletest)
