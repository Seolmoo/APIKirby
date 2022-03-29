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
	// 액터를 화면 중간에 놓는다.
	{
		float4 Pos = GameEngineWindow::GetScale().Half();
		SetPosition(Pos);
	}

	
	// 화면 하단 ui 랜더를 만든다.
	{
		GameEngineRenderer* Renderer = CreateRenderer("PlayBotUI.bmp");
		float4 BotUIPivot = GameEngineWindow::GetScale().Half();
		BotUIPivot.x = 0.0f;
		BotUIPivot.y -= Renderer->GetImage()->GetScale().Half().y;
		Renderer->SetPivot(BotUIPivot);
	}

}
