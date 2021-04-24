
read -p "Path to the Halide folder : " path
#Compiling the halide program
g++ ./program_axpy.cpp -g -L ${path}/build/src -I ${path}/build/include -lHalide -ldl -lpthread -std=c++11 -o ./exec/program_halide
#Running the halide program 
LD_LIBRARY_PATH=${path}/build/src ./exec/program_halide
#Compiling the C program
gcc ./program_axpy.c -o ./exec/program_c
#Running the C program 
./exec/program_c
#Comparing the two result files
cmp ./results_H.txt ./results_C.txt


