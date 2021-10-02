import qualified Text.Parsec as Parsec
import Text.Parsec ((<?>))
import Control.Applicative

parse rule text = Parsec.parse rule "(source)" text

test_simple_expr_pairs = [
  ("42",Const 42),
  ("-(-(0))",Uminus (Uminus (Const 0))),
  ("x",Var "x"),
  ("__x",Var "__x"),
  ("x67",Var "x67"),
  ("_67",Var "_67"),
  ("x+1",Binop Plus (Var "x") (Const 1)),
  ("x*2",Binop Times (Var "x") (Const 2)),
  ("a+b*c",Binop Plus (Var "a") (Binop Times (Var "b") (Var "c"))),
  ("(a+b)*c",Binop Times (Binop Plus (Var "a") (Var "b")) (Var "c")),
  ("a+b <= c*d",Binop LessEq (Binop Plus (Var "a") (Var "b")) (Binop Times (Var "c") (Var "d")))
  ]

