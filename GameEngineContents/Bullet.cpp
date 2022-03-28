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
	GameEngineRenderer* Bullet = CreateRenderer("Kirby_Bullet1.bmp");
	Bullet->SetTransColor(RGB(116, 154, 212));
	
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