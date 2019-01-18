#include "UIFileTabWindow.h"


UIFileTabWindow::UIFileTabWindow() : WindowBase()
{
}

UIFileTabWindow::UIFileTabWindow(MapManager *mapManager, PaletteManager *paletteManager, TileManager *tileManager, MapEditor *mapEditor) : WindowBase(mapManager, paletteManager, tileManager, mapEditor)
{
}

UIFileTabWindow::~UIFileTabWindow()
{
}

void UIFileTabWindow::update()
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

		if (mapManager->isCurrent(i))
		{
			ImGui::Text("test");
		}
		else if (ImGui::Button("test"))
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
		mapManager->newMap();
		//selectMap(mapManager->getCount() - 1);
	}
	ImGui::End();
}