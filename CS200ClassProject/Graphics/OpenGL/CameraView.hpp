/******************************************************************************
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name:   CameraView.hpp
Author
	- Sinil.Kang rtd99062@gmail.com
Creation Date: 08.12.2019

	Header file for Camera View
******************************************************************************/
#pragma once
#include <matrix3.hpp>
#include <vector2.hpp>

    class [[nodiscard]] CameraView
    {
    public:
        void            SetViewSize(vector2<float> pixel_size) noexcept;
        void            SetViewSize(int new_pixel_width, int new_pixel_height) noexcept;
		vector2<float> GetViewSize() const noexcept { return displaySize; }
        void            SetZoom(float new_zoom) noexcept;
        constexpr float GetZoom() const noexcept { return zoom; }
		matrix3<float>         GetCameraToNDCTransform() const noexcept { return cameraToNDC; }

        enum FrameOfReference
        {
            RightHanded_OriginCenter,
            RightHanded_OriginBottomLeft,
            LeftHanded_OriginTopLeft,
            NormalizedDeviceCoordinates
        };
        void                       SetFrameOfReference(FrameOfReference frame_of_reference) noexcept;
        constexpr FrameOfReference GetFrameOfReference() const noexcept { return frameOfReference; }

    private:
        vector2<float>          displaySize{};
        matrix3<float>          cameraToNDC = {1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f};
        float            zoom{1.0f};
        FrameOfReference frameOfReference = RightHanded_OriginCenter;
    };