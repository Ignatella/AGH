#pragma once

#include "main.h"
#include "shape.h"

/**
 * @brief Rysuje objekt
 * 
 * @param d 
 */
void draw(const Drawable *d)
{
    d->draw();
};