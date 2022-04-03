#include "Kirby.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImage.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngine/GameEngineCollision.h>

#include <GameEngine/GameEngineLevel.h> // 레벨을 통해서
#include "Bullet.h"						// 총알을 만들고 싶다.

Kirby::Kirby()
	: Speed_(300.0f)
	, Gravity_(100.0f)
{
}

Kirby::~Kirby()
{
}

void Kirby::Start()
{
	
	SetScale({ 100, 100 });

	PlayerCollision = CreateCollision("PlayerHitBox", {100, 100});

	// GetCollision("PlayerHitBox");

	// 애니메이션을 하나라도 만들면 애니메이션도 재생된다.
	GameEngineRenderer* Render = CreateRenderer();
	// 루프
	Render->SetTransColor(RGB(116, 154, 212));
	Render->CreateAnimation("Kirby_Walk_Right.bmp", "Walk_Right", 0, 3, 0.1f, true);
	Render->ChangeAnimation("Walk_Right");

	if (false == GameEngineInput::GetInst()->IsKey("MoveLeft"))
	{
		// 이때 대문자여야 합니다.
		GameEngineInput::GetInst()->CreateKey("MoveLeft", 'A');
		GameEngineInput::GetInst()->CreateKey("MoveRight", 'D');
		GameEngineInput::GetInst()->CreateKey("MoveUp", 'W');
		GameEngineInput::GetInst()->CreateKey("MoveDown", 'S');
		GameEngineInput::GetInst()->CreateKey("Jump", VK_LSHIFT);
		GameEngineInput::GetInst()->CreateKey("Fire", VK_SPACE);
	}


}

void Kirby::Update()
{
	MapColImage_ = GameEngineImageManager::GetInst()->Find("Level1_1ColMap.bmp");

	if (nullptr == MapColImage_)
	{
		MsgBoxAssert("맵 충돌용 이미지를 찾지 못했습니다.");
	}

	float4 CheckPos;
	float4 MoveDir = float4::ZERO;


	if (true == GameEngineInput::GetInst()->IsPress("MoveRight"))
	{
		MoveDir = float4::RIGHT;
		
	}
	if (true == GameEngineInput::GetInst()->IsPress("MoveLeft"))
	{
		MoveDir = float4::LEFT;
	}

	if (true == GameEngineInput::GetInst()->IsPress("MoveUp"))
	{
		MoveDir = float4::UP;
	}

	if (true == GameEngineInput::GetInst()->IsPress("MoveDown"))
	{
		MoveDir = float4::DOWN;
	}

	{
		float4 NextPos = GetPosition() + (MoveDir * GameEngineTime::GetDeltaTime()* Speed_);
		float4 CheckPos = NextPos + float4(0.0f, 20.0f);

		int Color = MapColImage_->GetImagePixel(CheckPos);

		if (RGB(0, 0, 0) != Color)
		{
			SetMove(MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
		}
	}

	GetLevel()->SetCameraPos(GetPosition() - GameEngineWindow::GetInst().GetScale().Half());


	if (0 > GetLevel()->GetCameraPos().x)
	{
		float4 CurCameraPos = GetLevel()->GetCameraPos();
		CurCameraPos.x = 0;
		GetLevel()->SetCameraPos(CurCameraPos);
	}
	if (0 > GetLevel()->GetCameraPos().y)
	{
		float4 CurCameraPos = GetLevel()->GetCameraPos();
		CurCameraPos.y = 0;
		GetLevel()->SetCameraPos(CurCameraPos);
	}

	float MapSizeX = 3048;
	float MapSizeY = 504;
	float CameraRectX = 768;
	float CameraRectY = 504;


	if (MapSizeX <= GetLevel()->GetCameraPos().x + CameraRectX)
	{
		float4 CurCameraPos = GetLevel()->GetCameraPos();
		CurCameraPos.x = GetLevel()->GetCameraPos().x - (GetLevel()->GetCameraPos().x + CameraRectX - MapSizeX);;
		GetLevel()->SetCameraPos(CurCameraPos);
	}

	// 

	if (MapSizeY <= (GetLevel()->GetCameraPos().y + CameraRectY))
	{
		float4 CurCameraPos = GetLevel()->GetCameraPos();
		CurCameraPos.y = GetLevel()->GetCameraPos().y - (GetLevel()->GetCameraPos().y + CameraRectY - MapSizeY);
		GetLevel()->SetCameraPos(CurCameraPos);
	}

	WallCheck();
	DoorCheck();
	//if (true == PlayerCollision->Collision("Door"))
	//{

	//}

	//{
	//	// 내포지션에서 
	// int Color = MapColImage_->GetImagePixel(GetPosition() + float4(0.0f, 20.0f));


	//	AccGravity_ += GameEngineTime::GetDeltaTime() * Gravity_;
	//	if (RGB(0, 0, 0) == Color)
	//	{
	//		AccGravity_ = 0.0f;
	//	}
	//	SetMove(float4::DOWN * GameEngineTime::GetDeltaTime() * AccGravity_);
	//}


	//if (true == GameEngineInput::GetInst()->GetTime("Fire"))
	//{
	//	Bullet* Ptr = GetLevel()->CreateActor<Bullet>();
	//	Ptr->SetPosition(GetPosition());
	//}


}

// 렌더러가 다 돌아가고 렌더링이 됨
void Kirby::Render()
{
}


void Kirby::WallCheck() 
{
	std::vector<GameEngineCollision*> ColList;

	if (true == PlayerCollision->CollisionResult("Wall", ColList, CollisionType::Rect, CollisionType::Rect))
	{
		for (size_t i = 0; i < ColList.size(); i++)
		{
			ColList[i]->Death();
		}
	}
}

void Kirby::DoorCheck()
{

	if (true == PlayerCollision->CollisionCheck("Door", CollisionType::Rect, CollisionType::Rect))
	{
		GameEngine::GetInst().ChangeLevel("Level2");
	}
}