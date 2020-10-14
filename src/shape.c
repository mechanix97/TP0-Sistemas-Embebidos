#include <stdlib.h>
#include <math.h>

#include <stdio.h>

#include "shape.h"
#include "image.h"

#define PI 3.141592654

bool shape_ctor(shape_t *me, coordinates_array_t *array, uint32_t position_x, uint32_t position_y){
	if(!me){
		return false;
	}

	me->position.x = position_x;
	me->position.y = position_y;

	size_t len = array->n_array;

	if((me->array.coordinates = (coordinate_t *)malloc(len*sizeof(coordinate_t))) == NULL){
		return false;
	}

	me->array.n_array = len;

	for(int i = 0; i < len; i++){
		me->array.coordinates[i] = array->coordinates[i];
	}

	return true;
}

void shape_dtor(shape_t *me){
	if(!me){
		return;
	}

	free(me->array.coordinates);
}

bool shape_move(shape_t *me, uint32_t dx, uint32_t dy){
	if(!me){
		return false;
	}

	me->position.x += dx;
	me->position.y += dy;

	return true;
}

bool shape_rotate(shape_t *me, float angle){
	if(!me){
		return false;
	}
	size_t len = me->array.n_array;

	for(int i = 0; i < len; ++i){
		me->array.coordinates[i] = coordinate_rotate(me->array.coordinates[i], me->position, angle);	
	}
	return true;
}

float shape_distance_from(shape_t *me, shape_t *shape){
	if(!me || !shape){
		return -1;
	}

	uint32_t x1 = me->position.x;
	uint32_t y1 = me->position.y;

	uint32_t x2 = shape->position.x;
	uint32_t y2 = shape->position.y;	

	return sqrt( pow(x1-x2,2) + pow(y1-y2,2) );
}

bool shape_plot(shape_t *me, image_t *image){
	if(!me || !image){
		return false;
	}
	size_t len = me->array.n_array;

	uint32_t origin_x =  me->position.x;
	uint32_t origin_y =  me->position.y;

	for(int i = 0; i < len; ++i){
		uint32_t x = me->array.coordinates[i].x + origin_x;
		uint32_t y = me->array.coordinates[i].y + origin_y;
		image_write(image, x, y, HIGH);

	}

	return true;
}

bool shape_scale(shape_t *me, float factor){
	if(!me){
		return false;
	}
	size_t len = me->array.n_array;

	for(int i = 0; i < len; ++i){
		me->array.coordinates[i].x = round(me->array.coordinates[i].x * factor);
		me->array.coordinates[i].y = round(me->array.coordinates[i].y * factor);
	}
	return true;
}

coordinate_t coordinate_rotate(coordinate_t position, coordinate_t center, float angle){
	float arg = (angle * PI) / 180;

	float s = sin(arg);
	float c = cos(arg);

	uint32_t x1 = position.x;
	uint32_t y1 = position.y;

	uint32_t origin_x = center.x;
	uint32_t origin_y = center.y;

	x1 -= origin_x;
	y1 -= origin_y;

	double xnew = x1 * c - y1 * s;
	double ynew = x1 * s + y1 * c;

	coordinate_t r = {round(xnew) + origin_x, round(ynew) + origin_y};

	return r;
}
