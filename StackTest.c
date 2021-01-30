#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "stack.h"
#include "header.h"
#define TOL 0.001
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

double absolute( double a )
{
    if( a < 0 )
        a *= -1;
    return a;
}

int main()
{
    LinkedList *stack = NULL;
    char *alloc = NULL;
    char *str = "James";
    int id = 24213112;
    int age = 21;
    double mark = 81.5;
    char grade = 'A';
    int empty = 0;
    stack = createStack();

    push( stack, str, 's' );
    push( stack, &id, 'i' );
    push( stack, &age, 'i' );
    push( stack, &mark, 'd' );
    push( stack, &grade, 'c' );

    printf("Test Pop Character: ");
    if( *(char*) pop( stack ) == 'A' )
        printf("%sPASSED%s\n\n", GREEN, RESET);
    else
        printf("%sFAILED%s\n\n", RED, RESET);

    printf("Test Pop Double: ");
    if( absolute( *(double *) pop( stack ) - 81.5 ) <= TOL )
        printf("%sPASSED%s\n\n", GREEN, RESET);
    else
        printf("%sFAILED%s\n\n", RED, RESET);

    printf("Test Empty: ");
    empty = isStackEmpty( stack );
    if( empty == FALSE )
        printf("%sPASSED%s\n\n", GREEN, RESET);
    else
        printf("%sFAILED%s\n\n", RED, RESET);

    printf("Test Pop Integer: ");
    if( *(int *) pop( stack ) == age )
        printf("%sPASSED%s\n\n", GREEN, RESET);
    else
        printf("%sFAILED%s\n\n", RED, RESET);

    printf("Test Stack Integer: ");
    if( *(int *) pop( stack ) == id )
        printf("%sPASSED%s\n\n", GREEN, RESET);
    else
        printf("%sFAILED%s\n\n", RED, RESET);

    printf("Test Pop String: ");
    if( strcmp( "James", (char*) pop( stack ) ) == 0 )
        printf("%sPASSED%s\n\n", GREEN, RESET);
    else
        printf("%sFAILED%s\n\n", RED, RESET); 

    printf("Test Empty: ");
    empty = isStackEmpty( stack );
    if( empty == TRUE )
        printf("%sPASSED%s\n\n", GREEN, RESET);
    else
        printf("%sFAILED%s\n\n", RED, RESET);

    printf("Push after Empty: ");
    alloc = malloc(sizeof(char));
    strcpy( alloc, "test" );
    push( stack, alloc, 's' );
    empty = isStackEmpty( stack );
    if( empty == FALSE )
        printf("%sPASSED%s\n\n", GREEN, RESET);
    else
        printf("%sFAILED%s\n\n", RED, RESET);

    free( alloc ); alloc = NULL;
    freeStack( stack );
    stack = NULL;
        
    stack = createStack();

    printf("TEST Empty after recreate stack: ");
    if ( isStackEmpty( stack ) == TRUE )
        printf("%sPASSED%s\n\n", GREEN, RESET);
    else
        printf("%sFAILED%s\n\n", RED, RESET);

    printf("Push Stack After Empty: ");
    push( stack, str, 's' );
    if ( isStackEmpty( stack ) == FALSE )
        printf("%sPASSED%s\n\n", GREEN, RESET);
    else
        printf("%sFAILED%s\n\n", RED, RESET);

    printf("Pop Stack After Pushed: ");
    pop( stack );
    if ( isStackEmpty( stack ) == TRUE )
        printf("%sPASSED%s\n\n", GREEN, RESET);
    else
        printf("%sFAILED%s\n\n", RED, RESET);

    printf("Push Stack After Empty: ");
    push( stack, &id, 'i' );
    if ( isStackEmpty( stack ) == FALSE )
        printf("%sPASSED%s\n\n", GREEN, RESET);
    else
        printf("%sFAILED%s\n\n", RED, RESET);

    return 0;
}
