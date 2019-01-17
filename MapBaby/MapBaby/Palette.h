#pragma once
#include <string>
#include <vector>
#include "PaletteEntry.h"

class Palette
{
private:
	std::vector<PaletteEntry> palette;
	int maxSize = 2;
public:
	Palette();
	~Palette();

	PaletteEntry getEntry(std::size_t index);
	int getSize(void);

	void setSize(std::size_t size);

	void add(PaletteEntry entry);
	void remove(std::size_t index);

	std::string Name;
};