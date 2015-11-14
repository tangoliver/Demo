
#include "CalcIntImpl.h"

#include <stdio.h>
#include <stdlib.h>

#include "mytype.h"

CCalcIntImpl::CCalcIntImpl()
{
}

CCalcIntImpl::~CCalcIntImpl()
{
}

int CCalcIntImpl::offset(const char *inNumber, const char *inOffset, char *outRes, int outResSize)
{
	if (NULL == inNumber || NULL == inOffset)
	{
		return echoInValidParams();
	}

	int number = atoi(inNumber);
	int offset = atoi(inOffset);
	int result = 0;
	if (0 < offset)
	{
		result = number << offset;
	} else if (0 > offset)
	{
		result = number >> (-offset);
	} else 
	{
		result = number;
	}

	if (NULL != outRes && 0 < outResSize)
	{
		snprintf(outRes, outResSize, "%d", result);
	}
	printf("%d\n", result);
	return 0;
}

int CCalcIntImpl::add(const char *inNumLeft, const char *inNumRight, char *outRes, int outResSize)
{
	if (NULL == inNumLeft || NULL == inNumRight)
	{
		return echoInValidParams();
	}

	int numLeft = atoi(inNumLeft);
	int numRight = atoi(inNumRight);
	int result = numLeft + numRight;

	if (NULL != outRes && 0 < outResSize)
	{
		snprintf(outRes, outResSize, "%d", result);
	}
	printf("%d\n", result);
	return 0;
}

int CCalcIntImpl::minus(const char *inNumLeft, const char *inNumRight, char *outRes, int outResSize)
{
	if (NULL == inNumLeft || NULL == inNumRight)
	{
		return echoInValidParams();
	}

	int numLeft = atoi(inNumLeft);
	int numRight = atoi(inNumRight);
	int result = numLeft - numRight;

	if (NULL != outRes && 0 < outResSize)
	{
		snprintf(outRes, outResSize, "%d", result);
	}
	printf("%d\n", result);
	return 0;
}

int CCalcIntImpl::multiply(const char *inNumLeft, const char *inNumRight, char *outRes, int outResSize)
{
	if (NULL == inNumLeft || NULL == inNumRight)
	{
		return echoInValidParams();
	}

	int numLeft = atoi(inNumLeft);
	int numRight = atoi(inNumRight);
	int result = numLeft * numRight;

	if (NULL != outRes && 0 < outResSize)
	{
		snprintf(outRes, outResSize, "%d", result);
	}
	printf("%d\n", result);
	return 0;
}


int CCalcIntImpl::divide(const char *inNumLeft, const char *inNumRight, char *outRes, int outResSize)
{
	if (NULL == inNumLeft || NULL == inNumRight)
	{
		return echoInValidParams();
	}

	int numLeft = atoi(inNumLeft);
	int numRight = atoi(inNumRight);
	if (0 == numRight)
	{
		return echoNaN();
	}
	
	int result = numLeft / numRight;
	if (NULL != outRes && 0 < outResSize)
	{
		snprintf(outRes, outResSize, "%d", result);
	}
	printf("%d\n", result);
	return 0;
}

int CCalcIntImpl::mod(const char *inNumLeft, const char *inNumRight, char *outRes, int outResSize)
{
	if (NULL == inNumLeft || NULL == inNumRight)
	{
		return echoInValidParams();
	}

	int numLeft = atoi(inNumLeft);
	int numRight = atoi(inNumRight);
	if (0 == numRight)
	{
		return echoNaN();
	}
	
	int result = numLeft % numRight;
	if (NULL != outRes && 0 < outResSize)
	{
		snprintf(outRes, outResSize, "%d", result);
	}
	printf("%d\n", result);
	return 0;
}

