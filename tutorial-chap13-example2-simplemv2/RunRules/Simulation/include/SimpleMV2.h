/**\file */
#ifndef SLIC_DECLARATIONS_SimpleMV2_H
#define SLIC_DECLARATIONS_SimpleMV2_H
#include "MaxSLiCInterface.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
#define SimpleMV2_M (4)


/*----------------------------------------------------------------------------*/
/*---------------------------- Interface default -----------------------------*/
/*----------------------------------------------------------------------------*/



/**
 * \brief Basic static function for the interface 'default'.
 * 
 * \param [in] ticks_SimpleMV2Kernel The number of ticks for which kernel "SimpleMV2Kernel" will run.
 * \param [in] instream_x0 Stream "x0".
 * \param [in] instream_size_x0 The size of the stream instream_x0 in bytes.
 * \param [in] instream_x1 Stream "x1".
 * \param [in] instream_size_x1 The size of the stream instream_x1 in bytes.
 * \param [in] instream_x2 Stream "x2".
 * \param [in] instream_size_x2 The size of the stream instream_x2 in bytes.
 * \param [in] instream_x3 Stream "x3".
 * \param [in] instream_size_x3 The size of the stream instream_x3 in bytes.
 * \param [out] outstream_y0 Stream "y0".
 * \param [in] outstream_size_y0 The size of the stream outstream_y0 in bytes.
 * \param [out] outstream_y1 Stream "y1".
 * \param [in] outstream_size_y1 The size of the stream outstream_y1 in bytes.
 * \param [out] outstream_y2 Stream "y2".
 * \param [in] outstream_size_y2 The size of the stream outstream_y2 in bytes.
 * \param [out] outstream_y3 Stream "y3".
 * \param [in] outstream_size_y3 The size of the stream outstream_y3 in bytes.
 */
void SimpleMV2(
	uint64_t ticks_SimpleMV2Kernel,
	const void *instream_x0,
	size_t instream_size_x0,
	const void *instream_x1,
	size_t instream_size_x1,
	const void *instream_x2,
	size_t instream_size_x2,
	const void *instream_x3,
	size_t instream_size_x3,
	void *outstream_y0,
	size_t outstream_size_y0,
	void *outstream_y1,
	size_t outstream_size_y1,
	void *outstream_y2,
	size_t outstream_size_y2,
	void *outstream_y3,
	size_t outstream_size_y3);

/**
 * \brief Basic static non-blocking function for the interface 'default'.
 * 
 * Schedule to run on an engine and return immediately.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 * 
 * 
 * \param [in] ticks_SimpleMV2Kernel The number of ticks for which kernel "SimpleMV2Kernel" will run.
 * \param [in] instream_x0 Stream "x0".
 * \param [in] instream_size_x0 The size of the stream instream_x0 in bytes.
 * \param [in] instream_x1 Stream "x1".
 * \param [in] instream_size_x1 The size of the stream instream_x1 in bytes.
 * \param [in] instream_x2 Stream "x2".
 * \param [in] instream_size_x2 The size of the stream instream_x2 in bytes.
 * \param [in] instream_x3 Stream "x3".
 * \param [in] instream_size_x3 The size of the stream instream_x3 in bytes.
 * \param [out] outstream_y0 Stream "y0".
 * \param [in] outstream_size_y0 The size of the stream outstream_y0 in bytes.
 * \param [out] outstream_y1 Stream "y1".
 * \param [in] outstream_size_y1 The size of the stream outstream_y1 in bytes.
 * \param [out] outstream_y2 Stream "y2".
 * \param [in] outstream_size_y2 The size of the stream outstream_y2 in bytes.
 * \param [out] outstream_y3 Stream "y3".
 * \param [in] outstream_size_y3 The size of the stream outstream_y3 in bytes.
 * \return A handle on the execution status, or NULL in case of error.
 */
max_run_t *SimpleMV2_nonblock(
	uint64_t ticks_SimpleMV2Kernel,
	const void *instream_x0,
	size_t instream_size_x0,
	const void *instream_x1,
	size_t instream_size_x1,
	const void *instream_x2,
	size_t instream_size_x2,
	const void *instream_x3,
	size_t instream_size_x3,
	void *outstream_y0,
	size_t outstream_size_y0,
	void *outstream_y1,
	size_t outstream_size_y1,
	void *outstream_y2,
	size_t outstream_size_y2,
	void *outstream_y3,
	size_t outstream_size_y3);

/**
 * \brief Advanced static interface, structure for the engine interface 'default'
 * 
 */
