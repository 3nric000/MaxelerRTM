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
  HWOffsetFix<1,0,UNSIGNED> id20out_value;

  HWOffsetFix<1,0,UNSIGNED> id3out_io_controller_force_disabled;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id5out_data;

  HWOffsetFix<1,0,UNSIGNED> id5st_read_next_cycle;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id5st_last_read_value;

  HWOffsetFix<1,0,UNSIGNED> id7out_io_x_force_disabled;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id13out_data;

  HWOffsetFix<1,0,UNSIGNED> id13st_read_next_cycle;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id13st_last_read_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id39out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id14out_io_y_force_disabled;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id16out_data;

  HWOffsetFix<1,0,UNSIGNED> id16st_read_next_cycle;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id16st_last_read_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id40out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id41out_output[7];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id17out_a;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id38out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id45out_value;

  HWOffsetFix<33,0,UNSIGNED> id1out_value;

  HWOffsetFix<32,0,UNSIGNED> id2out_count;
  HWOffsetFix<1,0,UNSIGNED> id2out_wrap;

  HWOffsetFix<33,0,UNSIGNED> id2st_count;

  std::string format_string_QueueKernel_1 (const char* _format_arg_format_string, const HWOffsetFix<32,0,TWOSCOMPLEMENT> &_format_arg_0, const HWOffsetFix<32,0,TWOSCOMPLEMENT> &_format_arg_1, const HWOffsetFix<32,0,TWOSCOMPLEMENT> &_format_arg_2, const HWOffsetFix<32,0,TWOSCOMPLEMENT> &_format_arg_3, const HWOffsetFix<32,0,TWOSCOMPLEMENT> &_format_arg_4, const HWOffsetFix<32,0,UNSIGNED> &_format_arg_5);
  std::string format_string_QueueKernel_2 (const char* _format_arg_format_string);
  HWOffsetFix<1,0,UNSIGNED> id23out_io_s_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id33out_value;

  HWOffsetFix<1,0,UNSIGNED> id44out_value;

  HWOffsetFix<49,0,UNSIGNED> id31out_value;

  HWOffsetFix<48,0,UNSIGNED> id32out_count;
  HWOffsetFix<1,0,UNSIGNED> id32out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id32st_count;

  HWOffsetFix<48,0,UNSIGNED> id43out_output[5];

  HWOffsetFix<48,0,UNSIGNED> id36out_run_cycle_count;

  HWOffsetFix<1,0,UNSIGNED> id37out_result[2];

  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits_1;
  const HWOffsetFix<32,0,TWOSCOMPLEMENT> c_hw_fix_32_0_sgn_undef;
  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits;
  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits_1;
  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits_2;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_1;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_2;
  const HWOffsetFix<48,0,UNSIGNED> c_hw_fix_48_0_uns_undef;

  void execute0();
};

}

#endif /* QUEUEKERNEL_H_ */
