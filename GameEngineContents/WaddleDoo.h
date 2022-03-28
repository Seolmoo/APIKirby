#pragma once
#include <GameEngine/GameEngineActor.h>

class WaddleDoo : public GameEngineActor
{
public:
	// constrcuter destructer
	WaddleDoo();
	~WaddleDoo();

	// delete Function
	WaddleDoo(const WaddleDoo& _Other) = delete;
	WaddleDoo(WaddleDoo&& _Other) noexcept = delete;
	WaddleDoo& operator=(const WaddleDoo& _Other) = delete;
	WaddleDoo& operator=(WaddleDoo&& _Other) noexcept = delete;


protected:

private:
	void Start() override;
	void Update() override;

};
