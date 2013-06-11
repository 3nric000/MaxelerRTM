/**\file */
#ifndef SLIC_DECLARATIONS_manager_chap02_example2SIM_H
#define SLIC_DECLARATIONS_manager_chap02_example2SIM_H
#include "MaxSLiCInterface.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * \brief Simple static function for the interface 'default'
 * 
 * \param [in] ticks_DualKernelKernel1 Scalar parameter
 * \param [in] ticks_DualKernelKernel2 Scalar parameter
 * \param [in] inscalar_DualKernelKernel1_doAdd Scalar parameter
 * \param [in] inscalar_DualKernelKernel2_doAdd Scalar parameter
 * \param [in] instream_x1 stream x1
 * \param [in] instream_size_x1 size of the stream instream_x1 in bytes
 * \param [in] instream_x2 stream x2
 * \param [in] instream_size_x2 size of the stream instream_x2 in bytes
 * \param [out] outstream_y1 stream y1
 * \param [in] outstream_size_y1 size of the stream outstream_y1 in bytes
 * \param [out] outstream_y2 stream y2
 * \param [in] outstream_size_y2 size of the stream outstream_y2 in bytes
 */
void manager_chap02_example2SIM(
	uint64_t ticks_DualKernelKernel1,
	uint64_t ticks_DualKernelKernel2,
	uint64_t inscalar_DualKernelKernel1_doAdd,
	uint64_t inscalar_DualKernelKernel2_doAdd,
	const void *instream_x1,
	size_t instream_size_x1,
	const void *instream_x2,
	size_t instream_size_x2,
	void *outstream_y1,
	size_t outstream_size_y1,
	void *outstream_y2,
	size_t outstream_size_y2);

/**
 * \brief Advanced static interface, structure for the engine interface 'default'
 * 
 */
typedef struct { 
	uint64_t ticks_DualKernelKernel1; /**<  [in] Scalar parameter */
	uint64_t ticks_DualKernelKernel2; /**<  [in] Scalar parameter */
	uint64_t inscalar_DualKernelKernel1_doAdd; /**<  [in] Scalar parameter */
	uint64_t inscalar_DualKernelKernel2_doAdd; /**<  [in] Scalar parameter */
	const void *instream_x1; /**<  [in] stream x1 */
	size_t instream_size_x1; /**<  [in] size of the stream instream_x1 in bytes */
	const void *instream_x2; /**<  [in] stream x2 */
	size_t instream_size_x2; /**<  [in] size of the stream instream_x2 in bytes */
	void *outstream_y1; /**<  [out] stream y1 */
	size_t outstream_size_y1; /**<  [in] size of the stream outstream_y1 in bytes */
	void *outstream_y2; /**<  [out] stream y2 */
	size_t outstream_size_y2; /**<  [in] size of the stream outstream_y2 in bytes */
} manager_chap02_example2SIM_actions_t;

/**
 * \brief Advanced static function for the interface 'default'
 * \param [in] engine the engine on which the actions will be executed
 * \param [in,out] interface_actions actions to be executed
 */
void manager_chap02_example2SIM_run(
	max_engine_t *engine,
	manager_chap02_example2SIM_actions_t *interface_actions);

/**
 * \brief Group run advanced static function for the interface 'default'
 * \param group group to use
 * \param interface_actions actions to run
 *
 * Run the actions on the first device available in the group.
 */
void manager_chap02_example2SIM_run_group(max_group_t *group, manager_chap02_example2SIM_actions_t *interface_actions);

/**
 * \brief Array run advanced static function for the interface 'default'
 * \param engarray the array of devices to use
 * \param interface_actions the array of actions to run
 *
 * Run the array of actions on the array of engines.  The length of interface_actions
 * must match the size of engarray.
 */
void manager_chap02_example2SIM_run_array(max_engarray_t *engarray, manager_chap02_example2SIM_actions_t *interface_actions[]);

max_actions_t* manager_chap02_example2SIM_convert(max_file_t *maxfile, manager_chap02_example2SIM_actions_t *interface_actions);

/**
 * \brief Turn debugging on for the functions in the static 
 *          interface of this maxfile.
 * \param debug_directory directory for the generated files
 */
void manager_chap02_example2SIM_debug(const char *debug_directory);

/**
 * \brief Initialise a maxfile.
 */
max_file_t* manager_chap02_example2SIM_init(void);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* SLIC_DECLARATIONS_manager_chap02_example2SIM_H */

