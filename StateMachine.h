#pragma once

#include <memory>
#include <stack>

#include "State.h"

using StateRef = std::unique_ptr<State>; /**< Pointer to every state, named StateRef */


/**
*	StateMachine class, this class will handle all of the differents states of the game.
*/
class StateMachine 
{
public:
	StateMachine();
	~StateMachine();
	/*! \brief Adds a game state to the stack.
 	*  
 	*@param newState Is a unique pointer to the state being added.
 	*@param isReplacing If the state is replacing there is no need of the argument, otherwise change it to false.
	 */
	void AddState(StateRef newState, bool isReplacing = true);
	/*!
 	Removes a state from the game stack.
	*/
	void RemoveState();
	/*!
 	Updates the game stack.
	*/
	void ProcessStateChange();

	/*!
 	Returns a referense to the active state.
	*/
	StateRef &GetActiveState();

private:

	std::stack<StateRef> _states;
	StateRef _newState;

	bool _isRemoving;
	bool _isAdding;
	bool _isReplacing;

};

