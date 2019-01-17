#include "PaletteManager.h"

PaletteManager::PaletteManager()
{
	Palette arduboy = Palette("Arduboy",2);
	arduboy.add(PaletteEntry(0x00, 0x00, 0x00));
	arduboy.add(PaletteEntry(0xff, 0xff, 0xff));

	this->addPalette(arduboy);
}

Palette * PaletteManager::getCurrentPalette()
{
	if (this->empty())
		return nullptr;
	return &(this->palettes[this->current]);
}

void PaletteManager::setCurrent(std::size_t index)
{
	this->current = index;
}

std::size_t PaletteManager::getCurrentIndex()
{
	return this->current;
}

Palette * PaletteManager::getPalette(std::size_t index)
{
	if (index > this->getCount())
		return nullptr;
	return &palettes[index];
}

void PaletteManager::addPalette(Palette & palette)
{
	this->palettes.push_back(palette);
}

void PaletteManager::deletePalette(const std::size_t index)
{
	if (index < this->getCount())
	{
		this->palettes.erase(palettes.begin() + index);

		if ((this->current != 0) && (this->current >= index))
		{
			this->current--;
		}
	}

}

bool PaletteManager::empty()
{
	return (this->getCount() == 0);
}

std::size_t PaletteManager::getCount()
{
	return palettes.size();
}