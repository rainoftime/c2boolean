/*  Generated 0.0.0.0.0.0 (-t1 -r2 -u2 -bcbmc) 2015-12-14 11:26:52  */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define THREADS 1
#define ROUNDS 2

#define STOP_VOID(A) return;
#define STOP_NONVOID(A) return 0;

#define IF(T,A,B)  if ((pc[T] > A) | (A >= pc_cs)) goto B;
#define GUARD(T,B)  assume( pc_cs >= B );

#ifndef NULL
#define NULL 0
#endif

#define assume(x) __CPROVER_assume(x)
#define __VERIFIER_assume(x) __CPROVER_assume(x)

#define assert(x) assert(x)
#define __VERIFIER_assert(x) assert(x)

#define __VERIFIER_nondet_int() nondet_int()
int nondet_int();
#define __VERIFIER_nondet_uint() nondet_uint()
unsigned int nondet_uint();
#define __VERIFIER_nondet_bool() nondet_bool()
_Bool nondet_bool();
#define __VERIFIER_nondet_char() nondet_char()
char nondet_char();
#define __VERIFIER_nondet_uchar() nondet_uchar()
unsigned char nondet_uchar();

unsigned __CPROVER_bitvector[1] active_thread[THREADS+1]={1};
unsigned __CPROVER_bitvector[9] pc[THREADS+1];
unsigned __CPROVER_bitvector[10] pc_cs;
unsigned int thread_index;
unsigned __CPROVER_bitvector[9] thread_lines[] = {307, 31};

/* pthread API */
typedef int __cs_t;
typedef int __cs_attr_t;
typedef int __cs_mutex_t;
typedef int __cs_mutexattr_t;
typedef int __cs_cond_t;
typedef int __cs_condattr_t;
typedef int __cs_spinlock_t;
typedef int __cs_key_t;
typedef int __cs_once_t;
typedef int __cs_rwlock_t;
typedef int __cs_rwlockattr_t;
typedef int __cs_barrier_t;
typedef int __cs_barrierattr_t;

/* define PTHREAD CONSTANTS */
#define PTHREAD_MUTEX_INITIALIZER -1
#define PTHREAD_COND_INITIALIZER -1
#define PTHREAD_RWLOCK_INITIALIZER 0
#define PTHREAD_BARRIER_SERIAL_THREAD 0
#define PTHREAD_CANCEL_ASYNCHRONOUS 0
#define PTHREAD_CANCEL_ENABLE 0
#define PTHREAD_CANCEL_DEFERRED 0
#define PTHREAD_CANCEL_DISABLE 0
#define PTHREAD_CANCELED 0
#define PTHREAD_CREATE_DETACHED 0
#define PTHREAD_CREATE_JOINABLE 0
#define PTHREAD_EXPLICIT_SCHED 0
#define PTHREAD_INHERIT_SCHED 0
#define PTHREAD_MUTEX_DEFAULT 0
#define PTHREAD_MUTEX_ERRORCHECK 0
#define PTHREAD_MUTEX_NORMAL 0
#define PTHREAD_MUTEX_RECURSIVE 0
#define PTHREAD_MUTEX_ROBUST 0
#define PTHREAD_MUTEX_STALLED 0
#define PTHREAD_ONCE_INIT 0
#define PTHREAD_PRIO_INHERIT 0
#define PTHREAD_PRIO_NONE 0
#define PTHREAD_PRIO_PROTECT 0
#define PTHREAD_PROCESS_SHARED 0
#define PTHREAD_PROCESS_PRIVATE 0
#define PTHREAD_SCOPE_PROCESS 0
#define PTHREAD_SCOPE_SYSTEM 0

void *threadargs[THREADS+1];

int __cs_create(__cs_t *id, void *attr, void *(*t)(void*), void *arg, int threadID) { if (threadID > THREADS) return 0;  *id = threadID; active_thread[threadID] = 1; threadargs[threadID] = arg; return 0; }
int __cs_join(__cs_t id, void **value_ptr) { assume(pc[id] == thread_lines[id]); return 0; }

void __cs_exit(void *value_ptr) { return; }   // only for parsing
__cs_t __cs_self() {  return thread_index;  }
int __cs_cancel(__cs_t id) {  return 0;  }

int __cs_mutex_init (__cs_mutex_t *m, int val) { *m = -1; return 0; }
int __cs_mutex_destroy(__cs_mutex_t *m) { return 0; }
int __cs_mutex_lock(__cs_mutex_t *m) { assume(*m == -1); *m = thread_index; return 0; }
int __cs_mutex_unlock(__cs_mutex_t *m) { assume(*m == thread_index); *m = -1; return 0; }

int __cs_cond_init(__cs_cond_t *cond, void *attr) { *cond = -1; return 0; }
int __cs_cond_destroy(__cs_cond_t *cond) { return 0; }
/* Already handle in lock optimizer module */
// int __cs_cond_wait(__cs_cond_t *cond, __cs_mutex_t *mutex) { __cs_mutex_unlock(mutex); assume(*cond != -1); __cs_mutex_lock(mutex); return 0;}
// int __cs_cond_timedwait(__cs_cond_t *cond, __cs_mutex_t *mutex, struct timespec *abstime) { if(__VERIFIER_nondet_bool()) {__cs_mutex_unlock(mutex); assume(*cond != -1); __cs_mutex_lock(mutex); return 0;} else {return ETIMEDOUT;}}
int __cs_cond_signal(__cs_cond_t *cond) { *cond = 1; return 0; }
int __cs_cond_broadcast(__cs_cond_t *cond) { *cond = 2; return 0; }

int __cs_spin_init(__cs_spinlock_t *l, int val) {*l = -1; return 0;}
int __cs_spin_destroy(__cs_spinlock_t *l) {return 0;}
int __cs_spin_lock(__cs_spinlock_t *l) { assume(*l == -1); *l = thread_index; return 0; }
int __cs_spin_unlock(__cs_spinlock_t *l) { assume(*l == thread_index); *l = -1; return 0; }

// Dirty fix for those macro in this situation val = __cs_..MACRO
#define __cs_mutex_lock_MACRO(m) 0; assume(m == -1); m = thread_index;
#define __cs_mutex_unlock_MACRO(m) 0; assume(m == thread_index); m = -1;
#define __cs_cond_signal_MACRO(cond) 0; cond = 1;
#define __cs_cond_broadcast_MACRO(cond) 0; cond = 2;
#define __cs_spin_unlock_MACRO(l) 0; assume(l == thread_index); l = -1;
#define __cs_spin_lock_MACRO(l) 0; assume(l == -1); l = thread_index;

// For schedule yield function
int __cs_sched_yield(unsigned __CPROVER_bitvector[10] val) {pc_cs = val + 1; return 0;}    // Version 1
//int __cs_sched_yield(unsigned __CPROVER_bitvector[10] val) {return 0;}     // Version 2


void * __cs_safe_malloc(size_t size) { void * ptr = malloc(size); assume(ptr); return ptr; }
void * __cs_unsafe_malloc(size_t size) { if(__VERIFIER_nondet_int()) return 0; return malloc(size); }
#define __cs_safe_malloc_LOCAL __cs_safe_malloc
#define __cs_unsafe_malloc malloc

void __cs_init_scalar(void *var, size_t size) {
    if (size == sizeof(int))
        *(int *)var = __VERIFIER_nondet_int();
    else {
        char * ptr = (char *)var;
        // size_t j;
        // for (j=0; j<size; j++)
        //     ptr[j] = __cs_nondet_char();
    }
}
size_t nondet_size_t();

unsigned __CPROVER_bitvector[9] guess_pc() {unsigned __CPROVER_bitvector[9] i; return i;}

/* here */


typedef 
                                                       struct Obj
                                                       {
                                                       		int field;
                                                       } Obj;
                                                       int __cs_function_Init_ObjType_inlined = 1;
                                                       int __cs_function_Operation_inlined = 1;
                                                       int __cs_function_Check_inlined = 1;
typedef 
                                                       struct WorkStealQueue
                                                       {
                                                       		__cs_mutex_t cs;
                                                       		long MaxSize;
                                                       		long InitialSize;
                                                       		long head;
                                                       		long tail;
                                                       		Obj **elems;
                                                       		long mask;
                                                       } WorkStealQueue;
                                                       long __CS_atomic_exchange(long *__csLOCALPARAM___CS_atomic_exchange_obj, long __csLOCALPARAM___CS_atomic_exchange_v)
                                                       {
                                                         static long __csLOCAL___CS_atomic_exchange_t;
                                                         __csLOCAL___CS_atomic_exchange_t = *__csLOCALPARAM___CS_atomic_exchange_obj;
                                                         *__csLOCALPARAM___CS_atomic_exchange_obj = __csLOCALPARAM___CS_atomic_exchange_v;
                                                         return __csLOCAL___CS_atomic_exchange_t;
                                                       }
                                                       
                                                       _Bool __CS_atomic_compare_exchange_strong(long *__csLOCALPARAM___CS_atomic_compare_exchange_strong_obj, long *__csLOCALPARAM___CS_atomic_compare_exchange_strong_expected, long __csLOCALPARAM___CS_atomic_compare_exchange_strong_desired)
                                                       {
                                                         if ((*__csLOCALPARAM___CS_atomic_compare_exchange_strong_obj) == (*__csLOCALPARAM___CS_atomic_compare_exchange_strong_expected))
                                                         {
                                                           *__csLOCALPARAM___CS_atomic_compare_exchange_strong_obj = __csLOCALPARAM___CS_atomic_compare_exchange_strong_desired;
                                                           return 1;
                                                         }
                                                         else
                                                         {
                                                           *__csLOCALPARAM___CS_atomic_compare_exchange_strong_expected = *__csLOCALPARAM___CS_atomic_compare_exchange_strong_obj;
                                                           return 0;
                                                         }
                                                       
                                                       }
                                                       
                                                       int __cs_function_readV_inlined = 1;
                                                       int __cs_function_writeV_inlined = 1;
                                                       int __cs_function_Init_WorkStealQueue_inlined = 1;
                                                       int __cs_function_Destroy_WorkStealQueue_inlined = 1;
                                                       int __cs_function_Steal_inlined = 1;
                                                       int __cs_function_SyncPop_inlined = 1;
                                                       int __cs_function_Pop_inlined = 1;
                                                       int __cs_function_SyncPush_inlined = 1;
                                                       int __cs_function_Push_inlined = 1;
                                                       void *Stealer_0(void *__csLOCALPARAM_Stealer_param)
                                                       {
                                                       static WorkStealQueue *__csLOCAL_Stealer_q;
IF(1,0,tStealer_0_1)                                   __csLOCAL_Stealer_q = (WorkStealQueue *) __csLOCALPARAM_Stealer_param;
                                                       static int __csLOCAL_Stealer_i;
                                                       static Obj *__csLOCAL_Stealer_r;
                                                       __csLOCAL_Stealer_i = 0;
                                                       	{
                                                       static _Bool __csLOCAL_Stealer___if_cond_5;
                                                       static _Bool __retval__Steal_1;
                                                       		{
                                                       static WorkStealQueue *__csLOCALPARAM_Steal_q;
tStealer_0_1: IF(1,1,tStealer_0_2)                     __csLOCALPARAM_Steal_q = __csLOCAL_Stealer_q;
                                                       static Obj **__csLOCALPARAM_Steal_result;
tStealer_0_2: IF(1,2,tStealer_0_3)                     __csLOCALPARAM_Steal_result = &__csLOCAL_Stealer_r;
                                                       static _Bool __csLOCAL_Steal_found;
tStealer_0_3: IF(1,3,tStealer_0_4)                     __cs_mutex_lock_MACRO((*__csLOCALPARAM_Steal_q).cs);
                                                       static long __csLOCAL_Steal_h;
                                                       static long __retval__readV_1;
                                                       			{
                                                       static long *__csLOCALPARAM_readV_v;
tStealer_0_4: IF(1,4,tStealer_0_5)                     __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_Steal_q).head;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tStealer_0_5: IF(1,5,tStealer_0_6)                     __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_1 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_1_0;
                                                       				__exit__readV_1_0: GUARD(1,6)
                                                       ;
                                                       			};
                                                       __csLOCAL_Steal_h = __retval__readV_1;
                                                       			{
                                                       static long *__csLOCALPARAM_writeV_v;
tStealer_0_6: IF(1,6,tStealer_0_7)                     __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_Steal_q).head;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_Steal_h + 1;
tStealer_0_7: IF(1,7,tStealer_0_8)                     __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       				__exit__writeV_1_0: GUARD(1,8)
                                                       ;
                                                       			};
                                                       0;
                                                       static _Bool __csLOCAL_Steal___if_cond_0;
                                                       static long __retval__readV_2;
                                                       			{
                                                       static long *__csLOCALPARAM_readV_v;
tStealer_0_8: IF(1,8,tStealer_0_9)                     __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_Steal_q).tail;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tStealer_0_9: IF(1,9,tStealer_0_10)                    __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_2 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_2_0;
                                                       				__exit__readV_2_0: GUARD(1,10)
                                                       ;
                                                       			};
                                                       __csLOCAL_Steal___if_cond_0 = __csLOCAL_Steal_h < __retval__readV_2;
                                                       if (__csLOCAL_Steal___if_cond_0)
                                                       			{
tStealer_0_10: IF(1,10,tStealer_0_11)                  *__csLOCALPARAM_Steal_result = (*__csLOCALPARAM_Steal_q).elems[__csLOCAL_Steal_h & (*__csLOCALPARAM_Steal_q).mask];
                                                       __csLOCAL_Steal_found = 1;
                                                       			}
                                                       			else
                                                       			{ GUARD(1,11)
                                                       				{
                                                       static long *__csLOCALPARAM_writeV_v;
tStealer_0_11: IF(1,11,tStealer_0_12)                  __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_Steal_q).head;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_Steal_h;
tStealer_0_12: IF(1,12,tStealer_0_13)                  __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       					__exit__writeV_2_0: GUARD(1,13)
                                                       ;
                                                       				};
                                                       0;
                                                       __csLOCAL_Steal_found = 0;
                                                       			}
                                                       			GUARD(1,13);
