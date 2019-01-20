#include "Palette.h"

Palette::Palette(std::size_t maxSize) : maxSize(maxSize)
{}

Palette::Palette(std::string name, std::size_t maxSize) : name(name), maxSize(maxSize)
{}

Palette::~Palette()
{
}

ColourRGB & Palette::getEntry(std::size_t index)
{
	return this->palette[std::min(index, this->palette.size())];
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

void Palette::set(std::size_t index, ColourRGB entry)
{
	palette[index] = entry;
}

void Palette::add(ColourRGB entry)
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