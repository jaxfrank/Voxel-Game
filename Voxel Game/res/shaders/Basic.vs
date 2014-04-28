#version 330

uniform mat4 projectedTransformationMatrix;

in layout(location = 0) vec3 position;
in layout(location = 1) vec4 vertexColor;

out vec4 color0;

void main(){
	gl_Position = vec4(position, 1.0) * projectedTransformationMatrix;
	color0 = vertexColor;
}