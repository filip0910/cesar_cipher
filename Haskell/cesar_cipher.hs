import Control.Monad (forM_, when)
import Data.Char
import Data.List
import System.Environment
import System.IO

main :: IO ()
main = do
  args <- getArgs
  let shift = if null args then 1 else read (head args) :: Int
  readChars shift

shiftChar :: Char -> Int -> Char
shiftChar c shift
  | ord c <= ord 'Z' =
      if (ord c + shift) > ord 'Z'
        then chr (mod (ord c + shift) (ord 'Z') + ord 'A' - 1)
        else
          ( if (ord c + shift) < ord 'A'
              then chr (ord c + shift - ord 'A' + ord 'Z' + 1)
              else chr (ord c + shift)
          )
  | otherwise =
      if (ord c + shift) > ord 'z'
        then chr (mod (ord c + shift) (ord 'z') + ord 'a' - 1)
        else
          ( if (ord c + shift) < ord 'a'
              then chr (ord c + shift - ord 'a' + ord 'z' + 1)
              else chr (ord c + shift)
          )

readChars :: Int -> IO ()
readChars shift = forM_ [1 ..] $ \_ -> do
  c <- getChar
  when (c /= '\n') $ do
    putStrLn (shiftChar c shift : "")
