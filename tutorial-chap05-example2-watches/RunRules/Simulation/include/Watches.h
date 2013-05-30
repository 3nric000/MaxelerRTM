/**\file */
#ifndef SLIC_DECLARATIONS_Watches_H
#define SLIC_DECLARATIONS_Watches_H
#include "MaxSLiCInterface.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
#define Watches_WatchesKernel_watch_stack_trace_x ("java.lang.Thread.getStackTrace(Thread.java:1426)/com.maxeler.photon.nodes.NodeWatch.addInput(NodeWatch.java:302)/com.maxeler.photon.libs.WatchFactory.watch(WatchFactory.java:136)/com.maxeler.photon.libs.WatchFactory.watch(WatchFactory.java:131)/com.maxeler.photon.libs.WatchFactory.watch(WatchFactory.java:127)/com.maxeler.maxcompiler.v2.kernelcompiler.types.base.DFEVar.watch(DFEVar.java:981)/watches.WatchesKernel.<init>(WatchesKernel.maxj:23)/watches.WatchesManager.main(WatchesManager.maxj:19)")
#define Watches_WatchesKernel_watch_stack_trace_prevOriginal ("java.lang.Thread.getStackTrace(Thread.java:1426)/com.maxeler.photon.nodes.NodeWatch.addInput(NodeWatch.java:302)/com.maxeler.photon.libs.WatchFactory.watch(WatchFactory.java:136)/com.maxeler.photon.libs.WatchFactory.watch(WatchFactory.java:131)/com.maxeler.photon.libs.WatchFactory.watch(WatchFactory.java:127)/com.maxeler.maxcompiler.v2.kernelcompiler.types.base.DFEVar.watch(DFEVar.java:981)/watches.WatchesKernel.<init>(WatchesKernel.maxj:27)/watches.WatchesManager.main(WatchesManager.maxj:19)")
#define Watches_WatchesKernel_watch_stack_trace_cnt ("java.lang.Thread.getStackTrace(Thread.java:1426)/com.maxeler.photon.nodes.NodeWatch.addInput(NodeWatch.java:302)/com.maxeler.photon.libs.WatchFactory.watch(WatchFactory.java:136)/com.maxeler.photon.libs.WatchFactory.watch(WatchFactory.java:131)/com.maxeler.photon.libs.WatchFactory.watch(WatchFactory.java:127)/com.maxeler.maxcompiler.v2.kernelcompiler.types.base.DFEVar.watch(DFEVar.java:981)/watches.WatchesKernel.<init>(WatchesKernel.maxj:32)/watches.WatchesManager.main(WatchesManager.maxj:19)")
#define Watches_WatchesKernel_watch_stack_trace_aboveLowerBound ("java.lang.Thread.getStackTrace(Thread.java:1426)/com.maxeler.photon.nodes.NodeWatch.addInput(NodeWatch.java:302)/com.maxeler.photon.libs.WatchFactory.watch(WatchFactory.java:136)/com.maxeler.photon.libs.WatchFactory.watch(WatchFactory.java:131)/com.maxeler.photon.libs.WatchFactory.watch(WatchFactory.java:127)/com.maxeler.maxcompiler.v2.kernelcompiler.types.base.DFEVar.watch(DFEVar.java:981)/watches.WatchesKernel.<init>(WatchesKernel.maxj:36)/watches.WatchesManager.main(WatchesManager.maxj:19)")
#define Watches_WatchesKernel_watch_stack_trace_prev ("java.lang.Thread.getStackTrace(Thread.java:1426)/com.maxeler.photon.nodes.NodeWatch.addInput(NodeWatch.java:302)/com.maxeler.photon.libs.WatchFactory.watch(WatchFactory.java:136)/com.maxeler.photon.libs.WatchFactory.watch(WatchFactory.java:131)/com.maxeler.photon.libs.WatchFactory.watch(WatchFactory.java:127)/com.maxeler.maxcompiler.v2.kernelcompiler.types.base.DFEVar.watch(DFEVar.java:981)/watches.WatchesKernel.<init>(WatchesKernel.maxj:39)/watches.WatchesManager.main(WatchesManager.maxj:19)")
#define Watches_WatchesKernel_watch_stack_trace_result ("java.lang.Thread.getStackTrace(Thread.java:1426)/com.maxeler.photon.nodes.NodeWatch.addInput(NodeWatch.java:302)/com.maxeler.photon.libs.WatchFactory.watch(WatchFactory.java:136)/com.maxeler.photon.libs.WatchFactory.watch(WatchFactory.java:131)/com.maxeler.photon.libs.WatchFactory.watch(WatchFactory.java:127)/com.maxeler.maxcompiler.v2.kernelcompiler.types.base.DFEVar.watch(DFEVar.java:981)/watches.WatchesKernel.<init>(WatchesKernel.maxj:45)/watches.WatchesManager.main(WatchesManager.maxj:19)")


