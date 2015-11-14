
#include "CalcFloatImpl.h"

CCalcFloatImpl::CCalcFloatImpl()
{
}

CCalcFloatImpl::~CCalcFloatImpl()
{
}

int CCalcFloatImpl::offset(const char *inNumber, const char *inOffset, char *outRes, int outResSize)
{
	// unsupport offset in float
	return echoInValidOperate();
}

int CCalcFloatImpl::add(const char *inNumLeft, const char *inNumRight, char *outRes, int outResSize)
{
	// unrealized
	return -1;
}

int CCalcFloatImpl::minus(const char *inNumLeft, const char *inNumRight, char *outRes, int outResSize)
{
	// unrealized
	return -1;
}

int CCalcFloatImpl::multiply(const char *inNumLeft, const char *inNumRight, char *outRes, int outResSize)
{
	// unrealized
	return -1;
}


int CCalcFloatImpl::divide(const char *inNumLeft, const char *inNumRight, char *outRes, int outResSize)
{
	// unrealized
	return -1;
}

int CCalcFloatImpl::mod(const char *inNumLeft, const char *inNumRight, char *outRes, int outResSize)
{
	// unsupport mod in float
	return echoInValidOperate();
}

