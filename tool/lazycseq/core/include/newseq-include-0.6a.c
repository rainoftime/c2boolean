/*  Generated <insert-version-here> (-t<insert-maxthreads-here> -r<insert-maxrounds-here> -u<insert-unwind-here> -b<insert-backend-here>) <insert-date-here>  */
#include <stdio.h>
#include <stdlib.h>

<insert-extraheaders-here>
#define THREADS <insert-maxthreads-here>
#define ROUNDS <insert-maxrounds-here>

#define STOP_VOID(A) return;
#define STOP_NONVOID(A) return 0;

#define IF(A,B)  if (pc[thread_index] > A || (A >= pc_cs)) goto B;
#define GUARD(B)  assume( pc_cs >= B );

#ifndef NULL
#define NULL 0
#endif

#define assume(x) <insert-assume-here>(x)
#define __VERIFIER_assume(x) <insert-assume-here>(x)

#define assert(x) <insert-assert-here>(x)
#define __VERIFIER_assert(x) <insert-assert-here>(x)

#define __VERIFIER_nondet_int() <insert-nondet_int-here>()
<insert-nondet_int-body-here>

#define __VERIFIER_nondet_uint() <insert-nondet_uint-here>()
<insert-nondet_uint-body-here>
unsigned int nondet_uint();

unsigned char active_thread[THREADS+1]={1};
unsigned int pc[THREADS+1];
unsigned int thread_index;
unsigned int pc_cs;

<insert-thread-lines-here>

void * __cs_safe_malloc(size_t size) { void * ptr = malloc(size); assume(ptr); return ptr; }
void * __cs_unsafe_malloc(size_t size) { if(nondet_int()) return 0; return malloc(size); }
////#define __cs_unsafe_malloc malloc

///char __cs_nondet_char() { char c; return c; }

// #define __cs_init_scalar(A,B) ;
void __cs_init_scalar(void *var, size_t size) {
	if (size == sizeof(int))
		*(int *)var = nondet_int();
	else {
		char * ptr = (char *)var;
		size_t j;

		//for (j=0; j<size; j++)
		//	ptr[j] = __cs_nondet_char();
	}
}

/* pthread API */
typedef int __cs_mutex_t;
typedef int __cs_cond_t;
typedef int __cs_t;

int __cs_mutex_init (__cs_mutex_t *m, int val) { *m = -1; return 0; }
int __cs_mutex_destroy(__cs_mutex_t *m) { return 0; }
int __cs_mutex_lock(__cs_mutex_t *m) { assume(*m == -1); *m = thread_index; return 0; } 
int __cs_mutex_unlock(__cs_mutex_t *m) { assert(*m == thread_index); *m = -1; return 0; }

void *threadargs[THREADS+1];

int __cs_create(__cs_t *id, void *attr, void *(*t)(void*), void *arg, int threadID) { if (threadID > THREADS) return 0;  *id = threadID; active_thread[threadID] = 1; threadargs[threadID] = arg; return 0; }
int __cs_join(__cs_t id, void **value_ptr) { assume(pc[id] == thread_lines[id]); return 0; }
int __cs_exit(void *value_ptr) { return 0; }   // only for parsing

int __cs_cond_wait(__cs_cond_t *cond, __cs_mutex_t *mutex) { __cs_mutex_unlock(mutex); assume(*cond != -1); __cs_mutex_lock(mutex); return 0; }
int __cs_cond_signal(__cs_cond_t *cond) { *cond = 1; return 0; }
int __cs_cond_init(__cs_cond_t *cond, void *attr) { *cond = -1; return 0; }

/////unsigned short guess_pc() {  unsigned short x; return x; }
unsigned short guess_pc() {  unsigned short x = nondet_int(); return x; }


/* here */

