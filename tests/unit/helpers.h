#include <libmem/libmem.h>

#if LM_OS == LM_OS_WIN
#	define TARGET_PROC "target.exe"
#else
#	define TARGET_PROC "target"
#endif

#define CHECK_PROCESS(proc) ( \
	(proc)->pid != LM_PID_BAD && \
	LM_STRLEN((proc)->path) > 0 && \
	LM_STRLEN((proc)->name) > 0 \
)

#define EQUAL_PROCESSES(p1, p2) ( \
	(p1)->pid == (p2)->pid && \
	(p1)->ppid == (p2)->ppid && \
	(p1)->start_time == (p2)->start_time && \
	!LM_STRCMP((p1)->path, (p2)->path) && \
	!LM_STRCMP((p1)->name, (p2)->name) \
)

#define CHECK_THREAD(thread) ((thread)->tid != LM_TID_BAD)
#define EQUAL_THREADS(t1, t2) ((t1)->tid == (t2)->tid)

#define CHECK_MODULE(mod) ( \
	(mod)->base != LM_ADDRESS_BAD && \
	(mod)->end != LM_ADDRESS_BAD && \
	(mod)->size > 0 && \
	LM_STRLEN((mod)->path) > 0 && \
	LM_STRLEN((mod)->name) > 0 \
)

/* Dependency Injection */
extern lm_process_t current_process;
extern lm_process_t target_process;
extern lm_thread_t  current_thread;
extern lm_thread_t  target_thread;