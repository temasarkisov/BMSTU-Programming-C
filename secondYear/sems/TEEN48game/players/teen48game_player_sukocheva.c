#include "../p_headers/teen48game_player_sukocheva.h" // данный хедер подключается для подключения
// вашей функции в главный модуль (в этом заголовочном файле вы описываете )
// #include <matrixgame.h> // данная библиотека подключается в header'e, описанном выше
// для работы с matrix_t (там также представлены
// функции работы с матрицами, которые могут быть полезны для работы с полем)
#include <stdlib.h> // данная библиотека подключена для работы рандома

#define ERROR 0

/* здесь можно создать свои статические переменные
которые будут помогать писать код, запоминать какие-то признаки 
матрицы до изменения и после, и тп. (ни и все мы помним, что доступ к этим переменным будет
только у нас)

Пример: static int side_array[4] = {}; // массив, который будет собирать
баллы, которые будут оценивать, в какую сторону из 4 выгоднее двигаться и тп.
*/

char teen48game_player_sukocheva(matrix_t *const matrix_buffer, int (*to_step)(matrix_t *const, const char))
{
    // здесь мы имеем некоторую работу над буферной матрицей (или не имеем),
    // и записываем некоторые признаки. Пример:
    // to_step(buffer, 'r') - изменит матрицу buffer как при ходе вправо (функция возвращает код ошибки
    // 0 - все завершилось успешно)
    int choice = rand() % 4;
    switch (choice)
    {
    case 0:
        return 'r';
    case 1:
        return 'l';
    case 2:
        return 'd';
    case 3:
        return 'u';
    }
    // возвращаем одно из 4 направлений: 'r', 'l', 'd', 'u'
    return ERROR; // до сюда не дойдет
}
