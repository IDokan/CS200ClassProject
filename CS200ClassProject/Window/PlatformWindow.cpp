#include "PlatformWindow.h"
#include "vector2.hpp"
#include <Input/InputController.h>
#include <Graphics/OpenGL/GL.hpp>
#include <stb_image.h>
#include <Graphics/OpenGL/Image.hpp>
#include <Window/Application.hpp>

namespace
{
	void KeyCallback(GLFWwindow*, int key, int, int action, int)
	{
		input.SetKeyboardInput(key, action);
	}
	void MousePositionCallback(GLFWwindow*, double xPos, double yPos)
	{
		input.SetMousePos(static_cast<float>(xPos), static_cast<float>(yPos));
	}
	void MouseButtonCallback(GLFWwindow*, int button, int action, int)
	{
		input.SetMouseButtonInput(button, action);
	}
	void MouseWheelScroll(GLFWwindow*, double x_offset, double y_offset)
	{
		input.SetMouseWheel(x_offset, y_offset);
	}
	void WindowSizeCallback(GLFWwindow*, int width, int height)
	{
		Graphics::GL::set_display_area(width, height);
	}
	void WindowClose(GLFWwindow* window)
	{
		glfwSetWindowShouldClose(window, GLFW_FALSE);
		Application::GetApplication()->SetIsRunning(false);
	}
	void WindowMaximizationCallback(GLFWwindow* window, int maximized)
	{
		if (maximized)
		{
			glfwMaximizeWindow(window);
		}
		else
		{
			glfwRestoreWindow(window);
		}
	}
	void WindowFocusCallback(GLFWwindow* window, int focused)
	{
		Application::GetApplication()->SetIsPaused(!focused);
	}
}

bool PlatformWindow::CreateWindow() noexcept
{
	if (!glfwInit())
	{
		return false;
	}
	
	xPosition = 100;
	yPosition = 100;

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_DEPTH_BITS, 24);
	glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_TRUE);
	glfwWindowHint(GLFW_SAMPLES, 4);

	window = glfwCreateWindow(xSize, ySize, "CS200 Class Project", nullptr, nullptr);
	glfwSetWindowPos(window, xPosition, yPosition);

	if (!window)
	{
		return false;
	}

	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, KeyCallback);
	glfwSetCursorPosCallback(window, MousePositionCallback);
	glfwSetMouseButtonCallback(window, MouseButtonCallback);
	glfwSetScrollCallback(window, MouseWheelScroll);
	glfwSetWindowSizeCallback(window, WindowSizeCallback);
	glfwSetWindowCloseCallback(window, WindowClose);
	glfwSetWindowMaximizeCallback(window, WindowMaximizationCallback);
	glfwSetWindowFocusCallback(window, WindowFocusCallback);
	glfwSwapInterval(true);

	GLFWimage icon[1];
	icon[0].pixels = stbi_load("C:/Users/KMU_USER/Desktop/CS200ClassProject/CS200ClassProject/assets/texture/engineCustomIcon.png", &icon[0].width, &icon[0].height, 0, 4);
	
	glfwSetWindowIcon(window, 1, &icon[0]);
	glewInit();

	return true;
}

void PlatformWindow::PollEvent() noexcept
{
	glfwPollEvents();
}

void PlatformWindow::SwapBackBuffer() noexcept
{
	glfwSwapBuffers(window);
}

void PlatformWindow::ToggleFullscreen() noexcept
{
	if (!IsFullScreen())
	{
		const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
		GLFWmonitor* monitor = glfwGetPrimaryMonitor();

		glfwGetWindowPos(window, &xPosition, &yPosition);
		glfwGetWindowSize(window, &xSize, &ySize);
		glfwSetWindowMonitor(window, monitor, 0, 0, mode->width, mode->height, 0);
		glViewport(0, 0, mode->width, mode->height);
		windowSize.width = mode->width;
		windowSize.height = mode->height;
	}
	else
	{
		glfwSetWindowMonitor(window, nullptr, xPosition, yPosition, xSize, ySize, 0);
		glViewport(0, 0, xSize, ySize);
		windowSize.width = xSize;
		windowSize.height = ySize;
	}
	glfwSwapInterval(true);
}

bool PlatformWindow::IsFullScreen() noexcept
{
	return glfwGetWindowMonitor(window);
}

void PlatformWindow::TurnOnMonitorVerticaSynchronization(bool enable) noexcept
{
	isVsyncOn = enable;
	glfwSwapInterval(enable);
}

bool PlatformWindow::IsMonitorVerticalSynchronizationOn() noexcept
{
	return isVsyncOn;
}

vector2<int> PlatformWindow::GetPlatformWindowSize() const noexcept
{
	return windowSize;
}

void PlatformWindow::SetWindowTitle(const std::string& title) noexcept
{
	glfwSetWindowTitle(window, title.c_str());
}

void PlatformWindow::ClearWindow() const noexcept
{
	glfwDestroyWindow(window);
	glfwTerminate();
}
