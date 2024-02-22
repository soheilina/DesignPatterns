load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "tlib",
    hdrs = glob(["*.hpp"]),
    deps = ["//lib:design-patterns"], #TODO: test with __pkg__
    #TODO: has no effect in including lib files; it still needs 'lib/' i.e. #include "lib/Composite.hpp". WHY?!?!?!
    copts = ["-Ilib"],
    # includes = ["lib"],
    visibility = ["//main:__pkg__"],
)
