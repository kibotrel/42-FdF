# 42-FdF

*Screenshot there soon™*

This project's goal is to make a wireframe representation of a terrain

## Install

Only works on **42-Paris Dumps** at the moment but should be portable on any **macOS X** in the near future.

Simply type command bellow in your shell :
```
$> make
```

## Usage
### Run the program

Once the program is compiled, run it with the following command line :
```
$> ./fdf 'map.fdf'
```
To get more informations on how the program works and how you can interact with it type :
```
$> ./fdf
```

### Controls

Keyboard :
* **W / A / S / D** Shift the displayed map by a fixed length in the desired direction
* **2 / 3 / 4 / 6 / 7 / 8** Rotate the projected map along x, y and z axis
* **I / P** Switch between **Isometric** and **Parallel** projections
* **Z / X / C** Change **Colorset**
* **Page_Up / Page_Down** Modify **Heigh Value** along projected z axis
* **R** Reset everything to the default point of view
* **H** Toggle HUD
* **ESC** Quit the visualizer

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

Whenever one of these error occurs, the correct error message is displayed on the **standard output** and the whole program return an error code that you can retrieve by running :
```
$> echo $?
```

## Screenshots
*Needs to add them soon™*
