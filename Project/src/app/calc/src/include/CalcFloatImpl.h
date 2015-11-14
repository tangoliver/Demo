#ifndef __APP_CALC_SRC_CALCFLOATIMPL_H__
#define __APP_CALC_SRC_CALCFLOATIMPL_H__

#include "CalcBaseImpl.h"

class CCalcFloatImpl : public CCalcBaseImpl
{
public:
	CCalcFloatImpl();
	virtual ~CCalcFloatImpl();

	virtual int offset(const char *inNumber, const char *inOffset, char *outRes, int outResSize);
	virtual int add(const char *inNumLeft, const char *inNumRight, char *outRes, int outResSize);
	virtual int minus(const char *inNumLeft, const char *inNumRight, char *outRes, int outResSize);
	virtual int multiply(const char *inNumLeft, const char *inNumRight, char *outRes, int outResSize);
	virtual int divide(const char *inNumLeft, const char *inNumRight, char *outRes, int outResSize);
	virtual int mod(const char *inNumLeft, const char *inNumRight, char *outRes, int outResSize);
};

#endif

