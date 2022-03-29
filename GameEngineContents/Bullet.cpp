#include "Bullet.h"
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngine/GameEngineImageManager.h>


Bullet::Bullet()
	: Time()
{
	
}

Bullet::~Bullet()
{
}

void Bullet::Start()
{
	GameEngineImage* StarBullet = GameEngineImageManager::GetInst()->Find("Kirby_StarBullet.bmp");
	StarBullet->CutCount(4, 1);

	GameEngineRenderer* StarBulletRender = CreateRenderer();
	// ·çÇÁ

	StarBulletRender->CreateAnimation("Kirby_StarBullet.bmp", "StarBullet", 0, 3, 0.1f, true);
	StarBulletRender->ChangeAnimation("StarBullet");
	StarBulletRender->SetTransColor(RGB(116, 154, 212));
	Death(2.0f);
}

void Bullet::Update()
{

	//Time -= GameEngineTime::GetDeltaTime();

	//if (0.0f >= Time)
	//{
	//	Death();
	//	return;
	//}

	SetMove(float4::RIGHT * GameEngineTime::GetDeltaTime() * 200.0f);
}