#pragma once
#include<iostream>
#include <random>
#include <thread>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

struct color
{
	int r = 0, g = 0, b = 0;
};

static void CoolEffect(color& color)
{
	if ( color.r == 255 && color.g == 255 && color.b == 255)
	{
		color.r = 0;
		color.g = 0;
		color.b = 0;
	}

	 else if (color.r == 255 && color.g == 255)
	{
		color.b++;
	}
	 else if ( color.r == 255)
	{
		color.g++;
	}
	 else
	 {
		color.r++;
	 }

}

static color rainbowColor(float time) {
	color c;
	// On utilise des sinus pour que les transitions soient douces
	c.r = int((std::sin(time) * 127 + 128));      // 0-255
	c.g = int((std::sin(time + 2.0f) * 127 + 128)); // décalage de phase
	c.b = int((std::sin(time + 4.0f) * 127 + 128)); // décalage de phase
	return c;
}


class Random
{
public:
	Random() :m_gen(m_rd()){}
	int GetRandomNumber(int min , int max )
	{
		std::uniform_int_distribution<int> dis(min, max);
		return dis(m_gen);
	}
private:
	std::mt19937_64 m_gen;
	std::random_device m_rd;
};


static float RgbToNormal(float operand)
{
	return operand * 1 / 255.0f;
}


namespace CreateWindow
{

	static int Run()
	{
		

		// Initialize GLFW
		glfwInit();



		// Tell GLFW what version of OpenGL we are using 
		// In this case we are using OpenGL 3.3
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		// Tell GLFW we are using the CORE profile
		// So that means we only have the modern functions
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



		// Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
		GLFWwindow* window = glfwCreateWindow(800, 800, "YoutubeOpenGL", NULL, NULL);
		// Error check if the window fails to create
		if (window == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			return -1;
		}
		// Introduce the window into the current context
		glfwMakeContextCurrent(window);



		//Load GLAD so it configures OpenGL
		gladLoadGL();
		// Specify the viewport of OpenGL in the Window
		// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
		glViewport(0, 0, 800, 800);



		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);



		// Main while loop
		while (!glfwWindowShouldClose(window))
		{
			// Take care of all GLFW events
			glfwPollEvents();
		}



