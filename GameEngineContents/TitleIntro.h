#pragma once
#include <GameEngine/GameEngineActor.h>

class TitleIntro : public GameEngineActor
{
public:
	// constrcuter destructer
	TitleIntro();
	~TitleIntro();

	// delete Function
	TitleIntro(const TitleIntro& _Other) = delete;
	TitleIntro(TitleIntro&& _Other) noexcept = delete;
	TitleIntro& operator=(const TitleIntro& _Other) = delete;
	TitleIntro& operator=(TitleIntro&& _Other) noexcept = delete;

protected:
	void Start();
	void Render();

private:

};

