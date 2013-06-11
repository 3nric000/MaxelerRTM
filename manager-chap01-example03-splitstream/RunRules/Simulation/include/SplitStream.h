/**\file */
#ifndef SLIC_DECLARATIONS_SplitStream_H
#define SLIC_DECLARATIONS_SplitStream_H
#include "MaxSLiCInterface.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/*----------------------------------------------------------------------------*/
/*---------------------------- Interface default -----------------------------*/
/*----------------------------------------------------------------------------*/



/**
 * \brief Basic static function for the interface 'default'.
 * 
 * \param [in] param_dataSize Interface Parameter "dataSize".
 * \param [in] inscalar_SplitStreamKernel1_doAdd Input scalar parameter "SplitStreamKernel1.doAdd".
 * \param [in] inscalar_SplitStreamKernel2_doAdd Input scalar parameter "SplitStreamKernel2.doAdd".
 * \param [in] instream_x The stream should be of size (param_dataSize * 4) bytes.
 * \param [out] outstream_y The stream should be of size (param_dataSize * 4) bytes.
 * \param [in] routing_string A string containing comma-separated "from_name -> to_name" routing commands.
 */
void SplitStream(
	int32_t param_dataSize,
	uint64_t inscalar_SplitStreamKernel1_doAdd,
	uint64_t inscalar_SplitStreamKernel2_doAdd,
	const uint32_t *instream_x,
	uint32_t *outstream_y,
	const char * routing_string);

/**
 * \brief Basic static non-blocking function for the interface 'default'.
 * 
 * Schedule to run on an engine and return immediately.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 * 
 * 
 * \param [in] param_dataSize Interface Parameter "dataSize".
 * \param [in] inscalar_SplitStreamKernel1_doAdd Input scalar parameter "SplitStreamKernel1.doAdd".
 * \param [in] inscalar_SplitStreamKernel2_doAdd Input scalar parameter "SplitStreamKernel2.doAdd".
 * \param [in] instream_x The stream should be of size (param_dataSize * 4) bytes.
 * \param [out] outstream_y The stream should be of size (param_dataSize * 4) bytes.
 * \param [in] routing_string A string containing comma-separated "from_name -> to_name" routing commands.
 * \return A handle on the execution status, or NULL in case of error.
 */
max_run_t *SplitStream_nonblock(
	int32_t param_dataSize,
	uint64_t inscalar_SplitStreamKernel1_doAdd,
	uint64_t inscalar_SplitStreamKernel2_doAdd,
	const uint32_t *instream_x,
	uint32_t *outstream_y,
	const char * routing_string);

/**
 * \brief Advanced static interface, structure for the engine interface 'default'
 * 
 */
typedef struct { 
	int32_t param_dataSize; /**<  [in] Interface Parameter "dataSize". */
	uint64_t inscalar_SplitStreamKernel1_doAdd; /**<  [in] Input scalar parameter "SplitStreamKernel1.doAdd". */
	uint64_t inscalar_SplitStreamKernel2_doAdd; /**<  [in] Input scalar parameter "SplitStreamKernel2.doAdd". */
	const uint32_t *instream_x; /**<  [in] The stream should be of size (param_dataSize * 4) bytes. */
	uint32_t *outstream_y; /**<  [out] The stream should be of size (param_dataSize * 4) bytes. */
	const char * routing_string; /**<  [in] A string containing comma-separated "from_name -> to_name" routing commands. */
} SplitStream_actions_t;

/**
 * \brief Advanced static function for the interface 'default'.
 * 
 * \param [in] engine The engine on which the actions will be executed.
 * \param [in,out] interface_actions Actions to be executed.
 */
void SplitStream_run(
	max_engine_t *engine,
	SplitStream_actions_t *interface_actions);

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
max_run_t *SplitStream_run_nonblock(
	max_engine_t *engine,
	SplitStream_actions_t *interface_actions);

/**
 * \brief Group run advanced static function for the interface 'default'.
 * 
 * \param [in] group Group to use.
 * \param [in,out] interface_actions Actions to run.
 *
 * Run the actions on the first device available in the group.
 */
void SplitStream_run_group(max_group_t *group, SplitStream_actions_t *interface_actions);

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
max_run_t *SplitStream_run_group_nonblock(max_group_t *group, SplitStream_actions_t *interface_actions);

/**
 * \brief Array run advanced static function for the interface 'default'.
 * 
 * \param [in] engarray The array of devices to use.
 * \param [in,out] interface_actions The array of actions to run.
 *
 * Run the array of actions on the array of engines.  The length of interface_actions
 * must match the size of engarray.
 */
void SplitStream_run_array(max_engarray_t *engarray, SplitStream_actions_t *interface_actions[]);

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
max_run_t *SplitStream_run_array_nonblock(max_engarray_t *engarray, SplitStream_actions_t *interface_actions[]);

/**
 * \brief Converts a static-interface action struct into a dynamic-interface max_actions_t struct.
 *
 * Note that this is an internal utility function used by other functions in the static interface.
 *
 * \param [in] maxfile The maxfile to use.
 * \param [in] interface_actions The interface-specific actions to run.
 * \return The dynamic-interface actions to run, or NULL in case of error.
 */
max_actions_t* SplitStream_convert(max_file_t *maxfile, SplitStream_actions_t *interface_actions);

/**
 * \brief Initialise a maxfile.
 */
max_file_t* SplitStream_init(void);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* SLIC_DECLARATIONS_SplitStream_H */

