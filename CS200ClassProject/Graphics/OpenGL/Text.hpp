/*
 * sinil.gang
 * Graphics Library
 * CS230
 */
#pragma once

#include <Graphics/OpenGL/Vertices.hpp>
#include <string>
#include <unordered_map>
#include "Graphics/OpenGL/CameraView.hpp"
#include "Graphics/OpenGL/Transform.hpp"
#include "Graphics/OpenGL/BitmapFont.hpp"

class CameraView;
class Transform;

namespace Graphics
{
	class BitmapFont;

    class [[nodiscard]] Text
    {
    public:
        Text() noexcept {};
        Text(std::wstring text_string, const BitmapFont& text_font) noexcept;

        std::vector<std::pair<const Vertices*, const Texture*>> GetVerticesWithMatchingTextures() const noexcept;
        std::wstring                                            GetString() const noexcept;
        void                                                    SetString(const std::wstring& text_string) noexcept;
        const BitmapFont*                                       GetFont() const noexcept;
        void                                                    SetFont(const BitmapFont& text_font) noexcept;

    private:
        void InitializeWithEmptyVertices() const noexcept;
        void BuildNewMeshesIfNeeded() const noexcept;

    private:
        std::wstring                              string{};
        const BitmapFont*                         font = nullptr;
        mutable std::unordered_map<int, Vertices> vertices{};
        mutable bool                              needNewMeshes = true;
    };
}
