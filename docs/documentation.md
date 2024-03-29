# Custom Documentation

<details>
<summary>Table of Contents</summary>

- [Custom Documentation](#custom-documentation)
  - [S0 - Environment Setup](#s0---environment-setup)
    - [Debugging features ](#debugging-features-)
    - [Columns as in vim](#columns-as-in-vim)
  - [S1 - C Basics](#s1---c-basics)
    - [`%c`](#c)
  - [S2 Variables](#s2-variables)
    - [`double` vs `float`](#double-vs-float)
    - [`%f` vs `%lf` ](#f-vs-lf-)
- [Misc.](#misc)

</details>

## S0 - Environment Setup

### Debugging features <!--CWD-->

- @StackOverflow: [VSCode -- how to set working directory for debugging a Python program](https://stackoverflow.com/questions/38623138/vscode-how-to-set-working-directory-for-debugging-a-python-program)

> In `launch.json`, specify a dynamic working directory (i.e. the directory where the currently-open Python file is located) using:

```json
"cwd": "${fileDirname}"
```
> This takes advantage of the ["variables reference" feature in VS Code](https://code.visualstudio.com/docs/editor/variables-reference#_settings-command-variables-and-input-variables), and the predefined variable `fileDirname`.
> 
> If you're using the `Python: Current File (Integrated Terminal)` option when you run Python, your `launch.json` file might look like mine, below ([more info on launch.json files here](https://code.visualstudio.com/docs/editor/debugging#_launch-configurations)).

```json
{
    "version": "0.2.0",
    "configurations": [
    {
            "name": "Python: Current File (Integrated Terminal)",
            "type": "python",
            "request": "launch",
            "program": "${file}",
            "console": "integratedTerminal",
            "cwd": "${fileDirname}"
    }, 

    //... other settings, but I modified the "Current File" setting above ...
}
```

> [Remember the `launch.json` file controls the run/debug settings of your Visual Studio code project](https://code.visualstudio.com/docs/editor/debugging#_launch-versus-attach-configurations); my `launch.json` file was auto-generated by VS Code, in the directory of my current "Open Project". I just edited the file manually to add `"cwd": "${fileDirname}"` as shown above.
> 
> ...
> 
> If you don't have a `launch.json` file, [try this](https://code.visualstudio.com/docs/editor/debugging#_launch-configurations):
>
> ...
>
> 
> > "When I clicked on the Debug button on my navigation panel it said "To customise Run and Debug create a `launch.json` file." Clicking on "create..." opened a dialog asking what language I was debugging. In my case I selected Python"


### Columns as in vim

> edit `settings.json` to `"editor.rulers": [80,120]` ([documentation](https://stackoverflow.com/questions/29968499/vertical-rulers-in-visual-studio-code))


## S1 - C Basics

### `%c`

- @StackOverflow: [Why is %c used in C?](https://stackoverflow.com/questions/10947965/why-is-c-used-in-c)


```c
#include <stdio.h>

int main(){
    
    printf("Year: %d \nWeek: %.2d \nDay: %c \n\n", 2023, 2, 'W');

    // (https://stackoverflow.com/questions/10947965/why-is-c-used-in-c)
    // Because %d will print the numeric character code of the char,
    printf("%d \n", 'a');       //prints 97 (on an ASCII system), while
    printf("%c \n\n", 'a');       // prints a.

    return 0;
}
```


## S2 Variables

### `double` vs `float`

- @StackExchange: [When do you use float and when do you use double](https://softwareengineering.stackexchange.com/questions/188721/when-do-you-use-float-and-when-do-you-use-double)

> The default choice for a floating-point type should be `double`. This is also the type that you get with floating-point literals without a suffix or (in C) standard functions that operate on floating point numbers (e.g. `exp`, `sin`, etc.).
> 
> `float` should only be used if you need to operate on a lot of floating-point numbers (think in the order of thousands or more) and analysis of the algorithm has shown that the reduced range and accuracy don't pose a problem.
> 
> `long double` can be used if you need more range or accuracy than `double`, and if it provides this on your target platform.
> 
> In summary, `float` and `long double` should be reserved for use by the specialists, with `double` for "every-day" use.


### `%f` vs `%lf` <!--long float?-->

- [What is Double in C?](https://www.scaler.com/topics/double-in-c/)

> A `double` in C can be printed by both using `%f` and `%lf`. **Both** the `%f` format specifier and the `%lf` format specifier represent `float` and `double`. The `printf()` in C treats both `float` and `double` the same.

- @StackOverflow: [Why does scanf() need "%lf" for doubles, when printf() is okay with just "%f"?](https://stackoverflow.com/questions/210590/why-does-scanf-need-lf-for-doubles-when-printf-is-okay-with-just-f)

> Because C will promote floats to doubles for functions that take variable arguments. Pointers aren't promoted to anything, so you should be using `%lf`, `%lg` or `%le` (or `%la` in C99) to read in doubles.

> Since С99 the matching between format specifiers and floating-point argument types in C is consistent between `printf` and `scanf`. It is
> - `%f` for `float`
> - `%lf` for `double`
> - `%Lf` for `long double`
> 
> It just so happens that when arguments of type `float` are passed as variadic parameters, such arguments are implicitly converted to type `double`. This is the reason why in `printf` format specifiers `%f` and `%lf` are equivalent and interchangeable. In `printf` you can "cross-use" `%lf` with `float` or `%f` with `double`.
> 
> But there's no reason to actually do it in practice. Don't use `%f` to `printf` arguments of type `double`. It is a widespread habit born back in C89/90 times, but it is a bad habit. Use `%lf` in `printf` for `double` and keep `%f` reserved for `float` arguments.





# Misc.

documentation
- @DavesGarage: [Stupid C Tricks: Unsafe Functions You MUST Avoid!](https://youtu.be/Qyn1qxi73u8&ab_channel=Dave%27sGarage)
- @StackOverflow: [Best practices: Where should function comments go in C/C++ code?](https://stackoverflow.com/questions/1849991/best-practices-where-should-function-comments-go-in-c-c-code)