#version 440 core

uniform vec3 triangleColour;

out vec4 colour;

void main()
{
	colour = vec4(triangleColour, 1.0f);
}