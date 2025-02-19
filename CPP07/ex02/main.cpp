// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.cpp                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/02/14 09:58:49 by vkuznets          #+#    #+#             */
// /*   Updated: 2025/02/19 10:32:20 by vkuznets         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "Array.hpp"
// #include <ctime> // for srand(time(0))
// #include <iostream>
// #define SIZE 42

// int main(void)
// {
//     // Creating an Array object and a normal array
//     Array<int> class_array(SIZE);
//     int *normal_array = new int[SIZE];

//     srand(time(0));

//     // Fill both arrays with random values
//     std::cout << "Filling both arrays with random values...\n";
//     for (int i = 0; i < SIZE; i++)
//     {
//         int value = rand() % 42;
//         class_array[i] = normal_array[i] = value;
//     }

//     // Copy constructor & assignment operator testing
//     std::cout << "Testing copy constructor and assignment operator...\n";
//     Array<int> class_arr_eq = class_array;
//     Array<int> class_arr_cp(class_arr_eq);

//     // Validate if the values are correctly copied
//     std::cout << "Comparing values to ensure correct copying...\n";
//     for (int i = 0; i < SIZE; i++)
//     {
//         if (normal_array[i] == class_array[i])
//         {
//             std::cout << "Match at index " << i << ": " << class_array[i] << std::endl;
//         }
//         else
//         {
//             std::cout << "Mismatch at index " << i << "!" << std::endl;
//         }
//     }

//     // Testing out-of-bounds access with exception handling
//     std::cout << "\nTesting out-of-bounds access with exception handling...\n";
//     try
//     {
//         std::cout << "Accessing -42 index: " << class_array[-42] << std::endl;
//     }
//     catch (const std::exception &e)
//     {
//         std::cerr << "Exception caught: " << e.what() << std::endl;
//     }

//     try
//     {
//         std::cout << "Accessing 42 index: " << class_array[42] << std::endl;
//     }
//     catch (const std::exception &e)
//     {
//         std::cerr << "Exception caught: " << e.what() << std::endl;
//     }

//     // Assign new random values
//     std::cout << "\nAssigning new random values to class_array...\n";
//     for (int i = 0; i < SIZE; i++)
//         class_array[i] = rand();

//     std::cout << "Cleaning up dynamically allocated memory...\n";

//     // Free dynamically allocated memory
//     delete[] normal_array;

//     return 0;
// }

#include <Array.hpp>
#include <iostream>

#define MAX_VAL 750
int main(int, char **)
{
    Array<int> numbers(MAX_VAL);
    int *mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    // SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete[] mirror; //
    return 0;
}
