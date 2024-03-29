/*  1. sinil.gang
 *  2. text assignment
 *  3. CS230
 *  4. Spring 2019
 */
#include <Graphics/OpenGL/BitmapFont.hpp>
#include <Graphics/OpenGL/Mesh.hpp>
#include <Graphics/OpenGL/StockShaders.hpp>
#include <Graphics/OpenGL/Text.hpp>

namespace Graphics
{
    Text::Text(std::wstring text_string, const BitmapFont& text_font) noexcept : string(text_string), font(&text_font)
    {
        InitializeWithEmptyVertices();
    }

    std::vector<std::pair<const Vertices*, const Texture*>> Text::GetVerticesWithMatchingTextures() const noexcept
    {
        BuildNewMeshesIfNeeded();
        std::vector<std::pair<const Vertices*, const Texture*>> result;
		const int vertices_size = static_cast<int>(vertices.size());
        for (int i = 0; i < vertices_size; ++i)
        {
            if (vertices.at(i).GetVerticesCount() != 0)
            {
                result.push_back(std::pair<const Vertices*, const Texture*>{&vertices.at(i), &font->GetTexture(i)});
            }
        }
        return result;
    }

    std::wstring Text::GetString() const noexcept { return string; }

    void Text::SetString(const std::wstring& text_string) noexcept
    {
        if (string != text_string)
        {
            needNewMeshes = true;
            string        = text_string;
        }
    }

    const BitmapFont* Text::GetFont() const noexcept { return font; }

    void Text::SetFont(const BitmapFont& text_font) noexcept
    {
        font = &text_font;
        InitializeWithEmptyVertices();
        needNewMeshes = true;
    }

    void Text::InitializeWithEmptyVertices() const noexcept
    {
        vertices.clear();

        for (int i = 0; i < font->GetInformation().pagesCount; ++i)
        {
            Vertices tmp;
            Mesh     empty;
            empty.Clear();
            tmp.InitializeWithMeshAndLayout(empty, SHADER::textured_vertex_layout());
            vertices.insert_or_assign(i, std::move(tmp));
        }
    }

    void Text::BuildNewMeshesIfNeeded() const noexcept
    {
        if (needNewMeshes == false)
        {
            return;
        }

        const BitmapFont::information& information = font->GetInformation();

        for (unsigned short i = 0; i < information.pagesCount; ++i)
        {
            Mesh     mesh;
            Vertices vertice;
            vector2  cursor{0.f};
            for (const auto& element : string)
            {
                const BitmapFont::character& character = font->GetCharacter(element);
                mesh.SetPointListType(PointListPattern::Triangles);

                if (element == L' ')
                {
                    if (font->HasCharacter(wchar_t(' ')))
                    {
                        cursor.x += character.xAdvance;
                    }
                    else
                    {
                        cursor.x += information.fontSize;
                    }
                }
                else if (element == L'\t')
                {
                    if (font->HasCharacter(wchar_t(' ')))
                    {
                        cursor.x = 4.f * character.xAdvance;
                    }
                    else
                    {
                        cursor.x = 4.f * information.fontSize;
                    }
                }
                else if (element == L'\n')
                {
                    cursor.x = 0;
                    cursor.y -= information.lineHeight;
                }
                else if (character.page == i)
                {

                    const float left   = character.xOffset + cursor.x;
                    const float bottom = (character.yOffset + character.height) * -1 + font->GetLineHeight() + cursor.y;
                    const float right  = left + character.width;
                    const float top    = bottom + character.height;

                    const float left_u   = static_cast<float>(character.x) / information.imageWidth;
                    const float right_u  = static_cast<float>(character.x + character.width) / information.imageWidth;
                    const float top_v    = static_cast<float>(character.y) / information.imageHeight;
                    const float bottom_v = static_cast<float>(character.y + character.height) / information.imageHeight;

                    mesh.AddPoint(vector2{left, top});
                    mesh.AddTextureCoordinate(vector2{left_u, top_v});
                    mesh.AddPoint(vector2{right, top});
                    mesh.AddTextureCoordinate(vector2{right_u, top_v});
                    mesh.AddPoint(vector2{left, bottom});
                    mesh.AddTextureCoordinate(vector2{left_u, bottom_v});

                    mesh.AddPoint(vector2{right, top});
                    mesh.AddTextureCoordinate(vector2{right_u, top_v});
                    mesh.AddPoint(vector2{left, bottom});
                    mesh.AddTextureCoordinate(vector2{left_u, bottom_v});
                    mesh.AddPoint(vector2{right, bottom});
                    mesh.AddTextureCoordinate(vector2{right_u, bottom_v});

                    cursor.x += character.xAdvance;
                }
                else
                {
                    cursor.x += character.xAdvance;
                }
            } // Loop End
            vertice.InitializeWithMeshAndLayout(mesh, SHADER::textured_vertex_layout());
            vertices.insert_or_assign(i, std::move(vertice));
        }
        needNewMeshes = false;
    }
}
