module Lib.CountNs where

import Lib.Parser (FASTA(..))
import Lib.Counting (countCharsRatio)

import Data.ByteString.Char8 (ByteString)
import qualified Data.ByteString.Char8 as BS


data FASTAratio = FR {
    labelR :: ByteString,
    ratio :: Double
}

instance Show FASTAratio where
    show (FR l r) = (BS.unpack l) ++ "\n" ++ (show r) ++ "\n"


countFASTA :: [Char] -> FASTA -> FASTAratio
countFASTA cs fas = FR (label fas) (countCharsRatio cs (content fas))

countFASTAs :: [Char] -> [FASTA] -> [FASTAratio]
countFASTAs cs fass = map (countFASTA cs) fass
