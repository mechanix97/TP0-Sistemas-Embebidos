#include "shape.h"
#include "rectangle.h"
#include <stdint.h>
#include <math.h>

#include <stdio.h>
#include <stdlib.h>


bool rectangle_ctor(rectangle_t *me, uint32_t position_x, uint32_t position_y, 
					uint32_t height, uint32_t width){
	if(!me){
		return false;
	}

	coordinates_array_t array;
	uint32_t len = height*2 + width*2 - 4;

	if((array.coordinates = (coordinate_t *) malloc(len*sizeof(coordinate_t))) == NULL){
		return false;
	}
	array.n_array = len;

	for(int i = 0; i < height; ++i){
		array.coordinates[i].x = 0 + position_x;
		array.coordinates[i].y = i + position_y;
		array.coordinates[i + height].x = width - 1 + position_x;
		array.coordinates[i + height].y = i + position_y;
	}

	for(int i = 1; i < width - 1; ++i){
		array.coordinates[i - 1 + 2*height].x = i + position_x;
		array.coordinates[i - 1 + 2*height].y = 0 + position_y;	
		array.coordinates[i - 1 + 2*height + width - 2].x = i + position_x;
		array.coordinates[i - 1 + 2*height + width - 2].y = height - 1 + position_y;
	}

	if(shape_ctor(&me->super, &array, position_x, position_y) != true){
		return false;
	} 
	free(array.coordinates);
	return true;
}


bool rectangle_rotate(rectangle_t *me, float angle){
	if(!me){
		return false;
	}
  	if(shape_rotate(&me->super, angle) != true){
  		return false;
  	}
  	return true;
}


uint32_t rectangle_get_area(rectangle_t *me){
	return me->height * me->width;
}

