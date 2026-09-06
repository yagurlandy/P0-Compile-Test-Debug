#include <stdlib.h>
#include <stdio.h>
#include "harness/unity.h"
#include "../src/lab.h"


void setUp(void) {
  printf("Setting up tests...\n");
}

void tearDown(void) {
  printf("Tearing down tests...\n");
}

void test_get_greeting(void) {
  char *greeting = get_greeting("Alice");
  TEST_ASSERT_NOT_NULL(greeting);
  TEST_ASSERT_EQUAL_STRING("Hello, Alice!", greeting);
  free(greeting); // Free the allocated memory for the greeting

  greeting = get_greeting(NULL);
  TEST_ASSERT_NULL(greeting);

  greeting = get_greeting("");
  TEST_ASSERT_NOT_NULL(greeting);
  TEST_ASSERT_EQUAL_STRING("Hello, !", greeting);
  free(greeting);
}

void test_multiply(void)
{
  TEST_ASSERT_EQUAL_INT(20, multiply(4, 5));
  TEST_ASSERT_EQUAL_INT(0, multiply(8, 0));
  TEST_ASSERT_EQUAL_INT(-12, multiply(-3, 4));
}

void test_wrong_sum(void)
{
  TEST_ASSERT_EQUAL_INT(6, wrong_sum(2, 3));
  TEST_ASSERT_EQUAL_INT(1, wrong_sum(0, 0));
  TEST_ASSERT_EQUAL_INT(0, wrong_sum(-3, 2));
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_get_greeting);
  RUN_TEST(test_multiply);
  RUN_TEST(test_wrong_sum);
  return UNITY_END();
}
