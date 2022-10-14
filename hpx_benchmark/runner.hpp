#include <chrono>
#include <fstream>
#include <functional>
#include <iostream>
#include <string>

struct csv_log_t
{
    static std::string run_log;

    csv_log_t()
    {
        if (run_log.empty())
        {
            run_log = "kernel,input_size,average_time,min_time,max_time\n";
        }
    }

    void add_log(std::string kernel_name, size_t input_size,
        double average_time, double min_time, double max_time)
    {
        run_log += kernel_name + "," + std::to_string(input_size) + "," +
            std::to_string(average_time) + "," + std::to_string(min_time) +
            "," + std::to_string(max_time) + "\n";
    }

    void write_to_file(std::string name = "csv_log")
    {
        std::ofstream csv_file(name + ".csv");
        csv_file << run_log;
    }

    std::string name;
};

std::string csv_log_t::run_log{};

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

        csv_log_t csv_log;

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

        csv_log.add_log(
            kernel_name, input_size, average_exe_time, min_time, max_time);

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
