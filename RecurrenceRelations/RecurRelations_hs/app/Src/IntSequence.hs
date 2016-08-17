module Src.IntSequence (
    rabbitGo,
    initialRabbits
) where


type FiboSeed = (Int, Int)

simpleFibo :: FiboSeed -> Int -> [Int]
simpleFibo (s1, s2) 0 = s1 : s2 : []
simpleFibo (s1, s2) n = s1 : (simpleFibo (s2, s1 + s2) (n - 1))

---------

type Size = Int

class IntSequence a where
    intSeq :: a -> Size -> [Int]

---------
--- Fibonacci Sequence ------

data Fibonacci = Fibo {
    sequence :: [Int] ,
    fiboSeeds :: (Int, Int)
}

instance IntSequence Fibonacci where
    intSeq (Fibo fs (s1, s2)) 0 = fs
    intSeq (Fibo fs (s1, s2)) n = intSeq (Fibo (fs ++ s3:[]) (s2, s3)) (n - 1)
                                        where s3 = s1 + s2

initFibo :: (Int, Int) -> Fibonacci
initFibo (s1, s2) = Fibo (s1:s2:[]) (s1, s2)

----- ROSALIND Problem ----
-- In the first place, there are a pair of Rabbit.
-- Rabbits reach reproductive age after one month.
-- In any given month, every rabbit of reproductive age mates with another rabbit of reproductive age.
-- one month after two rabbits mate, they produce several pairs of rabbits.

-- Given: n k.
    -- n months. Each pair will produce k pairs.
-- Return: How many pairs there are after n months.
-- ex: 5 3
-- 1 b' g'
-- 2 b  g
-- 3 b  g  3b' 3g'      = 4
-- 4 4b  4g 3b' 3g'     = 7
-- 5 7b  7g 12b' 12g'   = 19

rabbitGo :: Fibonacci -> Int -> Int -> Int
rabbitGo (Fibo fs (s1, s2)) n k
                | n <= 0 = error("months should be integer > 0")
                | n <= 2 = s2
                | otherwise = rabbitGo (Fibo (fs ++ s3:[]) (s2, s3)) (n - 1) k
                                    where s3 = s1 * k + s2

initialRabbits = initFibo (1, 1)




