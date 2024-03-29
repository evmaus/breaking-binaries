# Stack Smashing

Welcome to the first lab of "Breaking Binaries"!  Before you start this lab, make sure you have disabled ASLR in the Linux kernel by following the instructions in Basics/Getting Started.md.

This is still under construction.

## Lab Steps

### Step 1: Crashing a Program

Take a look at 'hello.cc'.  This is a simple program that greets the user given a command line argument.  We'll be using variations of it throughout this lab.

Try compiling hello.cc and running it.  We'll go into the meaning of each of the parameters in the Mitigations labs, but for now just know that they're necessary for the attack we want to do.

```clang++ -fno-stack-protector -Wl,-z,execstack hello.cc -o hello```

```./hello world```

Now to crash it.  Do you see how?  Let's try putting more than a hundred 'A's...

```./hello `perl -e "print 'A'x140"` ```

You should get a segmentation fault!  Let's talk about why.

As a side note, using a scripting language like Perl to automate inputs to a command line is a useful trick.

### Step 2: Why the Crash? Let's use LLDB

You can read more about common LLDB syntax [here](https://aaronbloomfield.github.io/pdr/tutorials/02-lldb/index.html), and if you aren't already familiar with LLDB you should read through that tutorial first.

It'll also be helpful to review the x86_64 calling convention in "Calling Convention.md"

Now let's run LLDB on ./hello.

```lldb ./hello `perl -e "print 'A'x140"```

Let's see what's going on here.  Use ```run``` to run the program.  You should get a crash with "stop reason = signal SIGSEGV: invalid address" at an instruction ```retq```.  ('retq' is simply the 64 bit version of 'ret')

Recall that 'ret' pulls the return address (in this case, the 64 bit return address) off the stack and returns execution to that address.  Let's see what the stack looks like with ```x/2x $rsp```.  You should get something like ```0x41414141 0x41414141```.  '0x41' is the ASCII character for 'A'; execution has crashed because strcpy took all 140 copies of 'A' and copied them onto the stack.

We'd recommend further examining the code in 'hello' (try ```disassemble -n hello```) to verify that you know what's going on in the function, and further examining the stack (try ```x/s $rsp-120```).

### Step 3: Redirecting Execution

Take a look at 'first_steps.cc'.  You can compile it as such:

```clang++ -fno-stack-protector -Wl,-z,execstack first_steps.cc -o first_step -m32```

Now, this is basically ./hello.cc with one added function, the "victory()" function (which prints "VICTORY!"), compiled as a 32 bit executable.

Can you find an input that will cause ./first_step to print out "VICTORY!"?  Hint:  Remember the calling convention and get the address of the 'victory()' function from LLDB via ```image lookup -r -n victory```.

### Step 4: Code Execution


### Step 5: Shellcode

Read the Shellcode.md writeup, and potentially "Hello World!" on everettmaus.com ([link](http://www.everettmaus.com/blog/posts/2016/12/27/hello-world.html)).

### Step 6: Arbitrary Code Exection

### Challenge:  Getting a Root Shell

## Related Reading

Smashing the Stack for Fun and Profit [link](http://www-inst.eecs.berkeley.edu/~cs161/fa08/papers/stack_smashing.pdf)
Hello World! on everettmaus.com (An introduction to shellcode on x86) [link](http://www.everettmaus.com/blog/posts/2016/12/27/hello-world.html)
