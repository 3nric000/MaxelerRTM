/**\file */
#ifndef SLIC_DECLARATIONS_CpuMain_H
#define SLIC_DECLARATIONS_CpuMain_H
#include "MaxSLiCInterface.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */



/*----------------------------------------------------------------------------*/
/*--------------------------- Interface writeLMem ----------------------------*/
/*----------------------------------------------------------------------------*/



/**
 * \brief Basic static function for the interface 'writeLMem'.
 * 
 * \param [in] param_address Interface Parameter "address".
 * \param [in] param_nbytes Interface Parameter "nbytes".
 * \param [in] instream_cpu_to_lmem The stream should be of size param_nbytes bytes.
 */
void CpuMain_writeLMem(
	int64_t param_address,
	int64_t param_nbytes,
	const void *instream_cpu_to_lmem);

/**
 * \brief Basic static non-blocking function for the interface 'writeLMem'.
 * 
 * Schedule to run on an engine and return immediately.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 * 
 * 
 * \param [in] param_address Interface Parameter "address".
 * \param [in] param_nbytes Interface Parameter "nbytes".
 * \param [in] instream_cpu_to_lmem The stream should be of size param_nbytes bytes.
 * \return A handle on the execution status, or NULL in case of error.
 */
max_run_t *CpuMain_writeLMem_nonblock(
	int64_t param_address,
	int64_t param_nbytes,
	const void *instream_cpu_to_lmem);

/**
 * \brief Advanced static interface, structure for the engine interface 'writeLMem'
 * 
 */
typedef struct { 
	int64_t param_address; /**<  [in] Interface Parameter "address". */
	int64_t param_nbytes; /**<  [in] Interface Parameter "nbytes". */
	const void *instream_cpu_to_lmem; /**<  [in] The stream should be of size param_nbytes bytes. */
} CpuMain_writeLMem_actions_t;

/**
 * \brief Advanced static function for the interface 'writeLMem'.
 * 
 * \param [in] engine The engine on which the actions will be executed.
 * \param [in,out] interface_actions Actions to be executed.
 */
void CpuMain_writeLMem_run(
	max_engine_t *engine,
	CpuMain_writeLMem_actions_t *interface_actions);

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
max_run_t *CpuMain_writeLMem_run_nonblock(
	max_engine_t *engine,
	CpuMain_writeLMem_actions_t *interface_actions);

/**
 * \brief Group run advanced static function for the interface 'writeLMem'.
 * 
 * \param [in] group Group to use.
 * \param [in,out] interface_actions Actions to run.
 *
 * Run the actions on the first device available in the group.
 */
void CpuMain_writeLMem_run_group(max_group_t *group, CpuMain_writeLMem_actions_t *interface_actions);

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
max_run_t *CpuMain_writeLMem_run_group_nonblock(max_group_t *group, CpuMain_writeLMem_actions_t *interface_actions);

/**
 * \brief Array run advanced static function for the interface 'writeLMem'.
 * 
 * \param [in] engarray The array of devices to use.
 * \param [in,out] interface_actions The array of actions to run.
 *
 * Run the array of actions on the array of engines.  The length of interface_actions
 * must match the size of engarray.
 */
void CpuMain_writeLMem_run_array(max_engarray_t *engarray, CpuMain_writeLMem_actions_t *interface_actions[]);

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
max_run_t *CpuMain_writeLMem_run_array_nonblock(max_engarray_t *engarray, CpuMain_writeLMem_actions_t *interface_actions[]);

/**
 * \brief Converts a static-interface action struct into a dynamic-interface max_actions_t struct.
 *
 * Note that this is an internal utility function used by other functions in the static interface.
 *
 * \param [in] maxfile The maxfile to use.
 * \param [in] interface_actions The interface-specific actions to run.
 * \return The dynamic-interface actions to run, or NULL in case of error.
 */
max_actions_t* CpuMain_writeLMem_convert(max_file_t *maxfile, CpuMain_writeLMem_actions_t *interface_actions);



