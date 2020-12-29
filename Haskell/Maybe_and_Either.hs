-- data Maybe a = Nothing | Just a

-- Maybe: Used for partial function: e.g.
lookup :: k -> AssocList k v -> Maybe v

-- Error handling
-- Takes float, returns either inverse or nothing
inverse :: Float -> Maybe Float

-- EITHER
-- Used for 2-way alternatives, e.g.
type Number = Either Integer Float

-- Error handling with message
type Error a = Either String a
