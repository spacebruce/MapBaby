#include "PaletteManager.h"

PaletteManager::PaletteManager()
{
	Palette arduboy = Palette("Arduboy",2);
	arduboy.add(ColourRGB(0x00, 0x00, 0x00));
	arduboy.add(ColourRGB(0xff, 0xff, 0xff));
	this->addPalette(arduboy);

	Palette amstrad = Palette("Amstrad CPC", 27);
	amstrad.add(ColourRGB(0x00, 0x00, 0x00));	//black
	amstrad.add(ColourRGB(0x00, 0x00, 0x80));	//dark blue
	amstrad.add(ColourRGB(0x00, 0x00, 0xFF));	//blue
	amstrad.add(ColourRGB(0x80, 0x00, 0x00));	//red
	amstrad.add(ColourRGB(0x80, 0x00, 0x80));	//magenta
	amstrad.add(ColourRGB(0x80, 0x00, 0xFF));	//mauve
	amstrad.add(ColourRGB(0xFF, 0x00, 0x00));	//red
	amstrad.add(ColourRGB(0xFF, 0x00, 0x80));	//purple
	amstrad.add(ColourRGB(0xFF, 0x00, 0xFF));	//bright magenta
	amstrad.add(ColourRGB(0x00, 0x80, 0x00));	//green
	amstrad.add(ColourRGB(0x00, 0x80, 0x80));	//cyan
	amstrad.add(ColourRGB(0x00, 0x80, 0xFF));	//sky blue
	amstrad.add(ColourRGB(0x80, 0x80, 0x00));	//mud
	amstrad.add(ColourRGB(0x80, 0x80, 0x80));	//gray
	amstrad.add(ColourRGB(0x80, 0x80, 0xFF));	//pastel blue
	amstrad.add(ColourRGB(0xFF, 0x80, 0x00));	//orange
	amstrad.add(ColourRGB(0xff, 0x80, 0x80));	//Salmon
	amstrad.add(ColourRGB(0xff, 0x80, 0xff));	//Pink
	amstrad.add(ColourRGB(0x00, 0xff, 0x00));	//bright green
	amstrad.add(ColourRGB(0x00, 0xff, 0x80));	//sea green
	amstrad.add(ColourRGB(0x00, 0xFF, 0xFF));	//bright cyan
	amstrad.add(ColourRGB(0x80, 0xff, 0x00));	//lime
	amstrad.add(ColourRGB(0x80, 0xFF, 0x80));	//pastel green
	amstrad.add(ColourRGB(0x80, 0xFF, 0xFF));	//pastel cyan
	amstrad.add(ColourRGB(0xFF, 0xFF, 0x00));	//yellow
	amstrad.add(ColourRGB(0xFF, 0xFF, 0x80));	//pastel yellow
	amstrad.add(ColourRGB(0xFF, 0xFF, 0xFF));	//white

	this->addPalette(amstrad);
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