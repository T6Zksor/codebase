#include "Observer.h"
#include "StrategyPattern.h"
#include <stdlib.h>

int main()
{
    DesignPattern::StrategyPattern::Instance _strategy_pattern;
    _strategy_pattern.Execute();

	DesignPattern::Observer::Instance _observer_pattern;
	_observer_pattern.Execute();

	system("pause");
    return 0;
}
