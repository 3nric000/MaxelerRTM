#ifndef CPUSTREAMKERNEL_H_
#define CPUSTREAMKERNEL_H_

// #include "KernelManagerBlockSync.h"


namespace maxcompilersim {

class CpuStreamKernel : public KernelManagerBlockSync {
public:
  CpuStreamKernel(const std::string &instance_name);

protected:
  virtual void runComputationCycle();
  virtual void resetComputation();
  virtual void resetComputationAfterFlush();
          void updateState();
          void preExecute();
  virtual int  getFlushLevelStart();

private:
  t_port_number m_str;
  t_port_number m_strout;
  HWOffsetFix<1,0,UNSIGNED> id17out_io_strout_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id0out_io_str_force_disabled;

  HWOffsetFix<32,0,UNSIGNED> id2out_data;

  HWOffsetFix<1,0,UNSIGNED> id2st_read_next_cycle;
  HWOffsetFix<32,0,UNSIGNED> id2st_last_read_value;

  HWOffsetFix<4,0,UNSIGNED> id56out_delay_eq_0;

  long id40st_store_idx;
  long id40st_store_idx_max;

  HWOffsetFix<32,0,UNSIGNED> id40sta_store[10];

  HWOffsetFix<7,0,UNSIGNED> id57out_delay_eq_1;

  long id46st_store_idx;
  long id46st_store_idx_max;

  HWOffsetFix<32,0,UNSIGNED> id46sta_store[93];

  long id45st_store_idx;
  long id45st_store_idx_max;

  HWOffsetFix<32,0,UNSIGNED> id45sta_store[10];

  HWOffsetFix<32,0,UNSIGNED> id52out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id54out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id49out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id33out_result[2];

  long id41st_store_idx;
  long id41st_store_idx_max;

  HWOffsetFix<32,0,UNSIGNED> id41sta_store[10];

  HWOffsetFix<32,0,UNSIGNED> id51out_output[6];

  HWOffsetFix<32,0,UNSIGNED> id34out_result[2];

  HWOffsetFix<7,0,UNSIGNED> id58out_delay_eq_2;

  long id47st_store_idx;
  long id47st_store_idx_max;

  HWOffsetFix<32,0,UNSIGNED> id47sta_store[102];

  HWOffsetFix<32,0,UNSIGNED> id35out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id27out_value;

  HWOffsetFix<1,0,UNSIGNED> id55out_value;

  HWOffsetFix<49,0,UNSIGNED> id25out_value;

  HWOffsetFix<48,0,UNSIGNED> id26out_count;
  HWOffsetFix<1,0,UNSIGNED> id26out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id26st_count;

  HWOffsetFix<48,0,UNSIGNED> id53out_output[5];

  HWOffsetFix<48,0,UNSIGNED> id30out_run_cycle_count;

  HWOffsetFix<1,0,UNSIGNED> id31out_result[2];

  HWOffsetFix<7,0,UNSIGNED> id59out_ce_delay_eq_0;

  HWOffsetFix<7,0,UNSIGNED> id60out_ce_delay_eq_1;

  HWOffsetFix<7,0,UNSIGNED> id61out_ce_delay_eq_2;

  HWOffsetFix<7,0,UNSIGNED> id62out_ce_delay_eq_3;

  HWOffsetFix<7,0,UNSIGNED> id63out_ce_delay_eq_4;

  HWOffsetFix<7,0,UNSIGNED> id64out_ce_delay_eq_5;

  HWOffsetFix<7,0,UNSIGNED> id65out_ce_delay_eq_6;

  HWOffsetFix<7,0,UNSIGNED> id66out_ce_delay_eq_7;

  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_undef;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits_1;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_1;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_2;
  const HWOffsetFix<48,0,UNSIGNED> c_hw_fix_48_0_uns_undef;

  void execute0();
};

}

#endif /* CPUSTREAMKERNEL_H_ */
