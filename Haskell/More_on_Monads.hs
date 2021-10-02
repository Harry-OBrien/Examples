-- Maybe monda (effect: abort)
M a = Maybe a

return x = Just x
Nothing >>= f = Nothing
Just x >>= f = fx

-- Either Monad (effect: abort with error message)
-- Either [if correct, return right (if right, right)]
M a = Either String a

return x = Right x
Left msg >>= f = Left msg
Right x >>= f = f x

-- State Monad
-- We have some state, and the computation has some side effect on the state
M a = state -> (a, state)
return x = \s -> (x,s)      -- Leave state unchanged
m >>= f = \s -> let
        (x,s') = m s        -- Run m on s, get result and new state s'
    in f x s'               -- Run f with result and new state

-- More functions on state monad
get = 's -> (s, s)      -- Return state as result, do not change state
put s = \_ -> ((), s)   -- Change to new state, return unit() (similar to void func())

-- List Monad (nodeterminism)
-- Model Computation with several alternatives
M a = [a]
return x = [x] -- Only one alternative

bind m f = concat (map f m) -- Apply f to each alternative in m, concat results

-- Same as
bind m f = [r | x <- m, r <- f x]

-- An empty list means 'no result'. Propogates like an error!