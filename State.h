#ifndef STATE_H
#define STATE_H
/**
*Abstract class where the derivatives of it will be the stages of the game.
*/
class State {
public:
	
	virtual ~State(){};
	virtual void Init() = 0;
	virtual void HandleInput() = 0;
	virtual void Update(float deltaTime) = 0;

	virtual void Draw(float deltaTime) = 0;
	virtual void Pause() {}
	virtual void Resume() {}
};

#endif