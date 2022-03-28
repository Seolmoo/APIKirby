#pragma once
#include <GameEngine/GameEngineActor.h>

// Ό³Έν :
class Kirby : public GameEngineActor
{
public:
	// constrcuter destructer
	Kirby();
	~Kirby();

	// delete Function
	Kirby(const Kirby& _Other) = delete;
	Kirby(Kirby&& _Other) noexcept = delete;
	Kirby& operator=(const Kirby& _Other) = delete;
	Kirby& operator=(Kirby&& _Other) noexcept = delete;

protected:

private:
	float Speed_;

	void Start() override;
	void Update() override;
	void Render() override;
};


