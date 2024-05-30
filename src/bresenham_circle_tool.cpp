//
// This source code is property of the Computer Graphics and Visualization 
// chair of the TU Dresden. Do not distribute in modified or unmodified form! 
// Copyright (C) 2016 CGV TU Dresden - All Rights Reserved
//
#include "bresenham_circle_tool.h"
#include <algorithm>
#include <math.h>

// Initialize the tool and store a reference of a canvas_buffer
bresenham_circle_tool::bresenham_circle_tool(canvas_buffer& canvas): tool_base(canvas)
{
	// This tool draws circles!
	shape = TS_CIRCLE;
}



// Draw a circle with center (x0, y0) and (x1, y1) on the circle
void bresenham_circle_tool::draw(int x0, int y0, int x1, int y1)
{
	// Calculate the radius
	int r = static_cast<int>(sqrt(static_cast<double>((x0-x1)*(x0-x1) + (y0-y1)*(y0-y1))));

	/************
	Additional task: Implement circle rasterization using the bresenham algorithm.
	                 The circle shall have its center at (x0, y0) with a
					 radius of "r".
    Zusatzaufgabe:   Implementieren Sie die Rasterisierung eines Kreises mit dem
	                 Bresenham-Algorithmus. Der Kreis soll seinen Mittelpunkt bei
					 (x0, y0) und einen Radius von "r" haben.
	*************/

    int x = 0;
    int y = r;
    int decision = 1 - r;; // Initial decision parameter

    // Draw the initial points
    auto draw_circle_points = [&](int xc, int yc, int x, int y) {
        canvas.set_pixel(xc + x, yc + y);
        canvas.set_pixel(xc - x, yc + y);
        canvas.set_pixel(xc + x, yc - y);
        canvas.set_pixel(xc - x, yc - y);
        canvas.set_pixel(xc + y, yc + x);
        canvas.set_pixel(xc - y, yc + x);
        canvas.set_pixel(xc + y, yc - x);
        canvas.set_pixel(xc - y, yc - x);
        };

    draw_circle_points(x0, y0, x, y);

    while (y >= x) {
        x++;

        // Check if the decision parameter needs to be updated
        if (decision > 0) {
            y--;
            decision = decision + 4 * (x - y) + 10;
        }
        else {
            decision = decision + 4 * x + 6;
        }

        draw_circle_points(x0, y0, x, y);
    }

}



// Put debug output into the stream "stream" to be displayed in the
// main window
void bresenham_circle_tool::set_text(std::stringstream& stream)
{
	stream<<"Tool: Bresenham-Circle (click and drag mouse to draw)";
}