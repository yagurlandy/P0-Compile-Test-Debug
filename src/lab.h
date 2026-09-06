#ifndef LAB_H
#define LAB_H

/** * @brief Returns a greeting message.
 *
 * This function returns a string that contains a greeting message.
 * The string is allocated with malloc and should be freed by the caller.
 * @param name The name to include in the greeting.
 * @return A greeting string.
 */
char* get_greeting(const char* restrict name);


/**
 * @brief multiplies two ints
 *
 * @param first_int first int in mult func
 * @param second_int second int in mult func
 * @return product of first and second int
 */
int multiply(int first_int, int second_int);

/**
 * @brief calculates incorrect sum of two ints
 *
 * @param first_int first int in add func
 * @param second_int second int in add func
 * @return intentional incorrect sum of the two ints
 */
int wrong_sum(int first_int, int second_int);

#endif // LAB_H
