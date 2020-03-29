# stackJumpClone
This is a clone of the stack jump game.

### How to run:
(I will provide compiled binaries from release 1)

## How to compile:

> (Prevously I used CMake to build this project(see src/old/), but now I do that manually. I just want this project to be as simple as possible.)

### On linux:

### Some notes:
> - I would highly encourage you to follow the way described here : https://www.sfml-dev.org/tutorials/2.5/start-linux.php, I have almost copied the exact same steps, but in a shorter way, without explanations.
---

1. Get a c++ compiler(on Ubuntu/Ubuntu based distros : `sudo apt install build-essential`)
2. Get SFML binaries(or you may build from it's source) goto https://www.sfml-dev.org/download.php and download the appropriate file.
3. Extract `SFML-2.5.1-linux-gcc-64-bit.tar.gz`
4. Copy the contents of `SFML-2.5.1/lib/` to `/usr/lib`**(optional)**
5. Copy the extracted directory to `src` directory of this project.
6. `cd` to the project's `src` directory and issue this command : `g++ *.cpp -std=c++11 -I SFML-2.5.1/include/ -L SFML-2.5.1/lib/ -lsfml-graphics -lsfml-window -lsfml-system -o game`
7. If you have **not** followed the step 4, then issue this command to run the game : `export LD_LIBRARY_PATH=SFML-2.5.1/lib && ./game`(while inside the project's `src` directory), or else follow step 8.
8. Now to run this game issue this command : `./game`(while inside the project's `src` directory)


### On Windows:
https://www.sfml-dev.org/tutorials/2.5/start-vc.php<br>
> (They have explained most of the steps very well. I would highly encourage you to read it.)

### On macOS:
https://www.sfml-dev.org/tutorials/2.5/start-osx.php
> (They have explained most of the steps very well. I would highly encourage you to read it.)
