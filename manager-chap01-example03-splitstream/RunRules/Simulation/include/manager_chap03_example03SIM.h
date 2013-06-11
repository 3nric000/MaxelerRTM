/**\file */
#ifndef SLIC_DECLARATIONS_manager_chap03_example03SIM_H
#define SLIC_DECLARATIONS_manager_chap03_example03SIM_H
#include "MaxSLiCInterface.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * \brief Simple static function for the interface 'default'
 * 
 * \param [in] routing_string string containing comma-separated 'from_name -> to_name' routing commands.
 * \param [in] ticks_SplitStreamKernel1 Scalar parameter
 * \param [in] ticks_SplitStreamKernel2 Scalar parameter
 * \param [in] inscalar_SplitStreamKernel1_doAdd Scalar parameter
 * \param [in] inscalar_SplitStreamKernel2_doAdd Scalar parameter
 * \param [in] instream_x stream x
 * \param [in] instream_size_x size of the stream instream_x in bytes
 * \param [out] outstream_y stream y
 * \param [in] outstream_size_y size of the stream outstream_y in bytes
 */
void manager_chap03_example03SIM(
	const char * routing_string,
	uint64_t ticks_SplitStreamKernel1,
	uint64_t ticks_SplitStreamKernel2,
	uint64_t inscalar_SplitStreamKernel1_doAdd,
	uint64_t inscalar_SplitStreamKernel2_doAdd,
	const void *instream_x,
	size_t instream_size_x,
	void *outstream_y,
	size_t outstream_size_y);

/**
 * \brief Advanced static interface, structure for the engine interface 'default'
 * 
 */
typedef struct { 
	const char * routing_string; /**<  [in] string containing comma-separated 'from_name -> to_name' routing commands. */
	uint64_t ticks_SplitStreamKernel1; /**<  [in] Scalar parameter */
	uint64_t ticks_SplitStreamKernel2; /**<  [in] Scalar parameter */
	uint64_t inscalar_SplitStreamKernel1_doAdd; /**<  [in] Scalar parameter */
	uint64_t inscalar_SplitStreamKernel2_doAdd; /**<  [in] Scalar parameter */
	const void *instream_x; /**<  [in] stream x */
	size_t instream_size_x; /**<  [in] size of the stream instream_x in bytes */
	void *outstream_y; /**<  [out] stream y */
	size_t outstream_size_y; /**<  [in] size of the stream outstream_y in bytes */
} manager_chap03_example03SIM_actions_t;

/**
 * \brief Advanced static function for the interface 'default'
 * \param [in] engine the engine on which the actions will be executed
 * \param [in,out] interface_actions actions to be executed
 */
void manager_chap03_example03SIM_run(
	max_engine_t *engine,
	manager_chap03_example03SIM_actions_t *interface_actions);

/**
 * \brief Group run advanced static function for the interface 'default'
 * \param group group to use
 * \param interface_actions actions to run
 *
 * Run the actions on the first device available in the group.
 */
void manager_chap03_example03SIM_run_group(max_group_t *group, manager_chap03_example03SIM_actions_t *interface_actions);

/**
 * \brief Array run advanced static function for the interface 'default'
 * \param engarray the array of devices to use
 * \param interface_actions the array of actions to run
 *
 * Run the array of actions on the array of engines.  The length of interface_actions
 * must match the size of engarray.
 */
void manager_chap03_example03SIM_run_array(max_engarray_t *engarray, manager_chap03_example03SIM_actions_t *interface_actions[]);

max_actions_t* manager_chap03_example03SIM_convert(max_file_t *maxfile, manager_chap03_example03SIM_actions_t *interface_actions);

/**
 * \brief Turn debugging on for the functions in the static 
 *          interface of this maxfile.
 * \param debug_directory directory for the generated files
 */
void manager_chap03_example03SIM_debug(const char *debug_directory);

/**
 * \brief Initialise a maxfile.
 */
max_file_t* manager_chap03_example03SIM_init(void);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* SLIC_DECLARATIONS_manager_chap03_example03SIM_H */

