#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int main()
{
    long long n = 340000062;
    double pi = 0;
    double temp;

    // union ticks
    // {
    //     unsigned long long t64;
    //     struct s32
    //     {
    //         long th, tl;
    //     }t32;

    // }start, end;
    // double cpu_Hz = 2100000000ULL; // 2.1 GHz CPU

    // asm("rdtsc\n":"=a"(start.t32.th),"=d"(start.t32.tl));

    timespec start_gettime, end_gettime;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start_gettime);


    for (int i = 0; i < n; i++)
    {
        temp = ((pow(-1, i)) / (2 * i + 1));
        pi += temp;
    }
    pi = 4 * pi;

    // asm("rdtsc\n":"=a"(end.t32.th),"=d"(end.t32.tl));
    // cout << "Time taken: " << (end.t64 - start.t64) / cpu_Hz << endl;
    
    clock_gettime(CLOCK_MONOTONIC_RAW, &end_gettime);
    cout << "clock_gettime: time = " << end_gettime.tv_sec - start_gettime.tv_sec + 0.000000001*(end_gettime.tv_nsec - start_gettime.tv_nsec) << endl;
    cout << "pi = " << pi << endl;
    return 0;
}
