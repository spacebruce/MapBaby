#include "UIPaletteWindow.h"

UIPaletteWindow::UIPaletteWindow() : UIWindowBase()
{
}

UIPaletteWindow::UIPaletteWindow(MapManager *mapManager, PaletteManager *paletteManager, TileManager *tileManager, MapEditor *mapEditor) : UIWindowBase(mapManager, paletteManager, tileManager, mapEditor)
{
}

UIPaletteWindow::~UIPaletteWindow()
{
}

void UIPaletteWindow::updateContents()
{
	if (ImGui::Begin("Palette", &visible, ImGuiWindowFlags_AlwaysAutoResize))
	{
		//Palette picker
		std::size_t currentPalette = paletteManager->getCurrentIndex();

		if (ImGui::BeginCombo("##PalettePicker", paletteManager->getCurrentPalette().name.c_str()))
		{
			for (std::size_t i = 0; i < paletteManager->getCount(); ++i)
			{
				bool selected = (i == currentPalette);
				if (ImGui::Selectable(paletteManager->getPalette(i).name.c_str(), selected))
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

		Palette& palette = paletteManager->getCurrentPalette();

		if (ImGui::CollapsingHeader("Settings"))
		{
			//Name editor
			ImGui::InputText("name", &palette.name);

			//Size
			std::uint32_t size = palette.getSize();
			if (ImGui::InputScalar("size", ImGuiDataType_U32, &size))
			{
				palette.setSize(size);
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

		if (ImGui::CollapsingHeader("Palette"))
		{
			ImGui::BeginChild("PaletteScroll", ImVec2(240, 300), true, 0);
			for (std::size_t i = 0; i < palette.getSize(); ++i)
			{
				ImGui::Text("%03i", i);
				ImGui::SameLine();

				ColourRGB colour = palette.getEntry(i);

				const float colScale = 255.0f;
				float tempColours[] = { colour.r / colScale, colour.g / colScale, colour.b / colScale };

				ImGui::PushID(i);

				if (ImGui::ColorEdit3("##picker", tempColours, ImGuiColorEditFlags_RGB))
				{
					colour.r = static_cast<GLubyte>(tempColours[0] * colScale);
					colour.g = static_cast<GLubyte>(tempColours[1] * colScale);
					colour.b = static_cast<GLubyte>(tempColours[2] * colScale);
					palette.set(i, colour);
				}

				ImGui::PopID();
			}
			ImGui::EndChild();
		}

	}
	ImGui::End();
}