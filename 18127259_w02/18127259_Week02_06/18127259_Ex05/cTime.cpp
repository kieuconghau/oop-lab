#include "cTime.h"

bool cTime::isValid()
{
	if (this->Hour < 0 || this->Hour > 23)
		return false;

	if (this->Min < 0 || this->Min > 59)
		return false;

	if (this->Sec < 0 || this->Sec > 59)
		return false;

	return true;
}

void cTime::input()
{
	while (true)
	{
		cout << " * Input Hour: ";
		cin >> this->Hour;
		cout << " * Input Minute: ";
		cin >> this->Min;
		cout << " * Input Second: ";
		cin >> this->Sec;

		if (this->isValid())
			break;
		else
			cout << "\aInvalid input! Please input again!" << endl;
	}
}

void cTime::change(const int secs)
{
	int SecCount = (86400 * (abs(secs) / 86400 + 1) + this->Hour * 60 * 60 + this->Min * 60 + this->Sec + secs) % 86400;
	
	this->Hour = SecCount / (60 * 60);
	this->Min = (SecCount - this->Hour * 60 * 60) / 60;
	this->Sec = SecCount - this->Hour * 60 * 60 - this->Min * 60;
}

string cTime::getFormat() const
{
	return to_string(this->Hour) + ":" + to_string(this->Min) + ":" + to_string(this->Sec);
}