module Src.SuffixTree where

data SNode = ROOT {
    label :: [String],
    childrens :: [SNode]
} | NODE {
    label :: [String],
    edge :: Char,
    childrens :: [SNode]
} | KNOT {

}

test :: SNode
test = NODE "a" [LEAF, LEAF]

someFunc :: IO ()
someFunc = putStrLn "someFunc"
