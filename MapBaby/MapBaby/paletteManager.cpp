#include "PaletteManager.h"

PaletteManager::PaletteManager()
{
	Palette arduboy = Palette("Arduboy",2);
	arduboy.add(PaletteEntry(0x00, 0x00, 0x00));
	arduboy.add(PaletteEntry(0xff, 0xff, 0xff));

	palettes.push_back(arduboy);
}

Palette & PaletteManager::getCurrent()
{
	return this->palettes[this->current];
}

void PaletteManager::setCurrent(std::size_t index)
{
	this->current = index;
}

std::size_t PaletteManager::getCurrentIndex()
{
	return this->current;
}

Palette & PaletteManager::getPalette(std::size_t index)
{
	return palettes[index];
}

std::size_t PaletteManager::getCount()
{
	return palettes.size();
}