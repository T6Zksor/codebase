#pragma once

namespace DesignPattern {
    namespace StrategyPattern {

        class FlyBehavior {
        public:
            virtual void fly() = 0;
        };

        class FlyWithWings : public FlyBehavior {
        public:
            void fly() override;
        };

        class FlyNoWay : public FlyBehavior {
        public:
            void fly() override;
        };

        class QuackBehavior {
        public:
            virtual void quack() = 0;
        };

        class Quack : public QuackBehavior {
        public:
            void quack() override;
        };

        class Squeak : public QuackBehavior {
        public:
            void quack() override;
        };

        class MuteQuack : public QuackBehavior {
        public:
            void quack() override;
        };

        class Duck {
        public:
            virtual void PerformDisplay() = 0;
            void PerformFly() { _fly->fly(); }
            void PerformQuack() { _quack->quack(); }
        public:
            void Execute();
        protected:
            FlyBehavior *_fly;
            QuackBehavior *_quack;
        };

        class MallardDuck : public Duck {
        public:
            MallardDuck();
            void PerformDisplay() override;
        };

        class RubberDuck : public Duck {
        public:
            RubberDuck();
            void PerformDisplay() override;
        };

        class Instance {
        public:
            void Execute();
        };
    }
}