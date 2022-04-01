#include "HUBWorld.h"
#include "Kirby.h"
#include "BackGround.h"
#include "ContentsEnums.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineRenderer.h>


HUBWorld::HUBWorld()
{
}

HUBWorld::~HUBWorld()
{
}

void HUBWorld::Loading()
{
	BackGround* Back =  CreateActor<BackGround>(0);
	Back->GetRenderer()->SetImage("HUB_World.bmp");
	CreateActor<Kirby>((int)ORDER::PLAYER);
}

void HUBWorld::Update()
{
	if (true == GameEngineInput::GetInst()->IsDown("Level1"))
	{
		GameEngine::GetInst().ChangeLevel("Level1");
	}

	if (true == GameEngineInput::GetInst()->IsDown("Level2"))
	{
		GameEngine::GetInst().ChangeLevel("Level2");
	}

	if (true == GameEngineInput::GetInst()->IsDown("BossLevel"))
	{
		GameEngine::GetInst().ChangeLevel("BossLevel");
	}
}

void HUBWorld::LevelChangeStart()
{
}
