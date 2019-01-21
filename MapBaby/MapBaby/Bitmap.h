#pragma once
#include <stdint.h>
#include <vector>

class Bitmap
{
private:
	std::uint16_t width;
	std::uint16_t height;
	std::vector<std::uint8_t> pixels;
public:
	Bitmap();
	Bitmap(std::uint16_t width, std::uint16_t height);
	Bitmap(const Bitmap &bitmap);
	~Bitmap();

	std::uint16_t getWidth() const;
	std::uint16_t getHeight() const;
	std::vector<std::uint8_t> getData() const;

	std::uint8_t getPixel(const std::uint16_t x, const std::uint16_t y) const;

	void resize(const std::uint16_t width, const std::uint16_t height);
};

