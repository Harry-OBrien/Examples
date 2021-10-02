import Constrol.Monad

type Val = Integer
data Expr = Const Val
    | Plus Expr Expr
    | Times Expr Expr
    | Div Expr Expr

{-
If we run
eval (Div (Const 1) (Const 0)), we would get an Exception (divide by 0)

To solve this, we use 'maybe'
-}
-- eval :: Expr -> Maybe Val
-- eval (Const x) = just x
-- eval (Plus a b) =
--     -- Check 'a' can be evaluated
--     case eval a of
--         Nothing -> Nothing
--         Just va ->
--             -- Check 'b' can be evaluated
--             case eval b of
--                 Nothing -> Nothing
--                 just vb -> Just(va + vb)
-- eval (Times a b) =
--     -- Check 'a' can be evaluated
--     case eval a of
--         Nothing -> Nothing
--         Just va ->
--             -- Check 'b' can be evaluated
--             case eval b of
--                 Nothing -> Nothing
--                 just vb -> Just(va * vb)
-- eval (Divides a b) = 
--     case eval a of
--         Nothing -> Nothing
--         Just va ->
--             case eval b of
--                 Nothing -> Nothing
--                 Just vb ->
--                     if vb /= 0 then
--                         Just (va `div` vb)
--                     else Nothing

-- The above contains a load of boiler plate and is a mess.
-- We use the power of a functional programming language to abstract away pars of the function

-- Uses infix operator (>>==) (called 'bind')
-- Binds the result of first argument to second argument
-- Takes 'a', a function, and returns a maybe value (Nothing or 'b')
>>= :: Maybe a -> (a -> Maybe b) -> Maybe b
-- If nothing, the whole thing fails, else perform f(x)
Nothing >>= f = Nothing
Just x >>= f = f x

-- This means we can now just do:
-- eval (Times a b) =
--     eval a >>= \va ->
--     eval b>>= \vb ->
--     Just (va*vb)

-- Even simpler (syntactic shortcut):
eval (Times a b) = do
    va <- eval a
    vb <- eval b
    return (va*vb)

-- GUARDS
-- Checking division by zero
-- do
--     guard (vb /= 0)
--     return (va `div` vb)

eval (Divides a b) = do
    va <- eval a
    vb <- eval b
    guard (vb /= 0)
    return (va `div` vb)    -- Fail if not (vb /= 0)