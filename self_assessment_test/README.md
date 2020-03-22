# Self-assessment Test

In this exercise sheet you will implement a _binary search tree storing
integers_ and follow some core principles of modular programming. The purpose
of the exercise is to check (for yourself) whether you are sufficiently
fluent in using the C programming language. Most exercises in this course
will build directly on top of what you learned in the previous semester.

If you are struggling with this exercise sheet, please consider doing this
course at a later point in your studies. Otherwise you need to be prepared
for the fact that subsequent exercises will probably require greater effort
from you than originally planned by us.

Also note that task 1 is longer than the typical tasks encountered in this
course. We will try to keep exercises concise and focused on a particular
topic, but you are required to know about the underlying details when
presenting. Therefore task 2 lists a bunch of questions we might typically
ask someone during the presentation of task 1.

## Task 1

Implement a module (`bstree.h`, `bstree.c`) providing a sorted binary tree
for integers. The header file is already provided and holds the signatures of
required functions alongside short descriptions. Your implementation should
fulfill these descriptions as closely as possible.

The `bstree` type is used as a _handle_ to work with the whole tree, and can
also be used as storage for information concerning the entire tree. How you
implement the tree structure itself is up to you. You might for example have
a `bstree_node`, which holds on to an integer and references to the left and
right child nodes.

- Read this task from top to bottom before starting your implementation.
- Ensure you fully understand the concept of a sorted binary tree as well as
  the provided header file.
- Ensure your implementation does not suffer from any memory leaks using
  `valgrind`.
- You should not be required to change any of the provided files. If you find
  an error, note it down and make _reasonable_ assumptions to continue.
- Keep your code clean and simple. It should be as readable as possible.
- Everything (variable names, comments, etc) must be written in English.
- Implement `bstree` and the required functions in `bstree.c`.

  - Your implementation may (and should) utilize additional functions not stated in the header file, but make sure they are not exported (e.g. by using `static`).
  - Only the `bstree_print` function produces output during normal execution, debug messages / logs of any kind.
  - Try to reuse already implemented functions (e.g. `bstree_remove` could make
    use of `bstree_maximum`).

- Ensure proper error handling.

  - Use `assert` to ensure that `NULL` is not passed to function which can not handle this case.
  - Check return values of functions that may fail, like `malloc`.

- Compare the output produced by `bstree_test.c` to
  `bstree_test_output.txt` in order to check your implementation. A matching output does not guarantee a 100% correct implementation!

## Task 2

This task builds on top of the previous one, but no implementation is
required. Its purpose is to ensure you understand the background behind the
details of the previous task. **Please submit your answers as a free-form text
file**.

- When would you use a sorted binary tree over a linked list?
- What would you change if the tree had to support not just integers, but any
  type of data?
- Why do we use modules instead of putting everything a single file?
- Is the development cycle (i.e. changing a source file, recompiling and
  running tests) faster when using modules? Explain your answer.
- What is a _header guard_ and why is it needed?
- Why is `bstree` not _defined_ in the header file? What are the
  implications?
- Explain the `const` in the parameter list of `bstree_print`, is it required?
- Explain memory leaks. Why are memory leaks bad? You should know how to use `valgrind` to check your program for memory leaks.
- What is the reason behind writing _everything_ in English?
- Why should you use `static` for _non-exported_ functions?
- Why should we comment our source code? Is it always needed? What should the
  comment state? What is _self-documenting code_?
- Why should the module not output debug messages?
- Why and when should you use `assert`?
- What are the benefits of using `make` over calling the compiler by hand?
- Imagine it was your job to design the interface for the bstree module
  (writing `bstree.h`). What would you have done differently, and why?