tStealer_0_13: IF(1,13,tStealer_0_14)                  __cs_mutex_unlock_MACRO((*__csLOCALPARAM_Steal_q).cs);
                                                       __retval__Steal_1 = __csLOCAL_Steal_found;
                                                       goto __exit__Steal_1_0;
                                                       			__exit__Steal_1_0: GUARD(1,14)
                                                       ;
                                                       		};
                                                       __csLOCAL_Stealer___if_cond_5 = __retval__Steal_1;
                                                       if (__csLOCAL_Stealer___if_cond_5)
                                                       		{
                                                       			{
                                                       static Obj *__csLOCALPARAM_Operation_r;
tStealer_0_14: IF(1,14,tStealer_0_15)                  __csLOCALPARAM_Operation_r = __csLOCAL_Stealer_r;
tStealer_0_15: IF(1,15,tStealer_0_16)                  (*__csLOCALPARAM_Operation_r).field++;
                                                       				__exit__Operation_1_0: GUARD(1,16)
                                                       ;
                                                       			};
                                                       0;
                                                       		}
                                                       		GUARD(1,16);
                                                       	};
                                                       __csLOCAL_Stealer_i++;
                                                       	{
                                                       static _Bool __csLOCAL_Stealer___if_cond_5;
                                                       static _Bool __retval__Steal_1;
                                                       		{
                                                       static WorkStealQueue *__csLOCALPARAM_Steal_q;
tStealer_0_16: IF(1,16,tStealer_0_17)                  __csLOCALPARAM_Steal_q = __csLOCAL_Stealer_q;
                                                       static Obj **__csLOCALPARAM_Steal_result;
tStealer_0_17: IF(1,17,tStealer_0_18)                  __csLOCALPARAM_Steal_result = &__csLOCAL_Stealer_r;
                                                       static _Bool __csLOCAL_Steal_found;
tStealer_0_18: IF(1,18,tStealer_0_19)                  __cs_mutex_lock_MACRO((*__csLOCALPARAM_Steal_q).cs);
                                                       static long __csLOCAL_Steal_h;
                                                       static long __retval__readV_1;
                                                       			{
                                                       static long *__csLOCALPARAM_readV_v;
tStealer_0_19: IF(1,19,tStealer_0_20)                  __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_Steal_q).head;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tStealer_0_20: IF(1,20,tStealer_0_21)                  __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_1 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_1_1;
                                                       				__exit__readV_1_1: GUARD(1,21)
                                                       ;
                                                       			};
                                                       __csLOCAL_Steal_h = __retval__readV_1;
                                                       			{
                                                       static long *__csLOCALPARAM_writeV_v;
tStealer_0_21: IF(1,21,tStealer_0_22)                  __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_Steal_q).head;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_Steal_h + 1;
tStealer_0_22: IF(1,22,tStealer_0_23)                  __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       				__exit__writeV_1_1: GUARD(1,23)
                                                       ;
                                                       			};
                                                       0;
                                                       static _Bool __csLOCAL_Steal___if_cond_0;
                                                       static long __retval__readV_2;
                                                       			{
                                                       static long *__csLOCALPARAM_readV_v;
tStealer_0_23: IF(1,23,tStealer_0_24)                  __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_Steal_q).tail;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tStealer_0_24: IF(1,24,tStealer_0_25)                  __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_2 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_2_1;
                                                       				__exit__readV_2_1: GUARD(1,25)
                                                       ;
                                                       			};
                                                       __csLOCAL_Steal___if_cond_0 = __csLOCAL_Steal_h < __retval__readV_2;
                                                       if (__csLOCAL_Steal___if_cond_0)
                                                       			{
tStealer_0_25: IF(1,25,tStealer_0_26)                  *__csLOCALPARAM_Steal_result = (*__csLOCALPARAM_Steal_q).elems[__csLOCAL_Steal_h & (*__csLOCALPARAM_Steal_q).mask];
                                                       __csLOCAL_Steal_found = 1;
                                                       			}
                                                       			else
                                                       			{ GUARD(1,26)
                                                       				{
                                                       static long *__csLOCALPARAM_writeV_v;
tStealer_0_26: IF(1,26,tStealer_0_27)                  __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_Steal_q).head;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_Steal_h;
tStealer_0_27: IF(1,27,tStealer_0_28)                  __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       					__exit__writeV_2_1: GUARD(1,28)
                                                       ;
                                                       				};
                                                       0;
                                                       __csLOCAL_Steal_found = 0;
                                                       			}
                                                       			GUARD(1,28);
tStealer_0_28: IF(1,28,tStealer_0_29)                  __cs_mutex_unlock_MACRO((*__csLOCALPARAM_Steal_q).cs);
                                                       __retval__Steal_1 = __csLOCAL_Steal_found;
                                                       goto __exit__Steal_1_1;
                                                       			__exit__Steal_1_1: GUARD(1,29)
                                                       ;
                                                       		};
                                                       __csLOCAL_Stealer___if_cond_5 = __retval__Steal_1;
                                                       if (__csLOCAL_Stealer___if_cond_5)
                                                       		{
                                                       			{
                                                       static Obj *__csLOCALPARAM_Operation_r;
tStealer_0_29: IF(1,29,tStealer_0_30)                  __csLOCALPARAM_Operation_r = __csLOCAL_Stealer_r;
tStealer_0_30: IF(1,30,tStealer_0_31)                  (*__csLOCALPARAM_Operation_r).field++;
                                                       				__exit__Operation_1_1: GUARD(1,31)
                                                       ;
                                                       			};
                                                       0;
                                                       		}
                                                       		GUARD(1,31);
                                                       	};
                                                       __csLOCAL_Stealer_i++;
                                                       assume(!(__csLOCAL_Stealer_i < 2));
                                                       	__exit_loop_1: GUARD(1,31)
                                                       ;
                                                       goto __exit_Stealer;
                                                       	__exit_Stealer: GUARD(1,31)
                                                       ;
tStealer_0_31:                                         STOP_NONVOID(31);
                                                       }
                                                       
                                                       
                                                       
                                                       int main_thread(void)
                                                       {
IF(0,0,tmain_1)                                        static int __csLOCAL_main_i;
                                                       static __cs_t *__csLOCAL_main_handles;
                                                       __csLOCAL_main_handles = (__cs_t *) __cs_safe_malloc((sizeof(__cs_t)) * 1);
                                                       static Obj *__csLOCAL_main_items;
                                                       __csLOCAL_main_items = __cs_safe_malloc(4 * (sizeof(Obj)));
                                                       __csLOCAL_main_i = 0;
                                                       if (!(__csLOCAL_main_i < (4 / 2)))
                                                       	{
                                                       goto __exit_loop_2;
                                                       	}
                                                       	;
                                                       	{
                                                       		{
                                                       static Obj *__csLOCALPARAM_Init_ObjType_r;
                                                       __csLOCALPARAM_Init_ObjType_r = &__csLOCAL_main_items[2 * __csLOCAL_main_i];
                                                       (*__csLOCALPARAM_Init_ObjType_r).field = 0;
                                                       			__exit__Init_ObjType_1_0: GUARD(0,1)
                                                       ;
                                                       		};
                                                       0;
                                                       		{
                                                       static Obj *__csLOCALPARAM_Init_ObjType_r;
                                                       __csLOCALPARAM_Init_ObjType_r = &__csLOCAL_main_items[(2 * __csLOCAL_main_i) + 1];
                                                       (*__csLOCALPARAM_Init_ObjType_r).field = 0;
                                                       			__exit__Init_ObjType_2_0: GUARD(0,1)
                                                       ;
                                                       		};
                                                       0;
                                                       	};
                                                       __csLOCAL_main_i++;
                                                       if (!(__csLOCAL_main_i < (4 / 2)))
                                                       	{
                                                       goto __exit_loop_2;
                                                       	}
                                                       	;
                                                       	{
                                                       		{
                                                       static Obj *__csLOCALPARAM_Init_ObjType_r;
                                                       __csLOCALPARAM_Init_ObjType_r = &__csLOCAL_main_items[2 * __csLOCAL_main_i];
                                                       (*__csLOCALPARAM_Init_ObjType_r).field = 0;
                                                       			__exit__Init_ObjType_1_1: GUARD(0,1)
                                                       ;
                                                       		};
                                                       0;
                                                       		{
                                                       static Obj *__csLOCALPARAM_Init_ObjType_r;
                                                       __csLOCALPARAM_Init_ObjType_r = &__csLOCAL_main_items[(2 * __csLOCAL_main_i) + 1];
                                                       (*__csLOCALPARAM_Init_ObjType_r).field = 0;
                                                       			__exit__Init_ObjType_2_1: GUARD(0,1)
                                                       ;
                                                       		};
                                                       0;
                                                       	};
                                                       __csLOCAL_main_i++;
                                                       assume(!(__csLOCAL_main_i < (4 / 2)));
                                                       	__exit_loop_2: GUARD(0,1)
                                                       ;
                                                       static WorkStealQueue __csLOCAL_main_q;
                                                       	{
                                                       static WorkStealQueue *__csLOCALPARAM_Init_WorkStealQueue_q;
                                                       __csLOCALPARAM_Init_WorkStealQueue_q = &__csLOCAL_main_q;
                                                       static long __csLOCALPARAM_Init_WorkStealQueue_size;
                                                       __csLOCALPARAM_Init_WorkStealQueue_size = 2;
                                                       (*__csLOCALPARAM_Init_WorkStealQueue_q).MaxSize = 1024 * 1024;
                                                       (*__csLOCALPARAM_Init_WorkStealQueue_q).InitialSize = 1024;
                                                       __cs_mutex_init(&(*__csLOCALPARAM_Init_WorkStealQueue_q).cs, 0);
                                                       		{
                                                       static long *__csLOCALPARAM_writeV_v;
                                                       __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_Init_WorkStealQueue_q).head;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = 0;
                                                       __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       			__exit__writeV_3: GUARD(0,1)
                                                       ;
                                                       		};
                                                       0;
                                                       (*__csLOCALPARAM_Init_WorkStealQueue_q).mask = __csLOCALPARAM_Init_WorkStealQueue_size - 1;
                                                       		{
                                                       static long *__csLOCALPARAM_writeV_v;
                                                       __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_Init_WorkStealQueue_q).tail;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = 0;
                                                       __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       			__exit__writeV_4: GUARD(0,1)
                                                       ;
                                                       		};
                                                       0;
                                                       (*__csLOCALPARAM_Init_WorkStealQueue_q).elems = __cs_safe_malloc(__csLOCALPARAM_Init_WorkStealQueue_size * (sizeof(Obj *)));
                                                       		__exit__Init_WorkStealQueue_1: GUARD(0,1)
                                                       ;
                                                       	};
                                                       0;
                                                       __csLOCAL_main_i = 0;
                                                       	{
                                                       __cs_create(&__csLOCAL_main_handles[__csLOCAL_main_i], 0, Stealer_0, &__csLOCAL_main_q, 1);
                                                       	};
                                                       __csLOCAL_main_i++;
                                                       assume(!(__csLOCAL_main_i < 1));
                                                       	__exit_loop_3: GUARD(0,1)
                                                       ;
                                                       __csLOCAL_main_i = 0;
                                                       if (!(__csLOCAL_main_i < (4 / 2)))
                                                       	{
                                                       goto __exit_loop_4;
                                                       	}
                                                       	;
                                                       	{
                                                       		{
                                                       static WorkStealQueue *__csLOCALPARAM_Push_q;
tmain_1: IF(0,1,tmain_2)                               __csLOCALPARAM_Push_q = &__csLOCAL_main_q;
                                                       static Obj *__csLOCALPARAM_Push_elem;
tmain_2: IF(0,2,tmain_3)                               __csLOCALPARAM_Push_elem = &__csLOCAL_main_items[2 * __csLOCAL_main_i];
                                                       static long __csLOCAL_Push_t;
                                                       static long __retval__readV_3;
                                                       			{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_3: IF(0,3,tmain_4)                               __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_Push_q).tail;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_4: IF(0,4,tmain_5)                               __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_3 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_3_0;
                                                       				__exit__readV_3_0: GUARD(0,5)
                                                       ;
                                                       			};
                                                       __csLOCAL_Push_t = __retval__readV_3;
                                                       static _Bool __csLOCAL_Push___if_cond_4;
                                                       static long __retval__readV_4;
                                                       			{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_5: IF(0,5,tmain_6)                               __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_Push_q).head;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_6: IF(0,6,tmain_7)                               __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_4 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_4_0;
                                                       				__exit__readV_4_0: GUARD(0,7)
                                                       ;
                                                       			};
