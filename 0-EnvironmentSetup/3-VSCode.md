# VSCode Setup

> We assume WSL, VSCode and its WSL-Remote extension were already installed in the Windows host

1. [x] complete [Debian](/docs/01-Setup/1-Debian.md) setup
2. [x] install VSCode extensions
   1. [x] C/C++ (v1.13.9)
   2. [x] Code Runner (v0.11.8)
3. [x] Verify **GCC** compiler is installed — successful `gcc --version`
<!-- - ELSE: Settings > Run Code Configuration > (...) -->

## test

1. [x] Create working directory and C file
```bash
mkdir -p ~/foo/test && cd "$_"
touch helloWorld.c
```

2. [x] Write Hello World program!
```c
#include <stdio.h>

int main()
{ 
    printf("Hello World!\n");
    return 0;
}
```

3. [x] Compile and execute!!

```bash
gcc helloWorld.c -o helloWorld
./helloWorld
```