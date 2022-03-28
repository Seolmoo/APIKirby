#include "HUBWorld.h"
#include "Kirby.h"
#include "TitleBackGround.h"

enum class ORDER
{
	BACKGROUND,
	PLAYER,
	MONSTER,

};

HUBWorld::HUBWorld()
{
}

HUBWorld::~HUBWorld()
{
}

void HUBWorld::Loading()
{
	CreateActor<TitleBackGround>(0);
}

void HUBWorld::Update()
{
}

void HUBWorld::LevelChangeStart()
{
	CreateActor<Kirby>((int)ORDER::PLAYER);
}