/*----------------------------------------------------------------------------*/
/*---------------------------- Interface default -----------------------------*/
/*----------------------------------------------------------------------------*/



/**
 * \brief Basic static function for the interface 'default'.
 * 
 * \param [in] param_N Interface Parameter "N".: Number of data items to process
 * \param [in] inscalar_WatchesKernel_n Input scalar parameter "WatchesKernel.n".
 * \param [in] instream_x The stream should be of size (param_N * 4) bytes.
 * \param [out] outstream_y The stream should be of size (param_N * 4) bytes.
 */
void Watches(
	int32_t param_N,
	uint64_t inscalar_WatchesKernel_n,
	const float *instream_x,
	float *outstream_y);

/**
 * \brief Basic static non-blocking function for the interface 'default'.
 * 
 * Schedule to run on an engine and return immediately.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 * 
 * 
 * \param [in] param_N Interface Parameter "N".: Number of data items to process
 * \param [in] inscalar_WatchesKernel_n Input scalar parameter "WatchesKernel.n".
 * \param [in] instream_x The stream should be of size (param_N * 4) bytes.
 * \param [out] outstream_y The stream should be of size (param_N * 4) bytes.
 * \return A handle on the execution status, or NULL in case of error.
 */
max_run_t *Watches_nonblock(
	int32_t param_N,
	uint64_t inscalar_WatchesKernel_n,
	const float *instream_x,
	float *outstream_y);

/**
 * \brief Advanced static interface, structure for the engine interface 'default'
 * 
 */
typedef struct { 
	int32_t param_N; /**<  [in] Interface Parameter "N".: Number of data items to process */
	uint64_t inscalar_WatchesKernel_n; /**<  [in] Input scalar parameter "WatchesKernel.n". */
	const float *instream_x; /**<  [in] The stream should be of size (param_N * 4) bytes. */
	float *outstream_y; /**<  [out] The stream should be of size (param_N * 4) bytes. */
} Watches_actions_t;

/**
 * \brief Advanced static function for the interface 'default'.
 * 
 * \param [in] engine The engine on which the actions will be executed.
 * \param [in,out] interface_actions Actions to be executed.
 */
void Watches_run(
	max_engine_t *engine,
	Watches_actions_t *interface_actions);

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
max_run_t *Watches_run_nonblock(
	max_engine_t *engine,
	Watches_actions_t *interface_actions);

/**
 * \brief Group run advanced static function for the interface 'default'.
 * 
 * \param [in] group Group to use.
 * \param [in,out] interface_actions Actions to run.
 *
 * Run the actions on the first device available in the group.
 */
void Watches_run_group(max_group_t *group, Watches_actions_t *interface_actions);

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
max_run_t *Watches_run_group_nonblock(max_group_t *group, Watches_actions_t *interface_actions);

/**
 * \brief Array run advanced static function for the interface 'default'.
 * 
 * \param [in] engarray The array of devices to use.
 * \param [in,out] interface_actions The array of actions to run.
 *
 * Run the array of actions on the array of engines.  The length of interface_actions
 * must match the size of engarray.
 */
void Watches_run_array(max_engarray_t *engarray, Watches_actions_t *interface_actions[]);

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
max_run_t *Watches_run_array_nonblock(max_engarray_t *engarray, Watches_actions_t *interface_actions[]);

/**
 * \brief Converts a static-interface action struct into a dynamic-interface max_actions_t struct.
 *
 * Note that this is an internal utility function used by other functions in the static interface.
 *
 * \param [in] maxfile The maxfile to use.
 * \param [in] interface_actions The interface-specific actions to run.
 * \return The dynamic-interface actions to run, or NULL in case of error.
 */
max_actions_t* Watches_convert(max_file_t *maxfile, Watches_actions_t *interface_actions);

/**
 * \brief Initialise a maxfile.
 */
max_file_t* Watches_init(void);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* SLIC_DECLARATIONS_Watches_H */