		// Delete window before ending the program
		glfwDestroyWindow(window);
		// Terminate GLFW before ending the program
		glfwTerminate();
		return 0;
	}

	static int Run_EX_Easy_1()
	{



		// Initialize GLFW
		glfwInit();



		// Tell GLFW what version of OpenGL we are using 
		// In this case we are using OpenGL 3.3
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		// Tell GLFW we are using the CORE profile
		// So that means we only have the modern functions
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



		// Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
		GLFWwindow* window = glfwCreateWindow(800, 800, "YoutubeOpenGL", NULL, NULL);
		// Error check if the window fails to create
		if (window == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			return -1;
		}
		// Introduce the window into the current context
		glfwMakeContextCurrent(window);



		//Load GLAD so it configures OpenGL
		gladLoadGL();
		// Specify the viewport of OpenGL in the Window
		// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
		glViewport(0, 0, 800, 800);



		// Specify the color of the background
		glClearColor(RgbToNormal(255), RgbToNormal(128), RgbToNormal(0.0f), 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);



		// Main while loop
		while (!glfwWindowShouldClose(window))
		{
			// Take care of all GLFW events
			glfwPollEvents();
		}



		// Delete window before ending the program
		glfwDestroyWindow(window);
		// Terminate GLFW before ending the program
		glfwTerminate();
		return 0;
	}
	static int Run_EX_Easy_2()
	{
		glfwInit();

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		GLsizei width = 400;
		GLsizei height = 225;

		GLFWwindow* window = glfwCreateWindow(width, height, "toto", nullptr, nullptr);
		glfwMakeContextCurrent(window);

		gladLoadGL();
		glViewport(0, 0, width, height);

		// Orange
		glClearColor(RgbToNormal(255), RgbToNormal(128), RgbToNormal(0.0f), 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		while (!glfwWindowShouldClose(window))
		{
			glfwPollEvents();
		}

		glfwDestroyWindow(window);
		glfwTerminate();
		return 0;
	}
	static int Run_EX_Easy_3()
	{
		glfwInit();

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		GLsizei width = 800;
		GLsizei height = 800;

		GLFWwindow* window = glfwCreateWindow(width, height, "toto", nullptr, nullptr);
		glfwMakeContextCurrent(window);

		gladLoadGL();
		glViewport(0,0,width,height);

		glClearColor(RgbToNormal(255), RgbToNormal(128), RgbToNormal(0.0f), 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);

		while (!glfwWindowShouldClose(window))
		{
			glfwPollEvents();
		}

		glfwDestroyWindow(window);
		glfwTerminate();

		return 0;
	}

	static int Run_EX_Medium_1()
	{
		glfwInit();

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		GLsizei width = 800;
		GLsizei height = 800;

		GLFWwindow* window = glfwCreateWindow(width, height, "Toto", nullptr, nullptr);
		glfwMakeContextCurrent(window);

		gladLoadGL();
		glViewport(0, 0, width, height);
		glClearColor(RgbToNormal(255), RgbToNormal(128), RgbToNormal(0.0f), 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);

		bool thisTime = false;

		while (!glfwWindowShouldClose(window))
		{
			if (thisTime)
				glClearColor(RgbToNormal(255), RgbToNormal(128), RgbToNormal(0.0f), 1.0f);
			else
				glClearColor(RgbToNormal(255), RgbToNormal(255), RgbToNormal(255), 1.0f);
			thisTime = !thisTime;

			
			glfwPollEvents();
			glClear(GL_COLOR_BUFFER_BIT);
			glfwSwapBuffers(window);
		}

		glfwDestroyWindow(window);
		glfwTerminate();
		return 1;
	}


	static int Run_EX_Hard_1()
	{
		glfwInit();

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		GLsizei width = 800;
		GLsizei height = 800;

		GLFWwindow* window = glfwCreateWindow(width, height, "Toto", nullptr, nullptr);
		glfwMakeContextCurrent(window);

		gladLoadGL();
		glViewport(0, 0, width, height);
		glClearColor(RgbToNormal(255), RgbToNormal(128), RgbToNormal(0.0f), 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);

		Random rd;

		color c;
		float lastTime = 0;
		while (!glfwWindowShouldClose(window))
		{
			if (glfwGetTime() - lastTime < 1.0f/60.0f)
			{
				continue;
			}

		/*	CoolEffect(c);*/
			c = rainbowColor(glfwGetTime());
			glClearColor(RgbToNormal(c.r), RgbToNormal(c.g), RgbToNormal(c.b), 1.0f);
		


			glfwPollEvents();
			glClear(GL_COLOR_BUFFER_BIT);
			glfwSwapBuffers(window);
			lastTime = glfwGetTime();
		}

		glfwDestroyWindow(window);
		glfwTerminate();
		return 1;
	}

	static int Run_BonnusOne()
	{
		glfwInit();

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		GLsizei width = 800;
		GLsizei height = 800;

		GLFWwindow* window = glfwCreateWindow(width, height, "Toto", nullptr, nullptr);
		glfwMakeContextCurrent(window);

		gladLoadGL();
		glViewport(0, 0, width, height);
		glClearColor(RgbToNormal(255), RgbToNormal(128), RgbToNormal(0.0f), 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);

		Random rd;

		color c;
		float lastTime = 0;
		while (!glfwWindowShouldClose(window))
		{
			if (glfwGetTime() - lastTime < 1.0f / 60.0f)
			{
				continue;
			}
			c = rainbowColor(glfwGetTime());
			glClearColor(RgbToNormal(c.r), RgbToNormal(c.g), RgbToNormal(c.b), 1.0f);

			glfwGetWindowSize(window, &width, &height);
			glViewport(0,0,width,height);

			glfwPollEvents();
			glClear(GL_COLOR_BUFFER_BIT);
			glfwSwapBuffers(window);
			lastTime = glfwGetTime();
		}

		glfwDestroyWindow(window);
		glfwTerminate();
		return 1;
	}

}