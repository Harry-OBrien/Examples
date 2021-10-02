-- import VeryBasicPComb
import Control.Monad(guard,liftM)
import Data.Char

{-

  PL & Paradigms

  Live lecture 5

-}




{-
  Building a parser
-}

{-
  The primitives are

  item :: Parser char
    parse a character

  return x :: a -> Parser a
    parse nothing, return x

  do r<-p1; p2
    parse with p1, then with p2

  empty :: Parser a
    fail to parse

  p1 <|> p2
    parse with p1. If this fails, try parsing with p2

  Running a parser:
    parse :: Parser a -> String -> Maybe (a,String)
      parse prefix of string. Return result and remaining string.

    parseAll :: Parser a -> String -> Maybe a
      parse whole string.

-}

{-
  Examples:
-}

{- Parse a single character. Show parse and parseAll -}

{- Parse two characters -}

{- Parse an H -}
pex3 = do c<-item; if c=='H' then return (); else empty
pex3' = do c<-item; guard (c=='H')

{- guard! -}

{- Parse character for which property holds -}
sat :: (Char -> Bool) -> Parser Char
sat p = do c<-item; guard (p c); return c

{- Parse a letter, digit, whitespace ... -}
letter = sat isLetter
digit = sat isDigit
space1 = sat isSpace


{- Parse exactly character c -}
char c = sat (==c)

{- Parse many spaces. Careful with indentation of <|>! -}
space = do space1; space; return ()
        <|> return ()

space' = many space1

{- Iterate a parser, return list of results -}
many p = do x<-p; xs<-many p; return (x:xs)
         <|> return []

{- Iterate at least once -}
some p = do x<-p; xs<-many p; return (x:xs)

{- Parse with p, but ignore any whitespace before and after -}
token p = do space; r<-p; space; return r

{- Parse a natural number -}
nat_number :: Parser Integer
nat_number = token (do s <- some digit; return (read s))

{- Parse an integer -}
number = nat_number
        <|> token (do char '-'; s <- some digit; return (-(read s)))


{- Parse a string, with escape. Show that choice order matters

  "Hello \"World\" "
-}

string = token ( do char '"'; s<-many ec; char '"'; return s)
  where
    ec = do char '\\'; item
      <|> sat (/='"')



{- Parse comma-separated list. At least one element.
  First with token (char ','), then intro ctrl for single character.
  then for string (mapM_)
-}

commas1 p = do x<-p; xs<-many (do ctrl ","; p); return (x:xs)

ctrl s = token (mapM_ char s)


{- Comma-separated, including empty list -}
commas p = commas1 p <|> return []

{- Parse with p, enclosed in start/end token -}

enclose s e p = do ctrl s; r<-p; ctrl e; return r


{- Simple JSON -}

data JValue =
    JNull
  | JBool Bool
  | JNumber Integer
  | JString String
  | JArray [JValue]
  | JObject [(String,JValue)]
  deriving Show

{- Parsers for each type! Use liftM! Spare Null and Bool for first! -}
jnumber = do r<-number; return (JNumber r)
jnumber' = liftM JNumber number

jstring = liftM JString string
jarray = liftM JArray (enclose "[" "]" (commas jvalue))

jobject = liftM JObject (enclose "{" "}" (commas field))
  where field = do n<-string; ctrl ":"; v<-jvalue; return (n,v)

jvalue = jnumber <|> jstring <|> jarray <|> jobject


parseFile p f = liftM (parseAll p) (readFile f)

{- Identifiers and keywords. Parse as many letters as possible. -}

{- Now we can true, false, null -}







