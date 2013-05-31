#ifndef CPU_MAINKERNEL_H_
#define CPU_MAINKERNEL_H_

// #include "KernelManagerBlockSync.h"


namespace maxcompilersim {

class cpu_mainKernel : public KernelManagerBlockSync {
public:
  cpu_mainKernel(const std::string &instance_name);

protected:
  virtual void runComputationCycle();
  virtual void resetComputation();
  virtual void resetComputationAfterFlush();
          void updateState();
          void preExecute();
  virtual int  getFlushLevelStart();

private:
  t_port_number m_p;
  t_port_number m_pp_value;
  t_port_number m_dvv_value;
  t_port_number m_source_container_value;
  t_port_number m_pp;
  HWOffsetFix<1,0,UNSIGNED> id111out_io_pp_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id0out_io_p_force_disabled;

  HWFloat<8,24> id2out_data;

  HWOffsetFix<1,0,UNSIGNED> id2st_read_next_cycle;
  HWFloat<8,24> id2st_last_read_value;

  HWFloat<8,24> id156out_output[1045];

  HWFloat<8,24> id161out_output[1045];

  HWFloat<8,24> id162out_output[1045];

  HWFloat<8,24> id163out_output[1045];

  HWFloat<8,24> id164out_output[565];

  HWFloat<8,24> id165out_output[85];

  HWFloat<8,24> id166out_output[85];

  HWFloat<8,24> id167out_output[85];

  HWFloat<8,24> id168out_output[85];

  HWFloat<8,24> id169out_output[36];

  HWFloat<8,24> id170out_output[3];

  HWFloat<8,24> id171out_output[10];

  HWFloat<8,24> id172out_output[3];

  HWFloat<8,24> id173out_output[3];

  HWFloat<8,24> id174out_output[8];

  HWFloat<8,24> id175out_output[7];

  HWFloat<8,24> id176out_output[6];

  HWFloat<8,24> id177out_output[9];

  HWFloat<8,24> id178out_output[4];

  HWFloat<8,24> id179out_output[11];

  HWFloat<8,24> id180out_output[104];

  HWFloat<8,24> id181out_output[40];

  HWFloat<8,24> id127out_floatOut[2];

  HWOffsetFix<1,0,UNSIGNED> id4out_io_pp_value_force_disabled;

  HWFloat<8,24> id6out_data;

  HWOffsetFix<1,0,UNSIGNED> id6st_read_next_cycle;
  HWFloat<8,24> id6st_last_read_value;

  HWFloat<8,24> id60out_result[13];

  HWOffsetFix<1,0,UNSIGNED> id7out_io_dvv_value_force_disabled;

  HWFloat<8,24> id9out_data;

  HWOffsetFix<1,0,UNSIGNED> id9st_read_next_cycle;
  HWFloat<8,24> id9st_last_read_value;

  HWFloat<8,24> id3out_c_0;

  HWFloat<8,24> id61out_result[9];

  HWFloat<8,24> id13out_c_1_0;

  HWFloat<8,24> id62out_result[13];

  HWFloat<8,24> id63out_result[9];

  HWFloat<8,24> id64out_result[13];

  HWFloat<8,24> id14out_c_1_1;

  HWFloat<8,24> id65out_result[13];

  HWFloat<8,24> id66out_result[9];

  HWFloat<8,24> id67out_result[13];

  HWFloat<8,24> id15out_c_1_2;

  HWFloat<8,24> id68out_result[13];

  HWFloat<8,24> id69out_result[9];

  HWFloat<8,24> id70out_result[13];

  HWFloat<8,24> id16out_c_1_3;

  HWFloat<8,24> id71out_result[13];

  HWFloat<8,24> id72out_result[9];

  HWFloat<8,24> id73out_result[13];

  HWFloat<8,24> id17out_c_1_4;

  HWFloat<8,24> id74out_result[13];

  HWFloat<8,24> id75out_result[9];

  HWFloat<8,24> id76out_result[13];

