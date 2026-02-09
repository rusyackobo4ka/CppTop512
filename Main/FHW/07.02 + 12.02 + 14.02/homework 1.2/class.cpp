#include "class.h"



complexNumber& complexNumber::operator++()
{
	++_realNum;
	return *(this);
}

complexNumber& complexNumber::operator--()
{
	--_realNum;
	return *(this);
}

bool complexNumber::operator== (complexNumber& number) const
{
	return _realNum == number._realNum and _imageNum == number._imageNum;
}
bool complexNumber::operator!= (complexNumber& number) const
{
	return _realNum != number._realNum or _imageNum != number._imageNum;
}
bool complexNumber::operator> (complexNumber& number) const
{
	return sqrt(_realNum * _realNum + _imageNum * _imageNum) > sqrt(number._realNum * number._realNum + number._imageNum * number._imageNum);
}
bool complexNumber::operator>= (complexNumber& number) const
{
	return sqrt(_realNum * _realNum + _imageNum * _imageNum) >= sqrt(number._realNum * number._realNum + number._imageNum * number._imageNum) or _realNum == number._realNum and _imageNum == number._imageNum;
}
bool complexNumber::operator< (complexNumber& number) const
{
	return sqrt(_realNum * _realNum + _imageNum * _imageNum) < sqrt(number._realNum * number._realNum + number._imageNum * number._imageNum);
}
bool complexNumber::operator<= (complexNumber& number) const
{
	return sqrt(_realNum * _realNum + _imageNum * _imageNum) <= sqrt(number._realNum * number._realNum + number._imageNum * number._imageNum) or _realNum == number._realNum and _imageNum == number._imageNum;
}


complexNumber complexNumber::operator* (complexNumber& number) const
{
	complexNumber result;

	result._realNum = (_realNum * number._realNum) - (_imageNum * number._imageNum);
	result._imageNum = (_realNum * number._imageNum) + (_imageNum * number._realNum);

	return result;
}
complexNumber complexNumber::operator* (double& number) const
{
	complexNumber result;

	result._realNum = _realNum * number;
	result._imageNum = _imageNum * number;

	return result;
}
complexNumber complexNumber::operator* (drob& number) const
{
	complexNumber result;

	result._realNum = _realNum * number.getDrobUp() / number.getDrobDown();
	result._imageNum = _imageNum * number.getDrobUp() / number.getDrobDown();

	return result;
}


complexNumber complexNumber::operator+ (complexNumber& number) const
{
	complexNumber result;

	result._realNum = _realNum + number._realNum;
	result._imageNum = _imageNum + number._imageNum;

	return result;
}
complexNumber complexNumber::operator+ (double& number) const
{
	complexNumber result;

	result._realNum = _realNum + number;

	return result;
}
complexNumber complexNumber::operator+ (drob& number) const
{
	complexNumber result;

	result._realNum = (_realNum * number.getDrobDown() + number.getDrobUp() ) / number.getDrobDown();
	result._imageNum = (_realNum * number.getDrobDown() + number.getDrobUp()) / number.getDrobDown();

	return result;
}



complexNumber complexNumber::operator- (complexNumber& number) const
{
		complexNumber result;

		result._realNum = _realNum - number._realNum;
		result._imageNum = _imageNum - number._imageNum;

		return result;
}
complexNumber complexNumber::operator- (double& number) const
{
	complexNumber result;

	result._realNum = _realNum - number;

	return result;
}
complexNumber complexNumber::operator- (drob& number) const
{
	complexNumber result;

	result._realNum = (_realNum * number.getDrobDown() - number.getDrobUp()) / number.getDrobDown();
	result._imageNum = (_realNum * number.getDrobDown() - number.getDrobUp()) / number.getDrobDown();

	return result;
}   

complexNumber complexNumber::operator/ (complexNumber& number) const
{
		number._imageNum *= (-1);

		complexNumber tmp = *this * number;
		complexNumber result;

		double delite = number._realNum * number._realNum + number._imageNum * number._imageNum;

		result._realNum = tmp._realNum / delite;
		result._imageNum = tmp._imageNum / delite;

		return result;
}
complexNumber complexNumber::operator/ (double& number) const
{
	complexNumber result;

	result._realNum = _realNum / number;
	result._imageNum = _imageNum / number;

	return result;
}
complexNumber complexNumber::operator/ (drob& number) const
{
	complexNumber result;

	result._realNum = _realNum * number.getDrobDown() / number.getDrobUp();
	result._imageNum = _imageNum * number.getDrobDown() / number.getDrobUp();

	return result;
}