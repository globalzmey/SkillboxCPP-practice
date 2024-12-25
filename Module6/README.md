 6.5 Практическая работа

В практической работе есть:

Обязательные задачи помогут проверить, как вы усвоили материал модуля. Их нужно сдать на проверку куратору.

Дополнительные задачи подойдут тем, кто хочет ещё немного потренироваться, решая задачки по программированию. Вы также можете отправлять их на проверку и получать обратную связь куратора, хотя это необязательно.


Цели практической работы

    Научиться использовать циклы while, do while и оператор break.
    Научиться основам работы с циклами.


Что входит в практическую работу

Обязательные задачи:

    Кукушка.
    Слишком большие числа.
    Коллекторы.
    Счастливый билетик.
    Числа Фибоначчи.
    Вклады.

Дополнительные задачи:

    Сокращение дроби.
    Угадай число*.


Задание 1. Кукушка
Что нужно сделать

Напишите программу, которая имитировала бы часы с кукушкой. В начале работы она спрашивает, который час, а затем нужное количество раз пишет «Ку-ку!». При выполнении задания необходимо обеспечить контроль ввода (например, количество часов не может быть отрицательным).

Пример выполнения

            Введите, который час: 2 
            Ку-ку! 
            Ку-ку!
Рекомендации по выполнению

Обратите внимание, если вы захотите использовать 24-часовой формат, в котором часы имеют значения 0–23, то кукушка не сможет вас оповестить о полночи (нулевой час).
Что оценивается

    Есть проверка входных значений.
    Количество выведенных на консоль фраз равно количеству часов.


Задание 2. Слишком большие числа
Что нужно сделать

У неудачливого бухгалтера всё опять идёт наперекосяк: ему приносят такие большие счета, что числа не помещаются на бумаге. Напишите программу, которая считала бы для него, сколько цифр (знаков) во вводимом числе.

Пример выполнения

            Введите число: 10 
            Цифр в числе: 2
Рекомендации по выполнению

    Тип int вмещает в себя не больше десяти цифр (предположим, что у бухгалтера очень маленькие листы бумаги).
    Проверьте, как программа будет себя вести на отрицательных числах и нуле.

Что оценивается

    В числе ноль программа определяет одну цифру.
    Количество цифр определяется правильно.


Задание 3. Коллекторы
Что нужно сделать

Напишите робота для коллекторов. В самом начале он спрашивает имя должника и сумму долга, а затем начинает требовать у него погашения долга до тех пор, пока тот не будет погашен полностью. Сумма долга должна уменьшаться, если пользователь ввёл сумму, меньшую чем сумма долга. Если пользователь внёс большую сумму, чем требуется для погашения, выведите сообщение о том, какой у него остаток на счету после такой операции. Обеспечьте контроль ввода.
Рекомендации по выполнению

При полной выплате долга необходимо учитывать остаток на счету, если он имеется.
Что оценивается

    Правильно считается остаток после полного погашения долга.
    Программа прекращает выполнение после того, как долг полностью погашен.
    При задании отрицательного долга программа выводит предупреждение и прекращает выполнение.


Задание 4. Счастливый билетик
Что нужно сделать

В старину, когда даже в столице билеты в общественном транспорте выдавали контролёры, существовало поверье: если на билете сумма первых трёх цифр в номере билета равна сумме трёх последних, то это к удаче. Напишите программу, которая получала бы на вход шестизначный номер билета и выводила, счастливый это билет или нет. К примеру, билеты 666 666 и 252 135 — счастливые, а 123 456 — нет.

Пример выполнения

            Введите номер билета: 123060 
            Билет счастливый! 
            Введите номер билета: 123040 
            Повезёт в следующий раз!
Рекомендации по выполнению

    Программу необходимо сделать так, чтобы можно было увеличить количество цифр в билете без особых изменений в коде.
    Для получения младшего разряда числа (самой правой цифры) используйте выражение: one_digit = digits % 10.
    Используйте циклы для подсчёта суммы цифр в номере билета.

Что оценивается

    Программа корректно определяет, является ли билет счастливым.
    Для подсчёта суммы цифр в билете используются циклы.


Задание 5. Числа Фибоначчи
Что нужно сделать

