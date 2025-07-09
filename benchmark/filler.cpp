/**
 * @file filler.cpp
 *
 * This file includes filler functions which are added to both result and
 * exceptions. The hypothesis and expectation is that the additional functions
 * will have no effect on the result experiment and will have an effect on the
 * exceptions experiment. Exceptions are effected because exceptions perform a
 * binary search through the exception index to find the handling info for each
 * function.
 *
 */

/**
 * @brief Performs some set of actions that forces the compiler to link in all
 * of the filler functions.
 */
void activate_filler();
