#include "TextureHolder.h"
#include <assert.h>


TextureHolder* TextureHolder::m_s_Instexture = nullptr;

TextureHolder::TextureHolder()
{
	assert(m_s_Instexture == nullptr);
	m_s_Instexture = this;
}

sf::Texture& TextureHolder::GetTexture(string const& filename)
{
	auto& mem = m_s_Instexture->m_Textures;

	auto keyValuePair = mem.find(filename);

	if (keyValuePair != mem.end())
	{

		return keyValuePair->second;

	}
	else {
	
		auto& texture = mem[filename];

		texture.loadFromFile(filename);

		return texture;
	}
}