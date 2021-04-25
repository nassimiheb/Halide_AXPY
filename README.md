# Halide_AXPY
This project is an implentation of the level 1 BLAS routine; called "axpy" ( "a x plus y")

## Halide Installation
### Acquiring LLVM

<pre>

    cmake -DCMAKE_BUILD_TYPE=Release \ 
    
    -DLLVM_ENABLE_PROJECTS="clang;lld;clang-tools-extra" \        
    
    -DLLVM_TARGETS_TO_BUILD="X86;ARM;NVPTX;AArch64;Mips;Hexagon" \        
    
    -DLLVM_ENABLE_TERMINFO=OFF -DLLVM_ENABLE_ASSERTIONS=ON \        
    
    -DLLVM_ENABLE_EH=ON -DLLVM_ENABLE_RTTI=ON -DLLVM_BUILD_32_BITS=OFF \        
    
    -S llvm-project/llvm -B llvm-build 
</pre>


Building LLVM : 

```cmake --build llvm-build```

Installing LLVM :

```cmake --install llvm-build --prefix llvm-install```

Pointing to Halide :

```export LLVM_ROOT=$PWD/llvm-installexport LLVM_CONFIG=$LLVM_ROOT/bin/llvm-config```

### Building Halide
   <pre> 
            git clone https:/github.com/halide/Halide.git    
            cd halide    
            make -j8
    </pre>
## Running the script 

Change the permission of the `./script.sh`:

```chmod +x script.sh```

Run the script :

```./script.sh```
    
if in Windows change the cmp instruction to FC. The results are saved in the files `results_H.txt` and `results_C.txt`.The cmp instruction compare between the two files and return void if the two files are identical. 
