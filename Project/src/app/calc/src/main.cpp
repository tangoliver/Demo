
#include <stdio.h>
#include <string.h>

#include "CalcIntImpl.h"
#include "CalcFloatImpl.h"

enum operate_e
{
	OPERATE_INVALID = -1,
	OPERATE_OFFSET = 0,
	OPERATE_ADD,
	OPERATE_MINUS,
	OPERATE_MUTIPLY,
	OPERATE_DIVIDE,
	OPERATE_MOD,
};

static int echoHelp()
{
	printf("usage: calc num1 operator num2 [-f/-n]\n");
	printf("operator: support offset/add/minus/mutiply/divide/mod\n");
	printf("-f: calculate in float\n");
	printf("-n(default): calculate in integer\n");
	return 0;
}

static ICalc *createCalcInterface(const char *opt)
{
	if (NULL != opt && 0 == strcasecmp(opt, "-f"))
	{
		return new CCalcFloatImpl();
	}

	return new CCalcIntImpl();
}

static int destoryCalcInterface(ICalc *calcInterface)
{
	if (NULL != calcInterface)
	{
		delete calcInterface;
		calcInterface = NULL;
	}

	return 0;
}

static int getOperate(const char *operate)
{
	if (NULL == operate)
	{
		return OPERATE_INVALID;
	}

	if (0 == strcasecmp(operate, "offset"))
	{
		return OPERATE_OFFSET;
	} else if (0 == strcasecmp(operate, "add"))
	{
		return OPERATE_ADD;
	} else if (0 == strcasecmp(operate, "minus"))
	{
		return OPERATE_MINUS;
	} else if (0 == strcasecmp(operate, "mutiply"))
	{
		return OPERATE_MUTIPLY;
	} else if (0 == strcasecmp(operate, "divide"))
	{
		return OPERATE_DIVIDE;
	} else if (0 == strcasecmp(operate, "mod"))
	{
		return OPERATE_MOD;
	}

	return OPERATE_INVALID;
}

static int calculate(ICalc *calcInterface, 
		const char *num1, const char *operate, const char *num2)
{
	if (NULL == calcInterface 
			|| NULL == num1 
			|| NULL == num2 
			|| NULL == operate)
	{
		return -1;
	}

	switch (getOperate(operate))
	{
	case OPERATE_OFFSET:
		calcInterface->offset(num1, num2, NULL, 0);
		break;
		
	case OPERATE_ADD:
		calcInterface->add(num1, num2, NULL, 0);
		break;
		
	case OPERATE_MINUS:
		calcInterface->minus(num1, num2, NULL, 0);
		break;
		
	case OPERATE_MUTIPLY:
		calcInterface->multiply(num1, num2, NULL, 0);
		break;
		
	case OPERATE_DIVIDE:
		calcInterface->divide(num1, num2, NULL, 0);
		break;
		
	case OPERATE_MOD:
		calcInterface->mod(num1, num2, NULL, 0);
		break;
	
	case OPERATE_INVALID:
	default:
		return -1;
	}

	return 0;
}

int main(int argc, char *argv[])
{
	if (argc > 5 || argc < 4)
	{
		return echoHelp(); 
	}

	int index = 0;
	const char *num1 = argv[++index];
	const char *operate = argv[++index];
	const char *num2 = argv[++index];
	const char *opt = (argc == 5) ? argv[++index] : NULL;
	
	ICalc *calcInterface = createCalcInterface(opt);
	if (0 != calculate(calcInterface, num1, operate, num2))
	{
		goto exit_safely;
	}

	destoryCalcInterface(calcInterface);
	return 0;

exit_safely:
	destoryCalcInterface(calcInterface);
	return echoHelp();

}

