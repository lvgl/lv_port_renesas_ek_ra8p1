/* See ra_cfg/fsp_cfg/lvgl/lvgl/lv_conf.h
 * to see default overrides
 */

#ifndef LV_CONF_USER_H_
#define LV_CONF_USER_H_

/** Build the demos */
#define LV_BUILD_DEMOS 1

#if LV_BUILD_DEMOS
    /** Show some widgets. This might be required to increase `LV_MEM_SIZE`. */
    #define LV_USE_DEMO_WIDGETS 1

    /** Benchmark your system */
    #define LV_USE_DEMO_BENCHMARK 1

    #if LV_USE_DEMO_BENCHMARK
        /** Use fonts where bitmaps are aligned 16 byte and has Nx16 byte stride */
        #define LV_DEMO_BENCHMARK_ALIGNED_FONTS 1
    #endif
#endif

/** Possible values
 * - LV_STDLIB_BUILTIN:     LVGL's built in implementation
 * - LV_STDLIB_CLIB:        Standard C functions, like malloc, strlen, etc
 * - LV_STDLIB_MICROPYTHON: MicroPython implementation
 * - LV_STDLIB_RTTHREAD:    RT-Thread implementation
 * - LV_STDLIB_CUSTOM:      Implement the functions externally
 */
#define LV_USE_STDLIB_MALLOC    LV_STDLIB_BUILTIN

#if LV_USE_STDLIB_MALLOC == LV_STDLIB_BUILTIN
    /** Size of memory available for `lv_malloc()` in bytes (>= 2kB) */
    #define LV_MEM_SIZE (1024 * 1024U)          /**< [bytes] */
#endif  /*LV_USE_STDLIB_MALLOC == LV_STDLIB_BUILTIN*/

/** The target buffer size for simple layer chunks. */
#define LV_DRAW_LAYER_SIMPLE_BUF_SIZE    (256 * 1024)    /**< [bytes]*/

/* Limit the max allocated memory for simple and transformed layers.
 * It should be at least `LV_DRAW_LAYER_SIMPLE_BUF_SIZE` sized but if transformed layers are also used
 * it should be enough to store the largest widget too (width x height x 4 area).
 * Set it to 0 to have no limit. */
#define LV_DRAW_LAYER_MAX_MEMORY (256 * 1024)  /**< No limit by default [bytes]*/

#define LV_USE_TINY_TTF 1

#define LV_USE_LOG 1
#if LV_USE_LOG
    /** Set value to one of the following levels of logging detail:
     *  - LV_LOG_LEVEL_TRACE    Log detailed information.
     *  - LV_LOG_LEVEL_INFO     Log important events.
     *  - LV_LOG_LEVEL_WARN     Log if something unwanted happened but didn't cause a problem.
     *  - LV_LOG_LEVEL_ERROR    Log only critical issues, when system may fail.
     *  - LV_LOG_LEVEL_USER     Log only custom log messages added by the user.
     *  - LV_LOG_LEVEL_NONE     Do not log anything. */
    #define LV_LOG_LEVEL LV_LOG_LEVEL_WARN

    /** - 1: Print log with 'printf';
     *  - 0: User needs to register a callback with `lv_log_register_print_cb()`. */
    #define LV_LOG_PRINTF 1

    /** Set callback to print logs.
     *  E.g `my_print`. The prototype should be `void my_print(lv_log_level_t level, const char * buf)`.
     *  Can be overwritten by `lv_log_register_print_cb`. */
    //#define LV_LOG_PRINT_CB

    /** - 1: Enable printing timestamp;
     *  - 0: Disable printing timestamp. */
    #define LV_LOG_USE_TIMESTAMP 1

    /** - 1: Print file and line number of the log;
     *  - 0: Do not print file and line number of the log. */
    #define LV_LOG_USE_FILE_LINE 1

    /* Enable/disable LV_LOG_TRACE in modules that produces a huge number of logs. */
    #define LV_LOG_TRACE_MEM        1   /**< Enable/disable trace logs in memory operations. */
    #define LV_LOG_TRACE_TIMER      1   /**< Enable/disable trace logs in timer operations. */
    #define LV_LOG_TRACE_INDEV      1   /**< Enable/disable trace logs in input device operations. */
    #define LV_LOG_TRACE_DISP_REFR  1   /**< Enable/disable trace logs in display re-draw operations. */
    #define LV_LOG_TRACE_EVENT      1   /**< Enable/disable trace logs in event dispatch logic. */
    #define LV_LOG_TRACE_OBJ_CREATE 1   /**< Enable/disable trace logs in object creation (core `obj` creation plus every widget). */
    #define LV_LOG_TRACE_LAYOUT     1   /**< Enable/disable trace logs in flex- and grid-layout operations. */
    #define LV_LOG_TRACE_ANIM       1   /**< Enable/disable trace logs in animation logic. */
    #define LV_LOG_TRACE_CACHE      1   /**< Enable/disable trace logs in cache operations. */
#endif  /*LV_USE_LOG*/

/*-------------
 * Asserts
 *-----------*/

/* Enable assertion failures if an operation fails or invalid data is found.
 * If LV_USE_LOG is enabled, an error message will be printed on failure. */
#define LV_USE_ASSERT_NULL          0   /**< Check if the parameter is NULL. (Very fast, recommended) */
#define LV_USE_ASSERT_MALLOC        0   /**< Checks is the memory is successfully allocated or no. (Very fast, recommended) */
#define LV_USE_ASSERT_STYLE         0   /**< Check if the styles are properly initialized. (Very fast, recommended) */
#define LV_USE_ASSERT_MEM_INTEGRITY 0   /**< Check the integrity of `lv_mem` after critical operations. (Slow) */
#define LV_USE_ASSERT_OBJ           0   /**< Check the object's type and existence (e.g. not deleted). (Slow) */


#define LV_USE_XML 0

    /** Enable drawing complex gradients in software: linear at an angle, radial or conical */
#define LV_USE_DRAW_SW_COMPLEX_GRADIENTS    0


/** 1: Enable system monitor component */
#define LV_USE_SYSMON   1
#if LV_USE_SYSMON
    /** Get the idle percentage. E.g. uint32_t my_get_idle(void); */
    #define LV_SYSMON_GET_IDLE lv_timer_get_idle

    /** 1: Show CPU usage and FPS count.
     *  - Requires `LV_USE_SYSMON = 1` */
    #define LV_USE_PERF_MONITOR 1
    #if LV_USE_PERF_MONITOR
        #define LV_USE_PERF_MONITOR_POS LV_ALIGN_BOTTOM_RIGHT

        /** 0: Displays performance data on the screen; 1: Prints performance data using log. */
        #define LV_USE_PERF_MONITOR_LOG_MODE 0
    #endif

    /** 1: Show used memory and memory fragmentation.
     *     - Requires `LV_USE_STDLIB_MALLOC = LV_STDLIB_BUILTIN`
     *     - Requires `LV_USE_SYSMON = 1`*/
    #define LV_USE_MEM_MONITOR 0
    #if LV_USE_MEM_MONITOR
        #define LV_USE_MEM_MONITOR_POS LV_ALIGN_BOTTOM_LEFT
    #endif
#endif /*LV_USE_SYSMON*/


#endif /* LV_CONF_USER_H_ */
