#include "Level1.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngine/GameEngine.h>
#include "BackGround.h"
#include "Kirby.h"
#include "ContentsEnums.h"
#include <GameEngine/GameEngineRenderer.h>
#include "PlayUI.h"

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

	PlayUI* Back = CreateActor<PlayUI>(0);

	BackGround* Back = CreateActor<BackGround>(0);
	Back->GetRenderer()->SetImage("Level1_1.bmp");

	// CreateActor<Kirby>((int)ORDER::PLAYER);

}
void Level1::Update() {
}

void Level1::LevelChangeStart() 
{
}

