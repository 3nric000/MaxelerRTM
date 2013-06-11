#ifndef LINEARKERNEL_H_
#define LINEARKERNEL_H_

// #include "KernelManagerBlockSync.h"


namespace maxcompilersim {

class linearKernel : public KernelManagerBlockSync {
public:
  linearKernel(const std::string &instance_name);

protected:
  virtual void runComputationCycle();
  virtual void resetComputation();
  virtual void resetComputationAfterFlush();
          void updateState();
          void preExecute();
  virtual int  getFlushLevelStart();

private:
  t_port_number m_controller;
  t_port_number m_p;
  t_port_number m_pp;
  t_port_number m_dvv;
  t_port_number m_py;
  t_port_number m_px;
  t_port_number m_source_container;
  t_port_number m_ppresult;
  HWOffsetFix<1,0,UNSIGNED> id140out_value;

  HWOffsetFix<1,0,UNSIGNED> id223out_value;

  HWOffsetFix<33,0,UNSIGNED> id1out_value;

  HWOffsetFix<32,0,UNSIGNED> id2out_count;
  HWOffsetFix<1,0,UNSIGNED> id2out_wrap;

  HWOffsetFix<33,0,UNSIGNED> id2st_count;

  HWOffsetFix<1,0,UNSIGNED> id3out_io_controller_force_disabled;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id5out_data;

  HWOffsetFix<1,0,UNSIGNED> id5st_read_next_cycle;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id5st_last_read_value;

  HWOffsetFix<1,0,UNSIGNED> id7out_io_p_force_disabled;

  HWFloat<8,24> id13out_data;

  HWOffsetFix<1,0,UNSIGNED> id13st_read_next_cycle;
  HWFloat<8,24> id13st_last_read_value;

  HWFloat<8,24> id164out_output[3];

  HWFloat<8,24> id199out_output[10];

  HWFloat<8,24> id200out_output[3];

  HWFloat<8,24> id201out_output[3];

  HWFloat<8,24> id202out_output[8];

  HWFloat<8,24> id203out_output[7];

  HWFloat<8,24> id204out_output[6];

  HWFloat<8,24> id205out_output[9];

  HWFloat<8,24> id206out_output[4];

  HWFloat<8,24> id207out_output[11];

  HWFloat<8,24> id158out_floatOut[2];

  HWOffsetFix<1,0,UNSIGNED> id160out_output[56];

  HWOffsetFix<1,0,UNSIGNED> id15out_io_pp_force_disabled;

  HWFloat<8,24> id21out_data;

  HWOffsetFix<1,0,UNSIGNED> id21st_read_next_cycle;
  HWFloat<8,24> id21st_last_read_value;

  HWFloat<8,24> id62out_result[13];

  HWFloat<8,24> id193out_output[143];

  HWOffsetFix<1,0,UNSIGNED> id161out_output[114];

  HWOffsetFix<1,0,UNSIGNED> id23out_io_dvv_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id162out_output[89];

  HWFloat<8,24> id29out_data;

  HWOffsetFix<1,0,UNSIGNED> id29st_read_next_cycle;
  HWFloat<8,24> id29st_last_read_value;

  HWFloat<8,24> id44out_c_0;

  HWFloat<8,24> id63out_result[9];

  HWFloat<8,24> id45out_c_1_0;

  HWFloat<8,24> id66out_result[13];

  HWFloat<8,24> id67out_result[9];

  HWFloat<8,24> id68out_result[13];

  HWFloat<8,24> id46out_c_1_1;

  HWFloat<8,24> id71out_result[13];

  HWFloat<8,24> id72out_result[9];

  HWFloat<8,24> id73out_result[13];

  HWFloat<8,24> id47out_c_1_2;

  HWFloat<8,24> id76out_result[13];

  HWFloat<8,24> id77out_result[9];

  HWFloat<8,24> id78out_result[13];

  HWFloat<8,24> id48out_c_1_3;

  HWFloat<8,24> id81out_result[13];

  HWFloat<8,24> id82out_result[9];

  HWFloat<8,24> id83out_result[13];

  HWFloat<8,24> id49out_c_1_4;

  HWFloat<8,24> id86out_result[13];

  HWFloat<8,24> id87out_result[9];

  HWFloat<8,24> id88out_result[13];

  HWFloat<8,24> id50out_c_2_0;

  HWOffsetFix<1,0,UNSIGNED> id41out_io_py_force_disabled;

  HWFloat<8,24> id43out_data;

  HWOffsetFix<1,0,UNSIGNED> id43st_read_next_cycle;
  HWFloat<8,24> id43st_last_read_value;

  HWFloat<8,24> id173out_output[2];

  HWFloat<8,24> id91out_result[13];

  HWFloat<8,24> id92out_result[9];

  HWFloat<8,24> id93out_result[13];

  HWFloat<8,24> id51out_c_2_1;

  HWFloat<8,24> id208out_output[11];

  HWFloat<8,24> id209out_output[4];

  HWFloat<8,24> id96out_result[13];

