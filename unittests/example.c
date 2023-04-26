#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	ft_islower(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}

int	ft_isupper(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}

int	ft_isalpha(int c)
{
	if (ft_isupper(c) || ft_islower(c))
		return (1);
	return (0);
}

char *capitalize_string(char * string) {
  char *capitalized;

  if (!string)
    return (NULL);
  capitalized = malloc(sizeof(char) * strlen(string) + 1);
  int i = 0;
  while (string[i]) {
    if (ft_isalpha(string[i])) {
      if (ft_islower(string[i])) {
        capitalized[i] = string[i] - 32;
      } else {
        capitalized[i] = string[i];
      }
    }
    i++;
  }
  return (capitalized);
}

int main(void) {

}
