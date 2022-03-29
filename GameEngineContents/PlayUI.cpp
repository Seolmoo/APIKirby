#include "PlayUI.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngine/GameEngineImageManager.h>

PlayUI::PlayUI() 
{
}

PlayUI::~PlayUI() 
{
}

void PlayUI::Start()
{
	// ���͸� ȭ�� �߰��� ���´�.
	{
		float4 Pos = GameEngineWindow::GetScale().Half();
		SetPosition(Pos);
	}

	
	// ȭ�� �ϴ� ui ������ �����.
	{
		GameEngineRenderer* Renderer = CreateRenderer("HUD_Base.bmp");
		float4 BotUIPivot = GameEngineWindow::GetScale().Half();
		BotUIPivot.x = 0.0f;
		BotUIPivot.y -= Renderer->GetImage()->GetScale().Half().y;
		Renderer->SetPivot(BotUIPivot);
	}

}