  HWFloat<8,24> id97out_result[9];

  HWFloat<8,24> id98out_result[13];

  HWFloat<8,24> id52out_c_2_2;

  HWFloat<8,24> id210out_output[9];

  HWFloat<8,24> id211out_output[6];

  HWFloat<8,24> id101out_result[13];

  HWFloat<8,24> id102out_result[9];

  HWFloat<8,24> id103out_result[13];

  HWFloat<8,24> id53out_c_2_3;

  HWFloat<8,24> id212out_output[5];

  HWFloat<8,24> id213out_output[3];

  HWFloat<8,24> id214out_output[8];

  HWFloat<8,24> id106out_result[13];

  HWFloat<8,24> id107out_result[9];

  HWFloat<8,24> id108out_result[13];

  HWFloat<8,24> id54out_c_2_4;

  HWFloat<8,24> id110out_result[13];

  HWFloat<8,24> id111out_result[9];

  HWFloat<8,24> id182out_output[14];

  HWFloat<8,24> id112out_result[13];

  HWFloat<8,24> id55out_c_3_0;

  HWOffsetFix<1,0,UNSIGNED> id38out_io_px_force_disabled;

  HWFloat<8,24> id40out_data;

  HWOffsetFix<1,0,UNSIGNED> id40st_read_next_cycle;
  HWFloat<8,24> id40st_last_read_value;

  HWFloat<8,24> id183out_output[2];

  HWFloat<8,24> id115out_result[13];

  HWFloat<8,24> id116out_result[9];

  HWFloat<8,24> id117out_result[13];

  HWFloat<8,24> id56out_c_3_1;

  HWFloat<8,24> id215out_output[11];

  HWFloat<8,24> id216out_output[4];

  HWFloat<8,24> id120out_result[13];

  HWFloat<8,24> id121out_result[9];

  HWFloat<8,24> id122out_result[13];

  HWFloat<8,24> id57out_c_3_2;

  HWFloat<8,24> id217out_output[9];

  HWFloat<8,24> id218out_output[6];

  HWFloat<8,24> id125out_result[13];

  HWFloat<8,24> id126out_result[9];

  HWFloat<8,24> id127out_result[13];

  HWFloat<8,24> id58out_c_3_3;

  HWFloat<8,24> id219out_output[5];

  HWFloat<8,24> id220out_output[3];

  HWFloat<8,24> id221out_output[8];

  HWFloat<8,24> id130out_result[13];

  HWFloat<8,24> id131out_result[9];

  HWFloat<8,24> id132out_result[13];

  HWFloat<8,24> id59out_c_3_4;

  HWFloat<8,24> id134out_result[13];

  HWFloat<8,24> id135out_result[9];

  HWFloat<8,24> id192out_output[14];

  HWFloat<8,24> id136out_result[13];

  HWFloat<8,24> id137out_result[9];

  HWFloat<8,24> id138out_result[13];

  HWOffsetFix<1,0,UNSIGNED> id194out_output[114];

  HWOffsetFix<1,0,UNSIGNED> id31out_io_source_container_force_disabled;

  HWRawBits<1> id195out_output[109];

  HWFloat<8,24> id37out_data;

  HWOffsetFix<1,0,UNSIGNED> id37st_read_next_cycle;
  HWFloat<8,24> id37st_last_read_value;

  HWFloat<8,24> id139out_result[13];

  std::string format_string_linearKernel_1 (const char* _format_arg_format_string, const HWOffsetFix<32,0,UNSIGNED> &_format_arg_0, const HWFloat<8,24> &_format_arg_1);
  std::string format_string_linearKernel_2 (const char* _format_arg_format_string);
  HWOffsetFix<1,0,UNSIGNED> id196out_output[114];

  HWOffsetFix<1,0,UNSIGNED> id143out_io_ppresult_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id197out_output[126];

  HWOffsetFix<1,0,UNSIGNED> id153out_value;

  HWOffsetFix<1,0,UNSIGNED> id222out_value;

  HWOffsetFix<49,0,UNSIGNED> id151out_value;

  HWOffsetFix<48,0,UNSIGNED> id152out_count;
  HWOffsetFix<1,0,UNSIGNED> id152out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id152st_count;

  HWOffsetFix<48,0,UNSIGNED> id198out_output[5];

  HWOffsetFix<48,0,UNSIGNED> id156out_run_cycle_count;

  HWOffsetFix<1,0,UNSIGNED> id157out_result[2];

  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits;
  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits;
  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits_1;
  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits_2;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits_1;
  const HWOffsetFix<32,0,TWOSCOMPLEMENT> c_hw_fix_32_0_sgn_undef;
  const HWFloat<8,24> c_hw_flt_8_24_undef;
  const HWFloat<8,24> c_hw_flt_8_24_2_0val;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_undef;
  const HWRawBits<1> c_hw_bit_1_undef;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_1;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_2;
  const HWOffsetFix<48,0,UNSIGNED> c_hw_fix_48_0_uns_undef;

  void execute0();
};

}

#endif /* LINEARKERNEL_H_ */
