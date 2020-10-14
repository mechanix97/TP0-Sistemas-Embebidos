
#include <stdio.h>
#include "image.h"

#include "rectangle.h"
#include "line.h"



#define MAX_IMG_NAME	20

#define N_ROWS			200 	// Cantidad de filas
#define N_COLS			200		// Cantidad de columnas


/* Ejemplo de uso de las funciones de la clase "imagen" */

int main(void){
	
	image_t img;
	int img_count=0;
	char img_name[MAX_IMG_NAME];

	line_t line1;
	line_t line2;
	rectangle_t rect;

	double angle1 = 180;
	double angle2 = 180;

	rectangle_ctor(&rect,20,20,160,160);

	for(int i=0; i<90; ++i){
		

		line_ctor(&line1, 100, 100, 200, 100);
		line_ctor(&line2, 100, 100, 200, 100);

		// Construyo el objeto "imagen"
		image_ctor(&img,N_ROWS,N_COLS); 

		// Lo modifico como yo quiera
		/*for(int i=0; i<l; i++){
			image_write(&img,i,i,HIGH); 
		}*/
		line_rotate(&line1, angle1);
		line_scale(&line1,0.5);
		shape_plot(&line1.super, &img);
		angle1-=4;

		line_rotate(&line2, angle2);
		line_scale(&line2,0.75);
		shape_plot(&line2.super, &img);		
		angle2-=144;
		
		shape_plot(&rect.super, &img);		
		
		// Lo guardo en un archivo
		sprintf(img_name,"./images/img%.3d.pbm",img_count); 
		image_to_file(&img,img_name); 
		
		// Libero memoria
		image_dtor(&img); 
		shape_dtor(&line1.super);
		shape_dtor(&line2.super);

		++img_count;
	}

	shape_dtor(&rect.super);
	
	return 0;
}