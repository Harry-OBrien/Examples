-- Computations with side-effect on some state

{-
M a state -> (a, state)

return x = \s -> (x,s)  -- Leave state unchanged
m >>= f = \s -> let
        (x,s') = m s    -- Run m on s, get result and nes state s'
    in f x s'           -- Run f with result and new state
-}
{-
-- MODELLING THE OUTSIDE WORLD
-- This is a state mode
-- Effects are amy interactions on the outside world
-- Returns a new, changed world
IO a = World -> (a, World)
-}

{-
-- Console (in Prelude)
getChar :: IO Char
putChar :: Char -> IO()

-- Files (System.IO)
type FilePath = String
data IOMode = 
    ReadMode | WriteMode | AppendMode | ReadWriteMode

openFile :: FilePath -> IOMode -> IO Handle
hClose :: Handle -> IO ()

hGetChar :: Handle -> IO Char
hPutChar :: Handle -> Char -> IO () -- Returns void, but changes state or the world (IO)

print :: Show a =? a -> IO ()
getLine :: IO String

-- Read string, and write a string back to the terminal
interact :: (String -> String) -> IO()

-- Like Python's Open as('r')
withFile :: FilePath -> IOMode -> (Handle -> IO r) -> IO r

---------------------------------------------------------------

import System.IO
h <- openFile "exampleText.txt" ReadMode
firstLine = hGetLine h

-}

import System.IO
import Data.Char

-- Read from file until EOF
-- this is the same as 'getContents :: IO String'
myReadAll :: IO String
myReadAll = do
    eof <- isEOF
    if eof then
        return ""
    else do
        c <- getChar
        s <- myReadAll
        return (c:s)


-- Print strinf
-- This is the same as putStr :: String -> IO ()
myPrintString :: String -> IO ()
myPrintString [] = return ()
myPrintString (c:s) = do
    putChar c
    myPrintString s

main = do
    -- this is a good use for the interact function
    -- main = do interact (filter isAscii); return 0
    -- echo "That's £37" | ./Inputs_and_Outputs -> |That's 37
    s  <- myReadAll
    let s' = filter isAscii s
    myPrintString s'
    return 0
