#pragma once
#include <string>
#include <vector>
#include "PaletteEntry.h"

class Palette
{
private:
	std::vector<PaletteEntry> palette;
	std::size_t maxSize = 2;
public:
	Palette() = default;
	Palette(std::size_t maxSize);
	Palette(std::string name, std::size_t maxSize);
	~Palette();

	PaletteEntry getEntry(std::size_t index);
	int getSize(void);

	void setSize(std::size_t size);

	void set(std::size_t index, PaletteEntry entry);
	void add(PaletteEntry entry);
	void remove(std::size_t index);

	std::string name;
};