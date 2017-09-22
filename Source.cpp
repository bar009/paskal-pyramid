#include "Header.h"

int ROWS = 0;

int main(void)
{
	string choise = "";
	while (true)
	{
		cout << "How much rows do you want? ";
		cin >> ROWS;
		Pyramiad pyramidOne;
		pyramidOne.makeRows();
		pyramidOne.startPyramid();
		pyramidOne.makeNumbers();
		pyramidOne.print();

		while (true)
		{
			cout << endl << "Enter EXIT to close. Enter PLAY to continue." << endl;
			cin >> choise;

			if ((choise.compare("exit") == 0) || (choise.compare("EXIT") == 0))
				return 0;
			if ((choise.compare("play") == 0) || (choise.compare("PLAY") == 0))
			{
				cout << "Yay!" << endl << endl;
				break;
			}
			else
				cout << "wrong input" << endl;
		}
	}
}

void Pyramiad::makeRows()
{
	vector<int> t;
	for (int i = 0; i < ROWS; i++)
		_rows.push_back(t);
}

void Pyramiad::startPyramid()
{
	_rows.at(0).push_back(1);

	if (ROWS > 1)
	{
		_rows.at(1).push_back(1);
		_rows.at(1).push_back(1);
	}
	if (ROWS > 2)
	{
		_rows.at(2).push_back(1);
		_rows.at(2).push_back(2);
		_rows.at(2).push_back(1);
	}
}

//algorithem
void Pyramiad::makeNumbers()
{
	unsigned int len = 0;
	unsigned int j = 0, k = 1;

	for (unsigned int i = 3; i <= ROWS-1; i++)//look for any row
	{
		j = 0, k = 1;
		len = _rows.at(i - 1).size();
		_rows.at(i).push_back(1);

		for (unsigned int l = 0; l < len+1; l++) //check how many number should be
		{

			if (len >= 3 && len > k && len > j) //if it's don't make more numbers more than should be
			{
				_rows.at(i).push_back(_rows.at(i - 1).at(k)+ _rows.at(i - 1).at(j));
				
			}

			else
				break;

			if (k < j)
				k = k + 2;

			else
				j = j + 2;
		}
		_rows.at(i).push_back(1);
	}
	
}

void Pyramiad::print()
{
	for (int k = 0; k < ROWS; k++)
	{
		for (std::vector<int>::const_iterator i = _rows.at(k).begin(); i != _rows.at(k).end(); ++i)
			std::cout << *i;
		cout << endl;
	}
}