Числами Фибоначчи называется следующая последовательность чисел: 1, 1, 2, 3, 5, 8, 13 и так далее (первое число равно 1, второе число равно 1, а каждое следующее равно сумме двух предыдущих). Напишите программу, которая по данному номеру N выводит N-е число этой последовательности (если оно не превосходит 2 147 483 647, конечно же). Обеспечьте контроль ввода.

Пример выполнения

            Введите номер последовательности: 1 
            Число в последовательности: 1 
            Введите номер последовательности: 6 
            Число в последовательности: 8
Рекомендации по выполнению

    Заметьте, что последовательность Фибоначчи всегда одинаковая. Пользователь вводит только порядковый номер числа из последовательности.
    Обратите внимание, что условие типа if(value > 2147483647) не имеет смысла.

Что оценивается

    Результатом запроса является число из последовательности Фибоначчи.
    Число 1 определяется как первое и второе число последовательности.


Задание 6. Вклады
Что нужно сделать

Вклад в банке составляет X рублей. Ежегодно он увеличивается на P процентов, после чего дробная часть копеек отбрасывается. Определите, через сколько лет вклад составит не менее Y рублей. Напишите программу, которая по данным числам X, Y, P определяет, сколько лет пройдёт, прежде чем сумма достигнет значения Y.

Пример выполнения

            Введите размер вклада: 100 
            Введите процентную ставку: 10 
            Введите желаемую сумму: 200 
            Придётся подождать: 8 лет

Пример вычисления:

1 год: 100 + 10% * 100 = 110

2 год: 110 + 10% * 110 = 121

3 год: 121 + 10% * 121 = 133 
Рекомендации по выполнению

    Расчёты проводятся в целых числах.
    У вклада есть капитализация процентов (проценты начисляются на весь остаток на счёте).

Что оценивается

Программа аварийно не завершается и не зависает при подсчёте вклада.


Задание 7. Сокращение дроби* (дополнительное задание)
Что нужно сделать

Пользователь вводит числа M и N. Напишите программу, которая преобразует дробь M/N к несократимому виду и выдаёт получившийся результат. Обеспечьте контроль ввода.

Пример выполнения

            Введите числитель: 4 
            Введите знаменатель: 6 
            Результат: 2 / 3 
            Введите числитель: 25 
            Введите знаменатель: 40
            Результат: 5 / 8 
            Введите числитель: −6 
            Введите знаменатель: 12 
            Результат: −1 / 2 
(При вводе отрицательных чисел в выводе должен быть только один ведущий минус. Неправильный вывод программы: 1/−2, −1/−2.) 
            Введите числитель: 896 
            Введите знаменатель: 3584 
            Результат: 1 / 4
Рекомендации по выполнению

Не забывайте о правилах деления чисел. Программа должна работать корректно и не должна «падать».
Что оценивается

    Алгоритм оптимальный, не бесконечный и не очень большой. Программа не зависает.
    Правильно определены критерии начала и конца цикла.


Задание 8. Угадай число* (дополнительное задание)
Что нужно сделать

Напишите программу, которая угадывает число, задуманное пользователем. Число загадывается в диапазоне от 0 до 63. Программа задаёт вопросы вида «Ваше число больше такого-то?» и на основе ответов пользователя («да» или «нет») угадывает число.
Рекомендации по выполнению

    В этом задании можно использовать любой алгоритм поиска, но полный перебор всех 64 значений — самый нежелательный из алгоритмов.
    Есть алгоритм, который гарантированно даст ответ за семь вопросов.

Что оценивается

    Нет полного перебора всех чисел.
    Программа работает только в указанном отрезке и не выходит за его пределы. При этом есть возможность поменять отрезок поиска без сильных изменений в коде программы.
    Допустимые ответы на вопросы — только «да» или «нет».


Критерии оценки работы

    Программы запускаются и корректно работают, нет синтаксических ошибок.
    Имена переменных корректные, отражают суть хранимых данных.
    Создан текстовый интерфейс для всех программ.
    Для всех заданий обеспечен контроль ввода, который обусловлен логикой работы программы. Где-то недопустимы отрицательные числа, а где-то нуль. Если число некорректное, то выводится сообщение об ошибке. Допускается отсутствие контроля на переполнение int.
    Выполнено пять и более заданий.