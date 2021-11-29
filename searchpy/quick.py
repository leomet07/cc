

Ways for Fast Input / Output in Python
By thekushalghosh, 13 months ago, In English

Hello CodeForces Community,

Input / Output in Python can be sometimes time taking in cases when the input is huge or we have to output many number of lines, or a huge number of arrays(lists) line after line.

I have come across many questions on CodeForces where the style of taking input and printing makes your code quite faster.

For Input :-

Normally, the input is taken from STDIN in the form of String using input(). And this STDIN is provided in the Judge's file. So why not try reading the input directly from the Judge's file using the Operating system(os) module, and input / output(io) module. This reading can be done in the form of bytes.

The code for that would be :-

import io,os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

or a native method (which can be used for not too large inputs) :-

import sys
input = sys.stdin.readline

Now for Output :-

Instead of throwing the output to the STDOUT, we can try writing to the Judge's sytem file. The code for that would be to use sys.stdout.write instead of print. But remember you can only output strings using this, so convert the output to string using str or map.

Examples :-

For printing an integer, instead of

print(n)

Use :-

sys.stdout.write(str(n) + "\n")

For printing a list of integers, instead of

print(*list)

Use :-

sys.stdout.write(" ".join(map(str,list)) + "\n")

Now Program examples On CodeForces, where this was useful :-

Question 1
TLE Solution
AC Solution
