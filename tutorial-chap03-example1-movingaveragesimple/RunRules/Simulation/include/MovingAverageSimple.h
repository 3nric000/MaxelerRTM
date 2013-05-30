/**\file */
#ifndef SLIC_DECLARATIONS_MovingAverageSimple_H
#define SLIC_DECLARATIONS_MovingAverageSimple_H
#include "MaxSLiCInterface.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/*----------------------------------------------------------------------------*/
/*------------------------------- Mode default -------------------------------*/
/*----------------------------------------------------------------------------*/



/**
 * \brief Basic static function for the mode 'default'.
 * 
 * \param [in] param_N Mode Parameter "N".: Number of data items to process
 * \param [in] instream_x The stream should be of size (param_N * 4) bytes.
 * \param [out] outstream_y The stream should be of size (param_N * 4) bytes.
 */
void MovingAverageSimple(
	int32_t param_N,
	const float *instream_x,
	float *outstream_y);

/**
 * \brief Basic static non-blocking function for the mode 'default'.
 * 
 * Schedule to run on an engine and return immediately.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 * 
 * 
 * \param [in] param_N Mode Parameter "N".: Number of data items to process
 * \param [in] instream_x The stream should be of size (param_N * 4) bytes.
 * \param [out] outstream_y The stream should be of size (param_N * 4) bytes.
 * \return A handle on the execution status, or NULL in case of error.
 */
max_run_t *MovingAverageSimple_nonblock(
	int32_t param_N,
	const float *instream_x,
	float *outstream_y);

/**
 * \brief Advanced static interface, structure for the mode 'default'
 * 
 */
typedef struct { 
	int32_t param_N; /**<  [in] Mode Parameter "N".: Number of data items to process */
	const float *instream_x; /**<  [in] The stream should be of size (param_N * 4) bytes. */
	float *outstream_y; /**<  [out] The stream should be of size (param_N * 4) bytes. */
} MovingAverageSimple_actions_t;

/**
 * \brief Advanced static function for the mode 'default'.
 * 
 * \param [in] engine The engine on which the actions will be executed.
 * \param [in,out] mode_actions Actions to be executed.
 */
void MovingAverageSimple_run(
	max_engine_t *engine,
	MovingAverageSimple_actions_t *mode_actions);

/**
 * \brief Advanced static non-blocking function for the mode 'default'.
 *
 * Schedule the actions to run on the engine and return immediately.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 *
 * 
 * \param [in] engine The engine on which the actions will be executed.
 * \param [in] mode_actions Actions to be executed.
 * \return A handle on the execution status of the actions, or NULL in case of error.
 */
max_run_t *MovingAverageSimple_run_nonblock(
	max_engine_t *engine,
	MovingAverageSimple_actions_t *mode_actions);

/**
 * \brief Group run advanced static function for the mode 'default'.
 * 
 * \param [in] group Group to use.
 * \param [in,out] mode_actions Actions to run.
 *
 * Run the actions on the first device available in the group.
 */
void MovingAverageSimple_run_group(max_group_t *group, MovingAverageSimple_actions_t *mode_actions);

/**
 * \brief Group run advanced static non-blocking function for the mode 'default'.
 * 
 *
 * Schedule the actions to run on the first device available in the group and return immediately.
 * The status of the run must be checked with ::max_wait. 
 * Note that use of ::max_nowait is prohibited with non-blocking running on groups:
 * see the ::max_run_group_nonblock documentation for more explanation.
 *
 * \param [in] group Group to use.
 * \param [in] mode_actions Actions to run.
 * \return A handle on the execution status of the actions, or NULL in case of error.
 */
max_run_t *MovingAverageSimple_run_group_nonblock(max_group_t *group, MovingAverageSimple_actions_t *mode_actions);

/**
 * \brief Array run advanced static function for the mode 'default'.
 * 
 * \param [in] engarray The array of devices to use.
 * \param [in,out] mode_actions The array of actions to run.
 *
 * Run the array of actions on the array of engines.  The length of mode_actions
 * must match the size of engarray.
 */
void MovingAverageSimple_run_array(max_engarray_t *engarray, MovingAverageSimple_actions_t *mode_actions[]);

/**
 * \brief Array run advanced static non-blocking function for the mode 'default'.
 * 
 *
 * Schedule to run the array of actions on the array of engines, and return immediately.
 * The length of mode_actions must match the size of engarray.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 *
 * \param [in] engarray The array of devices to use.
 * \param [in] mode_actions The array of actions to run.
 * \return A handle on the execution status of the actions, or NULL in case of error.
 */
max_run_t *MovingAverageSimple_run_array_nonblock(max_engarray_t *engarray, MovingAverageSimple_actions_t *mode_actions[]);

/**
 * \brief Converts a static-interface action struct into a dynamic-interface max_actions_t struct.
 *
 * Note that this is an internal utility function used by other functions in the static interface.
 *
 * \param [in] maxfile The maxfile to use.
 * \param [in] mode_actions The mode-specific actions to run.
 * \return The dynamic-interface actions to run, or NULL in case of error.
 */
max_actions_t* MovingAverageSimple_convert(max_file_t *maxfile, MovingAverageSimple_actions_t *mode_actions);

/**
 * \brief Initialise a maxfile.
 */
max_file_t* MovingAverageSimple_init(void);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* SLIC_DECLARATIONS_MovingAverageSimple_H */

