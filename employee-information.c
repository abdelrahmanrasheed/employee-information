#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES  1000
#define MAX_SALARIES  1000

int employees[MAX_EMPLOYEES];
float salaries[MAX_SALARIES];
int employee_number;

void employee_data(void);
void subset_employees(void);
void pay_raise(void);
void print_employees(void);

int main()
{
    int user_option;
    do
    {
        printf("\nPlease Enter number for corresponding function:\n\n"
               "1.Enter employees data\n"
               "2.Print out subset of employees\n"
               "3.Pay raise\n"
               "4.Print out salaries of all employees\n"
               "0.End\n\n");
               scanf("%i",&user_option);
               if (user_option == 0)
               {
                   printf("Goodbye.");
               }
               else if (user_option == 1)
               {
                   employee_data();
               }
               else if (user_option == 2)
               {
                   subset_employees();
               }
               else if (user_option == 3)
               {
                   pay_raise();
               }
               else if (user_option == 4)
               {
                   print_employees();
               }
               else
               {
                   printf("Please enter a valid input from 0-3!\n");
               }
    }
    while (user_option != 0);
    return 0;
}

void employee_data(void)
{
    printf("How many employees:  ");
    scanf("%i",&employee_number);
    if (employee_number > 1000)
    {
        printf("Value exceeds maximum value(Maximum value is 1000).\n");
        return;
    }
    for (int i = 0; i < employee_number; i++)
    {
        printf("Enter Employee %i ID:  ",i+1);
        scanf("%i",&employees[i]);
        printf("Enter Employee %i salary:  ",employees[i]);
        scanf("%f",&salaries[i]);
        printf("\n\n");
    }

}

void subset_employees(void)
{
    int salary,found = 0;
    printf("Enter Salary: ");
    scanf("%i",&salary);
    printf("\n");
    for (int i = 0; i < MAX_EMPLOYEES; i++)
    {
        if (salaries[i] > salary)
        {
            for (int j = i; j >= i; j--)
            {
                printf("Employee %i ",employees[j]);
                found = 1;
            }
            printf("\n\n");
        }
    }
        if (found == 0)
        {
            printf("This Value is higher than expected value");
        }
}

void pay_raise(void)
{
    int n;
    int employee_id;
    float raise;
            printf("Enter employee ID: ");
            scanf("%i",&employee_id);
            printf("Enter amount of raise percentage: ");
            scanf("%f",&raise);
            for (int i = 0; i < employee_id; i++)
            {
                if (employees[i] == employee_id)
                {
                        salaries[i] = salaries[i] + salaries[i] * (raise / 100);
                        printf("Employee %i new salary is %.2f\n",employee_id,salaries[i]);
                        break;
                }
                else if (employees[i] != employee_id)
                {
                    printf("\nEmployee ID not found, please enter correct employee ID.\n");
                    break;
                }
            }

}

void print_employees(void)
{
    for (int i = 0; i < employee_number; i++)
    {
        printf("Employee ID %i || Salary %.2f\n",employees[i],salaries[i]);
    }
}

