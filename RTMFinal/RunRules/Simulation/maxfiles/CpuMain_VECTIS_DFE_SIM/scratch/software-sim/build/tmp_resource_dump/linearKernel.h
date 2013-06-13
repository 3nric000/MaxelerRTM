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
  HWOffsetFix<1,0,UNSIGNED> id0out_io_controller_force_disabled;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id2out_data;

  HWOffsetFix<1,0,UNSIGNED> id2st_read_next_cycle;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id2st_last_read_value;

  HWOffsetFix<1,0,UNSIGNED> id154out_output[111];

  HWOffsetFix<1,0,UNSIGNED> id138out_io_ppresult_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id192out_output[129];

  HWOffsetFix<1,0,UNSIGNED> id4out_io_p_force_disabled;

  HWFloat<8,24> id10out_data;

  HWOffsetFix<1,0,UNSIGNED> id10st_read_next_cycle;
  HWFloat<8,24> id10st_last_read_value;

  HWFloat<8,24> id160out_output[3];

  HWFloat<8,24> id194out_output[10];

  HWFloat<8,24> id195out_output[3];

  HWFloat<8,24> id196out_output[3];

  HWFloat<8,24> id197out_output[8];

  HWFloat<8,24> id198out_output[7];

  HWFloat<8,24> id199out_output[6];

  HWFloat<8,24> id200out_output[9];

  HWFloat<8,24> id201out_output[4];

  HWFloat<8,24> id202out_output[11];

  HWFloat<8,24> id153out_floatOut[2];

  HWOffsetFix<1,0,UNSIGNED> id156out_output[56];

  HWOffsetFix<1,0,UNSIGNED> id12out_io_pp_force_disabled;

  HWFloat<8,24> id18out_data;

  HWOffsetFix<1,0,UNSIGNED> id18st_read_next_cycle;
  HWFloat<8,24> id18st_last_read_value;

  HWFloat<8,24> id59out_result[13];

  HWFloat<8,24> id189out_output[143];

  HWOffsetFix<1,0,UNSIGNED> id157out_output[111];

  HWOffsetFix<1,0,UNSIGNED> id20out_io_dvv_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id158out_output[92];

  HWFloat<8,24> id26out_data;

  HWOffsetFix<1,0,UNSIGNED> id26st_read_next_cycle;
  HWFloat<8,24> id26st_last_read_value;

  HWFloat<8,24> id41out_c_0;

  HWFloat<8,24> id60out_result[9];

  HWFloat<8,24> id42out_c_1_0;

  HWFloat<8,24> id63out_result[13];

  HWFloat<8,24> id64out_result[9];

  HWFloat<8,24> id65out_result[13];

  HWFloat<8,24> id43out_c_1_1;

  HWFloat<8,24> id68out_result[13];

  HWFloat<8,24> id69out_result[9];

  HWFloat<8,24> id70out_result[13];

  HWFloat<8,24> id44out_c_1_2;

  HWFloat<8,24> id73out_result[13];

  HWFloat<8,24> id74out_result[9];

  HWFloat<8,24> id75out_result[13];

  HWFloat<8,24> id45out_c_1_3;

  HWFloat<8,24> id78out_result[13];

  HWFloat<8,24> id79out_result[9];

  HWFloat<8,24> id80out_result[13];

  HWFloat<8,24> id46out_c_1_4;

  HWFloat<8,24> id83out_result[13];

  HWFloat<8,24> id84out_result[9];

  HWFloat<8,24> id85out_result[13];

  HWFloat<8,24> id47out_c_2_0;

  HWOffsetFix<1,0,UNSIGNED> id38out_io_py_force_disabled;

  HWFloat<8,24> id40out_data;

  HWOffsetFix<1,0,UNSIGNED> id40st_read_next_cycle;
  HWFloat<8,24> id40st_last_read_value;

  HWFloat<8,24> id169out_output[2];

  HWFloat<8,24> id88out_result[13];

  HWFloat<8,24> id89out_result[9];

  HWFloat<8,24> id90out_result[13];

  HWFloat<8,24> id48out_c_2_1;

  HWFloat<8,24> id203out_output[11];

  HWFloat<8,24> id204out_output[4];

  HWFloat<8,24> id93out_result[13];

  HWFloat<8,24> id94out_result[9];

  HWFloat<8,24> id95out_result[13];

  HWFloat<8,24> id49out_c_2_2;

  HWFloat<8,24> id205out_output[9];

  HWFloat<8,24> id206out_output[6];

  HWFloat<8,24> id98out_result[13];

  HWFloat<8,24> id99out_result[9];

  HWFloat<8,24> id100out_result[13];

  HWFloat<8,24> id50out_c_2_3;

  HWFloat<8,24> id207out_output[5];

  HWFloat<8,24> id208out_output[3];

  HWFloat<8,24> id209out_output[8];

  HWFloat<8,24> id103out_result[13];

  HWFloat<8,24> id104out_result[9];

  HWFloat<8,24> id105out_result[13];

  HWFloat<8,24> id51out_c_2_4;

  HWFloat<8,24> id107out_result[13];

  HWFloat<8,24> id108out_result[9];

  HWFloat<8,24> id178out_output[14];

  HWFloat<8,24> id109out_result[13];

  HWFloat<8,24> id52out_c_3_0;

  HWOffsetFix<1,0,UNSIGNED> id35out_io_px_force_disabled;

  HWFloat<8,24> id37out_data;

  HWOffsetFix<1,0,UNSIGNED> id37st_read_next_cycle;
  HWFloat<8,24> id37st_last_read_value;

  HWFloat<8,24> id179out_output[2];

  HWFloat<8,24> id112out_result[13];

  HWFloat<8,24> id113out_result[9];

  HWFloat<8,24> id114out_result[13];

  HWFloat<8,24> id53out_c_3_1;

  HWFloat<8,24> id210out_output[11];

  HWFloat<8,24> id211out_output[4];

  HWFloat<8,24> id117out_result[13];

  HWFloat<8,24> id118out_result[9];

  HWFloat<8,24> id119out_result[13];

  HWFloat<8,24> id54out_c_3_2;

  HWFloat<8,24> id212out_output[9];

  HWFloat<8,24> id213out_output[6];

  HWFloat<8,24> id122out_result[13];

  HWFloat<8,24> id123out_result[9];

  HWFloat<8,24> id124out_result[13];

  HWFloat<8,24> id55out_c_3_3;

  HWFloat<8,24> id214out_output[5];

  HWFloat<8,24> id215out_output[3];

  HWFloat<8,24> id216out_output[8];

  HWFloat<8,24> id127out_result[13];

  HWFloat<8,24> id128out_result[9];

  HWFloat<8,24> id129out_result[13];

  HWFloat<8,24> id56out_c_3_4;

  HWFloat<8,24> id131out_result[13];

  HWFloat<8,24> id132out_result[9];

  HWFloat<8,24> id188out_output[14];

  HWFloat<8,24> id133out_result[13];

  HWFloat<8,24> id134out_result[9];

  HWFloat<8,24> id135out_result[13];

  HWOffsetFix<1,0,UNSIGNED> id190out_output[111];

  HWOffsetFix<1,0,UNSIGNED> id28out_io_source_container_force_disabled;

  HWRawBits<1> id191out_output[112];

  HWFloat<8,24> id34out_data;

  HWOffsetFix<1,0,UNSIGNED> id34st_read_next_cycle;
  HWFloat<8,24> id34st_last_read_value;

  HWFloat<8,24> id136out_result[13];

  HWOffsetFix<1,0,UNSIGNED> id148out_value;

  HWOffsetFix<1,0,UNSIGNED> id217out_value;

  HWOffsetFix<49,0,UNSIGNED> id146out_value;

  HWOffsetFix<48,0,UNSIGNED> id147out_count;
  HWOffsetFix<1,0,UNSIGNED> id147out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id147st_count;

  HWOffsetFix<48,0,UNSIGNED> id193out_output[5];

  HWOffsetFix<48,0,UNSIGNED> id151out_run_cycle_count;

  HWOffsetFix<1,0,UNSIGNED> id152out_result[2];

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

#endif /* LINEARKERNEL_H_ */
