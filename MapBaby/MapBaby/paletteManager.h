#pragma once

#include <vector>
#include "Palette.h"

class PaletteManager
{
private:
	std::vector<Palette> palettes;
	std::size_t current = 0;
public:
	PaletteManager();
	~PaletteManager() = default;

	Palette & getCurrent();
	void setCurrent(std::size_t index);

	std::size_t getCurrentIndex();
	Palette & getPalette(std::size_t index);

	std::size_t getCount();
};