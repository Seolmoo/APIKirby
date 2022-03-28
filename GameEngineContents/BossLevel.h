#pragma once
#include <GameEngine/GameEngineLevel.h>

class BossLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	BossLevel();
	~BossLevel();

	// delete Function
	BossLevel(const BossLevel& _Other) = delete;
	BossLevel(BossLevel&& _Other) noexcept = delete;
	BossLevel& operator=(const BossLevel& _Other) = delete;
	BossLevel& operator=(BossLevel&& _Other) noexcept = delete;

protected:
	void Loading() override;
	void Update() override;
	void LevelChangeStart() override;

private:

};

