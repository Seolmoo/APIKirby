#include "GameEngineActor.h"
#include "GameEngine/GameEngine.h"
#include <GameEngineBase/GameEngineWindow.h>
#include "GameEngineRenderer.h"
#include "GameEngineCollision.h"


GameEngineActor::GameEngineActor()
	: Level_(nullptr)
{
	// delete this;
}

GameEngineActor::~GameEngineActor()
{
	{
		std::list<GameEngineRenderer*>::iterator StartIter = RenderList_.begin();
		std::list<GameEngineRenderer*>::iterator EndIter = RenderList_.end();

		for (; StartIter != EndIter; ++StartIter)
		{
			if (nullptr == (*StartIter))
			{
				continue;
			}
			delete (*StartIter);
			(*StartIter) = nullptr;
		}
	}

	{
		std::list<GameEngineCollision*>::iterator StartIter = CollisionList_.begin();
		std::list<GameEngineCollision*>::iterator EndIter = CollisionList_.end();

		for (; StartIter != EndIter; ++StartIter)
		{
			if (nullptr == (*StartIter))
			{
				continue;
			}
			delete (*StartIter);
			(*StartIter) = nullptr;
		}
	}
}

void GameEngineActor::DebugRectRender()
{
	// 선생님은 기본적으로 중앙을 기준으로하는걸 좋아합니다.

	GameEngineRect DebugRect(Position_, Scale_);


	Rectangle(
		GameEngine::BackBufferDC(),
		DebugRect.CenterLeft(),
		DebugRect.CenterTop(),
		DebugRect.CenterRight(),
		DebugRect.CenterBot()
	);
}

GameEngineRenderer* GameEngineActor::CreateRenderer(RenderPivot _PivotType /*= RenderPivot::CENTER*/, const float4& _PivotPos /*= { 0,0 }*/)
{
	GameEngineRenderer* NewRenderer = new GameEngineRenderer();

	NewRenderer->SetActor(this);
	// NewRenderer->SetImage(_Image);
	NewRenderer->SetPivot(_PivotPos);
	NewRenderer->SetPivotType(_PivotType);

	RenderList_.push_back(NewRenderer);
	return NewRenderer;

}


GameEngineRenderer* GameEngineActor::CreateRenderer(
	const std::string& _Image,
	RenderPivot _PivotType /*= RenderPivot::CENTER*/,
	const float4& _PivotPos /*= { 0,0 }*/
)
{
	GameEngineRenderer* NewRenderer = new GameEngineRenderer();

	NewRenderer->SetActor(this);
	NewRenderer->SetImage(_Image);
	NewRenderer->SetPivot(_PivotPos);
	NewRenderer->SetPivotType(_PivotType);

	RenderList_.push_back(NewRenderer);
	return NewRenderer;
}

void GameEngineActor::Renderering()
{
	StartRenderIter = RenderList_.begin();
	EndRenderIter = RenderList_.end();

	for (; StartRenderIter != EndRenderIter; ++StartRenderIter)
	{
		if (false == (*StartRenderIter)->IsUpdate())
		{
			continue;
		}

		(*StartRenderIter)->Render();
	}
}

GameEngineRenderer* GameEngineActor::CreateRendererToScale(
	const std::string& _Image, const float4& _Scale,
	RenderPivot _PivotType /*= RenderPivot::CENTER*/, const float4& _PivotPos /*= { 0,0 }*/
)
{
	GameEngineRenderer* NewRenderer = new GameEngineRenderer();

	NewRenderer->SetActor(this);
	NewRenderer->SetImage(_Image);
	NewRenderer->SetScale(_Scale);
	NewRenderer->SetPivot(_PivotPos);
	NewRenderer->SetPivotType(_PivotType);

	RenderList_.push_back(NewRenderer);
	return NewRenderer;
}

GameEngineCollision* GameEngineActor::CreateCollision(const std::string& _GroupName, float4 _Scale, float4 _Pivot /*= { 0, 0 }*/)
{
	GameEngineCollision* NewCollision = new GameEngineCollision();
	NewCollision->SetActor(this);
	NewCollision->SetPivot(_Pivot);
	NewCollision->SetScale(_Scale);

	GetLevel()->AddCollision(_GroupName, NewCollision);
	CollisionList_.push_back(NewCollision);
	return NewCollision;
}

void GameEngineActor::Release() 
{
	{
		std::list<GameEngineRenderer*>::iterator StartIter = RenderList_.begin();
		std::list<GameEngineRenderer*>::iterator EndIter = RenderList_.end();

		for (; StartIter != EndIter;)
		{
			if (false == (*StartIter)->IsDeath())
			{
				++StartIter;
				continue;
			}

			delete (*StartIter);
			StartIter = RenderList_.erase(StartIter);
		}
	}

	{
		std::list<GameEngineCollision*>::iterator StartIter = CollisionList_.begin();
		std::list<GameEngineCollision*>::iterator EndIter = CollisionList_.end();

		for (; StartIter != EndIter;)
		{
			if (false == (*StartIter)->IsDeath())
			{
				++StartIter;
				continue;
			}

			delete (*StartIter);
			StartIter = CollisionList_.erase(StartIter);
		}
	}


}