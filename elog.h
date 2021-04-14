#ifndef __ELOG_H
#define __ELOG_H

// Define log level
#define	ELOG_LEVEL_OFF    0 // Turn off log output
#define ELOG_LEVEL_PANIC  1 // The program cannot continue to run normally
#define ELOG_LEVEL_ERROR  2
#define ELOG_LEVEL_WARN   3
#define ELOG_LEVEL_NOTICE 4
#define ELOG_LEVEL_INFO   5
#define ELOG_LEVEL_DEBUG  6
#define ELOG_LEVEL_TRACE  7

// Control log output level
#ifndef ELOG_OUTPUT_LEVEL
#define ELOG_OUTPUT_LEVEL   ELOG_LEVEL_INFO
#endif

/**
 * Generally, the log will contain specific date and time information, 
 * but for embedded bare metal programs, we can get the date and time 
 * through the host computer. You can modify it according to your own 
 * situation. 
 */
// Format: main.c 123 ERROR <tag>This is test log.[key:100]
#define ELOG_OUTPUT(level, fmt, args...) \
        printf("%s\t\t %d\t %s\t "fmt"\r\n",__FILE__,__LINE__,level,##args)

#if (ELOG_OUTPUT_LEVEL >= ELOG_LEVEL_TRACE)
#define elog_trace(fmt, args...) ELOG_OUTPUT("TRACE", fmt, ##args)
#else
#define elog_trace(fmt, args...) do{}while(0)
#endif

#if (ELOG_OUTPUT_LEVEL >= ELOG_LEVEL_DEBUG)
#define elog_debug(fmt, args...) ELOG_OUTPUT("DEBUG", fmt, ##args)
#else
#define elog_debug(fmt, args...) do{}while(0)
#endif

#if (ELOG_OUTPUT_LEVEL >= ELOG_LEVEL_INFO)
#define elog_info(fmt, args...) ELOG_OUTPUT("INFO", fmt, ##args)
#else
#define elog_info(fmt, args...) do{}while(0)
#endif

#if (ELOG_OUTPUT_LEVEL >= ELOG_LEVEL_NOTICE)
#define elog_notice(fmt, args...) ELOG_OUTPUT("NOTICE", fmt, ##args)
#else
#define elog_notice(fmt, args...) do{}while(0)
#endif

#if (ELOG_OUTPUT_LEVEL >= ELOG_LEVEL_WARN)
#define elog_warn(fmt, args...) ELOG_OUTPUT("WARN", fmt, ##args)
#else
#define elog_warn(fmt, args...) do{}while(0)
#endif

#if (ELOG_OUTPUT_LEVEL >= ELOG_LEVEL_ERROR)
#define elog_error(fmt, args...) ELOG_OUTPUT("ERROR", fmt, ##args)
#else
#define elog_error(fmt, args...) do{}while(0)
#endif

#if (ELOG_OUTPUT_LEVEL >= ELOG_LEVEL_PANIC)
#define elog_panic(fmt, args...) ELOG_OUTPUT("PANIC", fmt, ##args)
#else
#define elog_panic(fmt, args...) do{}while(0)
#endif


/** 
 * The recommended usage is to add the tag to the head 
 * and the key-value to the tail, so that it looks easier visually 
 */
#define __ELOG_STRINGIFY(str) #str
#define E_TAG(tag) __ELOG_STRINGIFY(<tag>)
#define E_KV(key,value) __ELOG_STRINGIFY([key:value])

#endif

// end of file
