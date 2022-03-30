#include "Level1.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngine/GameEngine.h>
#include "BackGround.h"
#include "Kirby.h"
#include "ContentsEnums.h"
#include <GameEngine/GameEngineRenderer.h>
#include "PlayUI.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>

Level1::Level1()
{
}

Level1::~Level1()
{
}

void Level1::Loading() 
{
	if (true == GameEngineInput::GetInst()->IsDown("HUBWorld"))
	{
		GameEngine::GlobalEngine().ChangeLevel("HUBWorld");
	}

	{
		PlayUI* Actor = CreateActor<PlayUI>(0);
	}

	{
		BackGround* Actor = CreateActor<BackGround>(0);
		Actor->GetRenderer()->SetImage("Level1_1.bmp");

		float4 BackActor = {};
		BackActor.x = (Actor->GetRenderer()->GetImage()->GetScale().Half().x) - (GameEngineWindow::GetScale().Half().x);
		BackActor.y = (Actor->GetRenderer()->GetImage()->GetScale().Half().y) - (GameEngineWindow::GetScale().Half().y);

		Actor->GetRenderer()->SetPivot(BackActor);
		// 가로길이의 반만큼

	}

	{
		Kirby* Player = CreateActor<Kirby>((int)ORDER::PLAYER);
		// Player->SetPosition(GameEngineWindow::GetScale().Half());
		Player->SetPosition({100.0f, 100.0f});
	}

}
void Level1::Update() {
}

void Level1::LevelChangeStart() 
{
}

