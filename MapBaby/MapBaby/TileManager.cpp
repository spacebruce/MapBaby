#include "TileManager.h"

TileManager::TileManager()
{
}

TileManager::~TileManager()
{
}

void TileManager::createTile()
{
	SharedTile newTile = std::make_shared<Tile>();
	Texture * tex = newTile.get()->getTexture();

	//dummy texture
	constexpr static int width = 16;
	constexpr static int height = 16;
	GLuint pixels[width * height];
	for (int i = 0; i < (width * height); ++i)
	{
		GLubyte* colour = (GLubyte*)&pixels[i];
		if (i & 1)
		{
			colour[0] = 0xff;
			colour[1] = 0x00;
			colour[2] = 0x00;
			colour[3] = 0xff;
		}
		else
		{
			colour[0] = 0x00;
			colour[1] = 0xff;
			colour[2] = 0x00;
			colour[3] = 0xff;
		}
	}
	tex->createFromArray(width, height, pixels);

	tilePool.emplace_back(newTile);
}

Tile * TileManager::getTile(const int index)
{
	if ((index < 0) || (index > this->getCount()))
		return nullptr;
	return (this->tilePool[index].get());
}

int TileManager::getCount() const
{
	return (this->tilePool.size());
}