# Exercise Sheet 2

In this exercise sheet you will work with **processes** and **signals**.

Remember to provide a `Makefile`, and to adhere to our [general guidelines for programming exercises](../README.md).

## Task 1

Write a program which creates `N` child processes, where `N` can be specified
on the command line.

Every child

- Computes the 40th number of the Fibonacci sequence.
- Prints a message of the form `"Child <i> PID = <PID>. Fib(40) = <fib(40)>"`
  where PID refers to the _process id_.

The parent waits until all children have exited and then prints `"Done"`.

You may use the following implementation for the Fibonacci sequence:

```c
unsigned fib(unsigned n) {
  if(n <= 1) return n;
  return fib(n - 1) + fib(n - 2);
}
```

Example output:

```
./task1 2
Child 0 PID = 19698. Fib(40) = 102334155
Child 1 PID = 19699. Fib(40) = 102334155
Done
```

Analyze the obtained output. Is the order of the messages consistent? Can the
order of these messages be predicted? What does it depend on?

**Hint**: Remember that a child process can be created with `fork()`.
A parent process can wait for its children using `wait()` or `waitpid()`

## Task 2

Write a program in which the parent creates a single child process. The child
process prints the message `"Child <PID> sleeping for 5 seconds..."` and then
sleeps for five seconds, using the `sleep()` function. Afterwards it prints
`"Child done"` and exits. The parent process waits until it is sure that the
child has terminated, prints `"Parent done"` and exits as well. There is a
catch, however: In this task, you **must not** use `wait()` or `waitpid()`.

Example output:

```
./task2
Child 20196 sleeping for 5 seconds...
Child done
Parent done
```

**Hint**: Check the man page of `fork()` to see whether the parent is somehow
notified of child termination. Also see `sigaction()` to determine how to
respond to an incoming signal. For a general overview on signals see `man 7 signal`.

## Task 3

Write a program in which the parent process creates a single child process.

The parent

- Waits three seconds and then sends `SIGUSR2`, followed by `SIGUSR1` to the
  child
- It then continuously sends `SIGUSR1` every three seconds, until the child
  process has terminated
- Finally, it prints `"Parent done"` and exits

To implement this behavior the parent process **must** use the following
functions: `alarm()` and `pause()` (or alternatively `sigsuspend()`). You
**must not** use `sleep()`.

The child

- Blocks `SIGUSR2` for 13 seconds
- Upon receiving `SIGUSR1`, it prints `"Received SIGUSR1"`
- Upon receiving `SIGUSR2`, it prints `"Child done"` and exits

Note that you **may** use `sleep()` in the child process.

Example output:

```
./task3
Received SIGUSR1
Received SIGUSR1
Received SIGUSR1
Received SIGUSR1
Child done
Parent done
```

**Hint**: Check the man page of `alarm()`, `pause()`, `kill()`, `sigprocmask()` and
`sigaction()`.
