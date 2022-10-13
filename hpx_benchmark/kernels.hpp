#include <algorithm>
#include <execution>
#include <iostream>
#include <utility>
#include <vector>


#include <hpx/config.hpp>
#include <hpx/hpx.hpp>
#include <hpx/hpx_init.hpp>
#include <hpx/include/datapar.hpp>
#include <hpx/include/compute.hpp>

////////// Standard Library
struct std_count_t
{
    template <typename... Ts>
    auto operator()(Ts&&... ts)
    {
        return std::count(std::forward<Ts>(ts)...);
    }
};

struct std_foreach_t
{
    template <typename... Ts>
    auto operator()(Ts&&... ts)
    {
        return std::for_each(std::forward<Ts>(ts)...);
    }
};

struct std_reduce_t
{
    template <typename... Ts>
    auto operator()(Ts&&... ts)
    {
        return std::reduce(std::forward<Ts>(ts)...);
    }
};

struct std_generate_t
{
    template <typename... Ts>
    auto operator()(Ts&&... ts)
    {
        return std::generate(std::forward<Ts>(ts)...);
    }
};

struct std_max_element_t
{
    template <typename... Ts>
    auto operator()(Ts&&... ts)
    {
        return std::max_element(std::forward<Ts>(ts)...);
    }
};

struct std_sort_t
{
    template <typename... Ts>
    auto operator()(Ts&&... ts)
    {
        return std::sort(std::forward<Ts>(ts)...);
    }
};

////////// HPX
struct hpx_count_t
{
    template <typename... Ts>
    auto operator()(Ts&&... ts)
    {
        return hpx::count(std::forward<Ts>(ts)...);
    }
};

struct hpx_foreach_t
{
    template <typename... Ts>
    auto operator()(Ts&&... ts)
    {
        return hpx::for_each(std::forward<Ts>(ts)...);
    }
};

struct hpx_reduce_t
{
    template <typename... Ts>
    auto operator()(Ts&&... ts)
    {
        return hpx::reduce(std::forward<Ts>(ts)...);
    }
};

struct hpx_generate_t
{
    template <typename... Ts>
    auto operator()(Ts&&... ts)
    {
        return hpx::generate(std::forward<Ts>(ts)...);
    }
};

struct hpx_max_element_t
{
    template <typename... Ts>
    auto operator()(Ts&&... ts)
    {
        return hpx::max_element(std::forward<Ts>(ts)...);
    }
};

struct hpx_sort_t
{
    template <typename... Ts>
    auto operator()(Ts&&... ts)
    {
        return hpx::sort(std::forward<Ts>(ts)...);
    }
};

