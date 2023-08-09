#pragma once
#include <iostream>
#include<string>
#include<vector>
using namespace std;

class clsstring{

private:
	string _value;

public:

	clsstring(){
		_value = "";
	}

	clsstring(string value){
		_value = value;
	}

	void set_value(string value){
		_value = value;
	}

	string Value(){
		return _value;
	}

	__declspec(property(get= Value, put = set_value)) string value;

	static string upper_all_string(string text)
	{
		for (int i = 0; i < text.size(); i++)
		{
			if (text[i] != ' ')
				text[i] = toupper(text[i]);
		}
		return text;
	}

	string upper_all_string()
	{
		return upper_all_string(_value);
	}

	static string lower_all_string(string text)
	{

		for (int i = 0; i < text.size(); i++)
		{

			if (text[i] != ' ')
				if (isupper(text[i]))
					text[i] = tolower(text[i]);
		}
		return text;
	}

    string lower_all_string()
	{
		 return lower_all_string(_value);
	}

	static string remove_punctuation(string text)
	{
		string value=text;
		for (int i = 0; i < value.size(); i++)
		{
			if (!ispunct(value[i]))
				text += value[i];
		}
		return text;
	}

	string remove_punctuation()
	{
		return remove_punctuation(_value);
	}

	static string  trim_left(string text)
	{
		for (int i = 0; i < text.length(); i++)
		{
			if (text[i] != ' ')
			{
				text = text.substr(i, text.length() - i);
				return text;
			}
		}
		return "";

	}

	string  trim_left()
	{
		 return trim_left(_value);
	}

	static string  trim_right(string text)
	{
		for (int i = text.length() - 1; i >= 0; i--)
		{
			if (text[i] != ' ')
			{
				text = text.substr(0, text.length() - (text.length() - i));
				return text;
			}

		}
		return "";

	}

	string  trim_right()
	{
		return trim_right(_value);
	}

	static string  trim_right_left(string text)
	{
		text=trim_left(text);
		text=trim_right(text);
		return text;
	}

	string  trim_right_left()
	{
		return trim_right_left(_value);
	}

	static void each_word_in_line(string text,string delim)
	{
		int pos = 0;
		string subword = "";
		cout << endl;
		while ((pos = text.find(" ")) != string::npos)
		{
			subword = text.substr(0, pos);
			if (subword != " ")
				cout << subword << endl;
			text.erase(0, pos + delim.length());
		}
		if (text != "")
			cout << text << endl;
	}

	void each_word_in_line(string delim) {
		each_word_in_line(_value, delim);
	}

	static int count_string_subsets(string text,string delim)
	{
		int pos = 0;
		int count = 0;
		string subword = "";
		cout << endl;
		while ((pos = text.find(" ")) != string::npos)
		{
			subword = text.substr(0, pos);
			if (subword != " ")
				count++;
			text.erase(0, pos + delim.length());
		}
		if (text != "")
			count++;
		return count;
	}

	int count_string_subsets(string delim)
	{
		return count_string_subsets(_value, delim);
	}

	static char invert_charcter_case(char charcter){
	   (isupper(charcter)) ? charcter = tolower(charcter): charcter = toupper(charcter);
	}

	static string inverted_string_case(string text)
	{
		for (int i = 0; i < text.size(); i++)
		{
			if (text[i] != ' ')
				text[i] = invert_charcter_case(text[i]);

		}
		return text;
	}

	string inverted_string_case()
	{
		return inverted_string_case(_value);
	}

	static int count_capital_letter(string text)
	{
		int counter = 0;
		for (int i = 0; i < text.size(); i++)
		{
			if (text[i] != ' '&& isupper(text[i]))
				counter++;
		}
		return counter;
	}

	int count_capital_letter()
	{
		return count_capital_letter(_value);
	}

	static string up_first_char(string text)
	{
		bool isfirstLetter = true;
		for (int i = 0; i < text.size(); i++)
		{
			if (text[i] != ' ' && isfirstLetter)
				text[i] = toupper(text[i]);
			isfirstLetter = text[i] == ' ' ? true : false;
		}
		return text;
	}

	string up_first_char()
	{
	  return up_first_char(_value);
	}

	static string low_first_letter(string text)
	{
		if (isupper(text[0]))
			text[0] = text[0] + 32;

		for (int i = 0; i < text.size(); i++)
		{
			if (text[i] == ' ')
			{
				++i;
				if (isupper(text[i]))
					text[i] = text[i] + 32;
			}

		}
		return text;
	}

	string low_first_letter()
	{
		return low_first_letter(_value);
	}

