# Getting Started

You'll need a computer running some form of Linux.  The labs are currently tested with Ubuntu 18.04.

You'll want to install clang and lldb. On Ubuntu, that looks like this:

```sudo apt-get install clang lldb```

(Note that this list may grow as the first labs are built out.)

You'll need to disable a security feature called ASLR in order to do these labs.  You can do that by running the following command:

```echo 0 | sudo tee /proc/sys/kernel/randomize_va_space```

After you're done with the labs, remember to re-enable ASLR by running 

```echo 2 | sudo tee /proc/sys/kernel/randomize_va_space```

Please start with "Stack Smashing", the first lab. (Currently in progress)