typedef struct { 
	uint64_t ticks_SimpleMV2Kernel; /**<  [in] The number of ticks for which kernel "SimpleMV2Kernel" will run. */
	const void *instream_x0; /**<  [in] Stream "x0". */
	size_t instream_size_x0; /**<  [in] The size of the stream instream_x0 in bytes. */
	const void *instream_x1; /**<  [in] Stream "x1". */
	size_t instream_size_x1; /**<  [in] The size of the stream instream_x1 in bytes. */
	const void *instream_x2; /**<  [in] Stream "x2". */
	size_t instream_size_x2; /**<  [in] The size of the stream instream_x2 in bytes. */
	const void *instream_x3; /**<  [in] Stream "x3". */
	size_t instream_size_x3; /**<  [in] The size of the stream instream_x3 in bytes. */
	void *outstream_y0; /**<  [out] Stream "y0". */
	size_t outstream_size_y0; /**<  [in] The size of the stream outstream_y0 in bytes. */
	void *outstream_y1; /**<  [out] Stream "y1". */
	size_t outstream_size_y1; /**<  [in] The size of the stream outstream_y1 in bytes. */
	void *outstream_y2; /**<  [out] Stream "y2". */
	size_t outstream_size_y2; /**<  [in] The size of the stream outstream_y2 in bytes. */
	void *outstream_y3; /**<  [out] Stream "y3". */
	size_t outstream_size_y3; /**<  [in] The size of the stream outstream_y3 in bytes. */
} SimpleMV2_actions_t;

/**
 * \brief Advanced static function for the interface 'default'.
 * 
 * \param [in] engine The engine on which the actions will be executed.
 * \param [in,out] interface_actions Actions to be executed.
 */
void SimpleMV2_run(
	max_engine_t *engine,
	SimpleMV2_actions_t *interface_actions);

/**
 * \brief Advanced static non-blocking function for the interface 'default'.
 *
 * Schedule the actions to run on the engine and return immediately.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 *
 * 
 * \param [in] engine The engine on which the actions will be executed.
 * \param [in] interface_actions Actions to be executed.
 * \return A handle on the execution status of the actions, or NULL in case of error.
 */
max_run_t *SimpleMV2_run_nonblock(
	max_engine_t *engine,
	SimpleMV2_actions_t *interface_actions);

/**
 * \brief Group run advanced static function for the interface 'default'.
 * 
 * \param [in] group Group to use.
 * \param [in,out] interface_actions Actions to run.
 *
 * Run the actions on the first device available in the group.
 */
void SimpleMV2_run_group(max_group_t *group, SimpleMV2_actions_t *interface_actions);

/**
 * \brief Group run advanced static non-blocking function for the interface 'default'.
 * 
 *
 * Schedule the actions to run on the first device available in the group and return immediately.
 * The status of the run must be checked with ::max_wait. 
 * Note that use of ::max_nowait is prohibited with non-blocking running on groups:
 * see the ::max_run_group_nonblock documentation for more explanation.
 *
 * \param [in] group Group to use.
 * \param [in] interface_actions Actions to run.
 * \return A handle on the execution status of the actions, or NULL in case of error.
 */
max_run_t *SimpleMV2_run_group_nonblock(max_group_t *group, SimpleMV2_actions_t *interface_actions);

/**
 * \brief Array run advanced static function for the interface 'default'.
 * 
 * \param [in] engarray The array of devices to use.
 * \param [in,out] interface_actions The array of actions to run.
 *
 * Run the array of actions on the array of engines.  The length of interface_actions
 * must match the size of engarray.
 */
void SimpleMV2_run_array(max_engarray_t *engarray, SimpleMV2_actions_t *interface_actions[]);

/**
 * \brief Array run advanced static non-blocking function for the interface 'default'.
 * 
 *
 * Schedule to run the array of actions on the array of engines, and return immediately.
 * The length of interface_actions must match the size of engarray.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 *
 * \param [in] engarray The array of devices to use.
 * \param [in] interface_actions The array of actions to run.
 * \return A handle on the execution status of the actions, or NULL in case of error.
 */
max_run_t *SimpleMV2_run_array_nonblock(max_engarray_t *engarray, SimpleMV2_actions_t *interface_actions[]);

/**
 * \brief Converts a static-interface action struct into a dynamic-interface max_actions_t struct.
 *
 * Note that this is an internal utility function used by other functions in the static interface.
 *
 * \param [in] maxfile The maxfile to use.
 * \param [in] interface_actions The interface-specific actions to run.
 * \return The dynamic-interface actions to run, or NULL in case of error.
 */
max_actions_t* SimpleMV2_convert(max_file_t *maxfile, SimpleMV2_actions_t *interface_actions);

/**
 * \brief Initialise a maxfile.
 */
max_file_t* SimpleMV2_init(void);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* SLIC_DECLARATIONS_SimpleMV2_H */

