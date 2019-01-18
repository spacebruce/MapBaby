#include "UIPaletteWindow.h"

UIPaletteWindow::UIPaletteWindow() : WindowBase()
{
}

UIPaletteWindow::UIPaletteWindow(MapManager *mapManager, PaletteManager *paletteManager, TileManager *tileManager, MapEditor *mapEditor) : WindowBase(mapManager, paletteManager, tileManager, mapEditor)
{
}

UIPaletteWindow::~UIPaletteWindow()
{
}

void UIPaletteWindow::update()
{
	if (ImGui::Begin("Palette", &visible))
	{
		//Palette picker
		std::size_t currentPalette = paletteManager->getCurrentIndex();

		if (ImGui::BeginCombo("##PalettePicker", paletteManager->getCurrentPalette()->name.c_str()))
		{
			for (int i = 0; i < paletteManager->getCount(); ++i)
			{
				bool selected = (i == currentPalette);
				if (ImGui::Selectable(paletteManager->getPalette(i)->name.c_str(), selected))
					currentPalette = i;
				if (selected)
					ImGui::SetItemDefaultFocus();
			}
			paletteManager->setCurrent(currentPalette);
			ImGui::EndCombo();
		}

		//New palette
		ImGui::SameLine();
		if (ImGui::Button("+##newpal"))
		{
			paletteManager->addPalette(Palette());
		}

		Palette * palette = paletteManager->getCurrentPalette();

		if (ImGui::CollapsingHeader("Palette settings"))
		{
			//Name editor
			const std::size_t stringMax = 16;
			if (ImGui::InputText("name", const_cast<char*>(palette->name.c_str()), stringMax))
			{
				if (palette->name.length() > stringMax)
				{
					palette->name = palette->name.substr(0, stringMax);
				}
			}

			//Size
			std::uint32_t size = palette->getSize();
			if (ImGui::InputScalar("size", ImGuiDataType_U32, &size))
			{
				palette->setSize(size);
			}

			if (ImGui::Button("delete"))
			{
				paletteManager->deletePalette(paletteManager->getCurrentIndex());
				if (paletteManager->getCount() == 0)
				{
					paletteManager->addPalette(Palette());
				}
			}
		}

		ImGui::BeginChild("PaletteScroll", ImVec2(270, 500), true, 0);

		for (std::size_t i = 0; i < palette->getSize(); ++i)
		{
			ImGui::Text("No. %i", i);
			ImGui::SameLine();

			PaletteEntry colour = palette->getEntry(i);

			const float colScale = 255.0f;
			float tempColours[] = { colour.r / colScale, colour.g / colScale, colour.b / colScale };

			ImGui::PushID(i);

			if (ImGui::ColorEdit3("##picker", tempColours, ImGuiColorEditFlags_RGB))
			{
				colour.r = static_cast<GLubyte>(tempColours[0] * colScale);
				colour.g = static_cast<GLubyte>(tempColours[1] * colScale);
				colour.b = static_cast<GLubyte>(tempColours[2] * colScale);
				palette->set(i, colour);
			}

			ImGui::PopID();
		}

		ImGui::EndChild();

	}
	ImGui::End();
}