#include <iostream>
#include <cmath>
#include <ctime>
#include <sys/times.h>
#include <unistd.h>

using std::cout;
using std::endl;

int main()
{
    // long long n = 340001062;
    // clock_gettime ~ 13.9021
    // times ~ 14.19


    long long n = 1000010000;
    // clock_gettime ~ 49.1615
    // times ~ 68.99

    double pi = 0;
    double temp;

    struct tms start, end;
    long long clocks_per_sec = sysconf(_SC_CLK_TCK);
    // cout << "Частота тактов ядра в сек = " <<  clocks_per_sec << endl;
    long long clocks;
    times(&start);

    // timespec start_gettime, end_gettime;
    // clock_gettime(CLOCK_MONOTONIC_RAW, &start_gettime);


    for (int i = 0; i < n; i++)
    {
        temp = ((pow(-1, i)) / (2 * i + 1));
        pi += temp;
    }
    pi = 4 * pi;

    times(&end);
    clocks = end.tms_utime - start.tms_utime;
    cout << "Time taken: " << (double)clocks / clocks_per_sec << endl;

    // // clock_gettime(CLOCK_MONOTONIC_RAW, &end_gettime);
    // // cout << "clock_gettime: time = " << end_gettime.tv_sec - start_gettime.tv_sec + 0.000000001*(end_gettime.tv_nsec - start_gettime.tv_nsec) << endl;

    cout << "pi = " << pi << endl;
    return 0;
}
