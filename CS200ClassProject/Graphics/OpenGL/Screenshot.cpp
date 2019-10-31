/*  1. sinil.gang
 *  2. Image Programming
 *  3. CS230
 *  4. Spring 2019
 */
#include <Graphics/OpenGL/Screenshot.hpp>
#include <Graphics/OpenGL/glCheck.hpp>
#include <GL/glew.h>

namespace Graphics
{
    Image capture_screenshot_of_back_buffer_to_image(int pixels_width, int pixels_height, int left_x,
                                                     int bottom_y) noexcept
    {
        Image    result;

        glCheck(glReadBuffer(GL_BACK));
        result.ResizeToPixelWidthHeight(pixels_width, pixels_height);
        if (glReadnPixels != nullptr)
        {
            glCheck(glReadnPixels(left_x, bottom_y, pixels_width, pixels_height, GL_RGBA, GL_UNSIGNED_BYTE,
                                  result.GetPixelsBufferBytesSize(), result.GetPixelsPointer()));
        }
        else
        {
            glCheck(glReadPixels(left_x, bottom_y, pixels_width, pixels_height, GL_RGBA, GL_UNSIGNED_BYTE,
                                  result.GetPixelsPointer()));
        }
        result.FlipVertically();
        return result;
    }
}
