# stackJumpClone
This is a clone of the stack jump game.

### Note : I haven't included "resources" directory which is extremely necessary to run this game, not including this due to it's size. You can add an issue about it if you want that directory.

### How to run:
(I will provide compiled binaries from release 1)

## How to compile:
### On linux:

### Some notes:
> - Prevously I used `CMake` to build this project(see [`src/old/`](https://github.com/dev-moss/stackJumpClone/tree/master/src/old)), but now I do that manually. I just want this project to be as simple as possible.<br>
> - (I know there are many other ways to build a cpp project, but I am listing just one of them.)

---

1. Get a c++ compiler(on Ubuntu/Ubuntu based distros : `sudo apt install build-essential`)
2. Get SFML binaries(or you may build from it's source) goto https://www.sfml-dev.org/download.php and download the appropriate file.
3. Extract `SFML-2.5.1-linux-gcc-64-bit.tar.gz`(Yes I have tested the version 2.5.1, on a 64-bit linux)
4. Copy the contents of `SFML-2.5.1/lib/' to '/usr/lib'
5. Copy the extracted directory to 'src' directory of this project.
6. `cd` to the project's `src` directory and issue this command : `g++ stack-jump.cpp -I SFML-2.5.1/include/ -L SFML-2.5.1/lib/ -lsfml-graphics -lsfml-window -lsfml-system -o game`
7. Now to run this game issue this command : `./game`


### On Windows:
```
(TODO)
```
