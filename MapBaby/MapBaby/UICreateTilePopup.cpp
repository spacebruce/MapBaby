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
	if (ImGui::BeginPopup(this->identifier, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoMove))
	{
		//Buttons
		if (ImGui::Button("create"))
		{
			int i = Number;
			while (i > 0)
			{
				tileManager->createTile(tilePreview);
				--i;
			}
			ImGui::CloseCurrentPopup();
		}
		ImGui::SameLine();
		if (ImGui::Button("close"))
		{
			ImGui::CloseCurrentPopup();
		}
		ImGui::Separator();

		//Edit area
		ImGui::BeginChild("thing", ImVec2(300, 140));

		ImGui::Columns(2, nullptr, false);
		ImGui::ImageButton((void*)tilePreview.getTexture()->get(), ImVec2(128, 128));

		ImGui::NextColumn();

		ImGui::InputScalar("Number", ImGuiDataType_U32, &Number);

		ImGui::Checkbox("Lock to map size", &LockSize);

		bool tooltip = false;
		ImGui::InputScalar("Width", ImGuiDataType_U32, &Width);
		tooltip = ImGui::IsItemHovered();
		ImGui::InputScalar("Height", ImGuiDataType_U32, &Height);
		tooltip = (tooltip || ImGui::IsItemHovered());

		if (LockSize)
		{
			Map * map = mapManager->getCurrentMap();
			if (map != nullptr)
			{
				Width = map->getTileSize();
				Height = map->getTileSize();
			}
			if (tooltip)
			{
				ImGui::BeginTooltip();
				ImGui::Text("Locked");
				ImGui::EndTooltip();
			}
		}

		ImGui::EndChild();

		ImGui::EndPopup();
	}
}

void UICreateTilePopup::setTexturePattern()
{
	auto texture = tilePreview.getTexture();
	auto palette = paletteManager->getCurrentPalette();

	std::size_t length = Width * Height;
	std::uint8_t * pixels = new std::uint8_t[length];

	for (std::size_t i = 0; i < length; ++i)
	{
		pixels[i] = i % palette.getSize();
	}

	texture->createFromBitmap(Width, Height, pixels, palette);

	delete pixels;
}