/**\file */
#ifndef SLIC_DECLARATIONS_MaxRing_H
#define SLIC_DECLARATIONS_MaxRing_H
#include "MaxSLiCInterface.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/*----------------------------------------------------------------------------*/
/*---------------------------- Interface default -----------------------------*/
/*----------------------------------------------------------------------------*/



/**
 * \brief Simple static function for the interface 'default'.
 * 
 * \param [in] param_dataSize Parameter dataSize
 * \param [in] ticks_MaxRingKernel Input scalar parameter MaxRingKernel.run_cycle_count
 * \param [in] instream_fromcpu The stream should be of size (param_dataSize * 4) bytes
 * \param [out] outstream_tocpu The stream should be of size (param_dataSize * 4) bytes
 * \param [in] routing_string string containing comma-separated 'from_name -> to_name' routing commands.
 */
void MaxRing(
	int32_t param_dataSize,
	uint64_t ticks_MaxRingKernel,
	const uint32_t *instream_fromcpu,
	uint32_t *outstream_tocpu,
	const char * routing_string);

/**
 * \brief Simple static non-blocking function for the interface 'default'.
 * 
 * Schedule to run on an engine and return immediately.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 * 
 * 
 * \param [in] param_dataSize Parameter dataSize
 * \param [in] ticks_MaxRingKernel Input scalar parameter MaxRingKernel.run_cycle_count
 * \param [in] instream_fromcpu The stream should be of size (param_dataSize * 4) bytes
 * \param [out] outstream_tocpu The stream should be of size (param_dataSize * 4) bytes
 * \param [in] routing_string string containing comma-separated 'from_name -> to_name' routing commands.
 * \return a handle on the execution status, or NULL in case of error.
 */
max_run_t *MaxRing_nonblock(
	int32_t param_dataSize,
	uint64_t ticks_MaxRingKernel,
	const uint32_t *instream_fromcpu,
	uint32_t *outstream_tocpu,
	const char * routing_string);

/**
 * \brief Advanced static interface, structure for the engine interface 'default'
 * 
 */
typedef struct { 
	int32_t param_dataSize; /**<  [in] Parameter dataSize */
	uint64_t ticks_MaxRingKernel; /**<  [in] Input scalar parameter MaxRingKernel.run_cycle_count */
	const uint32_t *instream_fromcpu; /**<  [in] The stream should be of size (param_dataSize * 4) bytes */
	uint32_t *outstream_tocpu; /**<  [out] The stream should be of size (param_dataSize * 4) bytes */
	const char * routing_string; /**<  [in] string containing comma-separated 'from_name -> to_name' routing commands. */
} MaxRing_actions_t;

/**
 * \brief Advanced static function for the interface 'default'.
 * 
 * \param [in] engine the engine on which the actions will be executed
 * \param [in,out] interface_actions actions to be executed
 */
void MaxRing_run(
	max_engine_t *engine,
	MaxRing_actions_t *interface_actions);

/**
 * \brief Advanced static non-blocking function for the interface 'default'.
 *
 * Schedule the actions to run on the engine and return immediately.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 *
 * 
 * \param [in] engine the engine on which the actions will be executed
 * \param [in,out] interface_actions actions to be executed
 * \return a handle on the execution status of the actions, or NULL in case of error.
 */
max_run_t *MaxRing_run_nonblock(
	max_engine_t *engine,
	MaxRing_actions_t *interface_actions);

/**
 * \brief Group run advanced static function for the interface 'default'.
 * 
 * \param group group to use
 * \param interface_actions actions to run
 *
 * Run the actions on the first device available in the group.
 */
void MaxRing_run_group(max_group_t *group, MaxRing_actions_t *interface_actions);

/**
 * \brief Group run advanced static non-blocking function for the interface 'default'.
 * 
 *
 * Schedule the actions to run on the first device available in the group and return immediately.
 * The status of the run must be checked with ::max_wait. 
 * Note that use of ::max_nowait is prohibited with non-blocking running on groups:
 * see the ::max_run_group_nonblock documentation for more explanation.
 *
 * \param group group to use
 * \param interface_actions actions to run
 * \return a handle on the execution status of the actions, or NULL in case of error.
 */
max_run_t *MaxRing_run_group_nonblock(max_group_t *group, MaxRing_actions_t *interface_actions);

/**
 * \brief Array run advanced static function for the interface 'default'.
 * 
 * \param engarray the array of devices to use
 * \param interface_actions the array of actions to run
 *
 * Run the array of actions on the array of engines.  The length of interface_actions
 * must match the size of engarray.
 */
void MaxRing_run_array(max_engarray_t *engarray, MaxRing_actions_t *interface_actions[]);

/**
 * \brief Array run advanced static non-blocking function for the interface 'default'.
 * 
 *
 * Schedule to run the array of actions on the array of engines, and return immediately.
 * The length of interface_actions must match the size of engarray.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 *
 * \param engarray the array of devices to use
 * \param interface_actions the array of actions to run
 * \return a handle on the execution status of the actions, or NULL in case of error.
 */
max_run_t *MaxRing_run_array_nonblock(max_engarray_t *engarray, MaxRing_actions_t *interface_actions[]);

/**
 * \brief Converts a static-interface action struct into a dynamic-interface max_actions_t struct.
 *
 * Note that this is an internal utility function used by other functions in the static interface.
 *
 * \param maxfile the maxfile to use
 * \param interface_actions the interface-specific actions to run
 * \return the dynamic-interface actions to run, or NULL in case of error.
 */
max_actions_t* MaxRing_convert(max_file_t *maxfile, MaxRing_actions_t *interface_actions);

/**
 * \brief Turn debugging on for the functions in the static 
 *          interface of this maxfile.
 * \param debug_directory directory for the generated files
 */
void MaxRing_debug(const char *debug_directory);

/**
 * \brief Initialise a maxfile.
 */
max_file_t* MaxRing_init(void);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* SLIC_DECLARATIONS_MaxRing_H */

