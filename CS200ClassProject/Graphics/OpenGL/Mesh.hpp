/******************************************************************************
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name:   Mesh.hpp
Author
	- Sinil.Kang rtd99062@gmail.com
Creation Date: 08.10.2019

	Header file for Mesh
******************************************************************************/
#pragma once
#include <Graphics/OpenGL/Color4ub.hpp>
#include <vector2.hpp>
#include <cstddef>
#include <vector>

namespace Graphics
{
    enum class [[nodiscard]] PointListPattern
    {
        Lines, LineStrip, LineLoop, Triangles, TriangleStrip, TriangleFan
    };

    class [[nodiscard]] Mesh
    {
    public:
        std::size_t GetPointCount() const noexcept;
         vector2<float>     GetPoint(std::size_t index) const noexcept;
        Graphics::Color4ub    GetColor(std::size_t index = 0) const noexcept;
         vector2<float>     GetTextureCoordinate(std::size_t index) const noexcept;

        PointListPattern GetPointListPattern() const noexcept;
        void             SetPointListType(PointListPattern type) noexcept;

        void AddColor(Graphics::Color4ub color) noexcept;
        void AddPoint( vector2<float> point) noexcept;
        void AddTextureCoordinate( vector2<float> texture_coordinate) noexcept;

        void ClearColors() noexcept;
        bool HasMoreThanOneColor() const noexcept;

        void ClearTextureCoordinates() noexcept;
        void ClearPoints() noexcept;
        void Clear() noexcept;

    private:
        std::vector< vector2<float>>  points{};
        std::vector<Graphics::Color4ub> colors{};
        std::vector< vector2<float>>  textureCoordinates{};
        PointListPattern      pointListType = PointListPattern::Lines;
    };

    namespace MESH
    {
        Mesh create_circle(float radius = 1, Graphics::Color4ub color = Graphics::Color4ub{255}, std::size_t point_count = 30) noexcept;
        Mesh create_wire_circle(float radius = 1, Graphics::Color4ub color = Graphics::Color4ub{255},
                                std::size_t point_count = 30) noexcept;
        Mesh create_box(float dimension = 1, Graphics::Color4ub color = Graphics::Color4ub{255}) noexcept;
        Mesh create_rectangle(float width = 1, float height = 1, Graphics::Color4ub color = Graphics::Color4ub{255}) noexcept;
        Mesh create_wire_rectangle(float width = 1, float height = 1, Graphics::Color4ub color = Graphics::Color4ub{255}) noexcept;
        Mesh create_wire_box(float dimension = 1, Graphics::Color4ub color = Graphics::Color4ub{255}) noexcept;
        Mesh create_line( vector2<float> a = {0, 0},  vector2<float> b = {1, 0}, Graphics::Color4ub color = Graphics::Color4ub{255}) noexcept;
    }
}
