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


class Tree
{
private:
	VertexArray tree_log_sprite;
	Buffer* tree_log_coord_vbo1;
	Buffer* tree_log_coord_vbo2;
	IndexBuffer tree_log_ibo;
	//Shader tree_shader;
	VertexArray tree_leaves_sprite;
	Buffer* tree_leaves_coord_vbo1;
	Buffer* tree_leaves_coord_vbo2;
	IndexBuffer tree_leaves_ibo;

public:
	Shader tree_log_shader;
	Shader tree_leaves_shader;
	float coord_log[24];
	float coord_leaves[24];

	Tree();
	Tree(float coord[12]);
	Tree(float coordLog[24], float coordLeaves[24]);

	inline VertexArray getLogSprite() const noexcept { return tree_log_sprite; }
	inline VertexArray getLeavesSprite() const noexcept { return tree_leaves_sprite; }
	inline IndexBuffer getLogIbo() const noexcept { return tree_log_ibo; }
	inline IndexBuffer getLeavesIbo() const noexcept { return tree_leaves_ibo; }
	inline Shader getLogShader() noexcept { return tree_log_shader; }
	inline Shader getLeavesShader() noexcept { return tree_leaves_shader; }

	void updateCoordVbo();
	void updateLogMatrix(glm::mat4 matrix);
	void updateLeavesMatrix(glm::mat4 matrix);

	void bindLog() const noexcept;
	void bindLeaves() const noexcept;
	void unbindLog() const noexcept;
	void unbindLeaves() const noexcept;

	~Tree();
};

