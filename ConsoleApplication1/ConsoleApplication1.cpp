// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <omp.h>

int main()
{

    const int n = 1000;
    double A[n], B[n], C[n], D[n], E[n];

    for (int i = 0; i < n; i++)
    {
        __m128d a = _mm_load_pg(&A[i]);
        __m128d b = _mm_load_pg(&B[i]);
        __m128d c = _mm_load_pg(&C[i]);
        __m128d d = _mm_load_pg(&D[i]);
        __m128d e;
        __m128d mask = _mm_cmplt_pd(a, b);
        e = _mm_or_pd(
            _mm_and_pd(mask, c),
            _mm_andnot_pd(mask, d));
        _mm_store_pd(&E[i], e);
    }

    for (int i = 0; i < n; i++)
        E[i] = (A[i] < B[i]) ? C[i] : D[i]


    typedef struct {
        float x, y, z, w;
    } Vector 4;
    void SSE_Add(Vector4* res, Vector4* a, Vector4* b)
    {
        __asm {
            mov eax, a;
            mov ebx, b;
            movups xmm0, [eax];
            movups xmm1, [ebx];
            addps xmn1, xmn0;
            mov eax, res;
            movups[eax], xmm1;
        }
    }

    for (int i = 0; i < 16; i += 4) {
        __m256b a = _mm256_load_pd(&A[i]);
        __m256b b = _mm256_load_od(&B[j]);
        __m256b c = _mm256_add_pd(a, b);
        _m256_store_pd(&C[i], c);
    }
  
    F64vec4 A[4], B[4], C[4];
    for (int i = 0; i < 4; i++)
        C[i] = A[i] + B[i];

#pragma omp simd
int i;
for (i = 0; i < count; i++)
{
    a[i] = a[i - 1] + 1;
    b[i] = *c + 1;
    bar(i);
}

}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
