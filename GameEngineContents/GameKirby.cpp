#include "GameKirby.h"
#include "HUBWorld.h"
#include "EndingLevel.h"
#include "TitleLevel.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineBase/GameEngineFile.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngineBase/GameEngineInput.h>
#include "Level1.h"
#include "Level2.h"
#include "BossLevel.h"

GameKirby::GameKirby()
{
}

GameKirby::~GameKirby()
{
}

void GameKirby::GameInit()
{
	// ���������� * 3 
	GameEngineWindow::GetInst().SetWindowScaleAndPosition({ 300, 10 }, { 768, 672 });

	{
		// Ŀ��
		GameEngineDirectory ResourcesDir;
		ResourcesDir.MoveParent("APIKirby");
		ResourcesDir.Move("Kirby_Resources");
		ResourcesDir.Move("Actor");
		ResourcesDir.Move("Kirby");

		// �����ȿ� ��� �̹��� ������ ã�´�.
		std::vector<GameEngineFile> AllImageFileList = ResourcesDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
		}

		{
			GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Kirby_Walk_Right.bmp");
			Image->CutCount( 4, 1 );
		}
	}

	{
		// Ŀ��
		GameEngineDirectory ResourcesDir;
		ResourcesDir.MoveParent("APIKirby");
		ResourcesDir.Move("Kirby_Resources");
		ResourcesDir.Move("Level");

		// �����ȿ� ��� �̹��� ������ ã�´�.
		std::vector<GameEngineFile> AllImageFileList = ResourcesDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
		}
	}

	{
		// Ŀ��
		GameEngineDirectory ResourcesDir;
		ResourcesDir.MoveParent("APIKirby");
		ResourcesDir.Move("Kirby_Resources");
		ResourcesDir.Move("UI");

		// �����ȿ� ��� �̹��� ������ ã�´�.
		std::vector<GameEngineFile> AllImageFileList = ResourcesDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
		}
	}








	if (false == GameEngineInput::GetInst()->IsKey("Level1"))
	{
		GameEngineInput::GetInst()->CreateKey("Level1", '1');
		GameEngineInput::GetInst()->CreateKey("Level2", '2');
		GameEngineInput::GetInst()->CreateKey("BossLevel", '3');
		GameEngineInput::GetInst()->CreateKey("HUBWorld", 'P');
	}




	//GameEngineImage* KirbyImage = GameEngineImageManager::GetInst()->Find("Kirby_Idle_Right.bmp");
	//KirbyImage->Cut({ 48, 48 });



	CreateLevel<TitleLevel>("Title");
	CreateLevel<HUBWorld>("HUBWorld");
	CreateLevel<Level1>("Level1");
	CreateLevel<Level2>("Level2");
	CreateLevel<BossLevel>("BossLevel");
	ChangeLevel("Level1");
}

void GameKirby::GameLoop()
{
}

void GameKirby::GameEnd()
{
}
