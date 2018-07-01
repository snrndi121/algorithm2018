# Problem
- We are going to implement a simple editor, which only processes lowercase letters.
  And the editor has a cursor that can be located from front of a sentence to last
  of it. So, a range of movement is (L + 1) if the length of a sentenc L.
- For example, here is "abcd". Now the cursor is on right of 'd'. However it is possible
  to be on left of 'a' and it is meaningless.

- These are [command] of the editor
  L : Move a cursor left (_ignore it if a cursor is on the first of a sentence_)
  D : Move a cursor right (_ignore it if a cursor is on the last of a sentence_)
  B : Get rid of a word on left of cursor (_ignore it if a cursor is on the first of a sentence_). It looks like the cursor moved left, but actually there is no movement.
  P $ : Insert $ into left on the cursor.

# Condition
- The inital sentence is given on the first line._(L <= 100,000)_
- And the second line is the number of commands.(each commands are below it).
  _(1<=N <= 500,000)_
- After a initial sentence is entered, the cursor is on last of a sentence.
 (ex)'ab', then cursor is right of 'b'.
# Input_1
abcd
3
P x
L
P y
# Ouput_1
abcdyx

# Input_2
abc
9
L
L
L
L
L
P x
L
B
P y
# Ouput_2
yxabc

# Input_3
dmih
11
B
B
P x
L
B
B
B
P y
D
D
P z
# Ouput_3
yxz
