#include "Kirby.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImage.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngine/GameEngineCollision.h>

#include <GameEngine/GameEngineLevel.h> // ������ ���ؼ�
#include "Bullet.h"						// �Ѿ��� ����� �ʹ�.

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

	// �ִϸ��̼��� �ϳ��� ����� �ִϸ��̼ǵ� ����ȴ�.
	PlayerAnimationRender = CreateRenderer();
	// ����
	PlayerAnimationRender->SetTransColor(RGB(116, 154, 212));
	PlayerAnimationRender->CreateAnimation("Kirby_Walk_Right.bmp", "Walk_Right", 0, 3, 0.1f, true);
	PlayerAnimationRender->CreateAnimation("Kirby_Walk_Right.bmp", "Walk_Left", 0, 3, 0.1f, true);
	PlayerAnimationRender->ChangeAnimation("Walk_Right");

	AnimationName = "Walk_";
	CurDir_ = PlayerDir::Right;

	if (false == GameEngineInput::GetInst()->IsKey("MoveLeft"))
	{
		// �̶� �빮�ڿ��� �մϴ�.
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
	DirAnimationCheck();
	PlayerStateUpdate();

	MapColImage_ = GameEngineImageManager::GetInst()->Find("Level1_1ColMap.bmp");

	if (nullptr == MapColImage_)
	{
		MsgBoxAssert("�� �浹�� �̹����� ã�� ���߽��ϴ�.");
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
	//	// �������ǿ��� 
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

// �������� �� ���ư��� �������� ��
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

void Kirby::DirAnimationCheck()
{
	std::string ChangeName;

	PlayerDir CheckDir_ = CurDir_;
	std::string ChangeDirText = "Right";

	if (true == GameEngineInput::GetInst()->IsPress("MoveRight"))
	{
		CheckDir_ = PlayerDir::Right;
		ChangeDirText = "Right";
	}


	if (true == GameEngineInput::GetInst()->IsPress("MoveLeft"))
	{
		CheckDir_ = PlayerDir::Left;
		ChangeDirText = "Left";
	}

	if (CheckDir_ != CurDir_)
	{
		PlayerAnimationRender->ChangeAnimation(AnimationName + ChangeDirText);
	}

}


void Kirby::PlayerStateUpdate()
{

}