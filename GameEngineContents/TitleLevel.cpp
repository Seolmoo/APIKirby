#include "TitleLevel.h"
#include "GameEngine/GameEngine.h"
#include "TitleIntro.h"
#include "TitleBackGround.h"
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineInput.h>

TitleLevel::TitleLevel()
{
}

TitleLevel::~TitleLevel()
{
}

void TitleLevel::Loading()
{
	CreateActor<TitleIntro>(1);



	
}

void TitleLevel::Update()
{
	if (true == GameEngineInput::GetInst()->IsDown("LevelChange"))
	{
		GameEngine::GlobalEngine().ChangeLevel("HUBWorld");
	}

	// GameEngine::GlobalEngine().ChangeLevel("HUBWorld");
}