tmain_7: IF(0,7,tmain_8)                               __csLOCAL_Push___if_cond_4 = (__csLOCAL_Push_t < ((__retval__readV_4 + (*__csLOCALPARAM_Push_q).mask) + 1)) && (__csLOCAL_Push_t < (*__csLOCALPARAM_Push_q).MaxSize);
                                                       if (__csLOCAL_Push___if_cond_4)
                                                       			{
tmain_8: IF(0,8,tmain_9)                               (*__csLOCALPARAM_Push_q).elems[__csLOCAL_Push_t & (*__csLOCALPARAM_Push_q).mask] = __csLOCALPARAM_Push_elem;
                                                       				{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_9: IF(0,9,tmain_10)                              __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_Push_q).tail;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_Push_t + 1;
tmain_10: IF(0,10,tmain_11)                            __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       					__exit__writeV_5_0: GUARD(0,11)
                                                       ;
                                                       				};
                                                       0;
                                                       			}
                                                       			else
                                                       			{ GUARD(0,11)
                                                       				{
                                                       static WorkStealQueue *__csLOCALPARAM_SyncPush_q;
tmain_11: IF(0,11,tmain_12)                            __csLOCALPARAM_SyncPush_q = __csLOCALPARAM_Push_q;
                                                       static Obj *__csLOCALPARAM_SyncPush_elem;
tmain_12: IF(0,12,tmain_13)                            __csLOCALPARAM_SyncPush_elem = __csLOCALPARAM_Push_elem;
tmain_13: IF(0,13,tmain_14)                            __cs_mutex_lock_MACRO((*__csLOCALPARAM_SyncPush_q).cs);
                                                       static long __csLOCAL_SyncPush_h;
                                                       static long __retval__readV_5;
                                                       					{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_14: IF(0,14,tmain_15)                            __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_SyncPush_q).head;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_15: IF(0,15,tmain_16)                            __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_5 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_5_0;
                                                       						__exit__readV_5_0: GUARD(0,16)
                                                       ;
                                                       					};
                                                       __csLOCAL_SyncPush_h = __retval__readV_5;
                                                       static long __csLOCAL_SyncPush_count;
                                                       static long __retval__readV_6;
                                                       					{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_16: IF(0,16,tmain_17)                            __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_SyncPush_q).tail;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_17: IF(0,17,tmain_18)                            __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_6 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_6_0;
                                                       						__exit__readV_6_0: GUARD(0,18)
                                                       ;
                                                       					};
                                                       __csLOCAL_SyncPush_count = __retval__readV_6 - __csLOCAL_SyncPush_h;
tmain_18: IF(0,18,tmain_19)                            __csLOCAL_SyncPush_h = __csLOCAL_SyncPush_h & (*__csLOCALPARAM_SyncPush_q).mask;
                                                       					{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_19: IF(0,19,tmain_20)                            __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_SyncPush_q).head;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_SyncPush_h;
tmain_20: IF(0,20,tmain_21)                            __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       						__exit__writeV_6_0: GUARD(0,21)
                                                       ;
                                                       					};
                                                       0;
                                                       					{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_21: IF(0,21,tmain_22)                            __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_SyncPush_q).tail;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_SyncPush_h + __csLOCAL_SyncPush_count;
tmain_22: IF(0,22,tmain_23)                            __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       						__exit__writeV_7_0: GUARD(0,23)
                                                       ;
                                                       					};
                                                       0;
tmain_23: IF(0,23,tmain_24)                            if (__csLOCAL_SyncPush_count >= (*__csLOCALPARAM_SyncPush_q).mask)
                                                       					{
                                                       static long __csLOCAL_SyncPush_newsize;
tmain_24: IF(0,24,tmain_25)                            __csLOCAL_SyncPush_newsize = (*__csLOCALPARAM_SyncPush_q).mask == 0 ? (*__csLOCALPARAM_SyncPush_q).InitialSize : 2 * ((*__csLOCALPARAM_SyncPush_q).mask + 1);
tmain_25: IF(0,25,tmain_26)                            assert(__csLOCAL_SyncPush_newsize < (*__csLOCALPARAM_SyncPush_q).MaxSize);
                                                       static Obj **__csLOCAL_SyncPush_newtasks;
tmain_26: IF(0,26,tmain_27)                            __csLOCAL_SyncPush_newtasks = __cs_safe_malloc(__csLOCAL_SyncPush_newsize * (sizeof(Obj *)));
                                                       static long __csLOCAL_SyncPush_i;
                                                       __csLOCAL_SyncPush_i = 0;
                                                       if (!(__csLOCAL_SyncPush_i < __csLOCAL_SyncPush_count))
                                                       						{
                                                       goto __exit_loop_5;
                                                       						}
                                                       						;
                                                       						{
tmain_27: IF(0,27,tmain_28)                            __csLOCAL_SyncPush_newtasks[__csLOCAL_SyncPush_i] = (*__csLOCALPARAM_SyncPush_q).elems[(__csLOCAL_SyncPush_h + __csLOCAL_SyncPush_i) & (*__csLOCALPARAM_SyncPush_q).mask];
                                                       						};
                                                       __csLOCAL_SyncPush_i++;
                                                       if (!(__csLOCAL_SyncPush_i < __csLOCAL_SyncPush_count))
                                                       						{
                                                       goto __exit_loop_5;
                                                       						}
                                                       						;
                                                       						{
tmain_28: IF(0,28,tmain_29)                            __csLOCAL_SyncPush_newtasks[__csLOCAL_SyncPush_i] = (*__csLOCALPARAM_SyncPush_q).elems[(__csLOCAL_SyncPush_h + __csLOCAL_SyncPush_i) & (*__csLOCALPARAM_SyncPush_q).mask];
                                                       						};
                                                       __csLOCAL_SyncPush_i++;
                                                       assume(!(__csLOCAL_SyncPush_i < __csLOCAL_SyncPush_count));
                                                       						__exit_loop_5: GUARD(0,29)
                                                       ;
tmain_29: IF(0,29,tmain_30)                            free((*__csLOCALPARAM_SyncPush_q).elems);
tmain_30: IF(0,30,tmain_31)                            (*__csLOCALPARAM_SyncPush_q).elems = __csLOCAL_SyncPush_newtasks;
tmain_31: IF(0,31,tmain_32)                            (*__csLOCALPARAM_SyncPush_q).mask = __csLOCAL_SyncPush_newsize - 1;
                                                       						{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_32: IF(0,32,tmain_33)                            __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_SyncPush_q).head;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = 0;
tmain_33: IF(0,33,tmain_34)                            __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       							__exit__writeV_8_0: GUARD(0,34)
                                                       ;
                                                       						};
                                                       0;
                                                       						{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_34: IF(0,34,tmain_35)                            __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_SyncPush_q).tail;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_SyncPush_count;
tmain_35: IF(0,35,tmain_36)                            __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       							__exit__writeV_9_0: GUARD(0,36)
                                                       ;
                                                       						};
                                                       0;
                                                       					}
                                                       					GUARD(0,36);
tmain_36: IF(0,36,tmain_37)                            assert(__csLOCAL_SyncPush_count < (*__csLOCALPARAM_SyncPush_q).mask);
                                                       static long __csLOCAL_SyncPush_t;
                                                       static long __retval__readV_7;
                                                       					{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_37: IF(0,37,tmain_38)                            __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_SyncPush_q).tail;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_38: IF(0,38,tmain_39)                            __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_7 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_7_0;
                                                       						__exit__readV_7_0: GUARD(0,39)
                                                       ;
                                                       					};
                                                       __csLOCAL_SyncPush_t = __retval__readV_7;
tmain_39: IF(0,39,tmain_40)                            (*__csLOCALPARAM_SyncPush_q).elems[__csLOCAL_SyncPush_t & (*__csLOCALPARAM_SyncPush_q).mask] = __csLOCALPARAM_SyncPush_elem;
                                                       					{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_40: IF(0,40,tmain_41)                            __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_SyncPush_q).tail;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_SyncPush_t + 1;
tmain_41: IF(0,41,tmain_42)                            __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       						__exit__writeV_10_0: GUARD(0,42)
                                                       ;
                                                       					};
                                                       0;
tmain_42: IF(0,42,tmain_43)                            __cs_mutex_unlock_MACRO((*__csLOCALPARAM_SyncPush_q).cs);
                                                       					__exit__SyncPush_1_0: GUARD(0,43)
                                                       ;
                                                       				};
                                                       0;
                                                       			}
                                                       			GUARD(0,43);
                                                       			__exit__Push_1_0: GUARD(0,43)
                                                       ;
                                                       		};
                                                       0;
                                                       		{
                                                       static WorkStealQueue *__csLOCALPARAM_Push_q;
tmain_43: IF(0,43,tmain_44)                            __csLOCALPARAM_Push_q = &__csLOCAL_main_q;
                                                       static Obj *__csLOCALPARAM_Push_elem;
tmain_44: IF(0,44,tmain_45)                            __csLOCALPARAM_Push_elem = &__csLOCAL_main_items[(2 * __csLOCAL_main_i) + 1];
                                                       static long __csLOCAL_Push_t;
                                                       static long __retval__readV_8;
                                                       			{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_45: IF(0,45,tmain_46)                            __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_Push_q).tail;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_46: IF(0,46,tmain_47)                            __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_8 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_8_0;
                                                       				__exit__readV_8_0: GUARD(0,47)
                                                       ;
                                                       			};
                                                       __csLOCAL_Push_t = __retval__readV_8;
                                                       static _Bool __csLOCAL_Push___if_cond_4;
                                                       static long __retval__readV_9;
                                                       			{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_47: IF(0,47,tmain_48)                            __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_Push_q).head;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_48: IF(0,48,tmain_49)                            __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_9 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_9_0;
                                                       				__exit__readV_9_0: GUARD(0,49)
                                                       ;
                                                       			};
tmain_49: IF(0,49,tmain_50)                            __csLOCAL_Push___if_cond_4 = (__csLOCAL_Push_t < ((__retval__readV_9 + (*__csLOCALPARAM_Push_q).mask) + 1)) && (__csLOCAL_Push_t < (*__csLOCALPARAM_Push_q).MaxSize);
                                                       if (__csLOCAL_Push___if_cond_4)
                                                       			{
tmain_50: IF(0,50,tmain_51)                            (*__csLOCALPARAM_Push_q).elems[__csLOCAL_Push_t & (*__csLOCALPARAM_Push_q).mask] = __csLOCALPARAM_Push_elem;
                                                       				{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_51: IF(0,51,tmain_52)                            __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_Push_q).tail;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_Push_t + 1;
tmain_52: IF(0,52,tmain_53)                            __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       					__exit__writeV_11_0: GUARD(0,53)
                                                       ;
                                                       				};
                                                       0;
                                                       			}
                                                       			else
                                                       			{ GUARD(0,53)
                                                       				{
                                                       static WorkStealQueue *__csLOCALPARAM_SyncPush_q;
tmain_53: IF(0,53,tmain_54)                            __csLOCALPARAM_SyncPush_q = __csLOCALPARAM_Push_q;
                                                       static Obj *__csLOCALPARAM_SyncPush_elem;
tmain_54: IF(0,54,tmain_55)                            __csLOCALPARAM_SyncPush_elem = __csLOCALPARAM_Push_elem;
tmain_55: IF(0,55,tmain_56)                            __cs_mutex_lock_MACRO((*__csLOCALPARAM_SyncPush_q).cs);
                                                       static long __csLOCAL_SyncPush_h;
                                                       static long __retval__readV_10;
                                                       					{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_56: IF(0,56,tmain_57)                            __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_SyncPush_q).head;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_57: IF(0,57,tmain_58)                            __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_10 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_10_0;
                                                       						__exit__readV_10_0: GUARD(0,58)
                                                       ;
                                                       					};
                                                       __csLOCAL_SyncPush_h = __retval__readV_10;
                                                       static long __csLOCAL_SyncPush_count;
                                                       static long __retval__readV_11;
                                                       					{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_58: IF(0,58,tmain_59)                            __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_SyncPush_q).tail;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_59: IF(0,59,tmain_60)                            __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_11 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_11_0;
                                                       						__exit__readV_11_0: GUARD(0,60)
                                                       ;
                                                       					};
                                                       __csLOCAL_SyncPush_count = __retval__readV_11 - __csLOCAL_SyncPush_h;
