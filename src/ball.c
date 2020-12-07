#include "ball.h"

static struct Ball construct (int x, int y, int vx, int vy) {
    return (struct Ball){.x = x, .y = y, .vx = vx, .vy =vy};
}
const struct BallClass Ball = {.construct = &construct};

static void update_position(struct Ball * self) {
    self->x += self->vx;
    self->y += self->vy;

}