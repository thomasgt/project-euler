#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

uint64_t sumOfPrimes(uint64_t);

int main(int argc, char *argv[]) {
  uint64_t N;
  if (argc > 2) {
    std::cout << "Usage: summation_of_primes [n]" << std::endl;
    exit(EXIT_FAILURE);
  } else if (argc == 2) {
    N = std::stoul(argv[1]);
  } else {
    N = 10;
  }

  std::cout << "Computing summation of primes below " << N << std::endl;

  uint64_t sum = sumOfPrimes(N);

  std::cout << "Sum: " << sum << std::endl;
}

uint64_t sumOfPrimes(uint64_t n) {
  #define UNMARKED 0
  #define MARKED 1
  std::vector<uint8_t> sieve(n - 2, UNMARKED);
  uint64_t p = 2;
  for (;;) {
    for (uint64_t i = 2 * p; i < n; i += p) {
      sieve[i - 2] = MARKED;
    }
    auto it = std::find(sieve.begin() + p - 1, sieve.end(), UNMARKED);
    if (it != sieve.end()) {
      p = std::distance(sieve.begin(), it) + 2;
    } else {
      break;
    }
  }

  uint64_t sum = 0;
  for (uint64_t i = 0; i < sieve.size(); ++i) {
    if (sieve[i] == UNMARKED) {
      sum += i + 2;
    }
  }

  return sum;
}