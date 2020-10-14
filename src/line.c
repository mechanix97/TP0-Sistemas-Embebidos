#include "shape.h"
#include "line.h"
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#include <stdio.h>


bool line_ctor(line_t *me, uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2){
	if(!me){
		return false;
	}

	coordinates_array_t array;

	me->start.x = x1;
	me->start.y = y1;

	me->end.x = x2;
	me->end.y = y2;

	if(x1 == x2){
		int len = abs(y2-y1) + 1;
		if((array.coordinates = (coordinate_t *)malloc(len*sizeof(coordinate_t))) == NULL){
			return false;
		}
		array.n_array = len;
		for(int i = 0; i < len; i++){
			if(y2 > y1){
				array.coordinates[i].x = x1;
				array.coordinates[i].y = y1 + i;
			} else{
				array.coordinates[i].x = x1;
				array.coordinates[i].y = y2 + i;
			}
		}
	} else {
		float m = ((float)y1 - (float)y2) / ((float)x1 - (float)x2);
		float b = (float)y1 - m * (float) x1;	

		int len = abs(x2-x1)+1;

		if((array.coordinates = (coordinate_t *) malloc(len*sizeof(coordinate_t))) == NULL){
			return false;
		}
		array.n_array = len;
		for(int i = 0; i < len; i++){
			if(x2 > x1){
				uint32_t aux_x = x1+i;
				uint32_t aux_y = m * aux_x + b;
				array.coordinates[i].x = aux_x;
				array.coordinates[i].y = aux_y;
			} else { //x1 > x2
				uint32_t aux_x = x1-i;
				uint32_t aux_y = m * aux_x + b;
				array.coordinates[i].x = aux_x;
				array.coordinates[i].y = aux_y;

			} 				
		}
	}
	if(shape_ctor(&me->super, &array, x1, y1) != true){
		return false;
	} 
	free(array.coordinates);
	return true;
	//falta agregar puntos si abs(y2-y1) >> abs(x2-x1)
}


bool line_rotate(line_t *me, float angle){
  	if(shape_rotate(&me->super, angle) != true){
  		return false;
  	}
  	me->end = coordinate_rotate(me->end, me->start, angle);
  	return true;
}


bool line_scale(line_t *me, float factor){
	if(shape_scale(&me->super, factor) != true){
		return false;
	}

	me->start.x = round(me->start.x*factor);
	me->start.y = round(me->start.y*factor);
	me->end.x = round(me->end.x*factor);
	me->end.y = round(me->end.y*factor);
	return true;
}


float line_get_lenght(line_t *me){
	uint32_t x1 = me->start.x;
	uint32_t y1 = me->start.y;

	uint32_t x2 = me->end.x;
	uint32_t y2 = me->end.y;

	return sqrt( pow(x1-x2,2) + pow(y1-y2,2) );
}
