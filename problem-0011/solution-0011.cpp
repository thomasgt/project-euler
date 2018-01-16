#include <cstdint>
#include <iostream>
#include <memory>
#include <string>

struct Grid {
  Grid(uint32_t r, uint32_t c);
  uint8_t **data;
  const uint32_t rows;
  const uint32_t columns;
};

uint64_t getMaximumProduct(const Grid&);

int main(int argc, char *argv[]) {
  uint32_t n;
  std::string filename;
  if (argc > 2) {
    std::cout << "Usage: maximum_product [n filename]" << std::endl;
    exit(EXIT_FAILURE);
  } else if (argc == 2) {
    N = std::stoul(argv[1]);
  } else {
    N = 10;
  }
}

Grid::Grid(uint32_t r, uint32_t c) : rows(r), columns(c) {
  data = new uint8_t*[r];
  for (uint32_t i = 0; i < r; ++i) {
    data[i] = new uint8_t[c];
  }
}