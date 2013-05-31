/**\file */
#ifndef SLIC_DECLARATIONS_cpu_main_H
#define SLIC_DECLARATIONS_cpu_main_H
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
void cpu_main_writeLMem(
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
max_run_t *cpu_main_writeLMem_nonblock(
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
} cpu_main_writeLMem_actions_t;

/**
 * \brief Advanced static function for the interface 'writeLMem'.
 * 
 * \param [in] engine The engine on which the actions will be executed.
 * \param [in,out] interface_actions Actions to be executed.
 */
void cpu_main_writeLMem_run(
	max_engine_t *engine,
	cpu_main_writeLMem_actions_t *interface_actions);

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
max_run_t *cpu_main_writeLMem_run_nonblock(
	max_engine_t *engine,
	cpu_main_writeLMem_actions_t *interface_actions);

/**
 * \brief Group run advanced static function for the interface 'writeLMem'.
 * 
 * \param [in] group Group to use.
 * \param [in,out] interface_actions Actions to run.
 *
 * Run the actions on the first device available in the group.
 */
void cpu_main_writeLMem_run_group(max_group_t *group, cpu_main_writeLMem_actions_t *interface_actions);

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
max_run_t *cpu_main_writeLMem_run_group_nonblock(max_group_t *group, cpu_main_writeLMem_actions_t *interface_actions);

/**
 * \brief Array run advanced static function for the interface 'writeLMem'.
 * 
 * \param [in] engarray The array of devices to use.
 * \param [in,out] interface_actions The array of actions to run.
 *
 * Run the array of actions on the array of engines.  The length of interface_actions
 * must match the size of engarray.
 */
void cpu_main_writeLMem_run_array(max_engarray_t *engarray, cpu_main_writeLMem_actions_t *interface_actions[]);

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
max_run_t *cpu_main_writeLMem_run_array_nonblock(max_engarray_t *engarray, cpu_main_writeLMem_actions_t *interface_actions[]);

/**
 * \brief Converts a static-interface action struct into a dynamic-interface max_actions_t struct.
 *
 * Note that this is an internal utility function used by other functions in the static interface.
 *
 * \param [in] maxfile The maxfile to use.
 * \param [in] interface_actions The interface-specific actions to run.
 * \return The dynamic-interface actions to run, or NULL in case of error.
 */
max_actions_t* cpu_main_writeLMem_convert(max_file_t *maxfile, cpu_main_writeLMem_actions_t *interface_actions);



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
void cpu_main_readLMem(
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
max_run_t *cpu_main_readLMem_nonblock(
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
} cpu_main_readLMem_actions_t;

/**
 * \brief Advanced static function for the interface 'readLMem'.
 * 
 * \param [in] engine The engine on which the actions will be executed.
 * \param [in,out] interface_actions Actions to be executed.
 */
void cpu_main_readLMem_run(
	max_engine_t *engine,
	cpu_main_readLMem_actions_t *interface_actions);

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
max_run_t *cpu_main_readLMem_run_nonblock(
	max_engine_t *engine,
	cpu_main_readLMem_actions_t *interface_actions);

/**
 * \brief Group run advanced static function for the interface 'readLMem'.
 * 
 * \param [in] group Group to use.
 * \param [in,out] interface_actions Actions to run.
 *
 * Run the actions on the first device available in the group.
 */
void cpu_main_readLMem_run_group(max_group_t *group, cpu_main_readLMem_actions_t *interface_actions);

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
max_run_t *cpu_main_readLMem_run_group_nonblock(max_group_t *group, cpu_main_readLMem_actions_t *interface_actions);

/**
 * \brief Array run advanced static function for the interface 'readLMem'.
 * 
 * \param [in] engarray The array of devices to use.
 * \param [in,out] interface_actions The array of actions to run.
 *
 * Run the array of actions on the array of engines.  The length of interface_actions
 * must match the size of engarray.
 */
void cpu_main_readLMem_run_array(max_engarray_t *engarray, cpu_main_readLMem_actions_t *interface_actions[]);

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
max_run_t *cpu_main_readLMem_run_array_nonblock(max_engarray_t *engarray, cpu_main_readLMem_actions_t *interface_actions[]);

/**
 * \brief Converts a static-interface action struct into a dynamic-interface max_actions_t struct.
 *
 * Note that this is an internal utility function used by other functions in the static interface.
 *
 * \param [in] maxfile The maxfile to use.
 * \param [in] interface_actions The interface-specific actions to run.
 * \return The dynamic-interface actions to run, or NULL in case of error.
 */
max_actions_t* cpu_main_readLMem_convert(max_file_t *maxfile, cpu_main_readLMem_actions_t *interface_actions);



/*----------------------------------------------------------------------------*/
/*---------------------------- Interface default -----------------------------*/
/*----------------------------------------------------------------------------*/



/**
 * \brief Basic static function for the interface 'default'.
 * 
 * \param [in] param_burst Interface Parameter "burst".
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
 * \param [in] param_offF Interface Parameter "offF".
 * \param [in] param_offM Interface Parameter "offM".
 * \param [in] param_offS Interface Parameter "offS".
 * \param [in] param_xzSize Interface Parameter "xzSize".
 * \param [in] instream_dvv_value The stream should be of size 32 bytes.
 * \param [in] instream_pp_value The stream should be of size 32 bytes.
 * \param [in] instream_source_container_value The stream should be of size 32 bytes.
 */
void cpu_main(
	int64_t param_burst,
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
	int64_t param_offF,
	int64_t param_offM,
	int64_t param_offS,
	int64_t param_xzSize,
	const float *instream_dvv_value,
	const float *instream_pp_value,
	const float *instream_source_container_value);

/**
 * \brief Basic static non-blocking function for the interface 'default'.
 * 
 * Schedule to run on an engine and return immediately.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 * 
 * 
 * \param [in] param_burst Interface Parameter "burst".
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
 * \param [in] param_offF Interface Parameter "offF".
 * \param [in] param_offM Interface Parameter "offM".
 * \param [in] param_offS Interface Parameter "offS".
 * \param [in] param_xzSize Interface Parameter "xzSize".
 * \param [in] instream_dvv_value The stream should be of size 32 bytes.
 * \param [in] instream_pp_value The stream should be of size 32 bytes.
 * \param [in] instream_source_container_value The stream should be of size 32 bytes.
 * \return A handle on the execution status, or NULL in case of error.
 */
max_run_t *cpu_main_nonblock(
	int64_t param_burst,
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
	int64_t param_offF,
	int64_t param_offM,
	int64_t param_offS,
	int64_t param_xzSize,
	const float *instream_dvv_value,
	const float *instream_pp_value,
	const float *instream_source_container_value);

/**
 * \brief Advanced static interface, structure for the engine interface 'default'
 * 
 */
typedef struct { 
	int64_t param_burst; /**<  [in] Interface Parameter "burst". */
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
	int64_t param_offF; /**<  [in] Interface Parameter "offF". */
	int64_t param_offM; /**<  [in] Interface Parameter "offM". */
	int64_t param_offS; /**<  [in] Interface Parameter "offS". */
	int64_t param_xzSize; /**<  [in] Interface Parameter "xzSize". */
	const float *instream_dvv_value; /**<  [in] The stream should be of size 32 bytes. */
	const float *instream_pp_value; /**<  [in] The stream should be of size 32 bytes. */
	const float *instream_source_container_value; /**<  [in] The stream should be of size 32 bytes. */
} cpu_main_actions_t;

/**
 * \brief Advanced static function for the interface 'default'.
 * 
 * \param [in] engine The engine on which the actions will be executed.
 * \param [in,out] interface_actions Actions to be executed.
 */
void cpu_main_run(
	max_engine_t *engine,
	cpu_main_actions_t *interface_actions);

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
max_run_t *cpu_main_run_nonblock(
	max_engine_t *engine,
	cpu_main_actions_t *interface_actions);

/**
 * \brief Group run advanced static function for the interface 'default'.
 * 
 * \param [in] group Group to use.
 * \param [in,out] interface_actions Actions to run.
 *
 * Run the actions on the first device available in the group.
 */
void cpu_main_run_group(max_group_t *group, cpu_main_actions_t *interface_actions);

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
max_run_t *cpu_main_run_group_nonblock(max_group_t *group, cpu_main_actions_t *interface_actions);

/**
 * \brief Array run advanced static function for the interface 'default'.
 * 
 * \param [in] engarray The array of devices to use.
 * \param [in,out] interface_actions The array of actions to run.
 *
 * Run the array of actions on the array of engines.  The length of interface_actions
 * must match the size of engarray.
 */
void cpu_main_run_array(max_engarray_t *engarray, cpu_main_actions_t *interface_actions[]);

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
max_run_t *cpu_main_run_array_nonblock(max_engarray_t *engarray, cpu_main_actions_t *interface_actions[]);

/**
 * \brief Converts a static-interface action struct into a dynamic-interface max_actions_t struct.
 *
 * Note that this is an internal utility function used by other functions in the static interface.
 *
 * \param [in] maxfile The maxfile to use.
 * \param [in] interface_actions The interface-specific actions to run.
 * \return The dynamic-interface actions to run, or NULL in case of error.
 */
max_actions_t* cpu_main_convert(max_file_t *maxfile, cpu_main_actions_t *interface_actions);

/**
 * \brief Initialise a maxfile.
 */
max_file_t* cpu_main_init(void);

/* Error handling functions */
int cpu_main_has_errors(void);
const char* cpu_main_get_errors(void);
void cpu_main_clear_errors(void);
/* Free statically allocated maxfile data */
void cpu_main_free(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* SLIC_DECLARATIONS_cpu_main_H */

