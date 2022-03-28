#pragma once
#include <GameEngine/GameEngineLevel.h>

class HUBWorld : public GameEngineLevel
{
public:
	// constrcuter destructer
	HUBWorld();
	~HUBWorld();

	// delete Function
	HUBWorld(const HUBWorld& _Other) = delete;
	HUBWorld(HUBWorld&& _Other) noexcept = delete;
	HUBWorld& operator=(const HUBWorld& _Other) = delete;
	HUBWorld& operator=(HUBWorld&& _Other) noexcept = delete;

protected:
	void Loading() override;
	void Update() override;
	void LevelChangeStart() override;

private:

};

