#ifndef __APP_CALC_SRC_CALCBASEIMPL_H__
#define __APP_CALC_SRC_CALCBASEIMPL_H__

#include "CalcInterface.h"

class CCalcBaseImpl : public ICalc
{
public:
	CCalcBaseImpl();
	virtual ~CCalcBaseImpl();

protected:
	int echoNaN();
	int echoInValidParams();
	int echoInValidOperate();
};

#endif
