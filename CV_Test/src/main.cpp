// CS 課題
#include "lib/framework.hpp"

void DrawTexture(Vec2f player_pos,Vec2f player_size,
	Vec2f cut_start,Vec2f cut_wh,Texture texture)
{
	drawTextureBox(player_pos.x(), player_pos.y(), player_size.x(), player_size.y(),
		cut_start.x(), cut_start.y(), cut_wh.x(), cut_wh.y(), texture);
}

enum Direction
{
	LEFT_, RIGHT_, UP_, DOWN_
};

int main() {
  AppEnv env(1000,1000,false,true);

  Texture player("res/player.png");

  Vec2f player_pos = Vec2f(0, 0);
  Vec2f player_size = Vec2f(128, 256);
  Vec2f cut_start = Vec2f(0, 0);
  Vec2f cut_wh = Vec2f(128, 256);
  int direction;

  Vec2f b_pos[3];
  Vec2f b_wh = Vec2f(5, 5);
  Color b_color = Color::white;

  bool showBullet[3] = { false, false, false };

  while (env.isOpen()) {
	  env.begin();

	  if (env.isPushKey(GLFW_KEY_ENTER))
	  {
		  break;
	  }

	  if (env.isPressKey(GLFW_KEY_LEFT))
	  {
		  player_pos.x() -= 5;
		  direction = LEFT_;
		  cut_wh.x() = -128;
	  }

	  if (env.isPressKey(GLFW_KEY_RIGHT))
	  {
		  player_pos.x() += 5;
		  direction = RIGHT_;
		  cut_wh.x() = 128;
	  }

	  if (env.isPressKey(GLFW_KEY_UP))
	  {
		  player_pos.y() += 5;
		  direction = UP_;
	  }

	  if (env.isPressKey(GLFW_KEY_DOWN))
	  {
		  player_pos.y() -= 5;
		  direction = DOWN_;
	  }

	  if (env.isPushKey(GLFW_KEY_SPACE))
	  {
		  for (int i = 0; i < 3; ++i)
		  {
			  if (showBullet[3])
		  }
		  drawFillBox(player_pos.x() + 64, player_pos.y() + 128, 5, 5, Color::white);
	  }

	  DrawTexture(player_pos, player_size, cut_start, cut_wh, player);
	  
	  env.end();
  }
}