tmain_60: IF(0,60,tmain_61)                            __csLOCAL_SyncPush_h = __csLOCAL_SyncPush_h & (*__csLOCALPARAM_SyncPush_q).mask;
                                                       					{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_61: IF(0,61,tmain_62)                            __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_SyncPush_q).head;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_SyncPush_h;
tmain_62: IF(0,62,tmain_63)                            __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       						__exit__writeV_12_0: GUARD(0,63)
                                                       ;
                                                       					};
                                                       0;
                                                       					{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_63: IF(0,63,tmain_64)                            __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_SyncPush_q).tail;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_SyncPush_h + __csLOCAL_SyncPush_count;
tmain_64: IF(0,64,tmain_65)                            __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       						__exit__writeV_13_0: GUARD(0,65)
                                                       ;
                                                       					};
                                                       0;
tmain_65: IF(0,65,tmain_66)                            if (__csLOCAL_SyncPush_count >= (*__csLOCALPARAM_SyncPush_q).mask)
                                                       					{
                                                       static long __csLOCAL_SyncPush_newsize;
tmain_66: IF(0,66,tmain_67)                            __csLOCAL_SyncPush_newsize = (*__csLOCALPARAM_SyncPush_q).mask == 0 ? (*__csLOCALPARAM_SyncPush_q).InitialSize : 2 * ((*__csLOCALPARAM_SyncPush_q).mask + 1);
tmain_67: IF(0,67,tmain_68)                            assert(__csLOCAL_SyncPush_newsize < (*__csLOCALPARAM_SyncPush_q).MaxSize);
                                                       static Obj **__csLOCAL_SyncPush_newtasks;
tmain_68: IF(0,68,tmain_69)                            __csLOCAL_SyncPush_newtasks = __cs_safe_malloc(__csLOCAL_SyncPush_newsize * (sizeof(Obj *)));
                                                       static long __csLOCAL_SyncPush_i;
                                                       __csLOCAL_SyncPush_i = 0;
                                                       if (!(__csLOCAL_SyncPush_i < __csLOCAL_SyncPush_count))
                                                       						{
                                                       goto __exit_loop_6;
                                                       						}
                                                       						;
                                                       						{
tmain_69: IF(0,69,tmain_70)                            __csLOCAL_SyncPush_newtasks[__csLOCAL_SyncPush_i] = (*__csLOCALPARAM_SyncPush_q).elems[(__csLOCAL_SyncPush_h + __csLOCAL_SyncPush_i) & (*__csLOCALPARAM_SyncPush_q).mask];
                                                       						};
                                                       __csLOCAL_SyncPush_i++;
                                                       if (!(__csLOCAL_SyncPush_i < __csLOCAL_SyncPush_count))
                                                       						{
                                                       goto __exit_loop_6;
                                                       						}
                                                       						;
                                                       						{
tmain_70: IF(0,70,tmain_71)                            __csLOCAL_SyncPush_newtasks[__csLOCAL_SyncPush_i] = (*__csLOCALPARAM_SyncPush_q).elems[(__csLOCAL_SyncPush_h + __csLOCAL_SyncPush_i) & (*__csLOCALPARAM_SyncPush_q).mask];
                                                       						};
                                                       __csLOCAL_SyncPush_i++;
                                                       assume(!(__csLOCAL_SyncPush_i < __csLOCAL_SyncPush_count));
                                                       						__exit_loop_6: GUARD(0,71)
                                                       ;
tmain_71: IF(0,71,tmain_72)                            free((*__csLOCALPARAM_SyncPush_q).elems);
tmain_72: IF(0,72,tmain_73)                            (*__csLOCALPARAM_SyncPush_q).elems = __csLOCAL_SyncPush_newtasks;
tmain_73: IF(0,73,tmain_74)                            (*__csLOCALPARAM_SyncPush_q).mask = __csLOCAL_SyncPush_newsize - 1;
                                                       						{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_74: IF(0,74,tmain_75)                            __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_SyncPush_q).head;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = 0;
tmain_75: IF(0,75,tmain_76)                            __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       							__exit__writeV_14_0: GUARD(0,76)
                                                       ;
                                                       						};
                                                       0;
                                                       						{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_76: IF(0,76,tmain_77)                            __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_SyncPush_q).tail;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_SyncPush_count;
tmain_77: IF(0,77,tmain_78)                            __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       							__exit__writeV_15_0: GUARD(0,78)
                                                       ;
                                                       						};
                                                       0;
                                                       					}
                                                       					GUARD(0,78);
tmain_78: IF(0,78,tmain_79)                            assert(__csLOCAL_SyncPush_count < (*__csLOCALPARAM_SyncPush_q).mask);
                                                       static long __csLOCAL_SyncPush_t;
                                                       static long __retval__readV_12;
                                                       					{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_79: IF(0,79,tmain_80)                            __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_SyncPush_q).tail;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_80: IF(0,80,tmain_81)                            __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_12 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_12_0;
                                                       						__exit__readV_12_0: GUARD(0,81)
                                                       ;
                                                       					};
                                                       __csLOCAL_SyncPush_t = __retval__readV_12;
tmain_81: IF(0,81,tmain_82)                            (*__csLOCALPARAM_SyncPush_q).elems[__csLOCAL_SyncPush_t & (*__csLOCALPARAM_SyncPush_q).mask] = __csLOCALPARAM_SyncPush_elem;
                                                       					{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_82: IF(0,82,tmain_83)                            __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_SyncPush_q).tail;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_SyncPush_t + 1;
tmain_83: IF(0,83,tmain_84)                            __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       						__exit__writeV_16_0: GUARD(0,84)
                                                       ;
                                                       					};
                                                       0;
tmain_84: IF(0,84,tmain_85)                            __cs_mutex_unlock_MACRO((*__csLOCALPARAM_SyncPush_q).cs);
                                                       					__exit__SyncPush_2_0: GUARD(0,85)
                                                       ;
                                                       				};
                                                       0;
                                                       			}
                                                       			GUARD(0,85);
                                                       			__exit__Push_2_0: GUARD(0,85)
                                                       ;
                                                       		};
                                                       0;
                                                       static Obj *__csLOCAL_main_r;
                                                       static _Bool __csLOCAL_main___if_cond_6;
                                                       static _Bool __retval__Pop_1;
                                                       		{
                                                       static WorkStealQueue *__csLOCALPARAM_Pop_q;
tmain_85: IF(0,85,tmain_86)                            __csLOCALPARAM_Pop_q = &__csLOCAL_main_q;
                                                       static Obj **__csLOCALPARAM_Pop_result;
tmain_86: IF(0,86,tmain_87)                            __csLOCALPARAM_Pop_result = &__csLOCAL_main_r;
                                                       static long __csLOCAL_Pop_t;
                                                       static long __retval__readV_13;
                                                       			{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_87: IF(0,87,tmain_88)                            __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_Pop_q).tail;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_88: IF(0,88,tmain_89)                            __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_13 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_13_0;
                                                       				__exit__readV_13_0: GUARD(0,89)
                                                       ;
                                                       			};
                                                       __csLOCAL_Pop_t = __retval__readV_13 - 1;
                                                       			{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_89: IF(0,89,tmain_90)                            __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_Pop_q).tail;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_Pop_t;
tmain_90: IF(0,90,tmain_91)                            __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       				__exit__writeV_17_0: GUARD(0,91)
                                                       ;
                                                       			};
                                                       0;
                                                       static _Bool __csLOCAL_Pop___if_cond_3;
                                                       static long __retval__readV_14;
                                                       			{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_91: IF(0,91,tmain_92)                            __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_Pop_q).head;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_92: IF(0,92,tmain_93)                            __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_14 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_14_0;
                                                       				__exit__readV_14_0: GUARD(0,93)
                                                       ;
                                                       			};
                                                       __csLOCAL_Pop___if_cond_3 = __retval__readV_14 <= __csLOCAL_Pop_t;
                                                       if (__csLOCAL_Pop___if_cond_3)
                                                       			{
tmain_93: IF(0,93,tmain_94)                            *__csLOCALPARAM_Pop_result = (*__csLOCALPARAM_Pop_q).elems[__csLOCAL_Pop_t & (*__csLOCALPARAM_Pop_q).mask];
                                                       __retval__Pop_1 = 1;
                                                       goto __exit__Pop_1_0;
                                                       			}
                                                       			else
                                                       			{ GUARD(0,94)
                                                       				{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_94: IF(0,94,tmain_95)                            __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_Pop_q).tail;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_Pop_t + 1;
tmain_95: IF(0,95,tmain_96)                            __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       					__exit__writeV_18_0: GUARD(0,96)
                                                       ;
                                                       				};
                                                       0;
                                                       static _Bool __retval__SyncPop_1;
                                                       				{
                                                       static WorkStealQueue *__csLOCALPARAM_SyncPop_q;
tmain_96: IF(0,96,tmain_97)                            __csLOCALPARAM_SyncPop_q = __csLOCALPARAM_Pop_q;
                                                       static Obj **__csLOCALPARAM_SyncPop_result;
tmain_97: IF(0,97,tmain_98)                            __csLOCALPARAM_SyncPop_result = __csLOCALPARAM_Pop_result;
                                                       static _Bool __csLOCAL_SyncPop_found;
tmain_98: IF(0,98,tmain_99)                            __cs_mutex_lock_MACRO((*__csLOCALPARAM_SyncPop_q).cs);
                                                       static long __csLOCAL_SyncPop_t;
                                                       static long __retval__readV_15;
                                                       					{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_99: IF(0,99,tmain_100)                           __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_SyncPop_q).tail;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_100: IF(0,100,tmain_101)                         __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_15 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_15_0;
                                                       						__exit__readV_15_0: GUARD(0,101)
                                                       ;
                                                       					};
                                                       __csLOCAL_SyncPop_t = __retval__readV_15 - 1;
                                                       					{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_101: IF(0,101,tmain_102)                         __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_SyncPop_q).tail;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_SyncPop_t;
tmain_102: IF(0,102,tmain_103)                         __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       						__exit__writeV_19_0: GUARD(0,103)
                                                       ;
                                                       					};
                                                       0;
                                                       static _Bool __csLOCAL_SyncPop___if_cond_1;
                                                       static long __retval__readV_16;
                                                       					{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_103: IF(0,103,tmain_104)                         __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_SyncPop_q).head;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_104: IF(0,104,tmain_105)                         __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_16 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_16_0;
                                                       						__exit__readV_16_0: GUARD(0,105)
                                                       ;
                                                       					};
                                                       __csLOCAL_SyncPop___if_cond_1 = __retval__readV_16 <= __csLOCAL_SyncPop_t;
                                                       if (__csLOCAL_SyncPop___if_cond_1)
                                                       					{
tmain_105: IF(0,105,tmain_106)                         *__csLOCALPARAM_SyncPop_result = (*__csLOCALPARAM_SyncPop_q).elems[__csLOCAL_SyncPop_t & (*__csLOCALPARAM_SyncPop_q).mask];
                                                       __csLOCAL_SyncPop_found = 1;
                                                       					}
                                                       					else
                                                       					{ GUARD(0,106)
                                                       						{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_106: IF(0,106,tmain_107)                         __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_SyncPop_q).tail;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_SyncPop_t + 1;
tmain_107: IF(0,107,tmain_108)                         __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       							__exit__writeV_20_0: GUARD(0,108)
                                                       ;
                                                       						};
                                                       0;
                                                       __csLOCAL_SyncPop_found = 0;
                                                       					}
                                                       					GUARD(0,108);
                                                       static _Bool __csLOCAL_SyncPop___if_cond_2;
                                                       static long __retval__readV_17;
                                                       					{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_108: IF(0,108,tmain_109)                         __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_SyncPop_q).head;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_109: IF(0,109,tmain_110)                         __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_17 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_17_0;
                                                       						__exit__readV_17_0: GUARD(0,110)
                                                       ;
                                                       					};
                                                       __csLOCAL_SyncPop___if_cond_2 = __retval__readV_17 > __csLOCAL_SyncPop_t;
                                                       if (__csLOCAL_SyncPop___if_cond_2)
                                                       					{
                                                       						{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_110: IF(0,110,tmain_111)                         __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_SyncPop_q).head;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = 0;
tmain_111: IF(0,111,tmain_112)                         __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       							__exit__writeV_21_0: GUARD(0,112)
                                                       ;
                                                       						};
                                                       0;
                                                       						{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_112: IF(0,112,tmain_113)                         __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_SyncPop_q).tail;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = 0;
tmain_113: IF(0,113,tmain_114)                         __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       							__exit__writeV_22_0: GUARD(0,114)
                                                       ;
                                                       						};
                                                       0;
                                                       __csLOCAL_SyncPop_found = 0;
                                                       					}
                                                       					GUARD(0,114);
