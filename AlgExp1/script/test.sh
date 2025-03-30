#!/bin/bash
# 测试脚本：依次使用不同数据文件进行测试
for file in Project/data/*.txt; do
    echo "正在测试数据文件：$file"
    ./main < "$file"
    echo "---------------------------------"
done