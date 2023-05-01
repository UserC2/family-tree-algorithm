#ifndef ALGORITHM_FAMILYMEMBER_H
#define ALGORITHM_FAMILYMEMBER_H

#include <string_view>
#include <vector>

// struct behaves as a public class in C++
struct FamilyMember
{
	using relatives_t = std::vector<const FamilyMember*>;
	const FamilyMember* m_parent;
	const std::string_view m_name;

	/*
	 * Create a root FamilyMember with no parent.
	 */
	FamilyMember(const std::string_view name)
		: m_parent{ nullptr }
		, m_name{ name }
	{}

	/*
	 * Create a FamilyMember with the specified parent.
	 */
	FamilyMember(const std::string_view name, const FamilyMember* parent)
		: m_parent{ parent }
		, m_name{ name }
	{}

	/*
	 * Return the children of this person found in 'relatives'.
	 */
	relatives_t findChildren(relatives_t relatives) const
	{
		relatives_t children{};
		for (auto member : relatives)
		{
			if (member->m_parent == this)
			{
				children.push_back(member);
			}
		}
		return children;
	}
};

#endif