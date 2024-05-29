## Создание класса для работы с функциями

Был разработано консольное приложение, в котором можно задать функции и посмотреть их свойства.
Следущие функции были реализованы:
- Гипербола
- Парабола 
- Экспоненциальная функция 
- Многочлен

Все функции наследуются, от абстрактного класса function, в каждом классе реализованы:
- Вывод функции 
- Поиск значения функции в конкретной точке
- Поиск максимума/минимума на заданном интервале
- Интегрирование 
- Дифференцирование

## Экспонента 
f(x) = a^x
- В конструктор передаем значение a 
- Реализован вывод функции - displayResult()
- Поиск значения в точке - evaluate()
- При поиске минимума и максимума на заданном интервале, выводим, что у экспоненты нет минимуа или максимума
- Интегрирование по формуле: (a^x) / ln(a) + C
- Дифференцирование по формуле: ln(a) * a^x

## Гипербола
f(x) = a / (x - h) + k
- В конструктор передаем значение a, h, k
- Реализован вывод функции - displayResult()
- Поиск значения в точке - evaluate()
- При поиске минимума и максимума на заданном интервале, выводим, что у гиперболы нет минимуа или максимума
- Интегрирование по формуле: a * ln |x - h| + kx + C
- Дифференцирование по формуле: - a / (x - h + k)^2

## Парабола
f(x) = a(x-h)^2 + k, парабола задается в таком виде т.к. легче исследовать функцию именно такого вида
- В конструктор передаем значение a, h, k
- Реализован вывод функции - displayResult()
- Поиск значения в точке - evaluate()
- При поиске минимума и максимума на заданном интервале, проверяем границы интервала и точки вершины параболы
- Интегрирование по формуле: 2 * (x^3/3 - hx^2 +h^2x) + kx
- Дифференцирование по формуле: 2ax - 2ah

## Многочлен
f(x) = a^x
- В конструктор передаем вектор коэффицентов, первый коэффицент - коэфффицент при самой старшей степени
- Реализован вывод функции - displayResult(), который выводит многочлен в нужном виде, через преобразования строк
- Поиск значения в точке - evaluate()
- При поиске минимума и максимума на заданном интервале проверяем все точки на интервале и выводим максимум/минимум
- Интегрирование по [правилу трапеций](https://ru.wikipedia.org/wiki/%D0%9C%D0%B5%D1%82%D0%BE%D0%B4_%D1%82%D1%80%D0%B0%D0%BF%D0%B5%D1%86%D0%B8%D0%B9)
- Дифференцирование происходит в цикле по формуле производной f(x) = ax^b f'(x)=a*bx^(b-1) 

## Тестирование кода 
В файле main.cpp задаются функции
f(x) = 2^x
f(x) = 2/(x-1)-1
f(x) = 2(x-1)^2 + 3
f(x) = x^2 + 2x + 3
Поиск минимума и максимума, определенного интеграла происходит на интервале от [1, 5]
Написана функция, реализующая поиск производнйо сложной производной в заданной точке х - complex_function(), в которую передаются
два объекта абстрактного класса 'function', первая функция - внешняя функция, вторая функция - внтуреняя и значение x, функция типа void 
выводит в консоль значение дифференциала сзаданной сложной функции.
