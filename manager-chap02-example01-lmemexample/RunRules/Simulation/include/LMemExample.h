/**\file */
#ifndef SLIC_DECLARATIONS_LMemExample_H
#define SLIC_DECLARATIONS_LMemExample_H
#include "MaxSLiCInterface.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

int LMemExample_has_errors(void);
const char* LMemExample_get_errors(void);


/*----------------------------------------------------------------------------*/
/*--------------------------- Interface writeLMem ----------------------------*/
/*----------------------------------------------------------------------------*/



/**
 * \brief Basic static function for the interface 'writeLMem'.
 * 
 * \param [in] param_size Interface Parameter "size".
 * \param [in] param_start Interface Parameter "start".
 * \param [in] instream_fromcpu The stream should be of size (param_size * 4) bytes.
 */
void LMemExample_writeLMem(
	int32_t param_size,
	int32_t param_start,
	const int32_t *instream_fromcpu);

/**
 * \brief Basic static non-blocking function for the interface 'writeLMem'.
 * 
 * Schedule to run on an engine and return immediately.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 * 
 * 
 * \param [in] param_size Interface Parameter "size".
 * \param [in] param_start Interface Parameter "start".
 * \param [in] instream_fromcpu The stream should be of size (param_size * 4) bytes.
 * \return A handle on the execution status, or NULL in case of error.
 */
max_run_t *LMemExample_writeLMem_nonblock(
	int32_t param_size,
	int32_t param_start,
	const int32_t *instream_fromcpu);

/**
 * \brief Advanced static interface, structure for the engine interface 'writeLMem'
 * 
 */
typedef struct { 
	int32_t param_size; /**<  [in] Interface Parameter "size". */
	int32_t param_start; /**<  [in] Interface Parameter "start". */
	const int32_t *instream_fromcpu; /**<  [in] The stream should be of size (param_size * 4) bytes. */
} LMemExample_writeLMem_actions_t;

/**
 * \brief Advanced static function for the interface 'writeLMem'.
 * 
 * \param [in] engine The engine on which the actions will be executed.
 * \param [in,out] interface_actions Actions to be executed.
 */
void LMemExample_writeLMem_run(
	max_engine_t *engine,
	LMemExample_writeLMem_actions_t *interface_actions);

/**
 * \brief Advanced static non-blocking function for the interface 'writeLMem'.
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
max_run_t *LMemExample_writeLMem_run_nonblock(
	max_engine_t *engine,
	LMemExample_writeLMem_actions_t *interface_actions);

/**
 * \brief Group run advanced static function for the interface 'writeLMem'.
 * 
 * \param [in] group Group to use.
 * \param [in,out] interface_actions Actions to run.
 *
 * Run the actions on the first device available in the group.
 */
void LMemExample_writeLMem_run_group(max_group_t *group, LMemExample_writeLMem_actions_t *interface_actions);

/**
 * \brief Group run advanced static non-blocking function for the interface 'writeLMem'.
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
max_run_t *LMemExample_writeLMem_run_group_nonblock(max_group_t *group, LMemExample_writeLMem_actions_t *interface_actions);

/**
 * \brief Array run advanced static function for the interface 'writeLMem'.
 * 
 * \param [in] engarray The array of devices to use.
 * \param [in,out] interface_actions The array of actions to run.
 *
 * Run the array of actions on the array of engines.  The length of interface_actions
 * must match the size of engarray.
 */
void LMemExample_writeLMem_run_array(max_engarray_t *engarray, LMemExample_writeLMem_actions_t *interface_actions[]);

/**
 * \brief Array run advanced static non-blocking function for the interface 'writeLMem'.
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
max_run_t *LMemExample_writeLMem_run_array_nonblock(max_engarray_t *engarray, LMemExample_writeLMem_actions_t *interface_actions[]);

/**
 * \brief Converts a static-interface action struct into a dynamic-interface max_actions_t struct.
 *
 * Note that this is an internal utility function used by other functions in the static interface.
 *
 * \param [in] maxfile The maxfile to use.
 * \param [in] interface_actions The interface-specific actions to run.
 * \return The dynamic-interface actions to run, or NULL in case of error.
 */
