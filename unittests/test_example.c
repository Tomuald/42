#include "minunit.h"
#include <string.h>

int ft_isalpha(int c);
char *capitalize_string(char * string);

MU_TEST(test_capitalize_string) {
  char *result;
  result = capitalize_string("abcd");
  mu_assert(strcmp(result, "ABCD") == 0, "result should equal ABCD");
  result = capitalize_string(NULL);
  mu_assert(result == NULL, "result should equal NULL");
}

MU_TEST(test_isalpha) {
  int result;
  result = ft_isalpha(66);
  mu_assert(result != 0, "66 should == 1");
}

MU_TEST_SUITE(test_suite_name) {
  MU_RUN_TEST(test_isalpha);
  MU_RUN_TEST(test_capitalize_string);
}

int main(void) {
  MU_RUN_SUITE(test_suite_name);
  MU_REPORT();
  return MU_EXIT_CODE;
}
