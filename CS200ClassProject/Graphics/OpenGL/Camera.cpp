/******************************************************************************
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name:   Camera.cpp
Author
	- Sinil.Kang rtd99062@gmail.com
Creation Date: 08.12.2019

	Source file for Camera
******************************************************************************/

#include <Graphics/OpenGL/Camera.hpp>
#include <Graphics/OpenGL/Transform.hpp>
#include <Graphics/OpenGL/Material.hpp>

    Camera::Camera(vector2<float> camera_center, vector2<float> camera_up) noexcept 
    : center(camera_center), up(camera_up), right(vector2{camera_up.y, -camera_up.x})
    {}

    void Camera::ResetUp(vector2<float> camera_up) noexcept
    { 
        up = camera_up;
        right = vector2{up.y, -up.x};
    }

    void Camera::MoveUp(float distance) noexcept
    {
        center = (center + up * distance);
    }

    void Camera::MoveRight(float distance) noexcept
    { 
        center = (center + right*distance);
    }

    void Camera::Rotate(float angle_radians) noexcept
    { 
        up = rotateBy(angle_radians, up);
		right = vector2{ up.y, -up.x };
    }

    matrix3<float> Camera::CameraToWorld() const noexcept
    {
        // inverse translation * inverse rotation
        return MATRIX3::build_translation(center) * MATRIX3::transpose(matrix3{
            right.x, up.x, 0.f,
            right.y, up.y, 0.f,
            0.f, 0.f, 1.f
            });
    }

    matrix3<float> Camera::WorldToCamera() const noexcept
    {
        // rotation * translation
        return MATRIX3::transpose(matrix3{right.x, right.y, 0.f,
                       up.x,    up.y,    0.f,
            0.f, 0.f, 1.f}) * MATRIX3::build_translation(-center);
    }

void Camera::InitializeVars() noexcept
{
	SetCenter(vector2{ 0.f });
	up = vector2{ 0.f, 1.f };
	right = vector2{ 1.f, 0.f };
}
