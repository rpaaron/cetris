# Cetris
A cool looking Tetris game.
Made with SDL and OpenGL.

![cetris-screen](https://cloud.githubusercontent.com/assets/11562617/7838328/90a18a94-048c-11e5-83d8-16f8ee7af7e9.png)

#### Depends: 
    g++
    cmake
    SDL         (1.2) 
    SDL_ttf     (1.2)
    SDL_Mixer   (1.2)
    OpenGL

## Compiling on Linux
Install the required dependencies; On Debian: <br>
```bash
sudo apt-get install g++ git cmake 
sudo apt-get install libsdl1.2-dev libsdl-ttf2.0-dev libsdl-mixer1.2-dev 
```
Get the sources:<br>
```bash
git clone https://github.com/cecco4/cetris.git
```
Make a build directory<br>
```bash
cd cetris
mkdir build
cd build
```
Configure<br>
```bash
cmake -DCMAKE_INSTALL_PREFIX=/usr .. 
```
Compile ("-j" option is available") <br>
```bash
make
```
Install (eventually)<br>
```bash
sudo make install
```
Play (if installed)<br>
```bash
cetris
```
from any directory or serch in your games menu.<br>
Play (if not installed)<br>
```bash
./cetris
```
