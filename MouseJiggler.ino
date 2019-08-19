/**
 * Mouse Jiggler
 * 
 * This Arduino script turns USB-ready board into 'Mouse Jiggler'. 
 * It emulate a mouse and move the cursor in cerntain pattern. 
 * By keeping mouse moving, computer won't get into sleep mode or turn off.
 * 
 * All rights reserved.
 * 
 * Ron Li
 * 2019.08
 *                           ____
 *                          /    \__
 * |\                      /    @   \
 * \ \____________________|    \  .:|>
 *  \      ##             |    | \__/
 *   |    ####             \__/   \
 *   /  /  ##                    \|
 *  /  /_______________________\  \
 *  L_JJ                        \__JJ
 * 
 */
#include "Mouse.h"

/* Const definition */
enum move_pattern_t {
  move_pattern_rect,
  move_pattern_cirlce,
  move_pattern_three_points,
  NUM_OF_MOVE_PATTERN
};

/* Global variable definitions */
int move_step     = 30;
int move_delay    = 10;
int move_pattern  = move_pattern_cirlce;


void setup() {
  /* Arduino takes control of the mouse */
  Mouse.begin();
}

void loop() {
//  if(Mouse.isPressed()) {
//    move_pattern = (move_pattern + 1) % NUM_OF_MOVE_PATTERN; 
//  }
  /* Rectangle movement */
  if (move_pattern == move_pattern_rect) {
    Mouse.move(0, move_step, 0);
    delay(move_delay);
    Mouse.move(move_step, 0, 0);
    delay(move_delay);
    Mouse.move(0, -move_step, 0);
    delay(move_delay);
    Mouse.move(-move_step, 0, 0);
    delay(move_delay);
  }
  /* Circle movement */
  if (move_pattern == move_pattern_cirlce) {
    int circle_approx_n = 40;
    move_step = 10;
    move_delay = 15;
    
    for(int i = 0; i < circle_approx_n; i++) {
      float x = move_step * cos(2*3.14*(i + 1)/circle_approx_n);
      float y = move_step * sin(2*3.14*(i + 1)/circle_approx_n);
      Mouse.move(x, y, 0);
      delay(move_delay);
    }
  }
  /* Three point pattern */
  if(move_pattern == move_pattern_three_points) {
    move_step = -move_step;
    move_delay = 70;
    
    for(int i = 0; i < 3; i++) {
      Mouse.move(move_step, 0, 0);
      delay(move_delay);
    }
  }
}
