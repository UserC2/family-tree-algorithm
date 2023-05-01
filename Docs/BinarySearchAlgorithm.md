# Binary Search Algorithm

## Requirements
* Family member to find (string)
* Family tree (array)
	* Alphabetically sorted array of `FamilyMember`:
		* Name of member (string)
		* Pointer or reference to parent member (`FamilyMember`)

## Description
1. Find minimum and maximum index
1. Find the midpoint of the family array
1. Examine the family member at this index:
	1. If name > family member to find's name:
		* reduce maximum index to current index - 1
	1. If name < family member to find's name:
		* increase minimum index to current index + 1
	1. If name == family member to find's name:
		* return index
	1. If minIndex <= maxIndex:
		* return -1 (invalid index) (family member not found)

## Pseudocode
### Algorithm
```
binarySearch:
	requires:
		'name' as string
		'Family' as alphabetically sorted array of FamilyMember
	returns:
		index of family member as array_index_type
	function:
		'minIndex' as array_index_type = 0
		'maxIndex' as array_index_type = size of Family - 1
		while minIndex <= maxIndex:
			'i' as array_index_type = floor((minIndex + maxIndex) / 2)
			if name of FamilyMember at index i of Family is > name:
				maxIndex = i - 1;
			if name of FamilyMember at index i of Family is < name:
				minIndex = i + 1;
			if name of FamilyMember at index i of Family is == name:
				return i;
```

### Generic
```
FamilyMember:
	members:
		name as string
		parent as FamilyMember

distanceToRoot:
	requires:
		'person' as FamilyMember
	returns:
		distance from root of tree as integer
	function:
		'distance' as integer = 0
		'parent' as FamilyMember = parent of person
		while parent is valid:
			increment distance by 1
			parent = parent of parent
		return distance
			
findRelationship:
	requires:
		'personAName' as string
		'personBName' as string
		'Family' as alphabetically sorted array of FamilyMember
	returns:
		relationship of family member as string
	function:
		'personAIndex' as array_index_type = binarySearch(personAName, Family)
		'personBIndex' as array_index_type = binarySearch(personBName, Family)
		'personALevel' as integer = distanceToRoot(FamilyMember at personAIndex of Family)
		'personBLevel' as integer = distanceToRoot(FamilyMember at personBIndex of Family)

		'generationalDistance' as integer = abs(personALevel - personBLevel)
		'aIsOlderOrSameAge' as boolean = personALevel <= personBLevel

		note: function does not exist yet
		return getRelationshipString(generationalDistance, aIsOlderOrSameAge)
```

**This class not likely to be used:**
```
Relationships:
	member:
		'baseArray' as array of array of string
			Value:
				{ same person, child, grandchild }
				{ parent, sibling, nephew/niece, grand nephew/niece }
				{ grandparent, aunt/uncle }
				{ ..., grand aunt/uncle }
	functions:
		getString:
			requires:
				'personADistance'
				'personBDistance'
			returns:
				relationship of person A to person B as string
			function:
				'relationship' as string
				try:
					relationship = baseArray[personADistance][personBDistance]
				if failed because of 'array index invalid':
					match personADistance:
						is 3:
				return relationship

		attempt 2:
			requires/returns same
			function:
				match personADistance:
					<0:
						Error
					0:
						match personBDistance:
							<0:
								Error
							0:
								same person
							1:
								parent
							>1:
								(great * (personBDistance - 2)) grandparent
					1:
						match personBDistance:
							<0:
								Error
							0:
								child
							1:
								sibling
							2:
								aunt/uncle
							>2:
								(great * (personBDistance - 3)) grand aunt/uncle
					2:
						match personBDistance:
							<0:
								Error
							0:
								grandchild
							1:
								nephew/niece
							2:
								first cousin
							3:
								first cousin once removed
							4:
								first cousin twice removed
							>4:
								first cousin toString(personBDistance - -2) times removed
					>2:
						match personBDistance:
							<0:
								Error
							0:
								(great * (personADistance - 2)) grandchild
							1:
								(great * (personADistance - 2)) grand nephew/niece
							2:
								first cousin once removed
							>2:
								first cousin toString(personADistance - 1) times removed
						This is a bit too complicated.
```

## Complexity
### Time
**`O((log n) + l)`** where `n` is the amount of members in the family tree and `l` is the amount of levels in the family tree

**Explanation:**
* The array containing all family members is assumed to be sorted prior to using the algorithm.
* `log n` is the amount of iterations necessary to find a family member within the array using a binary search algorithm.
* Once the family member is found, it will take up to `l` iterations to find how far they are from the root.
* This process must be repeated for each family member, yielding a complexity of **`O(2(log n) + 2l)`**.
* The coefficient `2` can be omitted as it does not significantly affect the growth rate.
* (`l` could also be omitted as it is a constant and does not affect the growth rate, however it is a significant contributor to the time complexity of the algorithm for any remotely 'realistic' use case.)
	* For example, set `n` to 10<sup>299</sup> (a fairly large number).
	* log<sub>2</sub>(n) ~= 993 iterations.
	* For a family tree of that size, ~1000 levels wouldn't be unreasonable, which means that `l` would contribute 1000 iterations.

### Space
**`O(1)`**

**Explanation:**
* This algorithm only uses the family tree array provided to it. No copies are made.