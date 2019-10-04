/******************************************************************************
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name:   CameraManager.hpp
Author
	- Sinil.Kang rtd99062@gmail.com
Creation Date: 08.21.2019

	Header file for Camera Manager that Manage whole functions of camera things
******************************************************************************/
#pragma once

#include <Graphics/OpenGL/Camera.hpp>
#include <Graphics/OpenGL/CameraView.hpp>
#include <unordered_map>
#include <memory>

namespace Graphics
{
	class CameraManager final
	{
	public:
		CameraManager();
		~CameraManager() = default;

		void Init() noexcept;

		// Functions to control camera storage
		void AddCamera(const std::string&) noexcept;
		bool SelectCamera(const std::string&) noexcept;

		void SetPosition(const vector2<float>&) noexcept;
		vector2<float> GetPosition() const noexcept;

		void SetZoom(float) noexcept;
		constexpr float GetZoom() const noexcept;

		void SetViewSize(const vector2<float>&) noexcept;
		void SetViewSize(int, int) noexcept;
		const vector2<float> GetViewSize() const noexcept;

		void SetFrameOfReference(CameraView::FrameOfReference) noexcept;
		constexpr CameraView::FrameOfReference GetFrameOfReference() const noexcept { return selectedCamera->cameraView.GetFrameOfReference(); };

		matrix3<float> GetWorldToNDCTransform() const noexcept;

		void MoveUp(float dt, float distance) noexcept;
		void MoveRight(float dt, float distance) noexcept;

		// All Camera Moving is implemented in here.
		// You can call it with how much you want to zoom when mouse scroll up and down.
		void CameraMove(const float& zoomSize) noexcept;

	private:
		struct CameraSet
		{
			Camera camera;
			CameraView cameraView;
		};

		CameraSet* selectedCamera = nullptr;
		std::unordered_map<std::string, std::shared_ptr<CameraSet>> cameraStorage;
	};
}

