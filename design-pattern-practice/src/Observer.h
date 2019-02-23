#pragma once

#include <vector>
#include <string>

namespace DesignPattern {
	namespace Observer {

		struct ObserverData {
		public:
			ObserverData() = default;
			double _temperature;
			double _humidity;
			double _pressure;
		};

		class Observer {
		public:
			Observer() = delete;
			Observer(std::string name);
		public:
			void Update(const ObserverData&);
		private:
			std::string getObserverName();
		private:
			ObserverData _data;
			std::string _name;
		};
		class Subject {
		public:
			Subject() = default;
		public:
			void ResigterObserver(Observer *elem);
			void RemoveObserver(Observer *elem);
			void NotifyObservers();
			void SetNewObserverData(const ObserverData&);
			const ObserverData& GetObserverData() const;
		private:
			std::vector<Observer*> _observers;
			ObserverData _data;
		};

		class Instance {
		public:
			void Execute();
		};
	}
}