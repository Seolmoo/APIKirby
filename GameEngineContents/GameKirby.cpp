#include "GameKirby.h"
#include "HUBWorld.h"
#include "EndingLevel.h"
#include "TitleLevel.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineBase/GameEngineFile.h>
#include <GameEngine/GameEngineImageManager.h>

GameKirby::GameKirby()
{
}

GameKirby::~GameKirby()
{
}

void GameKirby::GameInit()
{
	// 원본사이즈 * 3 
	GameEngineWindow::GetInst().SetWindowScaleAndPosition({ 300, 10 }, { 768, 720 });

	// 커비
	GameEngineDirectory ResourcesDir;
	ResourcesDir.MoveParent("APIKirby");
	ResourcesDir.Move("Kirby_Resources");
	ResourcesDir.Move("Actor");
	ResourcesDir.Move("Kirby");

	// 폴더안에 모든 이미지 파일을 찾는다.
	std::vector<GameEngineFile> AllImageFileList = ResourcesDir.GetAllFile("Bmp");

	for (size_t i = 0; i < AllImageFileList.size(); i++)
	{
		GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
	}

	// Level
	ResourcesDir.MoveParent("APIKirby");
	ResourcesDir.Move("Kirby_Resources");
	ResourcesDir.Move("Level");

	AllImageFileList = ResourcesDir.GetAllFile("Bmp");
	for (size_t i = 0; i < AllImageFileList.size(); i++)
	{
		GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
	}


	GameEngineImage* KirbyImage = GameEngineImageManager::GetInst()->Find("Kirby_Idle_Right.bmp");
	KirbyImage->Cut({ 48, 48 });



	CreateLevel<TitleLevel>("Title");
	CreateLevel<HUBWorld>("HUBWorld");
	// CreateLevel<EndingLevel>("Ending");
	ChangeLevel("HUBWorld");
}

void GameKirby::GameLoop()
{
}

void GameKirby::GameEnd()
{
}
