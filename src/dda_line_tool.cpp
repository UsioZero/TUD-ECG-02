//
// This source code is property of the Computer Graphics and Visualization 
// chair of the TU Dresden. Do not distribute in modified or unmodified form! 
// Copyright (C) 2016 CGV TU Dresden - All Rights Reserved
//
#include "dda_line_tool.h"
#include <algorithm>
#include <iostream>


// Initialize the tool and store a reference of a canvas_buffer
dda_line_tool::dda_line_tool(canvas_buffer& canvas): tool_base(canvas)
{
	shape = TS_LINE;
}




// Draw a line from (x0, y0) to (x1, y1)
void dda_line_tool::draw(int x0, int y0, int x1, int y1)
{
	/************
	Task 3.1.1.    Implement the DDA algorithm to raster a line from (x0, y0)
	               to (x1, y1). To set a pixel use "canvas.set_pixel(x, y)" where
				   "x" and "y" is the desired pixel position. This method 
				   handles border violations. Establish the standard case in the
				   first step. If you need to swap the value of two variables you
				   can use the method "std::swap(a, b)".
	Aufgabe 3.1.1. Implementieren Sie den DDA-Algorithmus um eine Linie von
	               (x0, y0) nach (x1, y1) zu rastern. Verwenden Sie
				   "canvas.set_pixel(x, y)" um einen Pixel zu setzen, wobei
				   "x" und "y" den gewünschten Pixelpositionen entsprechen.
				   Diese Methode behandelt auch Randverletzungen. Stellen Sie zunaechst
				   den Standardfall her. Falls Sie den Wert zweier Variablen vertauschen
				   muessen koennen Sie dafür die Methode "std::swap(a, b)" verwenden.
   *************/



	int dx = double(x1 - x0);
	double dy = double(y1 - y0);
	double m = dy / dx;
	std::cout << x0 << ":" << y0 << " " << x1 << ":" << y1 << "\n";
	//std::cout << m << "\n";

	if (abs(dx) < abs(dy)) {

		if (y0 > y1) {
			int tmp = x0;
			x0 = x1;
			x1 = tmp;
			tmp = y0;
			y0 = y1;
			y1 = tmp;
		}

		double x = x0;
		m = dx / dy;	

		for (int i = y0; i <= y1; i++) {

			canvas.set_pixel(round(x), i);

			x += m;
		}
	}
	else {

		if (x0 > x1) {
			int tmp = x0;
			x0 = x1;
			x1 = tmp;
			tmp = y0;
			y0 = y1;
			y1 = tmp;
		}

		double y = y0;

		for (int i = x0; i <= x1; i++) {

			canvas.set_pixel(i, round(y));

			y += m;
		}
	}


}




// Put debug output into the stream "stream" to be displayed in the
// main window
void dda_line_tool::set_text(std::stringstream& stream)
{
	stream<<"Tool: DDA-Line (click and drag mouse to draw)";
}