#ifndef _dbg_h__
#define _dbg_h__

#include <stdio.h>
#include <errno.h>
#include <string.h>

// if compile with ndebug defined, "no debug" messages will remain
#ifdef NDEBUG
#define debug(M, ...)
#else
// alternatively use of debug("format", arg1, arg2) into an fprintf call to stderr.
// can create macros that actually work like printf and take variable args.
// ##__VA_ARGS__ "put whatever they had for extra arguments (...) here".  
// __FILE__ and __LINE__ get current file:line for debug message.
#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#endif

#define clean_errno() (errno == 0? "None" : strerror(errno))

#define log_err(M, ...) fprintf(stderr, "[ERROR] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_warn(M, ...) fprintf(stderr, "[WARN] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_info(M, ...) fprintf(stderr, "[INFO] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

// make sure condition A true, if not logs error M (with variable arguments for log_err)
// then jumps to function's error for cleanup
#define check(A, M, ...) if(!(A)) { log_err(M, ##__VA_ARGS__); errno=0; goto error; }
// 2nd best macro.  placed in any part of a func that shouldn't run.  if it does prints error
// message and jumps to error: label.
#define sentinel(M, ...)  { log_err(M, ##__VA_ARGS__); errno=0; goto error; }
// makes sure a pointer is valid, if not reports "Out of memory."
#define check_mem(A) check((A), "Out of memory.")

#define check_debug(A, M, ...) if(!(A)) { debug(M, ##__VA_ARGS__); errno=0; goto error; }

#endif

