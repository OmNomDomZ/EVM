#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int main()
{

    long long n = 100000000;
    double pi = 0;
    double temp;
    timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);


    for (int i = 0; i < n; i++)
    {
        temp = ((pow(-1, i)) / (2 * i + 1));
        pi += temp;
    }
    pi = 4 * pi;

    clock_gettime(CLOCK_MONOTONIC_RAW, &end);

    cout << "start = " << start.tv_sec << endl;
    cout << "end = "<< end.tv_sec << endl;
    cout << "pi = " << pi << endl;
    return 0;
}
