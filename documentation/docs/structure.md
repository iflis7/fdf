## Code Structure
The code is structured in a functional way. Like it's explained down here ↓

### Structs
``` 
t_project 0 or 1 managing the type of projection. 

typedef enum
{
	ISO,
	PARALLEL
}					t_project;
```
``` 
t_val is used as a stack to store evey z value and the color that goes with it when given in a map. 

typedef struct s_val
{
	int				z;
	int				color;
	struct s_val	*next;
}					t_val;
```
``` 
t_pnt is used to store evey coordinate (x y z) and the color that goes with it when given in a map. 

typedef struct s_pnt
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_pnt;
```
``` 
t_map grouping every variable needed to handle the map.

- Width and height to manage and check if the lines are equal.
- Z_min, z_max and z_range to mange the z coordinate.
- *val_arr to store the coordinates once poped from the stack.
- *color_arr to store the color when given by a map.

typedef struct s_map
{
	int				width;
	int				height;
	int				z_min;
	int				z_max;
	int				z_range;
	int				*val_arr;
	int				*color_arr;
}					t_map;
```
### Main

