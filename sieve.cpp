#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <time.h>
#include <fstream>

using namespace std;

std::chrono::duration<double> elapsed_seconds;

void sieve(vector<bool>& prime, long long n)
{
    auto start = std::chrono::steady_clock::now();
    prime[0] = prime[1] = false;
    for (int i = 2; i <= n; ++i)
        if (prime[i])
            if (i * 1ll * i <= n)
                for (int j = i * i; j <= n; j += i)
                    prime[j] = false;
    auto end = std::chrono::steady_clock::now();
    elapsed_seconds = end - start;
}

fstream table;
void sieveRun()
{
    fstream fs;
    fs.open("D:\\Algosi\\table3.txt");
    if (fs.is_open())
        for (long long n = 2; n < 100000003; )
        {
            cout << n << ' ';
            vector<bool> prime(n + 1, true);
            sieve(prime, n);
            fs << n << ' ';
            auto sec1 = elapsed_seconds.count();

            vector<bool> prime2(2 * n + 1, true);
            sieve(prime2, 2 * n);
            auto sec2 = elapsed_seconds.count();

            fs << sec2 / sec1 << '\n';
            cout << sec2 / sec1 << '\n';

            if (n < 10000)
                n += 5;
            else if (n < 100000)
                n += 2000;
            else if (n < 1000000)
                n += 10000;
            else if(n < 10000000)
                n += 100000;
            else 
                n += 1000000;
        }

}

int main()
{

    sieveRun();



}