tmain_114: IF(0,114,tmain_115)                         __cs_mutex_unlock_MACRO((*__csLOCALPARAM_SyncPop_q).cs);
                                                       __retval__SyncPop_1 = __csLOCAL_SyncPop_found;
                                                       goto __exit__SyncPop_1_0;
                                                       					__exit__SyncPop_1_0: GUARD(0,115)
                                                       ;
                                                       				};
                                                       __retval__Pop_1 = __retval__SyncPop_1;
                                                       goto __exit__Pop_1_0;
                                                       			}
                                                       			GUARD(0,115);
                                                       			__exit__Pop_1_0: GUARD(0,115)
                                                       ;
                                                       		};
                                                       __csLOCAL_main___if_cond_6 = __retval__Pop_1;
                                                       if (__csLOCAL_main___if_cond_6)
                                                       		{
                                                       			{
                                                       static Obj *__csLOCALPARAM_Operation_r;
tmain_115: IF(0,115,tmain_116)                         __csLOCALPARAM_Operation_r = __csLOCAL_main_r;
tmain_116: IF(0,116,tmain_117)                         (*__csLOCALPARAM_Operation_r).field++;
                                                       				__exit__Operation_2_0: GUARD(0,117)
                                                       ;
                                                       			};
                                                       0;
                                                       		}
                                                       		GUARD(0,117);
                                                       	};
                                                       __csLOCAL_main_i++;
                                                       if (!(__csLOCAL_main_i < (4 / 2)))
                                                       	{
                                                       goto __exit_loop_4;
                                                       	}
                                                       	;
                                                       	{
                                                       		{
                                                       static WorkStealQueue *__csLOCALPARAM_Push_q;
tmain_117: IF(0,117,tmain_118)                         __csLOCALPARAM_Push_q = &__csLOCAL_main_q;
                                                       static Obj *__csLOCALPARAM_Push_elem;
tmain_118: IF(0,118,tmain_119)                         __csLOCALPARAM_Push_elem = &__csLOCAL_main_items[2 * __csLOCAL_main_i];
                                                       static long __csLOCAL_Push_t;
                                                       static long __retval__readV_3;
                                                       			{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_119: IF(0,119,tmain_120)                         __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_Push_q).tail;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_120: IF(0,120,tmain_121)                         __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_3 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_3_1;
                                                       				__exit__readV_3_1: GUARD(0,121)
                                                       ;
                                                       			};
                                                       __csLOCAL_Push_t = __retval__readV_3;
                                                       static _Bool __csLOCAL_Push___if_cond_4;
                                                       static long __retval__readV_4;
                                                       			{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_121: IF(0,121,tmain_122)                         __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_Push_q).head;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_122: IF(0,122,tmain_123)                         __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_4 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_4_1;
                                                       				__exit__readV_4_1: GUARD(0,123)
                                                       ;
                                                       			};
tmain_123: IF(0,123,tmain_124)                         __csLOCAL_Push___if_cond_4 = (__csLOCAL_Push_t < ((__retval__readV_4 + (*__csLOCALPARAM_Push_q).mask) + 1)) && (__csLOCAL_Push_t < (*__csLOCALPARAM_Push_q).MaxSize);
                                                       if (__csLOCAL_Push___if_cond_4)
                                                       			{
tmain_124: IF(0,124,tmain_125)                         (*__csLOCALPARAM_Push_q).elems[__csLOCAL_Push_t & (*__csLOCALPARAM_Push_q).mask] = __csLOCALPARAM_Push_elem;
                                                       				{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_125: IF(0,125,tmain_126)                         __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_Push_q).tail;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_Push_t + 1;
tmain_126: IF(0,126,tmain_127)                         __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       					__exit__writeV_5_1: GUARD(0,127)
                                                       ;
                                                       				};
                                                       0;
                                                       			}
                                                       			else
                                                       			{ GUARD(0,127)
                                                       				{
                                                       static WorkStealQueue *__csLOCALPARAM_SyncPush_q;
tmain_127: IF(0,127,tmain_128)                         __csLOCALPARAM_SyncPush_q = __csLOCALPARAM_Push_q;
                                                       static Obj *__csLOCALPARAM_SyncPush_elem;
tmain_128: IF(0,128,tmain_129)                         __csLOCALPARAM_SyncPush_elem = __csLOCALPARAM_Push_elem;
tmain_129: IF(0,129,tmain_130)                         __cs_mutex_lock_MACRO((*__csLOCALPARAM_SyncPush_q).cs);
                                                       static long __csLOCAL_SyncPush_h;
                                                       static long __retval__readV_5;
                                                       					{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_130: IF(0,130,tmain_131)                         __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_SyncPush_q).head;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_131: IF(0,131,tmain_132)                         __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_5 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_5_1;
                                                       						__exit__readV_5_1: GUARD(0,132)
                                                       ;
                                                       					};
                                                       __csLOCAL_SyncPush_h = __retval__readV_5;
                                                       static long __csLOCAL_SyncPush_count;
                                                       static long __retval__readV_6;
                                                       					{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_132: IF(0,132,tmain_133)                         __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_SyncPush_q).tail;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_133: IF(0,133,tmain_134)                         __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_6 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_6_1;
                                                       						__exit__readV_6_1: GUARD(0,134)
                                                       ;
                                                       					};
                                                       __csLOCAL_SyncPush_count = __retval__readV_6 - __csLOCAL_SyncPush_h;
tmain_134: IF(0,134,tmain_135)                         __csLOCAL_SyncPush_h = __csLOCAL_SyncPush_h & (*__csLOCALPARAM_SyncPush_q).mask;
                                                       					{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_135: IF(0,135,tmain_136)                         __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_SyncPush_q).head;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_SyncPush_h;
tmain_136: IF(0,136,tmain_137)                         __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       						__exit__writeV_6_1: GUARD(0,137)
                                                       ;
                                                       					};
                                                       0;
                                                       					{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_137: IF(0,137,tmain_138)                         __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_SyncPush_q).tail;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_SyncPush_h + __csLOCAL_SyncPush_count;
tmain_138: IF(0,138,tmain_139)                         __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       						__exit__writeV_7_1: GUARD(0,139)
                                                       ;
                                                       					};
                                                       0;
tmain_139: IF(0,139,tmain_140)                         if (__csLOCAL_SyncPush_count >= (*__csLOCALPARAM_SyncPush_q).mask)
                                                       					{
                                                       static long __csLOCAL_SyncPush_newsize;
tmain_140: IF(0,140,tmain_141)                         __csLOCAL_SyncPush_newsize = (*__csLOCALPARAM_SyncPush_q).mask == 0 ? (*__csLOCALPARAM_SyncPush_q).InitialSize : 2 * ((*__csLOCALPARAM_SyncPush_q).mask + 1);
tmain_141: IF(0,141,tmain_142)                         assert(__csLOCAL_SyncPush_newsize < (*__csLOCALPARAM_SyncPush_q).MaxSize);
                                                       static Obj **__csLOCAL_SyncPush_newtasks;
tmain_142: IF(0,142,tmain_143)                         __csLOCAL_SyncPush_newtasks = __cs_safe_malloc(__csLOCAL_SyncPush_newsize * (sizeof(Obj *)));
                                                       static long __csLOCAL_SyncPush_i;
                                                       __csLOCAL_SyncPush_i = 0;
                                                       if (!(__csLOCAL_SyncPush_i < __csLOCAL_SyncPush_count))
                                                       						{
                                                       goto __exit_loop_7;
                                                       						}
                                                       						;
                                                       						{
tmain_143: IF(0,143,tmain_144)                         __csLOCAL_SyncPush_newtasks[__csLOCAL_SyncPush_i] = (*__csLOCALPARAM_SyncPush_q).elems[(__csLOCAL_SyncPush_h + __csLOCAL_SyncPush_i) & (*__csLOCALPARAM_SyncPush_q).mask];
                                                       						};
                                                       __csLOCAL_SyncPush_i++;
                                                       if (!(__csLOCAL_SyncPush_i < __csLOCAL_SyncPush_count))
                                                       						{
                                                       goto __exit_loop_7;
                                                       						}
                                                       						;
                                                       						{
tmain_144: IF(0,144,tmain_145)                         __csLOCAL_SyncPush_newtasks[__csLOCAL_SyncPush_i] = (*__csLOCALPARAM_SyncPush_q).elems[(__csLOCAL_SyncPush_h + __csLOCAL_SyncPush_i) & (*__csLOCALPARAM_SyncPush_q).mask];
                                                       						};
                                                       __csLOCAL_SyncPush_i++;
                                                       assume(!(__csLOCAL_SyncPush_i < __csLOCAL_SyncPush_count));
                                                       						__exit_loop_7: GUARD(0,145)
                                                       ;
tmain_145: IF(0,145,tmain_146)                         free((*__csLOCALPARAM_SyncPush_q).elems);
tmain_146: IF(0,146,tmain_147)                         (*__csLOCALPARAM_SyncPush_q).elems = __csLOCAL_SyncPush_newtasks;
tmain_147: IF(0,147,tmain_148)                         (*__csLOCALPARAM_SyncPush_q).mask = __csLOCAL_SyncPush_newsize - 1;
                                                       						{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_148: IF(0,148,tmain_149)                         __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_SyncPush_q).head;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = 0;
tmain_149: IF(0,149,tmain_150)                         __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       							__exit__writeV_8_1: GUARD(0,150)
                                                       ;
                                                       						};
                                                       0;
                                                       						{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_150: IF(0,150,tmain_151)                         __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_SyncPush_q).tail;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_SyncPush_count;
tmain_151: IF(0,151,tmain_152)                         __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       							__exit__writeV_9_1: GUARD(0,152)
                                                       ;
                                                       						};
                                                       0;
                                                       					}
                                                       					GUARD(0,152);
tmain_152: IF(0,152,tmain_153)                         assert(__csLOCAL_SyncPush_count < (*__csLOCALPARAM_SyncPush_q).mask);
                                                       static long __csLOCAL_SyncPush_t;
                                                       static long __retval__readV_7;
                                                       					{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_153: IF(0,153,tmain_154)                         __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_SyncPush_q).tail;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_154: IF(0,154,tmain_155)                         __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_7 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_7_1;
                                                       						__exit__readV_7_1: GUARD(0,155)
                                                       ;
                                                       					};
                                                       __csLOCAL_SyncPush_t = __retval__readV_7;
tmain_155: IF(0,155,tmain_156)                         (*__csLOCALPARAM_SyncPush_q).elems[__csLOCAL_SyncPush_t & (*__csLOCALPARAM_SyncPush_q).mask] = __csLOCALPARAM_SyncPush_elem;
                                                       					{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_156: IF(0,156,tmain_157)                         __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_SyncPush_q).tail;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_SyncPush_t + 1;
tmain_157: IF(0,157,tmain_158)                         __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       						__exit__writeV_10_1: GUARD(0,158)
                                                       ;
                                                       					};
                                                       0;
tmain_158: IF(0,158,tmain_159)                         __cs_mutex_unlock_MACRO((*__csLOCALPARAM_SyncPush_q).cs);
                                                       					__exit__SyncPush_1_1: GUARD(0,159)
                                                       ;
                                                       				};
                                                       0;
                                                       			}
                                                       			GUARD(0,159);
                                                       			__exit__Push_1_1: GUARD(0,159)
                                                       ;
                                                       		};
                                                       0;
                                                       		{
                                                       static WorkStealQueue *__csLOCALPARAM_Push_q;
tmain_159: IF(0,159,tmain_160)                         __csLOCALPARAM_Push_q = &__csLOCAL_main_q;
                                                       static Obj *__csLOCALPARAM_Push_elem;
tmain_160: IF(0,160,tmain_161)                         __csLOCALPARAM_Push_elem = &__csLOCAL_main_items[(2 * __csLOCAL_main_i) + 1];
                                                       static long __csLOCAL_Push_t;
                                                       static long __retval__readV_8;
                                                       			{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_161: IF(0,161,tmain_162)                         __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_Push_q).tail;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_162: IF(0,162,tmain_163)                         __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_8 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_8_1;
                                                       				__exit__readV_8_1: GUARD(0,163)
                                                       ;
                                                       			};
                                                       __csLOCAL_Push_t = __retval__readV_8;
                                                       static _Bool __csLOCAL_Push___if_cond_4;
                                                       static long __retval__readV_9;
                                                       			{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_163: IF(0,163,tmain_164)                         __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_Push_q).head;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_164: IF(0,164,tmain_165)                         __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_9 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_9_1;
                                                       				__exit__readV_9_1: GUARD(0,165)
                                                       ;
                                                       			};
