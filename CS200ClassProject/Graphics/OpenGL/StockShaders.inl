/******************************************************************************
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name:   StockShaders.inl
Author
	- Sinil.Kang rtd99062@gmail.com
Creation Date: 08.10.2019

	Source file for GLSL
******************************************************************************/
#pragma once

namespace Graphics
{
    inline Shader& SHADER::solid_color() noexcept
    {
        static Shader shader(R"(
#version 330

layout(location = 0) in vec2 position;

uniform mat3 to_ndc;
uniform float depth;

void main()
{
    vec3 position = to_ndc * vec3(position, 1.0f);
    gl_Position = vec4(position.xy, depth, 1.0);
}
)",
                             R"(
#version 330

uniform vec4 color;
out vec4 output_color;

void main()
{
    output_color = color;
}
)");
        return shader;
    }

    inline const VertexLayoutDescription& SHADER::solid_color_vertex_layout() noexcept
    {
        static VertexLayoutDescription layout{VertexLayoutDescription::Position2WithFloats};
        return layout;
    }

    inline Shader& SHADER::interpolated_colors() noexcept
    {
        static Shader shader(
            R"(
#version 330

layout(location = 0) in vec2 position;
layout(location = 1) in vec4 color;

uniform mat3 to_ndc;
uniform float depth;

smooth out vec4 interpolated_color;

void main()
{
    vec3 position = to_ndc * vec3(position, 1.0f);
    gl_Position = vec4(position.xy, depth, 1.0);
    interpolated_color = color;
}
)",
            R"(
#version 330

in vec4 interpolated_color;
out vec4 output_color;

void main()
{
    output_color = interpolated_color;
}
)");
        return shader;
    }

    inline const VertexLayoutDescription& SHADER::interpolated_colors_vertex_layout() noexcept
    {
        static VertexLayoutDescription layout{VertexLayoutDescription::Position2WithFloats,
                                              VertexLayoutDescription::Color4WithUnsignedBytes};
        return layout;
    }

	inline Shader& SHADER::textured() noexcept
	{
		static Shader shader(
			R"(
#version 330

layout(location = 0) in vec2 position;
layout(location = 1) in vec2 texture_coordinate;

uniform mat3 to_ndc;
uniform float depth;

out vec2 interpolated_texture_coordinate;

void main()
{
    vec3 position = to_ndc * vec3(position, 1.0f);
    gl_Position = vec4(position.xy, depth, 1.0);
    interpolated_texture_coordinate = texture_coordinate;
}
)",
R"(
#version 330

in vec2 interpolated_texture_coordinate;

uniform vec4 color;
uniform sampler2D texture_to_sample;

out vec4 output_color;

void main()
{
    vec4 texel = texture(texture_to_sample, interpolated_texture_coordinate);
    vec4 new_color = color * texel;
    if(new_color.a <= 0.0f)
        discard;
    output_color = new_color;
}
)");
		return shader;
	}

	inline Shader& SHADER::texturedInstanced() noexcept
	{
		static Shader shader(
			R"(
#version 330

layout(location = 0) in vec2 position;
layout(location = 1) in vec2 texture_coordinate;

uniform mat3 to_ndc;
uniform float depth;
uniform vec2 offsets[100];
uniform vec2 scales[100];

out vec2 interpolated_texture_coordinate;
flat out int glInstanceID;

void main()
{
	vec2 offset = offsets[gl_InstanceID];
    vec3 position = to_ndc * vec3(position*scales[gl_InstanceID] + offset, 1.0f);
    gl_Position = vec4(position.xy, depth, 1.0);
    interpolated_texture_coordinate = texture_coordinate;
	glInstanceID = gl_InstanceID;
}
)",
R"(
#version 330

in vec2 interpolated_texture_coordinate;
flat in int glInstanceID;

uniform vec3 colorArray[100];
uniform sampler2D texture_to_sample;

out vec4 output_color;

void main()
{
    vec4 texel = texture(texture_to_sample, interpolated_texture_coordinate);
    vec4 new_color = vec4(colorArray[glInstanceID], 1.f) * texel;
    if(new_color.a <= 0.0f)
        discard;
    output_color = new_color;
}
)");
		return shader;
	}

    inline const VertexLayoutDescription& SHADER::textured_vertex_layout() noexcept
    {
        static VertexLayoutDescription layout{VertexLayoutDescription::Position2WithFloats,
                                              VertexLayoutDescription::TextureCoordinates2WithFloats};
        return layout;
    }

	inline Shader& SHADER::animated() noexcept
	{
		static Shader shader(
			R"(
#version 330

layout(location = 0) in vec2 position;
layout(location = 1) in vec2 texture_coordinate;

uniform mat3 to_ndc;
uniform float depth;
uniform int frame;
uniform int index;
uniform vec2 image_size;

out vec2 interpolated_texture_coordinate;

void main()
{
    vec3 position = to_ndc * vec3(position, 1.0f);
    gl_Position = vec4(position.xy, depth, 1.0);
    interpolated_texture_coordinate = vec2((texture_coordinate.x+index)/frame, texture_coordinate.y);
}
)",
R"(
#version 330

in vec2 interpolated_texture_coordinate;

uniform vec4 color;
uniform sampler2D texture_to_sample;

out vec4 output_color;

void main()
{
    vec4 texel = texture(texture_to_sample, interpolated_texture_coordinate);
    vec4 new_color = color * texel;
    if(new_color.a <= 0.0f)
        discard;
    output_color = new_color;
}
)");
		return shader;
	}

	inline Shader& SHADER::particle() noexcept
    {
		static Shader shader{
			R"(
#version 330 core
layout (location = 0) in vec2 position;
layout (location = 1) in vec2 texture_coordinate;

			out vec2 interpolated_texture_coordinate;
			out vec4 ParticleColor;

			uniform float depth;
			uniform mat3 to_ndc;

			void main()
			{
			float scale = 10.f;
			interpolated_texture_coordinate = texture_coordinate;

			vec3 position = to_ndc * vec3(position*scale, 1.f);
			gl_Position = vec4(position.xy, depth, 1.0);
			}
			)",
			R"(
#version 330 core
			in vec2 interpolated_texture_coordinate;
			in vec4 ParticleColor;
			out vec4 output_color;

			uniform vec4 color;
			uniform sampler2D texture_to_sample;

			void main()
			{
			vec4 texel = texture(texture_to_sample, interpolated_texture_coordinate);
			vec4 new_color = color * texel;
			if(new_color.a <= 0.0f)
				discard;
			if(new_color.r <= 0.f && new_color.g <= 0.f && new_color.b <= 0.f)
			{
				discard;
			}
			output_color = new_color;
			}
			)"
		};
		return shader;
    }
}
