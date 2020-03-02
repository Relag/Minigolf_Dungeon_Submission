#ifndef TEXTUREHOLDER_H
#define TEXTUREHOLDER_H

#include <SFML/Graphics.hpp>
#include <map>

using namespace sf;
using namespace std;

class TextureHolder
{

public:
	TextureHolder();
	static Texture& GetTexture(string const& filename);

private:
	map<string, Texture> m_Textures;
	static TextureHolder* m_s_Instexture;
}; 
#endif // !TEXTUREHOLDER_H

