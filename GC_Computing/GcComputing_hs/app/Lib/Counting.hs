module Lib.Counting where

import Data.ByteString.Char8 (ByteString)
import qualified Data.ByteString.Char8 as BS

type Counter = (Int, Int)

initailCounter :: Counter
initailCounter = (0, 0)

posC :: Counter -> Int
posC (a, b) = a

negC :: Counter -> Int
negC (a, b) = b

add1pos :: Counter -> Counter
add1pos (a, b) = (a + 1, b)

add1neg :: Counter -> Counter
add1neg (a, b) = (a, b + 1)


ratio :: Counter -> Double
ratio ct
    | ct == initailCounter = 0
    | otherwise = 100 * ((fromIntegral.posC) ct) / (fromIntegral ((posC ct) + (negC ct)))

countCharsRatio' :: Counter -> [Char] -> ByteString -> Double
countCharsRatio' ct cs bs
    | bs == BS.empty = ratio ct
    | otherwise = if (BS.head bs) == '\n'
                        then countCharsRatio' ct cs (BS.tail bs)
                    else if elem (BS.head bs) cs
                        then countCharsRatio' (add1pos ct) cs (BS.tail bs)
                    else countCharsRatio' (add1neg ct) cs (BS.tail bs)

countCharsRatio = countCharsRatio' initailCounter




testByteString = BS.pack "akskd"


