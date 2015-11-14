#ifndef __APP_CALC_SRC_CALCINTERFACE_H__
#define __APP_CALC_SRC_CALCINTERFACE_H__

class ICalc 
{
public:
	virtual ~ICalc(){}

	virtual int offset(const char *inNumber, const char *inOffset, char *outRes, int outResSize) = 0;
	virtual int add(const char *inNumLeft, const char *inNumRight, char *outRes, int outResSize) = 0;
	virtual int minus(const char *inNumLeft, const char *inNumRight, char *outRes, int outResSize) = 0;
	virtual int multiply(const char *inNumLeft, const char *inNumRight, char *outRes, int outResSize) = 0;
	virtual int divide(const char *inNumLeft, const char *inNumRight, char *outRes, int outResSize) = 0;
	virtual int mod(const char *inNumLeft, const char *inNumRight, char *outRes, int outResSize) = 0;
};

#endif
