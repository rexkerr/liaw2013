Introduction
---------------

Error reporting within a programming language is most commonly used to communicate an unexpected condition or behavior of a program.  An error can either be propagated to a user or handled directly by the program.  Which is more appropriate is dependent on the type of error mechanism and the nature of the function reporting the error.

The first section addresses a variety of problems specifically targeted at _runtime execution_ of a program:

* [C++] The first set of problems address the most commonly-used historical C++ error-reporting mechanism, known as an `exception`.

* [boost] The second set of problems describes a new way to report and handle errors with the introduction of the `boost::optional` library.

* [C++] The final set of problems describes the `assert` function, which is most commonly used for validating a set of preconditions, postconditions, and/or invariants of a function.

The second section goes over a collection of problems related to error reporting at the _compile-time_ of a program.

* [C++11] The `static_assert` feature is to be introduced.
