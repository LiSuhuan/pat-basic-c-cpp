//
// Created by lenovo on 2023/6/9.
//
#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int num) {
    if (num <= 1)
        return false;

    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0)
            return false;
    }

    return true;
}

int countPrimeTriplets(int m, int n) {
    int count = 0;

    for (int p = m; p <= n - 2; ++p) {
        if (!isPrime(p))
            continue;

        for (int q = p + 1; q <= n - 1; ++q) {
            if (!isPrime(q))
                continue;

            for (int r = q + 1; r <= n; ++r) {
                if (!isPrime(r))
                    continue;

                if (isPrime(p * q + r) && isPrime(q * r + p) && isPrime(r * p + q))
                    ++count;
            }
        }
    }

    return count;
}

int main() {
    int m, n;
    cin >> m >> n;

    int count = countPrimeTriplets(m, n);
    cout << count << endl;

    return 0;
}
