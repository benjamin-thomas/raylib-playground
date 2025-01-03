#include <raylib.h>
#include <stdio.h>

#include "rlgl.h"  // Required to define vertex data (immediate-mode style)
#include "state.h"

typedef struct {
  char* name;
  Vector2 sides;
  Vector2 top;
  Vector2 bottom;
} texture_coord;

#define BLOCKS_SIZE 5
texture_coord blocks[BLOCKS_SIZE] = {
    {
        .name = "grass",
        .sides = {.y = 14, .x = 0},
        .top = {.y = 13, .x = 0},
        .bottom = {.y = 15, .x = 0},
    },
    {
        .name = "dirt",
        .sides = {.y = 15, .x = 0},
        .top = {.y = 15, .x = 0},
        .bottom = {.y = 15, .x = 0},
    },
    {
        .name = "wood",
        .sides = {.y = 14, .x = 4},
        .top = {.y = 15, .x = 4},
        .bottom = {.y = 15, .x = 4},
    },
    {
        .name = "snow",
        .sides = {.y = 14, .x = 8},
        .top = {.y = 13, .x = 8},
        .bottom = {.y = 15, .x = 0},
    },
    {
        .name = "multipletextureblock",
        .sides = {.y = 15, .x = 3},
        .top = {.y = 15, .x = 11},
        .bottom = {.y = 15, .x = 11},
    },
};

typedef struct {
  float width;
  float height;
  Vector2 sides;
  Vector2 top;
  Vector2 bottom;
} texture_rect;

void DrawCubeTextureRec(Texture2D texture, texture_rect t_rect,
                        Vector3 position, float width, float height,
                        float length, Color color) {
  float x = position.x;
  float y = position.y;
  float z = position.z;
  float texWidth = (float)texture.width;
  float texHeight = (float)texture.height;

  // Set desired texture to be enabled while drawing following vertex data
  rlSetTexture(texture.id);

  // We calculate the normalized texture coordinates for the desired texture-source-rectangle
  // It means converting from (tex.width, tex.height) coordinates to [0.0f, 1.0f] equivalent
  rlBegin(RL_QUADS);
  rlColor4ub(color.r, color.g, color.b, color.a);

  Vector2 sides = t_rect.sides;

  // Front face
  rlNormal3f(0.0f, 0.0f, 1.0f);
  rlTexCoord2f(sides.x / texWidth, (sides.y + t_rect.height) / texHeight);
  rlVertex3f(x - width / 2, y - height / 2, z + length / 2);
  rlTexCoord2f((sides.x + t_rect.width) / texWidth,
               (sides.y + t_rect.height) / texHeight);
  rlVertex3f(x + width / 2, y - height / 2, z + length / 2);
  rlTexCoord2f((sides.x + t_rect.width) / texWidth, sides.y / texHeight);
  rlVertex3f(x + width / 2, y + height / 2, z + length / 2);
  rlTexCoord2f(sides.x / texWidth, sides.y / texHeight);
  rlVertex3f(x - width / 2, y + height / 2, z + length / 2);

  // Back face
  rlNormal3f(0.0f, 0.0f, -1.0f);
  rlTexCoord2f((sides.x + t_rect.width) / texWidth,
               (sides.y + t_rect.height) / texHeight);
  rlVertex3f(x - width / 2, y - height / 2, z - length / 2);
  rlTexCoord2f((sides.x + t_rect.width) / texWidth, sides.y / texHeight);
  rlVertex3f(x - width / 2, y + height / 2, z - length / 2);
  rlTexCoord2f(sides.x / texWidth, sides.y / texHeight);
  rlVertex3f(x + width / 2, y + height / 2, z - length / 2);
  rlTexCoord2f(sides.x / texWidth, (sides.y + t_rect.height) / texHeight);
  rlVertex3f(x + width / 2, y - height / 2, z - length / 2);

  Vector2 top = t_rect.top;
  // Top face
  rlNormal3f(0.0f, 1.0f, 0.0f);
  rlTexCoord2f(top.x / texWidth, top.y / texHeight);
  rlVertex3f(x - width / 2, y + height / 2, z - length / 2);
  rlTexCoord2f(top.x / texWidth, (top.y + t_rect.height) / texHeight);
  rlVertex3f(x - width / 2, y + height / 2, z + length / 2);
  rlTexCoord2f((top.x + t_rect.width) / texWidth,
               (top.y + t_rect.height) / texHeight);
  rlVertex3f(x + width / 2, y + height / 2, z + length / 2);
  rlTexCoord2f((top.x + t_rect.width) / texWidth, top.y / texHeight);
  rlVertex3f(x + width / 2, y + height / 2, z - length / 2);

  Vector2 bottom = t_rect.bottom;
  // Bottom face
  rlNormal3f(0.0f, -1.0f, 0.0f);
  rlTexCoord2f((bottom.x + t_rect.width) / texWidth, bottom.y / texHeight);
  rlVertex3f(x - width / 2, y - height / 2, z - length / 2);
  rlTexCoord2f(bottom.x / texWidth, bottom.y / texHeight);
  rlVertex3f(x + width / 2, y - height / 2, z - length / 2);
  rlTexCoord2f(bottom.x / texWidth, (bottom.y + t_rect.height) / texHeight);
  rlVertex3f(x + width / 2, y - height / 2, z + length / 2);
  rlTexCoord2f((bottom.x + t_rect.width) / texWidth,
               (bottom.y + t_rect.height) / texHeight);
  rlVertex3f(x - width / 2, y - height / 2, z + length / 2);

  // Right face
  rlNormal3f(1.0f, 0.0f, 0.0f);
  rlTexCoord2f((sides.x + t_rect.width) / texWidth,
               (sides.y + t_rect.height) / texHeight);
  rlVertex3f(x + width / 2, y - height / 2, z - length / 2);
  rlTexCoord2f((sides.x + t_rect.width) / texWidth, sides.y / texHeight);
  rlVertex3f(x + width / 2, y + height / 2, z - length / 2);
  rlTexCoord2f(sides.x / texWidth, sides.y / texHeight);
  rlVertex3f(x + width / 2, y + height / 2, z + length / 2);
  rlTexCoord2f(sides.x / texWidth, (sides.y + t_rect.height) / texHeight);
  rlVertex3f(x + width / 2, y - height / 2, z + length / 2);

  // Left face
  rlNormal3f(-1.0f, 0.0f, 0.0f);
  rlTexCoord2f(sides.x / texWidth, (sides.y + t_rect.height) / texHeight);
  rlVertex3f(x - width / 2, y - height / 2, z - length / 2);
  rlTexCoord2f((sides.x + t_rect.width) / texWidth,
               (sides.y + t_rect.height) / texHeight);
  rlVertex3f(x - width / 2, y - height / 2, z + length / 2);
  rlTexCoord2f((sides.x + t_rect.width) / texWidth, sides.y / texHeight);
  rlVertex3f(x - width / 2, y + height / 2, z + length / 2);
  rlTexCoord2f(sides.x / texWidth, sides.y / texHeight);
  rlVertex3f(x - width / 2, y + height / 2, z - length / 2);

  rlEnd();

  rlSetTexture(0);
}

