#include "snprintf.h"

int value_len_def(long long int value, const int system)
{
    int value_len = 0;

    if (!value)
    {
        return 1;
    }

    if (value < 0)
    {
        while (value < 0)
        {
            value /= system;
            value_len++;
        }
    }
    else
    {
        while (value)
        {
            value /= system;
            value_len++;
        }
    }

    return value_len;
}

long int power(const int value, const int power)
{
    long long int ten_to_power = 1;

    for (int i = 0; i < power; i++)
    {
        ten_to_power *= value;
    }

    return ten_to_power;
}

void string_i12n(char *const string, const int size)
{
    for (int i = 0; i < size; i++)
    {
        string[i] = '\0';
    }
}

void put_value_int(long long int value, char *buffer, int *index_buffer, const int size)
{
    int value_len = value_len_def(value, 10);
    int neg_flag = 1;

    if (value < 0)
    {
        buffer[(*index_buffer)] = '-';
        (*index_buffer)++;
        neg_flag = -1;
    }

    for (int i = value_len - 1; i >= 0; i--)
    {
        if ((*index_buffer) < size)
        {
            buffer[(*index_buffer)] = value / power(10, i) * neg_flag + CODE_SYMB_DELTA; 
            value %= power(10, i);
        }

        (*index_buffer)++;
    }
}

void put_value_x_int(unsigned long long int value, char *buffer, int *index_buffer, const int size)
{
    char system_numbers[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' }; 
    int index_copy = 0;
    char *buffer_copy = (char *) calloc(MAX_SYMB_NUM, sizeof(char));

    if (!value)
    {
        buffer[(*index_buffer)] = system_numbers[0];
        (*index_buffer)++;
    }

    while (value)
    {
        buffer_copy[index_copy] = system_numbers[value % 16];
        value /= 16;
        index_copy++;
    }

    for (int i = index_copy - 1; i >= 0; i--)
    {
        if ((*index_buffer) < size)
        {
            buffer[(*index_buffer)] = buffer_copy[i];
        }

        (*index_buffer)++;
    }

    free(buffer_copy);
}

void put_value_o_int(unsigned long long int value, char *buffer, int *index_buffer, const int size)
{
    char system_numbers[] = { '0', '1', '2', '3', '4', '5', '6', '7' };
    int index_copy = 0;
    char *buffer_copy = (char *) calloc(MAX_SYMB_NUM, sizeof(char));

    if (!value)
    {
        buffer[(*index_buffer)] = system_numbers[0];
        (*index_buffer)++;
    }

    while (value)
    {
        buffer_copy[index_copy] = system_numbers[value % 8];
        value /= 8;
        index_copy++;
    }

    for (int i = index_copy - 1; i >= 0; i--)
    {
        if ((*index_buffer) < size)
        {
            buffer[(*index_buffer)] = buffer_copy[i];
        }

        (*index_buffer)++;
    }

    free(buffer_copy);
}

void identify_ll_specifier(va_list *const argptr, char *const format, int *index_format, char *buffer, int *index_buffer, const int size)
{
    long long int value_long_long_int = 0;
    unsigned long long int value_long_long_uint = 0;

    if (format[(*index_format)] == 'd')
    {
        value_long_long_int = va_arg(*argptr, long int);
        put_value_int(value_long_long_int, buffer, index_buffer, size);
        (*index_format)++; 
    }
    else if (format[(*index_format)] == 'x')
    {
        value_long_long_uint = va_arg(*argptr, unsigned long int);
        put_value_x_int(value_long_long_uint, buffer, index_buffer, size);
        (*index_format)++; 
    }
    else if (format[(*index_format)] == 'o')
    {
        value_long_long_uint = va_arg(*argptr, unsigned long int);
        put_value_o_int(value_long_long_uint, buffer, index_buffer, size);
        (*index_format)++; 
    }
}

void identify_l_specifier(va_list *const argptr, char *const format, int *index_format, char *buffer, int *index_buffer, const int size)
{
    long int value_long_int = 0;
    unsigned long int value_long_uint = 0;
    
    if (format[(*index_format)] == 'l')
    {
        (*index_format)++; 
        identify_ll_specifier(argptr, format, index_format, buffer, index_buffer, size);
    }
    else if (format[(*index_format)] == 'd')
    {
        value_long_int = va_arg(*argptr, long int);
        put_value_int(value_long_int, buffer, index_buffer, size);
        (*index_format)++; 
    }
    else if (format[(*index_format)] == 'x')
    {
        value_long_uint = va_arg(*argptr, unsigned long int);
        put_value_x_int(value_long_uint, buffer, index_buffer, size);
        (*index_format)++; 
    }
    else if (format[(*index_format)] == 'o')
    {
        value_long_uint = va_arg(*argptr, unsigned long int);
        put_value_o_int(value_long_uint, buffer, index_buffer, size);
        (*index_format)++; 
    }
}

void identify_specifier(va_list *const argptr, char *const format, int *index_format, char *buffer, int *index_buffer, const int size)
{
    int value_int = 0;
    unsigned int value_uint = 0;

    if (format[(*index_format)] == 'l')
    {
        (*index_format)++; 
        identify_l_specifier(argptr, format, index_format, buffer, index_buffer, size);
    }
    else if (format[(*index_format)] == 'd')
    {
        value_int = va_arg(*argptr, int);
        put_value_int(value_int, buffer, index_buffer, size);
        (*index_format)++; 
    }
    else if (format[(*index_format)] == 'x')
    {
        value_uint = va_arg(*argptr, unsigned int);
        put_value_x_int(value_uint, buffer, index_buffer, size);
        (*index_format)++; 
    }
    else if (format[(*index_format)] == 'o')
    {
        value_uint = va_arg(*argptr, unsigned int);
        put_value_o_int(value_uint, buffer, index_buffer, size);
        (*index_format)++; 
    }
} 

void get_specifier(char *const format, int *index_format, char *buffer, int *index_buffer, const int size)
{
    while (format[(*index_format)] != '%' && format[(*index_format)] != '\0')
    {
        if ((*index_buffer) < size)
        {
            buffer[(*index_buffer)] = format[(*index_format)]; 
        }
        
        (*index_buffer)++;
        (*index_format)++;
    }

    if (format[(*index_format)] == '%')   
    {
        (*index_format)++; 
    }
}

int my_snprintf(char *buffer, int size, char *format, ...)
{
    int index_format = 0;
    int index_buffer = 0;
    va_list argptr;

    va_start(argptr, format);

    string_i12n(buffer, size);

    while (format[index_format])
    {
        get_specifier(format, &index_format, buffer, &index_buffer, size);
        identify_specifier(&argptr, format, &index_format, buffer, &index_buffer, size);
    }

    if (size > 0)
    {
        buffer[size - 1] = '\0';
    }
    va_end(argptr);
    return index_buffer;
}