	static bool isvowel(char charcter)
	{
		charcter = tolower(charcter);
		if (charcter == 'o' || charcter == 'i' || charcter == 'u' || charcter == 'e' || charcter == 'a')
			return true;
		else
			return false;
	}

	static void print_vowel(string text)
	{
		cout << endl << "vawol in string is :: ";
		for (int i = 0; i < text.size(); i++)
		{
			if (isvowel(text[i]))
				cout << text[i] << " ";
		}
	}

	void print_vowel()
	{
		print_vowel(_value);
	}

	static int count_vowel(string text)
	{
		int count = 0;
		cout << endl << "vawol in string is :: ";
		for (int i = 0; i < text.size(); i++)
		{
			if (isvowel(text[i]))
				count++;
		}
		return count;
	}

	int count_vowel()
	{
		return count_vowel(_value);
	}

	static int count_lower_letter(string text)
	{
		int counter = 0;
		for (int i = 0; i < text.size(); i++)
		{

			if (text[i] != ' ' && islower(text[i]))
				counter++;
		}
		return counter;
	}

	int count_lower_letter()
	{
		return count_lower_letter(_value);
	}

	static void print_len_cap_low_letters(string text)
	{
		cout << "string length is :: " << text.length() << endl;
		cout << "capital letters count is :: " << count_capital_letter(text) << endl;
		cout << "lower letters count is :: " << count_lower_letter(text) << endl;
	}

	void print_len_cap_low_letters()
	{
		print_len_cap_low_letters(_value);
	}

	static void exist_letter_in_string(string text,char y, bool match_case = true)
	{
		int count = 0;
		for (int i = 0; i < text.size(); i++)
		{
			if (match_case)
			{
				if (y == text[i])
					count++;
			}
			else
			{
				if (toupper(y) == toupper(text[i]))
					count++;
			}
		}
		if (match_case)
			cout << "count of letter [" << y << "]" << "in the string match case is::  " << count << endl;
		else
		{
			cout << "count of letter [" << y << "]" << "in the string NOt match case is::  " << count << endl;
		}

	}

	void exist_letter_in_string(char y, bool match_case = true)
	{
		exist_letter_in_string(_value, y, match_case);
	}

	static string replace_in_string(string text,string original, string toreplace)
	{
		int pos;
		pos = text.find(original);
		while (pos != string::npos)
		{
			text = text.replace(pos, original.length(), toreplace);
			pos = text.find(original);
		}
		return text;
	}

	string replace_in_string(string original,string toreplace)
	{
		return replace_in_string(_value, original, toreplace);
	}

	static vector<string> vector_string_split(string text,string delim)
	{
		vector <string> vstring;
		short pos = 0;
		string subword = "";
		while ((pos = text.find(delim)) != string::npos)
		{
			subword = text.substr(0, pos);
			if (subword != "")
				vstring.push_back(subword);
			text.erase(0, pos + delim.length());
		}
		if (text != "")
			vstring.push_back(text);

		return vstring;
	}

	vector<string> vector_string_split(string delim) {
		return  vector_string_split(_value, delim);
	}

	static string print_v_text_reversed(string text, string delim)
	{
		vector<string> vstring;
		vstring= vector_string_split(text,delim);
		vector<string>::iterator it = vstring.end();
		text = "";
		while (it != vstring.begin())
		{
			it--;
			text += *it + delim;
		}

		return text;
	}

	string print_v_text_reversed(string delim)
	{
		return print_v_text_reversed(_value,delim);
	}

	static string join_string(vector <string> vstring, string delim)
	{
		string line = "";

		for (int i = 0; i < vstring.size() - 1; i++)
		{
			if (vstring[i] != " ")
				line += vstring[i] + delim;
		}
		line += vstring[vstring.size() - 1];
		return line;
	}

	static string join_string(string arr[20], int size, string delim)
	{
		string line = "";

		for (int i = 0; i < size; i++)
		{
			if (arr[i] != " " )
				line += arr[i] + delim;
		}
		line += arr[size];
		return line;
	}

	static string replace_in_string_using_split(string text,string delim, string orig, string toreplace, bool match = true)
	{
		vector<string> vstring;
		vstring = vector_string_split(text,delim);
		for (int i = 0; i < vstring.size(); i++)
		{
			if (match)
			{
				if (orig == vstring[i])
					vstring[i] = toreplace;
			}
			else
			{
				if (upper_all_string(vstring[i]) == upper_all_string(orig))
					vstring[i] = toreplace;
			}
		}
		text = join_string(vstring, " ");
		return text;
	}

	string replace_in_string_using_split(string delim, string orig, string toreplace, bool match = true)
	{
		return replace_in_string_using_split(_value,delim,orig, toreplace, match);
	}

};

