## What is this file?
* An attempt at creating a recursive algorithm.
* The algorithm works (I think), it's just less efficient than the binary search algorithm.
* See `Chart.md` for the 'chart' referred to in this document.

## Input:
- Person 1 (String)
- Person 2 (String)
- Tree (`Tree.md`)

## Algorithm:

### find(person):
1. Start at R
1. If r != person
1. else return person

## Output:
- Relationship (String)

Human example:

P1: Marj
P2: Lincoln

f = P1
Start R:
R -> Elizabeth
R != f

Chk R descendants
R-1 -> Marj
R-1 == f
FOUND
Return R-1

R:
Return R-1

P1 = R-1

Start R (don't start P1, can be older or same generation, which would be ignored)

f = P2
R -> Elizabeth
R != f
Chk R descendants

R-1 -> Marj
R-1 != f
Chk R-1 descendants

R-1-1 -> Kim
R-1-1 != f
Chk R-1-1 descendants

R-1-1-1 -> John G
R-1-1-1 != f
No R-1-1-1 descendants
Chk next R-1-1 descendant

R-1-1-2 -> Jamie
R-1-1-2 != f
No R-1-1-2 descendants
Chk next R-1-1 descendant

R-1-1-3 -> Julia
R-1-1-3 != f
No R-1-1-3 descendants
Chk next R-1-1 descendant

No more R-1-1 descendants
Return NULL
// Chk next R-1 descendant

R-1:
R-1-2 -> Monica
R-1-2 != f
Chk R-1-2 descendants

R-1-2-1 -> Phil
R-1-2-1 != f
Chk R-1-2-1 descendants

R-1-2-1-1 -> Lincoln
R-1-2-1-1 == f
FOUND
Return R-1-2-1-1

R-1-2-1:
Return R-1-2-1-1

R-1-2:
Return R-1-2-1-1

R-1:
Return R-1-2-1-1

R:
Return R-1-2-1-1

P2 = R-1-2-1-1

Find most common ancestor:
P1 = R-1
P2 = R-1-2-1-1
'R-1' is most common

(Alex & Mo example)
Alex 	= R-1-2-1-1-1
Mo 		= R-1-4-1-1
'R-1' is most common
Alex dist from R-1 = 4
Mo dist from R-1 = 3
Alex->4 Mo->3
chart[4][3]->second cousin once removed

R-1 -> Marj
Marj is most common ancestor

Find relationship
P1 = R-1
P2 = R-1-2-1-1
Common = R-1

P1 dist Common = 0

P2 dist Common = 3

Pass into chart (zero-indexed):
chart[0][3]->"Great Grandchild"

What if reversed
P1 = R-1-2-1-1
P2 = R-1

chart[3][0]->"Great Grandchild"
... wrong

P1 is the _ of P2
P1 is the great grandfather/mother of P2
oh chart is wrong
we can generate chart for us, is very simple no its not