import pandas as pd
df = pd.read_csv('./result/sorting_results.csv')

# 查看数据，确保列名正确
# print(df.head())

# 假设 CSV 文件的列为：
# "Data Size", "Merge Sort Time (ns)", "Quick Sort Time (ns)", "Select Time (ns)"
# 由于数据中有10个记录（每个数据规模出现10次），按 Data Size 分组并计算均值
grouped = df.groupby('Data Size', as_index=False).mean()

# 将平均值写入新的 CSV 文件 "averages.csv"
grouped.to_csv('./result/averages.csv', index=False)
print("平均耗时数据已写入 averages.csv")
