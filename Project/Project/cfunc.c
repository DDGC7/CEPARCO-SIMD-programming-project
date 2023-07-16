#include <stdio.h>
#include <stdlib.h>
#include <time.h>
extern void dotProduct_SIMD(long long int n, long long int* A, long long int* B, long long* sdot);
extern void dotProduct_ASM(long long int n, long long int* A, long long int* B, long long* sdot);

void dotProduct_C(long long int n, long long int* A, long long int* B, long long* sdot)
{
    int i;

    for (i = 0; i < n; i++)
    {
        *sdot = *sdot + (long long)A[i] * B[i];
    }
}

int main()
{
    int i, iterations = 30, C_x86 = 0;
    long long int n;
    long long sdot_C = 0;
    long long sdot_ASM = 0;
    long long sdot_SIMD;

    printf("Enter the vector length (n): ");
    scanf_s("%lld", &n);

    long long int* A = (long long int*)malloc(sizeof(long long int) * n);
    long long int* B = (long long int*)malloc(sizeof(long long int) * n);

    srand(time(NULL));  // Initialize random seed

    // Generate random values for vector A
    printf("\nGenerating random values for vector A\n");
    for (i = 0; i < n; i++)
    {
        A[i] = rand();
    }

    // Generate random values for vector B
    printf("Generating random values for vector B\n");
    for (i = 0; i < n; i++)
    {
        B[i] = rand();
    }

    clock_t start1, start2, start3, end1, end2, end3;
    double time_taken1, time_taken2, time_taken3, sum1 = 0, sum2 = 0, sum3 = 0, ave1 = 0, ave2 = 0, ave3 = 0;
    for (i = 0; i < iterations; i++)
    {
        sdot_C = 0;
        sdot_ASM = 0;

        start1 = clock();
        dotProduct_C(n, A, B, &sdot_C);
        end1 = clock();
        time_taken1 = ((double)(end1 - start1)) * 1e6 / CLOCKS_PER_SEC;
        sum1 += time_taken1;

        start2 = clock();
        dotProduct_ASM(n, A, B, &sdot_ASM);
        end2 = clock();
        time_taken2 = ((double)(end2 - start2)) * 1e6 / CLOCKS_PER_SEC;
        sum2 += time_taken2;

        start3 = clock();
        dotProduct_SIMD(n, A, B, &sdot_SIMD);
        end3 = clock();
        time_taken3 = ((double)(end3 - start3)) * 1e6 / CLOCKS_PER_SEC;
        sum3 += time_taken3;

        if (sdot_ASM != sdot_C)
        {
            printf("\nThe output of x86 is not the same as the output of C, which indicates it is incorrect.\n");
            C_x86 = 1;
            i = 30;
        }

        /*if (sdot_SIMD != sdot_C)
        {
            printf("\nThe output of SIMD is not the same as the output of C, which indicates it is incorrect.\n");
            i = 30;
        }*/
    }

    if (C_x86 != 1) 
    {
        printf("\nOutputs of C and x86 are the same (Correct)\n");
    }



    ave1 = sum1 / iterations;
    ave2 = sum2 / iterations;
    ave3 = sum3 / iterations;

    printf("\nC Average time: %f microseconds\n", ave1);
    printf("x86 Average time: %f microseconds\n", ave2);
    printf("SIMD Average time: %f microseconds\n", ave3);

    printf("\nDot product output of C: %lld\n", sdot_C);
    printf("Dot product output of ASM: %lld\n", sdot_ASM);
    printf("Dot product output of SIMD: %lld\n", sdot_SIMD);



    free(A);
    free(B);

    return 0;
}
