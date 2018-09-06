#include <stdafx.h>

int main() {
  std::mt19937 rng;
  rng.seed(std::random_device()());
  std::uniform_int_distribution<std::mt19937::result_type> dist6(
      1, 6);  // distribution in range [1, 6]

  std::cout << "sizeof (rng):" << sizeof(std::mt19937) << " sizeof (dist6):"
            << sizeof(std::uniform_int_distribution<std::mt19937::result_type>)
            << dist6(rng) << std::endl;
  return 0;
}
