#include "Observer.h"
#include <algorithm>
#include <iostream>

using namespace DesignPattern::Observer;

Observer::Observer(std::string name)
	:_name(name)
{}

void Observer::Update(const ObserverData& data)
{
	_data = data;
	std::cout << getObserverName() + " received update!" <<std::endl;
	std::cout << "Temperature is " << _data._temperature << std::endl;
	std::cout << "Humidity is " << _data._humidity << std::endl;
	std::cout << "Pressure is " << _data._pressure << std::endl;

}

std::string Observer::getObserverName() {
	return _name;
}

void Subject::ResigterObserver(Observer *elem) {
	_observers.push_back(elem);
}

void Subject::RemoveObserver(Observer *elem) {
	_observers.erase(
		std::remove(_observers.begin(), _observers.end(), elem),
		_observers.end());
}

void Subject::NotifyObservers() {
	for (auto elem : _observers) {
		elem->Update(GetObserverData());
	}
}

void Subject::SetNewObserverData(const ObserverData& data) {
	_data = data;
	NotifyObservers();
}

const ObserverData& Subject::GetObserverData() const {
	return _data;
}

void Instance::Execute() {
	Observer tom("tom"), jerry("jerry"), smith("smith");
	Subject sub;
	sub.ResigterObserver(&tom);
	sub.ResigterObserver(&jerry);
	sub.ResigterObserver(&smith);

	ObserverData data;
	data._temperature = 100;
	data._humidity = 80;
	data._pressure = 1.1;

	sub.SetNewObserverData(data);

	sub.RemoveObserver(&tom);
	sub.NotifyObservers();
}