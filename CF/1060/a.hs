main :: IO ()
main = do
	x <- getLine
	y <- getLine :: IO String
	putStrLn $ solve $ map read $ split y


split :: String -> [String]
split [] = []
split (x:xs) = [x]:split xs

solve::[Int] -> String
solve x = 	let ochos = contar x 8 in
			let n = length x in
			go n ochos
			where go 0 _ = 0
					go _ 0 = 0
					go m o = 1 + 

contar :: [Int] -> Int -> Int
contar [] _ = 0
contar (x:xs) y = (if x == y then 1 else 0) + (contar xs y)