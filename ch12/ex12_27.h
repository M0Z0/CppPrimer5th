#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <set>
#include <vector>
#include <map>
#include <string>

using namespace std;

class QueryResult;
class TextQuery{
public:
	using line_no = vector<string>::size_type;
	TextQuery(ifstream&);
	QueryResult query(const string&) const;
private:
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<line_no>>> wm;
};

TextQuery::TextQuery(ifstream &is) : file(new vector<string>)
{
	string text;
	while (getline(is, text)) {
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word;
		while (line>>word) {
			auto &lines = wm[word];
			if (!lines)
			{
				lines.reset(new set<line_no>);
			}
			lines->insert(n);
		}
	}
}