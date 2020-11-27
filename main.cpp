#include <iostream>
#include <iomanip>
#include <numeric>
#include <array>
#include <algorithm>

int main() {
  std::cout << __cplusplus << '\n';

  int numeric = 0;
  int iota = 1;
  do {
    numeric += iota;
    /*
    std::cout << std::setw(4) << numeric << ' ';
    numeric = numeric + 1;
    std::cout << std::setw(4) << numeric << ' ';
    numeric = numeric + numeric;
    std::cout << std::setw(4) << numeric << std::endl;
    */
  } while (++iota <= 100);
  std::cout << "The sum of numbers 1-100 (do while)   is "
            << numeric
            << std::endl;

  auto accum = [](auto N) { return (N * (N + 1) / 2); };
  auto sum = accum(100);
  std::cout << "The sum of numbers 1-100 (lambda).    is "
            << sum
            << std::endl;

  std::array<int, 100> val;
  std::iota(val.begin(), val.end(), 1);

#ifdef AS_DEBUGGIT__
  size_t cc = 0;
  size_t constexpr cc_max = 10;
  std::for_each(val.begin(), val.end(), [& cc](auto n_) {
    std::cout << std::setw(4) << n_
              << (++cc % cc_max == 0 ? "\n" : "");
  });
  std::cout << std::endl;
#endif

  auto val_sum = std::accumulate(val.begin(),
                                 val.end(),
                                 0,
                                 std::plus<>());
  std::cout << "The sum of numbers 1-100 (accumulate) is "
            << val_sum
            << std::endl;

  return 0;
}