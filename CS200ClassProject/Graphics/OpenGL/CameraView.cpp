/******************************************************************************
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name:   CameraView.cpp
Author
	- Sinil.Kang rtd99062@gmail.com
Creation Date: 08.12.2019

	Source file for Camera View
******************************************************************************/

#include <Graphics/OpenGL/CameraView.hpp>
#include <Graphics/OpenGL/Camera.hpp>
#include <Graphics/OpenGL/Transform.hpp>

// For RightHanded_OriginCenter
// You want to map (-w/2, w/2) to (-1,1) and (-h/2,h/2) to (-1,1)
//           (w/2,h/2)                (1,1)
//      +--------+             +--------+
//      |        |             |        |
//      | cam    |     --->    | ndc    |
//      +--------+             +--------+
// (-w/2,-h/2)              (-1,-1)
//

// For RightHanded_OriginBottomLeft
// You want to map (0, w) to (-1,1) and (0,h) to (-1,1)
//             (w,h)                  (1,1)
//      +--------+             +--------+
//      |        |             |        |
//      | cam    |     --->    | ndc    |
//      +--------+             +--------+
//    (0,0)                 (-1,-1)
//

// For LeftHanded_OriginTopLeft
// You want to map (0, w) to (-1,1) and (0,h) to (1,-1)
//    (0,0)                 (-1,1)
//      +--------+             +--------+
//      |        |             |        |
//      | cam    |     --->    | ndc    |
//      +--------+             +--------+
//             (w,h)                  (1,-1)
//


matrix3<float> CalculateMatrix(const CameraView& camera, const vector2<float>& displaySize)
    {
        matrix3<float> translateMatrix = MATRIX3::build_identity<float>();
		matrix3<float> scaleMatrix     = MATRIX3::build_scale<float>(2.f * camera.GetZoom() / displaySize.x, 2.f * camera.GetZoom() / displaySize.y);

        switch (camera.GetFrameOfReference())
        {
            case CameraView::RightHanded_OriginCenter:
                break;
            case CameraView::RightHanded_OriginBottomLeft:
                translateMatrix = MATRIX3::build_translation(vector2<float>{-1.f});
                break;
            case CameraView::LeftHanded_OriginTopLeft:
                translateMatrix            = MATRIX3::build_translation(vector2<float>{-1.f, 1.f});
                scaleMatrix.elements[1][1] = -scaleMatrix.elements[1][1];
                break;
            case CameraView::NormalizedDeviceCoordinates:
            default:;
        }
        return translateMatrix * scaleMatrix;
    }

    void CameraView::SetViewSize(vector2<float> pixel_size) noexcept
    {
        displaySize = pixel_size;

        cameraToNDC = CalculateMatrix(*this, displaySize);
    }

    void CameraView::SetViewSize(int new_pixel_width, int new_pixel_height) noexcept
    {
        displaySize = vector2<float>{static_cast<float>(new_pixel_width), static_cast<float>(new_pixel_height)};

        cameraToNDC = CalculateMatrix(*this, displaySize);
    }

    void CameraView::SetZoom(float new_zoom) noexcept
    { 
        zoom = new_zoom;

        cameraToNDC = CalculateMatrix(*this, displaySize);
    }

    void CameraView::SetFrameOfReference(FrameOfReference frame_of_reference) noexcept
    {
        frameOfReference = frame_of_reference;

        cameraToNDC = CalculateMatrix(*this, displaySize);
    }