  HWFloat<8,24> id18out_c_2_0;

  HWFloat<8,24> id77out_result[13];

  HWFloat<8,24> id78out_result[9];

  HWFloat<8,24> id79out_result[13];

  HWFloat<8,24> id19out_c_2_1;

  HWFloat<8,24> id182out_output[70];

  HWFloat<8,24> id80out_result[13];

  HWFloat<8,24> id81out_result[9];

  HWFloat<8,24> id82out_result[13];

  HWFloat<8,24> id20out_c_2_2;

  HWFloat<8,24> id183out_output[109];

  HWFloat<8,24> id83out_result[13];

  HWFloat<8,24> id84out_result[9];

  HWFloat<8,24> id85out_result[13];

  HWFloat<8,24> id21out_c_2_3;

  HWFloat<8,24> id184out_output[109];

  HWFloat<8,24> id86out_result[13];

  HWFloat<8,24> id87out_result[9];

  HWFloat<8,24> id88out_result[13];

  HWFloat<8,24> id22out_c_2_4;

  HWFloat<8,24> id185out_output[109];

  HWFloat<8,24> id89out_result[13];

  HWFloat<8,24> id90out_result[9];

  HWFloat<8,24> id91out_result[13];

  HWFloat<8,24> id23out_c_3_0;

  HWFloat<8,24> id186out_output[589];

  HWFloat<8,24> id92out_result[13];

  HWFloat<8,24> id93out_result[9];

  HWFloat<8,24> id94out_result[13];

  HWFloat<8,24> id24out_c_3_1;

  HWFloat<8,24> id187out_output[1069];

  HWFloat<8,24> id95out_result[13];

  HWFloat<8,24> id96out_result[9];

  HWFloat<8,24> id97out_result[13];

  HWFloat<8,24> id25out_c_3_2;

  HWFloat<8,24> id188out_output[1069];

  HWFloat<8,24> id98out_result[13];

  HWFloat<8,24> id99out_result[9];

  HWFloat<8,24> id100out_result[13];

  HWFloat<8,24> id26out_c_3_3;

  HWFloat<8,24> id189out_output[1069];

  HWFloat<8,24> id101out_result[13];

  HWFloat<8,24> id102out_result[9];

  HWFloat<8,24> id103out_result[13];

  HWFloat<8,24> id27out_c_3_4;

  HWFloat<8,24> id159out_output[1069];

  HWFloat<8,24> id104out_result[13];

  HWFloat<8,24> id105out_result[9];

  HWFloat<8,24> id106out_result[13];

  HWFloat<8,24> id107out_result[9];

  HWFloat<8,24> id108out_result[13];

  HWOffsetFix<1,0,UNSIGNED> id10out_io_source_container_value_force_disabled;

  HWFloat<8,24> id12out_data;

  HWOffsetFix<1,0,UNSIGNED> id12st_read_next_cycle;
  HWFloat<8,24> id12st_last_read_value;

  HWFloat<8,24> id109out_result[13];

  HWOffsetFix<1,0,UNSIGNED> id121out_value;

  HWOffsetFix<1,0,UNSIGNED> id190out_value;

  HWOffsetFix<49,0,UNSIGNED> id119out_value;

  HWOffsetFix<48,0,UNSIGNED> id120out_count;
  HWOffsetFix<1,0,UNSIGNED> id120out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id120st_count;

  HWOffsetFix<48,0,UNSIGNED> id160out_output[5];

  HWOffsetFix<48,0,UNSIGNED> id124out_run_cycle_count;

  HWOffsetFix<1,0,UNSIGNED> id125out_result[2];

  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits;
  const HWFloat<8,24> c_hw_flt_8_24_undef;
  const HWFloat<8,24> c_hw_flt_8_24_2_0val;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits_1;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_1;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_2;
  const HWOffsetFix<48,0,UNSIGNED> c_hw_fix_48_0_uns_undef;

  void execute0();
};

}

#endif /* CPU_MAINKERNEL_H_ */
