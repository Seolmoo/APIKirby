#pragma once
class GameEngineTime
{

private:
	static GameEngineTime* Inst_;

public:
	static GameEngineTime* GetInst()
	{
		return Inst_;
	}

	// 내가 의도한 순서로 지우기 위해 
	// pointer로 삭제

	static void Destroy()
	{
		if (nullptr != Inst_)
		{
			delete Inst_;
			Inst_ = nullptr;
		}
	}


public:
	void Reset();
	void Update();

	static inline float GetDeltaTime()
	{
		// 만약 만들고 할당바로안해주면 꼭해주어야됨
		//if (nullptr == Inst_)
		//{
		//	Inst_ = new GameEngineTime();
		//}

		return Inst_->DeltaTime_;
	}

protected:

private:
	__int64 SecondCount_;
	__int64 CurrentCount_;
	__int64 PrevCount_;
	float DeltaTime_;
	double RealDeltaTime_;


	GameEngineTime();
	~GameEngineTime();
	GameEngineTime(const GameEngineTime& _Other) = delete;
	GameEngineTime(GameEngineTime&& _Other) noexcept = delete;
	GameEngineTime& operator=(const GameEngineTime& _Other) = delete;
	GameEngineTime& operator=(GameEngineTime&& _Other) noexcept = delete;
};

