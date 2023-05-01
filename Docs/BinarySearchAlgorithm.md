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
		'minIndex' as array_index_type starting at 0
		'maxIndex' as array_index_type starting at size of Family - 1
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

findCommonAncestor:
	requires:
		'personA' as FamilyMember
		'personB' as FamilyMember
	returns:
		most common ancestor as FamilyMember
		or void if no common ancestor is found
	function:
		'ancestorsOfA' as array of FamilyMember = findPathToRoot(personAIndex)
		'ancestorsOfB' as array of FamilyMember = findPathToRoot(personBIndex)
		'i' as array_index_type
		while i < size of ancestorsOfA:
			if (FamilyMember at index i of ancestorsOfA == FamilyMember at index i of ancestorsOfB):
				return FamilyMember at i of ancestorsOfA;
			i = i + 1
		return void

findPathToRoot:
	requires:
		'person' as FamilyMember
	returns:
		path to root as array of FamilyMember
	function:
		'path' as array of FamilyMember
		'parent' as FamilyMember = parent of person
		while parent of parent != root:
			path.push(parent of parent)
			parent = parent of parent // what is this code?
		return path
			
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

## Strengths

## Weaknesses