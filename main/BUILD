load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = ["//tests:tlib"],
    # with copts this package has access to "tests" dir. So you don't have to put 'tests/' in the include path; just do #include "testComposite.hpp"
    copts = ["-Itests"],
)