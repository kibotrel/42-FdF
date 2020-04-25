# 42-FdF

![42](/screenshots/42.png)

[![CodeFactor](https://www.codefactor.io/repository/github/kibotrel/42-fdf/badge)](https://www.codefactor.io/repository/github/kibotrel/42-fdf)

This project's goal is to make a wire-frame representation of a coordinate system. It was originally a **42School** using **Minilibx graphic library** but since **macOS X Mojave** came out and **OpenGL deprecation**, I decided to use [SDL2](https://www.libsdl.org/) to make it run under Linux as-well.

## Install

This project works both under **Ubuntu 18.04** and **macOS X 10.14.6** and should on any **Linux distribution** as-well but didn't tried out. It contains a submodule that you must initialize before running the program like so :

```shell
$> git clone --recurse-submodules https://github.com/kibotrel/42-FdF.git
$> cd 42-FdF && make
```

## Usage
### Run the program

Once the program is compiled, run it with the following command line :
```shell
$> ./fdf 'map.fdf'
```
To get more informations on how the program works and how you can interact with it type :
```shell
$> ./fdf
```

### Controls

Keyboard :
* **Left / Right / Up / Down** Shift the displayed map by a fixed length in the desired direction
* **Q / W / A / D / X / C** Rotate the projected map along x, y and z axis
* **I / P** Switch between **Isometric** and **Parallel** projections
* **1 / 2 / 3** Change **Colorset**
* **Page_Up / Page_Down** Modify **Heigh Value** along projected z axis
* **9 / 0** **Zoom-in** or **Zoom-out**
* **R** Reset everything to the default point of view
* **H** Toggle HUD
* **Escape** Quit the visualizer

## Error management

Each following error is handled by the program leading to a complete memory free and program exit :
* Failed memory allocation (*ERROR-CODE 1*)
* Invalid read (*ERROR-CODE 2*)
* Invalid close (*ERROR-CODE 3*)
* Invalid filename (*ERROR-CODE 4*)
* Invalid map width (*ERROR-CODE 5*)
* Missing point(s) in a row (*ERROR-CODE 6*)
* Empty row (*ERROR-CODE 7*)
* Invalid map format (*ERROR-CODE 8*)
* Empty file (*ERROR-CODE 9*)
* Failed to initialize connection with SDL2 API (*ERROR-CODE 10*)
* Unable to create a SDL Window context (*ERROR-CODE 11*)
* Can't get the SDL Window surface (*ERROR-CODE 12*)
* Failed to initialize connection with SDL2_TTF API (*ERROR-CODE 13*)
* Can't load the given police file (*ERROR-CODE 14*)
* Failed to update the screen state (*ERROR-CODE 15*)
* Unable to process the requested SDL2_TTF string(*ERROR-CODE 16*)
* Failed to apply the requested SDL2_TTF generated text on the SDL window surface(*ERROR-CODE 17*)

Whenever one of these error occurs, the correct error message is displayed on the **standard output** and the whole program return an error code that you can retrieve by running :
```shell
$> echo $?
```

## Screenshots
*( Note : These screenshots were taken when the program used Minilibx before the code revamp to use SDL2, I changed a lot of thing during the process so HUD controls might be incorrect, don't pay attention to that, I might take new ones someday)*
![Europe](/screenshots/Europe.png)
![Andes](/screenshots/Andes.png)
![Venus](/screenshots/Venus.png)
![France](/screenshots/France.png)
![Red_Sea](/screenshots/Red_Sea.png)
