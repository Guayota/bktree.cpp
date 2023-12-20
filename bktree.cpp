#ifndef __CSUSSUS_H
#define __CSUSSUS_H
#include <map>
#include <cstdint>
#include <string>
#include <functional>
#include <optional>

namespace csus
{
template<
	typename Key,
	typename Distance,
	Distance distance_fn(Key&, Key&)
>
class bktree {
protected:
	template<typename K = Key, typename NM = Distance>
	class bkt_node {
	private:
		using NT = bkt_node<K, NM>;

	private:
		K				m_key;
		std::map<Distance, Key>* m_children;
		std::optional<Distance> m_max_child_distance;

	public:
		bkt_node(const Key& key) :
			m_key(key),
			m_children(new std::map<Distance, Key>),
			m_max_child_distance(std::nullopt)
		{}

		~bkt_node() {
			if (m_children->empty()) return;

			for (auto it = m_children->begin(); it != m_children->end(); ++it)
				delete it->second;
			
			delete m_children;
		}

	public:
		bool add_child(const Distance& distance, const Key& key) {
			m_children->insert(distance, key);
			// m_max_child_distance = std::max({ m_max_child_distance, distance }, std::optional == );
		}
		};
	};
	
	extern size_t lev_distance_substr(const std::string& s1, const std::string& s2);
	extern size_t lev_distance_cstr(const char* cs1, size_t n1, const char* cs2, size_t n2);
	extern size_t lev_distance(const std::string& s1, const std::string& s2);

	//using bktree_str = bktree<std::string, size_t, csus::lev_distance>;
}
#endif
