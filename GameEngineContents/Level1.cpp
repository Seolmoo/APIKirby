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
#include <GameEngine/GameEngineCollision.h>

Level1::Level1()
{
}

Level1::~Level1()
{
}

void Level1::Loading() 
{
	// PlayMove("aaa.avi");
	
	if (true == GameEngineInput::GetInst()->IsDown("HUBWorld"))
	{
		GameEngine::GetInst().ChangeLevel("HUBWorld");
	}

	{
		PlayUI* Actor = CreateActor<PlayUI>(0);
	}

	{
		BackGround* Actor = CreateActor<BackGround>(0);
		Actor->GetRenderer()->SetImage("Level1_1.bmp");

		float4 BackActor = {};
		BackActor.x = (Actor->GetRenderer()->GetImage()->GetScale().Half().x);
		BackActor.y = (Actor->GetRenderer()->GetImage()->GetScale().Half().y);

		Actor->GetRenderer()->SetPivot(BackActor);

		Actor->CreateCollision("Door", { 100, 100 }, {500, 300});

		Actor->CreateCollision("Wall", { 100, 100 }, { 300, 200 });
		// ���α����� �ݸ�ŭ

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


