import pandas as pd
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
avg_df = pd.read_csv('./result/averages.csv')
data_size = np.log(avg_df['Data Size'])
merge_sort = avg_df[' Merge Sort Time (ns)']
quick_sort = avg_df[' Quick Sort Time (ns)']
select_time = avg_df[' Select Time (ns)']
algorithm_map = ['Select k','Merge Sort', 'Quick Sort', ]
y_values = pd.factorize(algorithm_map)[0]
fig = plt.figure(figsize=(10, 7))
ax = fig.add_subplot(111, projection='3d')
x, y = np.meshgrid(data_size, y_values)
z = np.array([select_time,merge_sort,  quick_sort])
xpos, ypos = np.meshgrid(data_size, y_values)
xpos = xpos.flatten()
ypos = ypos.flatten()
dx = 1.7*1.2
dy = 0.4*1.2
dz = z.flatten()
ax.bar3d(xpos, ypos, np.zeros_like(dz), dx, dy, dz, zsort='average', color=plt.cm.viridis(dz / max(dz)))
ax.set_xlabel('Data Size')
# ax.set_ylabel('Algorithm')
ax.set_zlabel('Time (ns)')
ax.set_title('Average Time of Different Algorithms')
ax.set_yticks([0, 1, 2])
ax.set_yticklabels(algorithm_map)
plt.savefig("./img/figure1.png",dpi=500)
plt.show()


data_size = np.log(avg_df['Data Size'])
merge_sort = np.log(avg_df[' Merge Sort Time (ns)'])
quick_sort = np.log(avg_df[' Quick Sort Time (ns)'])
select_time = np.log(avg_df[' Select Time (ns)'])
algorithm_map = [ 'Select k','Merge Sort', 'Quick Sort']
y_values = pd.factorize(algorithm_map)[0]
fig = plt.figure(figsize=(10, 7))
ax = fig.add_subplot(111, projection='3d')
x, y = np.meshgrid(data_size, y_values)
z = np.array([ select_time, merge_sort,quick_sort])
xpos, ypos = np.meshgrid(data_size, y_values)
xpos = xpos.flatten()
ypos = ypos.flatten()
dx = 1.7*1.1
dy = 0.4*1.1
dz = z.flatten()
ax.bar3d(xpos, ypos, np.zeros_like(dz), dx, dy, dz, zsort='average', color=plt.cm.viridis(dz / max(dz)))
ax.set_xlabel('Data Size')
# ax.set_ylabel('Algorithm')
ax.set_zlabel('log(Time) (ns)')
ax.set_title('Average Time of Different Algorithms')
ax.set_yticks([0, 1, 2])
ax.set_yticklabels(algorithm_map)
plt.savefig("./img/figure2.png",dpi=500)
plt.show()