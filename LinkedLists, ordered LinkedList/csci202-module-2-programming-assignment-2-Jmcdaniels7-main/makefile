all:
    g++ -pedantic-errors -std=c++2a  -g main.cpp clock clockexcept person snack -o main
clock: clock.cpp clock.h
    g++ -pedantic-errors -std=c++2a  -g -c clock.cpp -o clock
clockexcept: clockexcept.h clockexcept.cpp
    g++ -pedantic-errors -std=c++2a  -g -c clockexcept.cpp -o clockexcept
person: person.h person.cpp
    g++ -pedantic-errors -std=c++2a  -g -c person.cpp -o person
snack: snack.h snack.cpp
    g++ -pedantic-errors -std=c++2a  -g -c snack.cpp -o snack