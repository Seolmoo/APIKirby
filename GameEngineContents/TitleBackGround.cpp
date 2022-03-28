#include "TitleBackGround.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImage.h>
#include <GameEngine/GameEngineImageManager.h>

TitleBackGround::TitleBackGround()
{
	// Level_ = nullptr;
}

TitleBackGround::~TitleBackGround()
{
}

void TitleBackGround::Start()
{	
	//
	SetPosition(GameEngineWindow::GetScale().Half());
	SetScale(GameEngineWindow::GetScale());
	
	CreateRenderer("Kirby_Title.bmp");
}

void TitleBackGround::Render()
{
	
	// DebugRectRender();
}