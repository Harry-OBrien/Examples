-- Defines a shortcut
-- Can be used interchangeably with original type
type Position = (integer, Integer)

-- Type parameters
type AssocList k v = [(k, v)]

-- Data declarations (Simple)
-- Defines type with 4 elements (constructors)
-- all constructors must start with upper case
    -- As opposed to function names or variables
data Direction = L | R | U | D

-- Data types can be pattern matched
move :: Direction -> Position -> Position
move L (x,y) = (x-1, y)
move R (x,y) = (x+1, y)
-- etc...

-- They can also have params
-- These happen to be standard
data Maybe a = Nothing | Just a
data Either a b = Left a  | Right b


-- Recursive declarations
-- The empty list is a list
-- If xs is a list, then Cons x xs is a list

data MyList a = Empty | Cons a (MyList a)

-- Pattern matching and recursion
append :: MyList a -> MyList a -> MyList a
append Empty ys = ys
append (Const x xs) ys = Cons x (append xs ys)

-- By default, a new data type will not provide and functionaly, eg. no equality or printing
-- However, there are obvious default definitions fro these functions
-- Deriving defines tehm for you
data MyList a = Empty | Cons a (MyList a)
    deriving (Ord, Eq, Show, Read)