/*----------------------------------------------------------------------------*/
/*---------------------------- Interface readLMem ----------------------------*/
/*----------------------------------------------------------------------------*/



/**
 * \brief Basic static function for the interface 'readLMem'.
 * 
 * \param [in] param_address Interface Parameter "address".
 * \param [in] param_nbytes Interface Parameter "nbytes".
 * \param [out] outstream_lmem_to_cpu The stream should be of size param_nbytes bytes.
 */
void CpuMain_readLMem(
	int64_t param_address,
	int64_t param_nbytes,
	void *outstream_lmem_to_cpu);

/**
 * \brief Basic static non-blocking function for the interface 'readLMem'.
 * 
 * Schedule to run on an engine and return immediately.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 * 
 * 
 * \param [in] param_address Interface Parameter "address".
 * \param [in] param_nbytes Interface Parameter "nbytes".
 * \param [out] outstream_lmem_to_cpu The stream should be of size param_nbytes bytes.
 * \return A handle on the execution status, or NULL in case of error.
 */
max_run_t *CpuMain_readLMem_nonblock(
	int64_t param_address,
	int64_t param_nbytes,
	void *outstream_lmem_to_cpu);

/**
 * \brief Advanced static interface, structure for the engine interface 'readLMem'
 * 
 */
typedef struct { 
	int64_t param_address; /**<  [in] Interface Parameter "address". */
	int64_t param_nbytes; /**<  [in] Interface Parameter "nbytes". */
	void *outstream_lmem_to_cpu; /**<  [out] The stream should be of size param_nbytes bytes. */
} CpuMain_readLMem_actions_t;

/**
 * \brief Advanced static function for the interface 'readLMem'.
 * 
 * \param [in] engine The engine on which the actions will be executed.
 * \param [in,out] interface_actions Actions to be executed.
 */
void CpuMain_readLMem_run(
	max_engine_t *engine,
	CpuMain_readLMem_actions_t *interface_actions);

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
max_run_t *CpuMain_readLMem_run_nonblock(
	max_engine_t *engine,
	CpuMain_readLMem_actions_t *interface_actions);

/**
 * \brief Group run advanced static function for the interface 'readLMem'.
 * 
 * \param [in] group Group to use.
 * \param [in,out] interface_actions Actions to run.
 *
 * Run the actions on the first device available in the group.
 */
void CpuMain_readLMem_run_group(max_group_t *group, CpuMain_readLMem_actions_t *interface_actions);

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
max_run_t *CpuMain_readLMem_run_group_nonblock(max_group_t *group, CpuMain_readLMem_actions_t *interface_actions);

/**
 * \brief Array run advanced static function for the interface 'readLMem'.
 * 
 * \param [in] engarray The array of devices to use.
 * \param [in,out] interface_actions The array of actions to run.
 *
 * Run the array of actions on the array of engines.  The length of interface_actions
 * must match the size of engarray.
 */
void CpuMain_readLMem_run_array(max_engarray_t *engarray, CpuMain_readLMem_actions_t *interface_actions[]);

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
max_run_t *CpuMain_readLMem_run_array_nonblock(max_engarray_t *engarray, CpuMain_readLMem_actions_t *interface_actions[]);

/**
 * \brief Converts a static-interface action struct into a dynamic-interface max_actions_t struct.
 *
 * Note that this is an internal utility function used by other functions in the static interface.
 *
 * \param [in] maxfile The maxfile to use.
 * \param [in] interface_actions The interface-specific actions to run.
 * \return The dynamic-interface actions to run, or NULL in case of error.
 */
max_actions_t* CpuMain_readLMem_convert(max_file_t *maxfile, CpuMain_readLMem_actions_t *interface_actions);



/*----------------------------------------------------------------------------*/
/*---------------------------- Interface default -----------------------------*/
/*----------------------------------------------------------------------------*/



