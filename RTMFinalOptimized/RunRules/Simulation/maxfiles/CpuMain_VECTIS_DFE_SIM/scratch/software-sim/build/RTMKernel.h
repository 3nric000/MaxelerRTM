#ifndef RTMKERNEL_H_
#define RTMKERNEL_H_

// #include "KernelManagerBlockSync.h"


namespace maxcompilersim {

class RTMKernel : public KernelManagerBlockSync {
public:
  RTMKernel(const std::string &instance_name);

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
  t_port_number m_scale;
  t_port_number m_dvv;
  t_port_number m_py;
  t_port_number m_px;
  t_port_number m_source_container;
  t_port_number m_ppresult;
  HWOffsetFix<1,0,UNSIGNED> id0out_io_controller_force_disabled;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id2out_data;

  HWOffsetFix<1,0,UNSIGNED> id2st_read_next_cycle;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id2st_last_read_value;

  HWOffsetFix<1,0,UNSIGNED> id164out_output[159];

  HWOffsetFix<1,0,UNSIGNED> id148out_io_ppresult_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id206out_output[89];

  HWOffsetFix<1,0,UNSIGNED> id4out_io_p_force_disabled;

  HWFloat<8,24> id10out_data;

  HWOffsetFix<1,0,UNSIGNED> id10st_read_next_cycle;
  HWFloat<8,24> id10st_last_read_value;

  HWFloat<8,24> id174out_output[3];

  HWFloat<8,24> id208out_output[10];

  HWFloat<8,24> id209out_output[3];

  HWFloat<8,24> id210out_output[3];

  HWFloat<8,24> id211out_output[8];

  HWFloat<8,24> id212out_output[7];

  HWFloat<8,24> id213out_output[6];

  HWFloat<8,24> id214out_output[9];

  HWFloat<8,24> id215out_output[4];

  HWFloat<8,24> id216out_output[11];

  HWFloat<8,24> id163out_floatOut[2];

  HWFloat<8,24> id170out_output[143];

  HWOffsetFix<1,0,UNSIGNED> id166out_output[159];

  HWRawBits<1> id167out_output[32];

  HWOffsetFix<1,0,UNSIGNED> id12out_io_pp_force_disabled;

  HWFloat<8,24> id18out_data;

  HWOffsetFix<1,0,UNSIGNED> id18st_read_next_cycle;
  HWFloat<8,24> id18st_last_read_value;

  HWOffsetFix<1,0,UNSIGNED> id168out_output[159];

  HWOffsetFix<1,0,UNSIGNED> id42out_io_scale_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id169out_output[32];

  HWFloat<8,24> id48out_data;

  HWOffsetFix<1,0,UNSIGNED> id48st_read_next_cycle;
  HWFloat<8,24> id48st_last_read_value;

  HWFloat<8,24> id65out_result[9];

  HWFloat<8,24> id68out_result[13];

  HWOffsetFix<1,0,UNSIGNED> id171out_output[159];

  HWOffsetFix<1,0,UNSIGNED> id20out_io_dvv_force_disabled;

  HWRawBits<1> id172out_output[44];

  HWFloat<8,24> id26out_data;

  HWOffsetFix<1,0,UNSIGNED> id26st_read_next_cycle;
  HWFloat<8,24> id26st_last_read_value;

  HWFloat<8,24> id49out_c_0;

  HWFloat<8,24> id69out_result[9];

  HWFloat<8,24> id50out_c_1_0;

  HWFloat<8,24> id72out_result[13];

  HWFloat<8,24> id73out_result[9];

  HWFloat<8,24> id74out_result[13];

  HWFloat<8,24> id51out_c_1_1;

  HWFloat<8,24> id77out_result[13];

  HWFloat<8,24> id78out_result[9];

  HWFloat<8,24> id79out_result[13];

  HWFloat<8,24> id52out_c_1_2;

  HWFloat<8,24> id82out_result[13];

  HWFloat<8,24> id83out_result[9];

  HWFloat<8,24> id84out_result[13];

  HWFloat<8,24> id53out_c_1_3;

  HWFloat<8,24> id87out_result[13];

  HWFloat<8,24> id88out_result[9];

  HWFloat<8,24> id89out_result[13];

  HWFloat<8,24> id54out_c_1_4;

  HWFloat<8,24> id92out_result[13];

  HWFloat<8,24> id93out_result[9];

  HWFloat<8,24> id94out_result[13];

  HWFloat<8,24> id55out_c_2_0;

  HWOffsetFix<1,0,UNSIGNED> id38out_io_py_force_disabled;

  HWFloat<8,24> id40out_data;

  HWOffsetFix<1,0,UNSIGNED> id40st_read_next_cycle;
  HWFloat<8,24> id40st_last_read_value;

  HWFloat<8,24> id183out_output[3];

  HWFloat<8,24> id97out_result[13];

  HWFloat<8,24> id98out_result[9];

