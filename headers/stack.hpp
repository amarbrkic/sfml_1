// Copyright 2022 Amar Brkic

#include <cstdarg>

#include <vector>

template <typename T> class Stack {
private:
  std::vector<T> mem;

public:
  T lastElement;

  /**
   * @brief  Simple push function
   * @note   Doesn't work well with plural arguments
   * @param  nArg: Should be any size
   * @retval None
   */
  template <typename... Args> void push(size_t nArg, ...) {

    va_list arguments;

    va_start(arguments, nArg);

    for (size_t i = 0; i < nArg; i++) {
      mem.push_back(va_arg(arguments, T));
    }

    va_end(arguments);

    lastElement = mem.at(mem.size() - 1);
  }
  void pop() {
    mem.pop_back();
    lastElement = mem.at(mem.size() - 1);
  }
  void print() {
    for (T i : mem) {
      std::cout << i << "\n";
    }
  }
};
