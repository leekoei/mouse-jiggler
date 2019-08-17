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

/* Global variable definitions */
int rect_len      = 20;
int move_delay    = 50;
int move_pattern  = move_rect;


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
}
