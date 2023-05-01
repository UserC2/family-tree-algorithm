#include "FamilyMember.h"
#include <vector>

namespace family
{
	using member_t = std::reference_wrapper<const FamilyMember>;
	using family_t = std::vector<member_t>;

	// layer 1 (root)
	const FamilyMember Elizabeth{ "Elizabeth" };
	// layer 2
	const FamilyMember Marj{ "Marj", &Elizabeth };
	const FamilyMember Rosanne{ "Rosanne", &Elizabeth };
	const FamilyMember Ruthanne{ "Ruthanne", &Elizabeth };
	const FamilyMember Donnie{ "Donnie", &Elizabeth };
	const FamilyMember Patricia{ "Patricia", &Elizabeth };
	// layer 3
	const FamilyMember Kim{ "Kim", &Marj };
	const FamilyMember Monica{ "Monica", &Marj };
	const FamilyMember Martin{ "Martin", &Marj };
	const FamilyMember Gabe{ "Gabe", &Marj };
	const FamilyMember John{ "John", &Marj };
	const FamilyMember Ben{ "Ben", &Marj };
	const FamilyMember Jerome{ "Jerome", &Marj };
	// layer 4
	const FamilyMember JohnG{ "John G", &Kim };
	const FamilyMember Jamie{ "Jamie", &Kim };
	const FamilyMember Julia{ "Julia", &Kim };
	const FamilyMember Phil{ "Phil", &Monica };
	const FamilyMember Alley{ "Alley", &Monica };
	const FamilyMember Anna{ "Anna", &Monica };
	const FamilyMember Steven{ "Steven", &Monica };
	const FamilyMember Ellane{ "Ellane", &Gabe };
	const FamilyMember Jake{ "Jake", &Gabe };
	const FamilyMember Veera{ "Veera", &Jerome };
	const FamilyMember Precila{ "Precila", &Jerome };
	const FamilyMember Clarence{ "Clarence", &Jerome };
	// layer 5
	const FamilyMember Lincoln{ "Lincoln", &Phil };
	const FamilyMember Mo{ "Mo", &Ellane };
	// layer 6
	const FamilyMember Alex{ "Alex", &Lincoln };

	// array containing all family members
	family_t tree {
		Elizabeth
		, Marj, Rosanne, Ruthanne, Donnie, Patricia
		, Kim, Monica, Martin, Gabe, John, Ben, Jerome
		, JohnG, Jamie, Julia, Phil, Alley, Anna, Steven, Ellane, Jake, Veera, Precila, Clarence
		, Lincoln, Mo
		, Alex
	};
}