import pandas as pd
df = pd.read_csv('./result/sorting_results.csv')

grouped = df.groupby('Data Size', as_index=False).mean()

grouped.to_csv('./result/averages.csv', index=False)
print("平均耗时数据已写入 averages.csv")
