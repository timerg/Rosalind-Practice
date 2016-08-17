{-# LANGUAGE OverloadedStrings #-}
module Main where

import Lib.Parser
import Lib.CountNs(countFASTAs)
import Data.List(intercalate)

import System.IO
import Data.ByteString.Char8 (ByteString)
import qualified Data.ByteString.Char8 as BS

main :: IO ()
main = do
    input <- BS.readFile "data"
    let parseResult = parseExec input
    case parseResult of
        Left a -> print "parse input error"
        Right a -> putStrLn(intercalate "\n" $ map show (countFASTAs "GC" a))



findlist :: Int -> [Int] -> Maybe Int
findlist x [] = Nothing
findlist x (s:xs) = if x == s then Just 1
    else
        case findlist x xs of
            Nothing -> Nothing
            Just a -> Just (1 + a)
-- findlist x (s:xs) = if x /= s then fmap (1+) (findlist x xs)
--                         else Just 1
