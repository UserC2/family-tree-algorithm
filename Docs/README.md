# Family Tree Algorithm

## What it does
* The algorithm finds the family members and compares their relationships to each other.
* It currently outputs whether the first family member is older than the second and how many generations each family member is seperated by.
* These two outputs are fed into a dummy function that puts them in a string and returns them.

## What it should be doing
* The dummy function should output their actual relationship as a string. Originally, I was going to use an array for this, (see `Chart.md`), but that was not such a great idea.
* Indicating to the user they provided a non-existent name in a more user-friendly manner than `Segmentation fault: 11`.
	* It would be nice if *more* segfaults occured however, as certain names will cause `binarySearch()` to confidently return a valid result family member index.
* Documentation for some algorithm functions is always helpful. For example, indicating that `binarySearch()` **requires** that the array is sorted alphabetically from a-z (unless random segfaults are desired).