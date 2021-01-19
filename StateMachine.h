

// State struct
typedef struct{
	void(*Enter)(void*);
	void(*Exit)();
	void(*Update)(float);
	char *name;
}State;

//StateMachine struct
typedef struct{
	State *state;
	State *stateList;
}StateMachine;

void change_state(StateMachine *sm, int stateIndex, void *data){
	sm->state->Exit();
	sm->state = &sm->stateList[stateIndex];
	sm->state->Enter(data);
}
