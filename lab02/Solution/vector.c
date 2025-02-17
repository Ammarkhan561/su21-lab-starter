/* Include the system headers we need */
#include <stdlib.h>
#include <stdio.h>

/* Include our header */
#include "vector.h"

/* Define what our struct is */
struct vector_t {
    size_t size;
    int *data;
};

/* Utility function to handle allocation failures. In this
   case we print a message and exit. */
static void allocation_failed() {
    fprintf(stderr, "Out of memory.\n");
    exit(1);
}

/* Bad example of how to create a new vector */
vector_t *bad_vector_new() {
    /* Create the vector and a pointer to it */
    vector_t *retval, v;
    retval = &v;

    /* Initialize attributes */
    retval->size = 1;
    retval->data = malloc(sizeof(int));
    if (retval->data == NULL) {
        allocation_failed();
    }

    retval->data[0] = 0;
    return retval;
}

/* Another suboptimal way of creating a vector */
vector_t also_bad_vector_new() {
    /* Create the vector */
    vector_t v;

    /* Initialize attributes */
    v.size = 1;
    v.data = malloc(sizeof(int));
    if (v.data == NULL) {
        allocation_failed();
    }
    v.data[0] = 0;
    return v;
}

/* Create a new vector with a size (length) of 1 and set its single component to zero... the
   right way */
/* TODO: uncomment the code that is preceded by // */
vector_t *vector_new() {
    /* Declare what this function will return */
    vector_t *retval;

    /* First, we need to allocate memory on the heap for the struct */
     retval =  malloc(sizeof(vector_t)); /* YOUR CODE HERE */

    /* Check our return value to make sure we got memory */
    if (retval == NULL) {
        allocation_failed();
    }

    /* Now we need to initialize our data.
       Since retval->data should be able to dynamically grow,
       what do you need to do? */
    retval->size =1 ;
    retval->data =calloc(retval->size, sizeof(int));//allocated a memory of block and initialized it to zero using calloc

    /* Check the data attribute of our vector to make sure we got memory */
     if (retval->data == NULL) {
    	 free(retval);				//Why is this line necessary? Because if it fails to allocate the memory we have to free the previously allocated memory for vector_t
         allocation_failed();
	}

    /* Complete the initialization by setting the single component to zero */
	retval->data[0] = 0;
    /* and return... */
    return retval; /* UPDATE RETURN VALUE */
}

/* Return the value at the specified location/component "loc" of the vector */
int vector_get(vector_t *v, size_t loc) {

    /* If we are passed a NULL pointer for our vector, complain about it and exit. */
    if(v == NULL) {
        fprintf(stderr, "vector_get: passed a NULL vector.\n");
        abort();
    }

    /* If the requested location is higher than we have allocated, return 0.
     * Otherwise, return what is in the passed location.
     */
    if (loc >= v->size){    /* YOUR CODE HERE */
    	return 0;
	}
    else {
	return v->data[loc];
	}
}

/* Free up the memory allocated for the passed vector.
   Remember, you need to free up ALL the memory that was allocated. */
void vector_delete(vector_t *v) {
    free(v->data);
	free(v);
	
}

/* Set a value in the vector. If the extra memory allocation fails, call
   allocation_failed(). */
void vector_set(vector_t *v, size_t loc, int value) {
    /* What do you need to do if the location is greater than the size we have
     * allocated?  Remember that unset locations should contain a value of 0.
     */
    if ( loc >= v->size){
        size_t updated_size = loc; 
        int *updated_data;
        updated_data = realloc( v->data , updated_size * sizeof(int) ); //reallocating the memory to the updated size
        if ( updated_data == NULL ){ //checking if the memory is allocated or not 
            allocation_failed();
        }
        for ( int i = v->size; i < updated_size; i++){ //loop to initialize the updated data to 0
            updated_data [i] = 0;
        }
        v->size = updated_size;
        v->data =updated_data;
        
    }
    else{
        v->data[loc] = value; //if loc < v->size
    }

}

