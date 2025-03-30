import os
import random
sizes = [10, 100, 1000, 10000, 100000, 1000000, 10000000]
output_dir = "./data"
os.makedirs(output_dir, exist_ok=True)

for size in sizes:
    filename = os.path.join(output_dir, f"test_{size}.txt")
    data = random.sample(range(1, size * 10), size)  
    
    with open(filename, "w") as f:
        f.write(f"{size}\n")
        f.write(" ".join(map(str, data)) + "\n")
        f.write(" ".join(map(str, data)) + "\n")
        f.write(f"{random.randint(1, size)}\n")
