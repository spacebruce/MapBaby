#include "UICreateTilePopup.h"

UICreateTilePopup::UICreateTilePopup(MapManager *mapManager, PaletteManager *paletteManager, TileManager *tileManager, MapEditor *mapEditor) : UIPopupBase("Create Tile", mapManager, paletteManager, tileManager, mapEditor)
{
}

UICreateTilePopup::UICreateTilePopup()
{
}

UICreateTilePopup::~UICreateTilePopup()
{
}

void UICreateTilePopup::reset()
{
	Number = 1;
	Width = 16;
	Height = 16;
	LockSize = true;

	setTexturePattern();
}

void UICreateTilePopup::updateContents()
{
	if (ImGui::BeginPopup(this->identifier, ImGuiWindowFlags_NoMove))
	{
		Map * map = mapManager->getCurrentMap();

		//Buttons
		if (ImGui::Button("create"))
		{
			int i = Number;
			while (i > 0)
			{
				tileManager->createTile(paletteManager->getCurrentPalette(), tilePreview);
				--i;
			}
			ImGui::CloseCurrentPopup();
		}
		ImGui::SameLine();
		if (ImGui::Button("close"))
		{
			ImGui::CloseCurrentPopup();
		}

		ImGui::SameLine(162.0f);
		ImGui::PushItemWidth(100.0f);
		if (ImGui::InputInt("Number", &Number))
		{
			if (Number < 1)	Number = 1;
		}

		ImGui::Separator();

		ImGui::BeginChild("body", ImVec2(300, 140));

		ImGui::Columns(2, nullptr, false);

		//Preview area
		ImGui::ImageButton(ImTextureID(tilePreview.texture.get()), ImVec2(128, 128));
		ImGui::NextColumn();

		//Edit area
		Dirty = false;
		bool tooltip = false;

		ImGui::Checkbox("Lock to map size", &LockSize);

		Dirty = ImGui::InputInt("Width", &Width);
		tooltip = ImGui::IsItemHovered();
		Dirty = (Dirty || ImGui::InputInt("Height", &Height));
		tooltip = (tooltip || ImGui::IsItemHovered());

		if (LockSize)
		{
			Dirty = false;
			if (map != nullptr)
			{
				if ((Width != map->getTileWidth()) || (Height != map->getTileHeight()))
				{
					Dirty = true;
				}
				Width = map->getTileWidth();
				Height = map->getTileHeight();
			}
			if (tooltip)
			{
				ImGui::BeginTooltip();
				ImGui::Text("Locked");
				ImGui::EndTooltip();
			}
		}

		ImGui::EndChild();

		if (Dirty)
		{
			setTexturePattern();
		}

		ImGui::EndPopup();
	}
}

void UICreateTilePopup::setTexturePattern()
{
	if ((Width) < 1 && (Height < 1))
		return;

	auto palette = paletteManager->getCurrentPalette();

	std::size_t length = Width * Height;
	Bitmap bitmap = Bitmap(Width, Height);

	for (std::size_t i = 0; i < length; ++i)
	{
		bitmap.setPixel(i, i % palette.getSize());
	}

	tilePreview.bitmap = bitmap;
	tilePreview.texture.createFromBitmap(bitmap, palette);
}