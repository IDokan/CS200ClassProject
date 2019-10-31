/*
 * Rudy Castan
 * Graphics Library
 * CS230
 */
#pragma once
#include <Graphics/OpenGL/Image.hpp>

namespace Graphics
{
    Image capture_screenshot_of_back_buffer_to_image(int pixels_width, int pixels_height, int left_x = 0,
                                                     int bottom_y = 0) noexcept;
}
