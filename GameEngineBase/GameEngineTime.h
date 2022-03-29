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

	// ���� �ǵ��� ������ ����� ���� 
	// pointer�� ����

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
		// ���� ����� �Ҵ�ٷξ����ָ� �����־�ߵ�
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
