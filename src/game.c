#include <stdio.h>
#include <SDL2/SDL.h>
#include "./constants.h"
#include "./function_prototypes.h"

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
int game_is_running = FALSE;
int last_frame_time = 0;
int direction = 1;

struct square{
	float x;
	float y;
	float width;
	float height;
} square;

int main(){
  game_is_running = initialize_window();
  setup();
  
  while(game_is_running){
	  process_input();  
	  update();
	  render();
  }
  destroy_window();
  //printf("game is running...\n");
  return 0;
}

int initialize_window(void){
  if(SDL_Init(SDL_INIT_EVERYTHING) != 0){ 
	  fprintf(stderr, "Error Initializing SDL.\n");
	  return FALSE;
  }
  
  window = SDL_CreateWindow(NULL,
							SDL_WINDOWPOS_CENTERED,
							SDL_WINDOWPOS_CENTERED,
							WINDOW_WIDTH,
							WINDOW_HEIGHT,
							SDL_WINDOW_BORDERLESS /*PHYSICAL WINDOWS PROPERTIES */
  );/*if you want window name just pass it inside this method*/
  if(!window){
	  fprintf(stderr, "Error creating SDL Window.\n");
	  return FALSE;
  }
  renderer = SDL_CreateRenderer(window, -1, 0);
  if(!renderer){
	  fprintf(stderr, "Error creating SDL Renderer.\n");
	  return FALSE;
  } 

  return TRUE;
}

void setup(void){
 // square.x = 40;   
	square.x = WINDOW_WIDTH/2 ;
  square.y = 40; 
  square.width = 40; 
  square.height = 40; 
}

void process_input(void){
  SDL_Event event;
  SDL_PollEvent(&event);

  switch(event.type){
	case SDL_QUIT:
		game_is_running = FALSE;
		break;
	case SDL_KEYDOWN:
		if(event.key.keysym.sym == SDLK_ESCAPE)
			game_is_running = FALSE;
		break;
  }
}

void update(void){
  /*while(!SDL_TICKS_PASSED(SDL_GetTicks(), last_frame_time + FRAME_TARGET_TIME) ){
	//WASTE TIME!!!	
  }*/
  /*time to wait until the target frame time in mls */
  int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - last_frame_time);
  /*only delay if we are out of the mark of time*/
  if(time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME){
	  SDL_Delay(time_to_wait);	
  }





  //delta time in seconds
  float delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0f;

  last_frame_time = SDL_GetTicks();
  //direction = direction * -1;
  int vy = 70 * delta_time;
  if(square.y > WINDOW_HEIGHT-40 || square.y < 0){ 
    vy *=  -1;

  }
  square.y += vy;
  //if (WINDOW_HEIGHT < square.y) {
  //  //square.x += 70 * delta_time;	
  //  //square.y -= 70 * delta_time;
  //  square.y = 0;
  //}else if (WINDOW_HEIGHT > square.y){
  //  square.y += 70 * delta_time;
  //}
  // printf("%f, %f",square.x,square.y);
  //square.x += 1;
}

void render(void){
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);/*R, G, B, ALPHA */
  SDL_RenderClear(renderer);
  //render square
  SDL_SetRenderDrawColor(renderer, 200, 0, 0, 255);/*R, G, B, ALPHA */
  SDL_Rect	square_rect = {square.x, square.y, square.width, square.height};
  SDL_RenderFillRect(renderer, &square_rect);
  SDL_RenderPresent(renderer);
  
}

void destroy_window(void){
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
