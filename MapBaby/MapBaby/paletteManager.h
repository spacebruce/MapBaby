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

	std::size_t getCurrentIndex();
	Palette& getCurrentPalette();
	Palette& getPalette(std::size_t index);

	void setCurrent(std::size_t index);

	void addPalette(Palette & palette);
	void deletePalette(const std::size_t index);

	bool empty();

	std::size_t getCount();
};