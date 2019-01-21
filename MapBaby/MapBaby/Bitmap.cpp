#include "Bitmap.h"

Bitmap::Bitmap()
{
}

Bitmap::Bitmap(std::uint16_t width, std::uint16_t height)
{
	
}

Bitmap::Bitmap(const Bitmap & bitmap)
{
	this->width = bitmap.getWidth();
	this->height = bitmap.getHeight();
	this->pixels = bitmap.getData();
}

Bitmap::~Bitmap()
{
}

std::uint16_t Bitmap::getWidth() const
{
	return this->width;
}
std::uint16_t Bitmap::getHeight() const
{
	return this->height;
}
std::uint8_t Bitmap::getPixel(const std::uint16_t x, const std::uint16_t y) const
{
	return pixels[(y * this->width) + x];
}
std::vector<std::uint8_t> Bitmap::getData() const
{
	return pixels;
}

void Bitmap::resize(const std::uint16_t width, const std::uint16_t height)
{
	this->width = width;
	this->height = height;
	pixels.resize(width * height);
}
