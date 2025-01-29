#pragma once

#include "../Buffers/Buffer.hpp"
#include "../Buffers/IndexBuffer.hpp"
#include "../Buffers/VertexArray.hpp"
#include "../Shaders/Shader.hpp"
#include "Texture.hpp"

#include <../../../Dependencies/glm/glm.hpp>
#include <../../../Dependencies/glm/gtc/matrix_transform.hpp>
#include <../../../Dependencies/glm/gtc/bitfield.hpp>
#include <../../../Dependencies/glm/gtc/color_space.hpp>
#include <../../../Dependencies/glm/gtc/constants.hpp>
#include <../../../Dependencies/glm/gtc/type_ptr.hpp>


class Car
{
private:
	VertexArray car_sprite;
	Buffer* car_coord_vbo1;
	Buffer* car_coord_vbo2;
	IndexBuffer car_ibo;
	//Shader car_shader;

public:
	Shader car_shader;
	float coord[24];

	Car(float coord[24]);

	inline VertexArray getSprite() const noexcept { return car_sprite; }
	inline IndexBuffer getIbo() const noexcept { return car_ibo; }
	inline Shader getShader() noexcept { return car_shader; }

	void updateCoordVbo();
	void updateMatrix(glm::mat4 matrix);

	void bind() const noexcept;
	void unbind() const noexcept;

	~Car();
};

