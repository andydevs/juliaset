//-----------------------------------------------------------------------------------
// Program: JuliaSet
// 
// Generates Julia set images
//
// Author:  Anshul Kharbanda
// Created: 8 - 14 - 2016
//-----------------------------------------------------------------------------------

// Headers being used
#include "JuliaSet/colormap.h"

/**
 * Creates an empty ColorRGB
 */
ColorRGB::ColorRGB():
red(0), 
green(0), 
blue(0) 
{}

/**
 * Creates a ColorRGB with the given red, green and blue values
 *
 * @param r the red value
 * @param g the green value
 * @param b the blue value
 */
ColorRGB::ColorRGB(short r, short g, short b):
red(r), 
green(g), 
blue(b) 
{}

/**
 * Creates a ColorRGB with the given integer color value
 *
 * @param color an RGB color integer
 */
ColorRGB::ColorRGB(unsigned color):
red((color & 0xff0000) >> 16),
green((color & 0x00ff00) >> 8),
blue((color & 0x0000ff))
{}

/**
 * Returns the result of the color shifted by the given gradient value
 *
 * @param other the gradient to shift the color by
 */
ColorRGB ColorRGB::operator+(ColorGradientRGB other) const
{
	return ColorRGB(
		(short)(red + other.red),
		(short)(green + other.green),
		(short)(blue + other.blue)
	);
}

/**
 * Creates an empty ColorGradientRGB
 */
ColorGradientRGB::ColorGradientRGB():
red(0),
green(0),
blue(0)
{}

/**
 * Creates a ColorGradientRGB with the given red, green and blue values
 *
 * @param r the red value
 * @param g the green value
 * @param b the blue value
 */
ColorGradientRGB::ColorGradientRGB(double r, double g, double b):
red(r),
green(g),
blue(b)
{}

/**
 * Computes the ColorGradientRGB between the given start and end colors
 *
 * @param start the start color
 * @param end   the end color
 */
ColorGradientRGB::ColorGradientRGB(ColorRGB first, ColorRGB last)
{
	red   = (last.red   - first.red)   / 256.0;
	green = (last.green - first.green) / 256.0;
	blue  = (last.blue  - first.blue)  / 256.0;

}

/**
 * Computes the gradient value at the given point in the space
 *
 * @param point the point in the gradient space
 */
ColorGradientRGB ColorGradientRGB::operator*(unsigned iterations) const
{
	return ColorGradientRGB(
		red*iterations,
		green*iterations,
		blue*iterations
	);
}

/**
 * Creates an empty ColorMapRGB
 */
ColorMapRGB::ColorMapRGB() {}

/**
 * Destroys the ColorMapRGB
 */
ColorMapRGB::~ColorMapRGB() {}

/**
 * Creates a GradientMapRGB between the two given colors
 *
 * @param start the start color
 * @param end   the end color
 */
GradientMapRGB::GradientMapRGB(unsigned start, unsigned end):
ColorMapRGB(),
m_start(start),
m_gradient(start, end)
{}

/**
 * Destroys the GradientMapRGB
 */
GradientMapRGB::~GradientMapRGB() {}

/**
 * Maps the given number of iterations to a given color
 *
 * @param iterations the iterations being mapped
 *
 * @return the color calculated from the iterations
 */
ColorRGB GradientMapRGB::color(unsigned iterations) const
{
	return m_start + m_gradient*iterations;
}