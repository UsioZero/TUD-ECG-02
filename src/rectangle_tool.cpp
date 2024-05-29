//
// This source code is property of the Computer Graphics and Visualization 
// chair of the TU Dresden. Do not distribute in modified or unmodified form! 
// Copyright (C) 2016 CGV TU Dresden - All Rights Reserved
//
#include "rectangle_tool.h"
#include <algorithm>
#include "dda_line_tool.h"


// Initialize the tool and store a reference of a canvas_buffer
rectangle_tool::rectangle_tool(canvas_buffer& canvas): tool_base(canvas)
{
	shape = TS_BOX;
}



// Draw a box from (x0, y0) to (x1, y1)
void rectangle_tool::draw(int x0, int y0, int x1, int y1)
{
	/************
	Additional task: Implement the rasterization of a rectangle that
	                 ranges from (x0, y0) to (x1, y1).
    Zusatzaufgabe:   Implementieren Sie die Rasterisierung eines
	                 Rechtecks, das von (x0, y0) nach (x1, y1) geht.
	*************/
	if (x0 > x1) {
		int tmp = x0;
		x0 = x1;
		x1 = tmp;
	}
	if (y0 > y1) {
		int tmp = y0;
		y0 = y1;
		y1 = tmp;
	}

	for (int i = x0; i <= x1; i++) {
		canvas.set_pixel(i, y0);
		canvas.set_pixel(i, y1);
	}

	for (int i = y0; i <= y1; i++) {
		canvas.set_pixel(x0, i);
		canvas.set_pixel(x1, i);
	}

}





// Put debug output into the stream "stream" to be displayed in the
// main window
void rectangle_tool::set_text(std::stringstream& stream)
{
	stream<<"Tool: Rectangle (click and drag mouse to draw)";
}