
#include "CalcBaseImpl.h"

#include <stdio.h>

CCalcBaseImpl::CCalcBaseImpl()
{
}

CCalcBaseImpl::~CCalcBaseImpl()
{
}

int CCalcBaseImpl::echoNaN()
{
	printf("NaN\n");
	return 0;
}

int CCalcBaseImpl::echoInValidParams()
{
	printf("Invalid params\n");
	return 0;
}

int CCalcBaseImpl::echoInValidOperate()
{
	printf("Invalid opertate\n");
	return 0;
}