void draw_3d_world(State* state) {
  BeginMode3D(state->camera);

  DrawCube((Vector3){2.0f, 1.0f, 0.0f}, 2.0f, 2.0f, 2.0f, GREEN);
  DrawCubeWires((Vector3){2.0f, 1.0f, 0.0f}, 2.0f, 2.0f, 2.0f, LIME);

  float cellWidth = state->atlas.width / 16.0f;
  float cellHeight = state->atlas.height / 16.0f;

  texture_coord grass = blocks[state->atlas_idx];

  texture_rect t_rect = {
      .width = cellWidth,
      .height = cellHeight,

      .sides =
          {
              .x = cellWidth * grass.sides.x,
              .y = cellHeight * grass.sides.y,
          },
      .top =
          {
              .x = cellWidth * grass.top.x,
              .y = cellHeight * grass.top.y,
          },
      .bottom =
          {
              .x = cellWidth * grass.bottom.x,
              .y = cellHeight * grass.bottom.y,
          },
  };

  Vector3 pos = {0.0f, 1.0f, 0.0f};
  DrawCubeTextureRec(state->atlas, t_rect, pos, 2.0f, 2.0f, 2.0f, WHITE);

  DrawGrid(8, 1.0f);

  EndMode3D();
}

void draw_2d_overlay(State* state) {
  DrawRectangle(10, 10, 500, 110, Fade(SKYBLUE, 0.5f));
  DrawRectangleLines(10, 10, 500, 110, BLUE);

  const char* cam_pos_txt =
      TextFormat("Camera Position: (%02f,%02f, %02f)", state->camera.position.x,
                 state->camera.position.y, state->camera.position.z);

  DrawText(cam_pos_txt, 20, 25, 20, BLACK);

  const char* cam_target_txt =
      TextFormat("Camera Target: (%02f,%02f, %02f)", state->camera.target.x,
                 state->camera.target.y, state->camera.target.z);

  DrawText(cam_target_txt, 20, 55, 20, BLACK);

  const char* atlas_coord_txt = TextFormat(
      "Block name: %s(%d)", blocks[state->atlas_idx].name, state->atlas_idx);

  DrawText(atlas_coord_txt, 20, 85, 20, BLACK);
}

void draw(State* state) {
  BeginDrawing();

  ClearBackground(RAYWHITE);

  draw_3d_world(state);
  draw_2d_overlay(state);

  EndDrawing();
}

bool is_shift() {
  return (IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT));
}

void update(State* state) {
  if (IsKeyPressed(KEY_F1)) {
    printf("Resetting state!\n");
    state_init(state, true);
  }

  if (is_shift() && IsKeyPressed(KEY_F2)) {
    state->atlas_idx = (state->atlas_idx + BLOCKS_SIZE - 1) % BLOCKS_SIZE;
  } else if (IsKeyPressed(KEY_F2)) {
    state->atlas_idx = (state->atlas_idx + 1) % BLOCKS_SIZE;
  }

  if (IsKeyPressed('X')) {
    state->is_window_focused = !state->is_window_focused;
    if (state->is_window_focused) {
      DisableCursor();
    } else {
      EnableCursor();
    }
  }

  if (state->is_window_focused) UpdateCamera(&state->camera, CAMERA_FREE);

  if (IsKeyPressed('Z')) {
    state->camera.target = (Vector3){0.0f, 0.0f, 0.0f};
  }
}

void update_and_draw(State* state) {
  update(state);
  draw(state);
}