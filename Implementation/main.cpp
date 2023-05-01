#include "FamilyTree.h" // family tree is defined here
#include "FamilyMember.h"
#include "C2Utility.h" // make strings lowercase
#include "input.h" // get user input (and complain automatically when its bad)
#include <algorithm> // sort the family tree
#include <cmath> // abs
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

size_t binarySearch(const std::string_view nameToFind, family::family_t family)
{
	const std::string find{ utility::makeLower(nameToFind) };
	size_t minIndex{ 0 };
	size_t maxIndex{ family.size() - 1 };
	while (minIndex <= maxIndex)
	{
		// integer division equivalent to floor
		size_t i{ (minIndex + maxIndex) / 2 };
		std::string name{ utility::makeLower(family[i].get().m_name) };
		if (name > find) maxIndex = i - 1;
		if (name < find) minIndex = i + 1;
		if (name == find) return i;
	}
	return -1;
}

int distanceToRoot(const FamilyMember& person)
{
	int distance{ 0 };
	const FamilyMember* parent{ person.m_parent };
	while (parent != nullptr)
	{
		distance++;
		parent = parent->m_parent;
	}
	return distance;
}

std::string getRelationshipString(const int generationalDifference, bool aIsOlderOrSameAge)
{
	// (this still needs to be implemented)
	return std::to_string(generationalDifference) + (aIsOlderOrSameAge ? " a older/same" : " b older");
	// if (aDistanceFromCommon > bDistanceFromCommon)
	// 	;
	// 	// a younger
	// 	// same, child, grandchild, greatgrandchild...
	// if (aDistanceFromCommon < bDistanceFromCommon)
	// 	;
	// 	// b younger
	// 	// same, parent, grandparent, greatgrandparent...
	// else
	// 	;
	// 	// same generation
	// 	// sibling, firstcousin, second 1st 2nd 3rd 4th 5th 6th 
}

std::string findRelationship(const std::string_view a, const std::string_view b, family::family_t family)
{
	// find the family members
	size_t aIndex{ binarySearch(a, family) };
	size_t bIndex{ binarySearch(b, family) };
	// we should probably check that these are not -1 to avoid segfaults
	// find how far the family members are from root
	int aLevel{ distanceToRoot(family[aIndex].get()) };
	int bLevel{ distanceToRoot(family[bIndex].get()) };
	// calculate the distance between generations and if a is older or same age
	return getRelationshipString(std::abs(aLevel - bLevel), aLevel <= bLevel);
}

bool compareFamilyMember(const family::member_t a, const family::member_t b)
{
	return a.get().m_name < b.get().m_name;
}

int main()
{
	std::sort(family::tree.begin(), family::tree.end(), compareFamilyMember);

	std::cout << "Family members:\n";
	for (auto member : family::tree)
	{
		std::cout << member.get().m_name << '\n';
	}

	const std::string personA{ 
		input::getInput<std::string>("Enter the name of Person A: ") };
	const std::string personB{ 
		input::getInput<std::string>("Enter the name of Person B: ") };
	const std::string relationship{
		findRelationship(personA, personB, family::tree) };

	std::cout << personA << " is the " << relationship << " of " << personB
		 << '\n';

	return 0;
}
