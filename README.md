# SDLProject
Try doing some game with SDL2

## Build Steps:
-In the project root dir, run following commands to build:
```bash
$>./install_dependency.sh
$>mkdir build

#for debug mode 
$>cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=ON .  

#for Release mode
$>cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=ON . 

$>cmake --build .
```
