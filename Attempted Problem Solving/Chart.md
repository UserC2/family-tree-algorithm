## What is this file?
* An attempt at generating a chart similar to [this one](http://www.genealogyintime.com/articles/the-key-to-understanding-family-relationships-page1.html) using a computer program (or approximating it using switch statements).
* It turns out this chart doesn't work for determining aunts/uncles, parents, grandparents, or greatgrandparents, which is why there's a few charts in this document.
* Also, I got confused with vague axis definitions a few times, so there's a few extra charts.

x = person 1
y = person 2

x is the _ of y

(value being dist from most common)
e.g. x->3, y->0
x is the 'great grandchild' of y
good

e.g. x->0, y->3
x is the 'great grandparent' of y

## src chart
  0    1    2    3    ...
0 ca   ch   gc   ggc  2ggc
1 ch   bs   nn   gnn  ggnn
2 gc   nn   fc   fcor fctr
3 ggc  gnn  fcor sc   scor
. 2ggc ggnn fctr scor tc

## definitions
gp = grandparent
sp = same person
sib = sibling
x oldest?
y newest?
no?

00 x same as y
01 x parent of y
10 x child of y

## improved chart
  0    1    2    3    ...
0 sp   ch   gc   ggc  2ggc
1 p    bs   nn   gnn  ggnn
2 gp   nn   fc   fcor fctr
3 ggp  gnn  fcor sc   scor
. 2ggp ggnn fctr scor tc
// grandparents will be x



x = person is _ to...
y = second person

dist from common (person a younger)
0 = same
1 = child
2 = grandchild
3 = (3 - 2) * great grandchild
4 = (4 - 2) * great grandchild

dist from common (person b older)
0 = same
1 = parent
2 = grandparent
3 = (3 - 2) * great grandparent
4 = (4 - 2) * great grandparent

TODO: reverse order NO!
x = less close
y = more close
  0    1    2    3    ...
0 sp   ch   gc   ggc  2ggc
1 p    sib  nn   gnn  ggnn
2 gp   nn   fc   fcor fctr
3 ggp  gnn  fcor sc   scor
. 2ggp ggnn fctr scor tc

uncle/aunt

martin d1 y
phil d2 x

martin = uncle of phil
x2 y1
x2 == gc, nn, fc, fcor, fctr
y1 == nn (swap nn with au)

reversed:
x = personADistance
y = personBDistance
1 is _ to 3
chart is reversed
  0    1    2    3    ...
0 sp   p    gp   ggp  2ggp
1 ch   sib  au   gau  ggau
2 gc   nn   fc   fcor fctr
3 ggc  gnn  fcor sc   scor
. 2ggc ggnn fctr scor tc

Good chart:
  0    1    2    3    ...  pad
0 sp   ch   gc   ggc  2ggc
1 p    sib  nn   gnn  ggnn
2 gp   au   fc   fcor fctr
3 ggp  gau  fcor sc   scor
. 2ggp ggau fctr scor tc
pbd

## Function
if equal:
0, 0 = same
1, 1 = sibling
2, 2 = fc
3, 3 = sc
4, 4 = tc
n = 0: same person
n = 1: sibling
n >= 2:
n, n = prefix(n - 1) cousin

prefix:
	1: first (or blank string)
	2: second
	3: third
	4: fourth
	5: ...

x, y
if unequal:
n = 1:
1, 0 = parent
n = 2:
2, 0 = grandparent
n >= 3:
n, 0 = (great * (n - 2)) grandparent
0, 1 = child
0, 2 = grandchild
0, n = (great * (n - 2)) grandchild

aunt/uncle/nephew/niece
2, 1 = aunt/uncle
3, 1 = grand aunt/uncle
n, 1 = (great * (n - 3)) grand aunt/uncle
1, 2 = nephew/niece
1, 3 = grand nephew/niece
1, n = (great * (n - 3)) grand nephew/niece

first/second/third cousin

optimization:
search both at the same time
- if string == person 1
- if string == person 2
- if both found, go back