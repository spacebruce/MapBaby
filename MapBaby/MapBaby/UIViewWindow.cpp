#include "UIViewWindow.h"

UIViewWindow::UIViewWindow() : UIWindowBase()
{
}

UIViewWindow::UIViewWindow(MapManager *mapManager, PaletteManager *paletteManager, TileManager *tileManager, MapEditor *mapEditor) : UIWindowBase(mapManager, paletteManager, tileManager, mapEditor)
{
}

UIViewWindow::~UIViewWindow()
{
}

void UIViewWindow::updateContents()
{
	ImGui::Begin("View", &visible, ImGuiWindowFlags_AlwaysAutoResize);

	if (ImGui::CollapsingHeader("Debug"))
	{
		ImGui::Text("mouse x : %f", mapEditor->camera.getMouseX());
		ImGui::Text("mouse y : %f", mapEditor->camera.getMouseY());

		auto cameraBox = mapEditor->camera.getBox();
		ImGui::Text("cam l %f", cameraBox.left);
		ImGui::Text("cam r %f", cameraBox.right);
		ImGui::Text("cam t %f", cameraBox.top);
		ImGui::Text("cam b %f", cameraBox.bottom);
	}

	//Position
	if (ImGui::CollapsingHeader("Position"))
	{
		ImGui::DragInt("x", &(mapEditor->camera.x));
		ImGui::DragInt("y", &(mapEditor->camera.y));
	}

	//Zoom
	if (ImGui::CollapsingHeader("Zoom"))
	{
		ImGui::SliderFloat("###Zoom", &(mapEditor->camera.zoom), 1.0f, 1000.0f, "%.1f", 2.0f);
		ImGui::SameLine();
		if (ImGui::Button("-"))
		{
			mapEditor->camera.zoom -= 50.0f;
		}
		ImGui::SameLine();
		if (ImGui::Button("+"))
		{
			mapEditor->camera.zoom += 50.0f;
		}
		ImGui::SameLine();
		if (ImGui::Button("100%"))
		{
			mapEditor->camera.zoom = 100.0f;
		}
	}

	ImGui::End();
}