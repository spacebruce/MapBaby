#include "Palette.h"

Palette::Palette()
{
}

Palette::~Palette()
{
}

PaletteEntry Palette::getEntry(int index)
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

void Palette::setSize(int size)
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

void Palette::remove(int index)
{
	palette.erase(palette.begin() + index);
}