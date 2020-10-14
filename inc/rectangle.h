#ifndef RECTANGLE_H
#define RECTANGLE_H 

#include "shape.h"
#include <stdint.h>

/* Estructura principal que representa la clase "rectángulo" */
typedef struct {
	shape_t super; 			// Clase de la cual se hereda
	uint32_t height;		// Altura del rectángulo
	uint32_t width;			// Ancho del rectángulo
	float rotation_angle;	// Ángulo en el cual se encuentra rotada la figura
} rectangle_t;


/** 	@brief: Contructor del objeto "rectángulo"
*		@params: recibe el puntero al objeto, la posición en el espacio (posición en x e y), la altura y el ancho del rectángulo
*		@return: Devuelve verdadero sii encontró memoria para guardar el objeto.
**/
bool rectangle_ctor(rectangle_t *me, uint32_t position_x, uint32_t position_y, 
					uint32_t height, uint32_t width);

/** 	@brief: Rota al rectángulo un cierto ángulo.
*		@params: recibe el puntero al objeto y el valor en radianes a rotar.
*		@return: Devuelve verdadero si la operación resultó exitosa.
**/
bool rectangle_rotate(rectangle_t *me, float angle);


/** 	@brief: Devuelve el área del rectángulo.
*		@params: recibe el puntero al objeto.
*		@return: Devuelve el valor del área.
**/
uint32_t rectangle_get_area(rectangle_t *me);


#endif