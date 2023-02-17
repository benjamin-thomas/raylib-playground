#lang racket/base

; Run with:
;   racket main.rkt

(module+ main
  (require raylib/2d/unsafe)

  (InitWindow 800 450 "Hello Raylib")
  (SetTargetFPS 30)

  (let loop ([x 0])
    (when (not (WindowShouldClose))
      (BeginDrawing)
      (ClearBackground RAYWHITE)
      (DrawText "Hello Raylib (from Racket)" x 200 20 LIGHTGRAY)
      (EndDrawing)
      (loop (+ 1 x))))

  (CloseWindow))
