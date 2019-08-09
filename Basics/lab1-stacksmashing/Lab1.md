# Stack Smashing

Welcome to the first lab of "Introduction to the Dark Arts"!

This is still under construction.

## Lab Steps

### Step 1: Crashing a Program

Take a look at hello.cc.  This is a simple program that greets the user given a command line argument.  We'll be using variations of it throughout this lab.

Try compiling hello.cc and running it.  We'll go into the meaning of each of the parameters in the Mitigations labs, but for now just know that they're necessary for the attack we want to do.

```clang++ -fno-stack-protector -Wl,-z,execstack hello.cc -o hello```

```./hello world```

Now to crash it.  Do you see how?  Let's try putting more than a hundred 'A's...

```./hello `perl -e "print 'A'x100"` ```

You should get a segmentation fault!  Let's talk about why.

### Step 2: Why the Crash? Let's use GDB

### Step 3: Redirecting Execution

### Step 4: Code Execution

### Step 5: Shellcode

Read the Shellcode.md writeup, and potentially "Hello World!" on everettmaus.com ([link](http://www.everettmaus.com/blog/posts/2016/12/27/hello-world.html)).

### Step 6: Arbitrary Code Exection

### Challenge:  Getting a Root Shell

## Related Reading

Smashing the Stack for Fun and Profit [link](http://www-inst.eecs.berkeley.edu/~cs161/fa08/papers/stack_smashing.pdf)
Hello World! on everettmaus.com (An introduction to shellcode on x86) [link](http://www.everettmaus.com/blog/posts/2016/12/27/hello-world.html)