max_actions_t* LMemExample_writeLMem_convert(max_file_t *maxfile, LMemExample_writeLMem_actions_t *interface_actions);



/*----------------------------------------------------------------------------*/
/*---------------------------- Interface readLMem ----------------------------*/
/*----------------------------------------------------------------------------*/



/**
 * \brief Basic static function for the interface 'readLMem'.
 * 
 * \param [in] param_size Interface Parameter "size".
 * \param [in] param_start Interface Parameter "start".
 * \param [out] outstream_tocpu The stream should be of size (param_size * 4) bytes.
 */
void LMemExample_readLMem(
	int32_t param_size,
	int32_t param_start,
	int32_t *outstream_tocpu);

/**
 * \brief Basic static non-blocking function for the interface 'readLMem'.
 * 
 * Schedule to run on an engine and return immediately.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 * 
 * 
 * \param [in] param_size Interface Parameter "size".
 * \param [in] param_start Interface Parameter "start".
 * \param [out] outstream_tocpu The stream should be of size (param_size * 4) bytes.
 * \return A handle on the execution status, or NULL in case of error.
 */
max_run_t *LMemExample_readLMem_nonblock(
	int32_t param_size,
	int32_t param_start,
	int32_t *outstream_tocpu);

/**
 * \brief Advanced static interface, structure for the engine interface 'readLMem'
 * 
 */
typedef struct { 
	int32_t param_size; /**<  [in] Interface Parameter "size". */
	int32_t param_start; /**<  [in] Interface Parameter "start". */
	int32_t *outstream_tocpu; /**<  [out] The stream should be of size (param_size * 4) bytes. */
} LMemExample_readLMem_actions_t;

/**
 * \brief Advanced static function for the interface 'readLMem'.
 * 
 * \param [in] engine The engine on which the actions will be executed.
 * \param [in,out] interface_actions Actions to be executed.
 */
void LMemExample_readLMem_run(
	max_engine_t *engine,
	LMemExample_readLMem_actions_t *interface_actions);

/**
 * \brief Advanced static non-blocking function for the interface 'readLMem'.
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
max_run_t *LMemExample_readLMem_run_nonblock(
	max_engine_t *engine,
	LMemExample_readLMem_actions_t *interface_actions);

/**
 * \brief Group run advanced static function for the interface 'readLMem'.
 * 
 * \param [in] group Group to use.
 * \param [in,out] interface_actions Actions to run.
 *
 * Run the actions on the first device available in the group.
 */
void LMemExample_readLMem_run_group(max_group_t *group, LMemExample_readLMem_actions_t *interface_actions);

/**
 * \brief Group run advanced static non-blocking function for the interface 'readLMem'.
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
max_run_t *LMemExample_readLMem_run_group_nonblock(max_group_t *group, LMemExample_readLMem_actions_t *interface_actions);

/**
 * \brief Array run advanced static function for the interface 'readLMem'.
 * 
 * \param [in] engarray The array of devices to use.
 * \param [in,out] interface_actions The array of actions to run.
 *
 * Run the array of actions on the array of engines.  The length of interface_actions
 * must match the size of engarray.
 */
void LMemExample_readLMem_run_array(max_engarray_t *engarray, LMemExample_readLMem_actions_t *interface_actions[]);

/**
 * \brief Array run advanced static non-blocking function for the interface 'readLMem'.
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
max_run_t *LMemExample_readLMem_run_array_nonblock(max_engarray_t *engarray, LMemExample_readLMem_actions_t *interface_actions[]);

/**
 * \brief Converts a static-interface action struct into a dynamic-interface max_actions_t struct.
 *
 * Note that this is an internal utility function used by other functions in the static interface.
 *
 * \param [in] maxfile The maxfile to use.
 * \param [in] interface_actions The interface-specific actions to run.
 * \return The dynamic-interface actions to run, or NULL in case of error.
 */
