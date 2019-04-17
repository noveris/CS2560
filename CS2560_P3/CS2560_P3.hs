import Data.List

reverse_polish :: String -> Float
reverse_polish = head . foldl foldfunc [] . words
  where foldfunc (x:y:ys) "*" = (x * y):ys
        foldfunc (x:y:ys) "+" = (x + y):ys
        foldfunc (x:y:ys) "-" = (y - x):ys
        foldfunc (x:y:ys) "/" = (y / x):ys
        foldfunc (x:y:ys) "^" = (y ** x):ys
        foldfunc (x:xs) "ln" = log x:xs
        foldfunc xs "sum" = [sum xs]
        foldfunc xs num = read num:xs
