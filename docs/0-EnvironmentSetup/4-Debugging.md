# Launch.Json - Debug & Run

> As we start the SECTION-02 we feel itchy about the lack of feedback from the machine/IDE when it comes to debugging and compiling our C code, ie. building and running.


1. [x] read documentation
   1. @VSCodeDocs: [Using C++ and WSL in VS Code](https://code.visualstudio.com/docs/cpp/config-wsl)
   2. @VSCodeDocs: [Configure C/C++ debugging](https://code.visualstudio.com/docs/cpp/launch-json-reference)

- [x] install compiling tools to use in VSCode

```bash
# Install build-essential and gdb
sudo apt update
sudo apt install build-essential gdb
code .
```

- [X] TEST SUCCESSFULLY:

1. Open `file.c` in VSCode; click on **Debug**
2. Select the following
```markdown
C/C++: gcc-11 build and debug active file (compiler: usr/bin/gcc-11)'
```
3. New file `tasks.json` created under new directory `.vscode`
4. Now manage to create `launch.json` with Configuration: "Launch"
5. Eventually, manage to use the **Debugging Interface** and receive relevant **Build Information**