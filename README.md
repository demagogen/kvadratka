# Kvadratka
## Скачивание программы
Для скачивания программы нужно ввести в консоль. Необходимо скачать [git](https://git-scm.com/).
```bash
git clone https://github.com/demagogen/kvadratka.git
cd kvadratka
```
## Сборка программы
Для сборки программы нужно ввести в консоль
```bash
make
```
## Запуск программы
Для запуска программы нужно ввести в консоль
```bash
./kvadratka/build/kvadratka
```
## Выбор режима программы
После запуска программы на экране появится текст в вариантами выбора. После его появления нужно ввести цифру.
```bash
Выберите действие
        Решение квадратного уравнения (введите 1)
        Запустить тест программы      (введите 2)
1
```
Чтобы запустить режим решения квадратного уравнения, нужно ввести 1. Чтобы запустить режим тестирования, нужно ввести 2.
При любом другом значении, программа выведет ошибку.
```bash
Ошибочный ввод
```
### Режим решения квадратного уравнения
Программа запросит ввести через пробел три коэффициента квадратного уравнения,
```bash
Введите значения трех коэффициентов через пробел
1 2 1
```

 после чего она выводит ответ.
```bash
Одно решение: -1.000000
```
### Режим тестирования программы
Запускаются тесты для программы, после чего выводятся результаты прохождения.
```bash
Старт теста 1
тест 1 пройден
Старт теста 2
тест 2 пройден
Старт теста 3
тест 3 пройден
Старт теста 4
тест 4 пройден
Старт теста 5
тест 5 пройден
Старт теста 6
тест 6 пройден
Старт теста 7
тест 7 пройден
Старт теста 8
Ошибка в тесте 8
a = 0.100000, b = 0.100000, c = 0.600000, num_of_sol = TWO_SOLUTIONS, x1 = 2.000000, x2 = -3.000000
num_of_sol = NO_SOLUTIONS, x1 = nan, x2 = nan
Старт теста 9
тест 9 пройден
```
#### Ввод своих тестовых значений
Чтобы ввести свои тестовые значения, нужно открыть файл `tests.cpp` и внести изменения в уже имеющиеся тесты, или добавить новые в структуру `test_data`
```bash
static const TEST_DATA test_data_array[] {
    {
        .number_of_test = 1,
        .a = 0,
        .b = 0,
        .c = 0,
        .x1_ex = NAN,
        .x2_ex = NAN,
        .num_of_sol_ex = INF_NUMBER_OF_SOLUTIONS,
    },
```
## Документация
Чтобы посмотреть документацию, нужно ввести в консоль команды
```bash
make docs
xdg-open ./html/index.html
```
## Удаление программы
Чтобы удалить программу, нужно ввести в консоль команды
```bash
cd ../
rm -rf kvadratka
```
