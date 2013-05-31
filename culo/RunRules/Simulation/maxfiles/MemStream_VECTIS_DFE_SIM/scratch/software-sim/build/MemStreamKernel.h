#ifndef MEMSTREAMKERNEL_H_
#define MEMSTREAMKERNEL_H_

// #include "KernelManagerBlockSync.h"


namespace maxcompilersim {

class MemStreamKernel : public KernelManagerBlockSync {
public:
  MemStreamKernel(const std::string &instance_name);

protected:
  virtual void runComputationCycle();
  virtual void resetComputation();
  virtual void resetComputationAfterFlush();
          void updateState();
          void preExecute();
  virtual int  getFlushLevelStart();

private:
  t_port_number m_x;
  t_port_number m_y;
  t_port_number m_s;
  HWOffsetFix<1,0,UNSIGNED> id10out_io_s_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id0out_io_x_force_disabled;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id2out_data;

  HWOffsetFix<1,0,UNSIGNED> id2st_read_next_cycle;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id2st_last_read_value;

  HWOffsetFix<1,0,UNSIGNED> id3out_io_y_force_disabled;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id5out_data;

  HWOffsetFix<1,0,UNSIGNED> id5st_read_next_cycle;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id5st_last_read_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id6out_a;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id26out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id20out_value;

  HWOffsetFix<1,0,UNSIGNED> id28out_value;

  HWOffsetFix<49,0,UNSIGNED> id18out_value;

  HWOffsetFix<48,0,UNSIGNED> id19out_count;
  HWOffsetFix<1,0,UNSIGNED> id19out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id19st_count;

  HWOffsetFix<48,0,UNSIGNED> id27out_output[5];

  HWOffsetFix<48,0,UNSIGNED> id23out_run_cycle_count;

  HWOffsetFix<1,0,UNSIGNED> id24out_result[2];

  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits;
  const HWOffsetFix<32,0,TWOSCOMPLEMENT> c_hw_fix_32_0_sgn_undef;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits_1;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_1;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_2;
  const HWOffsetFix<48,0,UNSIGNED> c_hw_fix_48_0_uns_undef;

  void execute0();
};

}

#endif /* MEMSTREAMKERNEL_H_ */
