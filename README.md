# CEPARCO Project Deep Dive: SIMD programming project 
## Specification
![image](https://github.com/DDGC7/CEPARCO-SIMD-programming-project/assets/99391788/1f89daec-982b-4c03-83ea-35a42e75865b)

## Average Execution Time Comparison 
![image](https://github.com/DDGC7/CEPARCO-SIMD-programming-project/assets/99391788/d4b3ac63-8dd5-486a-9b7d-007f40e42255)

The given vector sizes to be measured are {2^20, 2^24, and 2^28 up until 2^30). However, it seems the malloc cannot handle allocating more than 2 GB of memory. The maximum it could handle apparently is only up to 2^26 for both arrays. 

For the comparison of their average execution time, it would appear that the C program is the slowest and that SIMD is the fastest.

For 2^20, x86 is faster than C by 1.718 times.
For 2^24, x86 is faster than C by 1.586 times.
For 2^26, x86 is faster than C by 1.543 times.

For 2^20, SIMD is faster than C by 3.267 times.
For 2^24, SIMD is faster than C by 3.074 times.
For 2^26, SIMD is faster than C by 2.957 times.

For 2^20, SIMD is faster than x86 by 1.902 times.
For 2^24, SIMD is faster than x86 by 1.937 times.
For 2^26, SIMD is faster than x86 by 1.916 times.

### Output
![image](https://github.com/DDGC7/CEPARCO-SIMD-programming-project/assets/99391788/4f903805-84f2-48fb-aa70-1d9dc4591b5c)


![image](https://github.com/DDGC7/CEPARCO-SIMD-programming-project/assets/99391788/05293a5f-71da-4636-b2a8-41bc97bfd88d)


![image](https://github.com/DDGC7/CEPARCO-SIMD-programming-project/assets/99391788/b34368da-9812-4a2c-8345-9137dfc5cacd)


## Performance Analysis

Based on the recorded average execution times, or the performance, C is the slowest and x86 SIMD is the fastest. The reasoning on why C is the slowest is because x86 assembly code allows fine-grained control over the instructions executed by the processor. Which means that you are able to use the most efficient instructions that are specific to the x86 architecture, which you cannot do in C. Also, in x86 you are able to only use the necessary and needed instructions in order to perform your computation. 

Another reason why x86 would be faster than C is that you have precise control over memory access, which can lead to optimal performance. This isn’t likely to be possible in C code. For x86 SIMD, it can be faster than regular x86 for these reasons. One of the reasons is because of the parallel processing. This allows the instructions to perform the same operation on multiple data elements simultaneously, which leads to faster execution. 

Another reason why it is faster is because of the enhanced instructions that are included or provided. These enhanced instructions are able to cover wider registers, enabling larger data to be processed simultaneously. 



