import os
import pandas as pd

df2 = pd.read_csv('results.csv')
num_algorithms = len(df2)//2

for i in range(num_algorithms):
    std_kernel = df2.iloc[i]['kernel']
    hpx_kernel = df2.iloc[i+num_algorithms]['kernel']
    std_average_time = df2.iloc[i]['average_time']
    hpx_average_time = df2.iloc[i+num_algorithms]['average_time']

    print(f"{std_kernel}/{hpx_kernel}: {std_average_time}/{hpx_average_time}")
    print(f"{std_kernel}/{hpx_kernel}: {std_average_time/hpx_average_time}")
    print()
    
