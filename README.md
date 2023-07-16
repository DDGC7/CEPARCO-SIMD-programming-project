# CEPARCO Project Deep Dive: SIMD programming project 
## Specification
![image](https://github.com/DDGC7/CEPARCO-SIMD-programming-project/assets/99391788/1f89daec-982b-4c03-83ea-35a42e75865b)

## Program Details
The project folder will contain three files. Mentioned below are the filenames included in the folder that will be performing dot matrix.

cfunc.c - will contain the C kernel and main used to call the other kernels.

asmfunc.asm - will contain the x86 kernel.

simdfunc.asm - will contain the x86 SIMD kernel.

For the creation of vectors A and B, each element of each vector will be randomized. The program made use of the rand() function to initialize the randomized elements. 

 The program will ask the user to input n, which is the vector length. The next step of the program is the initialization of vectors A and B. After initializing, the kernels will run for 30 times. The program made use of time.h in order to get the average execution time of each kernel and display it. The next step is that it will display a prompt saying whether the outputs of each kernel are a match. If not, the program will display an error message. 

For the correction check, I will use the output of the C program as my basis, since for me the C program is what I am sure of to be correct. My error checking involves comparing the x86 output to my C program output. If it is correct, then it will proceed with the loop in order to run 30 times. If it is not the same, then it will print a message that the answer is incorrect, and the loop will end. 

## Program Screenshots
### 1. C kernel
![image](https://github.com/DDGC7/CEPARCO-SIMD-programming-project/assets/99391788/0b8ce382-b1f7-4b74-8c2f-f518f68f4a99)
### 2. x86 kernel
![image](https://github.com/DDGC7/CEPARCO-SIMD-programming-project/assets/99391788/390750dc-150b-446f-9a3c-4a90a2ae7fb2)
### 3. x86 SIMD kernel
![image](https://github.com/DDGC7/CEPARCO-SIMD-programming-project/assets/99391788/a97ae923-edfc-46d1-81f2-5873093c8926)
### 4. C main program
![image](https://github.com/DDGC7/CEPARCO-SIMD-programming-project/assets/99391788/4aff5cb8-794c-40fe-9a01-39fc481ae175)
![image](https://github.com/DDGC7/CEPARCO-SIMD-programming-project/assets/99391788/513030ab-1647-42c1-8787-7bbc0ebee5ec)
![image](https://github.com/DDGC7/CEPARCO-SIMD-programming-project/assets/99391788/ed0d6a7e-e6c5-4e94-937f-ddccd270533c)
### 5. Output
![image](https://github.com/DDGC7/CEPARCO-SIMD-programming-project/assets/99391788/4995096f-6856-42aa-9ff7-01aa4711e588)

![image](https://github.com/DDGC7/CEPARCO-SIMD-programming-project/assets/99391788/4e8c8e2f-3dd3-4769-a847-72c8966e02ad)

![image](https://github.com/DDGC7/CEPARCO-SIMD-programming-project/assets/99391788/7d7be8d9-797c-4d48-a71b-ef71ccc8a4f7)


## Average Execution Time Comparison 
![image](https://github.com/DDGC7/CEPARCO-SIMD-programming-project/assets/99391788/d4b3ac63-8dd5-486a-9b7d-007f40e42255)

The given vector sizes to be measured are {2^20, 2^24, and 2^28 up until 2^30). However, it seems the malloc cannot handle allocating more than 2 GB of memory. The maximum it could handle apparently is only up to 2^26 for both arrays. 

For the comparison of their average execution time, it would appear that the C program is the slowest. Although it is expected that SIMD would have the fastest execution time because of its parallelism, x86 is the fastest program for the data that I have right now. 

For 2^20, x86 is faster than C by 0.454 times.
For 2^24, x86 is faster than C by 0.584 times.
For 2^26, x86 is faster than C by 0.570.

## Performance Analysis

Based on the recorded average execution times, or the performance, C is the slowest and presumably x86 SIMD is the fastest. The reasoning on why C is the slowest is because x86 assembly code allows fine-grained control over the instructions executed by the processor. Which means that you are able to use the most efficient instructions that are specific to the x86 architecture, which you cannot do in C. Also, in x86 you are able to only use the necessary and needed instructions in order to perform your computation. 

Another reason why x86 would be faster than C is that you have precise control over memory access, which can lead to optimal performance. This isn’t likely to be possible in C code. For x86 SIMD, it can be faster than regular x86 for these reasons. One of the reasons is because of the parallel processing. This allows the instructions to perform the same operation on multiple data elements simultaneously, which leads to faster execution. 

Another reason why it is faster is because of the enhanced instructions that are included or provided. These enhanced instructions are able to cover wider registers, enabling larger data to be processed simultaneously. 

## Missing Specifications

For the missing specifications of the project, I wasn’t able to implement a proper working kernel for x86 SIMD.  For my x86 SIMD kernel, I honestly wasn’t able to print the right output. Although, I felt like I traced my program properly and that the logic was right, the computation wasn’t getting displayed. Because of that, I wasn’t also able to implement error checking for x86 SIMD, since the kernel itself isn’t working. 

For the sample size, for some reason my program could not handle 2^27 and beyond inputs. I always get an error, so for that I decided to run up until 2^26.

