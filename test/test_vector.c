#include "vector.h"

/*-------------------------------------
 * Representation
 -------------------------------------*/
typedef struct test {
        unsigned x;
        int y;
} *Test_T;

/*-------------------------------------
 * Function Prototypes
 -------------------------------------*/
void test_vector_length(Vector_T vec);
void test_vector_set(Vector_T vec, Test_T test1);
void test_vector_setters(Vector_T vec, Test_T test1);
void test_vector_get(Vector_T vec);
void test_vector_getters(Vector_T vec);

/*-------------------------------------
 * Main
 -------------------------------------*/
int main(int argc, char *argv[]) {
        Vector_T vec;
        Test_T test1 = NULL;

        (void) argc, (void) argv;

        vec = Vector_new(10);
        assert(vec != NULL);

        test1 = malloc(sizeof(struct test));
        assert(test1 != NULL);
        test1->x = 10;
        test1->y = -5;

        fprintf(stderr, "\n"); //formatting

        //Unit Tests
        test_vector_length(vec);
        test_vector_set(vec, test1);
        test_vector_get(vec);

        //Cleanup
        free(test1);
        Vector_free(&vec);
}

/*-------------------------------------
 * Function Definitions
 -------------------------------------*/
void test_vector_length(Vector_T vec)
{
        Vector_T null_vec = NULL;
        unsigned length;

        fprintf(stderr, ">>>>>>>>>>>>>>>>>>>> Testing Vector_length\n");

        //Valid Cases
        fprintf(stderr, "Valid Cases --------\n");
        length = Vector_length(vec);
        fprintf(stderr, "Length of vec: %u\n", length);

        //Edge Cases
        (void) null_vec;
        fprintf(stderr, "\nEdge Cases ---------\n");
        //length = Vector_length(null_vec); //expected assertion

        fprintf(stderr, ">>>>>>>>>> Tests Passed.\n\n");
}

void test_vector_set(Vector_T vec, Test_T test1)
{
        Vector_T null_vec = NULL;
        unsigned index = 0;
        unsigned i;
        int n = 1234;
        int *n_ptr = &n;

        fprintf(stderr, ">>>>>>>>>>>>>>>>>>>> Testing Vector_set\n");

        //Valid Cases
        fprintf(stderr, "Valid Cases --------\n");
        Vector_set(vec, n_ptr, index);

        Vector_set(vec, test1, index);

        fprintf(stderr, "old length: %u\n", Vector_length(vec));
        Vector_set(vec, test1, Vector_length(vec));
        fprintf(stderr, "new length: %u\n", Vector_length(vec));

        for (i = 0; i < 10000; i++) {
                Vector_set(vec, test1, i);
        }

        //Edge Cases
        (void) null_vec;
        fprintf(stderr, "\nEdge Cases ---------\n");
        //Vector_set(vec, n_ptr, 1000); //expected assertion
        //Vector_set(vec, NULL, 0); // expected assertion
        //Vector_set(null_vec, test1, 1); // expected assertion
        //Vector_set(vec, test1, -1); //expected assertion

        fprintf(stderr, ">>>>>>>>>> Tests Passed.\n\n");
}

void test_vector_setters(Vector_T vec, Test_T test1)
{
        (void) vec, (void) test1;
}

void test_vector_get(Vector_T vec)
{
        Vector_T null_vec = NULL;
        Test_T test2 = NULL;
        int *ptr;
        unsigned i;
        unsigned index = 0;
        unsigned last = Vector_length(vec) - 1;

        fprintf(stderr, ">>>>>>>>>>>>>>>>>>>> Testing Vector_get\n");

        //Valid Cases
        fprintf(stderr, "Valid Cases --------\n");
        test2 = (Test_T) Vector_get(vec, index);
        fprintf(stderr, "vec[%u]->x: %u\n", index, test2->x);
        fprintf(stderr, "vec[%u]->y: %d\n", index, test2->y);

        test2 = (Test_T) Vector_get(vec, last);
        fprintf(stderr, "vec[%u]->x: %u\n", last, test2->x);
        fprintf(stderr, "vec[%u]->y: %d\n", last, test2->y);

        //Edge Cases
        (void) null_vec, (void) ptr, (void) i;
        fprintf(stderr, "\nEdge Cases ---------\n");
        //ptr = (int *) Vector_get(vec, -1); //expected assertion
        //ptr = (int *) Vector_get(vec, last + 1); //expected assertion
        //ptr = (int *) Vector_get(vec, last + 10); //expected assertion
        //ptr = (int *) Vector_get(null_vec, 0); //expected assertion
        /* expected assertion
        for (i = 0; i < last + 20; i++) {
                ptr = (int *) Vector_get(vec, i);
                fprintf(stderr, "got vec[%u]\n", i);
        }
        */

        fprintf(stderr, ">>>>>>>>>> Tests Passed.\n\n");
}

void test_vector_getters(Vector_T vec)
{
        (void) vec;
}
