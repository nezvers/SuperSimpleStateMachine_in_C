#include <stdio.h>
#include "StateMachine.h"


// example data passed to state enter
typedef struct {
	int speed;
}SomeData;

// Example state functions
void st_idle_enter(void *data){
	printf("Idle entered \n");
}
void st_run_enter(void *data){
	int spd = ((SomeData*)data)->speed;
	printf("Run entered with speed data: %d \n", spd);
}
void st_exit(){
	printf("exited \n");
}
void st_update(float dt){
	printf("delta_time: %f \n", dt);
}

// State enum
enum {
	WALK,
	RUN
};

int main(){
	State idle = {st_idle_enter, st_exit, st_update, "idle"};
	State run = {st_run_enter, st_exit, st_update, "run"};
	State list[] = {idle, run};
	StateMachine sm = {&idle, list};
	
	sm.state->Update(0.666);
	change_state(&sm, WALK, NULL);
	
	SomeData data = {16};
	change_state(&sm, RUN, (void*)&data);
	
	return 0;
}
