#!/bin/bash
# 编译所有算法源文件并生成可执行文件 main
g++ -std=c++11 -O2 Project/algorithm/*.cpp -o main
if [ $? -eq 0 ]; then
    echo "编译成功，生成可执行文件 main"
else
    echo "编译失败，请检查代码"
fi
