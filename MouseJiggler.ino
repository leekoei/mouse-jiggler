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
 *              ____
 *             /    \__
 * |\         /    @   \
 * \ \_______|    \  .:|>
 *  \      ##|    | \__/
 *   |    ####\__/   \
 *   /  /  ##       \|
 *  /  /__________\  \
 *  L_JJ           \__JJ
 * 
 */
#include "Mouse.h"

/* Const definition */
const int move_rect = 0;
const int move_circle = 1;

const int circle_approx_n = 50;

/* Global variable definitions */
int rect_len      = 15;
int move_delay    = 5;
int move_pattern  = move_circle;


void setup() {
  /* Arduino takes control of the mouse */
  Mouse.begin();
}

void loop() {
  /* Rectangle movement */
  if (move_pattern == move_rect) {
    Mouse.move(0, rect_len, 0);
    delay(move_delay);
    Mouse.move(rect_len, 0, 0);
    delay(move_delay);
    Mouse.move(0, -rect_len, 0);
    delay(move_delay);
    Mouse.move(-rect_len, 0, 0);
    delay(move_delay);
  }
  if (move_pattern == move_circle) {
    for(int i = 0; i < circle_approx_n; i++) {
      float x = rect_len * cos(2*3.14*(i + 1)/circle_approx_n);
      float y = rect_len * sin(2*3.14*(i + 1)/circle_approx_n);
      Mouse.move(x, y, 0);
      delay(move_delay);
    }
  }
}
