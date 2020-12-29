
-- x <- xs : generator, for any liust expression xs
-- expr: guard, for any Boolean expr

sq_nums :: Int -> [Int]
sq_nums n = [x^2 | x <- [1..n]]

cube_mod_3_nums :: Int -> [Int]
cube_mod_3_nums n = [x^3 | x <- [1..n], x^3 `mod` 3 == 0]


-- Nesting guards and generators
-- Multiple generators: nested iteration, leftmost == outermost
nested_nums = [ (x, y) | x <- [1..3], y <- [5..6]]

-- later generators can depend on earlier ones
later_dependant = [(x, y) | x <- [1..3], y<- [x..x+2]]

-- NESTED FOR LOOPS
{-
std::vector<pair<int, int>> list;
for (int x=1; x <= 5; x++){
    if (even(x)) {
        for (int y = x; y <= x+2; y++) {
            if (odd(x+y)) {
                // add to list
                list.push_back((x, y));
            }
        }
    }
}

translates to:
-}

nested_for = [(x,y) | x <- [1..5], even x, y <- [x..x+2], odd (x+y)]

-- MAP AND FILTER AS LIST COMPREHENSION
-- Iterate over list and perform f on each val
-- map f xs == [f x | x<-xs ]

-- Iterate over list and only keep elements that satisy 'p'
-- filter p xs == [x | x <- xs, p x]

-- Filter then map
-- (map f . filter p) xs == [f x | x <- xs, p x]

-- Flatten list
-- Maps 2d list of elements into single list by appending to single list
-- concat xss == [x | xs<-xss, x <- xs]

-- ZIPPING TWO LISTS
{-
a = [1, 2, 3]
b = [a, b, c]
zip a b = [(1, a), (2, b), (3, c)]

this also works with infinite lists
-}

-- String comprehension
parenthesise :: String -> String
parenthesise s = concat ([ "("++[c]++")" | c <- s])