#ifndef LINE_H
#define LINE_H 

#include "shape.h"
#include <stdint.h>

/* Estructura principal que representa la clase "línea" */
typedef struct {
	shape_t super;			// Clase de la cual se hereda
	coordinate_t start;		// Coordenada de origen
	coordinate_t end;		// Coordenada de final
} line_t;


/** 	@brief: Contructor del objeto "línea"
*		@params: recibe el puntero al objeto y las coordenadas para definir el segmento de línea.
*		@return: Devuelve verdadero sii encontró memoria para guardar el objeto.
**/
bool line_ctor(line_t *me, uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2);


/** 	@brief: Rotar al segmento dejando fijo el punto de partida.
*		@params: recibe el puntero al objeto y el ángulo a rotar
*		@return: Devuelve verdadero si se realizó con éxito la operación
**/
bool line_rotate(line_t *me, float angle);


/** 	@brief: Escala al segmento por un factor, dejando fijo el punto de partida.
*		@params: recibe el puntero al objeto y el ángulo a rotar
*		@return: Devuelve verdadero si se realizó con éxito la operación
**/
bool line_scale(line_t *me, float factor);


/** 	@brief: Calcula la longitud del segmento.
*		@params: recibe el puntero al objeto.
*		@return: Devuelve la longitud del segmento.
**/
float line_get_lenght(line_t *me);

#endif