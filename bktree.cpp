#include "csussus.hpp"

namespace csus
{
	size_t lev_distance_substr(const std::string& s1, const std::string& s2) {
		size_t l1 = s1.length(), l2 = s2.length();
		if (l1 == 0) return l2;
		if (l2 == 0) return l1;

		auto t1 = s1.substr(1, l1 - 1);
		auto t2 = s2.substr(1, l2 - 1);
		if (s1.at(0) == s2.at(0)) return lev_distance_substr(t1, t2);

		return 1 + std::min<size_t>({
				lev_distance_substr(t1, s2),
				lev_distance_substr(s1, t2),
				lev_distance_substr(t1, t2),
			});
	}

	size_t lev_distance_cstr(
		const char* cs1, size_t n1,
		const char* cs2, size_t n2
	) {
		if (n1 == 0) return n2;
		if (n2 == 0) return n1;

		if (cs1[0] == cs2[0]) return lev_distance_cstr(cs1+1, n1-1, cs2+1, n2-1);

		return 1 + std::min<size_t>({
				lev_distance_cstr(cs1 + 1, n1 - 1, cs2    , n2),
				lev_distance_cstr(cs1    , n1    , cs2 + 1, n2 - 1),
				lev_distance_cstr(cs1 + 1, n1 - 1, cs2 + 1, n2 - 1),
			});
	}

	size_t lev_distance(const std::string& s1, const std::string& s2) {
		size_t l1 = s1.length(), l2 = s2.length();
		if (l1 == 0) return l2;
		if (l2 == 0) return l1;

		const char* c1 = s1.c_str();
		const char* c2 = s2.c_str();
		if (s1.at(0) == s2.at(0)) return lev_distance_cstr(c1, l1, c2, l2);

		return 1 + std::min<size_t>({
				lev_distance_cstr(c1 + 1, l1 - 1, c2    , l2),
				lev_distance_cstr(c1    , l1    , c2 + 1, l2 - 1),
				lev_distance_cstr(c1 + 1, l1 - 1, c2 + 1, l2 - 1),
			});
	}
}