tmain_165: IF(0,165,tmain_166)                         __csLOCAL_Push___if_cond_4 = (__csLOCAL_Push_t < ((__retval__readV_9 + (*__csLOCALPARAM_Push_q).mask) + 1)) && (__csLOCAL_Push_t < (*__csLOCALPARAM_Push_q).MaxSize);
                                                       if (__csLOCAL_Push___if_cond_4)
                                                       			{
tmain_166: IF(0,166,tmain_167)                         (*__csLOCALPARAM_Push_q).elems[__csLOCAL_Push_t & (*__csLOCALPARAM_Push_q).mask] = __csLOCALPARAM_Push_elem;
                                                       				{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_167: IF(0,167,tmain_168)                         __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_Push_q).tail;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_Push_t + 1;
tmain_168: IF(0,168,tmain_169)                         __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       					__exit__writeV_11_1: GUARD(0,169)
                                                       ;
                                                       				};
                                                       0;
                                                       			}
                                                       			else
                                                       			{ GUARD(0,169)
                                                       				{
                                                       static WorkStealQueue *__csLOCALPARAM_SyncPush_q;
tmain_169: IF(0,169,tmain_170)                         __csLOCALPARAM_SyncPush_q = __csLOCALPARAM_Push_q;
                                                       static Obj *__csLOCALPARAM_SyncPush_elem;
tmain_170: IF(0,170,tmain_171)                         __csLOCALPARAM_SyncPush_elem = __csLOCALPARAM_Push_elem;
tmain_171: IF(0,171,tmain_172)                         __cs_mutex_lock_MACRO((*__csLOCALPARAM_SyncPush_q).cs);
                                                       static long __csLOCAL_SyncPush_h;
                                                       static long __retval__readV_10;
                                                       					{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_172: IF(0,172,tmain_173)                         __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_SyncPush_q).head;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_173: IF(0,173,tmain_174)                         __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_10 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_10_1;
                                                       						__exit__readV_10_1: GUARD(0,174)
                                                       ;
                                                       					};
                                                       __csLOCAL_SyncPush_h = __retval__readV_10;
                                                       static long __csLOCAL_SyncPush_count;
                                                       static long __retval__readV_11;
                                                       					{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_174: IF(0,174,tmain_175)                         __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_SyncPush_q).tail;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_175: IF(0,175,tmain_176)                         __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_11 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_11_1;
                                                       						__exit__readV_11_1: GUARD(0,176)
                                                       ;
                                                       					};
                                                       __csLOCAL_SyncPush_count = __retval__readV_11 - __csLOCAL_SyncPush_h;
tmain_176: IF(0,176,tmain_177)                         __csLOCAL_SyncPush_h = __csLOCAL_SyncPush_h & (*__csLOCALPARAM_SyncPush_q).mask;
                                                       					{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_177: IF(0,177,tmain_178)                         __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_SyncPush_q).head;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_SyncPush_h;
tmain_178: IF(0,178,tmain_179)                         __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       						__exit__writeV_12_1: GUARD(0,179)
                                                       ;
                                                       					};
                                                       0;
                                                       					{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_179: IF(0,179,tmain_180)                         __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_SyncPush_q).tail;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_SyncPush_h + __csLOCAL_SyncPush_count;
tmain_180: IF(0,180,tmain_181)                         __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       						__exit__writeV_13_1: GUARD(0,181)
                                                       ;
                                                       					};
                                                       0;
tmain_181: IF(0,181,tmain_182)                         if (__csLOCAL_SyncPush_count >= (*__csLOCALPARAM_SyncPush_q).mask)
                                                       					{
                                                       static long __csLOCAL_SyncPush_newsize;
tmain_182: IF(0,182,tmain_183)                         __csLOCAL_SyncPush_newsize = (*__csLOCALPARAM_SyncPush_q).mask == 0 ? (*__csLOCALPARAM_SyncPush_q).InitialSize : 2 * ((*__csLOCALPARAM_SyncPush_q).mask + 1);
tmain_183: IF(0,183,tmain_184)                         assert(__csLOCAL_SyncPush_newsize < (*__csLOCALPARAM_SyncPush_q).MaxSize);
                                                       static Obj **__csLOCAL_SyncPush_newtasks;
tmain_184: IF(0,184,tmain_185)                         __csLOCAL_SyncPush_newtasks = __cs_safe_malloc(__csLOCAL_SyncPush_newsize * (sizeof(Obj *)));
                                                       static long __csLOCAL_SyncPush_i;
                                                       __csLOCAL_SyncPush_i = 0;
                                                       if (!(__csLOCAL_SyncPush_i < __csLOCAL_SyncPush_count))
                                                       						{
                                                       goto __exit_loop_8;
                                                       						}
                                                       						;
                                                       						{
tmain_185: IF(0,185,tmain_186)                         __csLOCAL_SyncPush_newtasks[__csLOCAL_SyncPush_i] = (*__csLOCALPARAM_SyncPush_q).elems[(__csLOCAL_SyncPush_h + __csLOCAL_SyncPush_i) & (*__csLOCALPARAM_SyncPush_q).mask];
                                                       						};
                                                       __csLOCAL_SyncPush_i++;
                                                       if (!(__csLOCAL_SyncPush_i < __csLOCAL_SyncPush_count))
                                                       						{
                                                       goto __exit_loop_8;
                                                       						}
                                                       						;
                                                       						{
tmain_186: IF(0,186,tmain_187)                         __csLOCAL_SyncPush_newtasks[__csLOCAL_SyncPush_i] = (*__csLOCALPARAM_SyncPush_q).elems[(__csLOCAL_SyncPush_h + __csLOCAL_SyncPush_i) & (*__csLOCALPARAM_SyncPush_q).mask];
                                                       						};
                                                       __csLOCAL_SyncPush_i++;
                                                       assume(!(__csLOCAL_SyncPush_i < __csLOCAL_SyncPush_count));
                                                       						__exit_loop_8: GUARD(0,187)
                                                       ;
tmain_187: IF(0,187,tmain_188)                         free((*__csLOCALPARAM_SyncPush_q).elems);
tmain_188: IF(0,188,tmain_189)                         (*__csLOCALPARAM_SyncPush_q).elems = __csLOCAL_SyncPush_newtasks;
tmain_189: IF(0,189,tmain_190)                         (*__csLOCALPARAM_SyncPush_q).mask = __csLOCAL_SyncPush_newsize - 1;
                                                       						{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_190: IF(0,190,tmain_191)                         __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_SyncPush_q).head;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = 0;
tmain_191: IF(0,191,tmain_192)                         __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       							__exit__writeV_14_1: GUARD(0,192)
                                                       ;
                                                       						};
                                                       0;
                                                       						{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_192: IF(0,192,tmain_193)                         __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_SyncPush_q).tail;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_SyncPush_count;
tmain_193: IF(0,193,tmain_194)                         __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       							__exit__writeV_15_1: GUARD(0,194)
                                                       ;
                                                       						};
                                                       0;
                                                       					}
                                                       					GUARD(0,194);
tmain_194: IF(0,194,tmain_195)                         assert(__csLOCAL_SyncPush_count < (*__csLOCALPARAM_SyncPush_q).mask);
                                                       static long __csLOCAL_SyncPush_t;
                                                       static long __retval__readV_12;
                                                       					{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_195: IF(0,195,tmain_196)                         __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_SyncPush_q).tail;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_196: IF(0,196,tmain_197)                         __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_12 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_12_1;
                                                       						__exit__readV_12_1: GUARD(0,197)
                                                       ;
                                                       					};
                                                       __csLOCAL_SyncPush_t = __retval__readV_12;
tmain_197: IF(0,197,tmain_198)                         (*__csLOCALPARAM_SyncPush_q).elems[__csLOCAL_SyncPush_t & (*__csLOCALPARAM_SyncPush_q).mask] = __csLOCALPARAM_SyncPush_elem;
                                                       					{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_198: IF(0,198,tmain_199)                         __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_SyncPush_q).tail;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_SyncPush_t + 1;
tmain_199: IF(0,199,tmain_200)                         __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       						__exit__writeV_16_1: GUARD(0,200)
                                                       ;
                                                       					};
                                                       0;
tmain_200: IF(0,200,tmain_201)                         __cs_mutex_unlock_MACRO((*__csLOCALPARAM_SyncPush_q).cs);
                                                       					__exit__SyncPush_2_1: GUARD(0,201)
                                                       ;
                                                       				};
                                                       0;
                                                       			}
                                                       			GUARD(0,201);
                                                       			__exit__Push_2_1: GUARD(0,201)
                                                       ;
                                                       		};
                                                       0;
                                                       static Obj *__csLOCAL_main_r;
                                                       static _Bool __csLOCAL_main___if_cond_6;
                                                       static _Bool __retval__Pop_1;
                                                       		{
                                                       static WorkStealQueue *__csLOCALPARAM_Pop_q;
tmain_201: IF(0,201,tmain_202)                         __csLOCALPARAM_Pop_q = &__csLOCAL_main_q;
                                                       static Obj **__csLOCALPARAM_Pop_result;
tmain_202: IF(0,202,tmain_203)                         __csLOCALPARAM_Pop_result = &__csLOCAL_main_r;
                                                       static long __csLOCAL_Pop_t;
                                                       static long __retval__readV_13;
                                                       			{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_203: IF(0,203,tmain_204)                         __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_Pop_q).tail;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_204: IF(0,204,tmain_205)                         __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_13 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_13_1;
                                                       				__exit__readV_13_1: GUARD(0,205)
                                                       ;
                                                       			};
                                                       __csLOCAL_Pop_t = __retval__readV_13 - 1;
                                                       			{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_205: IF(0,205,tmain_206)                         __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_Pop_q).tail;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_Pop_t;
tmain_206: IF(0,206,tmain_207)                         __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       				__exit__writeV_17_1: GUARD(0,207)
                                                       ;
                                                       			};
                                                       0;
                                                       static _Bool __csLOCAL_Pop___if_cond_3;
                                                       static long __retval__readV_14;
                                                       			{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_207: IF(0,207,tmain_208)                         __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_Pop_q).head;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_208: IF(0,208,tmain_209)                         __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_14 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_14_1;
                                                       				__exit__readV_14_1: GUARD(0,209)
                                                       ;
                                                       			};
                                                       __csLOCAL_Pop___if_cond_3 = __retval__readV_14 <= __csLOCAL_Pop_t;
                                                       if (__csLOCAL_Pop___if_cond_3)
                                                       			{
tmain_209: IF(0,209,tmain_210)                         *__csLOCALPARAM_Pop_result = (*__csLOCALPARAM_Pop_q).elems[__csLOCAL_Pop_t & (*__csLOCALPARAM_Pop_q).mask];
                                                       __retval__Pop_1 = 1;
                                                       goto __exit__Pop_1_1;
                                                       			}
                                                       			else
                                                       			{ GUARD(0,210)
                                                       				{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_210: IF(0,210,tmain_211)                         __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_Pop_q).tail;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_Pop_t + 1;
tmain_211: IF(0,211,tmain_212)                         __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       					__exit__writeV_18_1: GUARD(0,212)
                                                       ;
                                                       				};
                                                       0;
                                                       static _Bool __retval__SyncPop_1;
                                                       				{
                                                       static WorkStealQueue *__csLOCALPARAM_SyncPop_q;
tmain_212: IF(0,212,tmain_213)                         __csLOCALPARAM_SyncPop_q = __csLOCALPARAM_Pop_q;
                                                       static Obj **__csLOCALPARAM_SyncPop_result;
tmain_213: IF(0,213,tmain_214)                         __csLOCALPARAM_SyncPop_result = __csLOCALPARAM_Pop_result;
                                                       static _Bool __csLOCAL_SyncPop_found;
tmain_214: IF(0,214,tmain_215)                         __cs_mutex_lock_MACRO((*__csLOCALPARAM_SyncPop_q).cs);
                                                       static long __csLOCAL_SyncPop_t;
                                                       static long __retval__readV_15;
                                                       					{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_215: IF(0,215,tmain_216)                         __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_SyncPop_q).tail;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_216: IF(0,216,tmain_217)                         __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_15 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_15_1;
                                                       						__exit__readV_15_1: GUARD(0,217)
                                                       ;
                                                       					};
                                                       __csLOCAL_SyncPop_t = __retval__readV_15 - 1;
                                                       					{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_217: IF(0,217,tmain_218)                         __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_SyncPop_q).tail;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_SyncPop_t;