  HWFloat<8,24> id99out_result[13];

  HWFloat<8,24> id56out_c_2_1;

  HWFloat<8,24> id217out_output[10];

  HWFloat<8,24> id218out_output[5];

  HWFloat<8,24> id102out_result[13];

  HWFloat<8,24> id103out_result[9];

  HWFloat<8,24> id104out_result[13];

  HWFloat<8,24> id57out_c_2_2;

  HWFloat<8,24> id219out_output[8];

  HWFloat<8,24> id220out_output[7];

  HWFloat<8,24> id107out_result[13];

  HWFloat<8,24> id108out_result[9];

  HWFloat<8,24> id109out_result[13];

  HWFloat<8,24> id58out_c_2_3;

  HWFloat<8,24> id221out_output[4];

  HWFloat<8,24> id222out_output[3];

  HWFloat<8,24> id223out_output[9];

  HWFloat<8,24> id112out_result[13];

  HWFloat<8,24> id113out_result[9];

  HWFloat<8,24> id114out_result[13];

  HWFloat<8,24> id59out_c_2_4;

  HWFloat<8,24> id116out_result[13];

  HWFloat<8,24> id117out_result[9];

  HWFloat<8,24> id192out_output[14];

  HWFloat<8,24> id118out_result[13];

  HWFloat<8,24> id60out_c_3_0;

  HWOffsetFix<1,0,UNSIGNED> id35out_io_px_force_disabled;

  HWFloat<8,24> id37out_data;

  HWOffsetFix<1,0,UNSIGNED> id37st_read_next_cycle;
  HWFloat<8,24> id37st_last_read_value;

  HWFloat<8,24> id193out_output[3];

  HWFloat<8,24> id121out_result[13];

  HWFloat<8,24> id122out_result[9];

  HWFloat<8,24> id123out_result[13];

  HWFloat<8,24> id61out_c_3_1;

  HWFloat<8,24> id224out_output[10];

  HWFloat<8,24> id225out_output[5];

  HWFloat<8,24> id126out_result[13];

  HWFloat<8,24> id127out_result[9];

  HWFloat<8,24> id128out_result[13];

  HWFloat<8,24> id62out_c_3_2;

  HWFloat<8,24> id226out_output[8];

  HWFloat<8,24> id227out_output[7];

  HWFloat<8,24> id131out_result[13];

  HWFloat<8,24> id132out_result[9];

  HWFloat<8,24> id133out_result[13];

  HWFloat<8,24> id63out_c_3_3;

  HWFloat<8,24> id228out_output[4];

  HWFloat<8,24> id229out_output[3];

  HWFloat<8,24> id230out_output[9];

  HWFloat<8,24> id136out_result[13];

  HWFloat<8,24> id137out_result[9];

  HWFloat<8,24> id138out_result[13];

  HWFloat<8,24> id64out_c_3_4;

  HWFloat<8,24> id140out_result[13];

  HWFloat<8,24> id141out_result[9];

  HWFloat<8,24> id202out_output[14];

  HWFloat<8,24> id142out_result[13];

  HWFloat<8,24> id143out_result[9];

  HWFloat<8,24> id144out_result[13];

  HWOffsetFix<1,0,UNSIGNED> id203out_output[159];

  HWOffsetFix<1,0,UNSIGNED> id28out_io_source_container_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id204out_output[64];

  HWFloat<8,24> id34out_data;

  HWOffsetFix<1,0,UNSIGNED> id34st_read_next_cycle;
  HWFloat<8,24> id34st_last_read_value;

  HWFloat<8,24> id145out_result[13];

  HWFloat<8,24> id205out_output[45];

  HWFloat<8,24> id146out_result[9];

  HWOffsetFix<1,0,UNSIGNED> id158out_value;

  HWOffsetFix<1,0,UNSIGNED> id231out_value;

  HWOffsetFix<49,0,UNSIGNED> id156out_value;

  HWOffsetFix<48,0,UNSIGNED> id157out_count;
  HWOffsetFix<1,0,UNSIGNED> id157out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id157st_count;

  HWOffsetFix<48,0,UNSIGNED> id207out_output[5];

  HWOffsetFix<48,0,UNSIGNED> id161out_run_cycle_count;

  HWOffsetFix<1,0,UNSIGNED> id162out_result[2];

  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits;
  const HWOffsetFix<32,0,TWOSCOMPLEMENT> c_hw_fix_32_0_sgn_undef;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_undef;
  const HWFloat<8,24> c_hw_flt_8_24_undef;
  const HWFloat<8,24> c_hw_flt_8_24_2_0val;
  const HWRawBits<1> c_hw_bit_1_undef;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits_1;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_1;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_2;
  const HWOffsetFix<48,0,UNSIGNED> c_hw_fix_48_0_uns_undef;

  void execute0();
};

}

#endif /* RTMKERNEL_H_ */
