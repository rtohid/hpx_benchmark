#include <chrono>
#include <fstream>
#include <functional>
#include <iostream>
#include <string>

class Runner
{
public:
    Runner(std::string kernel_name, size_t num_runs, size_t input_size = 0)
      : kernel_name(kernel_name)
      , num_runs(num_runs)
      , input_size(input_size)
    {
    }

    template <typename Function, typename... Args>
    void run(Function&& kernel, Args&&... args)
    {
        double current_time = 0;
        std::chrono::duration<double> execution_time;

        std::ofstream csv_file(kernel_name + ".csv");

        csv_file << "kernel, input_size, averag_time, min_time, max_time\n";

        std::cout << "START RUNNING <<<" << kernel_name << ">>>" << std::endl;
        for (size_t i = 0; i < num_runs; i++)
        {
            auto start = std::chrono::high_resolution_clock::now();

            ////////// Calling the Kernel
            kernel(std::forward<Args>(args)...);

            execution_time = std::chrono::high_resolution_clock::now() - start;
            current_time = execution_time.count();

            ////////// Update running times
            if (current_time < min_time)
                min_time = current_time;
            if (current_time > max_time)
                max_time = current_time;
            average_exe_time += current_time;

            std::cout << "~~~ run " << i + 1 << " took: " << current_time
                      << " ~~~" << std::endl;
        }

        average_exe_time /= num_runs;

        csv_file << kernel_name << ", " << input_size << ", "
                 << average_exe_time << ", " << min_time << ", " << max_time
                 << std::endl;

        std::cout << kernel_name << " took " << average_exe_time
                  << " on average" << std::endl;
        std::cout << "FINISHED RUNNING <<<" << kernel_name << ">>>"
                  << std::endl;
    }

    size_t num_runs;
    size_t input_size;

    double min_time = std::numeric_limits<double>::max();
    double max_time = 0;
    double average_exe_time;

    std::string kernel_name;
};
