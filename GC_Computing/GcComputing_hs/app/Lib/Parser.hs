{-# LANGUAGE OverloadedStrings #-}

module Lib.Parser where

import Data.Attoparsec.ByteString.Char8
import Data.ByteString.Char8 (ByteString)
import qualified Data.ByteString.Char8 as BS

-- skipWhile :: (Char -> Bool) -> Parser ()

data FASTA = FASTA{
      label :: ByteString
    , content :: ByteString
} deriving (Show)

-- instance Show FASTA where
--     show (FASTA l c) = BS.append c l


singleFASTA :: Parser FASTA
singleFASTA = do
    char '>'
    label <- takeTill ((==) '\n')
    endOfLine
    content <- takeTill ((==) '>')
    -- endOfLine
    return (FASTA label content)

-- Noticed that the result contains "\n". Remeber to ignore them later.
parseFASTA :: Parser [FASTA]
parseFASTA = do
    manyTill singleFASTA endOfInput


-- This will give an either result. Need some extra work to deal with it.
parseExec = parseOnly parseFASTA