max_actions_t* LMemExample_readLMem_convert(max_file_t *maxfile, LMemExample_readLMem_actions_t *interface_actions);



/*----------------------------------------------------------------------------*/
/*---------------------------- Interface default -----------------------------*/
/*----------------------------------------------------------------------------*/



/**
 * \brief Basic static function for the interface 'default'.
 * 
 * \param [in] param_N Interface Parameter "N".
 * \param [in] instream_fromcpu Stream "fromcpu".
 * \param [in] instream_size_fromcpu The size of the stream instream_fromcpu in bytes.
 * \param [out] outstream_tocpu Stream "tocpu".
 * \param [in] outstream_size_tocpu The size of the stream outstream_tocpu in bytes.
 * \param [in] lmem_address_cpu2lmem Linear LMem control for "cpu2lmem" stream: base address, in bytes.
 * \param [in] lmem_arr_size_cpu2lmem Linear LMem control for "cpu2lmem" stream: array size, in bytes.
 * \param [out] lmem_address_inA Linear LMem control for "inA" stream: base address, in bytes.
 * \param [out] lmem_arr_size_inA Linear LMem control for "inA" stream: array size, in bytes.
 * \param [out] lmem_address_inB Linear LMem control for "inB" stream: base address, in bytes.
 * \param [out] lmem_arr_size_inB Linear LMem control for "inB" stream: array size, in bytes.
 * \param [out] lmem_address_lmem2cpu Linear LMem control for "lmem2cpu" stream: base address, in bytes.
 * \param [out] lmem_arr_size_lmem2cpu Linear LMem control for "lmem2cpu" stream: array size, in bytes.
 */
void LMemExample(
	int32_t param_N,
	const void *instream_fromcpu,
	size_t instream_size_fromcpu,
	void *outstream_tocpu,
	size_t outstream_size_tocpu,
	size_t lmem_address_cpu2lmem,
	size_t lmem_arr_size_cpu2lmem,
	size_t lmem_address_inA,
	size_t lmem_arr_size_inA,
	size_t lmem_address_inB,
	size_t lmem_arr_size_inB,
	size_t lmem_address_lmem2cpu,
	size_t lmem_arr_size_lmem2cpu);

/**
 * \brief Basic static non-blocking function for the interface 'default'.
 * 
 * Schedule to run on an engine and return immediately.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 * 
 * 
 * \param [in] param_N Interface Parameter "N".
 * \param [in] instream_fromcpu Stream "fromcpu".
 * \param [in] instream_size_fromcpu The size of the stream instream_fromcpu in bytes.
 * \param [out] outstream_tocpu Stream "tocpu".
 * \param [in] outstream_size_tocpu The size of the stream outstream_tocpu in bytes.
 * \param [in] lmem_address_cpu2lmem Linear LMem control for "cpu2lmem" stream: base address, in bytes.
 * \param [in] lmem_arr_size_cpu2lmem Linear LMem control for "cpu2lmem" stream: array size, in bytes.
 * \param [out] lmem_address_inA Linear LMem control for "inA" stream: base address, in bytes.
 * \param [out] lmem_arr_size_inA Linear LMem control for "inA" stream: array size, in bytes.
 * \param [out] lmem_address_inB Linear LMem control for "inB" stream: base address, in bytes.
 * \param [out] lmem_arr_size_inB Linear LMem control for "inB" stream: array size, in bytes.
 * \param [out] lmem_address_lmem2cpu Linear LMem control for "lmem2cpu" stream: base address, in bytes.
 * \param [out] lmem_arr_size_lmem2cpu Linear LMem control for "lmem2cpu" stream: array size, in bytes.
 * \return A handle on the execution status, or NULL in case of error.
 */
