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

#include "CameraManager.hpp"
#include <Window/Application.hpp>
#include <Input/InputController.h>
#include <stdexcept>

Graphics::CameraManager::CameraManager()
{
	cameraStorage.clear();
	AddCamera("MainCamera");
	SelectCamera("MainCamera");
}

/**
 * \brief 
 * For now, it do only set view size. However, Named for the possibility which do anything else...
 */
void Graphics::CameraManager::Init() noexcept
{
	vector2<int> windowSize = Application::GetApplication()->GetWindowSize();
	selectedCamera->cameraView.SetViewSize(windowSize.x, windowSize.y);
	selectedCamera->cameraView.SetZoom(1.f);
	selectedCamera->camera.InitializeVars();
}

/**
 * \brief 
 * \Notice Function name is "AddCamera" but it is able to initialize cameraSet when cameraTag is already exist value.
 * \param cameraTag : Key value for cameraStorage
 */
void Graphics::CameraManager::AddCamera(const std::string& cameraTag) noexcept
{
	cameraStorage.insert_or_assign(cameraTag, std::make_shared<CameraSet>());
}

bool Graphics::CameraManager::SelectCamera(const std::string& cameraTag) noexcept
{
	try
	{
		selectedCamera = cameraStorage.at(cameraTag).get();
	}
	catch (const std::out_of_range&)
	{
		selectedCamera = nullptr;
		// Log Something to notice fail.
		return false;
	}
	return true;
}

void Graphics::CameraManager::SetPosition(const vector2<float>& position) noexcept
{
	selectedCamera->camera.SetCenter(position);
}

vector2<float> Graphics::CameraManager::GetPosition() const noexcept
{
	return selectedCamera->camera.GetCenter();
}

void Graphics::CameraManager::SetZoom(float zoom) noexcept
{
	selectedCamera->cameraView.SetZoom(zoom);
}

constexpr float Graphics::CameraManager::GetZoom() const noexcept
{
	return selectedCamera->cameraView.GetZoom();
}

void Graphics::CameraManager::SetViewSize(const vector2<float>& size) noexcept
{
	selectedCamera->cameraView.SetViewSize(size);
}

void Graphics::CameraManager::SetViewSize(int width, int height) noexcept
{
	selectedCamera->cameraView.SetViewSize(width, height);
}

const vector2<float> Graphics::CameraManager::GetViewSize() const noexcept
{
	return selectedCamera->cameraView.GetViewSize();
}

void Graphics::CameraManager::SetFrameOfReference(CameraView::FrameOfReference frameOfReference) noexcept
{
	selectedCamera->cameraView.SetFrameOfReference(frameOfReference);
}

matrix3<float> Graphics::CameraManager::GetWorldToNDCTransform() const noexcept
{
	return selectedCamera->cameraView.GetCameraToNDCTransform() * 
		selectedCamera->camera.WorldToCamera();
}

void Graphics::CameraManager::MoveUp(float dt, float distance) noexcept
{
	selectedCamera->camera.MoveUp(dt * distance);
}

void Graphics::CameraManager::MoveRight(float dt, float distance) noexcept
{
	selectedCamera->camera.MoveRight(dt * distance);
}

void Graphics::CameraManager::CameraMove(const float& zoomSize) noexcept
{
	// Camera Movement
	if(input.IsMouseButtonTriggered(GLFW_MOUSE_BUTTON_RIGHT))
	{
		input.SetPresentMousePosition(input.GetMousePosition());
	}
	if (input.IsMouseButtonPressed(GLFW_MOUSE_BUTTON_RIGHT))
	{
		const vector2<float>& mousePosition = input.GetMousePosition();
		const vector2<float>& distance = (input.GetPresentMousePosition() - mousePosition) / selectedCamera->cameraView.GetZoom();

		selectedCamera->camera.MoveRight(distance.x);
		selectedCamera->camera.MoveUp(distance.y);

		input.SetPresentMousePosition(mousePosition);
	}

	// Camera Zoom In and Out
	if (input.MouseWheelScroll() > 0)
	{
		selectedCamera->cameraView.SetZoom(
			selectedCamera->cameraView.GetZoom() * zoomSize
		);
	}
	if (input.MouseWheelScroll() < 0)
	{
		selectedCamera->cameraView.SetZoom(
			selectedCamera->cameraView.GetZoom() / zoomSize
		);
	}

	if (input.IsKeyPressed(GLFW_KEY_E))
	{
		selectedCamera->camera.Rotate(0.05);
	}
	if (input.IsKeyPressed(GLFW_KEY_Q))
	{
		selectedCamera->camera.Rotate(-0.05);
	}
}

