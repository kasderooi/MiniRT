# MiniRT

MiniRT is a small Ray Tracer program. The first big C program I did at codam.

## Project description

### The MiniRT program takes an input file formatten as "*.rt" in which shapes are defined as follow's:  
> ***Size of the map***	= R	x-axis y-axis;  
***Ambient light***		= A	brightness RGB-color;  
***camera***          = c	position_vector	orientation_vector  FieldOfView;  
***light spot***      = l	position_vector	brightness  RGB-Color;  
***shape sphere***    = sp	position_vector	size	RGB-color;  
***shape triangle***  = tr	position_point1 position_point2 position_point3 RGB-color;  
***shape plane***     = pl	position_vector	norm_vector	RGB-color;  
***shape cylinder***  = cy 	position_vector norm_vector diameter height RGB-color;  
***shape square***    = sq	position_vector norm_vector size RGB-color;  
  
> ***x-axis***          			= integer;  
***y-axis***          			= integer;  
***brightness***      			= float between 0 and 1;  
***orientation_vector***		= signed floats between -1 and 1 formatted as x,y,z;  
***FieldOfView***						=	integer in degrees between 0 and 180;  
***RGB-color***       			= integer between 0 and 255 formatted as R,G,B;  
***position_vector*** 			= signed integers formatted as x,y,z;  
***norm_vector***						=	signed integers formatted as x,y,z;  
***size/diameter/height***	= integer;  

## How to use
> Execute the following commands:

```shell
git clone https://github.com/kasderooi/MiniRT.git
cd MiniRT
make run
```

> the program wil use test.rt as a default map, making changes to that map or directing the makefile to a different rt file will change the output
