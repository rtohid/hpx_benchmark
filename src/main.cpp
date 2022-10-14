#include <cmath>

#include <hpx/config.hpp>
#include <hpx/hpx.hpp>
#include <hpx/hpx_init.hpp>
#include <hpx/include/datapar.hpp>

#include <hpx_benchmark/kernels.hpp>
#include <hpx_benchmark/runner.hpp>
#include <hpx_benchmark/utils.hpp>

int run_std()
{
    constexpr int num_runs{10};
    size_t input_size{static_cast<size_t>(std::pow(2, 26))};
    std::vector<double> input(input_size);

    std_count_t std_count;
    std_foreach_t std_foreach;
    std_generate_t std_generate;
    std_reduce_t std_reduce;
    std_max_element_t std_max_element;
    std_sort_t std_sort;

    Runner run_std_generate{"std_generate", num_runs, input_size};
    run_std_generate.run(std_generate, std::execution::seq, input.begin(),
        input.end(), generate_real_t<double>{});

    Runner run_std_count{"std_count", num_runs, input_size};
    run_std_count.run(
        std_count, std::execution::seq, input.begin(), input.end(), input[0]);

    Runner run_std_foreach{"std_foreach", num_runs, input_size};
    run_std_foreach.run(std_foreach, input.begin(), input.end(),
        [](auto& v) { v = v * 5.0f + v; });

    Runner run_std_reduce{"std_reduce", num_runs, input_size};
    run_std_reduce.run(
        std_reduce, std::execution::seq, input.begin(), input.end());

    Runner run_std_max_element{"std_max_element", num_runs, input_size};
    run_std_max_element.run(
        std_max_element, std::execution::seq, input.begin(), input.end());

    Runner run_std_sort{"std_sort", num_runs, input_size};
    run_std_sort.run(
        std_sort, std::execution::seq, input.begin(), input.end());

    return 0;
}

int run_hpx()
{
    constexpr int num_runs{10};
    size_t input_size{static_cast<size_t>(std::pow(2, 26))};
    std::vector<double> input(input_size);

    hpx_count_t hpx_count;
    hpx_foreach_t hpx_foreach;
    hpx_generate_t hpx_generate;
    hpx_reduce_t hpx_reduce;
    hpx_max_element_t hpx_max_element;
    hpx_sort_t hpx_sort;

    Runner run_hpx_generate{"hpx_generate", num_runs, input_size};
    run_hpx_generate.run(hpx_generate, hpx::execution::seq, input.begin(),
        input.end(), generate_real_t<double>{});

    Runner run_hpx_count{"hpx_count", num_runs, input_size};
    run_hpx_count.run(
        hpx_count, hpx::execution::seq, input.begin(), input.end(), input[0]);

    Runner run_hpx_foreach{"hpx_foreach", num_runs, input_size};
    run_hpx_foreach.run(hpx_foreach, input.begin(), input.end(),
        [](auto& v) { v = v * 5.0f + v; });

    Runner run_hpx_reduce{"hpx_reduce", num_runs, input_size};
    run_hpx_reduce.run(
        hpx_reduce, hpx::execution::seq, input.begin(), input.end());

    Runner run_hpx_max_element{"hpx_max_element", num_runs, input_size};
    run_hpx_max_element.run(
        hpx_max_element, hpx::execution::seq, input.begin(), input.end());

    Runner run_hpx_sort{"hpx_sort", num_runs, input_size};
    run_hpx_sort.run(
        hpx_sort, hpx::execution::seq, input.begin(), input.end());

    return 0;
}

int hpx_main()
{
    run_hpx();
    return hpx::finalize();
}

int main()
{
    run_std();
    hpx::init();
    csv_log_t csv_file{};
    csv_file.write_to_file("results");
}
