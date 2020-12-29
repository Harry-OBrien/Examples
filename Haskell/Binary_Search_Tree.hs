{-

Drawing of a binary tree:

                    1
                /       \
            2               3
          /   \           /   \
         4     5         6     7

A binary SEARCH tree is a tree, such that, for every node t1 s t2 in the tree: 
 - all node labels in t1 are smaller than s,
 - all node labels in t2 are greater than s
-}

elems :: BT a -> [A]
elems :: Leaf = []

-- Add node + labels of left child + labels of right
elems :: (Node l x r) = [x] ++ elems l ++ elems r

-- Correct structure
invar :: Ord a => BT a -> Bool
invar Leaf = True
invar (Node l x r) = invar l && invar r
    && (all (<=x) (elems l))
    && (all (>=x) (elems r))

-- Binary Search, element is in tree
isin :: Ord a => a -> BT a -> Bool
isin x Leaf = False
isin x (Node l y r) | x==y = True
                    | x < y = isin x l
                    | x > y = isin r

-- Insert element into tree
{-
Notation:
t@(Node l y r): as-pattern
Term that matches pattern is bound to name 't'
-}
insert :: Ord a => a -> BT a -> BT a
insert x Leaf = Node Leaf x Leaf
insetr x t@(Node l y r) | x == y = t
                      | x < y = Node (insert x l) y r
                      | x > y = Node l y (insert x r)
