#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class Hashing
{
public:
    vector<string> table;
	int HT_Size,Table_cnt,collision;
	float load_factor;
    	hash<string> hashfunc;
	

	Hashing(int n)
	{
		HT_Size = n,Table_cnt = 0,collision = 0,load_factor = 0;
		table.assign(n, "");
	}

	int Collision_fun(int value)
	{
		int i = 1,quadratic_val = 1;
		int new_hash = (value + quadratic_val) % HT_Size;
		while (table[new_hash] != "")
		{
			i++;
			collision++;
			quadratic_val += 2 * i - 1;    // Here we find the difference from the previous value rather than computing from the starting address
			new_hash = (value + quadratic_val) % HT_Size; // we use modulus funct to fit into  the table size
		}
		return new_hash;
	}
	void insert(string quadratic_val)
	{
		int value;
		string temp;
		ifstream input_file;
		input_file.open(quadratic_val);
		while (getline(input_file, temp))
		{
			stringstream linestream(temp);
			string input_words;
			while (getline(linestream, input_words, ','))
			{
				value = hashfunc(input_words) % HT_Size;
				if (table[value] == "")
				{
				    table[value] = input_words;
				}
				else
				{
				    	collision++;
					table[Collision_fun(value)]=input_words;
				}
				Table_cnt++;
				load_factor = (float)Table_cnt / (float)HT_Size;
				if (load_factor > 0.5)
				{
					cout << "Total collisions before hashing: " << collision << endl;
					HT_Size = HT_Size*2;
					table.assign(HT_Size, "");
					Table_cnt = 0,collision = 0,load_factor = 0;
					input_file.close();
					this->insert(quadratic_val);
					return;
				}
			}
		}
		input_file.close();
		return;
	}
};
int main()
{
	Hashing HT(31);
	HT.insert("Input_words.txt");
	cout << "Total number of collisions after rehashing : "<<HT.collision;
	return 0;
}
