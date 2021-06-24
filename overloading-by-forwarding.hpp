#ifndef _OVERLOADING_BY_FORWARDING_H_
#define _OVERLOADING_BY_FORWARDING_H_

#include <cstddef>
#include <iostream>


auto ProcessPair(int a, int b)
{
    std::cout << "ProcessPair (int): a=" << a << ", b=" << b << std::endl;
}

auto ProcessPair(double a, double b)
{
    std::cout << "ProcessPair (double): a=" << a << ", b=" << b << std::endl;
}

auto ForwardToProcessor = []<typename ...T>(T&& ...args) {
  return ProcessPair(std::forward<T>(args)...); // we have all the types!
};

#endif