max_run_t *LMemExample_nonblock(
	int32_t param_N,
	const void *instream_fromcpu,
	size_t instream_size_fromcpu,
	void *outstream_tocpu,
	size_t outstream_size_tocpu,
	size_t lmem_address_cpu2lmem,
	size_t lmem_arr_size_cpu2lmem,
	size_t lmem_address_inA,
	size_t lmem_arr_size_inA,
	size_t lmem_address_inB,
	size_t lmem_arr_size_inB,
	size_t lmem_address_lmem2cpu,
	size_t lmem_arr_size_lmem2cpu);

/**
 * \brief Advanced static interface, structure for the engine interface 'default'
 * 
 */
typedef struct { 
	int32_t param_N; /**<  [in] Interface Parameter "N". */
	const void *instream_fromcpu; /**<  [in] Stream "fromcpu". */
	size_t instream_size_fromcpu; /**<  [in] The size of the stream instream_fromcpu in bytes. */
	void *outstream_tocpu; /**<  [out] Stream "tocpu". */
	size_t outstream_size_tocpu; /**<  [in] The size of the stream outstream_tocpu in bytes. */
	size_t lmem_address_cpu2lmem; /**<  [in] Linear LMem control for "cpu2lmem" stream: base address, in bytes. */
	size_t lmem_arr_size_cpu2lmem; /**<  [in] Linear LMem control for "cpu2lmem" stream: array size, in bytes. */
	size_t lmem_address_inA; /**<  [out] Linear LMem control for "inA" stream: base address, in bytes. */
	size_t lmem_arr_size_inA; /**<  [out] Linear LMem control for "inA" stream: array size, in bytes. */
	size_t lmem_address_inB; /**<  [out] Linear LMem control for "inB" stream: base address, in bytes. */
	size_t lmem_arr_size_inB; /**<  [out] Linear LMem control for "inB" stream: array size, in bytes. */
	size_t lmem_address_lmem2cpu; /**<  [out] Linear LMem control for "lmem2cpu" stream: base address, in bytes. */
	size_t lmem_arr_size_lmem2cpu; /**<  [out] Linear LMem control for "lmem2cpu" stream: array size, in bytes. */
} LMemExample_actions_t;

/**
 * \brief Advanced static function for the interface 'default'.
 * 
 * \param [in] engine The engine on which the actions will be executed.
 * \param [in,out] interface_actions Actions to be executed.
 */
void LMemExample_run(
	max_engine_t *engine,
	LMemExample_actions_t *interface_actions);

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
max_run_t *LMemExample_run_nonblock(
	max_engine_t *engine,
	LMemExample_actions_t *interface_actions);

/**
 * \brief Group run advanced static function for the interface 'default'.
 * 
 * \param [in] group Group to use.
 * \param [in,out] interface_actions Actions to run.
 *
 * Run the actions on the first device available in the group.
 */
void LMemExample_run_group(max_group_t *group, LMemExample_actions_t *interface_actions);

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
max_run_t *LMemExample_run_group_nonblock(max_group_t *group, LMemExample_actions_t *interface_actions);

/**
 * \brief Array run advanced static function for the interface 'default'.
 * 
 * \param [in] engarray The array of devices to use.
 * \param [in,out] interface_actions The array of actions to run.
 *
 * Run the array of actions on the array of engines.  The length of interface_actions
 * must match the size of engarray.
 */
void LMemExample_run_array(max_engarray_t *engarray, LMemExample_actions_t *interface_actions[]);

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
max_run_t *LMemExample_run_array_nonblock(max_engarray_t *engarray, LMemExample_actions_t *interface_actions[]);

/**
 * \brief Converts a static-interface action struct into a dynamic-interface max_actions_t struct.
 *
 * Note that this is an internal utility function used by other functions in the static interface.
 *
 * \param [in] maxfile The maxfile to use.
 * \param [in] interface_actions The interface-specific actions to run.
 * \return The dynamic-interface actions to run, or NULL in case of error.
 */
max_actions_t* LMemExample_convert(max_file_t *maxfile, LMemExample_actions_t *interface_actions);

/**
 * \brief Initialise a maxfile.
 */
max_file_t* LMemExample_init(void);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* SLIC_DECLARATIONS_LMemExample_H */

