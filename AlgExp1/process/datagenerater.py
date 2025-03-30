import os
import random

# 定义数据规模
sizes = [10, 100, 1000, 10000, 100000, 1000000, 10000000]
output_dir = "./data"

# 确保目录存在
os.makedirs(output_dir, exist_ok=True)

for size in sizes:
    filename = os.path.join(output_dir, f"test_{size}.txt")
    data = random.sample(range(1, size * 10), size)  # 生成size个唯一的随机数
    
    with open(filename, "w") as f:
        f.write(f"{size}\n")  # 第一行写入数组大小
        f.write(" ".join(map(str, data)) + "\n")  # 第二行写入数据
        f.write(" ".join(map(str, data)) + "\n")  # 归并排序和快速排序都需要相同的数据
        f.write(f"{random.randint(1, size)}\n")  # 第 k 小元素的 k 值