/**
 * \brief Basic static function for the interface 'default'.
 * 
 * \param [in] param_c_0 Interface Parameter "c_0".
 * \param [in] param_c_1_0 Interface Parameter "c_1_0".
 * \param [in] param_c_1_1 Interface Parameter "c_1_1".
 * \param [in] param_c_1_2 Interface Parameter "c_1_2".
 * \param [in] param_c_1_3 Interface Parameter "c_1_3".
 * \param [in] param_c_1_4 Interface Parameter "c_1_4".
 * \param [in] param_c_2_0 Interface Parameter "c_2_0".
 * \param [in] param_c_2_1 Interface Parameter "c_2_1".
 * \param [in] param_c_2_2 Interface Parameter "c_2_2".
 * \param [in] param_c_2_3 Interface Parameter "c_2_3".
 * \param [in] param_c_2_4 Interface Parameter "c_2_4".
 * \param [in] param_c_3_0 Interface Parameter "c_3_0".
 * \param [in] param_c_3_1 Interface Parameter "c_3_1".
 * \param [in] param_c_3_2 Interface Parameter "c_3_2".
 * \param [in] param_c_3_3 Interface Parameter "c_3_3".
 * \param [in] param_c_3_4 Interface Parameter "c_3_4".
 * \param [in] param_n1 Interface Parameter "n1".
 * \param [in] param_n2 Interface Parameter "n2".
 * \param [in] instream_controller The stream should be of size ((((param_n1 * param_n2) * param_n2) * 10) * 4) bytes.
 */
void CpuMain(
	double param_c_0,
	double param_c_1_0,
	double param_c_1_1,
	double param_c_1_2,
	double param_c_1_3,
	double param_c_1_4,
	double param_c_2_0,
	double param_c_2_1,
	double param_c_2_2,
	double param_c_2_3,
	double param_c_2_4,
	double param_c_3_0,
	double param_c_3_1,
	double param_c_3_2,
	double param_c_3_3,
	double param_c_3_4,
	int64_t param_n1,
	int64_t param_n2,
	const int32_t *instream_controller);

/**
 * \brief Basic static non-blocking function for the interface 'default'.
 * 
 * Schedule to run on an engine and return immediately.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 * 
 * 
 * \param [in] param_c_0 Interface Parameter "c_0".
 * \param [in] param_c_1_0 Interface Parameter "c_1_0".
 * \param [in] param_c_1_1 Interface Parameter "c_1_1".
 * \param [in] param_c_1_2 Interface Parameter "c_1_2".
 * \param [in] param_c_1_3 Interface Parameter "c_1_3".
 * \param [in] param_c_1_4 Interface Parameter "c_1_4".
 * \param [in] param_c_2_0 Interface Parameter "c_2_0".
 * \param [in] param_c_2_1 Interface Parameter "c_2_1".
 * \param [in] param_c_2_2 Interface Parameter "c_2_2".
 * \param [in] param_c_2_3 Interface Parameter "c_2_3".
 * \param [in] param_c_2_4 Interface Parameter "c_2_4".
 * \param [in] param_c_3_0 Interface Parameter "c_3_0".
 * \param [in] param_c_3_1 Interface Parameter "c_3_1".
 * \param [in] param_c_3_2 Interface Parameter "c_3_2".
 * \param [in] param_c_3_3 Interface Parameter "c_3_3".
 * \param [in] param_c_3_4 Interface Parameter "c_3_4".
 * \param [in] param_n1 Interface Parameter "n1".
 * \param [in] param_n2 Interface Parameter "n2".
 * \param [in] instream_controller The stream should be of size ((((param_n1 * param_n2) * param_n2) * 10) * 4) bytes.
 * \return A handle on the execution status, or NULL in case of error.
 */
max_run_t *CpuMain_nonblock(
	double param_c_0,
	double param_c_1_0,
	double param_c_1_1,
	double param_c_1_2,
	double param_c_1_3,
	double param_c_1_4,
	double param_c_2_0,
	double param_c_2_1,
	double param_c_2_2,
	double param_c_2_3,
	double param_c_2_4,
	double param_c_3_0,
	double param_c_3_1,
	double param_c_3_2,
	double param_c_3_3,
	double param_c_3_4,
	int64_t param_n1,
	int64_t param_n2,
	const int32_t *instream_controller);