tmain_218: IF(0,218,tmain_219)                         __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       						__exit__writeV_19_1: GUARD(0,219)
                                                       ;
                                                       					};
                                                       0;
                                                       static _Bool __csLOCAL_SyncPop___if_cond_1;
                                                       static long __retval__readV_16;
                                                       					{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_219: IF(0,219,tmain_220)                         __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_SyncPop_q).head;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_220: IF(0,220,tmain_221)                         __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_16 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_16_1;
                                                       						__exit__readV_16_1: GUARD(0,221)
                                                       ;
                                                       					};
                                                       __csLOCAL_SyncPop___if_cond_1 = __retval__readV_16 <= __csLOCAL_SyncPop_t;
                                                       if (__csLOCAL_SyncPop___if_cond_1)
                                                       					{
tmain_221: IF(0,221,tmain_222)                         *__csLOCALPARAM_SyncPop_result = (*__csLOCALPARAM_SyncPop_q).elems[__csLOCAL_SyncPop_t & (*__csLOCALPARAM_SyncPop_q).mask];
                                                       __csLOCAL_SyncPop_found = 1;
                                                       					}
                                                       					else
                                                       					{ GUARD(0,222)
                                                       						{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_222: IF(0,222,tmain_223)                         __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_SyncPop_q).tail;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_SyncPop_t + 1;
tmain_223: IF(0,223,tmain_224)                         __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       							__exit__writeV_20_1: GUARD(0,224)
                                                       ;
                                                       						};
                                                       0;
                                                       __csLOCAL_SyncPop_found = 0;
                                                       					}
                                                       					GUARD(0,224);
                                                       static _Bool __csLOCAL_SyncPop___if_cond_2;
                                                       static long __retval__readV_17;
                                                       					{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_224: IF(0,224,tmain_225)                         __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_SyncPop_q).head;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_225: IF(0,225,tmain_226)                         __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_17 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_17_1;
                                                       						__exit__readV_17_1: GUARD(0,226)
                                                       ;
                                                       					};
                                                       __csLOCAL_SyncPop___if_cond_2 = __retval__readV_17 > __csLOCAL_SyncPop_t;
                                                       if (__csLOCAL_SyncPop___if_cond_2)
                                                       					{
                                                       						{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_226: IF(0,226,tmain_227)                         __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_SyncPop_q).head;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = 0;
tmain_227: IF(0,227,tmain_228)                         __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       							__exit__writeV_21_1: GUARD(0,228)
                                                       ;
                                                       						};
                                                       0;
                                                       						{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_228: IF(0,228,tmain_229)                         __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_SyncPop_q).tail;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = 0;
tmain_229: IF(0,229,tmain_230)                         __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       							__exit__writeV_22_1: GUARD(0,230)
                                                       ;
                                                       						};
                                                       0;
                                                       __csLOCAL_SyncPop_found = 0;
                                                       					}
                                                       					GUARD(0,230);
tmain_230: IF(0,230,tmain_231)                         __cs_mutex_unlock_MACRO((*__csLOCALPARAM_SyncPop_q).cs);
                                                       __retval__SyncPop_1 = __csLOCAL_SyncPop_found;
                                                       goto __exit__SyncPop_1_1;
                                                       					__exit__SyncPop_1_1: GUARD(0,231)
                                                       ;
                                                       				};
                                                       __retval__Pop_1 = __retval__SyncPop_1;
                                                       goto __exit__Pop_1_1;
                                                       			}
                                                       			GUARD(0,231);
                                                       			__exit__Pop_1_1: GUARD(0,231)
                                                       ;
                                                       		};
                                                       __csLOCAL_main___if_cond_6 = __retval__Pop_1;
                                                       if (__csLOCAL_main___if_cond_6)
                                                       		{
                                                       			{
                                                       static Obj *__csLOCALPARAM_Operation_r;
tmain_231: IF(0,231,tmain_232)                         __csLOCALPARAM_Operation_r = __csLOCAL_main_r;
tmain_232: IF(0,232,tmain_233)                         (*__csLOCALPARAM_Operation_r).field++;
                                                       				__exit__Operation_2_1: GUARD(0,233)
                                                       ;
                                                       			};
                                                       0;
                                                       		}
                                                       		GUARD(0,233);
                                                       	};
                                                       __csLOCAL_main_i++;
                                                       assume(!(__csLOCAL_main_i < (4 / 2)));
                                                       	__exit_loop_4: GUARD(0,233)
                                                       ;
                                                       __csLOCAL_main_i = 0;
                                                       if (!(__csLOCAL_main_i < (4 / 2)))
                                                       	{
                                                       goto __exit_loop_9;
                                                       	}
                                                       	;
                                                       	{
                                                       static Obj *__csLOCAL_main_r;
                                                       static _Bool __csLOCAL_main___if_cond_7;
                                                       static _Bool __retval__Pop_2;
                                                       		{
                                                       static WorkStealQueue *__csLOCALPARAM_Pop_q;
tmain_233: IF(0,233,tmain_234)                         __csLOCALPARAM_Pop_q = &__csLOCAL_main_q;
                                                       static Obj **__csLOCALPARAM_Pop_result;
tmain_234: IF(0,234,tmain_235)                         __csLOCALPARAM_Pop_result = &__csLOCAL_main_r;
                                                       static long __csLOCAL_Pop_t;
                                                       static long __retval__readV_18;
                                                       			{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_235: IF(0,235,tmain_236)                         __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_Pop_q).tail;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_236: IF(0,236,tmain_237)                         __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_18 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_18_0;
                                                       				__exit__readV_18_0: GUARD(0,237)
                                                       ;
                                                       			};
                                                       __csLOCAL_Pop_t = __retval__readV_18 - 1;
                                                       			{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_237: IF(0,237,tmain_238)                         __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_Pop_q).tail;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_Pop_t;
tmain_238: IF(0,238,tmain_239)                         __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       				__exit__writeV_23_0: GUARD(0,239)
                                                       ;
                                                       			};
                                                       0;
                                                       static _Bool __csLOCAL_Pop___if_cond_3;
                                                       static long __retval__readV_19;
                                                       			{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_239: IF(0,239,tmain_240)                         __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_Pop_q).head;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_240: IF(0,240,tmain_241)                         __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_19 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_19_0;
                                                       				__exit__readV_19_0: GUARD(0,241)
                                                       ;
                                                       			};
                                                       __csLOCAL_Pop___if_cond_3 = __retval__readV_19 <= __csLOCAL_Pop_t;
                                                       if (__csLOCAL_Pop___if_cond_3)
                                                       			{
tmain_241: IF(0,241,tmain_242)                         *__csLOCALPARAM_Pop_result = (*__csLOCALPARAM_Pop_q).elems[__csLOCAL_Pop_t & (*__csLOCALPARAM_Pop_q).mask];
                                                       __retval__Pop_2 = 1;
                                                       goto __exit__Pop_2_0;
                                                       			}
                                                       			else
                                                       			{ GUARD(0,242)
                                                       				{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_242: IF(0,242,tmain_243)                         __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_Pop_q).tail;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_Pop_t + 1;
tmain_243: IF(0,243,tmain_244)                         __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       					__exit__writeV_24_0: GUARD(0,244)
                                                       ;
                                                       				};
                                                       0;
                                                       static _Bool __retval__SyncPop_2;
                                                       				{
                                                       static WorkStealQueue *__csLOCALPARAM_SyncPop_q;
tmain_244: IF(0,244,tmain_245)                         __csLOCALPARAM_SyncPop_q = __csLOCALPARAM_Pop_q;
                                                       static Obj **__csLOCALPARAM_SyncPop_result;
tmain_245: IF(0,245,tmain_246)                         __csLOCALPARAM_SyncPop_result = __csLOCALPARAM_Pop_result;
                                                       static _Bool __csLOCAL_SyncPop_found;
tmain_246: IF(0,246,tmain_247)                         __cs_mutex_lock_MACRO((*__csLOCALPARAM_SyncPop_q).cs);
                                                       static long __csLOCAL_SyncPop_t;
                                                       static long __retval__readV_20;
                                                       					{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_247: IF(0,247,tmain_248)                         __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_SyncPop_q).tail;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_248: IF(0,248,tmain_249)                         __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_20 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_20_0;
                                                       						__exit__readV_20_0: GUARD(0,249)
                                                       ;
                                                       					};
                                                       __csLOCAL_SyncPop_t = __retval__readV_20 - 1;
                                                       					{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_249: IF(0,249,tmain_250)                         __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_SyncPop_q).tail;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_SyncPop_t;
tmain_250: IF(0,250,tmain_251)                         __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       						__exit__writeV_25_0: GUARD(0,251)
                                                       ;
                                                       					};
                                                       0;
                                                       static _Bool __csLOCAL_SyncPop___if_cond_1;
                                                       static long __retval__readV_21;
                                                       					{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_251: IF(0,251,tmain_252)                         __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_SyncPop_q).head;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_252: IF(0,252,tmain_253)                         __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_21 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_21_0;
                                                       						__exit__readV_21_0: GUARD(0,253)
                                                       ;
                                                       					};
                                                       __csLOCAL_SyncPop___if_cond_1 = __retval__readV_21 <= __csLOCAL_SyncPop_t;
                                                       if (__csLOCAL_SyncPop___if_cond_1)
                                                       					{
tmain_253: IF(0,253,tmain_254)                         *__csLOCALPARAM_SyncPop_result = (*__csLOCALPARAM_SyncPop_q).elems[__csLOCAL_SyncPop_t & (*__csLOCALPARAM_SyncPop_q).mask];
                                                       __csLOCAL_SyncPop_found = 1;
                                                       					}
                                                       					else
                                                       					{ GUARD(0,254)
                                                       						{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_254: IF(0,254,tmain_255)                         __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_SyncPop_q).tail;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_SyncPop_t + 1;
tmain_255: IF(0,255,tmain_256)                         __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       							__exit__writeV_26_0: GUARD(0,256)
                                                       ;
                                                       						};
                                                       0;
                                                       __csLOCAL_SyncPop_found = 0;
                                                       					}
                                                       					GUARD(0,256);
                                                       static _Bool __csLOCAL_SyncPop___if_cond_2;
                                                       static long __retval__readV_22;
                                                       					{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_256: IF(0,256,tmain_257)                         __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_SyncPop_q).head;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_257: IF(0,257,tmain_258)                         __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_22 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_22_0;
                                                       						__exit__readV_22_0: GUARD(0,258)
                                                       ;
                                                       					};
                                                       __csLOCAL_SyncPop___if_cond_2 = __retval__readV_22 > __csLOCAL_SyncPop_t;
                                                       if (__csLOCAL_SyncPop___if_cond_2)
                                                       					{
                                                       						{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_258: IF(0,258,tmain_259)                         __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_SyncPop_q).head;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = 0;
tmain_259: IF(0,259,tmain_260)                         __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       							__exit__writeV_27_0: GUARD(0,260)
                                                       ;
                                                       						};
                                                       0;
                                                       						{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_260: IF(0,260,tmain_261)                         __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_SyncPop_q).tail;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = 0;
tmain_261: IF(0,261,tmain_262)                         __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       							__exit__writeV_28_0: GUARD(0,262)
                                                       ;
                                                       						};
                                                       0;
                                                       __csLOCAL_SyncPop_found = 0;
                                                       					}
                                                       					GUARD(0,262);
tmain_262: IF(0,262,tmain_263)                         __cs_mutex_unlock_MACRO((*__csLOCALPARAM_SyncPop_q).cs);
                                                       __retval__SyncPop_2 = __csLOCAL_SyncPop_found;
                                                       goto __exit__SyncPop_2_0;
                                                       					__exit__SyncPop_2_0: GUARD(0,263)
                                                       ;
                                                       				};
                                                       __retval__Pop_2 = __retval__SyncPop_2;
                                                       goto __exit__Pop_2_0;
                                                       			}
                                                       			GUARD(0,263);
                                                       			__exit__Pop_2_0: GUARD(0,263)
                                                       ;
                                                       		};
                                                       __csLOCAL_main___if_cond_7 = __retval__Pop_2;
                                                       if (__csLOCAL_main___if_cond_7)
                                                       		{
                                                       			{
                                                       static Obj *__csLOCALPARAM_Operation_r;
tmain_263: IF(0,263,tmain_264)                         __csLOCALPARAM_Operation_r = __csLOCAL_main_r;
tmain_264: IF(0,264,tmain_265)                         (*__csLOCALPARAM_Operation_r).field++;
                                                       				__exit__Operation_3_0: GUARD(0,265)
                                                       ;
                                                       			};
                                                       0;
                                                       		}
                                                       		GUARD(0,265);
                                                       	};
                                                       __csLOCAL_main_i++;
                                                       if (!(__csLOCAL_main_i < (4 / 2)))
                                                       	{
                                                       goto __exit_loop_9;
                                                       	}
                                                       	;
                                                       	{
                                                       static Obj *__csLOCAL_main_r;
                                                       static _Bool __csLOCAL_main___if_cond_7;
                                                       static _Bool __retval__Pop_2;
                                                       		{
                                                       static WorkStealQueue *__csLOCALPARAM_Pop_q;
tmain_265: IF(0,265,tmain_266)                         __csLOCALPARAM_Pop_q = &__csLOCAL_main_q;
                                                       static Obj **__csLOCALPARAM_Pop_result;
tmain_266: IF(0,266,tmain_267)                         __csLOCALPARAM_Pop_result = &__csLOCAL_main_r;
                                                       static long __csLOCAL_Pop_t;
                                                       static long __retval__readV_18;
                                                       			{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_267: IF(0,267,tmain_268)                         __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_Pop_q).tail;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_268: IF(0,268,tmain_269)                         __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_18 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_18_1;
                                                       				__exit__readV_18_1: GUARD(0,269)
                                                       ;
                                                       			};
                                                       __csLOCAL_Pop_t = __retval__readV_18 - 1;
                                                       			{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_269: IF(0,269,tmain_270)                         __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_Pop_q).tail;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_Pop_t;
tmain_270: IF(0,270,tmain_271)                         __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       				__exit__writeV_23_1: GUARD(0,271)
                                                       ;
                                                       			};
                                                       0;
                                                       static _Bool __csLOCAL_Pop___if_cond_3;
                                                       static long __retval__readV_19;
                                                       			{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_271: IF(0,271,tmain_272)                         __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_Pop_q).head;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_272: IF(0,272,tmain_273)                         __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_19 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_19_1;
                                                       				__exit__readV_19_1: GUARD(0,273)
                                                       ;
                                                       			};
                                                       __csLOCAL_Pop___if_cond_3 = __retval__readV_19 <= __csLOCAL_Pop_t;
                                                       if (__csLOCAL_Pop___if_cond_3)
                                                       			{
tmain_273: IF(0,273,tmain_274)                         *__csLOCALPARAM_Pop_result = (*__csLOCALPARAM_Pop_q).elems[__csLOCAL_Pop_t & (*__csLOCALPARAM_Pop_q).mask];
                                                       __retval__Pop_2 = 1;
                                                       goto __exit__Pop_2_1;
                                                       			}
                                                       			else
                                                       			{ GUARD(0,274)
                                                       				{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_274: IF(0,274,tmain_275)                         __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_Pop_q).tail;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_Pop_t + 1;
tmain_275: IF(0,275,tmain_276)                         __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       					__exit__writeV_24_1: GUARD(0,276)
                                                       ;
                                                       				};
                                                       0;
                                                       static _Bool __retval__SyncPop_2;
                                                       				{
                                                       static WorkStealQueue *__csLOCALPARAM_SyncPop_q;
tmain_276: IF(0,276,tmain_277)                         __csLOCALPARAM_SyncPop_q = __csLOCALPARAM_Pop_q;
                                                       static Obj **__csLOCALPARAM_SyncPop_result;
tmain_277: IF(0,277,tmain_278)                         __csLOCALPARAM_SyncPop_result = __csLOCALPARAM_Pop_result;
                                                       static _Bool __csLOCAL_SyncPop_found;
tmain_278: IF(0,278,tmain_279)                         __cs_mutex_lock_MACRO((*__csLOCALPARAM_SyncPop_q).cs);
                                                       static long __csLOCAL_SyncPop_t;
                                                       static long __retval__readV_20;
                                                       					{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_279: IF(0,279,tmain_280)                         __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_SyncPop_q).tail;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_280: IF(0,280,tmain_281)                         __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_20 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_20_1;
                                                       						__exit__readV_20_1: GUARD(0,281)
                                                       ;
                                                       					};
                                                       __csLOCAL_SyncPop_t = __retval__readV_20 - 1;
                                                       					{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_281: IF(0,281,tmain_282)                         __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_SyncPop_q).tail;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_SyncPop_t;
