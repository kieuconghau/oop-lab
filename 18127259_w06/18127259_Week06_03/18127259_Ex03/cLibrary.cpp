#include "cLibrary.h"

cLibrary::cLibrary() {}

cLibrary::~cLibrary()
{
	int n = this->Readers.size();

	for (int i = 0; i < n; i++)
		delete this->Readers[i];
}

void cLibrary::input()
{
	string opt;
	while (true)
	{
		cout << "Choose: 1. Normal Reader, 2. VIP Reader, 0. <Exit> ";
		getline(cin, opt);

		if (opt != "1" && opt != "2")
			break;

		cReader* reader;
		if (opt == "1")
		{
			reader = new cNormalReader;
		}
		else if (opt == "2")
		{
			reader = new cVipReader;
		}
		else
			throw;

		reader->input_info();

		this->Readers.push_back(reader);
	}
}

void cLibrary::show()
{
	int n = this->Readers.size();

	for (int i = 0; i < n; i++)
	{
		cout << "#" << i + 1 << endl;
		this->Readers[i]->show_info();
		cout << endl;
	}
}

float cLibrary::calc_sum_fees()
{
	int n = this->Readers.size();

	float sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += this->Readers[i]->calc_fees();
	}

	return sum;
}

vector<cReader*> cLibrary::find_readers_having_the_highest_fees()
{
	int n = this->Readers.size();

	float max = this->Readers[0]->calc_fees();
	float cur;
	for (int i = 1; i < n; i++)
	{
		cur = this->Readers[i]->calc_fees();
		if (cur > max)
			max = cur;
	}

	vector<cReader*> res;
	for (int i = 0; i < n; i++)
	{
		if (fabs(this->Readers[i]->calc_fees() - max) <= 0.00001)
			res.push_back(this->Readers[i]);
	}

	return res;
}

int cLibrary::count_normal_readers()
{
	int n = this->Readers.size();

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (this->Readers[i]->has_type(cReader::ecType::NORMAL))
			++count;
	}

	return count;
}

int cLibrary::count_vip_readers()
{
	int n = this->Readers.size();

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (this->Readers[i]->has_type(cReader::ecType::VIP))
			++count;
	}

	return count;
}

float cLibrary::calc_average_salary()
{
	return this->calc_sum_fees() / this->Readers.size();
}

vector<cReader*> cLibrary::find_readers_having_fees_more_than(float fees)
{
	int n = this->Readers.size();

	vector<cReader*> res;
	for (int i = 0; i < n; i++)
	{
		if (this->Readers[i]->calc_fees() > fees)
			res.push_back(this->Readers[i]);
	}

	return res;
}

cReader* cLibrary::find_a_reader_with_id()
{
	string id;
	cout << "Input ID:";
	getline(cin, id);

	int n = this->Readers.size();

	for (int i = 0; i < n; i++)
	{
		if (this->Readers[i]->has_id(id))
			return this->Readers[i];
	}

	return nullptr;
}

vector<cReader*> cLibrary::find_readers_with_full_name()
{
	string fullName;
	cout << "Input full name: ";
	getline(cin, fullName);

	int n = this->Readers.size();

	vector<cReader*> res;
	for (int i = 0; i < n; i++)
	{
		if (this->Readers[i]->has_full_name(fullName))
			res.push_back(this->Readers[i]);
	}

	return res;
}

int cLibrary::count_readers_having_expiration_date_in_year(int year)
{
	int n = this->Readers.size();

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (this->Readers[i]->has_expiration_date_in_year(year))
			++count;
	}

	return count;
}
