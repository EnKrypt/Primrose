#include <cmath>
#include <iostream>
using namespace std;

void usage(string message = "") {
    if (message != "") {
        cout << message << endl << endl;
    }
    cout << "Primrose v0.1" << endl
         << "A prime factorization tool" << endl
         << "https://github.com/EnKrypt/Primrose" << endl
         << endl
         << "Usage: primrose [number]" << endl;
}

inline bool isPrime(long long number) {
    if (((!(number & 1)) && number != 2) || (number < 2) ||
        (number % 3 == 0 && number != 3))
        return (false);

    for (long long k = 1; 36 * k * k - 12 * k < number; ++k)
        if ((number % (6 * k + 1) == 0) || (number % (6 * k - 1) == 0))
            return (false);
    return true;
}

void factorize(long long prime) {
    long long upper_limit = prime;
    long long lower_limit = 2;
    long long iterations = 0;

    while (prime != 1 && lower_limit <= upper_limit) {
        if (isPrime(lower_limit)) {
            while (prime % lower_limit == 0) {
                cout << lower_limit << endl;
                prime = prime / lower_limit;
            }
            upper_limit = floor(prime / lower_limit);
        }
        lower_limit++;
        iterations++;
    }

    if (prime != 1) {
        cout << prime << endl;
    }

    cout << endl << "Computed in " << iterations << " iterations" << endl;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        usage();
        return 1;
    }

    long long prime = -1;
    try {
        prime = stoll(argv[1]);
    } catch (const exception &e) {
        usage("Argument is not a number");
        return 1;
    }

    if (prime < 2) {
        usage("Cannot factorize numbers less than 2");
        return 1;
    }

    factorize(prime);
    return 0;
}
