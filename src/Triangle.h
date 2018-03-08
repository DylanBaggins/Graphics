#pragma once
#include <GL/glew.h>
#include <array>
#include <ctime>

class Triangle
{
public:


	//constructor
	Triangle()
	{

	}

	//define vertices for the triangle
	GLfloat vertices[900] = {};
	 
	//set up vertex buffer object
	GLuint VBO;
	
	//set up vertex array object
	GLuint VAO;

	//generate random folots between -1.0 & 1.0
	float floatGen(float Min, float Max) 
	{
		return ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
	}
	
	//Create 100 random triangles
	void randoTriangles()
	{
		for (int i = 0; i < 899; i++) 
		{
			vertices[i] = floatGen(-1.0, 1.0);
			std::cout << vertices[i] << std::endl;
		}
	}

	void setBuffers()
	{
		//
		//OpenGL buffers
		//set up 1 for the triangle
		
		glGenBuffers(1, &VBO);

		// Initialization code using Vertex Array Object (VAO) (done once (unless the object frequently changes))
		
		glGenVertexArrays(1, &VAO);
		// Bind Vertex Array Object
		glBindVertexArray(VAO);
		// Copy our vertices array in a buffer for OpenGL to use
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		// Then set our vertex attributes pointers
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);
		//Unbind the VAO
		glBindVertexArray(0);
	}
};
