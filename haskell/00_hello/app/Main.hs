{-# OPTIONS -Wall #-}

module Main where

import Control.Monad (unless)
import Raylib.Colors (rayWhite, red)
import Raylib.Core (beginDrawing, clearBackground, closeWindow, endDrawing, initWindow, setTargetFPS, windowShouldClose)
import Raylib.Shapes (drawRectangleRec)
import Raylib.Types (Rectangle (Rectangle))

-- cabal run

setup :: IO ()
setup = do
    initWindow 600 450 "Hello Raylib!"
    setTargetFPS 60

rect :: Rectangle
rect = Rectangle 50 50 50 50

draw :: IO ()
draw = do
    clearBackground rayWhite
    drawRectangleRec rect red

gameLoop :: IO ()
gameLoop = do
    beginDrawing
    draw
    endDrawing

    shouldClose <- windowShouldClose
    unless shouldClose gameLoop

main :: IO ()
main = do
    setup
    gameLoop
    closeWindow
