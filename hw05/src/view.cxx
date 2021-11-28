// YOU DEFINITELY NEED TO MODIFY THIS FILE.

#include "view.hxx"
#include "model.hxx"

///
/// VIEW CONSTANTS
///

// Colors are red-green-blue(-alpha), each component
// from 0 to 255.
static ge211::Color const ball_color {255, 127, 127};
static ge211::Color const paddle_color {255, 255, 127};
static ge211::Color const brick_color {100, 100, 100};


///
/// VIEW CONSTRUCTOR
///

// Data members that are references cannot be initialized by assignment
// in the constructor body and must be initialized in a member
// initializer list.
View::View(Model const& m)
        : model(m),
          ball_sprite(m.config.ball_radius, ball_color),
          paddle_sprite(m.config.paddle_dims, paddle_color),
          brick_sprite(m.config.brick_dims(), brick_color)
{ }


///
/// VIEW FUNCTIONS
///

// Use `Sprite_set::add_sprite(Sprite&, Position)` to add each sprite
// to `sprites`.
void
View::draw(ge211::Sprite_set & sprites) {
    sprites.add_sprite(ball_sprite, {
            (int) model.ball.center.x - model.ball.radius,
            (int) model.ball.center.y - model.ball.radius
    });
    sprites.add_sprite(paddle_sprite, {
            (int) model.paddle.x,
            (int) model.paddle.y
    });

    for (size_t i = 0; i < model.bricks.size(); i++) {
        sprites.add_sprite(brick_sprite, {
                model.bricks[i].x,
                model.bricks[i].y
        });
    }
}

ge211::Dims<int>
View::initial_window_dimensions() const
{
    return model.config.scene_dims;
}

