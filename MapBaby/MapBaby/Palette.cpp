#include "Palette.h"

Palette::Palette()
{
}

Palette::~Palette()
{
}

PaletteEntry Palette::getEntry(std::size_t index)
{
	if (index > this->palette.size())
	{
		return PaletteEntry(0x00, 0x00, 0x00, index);
	}
	return this->palette[index];
}

int Palette::getSize(void)
{
	return this->maxSize;
}

void Palette::setSize(std::size_t size)
{
	this->maxSize = size;
	this->palette.resize(size);
}

void Palette::add(PaletteEntry entry)
{
	if (this->palette.size() < this->maxSize)
	{
		palette.emplace_back(entry);
	}
}

void Palette::remove(std::size_t index)
{
	palette.erase(palette.begin() + index);
}