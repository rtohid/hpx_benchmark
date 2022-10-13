//  Copyright (c) 2022 Srinivas Yadav
//
//  SPDX-License-Identifier: BSL-1.0
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <random>

template <typename T>
struct generate_real_t
{
    generate_real_t(int seed = 42)
      : mersenne_engine(std::mt19937(seed))
    {
    }

    T operator()()
    {
        return std::uniform_real_distribution<T>{0, 1024}(mersenne_engine);
    }

    std::mt19937 mersenne_engine;
};

template <typename T>
struct generate_natural_t
{
    generate_natural_t(int seed = 42)
      : mersenne_engine(std::mt19937(seed))
    {
    }

    T operator()()
    {
        return std::uniform_int_distribution<T>{0, 1024}(mersenne_engine);
    }

    std::mt19937 mersenne_engine;
};
