#pragma once
#include <map>
#include <vector>
#include <string>

class Table
{
	unsigned long long id;
	std::vector<std::map<std::string, std::pair<unsigned long long, std::string>>> t;
public:
	Table() :id(0) {}
	unsigned long long add(std::string name, std::string type)
	{
		int size = t.size();
		for (int i = size - 1; i > -1; i--)
		{
			if (t[i].find(name) != t[i].end())
			{
				t[i][name].second = type;
				return t[i][name].first;
			}
		}
		t[0].insert(std::pair<std::string, std::pair<unsigned long long, std::string>>
			(name, std::pair<unsigned long long, std::string>(++id, type)));
		return id;
	}

	unsigned long long add_local(std::string name, std::string type)
	{
		size_t i = t.size() - 1;
		if (t[i].find(name) != t[i].end())
		{
			t[i][name].second = type;
			return t[i][name].first;
		}
		else
		{
			t[i].insert(std::pair<std::string, std::pair<unsigned long long, std::string>>
				(name, std::pair<unsigned long long, std::string>(++id, type)));
			return id;
		}
	}

	std::pair<unsigned long long, std::string> get(std::string name)
	{
		int size = t.size();
		for (int i = size - 1; i > -1; i--)
			if (t[i].find(name) != t[i].end())
				return t[i][name];
		return std::pair<unsigned long long, std::string>(0, "nil");
	}

	void add_level()
	{
		t.push_back(std::map<std::string, std::pair<unsigned long long, std::string>>());
	}

	void delete_level()
	{
		t.pop_back();
	}

	void clear()
	{
		id = 0;
		t.clear();
	}
};
