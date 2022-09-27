# `Fdf`

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/iflis7/fdf?color=lightblue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/iflis7/fdf?color=critical" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/iflis7/fdf?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/iflis7/fdf?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/iflis7/fdf?color=green" />
</p>

This project is about representing a landscape as a 3D object
in which all surfaces are outlined in lines. `Version: 2`.<br>
You can read the subject: [`fdf_subject.pdf`](subject/fdf_subject.pdf)

## Discription of mandatory part

This project is about creating a simple wireframe model representation of a 3D landscape by linking various points (x, y, z) thanks to line segments (edges).
Your project must comply with the following rules:
* You must use the MiniLibX. Either the version available on the school machines, or installing it using its sources.
* You have to turn in a Makefile which will compile your source files. It must not relink.
* Global variables are forbidden.

### Rendering

* Your program has to represent the model in isometric projection.

• Each number represents a point in space:
    * The horizontal position corresponds to its axis.
    * The vertical position corresponds to its ordinate.
    * The value corresponds to its altitude.

### Graphic management

* Your program has to display the image in a window.
* The management of your window must remain smooth (changing to another window, minimizing, and so forth).
* Pressing ESC must close the window and quit the program in a clean way.
* Clicking on the cross on the window’s frame must close the window and quit the program in a clean way.
* The use of the images of the MiniLibX is mandatory.

## Bonus part

You are allowed to use other functions to complete the bonus part as long as their
use is justified during your evaluation. Be smart!
You will get some extra points if you can:
* Include one extra projection (such as parallel or conic)!
* Zoom in and out.
* Translate your model.
* Rotate your model.
* Add one more bonus of your choice.

All errors like: wrong commands,  permission to files and etc, need be handle.

[![hsaadi's 42 FdF Score](https://badge42.vercel.app/api/v2/cl5s2p211013909jutf782quk/project/2618288)](https://github.com/JaeSeoKim/badge42)
