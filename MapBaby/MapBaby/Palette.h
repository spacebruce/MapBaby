#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include "Colours.h"

class Palette
{
private:
	std::vector<ColourRGB> palette;
	std::size_t maxSize = 0;
public:
	Palette() = default;
	Palette(std::size_t maxSize);
	Palette(std::string name, std::size_t maxSize);
	~Palette();

	ColourRGB & getEntry(std::size_t index);
	std::size_t getSize(void);

	void setSize(std::size_t size);

	void set(std::size_t index, ColourRGB entry);
	void add(ColourRGB entry);
	void remove(std::size_t index);

	std::string name;
};