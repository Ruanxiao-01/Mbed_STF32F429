#include <mbed.h>

// Example 1
int main()
{
  // Declare and Initialize a variable
  int my_integer = 1;
  int my_negative_integer = -1;
  bool is_true = true;
  bool is_false = false;
  char my_char = 'a';
  float my_float = 0.1;
  float my_negative_float = -0.1;

  uint32_t register1 = 21;
  uint32_t register1_hex = 0x21213212;
  uint32_t register1_bin = 0b00000000'00000000'00000000'00000000;

  uint32_t *my_ptr = &register1;

  printf("%d", *my_ptr);

  int x = 6;
  x = 5;
  x = 4;
  x = 3;
  x = 2;

  volatile int v = 6;
  v = 5;
  v = 4;
  v = 3;
  v = 2;

  volatile int *v_ptr = &v;
  *v_ptr = 7;
  *v_ptr = 8;
  *v_ptr = 9;
  *v_ptr = 10;
  while (1)
  {

    thread_sleep_for(500);
  }
}

// Declaring Function
uint32_t add_two_numbers(uint32_t a, uint32_t b)
{
  uint32_t res = a + b;
  return res;
}

int main()
{
  uint32_t num1 = 2, num2 = 3;
  uint32_t to_print = add_two_numbers(num1, num2);
  printf("value = %d\n", to_print);
}

// * --------------------------------------------------
uint32_t add_all_numbers(uint32_t arr[], uint32_t n)
{
  uint32_t res = 0;
  for (uint32_t i = 0; i < n; i++)
  {
    res = res + arr[i];
  }
}

int main()
{
  uint32_t num1[] = {1, 2, 3, 4};
  uint32_t to_print = add_all_numbers(num1, 4);
  printf("value = %d\n", to_print);
}
// * --------------------------------------------------

typedef struct example_struct
{
  volatile uint32_t member_one;
  volatile uint32_t member_two;
  volatile uint32_t member_three;
} example_struct;

example_struct ex_str;
volatile uint32_t ex_arr[3];

int main()
{

  ex_str.member_one = 1;
  ex_str.member_two = 2;
  ex_str.member_three = 3;

  ex_arr[0] = 1;
  ex_arr[1] = 2;
  ex_arr[2] = 3;

  volatile uint32_t *ptr = &ex_str.member_one;
  *ptr = 20;

  ptr[0] = 4;
  ptr[1] = 5;
  ptr[2] = 6;

  while (1)
  {
    thread_sleep_for(500);
  }
}

// Example 3
typedef struct example_struct
{
  volatile uint32_t member_one;
  volatile uint32_t member_two;
  volatile uint32_t member_three;
} example_struct;

void set_struct_members(example_struct ex, uint32_t value)
{
  ex.member_one = value;
  ex.member_two = value;
  ex.member_three = value;
}

void set_struct_members_by_pointer(example_struct *ex, uint32_t value)
{
  ex->member_one = value; //(*ex).member_one=value;
  ex->member_two = value;
  ex->member_three = value;
}

example_struct ex_str;

int main()
{

  set_struct_members(ex_str, 7);
  set_struct_members_by_pointer(&ex_str, 8);

  while (1)
  {

    thread_sleep_for(500);
  }
}

// Example 4
typedef struct example_struct
{
  volatile uint32_t member_one;
  volatile uint32_t member_two;
  volatile uint32_t member_three;
} example_struct;

void set_struct_members(example_struct ex, uint32_t value)
{
  ex.member_one = value;
  ex.member_two = value;
  ex.member_three = value;
}

void set_struct_members_by_pointer(example_struct *ex, uint32_t value)
{
  ex->member_one = value;
  ex->member_two = value;
  ex->member_three = value;
}

volatile example_struct ex_str_arr[10];

int main()
{

  for (int i = 0; i < 10; i++)
  {

    set_struct_members_by_pointer(&ex_str_arr[i], 2);
  }

  while (1)
  {

    thread_sleep_for(500);
  }
}
