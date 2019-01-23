#include "UIFileTabWindow.h"


UIFileTabWindow::UIFileTabWindow() : UIWindowBase()
{
}

UIFileTabWindow::UIFileTabWindow(MapManager *mapManager, PaletteManager *paletteManager, TileManager *tileManager, MapEditor *mapEditor) : UIWindowBase(mapManager, paletteManager, tileManager, mapEditor)
{
	newFilePopup = UINewFileDialogue(mapManager, paletteManager, tileManager, mapEditor);
}

UIFileTabWindow::~UIFileTabWindow()
{
}

void UIFileTabWindow::updateContents()
{
	ImGui::Begin("Tabs", &visible, ImGuiWindowFlags_AlwaysAutoResize);

	ImGui::Text("Current : %i", mapManager->getCurrent());

	if (ImGui::Button("-"))
	{
		mapManager->deselect();
		mapEditor->changeMap(nullptr);
	}
	ImGui::SameLine();

	for (auto i = 0; i < mapManager->getCount(); ++i)
	{
		ImGui::PushID(static_cast<std::uint64_t>(mapManager->getMap(i)->getID()));

		const char* name = mapManager->getMap(i)->name.c_str();

		if (ImGui::ButtonDisable(name, !mapManager->isCurrent(i)))
		{
			mapManager->setCurrent(i);
			mapEditor->changeMap(mapManager->getMap(i));
		}
		ImGui::SameLine();
		if (ImGui::Button("x"))
		{
			if (mapManager->isCurrent(i))
			{
				mapEditor->changeMap(nullptr);
			}
			mapManager->closeMap(i);
		}
		ImGui::SameLine();

		ImGui::PopID();
	}
	if (ImGui::Button("+"))
	{
		newFilePopup.open();
		//mapManager->newMap();
		//selectMap(mapManager->getCount() - 1);
	}
	ImGui::End();

	newFilePopup.update();
}