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
	Bitmap(const std::uint16_t width, const std::uint16_t height);
	Bitmap(const Bitmap &bitmap);
	~Bitmap();

	std::uint16_t getWidth() const;
	std::uint16_t getHeight() const;
	std::vector<std::uint8_t> getData() const;

	std::uint8_t getPixel(const std::uint16_t x, const std::uint16_t y) const;
	std::uint8_t getPixel(const std::uint16_t index) const;
	void setPixel(const std::uint16_t x, const std::uint16_t y, const std::uint8_t entry);

	void setPixel(const std::uint16_t index, const std::uint8_t entry);

	void resize(const std::uint16_t width, const std::uint16_t height);
};
