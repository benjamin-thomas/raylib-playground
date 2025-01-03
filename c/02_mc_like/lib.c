#include <math.h>
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

#define BLOCKS_SIZE 6
texture_coord blocks[BLOCKS_SIZE] = {
    {
        .name = "air",
        .sides = {.y = 0, .x = 0},
        .top = {.y = 0, .x = 0},
        .bottom = {.y = 0, .x = 0},
    },
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

Vector3 calculate_preview_position(Camera3D camera, float distance) {
  // Calculate the direction vector from camera position to target
  Vector3 dir = {
      camera.target.x - camera.position.x,
      camera.target.y - camera.position.y,
      camera.target.z - camera.position.z,
  };

  // Normalize the direction vector
  float length = sqrtf(dir.x * dir.x + dir.y * dir.y + dir.z * dir.z);
  dir.x /= length;
  dir.y /= length;
  dir.z /= length;

  // Calculate the position at the given distance
  Vector3 position = {
      camera.position.x + dir.x * distance,
      camera.position.y + dir.y * distance,
      camera.position.z + dir.z * distance,
  };

  // Round to nearest whole number to snap to grid
  position.x = roundf(position.x);
  position.y = roundf(position.y);
  position.z = roundf(position.z);

  return position;
}

// BLOCK HANDLING START
// Check if a position is within our world bounds
bool is_position_valid(Vector3 pos) {
  return pos.x >= 0 && pos.x < WORLD_SIZE_X && pos.y >= 0 &&
         pos.y < WORLD_SIZE_Y && pos.z >= 0 && pos.z < WORLD_SIZE_Z;
}

// Set a block in the world if the position is valid
void set_block(State* state, Vector3 pos, int block_type) {
  // Convert floating point coordinates to integers
  int x = (int)roundf(pos.x);
  int y = (int)roundf(pos.y);
  int z = (int)roundf(pos.z);

  Vector3 int_pos = {x, y, z};
  if (is_position_valid(int_pos)) {
    state->world[x][y][z] = block_type;
  }
}

// Get the block type at a position (returns 0 for invalid positions)
int get_block(State* state, Vector3 pos) {
  int x = (int)roundf(pos.x);
  int y = (int)roundf(pos.y);
  int z = (int)roundf(pos.z);

  Vector3 int_pos = {x, y, z};
  if (is_position_valid(int_pos)) {
    return state->world[x][y][z];
  }
  return 0;  // Return air for invalid positions
}
// BLOCK HANDLING END

void draw_3d_world(State* state) {
  BeginMode3D(state->camera);

  float cellWidth = state->atlas.width / 16.0f;
  float cellHeight = state->atlas.height / 16.0f;

  // Draw all placed blocks
  for (int x = 0; x < WORLD_SIZE_X; x++) {
    for (int y = 0; y < WORLD_SIZE_Y; y++) {
      for (int z = 0; z < WORLD_SIZE_Z; z++) {
        int block_type = state->world[x][y][z];
        if (block_type != 0) {  // Don't draw air blocks
          texture_coord block_tex = blocks[block_type];
          texture_rect t_rect = {
              .width = cellWidth,
              .height = cellHeight,
              .sides =
                  {
                      .x = cellWidth * block_tex.sides.x,
                      .y = cellHeight * block_tex.sides.y,
                  },
              .top =
                  {
                      .x = cellWidth * block_tex.top.x,
                      .y = cellHeight * block_tex.top.y,
                  },
              .bottom =
                  {
                      .x = cellWidth * block_tex.bottom.x,
                      .y = cellHeight * block_tex.bottom.y,
                  },
          };

          Vector3 pos = {(float)x, (float)y, (float)z};
          DrawCubeTextureRec(state->atlas, t_rect, pos, 1.0f, 1.0f, 1.0f,
                             WHITE);
        }
      }
    }
  }

  // Draw the preview block
  if (is_position_valid(state->preview_block_pos)) {
    texture_coord preview_tex = blocks[state->atlas_idx];
    texture_rect t_rect = {
        .width = cellWidth,
        .height = cellHeight,
        .sides =
            {
                .x = cellWidth * preview_tex.sides.x,
                .y = cellHeight * preview_tex.sides.y,
            },
        .top =
            {
                .x = cellWidth * preview_tex.top.x,
                .y = cellHeight * preview_tex.top.y,
            },
        .bottom =
            {
                .x = cellWidth * preview_tex.bottom.x,
                .y = cellHeight * preview_tex.bottom.y,
            },
    };

    DrawCubeTextureRec(state->atlas, t_rect, state->preview_block_pos, 1.0f,
                       1.0f, 1.0f,
                       Fade(WHITE, 0.7f));  // Semi-transparent preview
  } else {
    DrawCubeWires(state->preview_block_pos, 1.0f, 1.0f, 1.0f, DARKBROWN);
    DrawCube(state->preview_block_pos, 1.0f, 1.0f, 1.0f, RED);
  }

  DrawGrid(WORLD_SIZE_X, 1.0f);

  EndMode3D();
}

void draw_2d_overlay(State* state) {
  DrawRectangle(10, 10, 500, 140, Fade(SKYBLUE, 0.5f));
  DrawRectangleLines(10, 10, 500, 140, BLUE);

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

  const char* preview_pos_txt = TextFormat(
      "Preview Position: (%.02f,%.02f, %.02f)", state->preview_block_pos.x,
      state->preview_block_pos.y, state->preview_block_pos.z);

  DrawText(preview_pos_txt, 20, 115, 20, BLACK);
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

  if (state->is_window_focused) {
    UpdateCamera(&state->camera, CAMERA_FREE);

    state->preview_block_pos = calculate_preview_position(state->camera, 8.0f);
  }

  if (IsKeyPressed('Z')) {
    state->camera.target = (Vector3){0.0f, 0.0f, 0.0f};
  }

  // Place or remove blocks with mouse buttons
  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    set_block(state, state->preview_block_pos, state->atlas_idx);
  } else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
    set_block(state, state->preview_block_pos, 0);  // Remove block (set to air)
  }
}

void update_and_draw(State* state) {
  update(state);
  draw(state);
}