#include "BossLevel.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngine/GameEngine.h>
BossLevel::BossLevel()
{
}

BossLevel::~BossLevel()
{
}

void BossLevel::Loading()
{

}
void BossLevel::Update() {
	if (true == GameEngineInput::GetInst()->IsDown("HUBWorld"))
	{
		GameEngine::GlobalEngine().ChangeLevel("HUBWorld");
	}
}

void BossLevel::LevelChangeStart() {

}