tmain_282: IF(0,282,tmain_283)                         __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       						__exit__writeV_25_1: GUARD(0,283)
                                                       ;
                                                       					};
                                                       0;
                                                       static _Bool __csLOCAL_SyncPop___if_cond_1;
                                                       static long __retval__readV_21;
                                                       					{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_283: IF(0,283,tmain_284)                         __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_SyncPop_q).head;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_284: IF(0,284,tmain_285)                         __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_21 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_21_1;
                                                       						__exit__readV_21_1: GUARD(0,285)
                                                       ;
                                                       					};
                                                       __csLOCAL_SyncPop___if_cond_1 = __retval__readV_21 <= __csLOCAL_SyncPop_t;
                                                       if (__csLOCAL_SyncPop___if_cond_1)
                                                       					{
tmain_285: IF(0,285,tmain_286)                         *__csLOCALPARAM_SyncPop_result = (*__csLOCALPARAM_SyncPop_q).elems[__csLOCAL_SyncPop_t & (*__csLOCALPARAM_SyncPop_q).mask];
                                                       __csLOCAL_SyncPop_found = 1;
                                                       					}
                                                       					else
                                                       					{ GUARD(0,286)
                                                       						{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_286: IF(0,286,tmain_287)                         __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_SyncPop_q).tail;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = __csLOCAL_SyncPop_t + 1;
tmain_287: IF(0,287,tmain_288)                         __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       							__exit__writeV_26_1: GUARD(0,288)
                                                       ;
                                                       						};
                                                       0;
                                                       __csLOCAL_SyncPop_found = 0;
                                                       					}
                                                       					GUARD(0,288);
                                                       static _Bool __csLOCAL_SyncPop___if_cond_2;
                                                       static long __retval__readV_22;
                                                       					{
                                                       static long *__csLOCALPARAM_readV_v;
tmain_288: IF(0,288,tmain_289)                         __csLOCALPARAM_readV_v = &(*__csLOCALPARAM_SyncPop_q).head;
                                                       static long __csLOCAL_readV_expected;
                                                       __csLOCAL_readV_expected = 0;
tmain_289: IF(0,289,tmain_290)                         __CS_atomic_compare_exchange_strong(__csLOCALPARAM_readV_v, &__csLOCAL_readV_expected, 0);
                                                       __retval__readV_22 = __csLOCAL_readV_expected;
                                                       goto __exit__readV_22_1;
                                                       						__exit__readV_22_1: GUARD(0,290)
                                                       ;
                                                       					};
                                                       __csLOCAL_SyncPop___if_cond_2 = __retval__readV_22 > __csLOCAL_SyncPop_t;
                                                       if (__csLOCAL_SyncPop___if_cond_2)
                                                       					{
                                                       						{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_290: IF(0,290,tmain_291)                         __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_SyncPop_q).head;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = 0;
tmain_291: IF(0,291,tmain_292)                         __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       							__exit__writeV_27_1: GUARD(0,292)
                                                       ;
                                                       						};
                                                       0;
                                                       						{
                                                       static long *__csLOCALPARAM_writeV_v;
tmain_292: IF(0,292,tmain_293)                         __csLOCALPARAM_writeV_v = &(*__csLOCALPARAM_SyncPop_q).tail;
                                                       static long __csLOCALPARAM_writeV_w;
                                                       __csLOCALPARAM_writeV_w = 0;
tmain_293: IF(0,293,tmain_294)                         __CS_atomic_exchange(__csLOCALPARAM_writeV_v, __csLOCALPARAM_writeV_w);
                                                       							__exit__writeV_28_1: GUARD(0,294)
                                                       ;
                                                       						};
                                                       0;
                                                       __csLOCAL_SyncPop_found = 0;
                                                       					}
                                                       					GUARD(0,294);
tmain_294: IF(0,294,tmain_295)                         __cs_mutex_unlock_MACRO((*__csLOCALPARAM_SyncPop_q).cs);
                                                       __retval__SyncPop_2 = __csLOCAL_SyncPop_found;
                                                       goto __exit__SyncPop_2_1;
                                                       					__exit__SyncPop_2_1: GUARD(0,295)
                                                       ;
                                                       				};
                                                       __retval__Pop_2 = __retval__SyncPop_2;
                                                       goto __exit__Pop_2_1;
                                                       			}
                                                       			GUARD(0,295);
                                                       			__exit__Pop_2_1: GUARD(0,295)
                                                       ;
                                                       		};
                                                       __csLOCAL_main___if_cond_7 = __retval__Pop_2;
                                                       if (__csLOCAL_main___if_cond_7)
                                                       		{
                                                       			{
                                                       static Obj *__csLOCALPARAM_Operation_r;
tmain_295: IF(0,295,tmain_296)                         __csLOCALPARAM_Operation_r = __csLOCAL_main_r;
tmain_296: IF(0,296,tmain_297)                         (*__csLOCALPARAM_Operation_r).field++;
                                                       				__exit__Operation_3_1: GUARD(0,297)
                                                       ;
                                                       			};
                                                       0;
                                                       		}
                                                       		GUARD(0,297);
                                                       	};
                                                       __csLOCAL_main_i++;
                                                       assume(!(__csLOCAL_main_i < (4 / 2)));
                                                       	__exit_loop_9: GUARD(0,297)
                                                       ;
                                                       __csLOCAL_main_i = 0;
                                                       	{
tmain_297: IF(0,297,tmain_298)                         __cs_join(__csLOCAL_main_handles[__csLOCAL_main_i], 0);
                                                       	};
                                                       __csLOCAL_main_i++;
                                                       assume(!(__csLOCAL_main_i < 1));
                                                       	__exit_loop_10: GUARD(0,298)
                                                       ;
                                                       __csLOCAL_main_i = 0;
                                                       if (!(__csLOCAL_main_i < (4 / 2)))
                                                       	{
                                                       goto __exit_loop_11;
                                                       	}
                                                       	;
                                                       	{
                                                       		{
                                                       static Obj *__csLOCALPARAM_Check_r;
tmain_298: IF(0,298,tmain_299)                         __csLOCALPARAM_Check_r = &__csLOCAL_main_items[2 * __csLOCAL_main_i];
tmain_299: IF(0,299,tmain_300)                         assert((*__csLOCALPARAM_Check_r).field == 1);
                                                       			__exit__Check_1_0: GUARD(0,300)
                                                       ;
                                                       		};
                                                       0;
                                                       		{
                                                       static Obj *__csLOCALPARAM_Check_r;
tmain_300: IF(0,300,tmain_301)                         __csLOCALPARAM_Check_r = &__csLOCAL_main_items[(2 * __csLOCAL_main_i) + 1];
tmain_301: IF(0,301,tmain_302)                         assert((*__csLOCALPARAM_Check_r).field == 1);
                                                       			__exit__Check_2_0: GUARD(0,302)
                                                       ;
                                                       		};
                                                       0;
                                                       	};
                                                       __csLOCAL_main_i++;
                                                       if (!(__csLOCAL_main_i < (4 / 2)))
                                                       	{
                                                       goto __exit_loop_11;
                                                       	}
                                                       	;
                                                       	{
                                                       		{
                                                       static Obj *__csLOCALPARAM_Check_r;
tmain_302: IF(0,302,tmain_303)                         __csLOCALPARAM_Check_r = &__csLOCAL_main_items[2 * __csLOCAL_main_i];
tmain_303: IF(0,303,tmain_304)                         assert((*__csLOCALPARAM_Check_r).field == 1);
                                                       			__exit__Check_1_1: GUARD(0,304)
                                                       ;
                                                       		};
                                                       0;
                                                       		{
                                                       static Obj *__csLOCALPARAM_Check_r;
tmain_304: IF(0,304,tmain_305)                         __csLOCALPARAM_Check_r = &__csLOCAL_main_items[(2 * __csLOCAL_main_i) + 1];
tmain_305: IF(0,305,tmain_306)                         assert((*__csLOCALPARAM_Check_r).field == 1);
                                                       			__exit__Check_2_1: GUARD(0,306)
                                                       ;
                                                       		};
                                                       0;
                                                       	};
                                                       __csLOCAL_main_i++;
                                                       assume(!(__csLOCAL_main_i < (4 / 2)));
                                                       	__exit_loop_11: GUARD(0,306)
                                                       ;
tmain_306: IF(0,306,tmain_307)                         free(__csLOCAL_main_items);
                                                       goto __exit_main;
                                                       	__exit_main: GUARD(0,307)
                                                       ;
tmain_307:                                             STOP_NONVOID(307);
                                                       }
                                                       
                                                       
                                                       
                                                       int main(void) {
                                                                 // round 0
                                                                 thread_index = 0;
                                                                 pc_cs = pc[0] + guess_pc();
                                                                 assume((pc_cs > 0) && (pc_cs <= 307));
                                                                 main_thread();
                                                                 pc[0] = pc_cs;
                                                       
                                                                 thread_index = 1;
                                                                 if (active_thread[1] == 1) { /** Stealer_0 **/
                                                                    pc_cs = pc[1] + guess_pc();
                                                                    assume((pc_cs >= 0) && (pc_cs <= 31));
                                                                    Stealer_0(threadargs[1]);
                                                                    pc[1] = pc_cs;
                                                                 }
                                                       
                                                                 // round 1
                                                                 thread_index = 0;
                                                                 if (active_thread[0] == 1) { /** main **/
                                                                     pc_cs = pc[0] + guess_pc();
                                                                     assume((pc_cs >= pc[0]) && (pc_cs <= 307));
                                                                     main_thread();
                                                                     pc[0] = pc_cs;
                                                                 }
                                                       
                                                                 thread_index = 1;
                                                                 if (active_thread[1] == 1) { /** Stealer_0 **/
                                                                    pc_cs = pc[1] + guess_pc();
                                                                    assume((pc_cs >= pc[1]) && (pc_cs <= 31));
                                                                    Stealer_0(threadargs[1]);
                                                                    pc[1] = pc_cs;
                                                                 }
                                                       
                                                                 thread_index = 0;
                                                                 if (active_thread[0] == 1) {
                                                                    pc_cs = pc[0] + guess_pc();
                                                                    assume((pc_cs >= pc[0]) && (pc_cs <= 307));
                                                                    main_thread();
                                                                 }
                                                       
                                                          return 0;
                                                       }
                                                       


