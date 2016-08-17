module Main where

import Src.IntSequence

main :: IO ()
main = do
    print $ "Months:"
    n <- getLine
    months <- readIO n :: IO Int
    print $ "How many rabbits each pair can produce:"
    k <- getLine
    produced <- readIO k :: IO Int
    print $ rabbitGo initialRabbits months produced
