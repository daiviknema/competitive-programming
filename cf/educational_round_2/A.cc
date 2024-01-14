// https://codeforces.com/contest/600/problem/A

#include <bits/stdc++.h>

using namespace std;

class WordExtractor {

private:
    bool is_delim(char ch) {
	return (ch == ',' || ch == ';');
    }

public:
    vector<string> extract_words(const string& s) {
	int prev_delim = -1;
	vector<string> ans;
	for (int i = 0; i < s.length(); i++) {
	    if (is_delim(s[i])) {
		string word = s.substr(prev_delim+1, i-prev_delim-1);
		ans.push_back(word);
		prev_delim = i;
	    }
	}
	ans.push_back(s.substr(prev_delim+1, s.length()-1-prev_delim));
	return ans;
    }
};

class NumberValidator {
private:
    bool is_zero(const string& s) {
	return (s.length() == 1 && s[0] == '0');
    }

    bool is_number(char ch) {
	return ('0' <= ch && ch <= '9');
    }

public:
    bool is_valid_number(const string& s) {
	if (s == "") return false;

	bool is_valid = true;

	if (is_zero(s)) return is_valid;

	// all characters in the string lie between '0' and '9'
	for (char ch : s) {
	    is_valid = is_valid && is_number(ch);
	}

	// check for leading zeros
	is_valid = is_valid && (s[0] != '0');

	return is_valid;
    }
};

int main() {
    string s;
    cin >> s;

    WordExtractor we;
    NumberValidator nv;

    vector<string> words = we.extract_words(s);

    string a = "", b = "";
    for (string word : words) {
	if (nv.is_valid_number(word)) {
	    a += word;
	    a += ",";
	} else {
	    b += word;
	    b += ",";
	}
    }
    
    if (a != "") a = "\"" + a.substr(0, a.length()-1) + "\"";
    else a = "-";

    if (b != "") b = "\"" + b.substr(0, b.length()-1) + "\"";
    else b = "-";


    cout << a << endl;
    cout << b << endl;

    return 0;
}
