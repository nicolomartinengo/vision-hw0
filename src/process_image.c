#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "image.h"

float get_pixel(image im, int x, int y, int c)
{
    // Clamp x to be within [0, im.w - 1]
    if (x < 0) x = 0;
    if (x >= im.w) x = im.w - 1;

    // Clamp y to be within [0, im.h - 1]
    if (y < 0) y = 0;
    if (y >= im.h) y = im.h - 1;

    // Clamp c to be within [0, im.c - 1]
    if (c < 0) c = 0;
    if (c >= im.c) c = im.c - 1;

    // Calculate 1D index for the pixel value
    int index = c * im.w * im.h + y * im.w + x;

    // Return the pixel value
    return im.data[index];
}

void set_pixel(image im, int x, int y, int c, float v)
{
    // Ignore if x, y, or c is out of bounds
    if (x < 0 || x >= im.w || y < 0 || y >= im.h || c < 0 || c >= im.c) {
        return;
    }

    // Calculate 1D index for the pixel value
    int index = c * im.w * im.h + y * im.w + x;

    // Set the pixel value
    im.data[index] = v;
}


image copy_image(image im)
{
    image copy = make_image(im.w, im.h, im.c);
    // TODO Fill this in
    return copy;
}

image rgb_to_grayscale(image im)
{
    assert(im.c == 3);
    image gray = make_image(im.w, im.h, 1);
    // TODO Fill this in
    return gray;
}

void shift_image(image im, int c, float v)
{
    // TODO Fill this in
}

void clamp_image(image im)
{
    // TODO Fill this in
}


// These might be handy
float three_way_max(float a, float b, float c)
{
    return (a > b) ? ( (a > c) ? a : c) : ( (b > c) ? b : c) ;
}

float three_way_min(float a, float b, float c)
{
    return (a < b) ? ( (a < c) ? a : c) : ( (b < c) ? b : c) ;
}

void rgb_to_hsv(image im)
{
    // TODO Fill this in
}

void hsv_to_rgb(image im)
{
    // TODO Fill this in
}
