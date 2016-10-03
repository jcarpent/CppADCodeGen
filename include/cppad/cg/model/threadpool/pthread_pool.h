#ifndef CPPADCG_PTHREAD_POOL_H
#define CPPADCG_PTHREAD_POOL_H
/* --------------------------------------------------------------------------
 *  CppADCodeGen: C++ Algorithmic Differentiation with Source Code Generation:
 *    Copyright (C) 2016 Ciengis
 *
 *  CppADCodeGen is distributed under multiple licenses:
 *
 *   - Eclipse Public License Version 1.0 (EPL1), and
 *   - GNU General Public License Version 3 (GPL3).
 *
 *  EPL1 terms and conditions can be found in the file "epl-v10.txt", while
 *  terms and conditions for the GPL3 can be found in the file "gpl3.txt".
 * ----------------------------------------------------------------------------
 * Author: Joao Leal
 */

#ifdef __cplusplus
extern "C" {
#endif

enum ScheduleStrategy {SCHED_SINGLE_JOB,
                       SCHED_MULTI_JOB,
                       SCHED_STATIC};

typedef void (*cppadcg_thpool_function_type)(void*);


void cppadcg_thpool_set_threads(int n);

int cppadcg_thpool_get_threads();


void cppadcg_thpool_set_scheduler_strategy(enum ScheduleStrategy s);

enum ScheduleStrategy cppadcg_thpool_get_scheduler_strategy();


void cppadcg_thpool_set_multijob_maxgroupwork(float v);

float cppadcg_thpool_get_multijob_maxgroupwork();


unsigned int cppadcg_thpool_get_time_meas();

void cppadcg_thpool_set_time_meas(unsigned int n);


void cppadcg_thpool_set_verbose(int v);

int cppadcg_thpool_is_verbose();


void cppadcg_thpool_set_disabled(int disabled);

int cppadcg_thpool_is_disabled();


void cppadcg_thpool_prepare();

void cppadcg_thpool_add_job(cppadcg_thpool_function_type function,
                            void* arg,
                            const float* avgElapsed,
                            float* elapsed);

void cppadcg_thpool_add_jobs(cppadcg_thpool_function_type functions[],
                             void* args[],
                             const float avgElapsed[],
                             float elapsed[],
                             const int order[],
                             int nJobs);

void cppadcg_thpool_wait();

void cppadcg_thpool_update_order(float avgElapsed[],
                                 unsigned int n_time_meas,
                                 const float elapsed[],
                                 int order[],
                                 int nJobs);

void cppadcg_thpool_shutdown();

#ifdef __cplusplus
}
#endif

#endif