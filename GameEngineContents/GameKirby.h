#pragma once
#include <GameEngine/GameEngine.h>

class GameKirby : public GameEngine
{
public:
	// constrcuter destructer
	GameKirby();
	~GameKirby();

	// delete Function
	GameKirby(const GameKirby& _Other) = delete;
	GameKirby(GameKirby&& _Other) noexcept = delete;
	GameKirby& operator=(const GameKirby& _Other) = delete;
	GameKirby& operator=(GameKirby&& _Other) noexcept = delete;

	void GameInit() override;
	void GameLoop() override;
	void GameEnd() override;

protected:

private:
};

