#include "Level1.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngine/GameEngine.h>

Level1::Level1()
{
}

Level1::~Level1()
{
}

void Level1::Loading() 
{

}
void Level1::Update() {
	if (true == GameEngineInput::GetInst()->IsDown("HUBWorld"))
	{
		GameEngine::GlobalEngine().ChangeLevel("HUBWorld");
	}

}

void Level1::LevelChangeStart() 
{
}
