#include "pch.h"
#include "CppUnitTest.h"
#include "../Lua/globals.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(expressions)
		{
			try {
				char* inp = "..\\texts\\expressions.lua";
				const char* standard = "..\\standard\\expressions.json";
				std::fstream st;
				st.open(standard);
				if (!st.is_open())
					throw std::runtime_error("Error opening file\n");
				std::string s;
				getline(st, s, '\0');
				st.close();
				Assert::IsTrue(parse(inp)==s);
			}
			catch (const std::exception& err) {
				Assert::IsTrue(false);
			}
		}

		TEST_METHOD(_for)
		{
			try {
				char* inp = "..\\texts\\for.lua";
				const char* standard = "..\\standard\\for.json";
				std::fstream st;
				st.open(standard);
				if (!st.is_open())
					throw std::runtime_error("Error opening file\n");
				std::string s;
				getline(st, s, '\0');
				st.close();
				Assert::IsTrue(parse(inp) == s);
			}
			catch (const std::exception& err) {
				Assert::IsTrue(false);
			}
		}

		TEST_METHOD(function)
		{
			try {
				char* inp = "..\\texts\\function.lua";
				const char* standard = "..\\standard\\function.json";
				std::fstream st;
				st.open(standard);
				if (!st.is_open())
					throw std::runtime_error("Error opening file\n");
				std::string s;
				getline(st, s, '\0');
				st.close();
				Assert::IsTrue(parse(inp) == s);
			}
			catch (const std::exception& err) {
				Assert::IsTrue(false);
			}
		}
		
		TEST_METHOD(_if)
		{
			try {
				char* inp = "..\\texts\\if.lua";
				const char* standard = "..\\standard\\if.json";
				std::fstream st;
				st.open(standard);
				if (!st.is_open())
					throw std::runtime_error("Error opening file\n");
				std::string s;
				getline(st, s, '\0');
				st.close();
				Assert::IsTrue(parse(inp) == s);
			}
			catch (const std::exception& err) {
				Assert::IsTrue(false);
			}
		}

		TEST_METHOD(repeat)
		{
			try {
				char* inp = "..\\texts\\repeat.lua";
				const char* standard = "..\\standard\\repeat.json";
				std::fstream st;
				st.open(standard);
				if (!st.is_open())
					throw std::runtime_error("Error opening file\n");
				std::string s;
				getline(st, s, '\0');
				st.close();
				Assert::IsTrue(parse(inp) == s);
			}
			catch (const std::exception& err) {
				Assert::IsTrue(false);
			}
		}

		TEST_METHOD(strings)
		{
			try {
				char* inp = "..\\texts\\strings.lua";
				const char* standard = "..\\standard\\strings.json";
				std::fstream st;
				st.open(standard);
				if (!st.is_open())
					throw std::runtime_error("Error opening file\n");
				std::string s;
				getline(st, s, '\0');
				st.close();
				Assert::IsTrue(parse(inp) == s);
			}
			catch (const std::exception& err) {
				Assert::IsTrue(false);
			}
		}

		TEST_METHOD(table)
		{
			try {
				char* inp = "..\\texts\\table.lua";
				const char* standard = "..\\standard\\table.json";
				std::fstream st;
				st.open(standard);
				if (!st.is_open())
					throw std::runtime_error("Error opening file\n");
				std::string s;
				getline(st, s, '\0');
				st.close();
				Assert::IsTrue(parse(inp) == s);
			}
			catch (const std::exception& err) {
				Assert::IsTrue(false);
			}
		}

		TEST_METHOD(_while)
		{
			try {
				char* inp = "..\\texts\\while.lua";
				const char* standard = "..\\standard\\while.json";
				std::fstream st;
				st.open(standard);
				if (!st.is_open())
					throw std::runtime_error("Error opening file\n");
				std::string s;
				getline(st, s, '\0');
				st.close();
				Assert::IsTrue(parse(inp) == s);
			}
			catch (const std::exception& err) {
				Assert::IsTrue(false);
			}
		}
	};
}

