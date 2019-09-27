#include "PlatformWindow.h"
#include "vector2.hpp"

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
	// TODO: Make a callback functions and Uncomment it
	//glfwSetKeyCallback(window, KeyCallback);
	//glfwSetCursorPosCallback(window, MousePositionCallback);
	//glfwSetMouseButtonCallback(window, MouseButtonCallback);
	//glfwSetScrollCallback(window, MouseWheelScroll);
	//glfwSetWindowSizeCallback(window, WindowSizeCallback);
	glfwSwapInterval(true);

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

void PlatformWindow::ClearWindow() const noexcept
{
	glfwDestroyWindow(window);
	glfwTerminate();
}