/**
 * \brief Advanced static interface, structure for the engine interface 'default'
 * 
 */
typedef struct { 
	double param_c_0; /**<  [in] Interface Parameter "c_0". */
	double param_c_1_0; /**<  [in] Interface Parameter "c_1_0". */
	double param_c_1_1; /**<  [in] Interface Parameter "c_1_1". */
	double param_c_1_2; /**<  [in] Interface Parameter "c_1_2". */
	double param_c_1_3; /**<  [in] Interface Parameter "c_1_3". */
	double param_c_1_4; /**<  [in] Interface Parameter "c_1_4". */
	double param_c_2_0; /**<  [in] Interface Parameter "c_2_0". */
	double param_c_2_1; /**<  [in] Interface Parameter "c_2_1". */
	double param_c_2_2; /**<  [in] Interface Parameter "c_2_2". */
	double param_c_2_3; /**<  [in] Interface Parameter "c_2_3". */
	double param_c_2_4; /**<  [in] Interface Parameter "c_2_4". */
	double param_c_3_0; /**<  [in] Interface Parameter "c_3_0". */
	double param_c_3_1; /**<  [in] Interface Parameter "c_3_1". */
	double param_c_3_2; /**<  [in] Interface Parameter "c_3_2". */
	double param_c_3_3; /**<  [in] Interface Parameter "c_3_3". */
	double param_c_3_4; /**<  [in] Interface Parameter "c_3_4". */
	int64_t param_n1; /**<  [in] Interface Parameter "n1". */
	int64_t param_n2; /**<  [in] Interface Parameter "n2". */
	const int32_t *instream_controller; /**<  [in] The stream should be of size ((((param_n1 * param_n2) * param_n2) * 10) * 4) bytes. */
} CpuMain_actions_t;

/**
 * \brief Advanced static function for the interface 'default'.
 * 
 * \param [in] engine The engine on which the actions will be executed.
 * \param [in,out] interface_actions Actions to be executed.
 */
void CpuMain_run(
	max_engine_t *engine,
	CpuMain_actions_t *interface_actions);

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
max_run_t *CpuMain_run_nonblock(
	max_engine_t *engine,
	CpuMain_actions_t *interface_actions);

/**
 * \brief Group run advanced static function for the interface 'default'.
 * 
 * \param [in] group Group to use.
 * \param [in,out] interface_actions Actions to run.
 *
 * Run the actions on the first device available in the group.
 */
void CpuMain_run_group(max_group_t *group, CpuMain_actions_t *interface_actions);

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
max_run_t *CpuMain_run_group_nonblock(max_group_t *group, CpuMain_actions_t *interface_actions);

/**
 * \brief Array run advanced static function for the interface 'default'.
 * 
 * \param [in] engarray The array of devices to use.
 * \param [in,out] interface_actions The array of actions to run.
 *
 * Run the array of actions on the array of engines.  The length of interface_actions
 * must match the size of engarray.
 */
void CpuMain_run_array(max_engarray_t *engarray, CpuMain_actions_t *interface_actions[]);

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
max_run_t *CpuMain_run_array_nonblock(max_engarray_t *engarray, CpuMain_actions_t *interface_actions[]);

/**
 * \brief Converts a static-interface action struct into a dynamic-interface max_actions_t struct.
 *
 * Note that this is an internal utility function used by other functions in the static interface.
 *
 * \param [in] maxfile The maxfile to use.
 * \param [in] interface_actions The interface-specific actions to run.
 * \return The dynamic-interface actions to run, or NULL in case of error.
 */
max_actions_t* CpuMain_convert(max_file_t *maxfile, CpuMain_actions_t *interface_actions);

/**
 * \brief Initialise a maxfile.
 */
max_file_t* CpuMain_init(void);

/* Error handling functions */
int CpuMain_has_errors(void);
const char* CpuMain_get_errors(void);
void CpuMain_clear_errors(void);
/* Free statically allocated maxfile data */
void CpuMain_free(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* SLIC_DECLARATIONS_CpuMain_H */

