import os
import pandas as pd

algorithms = [
    "std_count",
    "hpx_count",
    "std_reduce",
    "hpx_reduce",
    "std_foreach",
    "hpx_foreach",
    "std_max_element",
    "hpx_max_element",
    "std_sort",
    "hpx_sort",
]

df = pd.DataFrame()
for algorithm in algorithms:
    df2 = pd.read_csv(f"/work/rod/hpx_benchmark/{algorithm}.csv")
    print(df2)

# df = pd.DataFrame()
# df2 = pd.read_csv('/work/rod/hpx_benchmark/results.csv')
# print(df2)
