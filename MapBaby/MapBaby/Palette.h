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

	PaletteEntry getEntry(int index);
	int getSize(void);

	void setSize(int size);

	void add(PaletteEntry entry);
	void remove(int index);

	std::string Name;
};