/**\file */
#ifndef SLIC_DECLARATIONS_manager_chap02_example02SIM_H
#define SLIC_DECLARATIONS_manager_chap02_example02SIM_H
#include "MaxSLiCInterface.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * \brief Simple static function for the interface 'default'
 * 
 * \param [in] ticks_ControlGroupKernel Scalar parameter
 * \param [in] instream_fromcpu stream fromcpu
 * \param [in] instream_size_fromcpu size of the stream instream_fromcpu in bytes
 * \param [out] outstream_tocpu stream tocpu
 * \param [in] outstream_size_tocpu size of the stream outstream_tocpu in bytes
 * \param [in] lmem_address_cpu2lmem linear lmem control for "cpu2lmem" stream: base address, in bytes.
 * \param [in] lmem_size_cpu2lmem linear lmem control for "cpu2lmem" stream: array size, in bytes.
 * \param [in] lmem_address_oData linear lmem control for "oData" stream: base address, in bytes.
 * \param [in] lmem_size_oData linear lmem control for "oData" stream: array size, in bytes.
 * \param [out] lmem_address_lmem2cpu linear lmem control for "lmem2cpu" stream: base address, in bytes.
 * \param [out] lmem_size_lmem2cpu linear lmem control for "lmem2cpu" stream: array size, in bytes.
 * \param [out] lmem_address_inA linear lmem control for "inA" stream: base address, in bytes.
 * \param [out] lmem_size_inA linear lmem control for "inA" stream: array size, in bytes.
 * \param [out] lmem_address_inB linear lmem control for "inB" stream: base address, in bytes.
 * \param [out] lmem_size_inB linear lmem control for "inB" stream: array size, in bytes.
 */
void manager_chap02_example02SIM(
	uint64_t ticks_ControlGroupKernel,
	const void *instream_fromcpu,
	size_t instream_size_fromcpu,
	void *outstream_tocpu,
	size_t outstream_size_tocpu,
	int lmem_address_cpu2lmem,
	int lmem_size_cpu2lmem,
	int lmem_address_oData,
	int lmem_size_oData,
	int lmem_address_lmem2cpu,
	int lmem_size_lmem2cpu,
	int lmem_address_inA,
	int lmem_size_inA,
	int lmem_address_inB,
	int lmem_size_inB);

/**
 * \brief Advanced static interface, structure for the engine interface 'default'
 * 
 */
typedef struct { 
	uint64_t ticks_ControlGroupKernel; /**<  [in] Scalar parameter */
	const void *instream_fromcpu; /**<  [in] stream fromcpu */
	size_t instream_size_fromcpu; /**<  [in] size of the stream instream_fromcpu in bytes */
	void *outstream_tocpu; /**<  [out] stream tocpu */
	size_t outstream_size_tocpu; /**<  [in] size of the stream outstream_tocpu in bytes */
	int lmem_address_cpu2lmem; /**<  [in] linear lmem control for "cpu2lmem" stream: base address, in bytes. */
	int lmem_size_cpu2lmem; /**<  [in] linear lmem control for "cpu2lmem" stream: array size, in bytes. */
	int lmem_address_oData; /**<  [in] linear lmem control for "oData" stream: base address, in bytes. */
	int lmem_size_oData; /**<  [in] linear lmem control for "oData" stream: array size, in bytes. */
	int lmem_address_lmem2cpu; /**<  [out] linear lmem control for "lmem2cpu" stream: base address, in bytes. */
	int lmem_size_lmem2cpu; /**<  [out] linear lmem control for "lmem2cpu" stream: array size, in bytes. */
	int lmem_address_inA; /**<  [out] linear lmem control for "inA" stream: base address, in bytes. */
	int lmem_size_inA; /**<  [out] linear lmem control for "inA" stream: array size, in bytes. */
	int lmem_address_inB; /**<  [out] linear lmem control for "inB" stream: base address, in bytes. */
	int lmem_size_inB; /**<  [out] linear lmem control for "inB" stream: array size, in bytes. */
} manager_chap02_example02SIM_actions_t;

/**
 * \brief Advanced static function for the interface 'default'
 * \param [in] engine the engine on which the actions will be executed
 * \param [in,out] interface_actions actions to be executed
 */
void manager_chap02_example02SIM_run(
	max_engine_t *engine,
	manager_chap02_example02SIM_actions_t *interface_actions);

/**
 * \brief Group run advanced static function for the interface 'default'
 * \param group group to use
 * \param interface_actions actions to run
 *
 * Run the actions on the first device available in the group.
 */
void manager_chap02_example02SIM_run_group(max_group_t *group, manager_chap02_example02SIM_actions_t *interface_actions);

/**
 * \brief Array run advanced static function for the interface 'default'
 * \param engarray the array of devices to use
 * \param interface_actions the array of actions to run
 *
 * Run the array of actions on the array of engines.  The length of interface_actions
 * must match the size of engarray.
 */
void manager_chap02_example02SIM_run_array(max_engarray_t *engarray, manager_chap02_example02SIM_actions_t *interface_actions[]);

max_actions_t* manager_chap02_example02SIM_convert(max_file_t *maxfile, manager_chap02_example02SIM_actions_t *interface_actions);

/**
 * \brief Turn debugging on for the functions in the static 
 *          interface of this maxfile.
 * \param debug_directory directory for the generated files
 */
void manager_chap02_example02SIM_debug(const char *debug_directory);

/**
 * \brief Initialise a maxfile.
 */
max_file_t* manager_chap02_example02SIM_init(void);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* SLIC_DECLARATIONS_manager_chap02_example02SIM_H */

