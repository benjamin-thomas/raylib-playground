(* dune exec --display=quiet bin/main.exe *)

module R = Raylib

let setup () =
  R.init_window 800 450 "Hello Raylib"
  ; R.set_target_fps 60
;;

type model = { speed : int; x : int }

let update model =
  let approx_text_width = 400 in
  let max_right = R.get_screen_width () - approx_text_width in
  let speed =
    if model.x < 0 then
      abs model.speed
    else if model.x > max_right then
      abs model.speed * -1
    else
      model.speed
  in
  { x = model.x + model.speed; speed }
;;

let do_draw model =
  R.clear_background R.Color.darkgray
  ; R.draw_text "Hello Raylib (from OCaml)!" model.x 200 30 R.Color.red
  ; R.draw_text
      (Printf.sprintf "Speed=%d, X=%03d " model.speed model.x)
      20 20 30 R.Color.blue
;;

let draw model =
  R.begin_drawing ()
  ; do_draw model
  ; R.end_drawing ()
;;

let rec loop model =
  match R.window_should_close () with
  | false ->
      let model = update model in
      draw model
      ; loop model
  | true -> R.close_window ()
;;

let () =
  setup ()
  ; loop { speed = 5; x = 20 }
;;
