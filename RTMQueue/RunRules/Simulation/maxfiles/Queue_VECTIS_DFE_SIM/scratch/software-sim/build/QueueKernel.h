#ifndef QUEUEKERNEL_H_
#define QUEUEKERNEL_H_

// #include "KernelManagerBlockSync.h"


namespace maxcompilersim {

class QueueKernel : public KernelManagerBlockSync {
public:
  QueueKernel(const std::string &instance_name);

protected:
  virtual void runComputationCycle();
  virtual void resetComputation();
  virtual void resetComputationAfterFlush();
          void updateState();
          void preExecute();
  virtual int  getFlushLevelStart();

private:
  t_port_number m_controller;
  t_port_number m_x;
  t_port_number m_y;
  t_port_number m_s;
  HWOffsetFix<1,0,UNSIGNED> id22out_value;

  HWOffsetFix<1,0,UNSIGNED> id0out_io_controller_force_disabled;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id2out_data;

  HWOffsetFix<1,0,UNSIGNED> id2st_read_next_cycle;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id2st_last_read_value;

  HWOffsetFix<1,0,UNSIGNED> id4out_io_x_force_disabled;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id10out_data;

  HWOffsetFix<1,0,UNSIGNED> id10st_read_next_cycle;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id10st_last_read_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id42out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id12out_io_y_force_disabled;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id18out_data;

  HWOffsetFix<1,0,UNSIGNED> id18st_read_next_cycle;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id18st_last_read_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id43out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id44out_output[7];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id19out_a;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id41out_result[2];

  std::string format_string_QueueKernel_1 (const char* _format_arg_format_string, const HWOffsetFix<32,0,TWOSCOMPLEMENT> &_format_arg_0, const HWOffsetFix<32,0,TWOSCOMPLEMENT> &_format_arg_1, const HWOffsetFix<32,0,TWOSCOMPLEMENT> &_format_arg_2, const HWOffsetFix<32,0,TWOSCOMPLEMENT> &_format_arg_3, const HWOffsetFix<32,0,TWOSCOMPLEMENT> &_format_arg_4);
  std::string format_string_QueueKernel_2 (const char* _format_arg_format_string);
  HWOffsetFix<1,0,UNSIGNED> id25out_io_s_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id35out_value;

  HWOffsetFix<1,0,UNSIGNED> id46out_value;

  HWOffsetFix<49,0,UNSIGNED> id33out_value;

  HWOffsetFix<48,0,UNSIGNED> id34out_count;
  HWOffsetFix<1,0,UNSIGNED> id34out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id34st_count;

  HWOffsetFix<48,0,UNSIGNED> id45out_output[5];

  HWOffsetFix<48,0,UNSIGNED> id38out_run_cycle_count;

  HWOffsetFix<1,0,UNSIGNED> id39out_result[2];

  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits_1;
  const HWOffsetFix<32,0,TWOSCOMPLEMENT> c_hw_fix_32_0_sgn_undef;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_1;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_2;
  const HWOffsetFix<48,0,UNSIGNED> c_hw_fix_48_0_uns_undef;

  void execute0();
};

}

#endif /* QUEUEKERNEL_H_ */
