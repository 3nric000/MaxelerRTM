#include "stdsimheader.h"
#include "RTMKernel.h"

namespace maxcompilersim {

RTMKernel::RTMKernel(const std::string &instance_name) : 
  KernelManagerBlockSync(instance_name, 255, 2, 0, 0, "",1)
, c_hw_fix_1_0_uns_bits((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x0l))))
, c_hw_fix_32_0_sgn_undef((HWOffsetFix<32,0,TWOSCOMPLEMENT>()))
, c_hw_fix_1_0_uns_undef((HWOffsetFix<1,0,UNSIGNED>()))
, c_hw_flt_8_24_undef((HWFloat<8,24>()))
, c_hw_flt_8_24_2_0val((HWFloat<8,24>(varint_u<32>(0x40000000l))))
, c_hw_bit_1_undef((HWRawBits<1>()))
, c_hw_fix_1_0_uns_bits_1((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x1l))))
, c_hw_fix_49_0_uns_bits((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x1000000000000l))))
, c_hw_fix_49_0_uns_bits_1((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000000l))))
, c_hw_fix_49_0_uns_bits_2((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000001l))))
, c_hw_fix_48_0_uns_undef((HWOffsetFix<48,0,UNSIGNED>()))
{
  { // Node ID: 0 (NodeInputMappedReg)
    registerMappedRegister("io_controller_force_disabled", Data(1));
  }
  { // Node ID: 2 (NodeInput)
     m_controller =  registerInput("controller",0,5);
  }
  { // Node ID: 148 (NodeInputMappedReg)
    registerMappedRegister("io_ppresult_force_disabled", Data(1));
  }
  { // Node ID: 4 (NodeInputMappedReg)
    registerMappedRegister("io_p_force_disabled", Data(1));
  }
  { // Node ID: 10 (NodeInput)
     m_p =  registerInput("p",1,5);
  }
  { // Node ID: 12 (NodeInputMappedReg)
    registerMappedRegister("io_pp_force_disabled", Data(1));
  }
  { // Node ID: 18 (NodeInput)
     m_pp =  registerInput("pp",2,5);
  }
  { // Node ID: 42 (NodeInputMappedReg)
    registerMappedRegister("io_scale_force_disabled", Data(1));
  }
  { // Node ID: 48 (NodeInput)
     m_scale =  registerInput("scale",7,5);
  }
  { // Node ID: 20 (NodeInputMappedReg)
    registerMappedRegister("io_dvv_force_disabled", Data(1));
  }
  { // Node ID: 26 (NodeInput)
     m_dvv =  registerInput("dvv",3,5);
  }
  { // Node ID: 49 (NodeInputMappedReg)
    registerMappedRegister("c_0", Data(32));
  }
  { // Node ID: 50 (NodeInputMappedReg)
    registerMappedRegister("c_1_0", Data(32));
  }
  { // Node ID: 51 (NodeInputMappedReg)
    registerMappedRegister("c_1_1", Data(32));
  }
  { // Node ID: 52 (NodeInputMappedReg)
    registerMappedRegister("c_1_2", Data(32));
  }
  { // Node ID: 53 (NodeInputMappedReg)
    registerMappedRegister("c_1_3", Data(32));
  }
  { // Node ID: 54 (NodeInputMappedReg)
    registerMappedRegister("c_1_4", Data(32));
  }
  { // Node ID: 55 (NodeInputMappedReg)
    registerMappedRegister("c_2_0", Data(32));
  }
  { // Node ID: 38 (NodeInputMappedReg)
    registerMappedRegister("io_py_force_disabled", Data(1));
  }
  { // Node ID: 40 (NodeInput)
     m_py =  registerInput("py",6,5);
  }
  { // Node ID: 56 (NodeInputMappedReg)
    registerMappedRegister("c_2_1", Data(32));
  }
  { // Node ID: 57 (NodeInputMappedReg)
    registerMappedRegister("c_2_2", Data(32));
  }
  { // Node ID: 58 (NodeInputMappedReg)
    registerMappedRegister("c_2_3", Data(32));
  }
  { // Node ID: 59 (NodeInputMappedReg)
    registerMappedRegister("c_2_4", Data(32));
  }
  { // Node ID: 60 (NodeInputMappedReg)
    registerMappedRegister("c_3_0", Data(32));
  }
  { // Node ID: 35 (NodeInputMappedReg)
    registerMappedRegister("io_px_force_disabled", Data(1));
  }
  { // Node ID: 37 (NodeInput)
     m_px =  registerInput("px",5,5);
  }
  { // Node ID: 61 (NodeInputMappedReg)
    registerMappedRegister("c_3_1", Data(32));
  }
  { // Node ID: 62 (NodeInputMappedReg)
    registerMappedRegister("c_3_2", Data(32));
  }
  { // Node ID: 63 (NodeInputMappedReg)
    registerMappedRegister("c_3_3", Data(32));
  }
  { // Node ID: 64 (NodeInputMappedReg)
    registerMappedRegister("c_3_4", Data(32));
  }
  { // Node ID: 28 (NodeInputMappedReg)
    registerMappedRegister("io_source_container_force_disabled", Data(1));
  }
  { // Node ID: 34 (NodeInput)
     m_source_container =  registerInput("source_container",4,5);
  }
  { // Node ID: 154 (NodeOutput)
    m_ppresult = registerOutput("ppresult",0 );
  }
  { // Node ID: 158 (NodeConstantRawBits)
    id158out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 231 (NodeConstantRawBits)
    id231out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 156 (NodeConstantRawBits)
    id156out_value = (c_hw_fix_49_0_uns_bits);
  }
  { // Node ID: 159 (NodeOutputMappedReg)
    registerMappedRegister("current_run_cycle_count", Data(48));
  }
  { // Node ID: 161 (NodeInputMappedReg)
    registerMappedRegister("run_cycle_count", Data(48));
  }
}

void RTMKernel::resetComputation() {
  resetComputationAfterFlush();
}

void RTMKernel::resetComputationAfterFlush() {
  { // Node ID: 0 (NodeInputMappedReg)
    id0out_io_controller_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_controller_force_disabled");
  }
  { // Node ID: 2 (NodeInput)

    (id2st_read_next_cycle) = (c_hw_fix_1_0_uns_bits);
    (id2st_last_read_value) = (c_hw_fix_32_0_sgn_undef);
  }
  { // Node ID: 164 (NodeFIFO)

    for(int i=0; i<159; i++)
    {
      id164out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 148 (NodeInputMappedReg)
    id148out_io_ppresult_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_ppresult_force_disabled");
  }
  { // Node ID: 206 (NodeFIFO)

    for(int i=0; i<89; i++)
    {
      id206out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 4 (NodeInputMappedReg)
    id4out_io_p_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_p_force_disabled");
  }
  { // Node ID: 10 (NodeInput)

    (id10st_read_next_cycle) = (c_hw_fix_1_0_uns_bits);
    (id10st_last_read_value) = (c_hw_flt_8_24_undef);
  }
  { // Node ID: 174 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id174out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 208 (NodeFIFO)

    for(int i=0; i<10; i++)
    {
      id208out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 209 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id209out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 210 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id210out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 211 (NodeFIFO)

    for(int i=0; i<8; i++)
    {
      id211out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 212 (NodeFIFO)

    for(int i=0; i<7; i++)
    {
      id212out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 213 (NodeFIFO)

    for(int i=0; i<6; i++)
    {
      id213out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 214 (NodeFIFO)

    for(int i=0; i<9; i++)
    {
      id214out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 215 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id215out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 216 (NodeFIFO)

    for(int i=0; i<11; i++)
    {
      id216out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 170 (NodeFIFO)

    for(int i=0; i<143; i++)
    {
      id170out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 166 (NodeFIFO)

    for(int i=0; i<159; i++)
    {
      id166out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 167 (NodeFIFO)

    for(int i=0; i<32; i++)
    {
      id167out_output[i] = (c_hw_bit_1_undef);
    }
  }
  { // Node ID: 12 (NodeInputMappedReg)
    id12out_io_pp_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_pp_force_disabled");
  }
  { // Node ID: 18 (NodeInput)

    (id18st_read_next_cycle) = (c_hw_fix_1_0_uns_bits);
    (id18st_last_read_value) = (c_hw_flt_8_24_undef);
  }
  { // Node ID: 168 (NodeFIFO)

    for(int i=0; i<159; i++)
    {
      id168out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 42 (NodeInputMappedReg)
    id42out_io_scale_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_scale_force_disabled");
  }
  { // Node ID: 169 (NodeFIFO)

    for(int i=0; i<32; i++)
    {
      id169out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 48 (NodeInput)

    (id48st_read_next_cycle) = (c_hw_fix_1_0_uns_bits);
    (id48st_last_read_value) = (c_hw_flt_8_24_undef);
  }
  { // Node ID: 171 (NodeFIFO)

    for(int i=0; i<159; i++)
    {
      id171out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 20 (NodeInputMappedReg)
    id20out_io_dvv_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_dvv_force_disabled");
  }
  { // Node ID: 172 (NodeFIFO)

    for(int i=0; i<44; i++)
    {
      id172out_output[i] = (c_hw_bit_1_undef);
    }
  }
  { // Node ID: 26 (NodeInput)

    (id26st_read_next_cycle) = (c_hw_fix_1_0_uns_bits);
    (id26st_last_read_value) = (c_hw_flt_8_24_undef);
  }
  { // Node ID: 49 (NodeInputMappedReg)
    id49out_c_0 = getMappedRegValue<HWFloat<8,24> >("c_0");
  }
  { // Node ID: 50 (NodeInputMappedReg)
    id50out_c_1_0 = getMappedRegValue<HWFloat<8,24> >("c_1_0");
  }
  { // Node ID: 51 (NodeInputMappedReg)
    id51out_c_1_1 = getMappedRegValue<HWFloat<8,24> >("c_1_1");
  }
  { // Node ID: 52 (NodeInputMappedReg)
    id52out_c_1_2 = getMappedRegValue<HWFloat<8,24> >("c_1_2");
  }
  { // Node ID: 53 (NodeInputMappedReg)
    id53out_c_1_3 = getMappedRegValue<HWFloat<8,24> >("c_1_3");
  }
  { // Node ID: 54 (NodeInputMappedReg)
    id54out_c_1_4 = getMappedRegValue<HWFloat<8,24> >("c_1_4");
  }
  { // Node ID: 55 (NodeInputMappedReg)
    id55out_c_2_0 = getMappedRegValue<HWFloat<8,24> >("c_2_0");
  }
  { // Node ID: 38 (NodeInputMappedReg)
    id38out_io_py_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_py_force_disabled");
  }
  { // Node ID: 40 (NodeInput)

    (id40st_read_next_cycle) = (c_hw_fix_1_0_uns_bits);
    (id40st_last_read_value) = (c_hw_flt_8_24_undef);
  }
  { // Node ID: 183 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id183out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 56 (NodeInputMappedReg)
    id56out_c_2_1 = getMappedRegValue<HWFloat<8,24> >("c_2_1");
  }
  { // Node ID: 217 (NodeFIFO)

    for(int i=0; i<10; i++)
    {
      id217out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 218 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id218out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 57 (NodeInputMappedReg)
    id57out_c_2_2 = getMappedRegValue<HWFloat<8,24> >("c_2_2");
  }
  { // Node ID: 219 (NodeFIFO)

    for(int i=0; i<8; i++)
    {
      id219out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 220 (NodeFIFO)

    for(int i=0; i<7; i++)
    {
      id220out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 58 (NodeInputMappedReg)
    id58out_c_2_3 = getMappedRegValue<HWFloat<8,24> >("c_2_3");
  }
  { // Node ID: 221 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id221out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 222 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id222out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 223 (NodeFIFO)

    for(int i=0; i<9; i++)
    {
      id223out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 59 (NodeInputMappedReg)
    id59out_c_2_4 = getMappedRegValue<HWFloat<8,24> >("c_2_4");
  }
  { // Node ID: 192 (NodeFIFO)

    for(int i=0; i<14; i++)
    {
      id192out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 60 (NodeInputMappedReg)
    id60out_c_3_0 = getMappedRegValue<HWFloat<8,24> >("c_3_0");
  }
  { // Node ID: 35 (NodeInputMappedReg)
    id35out_io_px_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_px_force_disabled");
  }
  { // Node ID: 37 (NodeInput)

    (id37st_read_next_cycle) = (c_hw_fix_1_0_uns_bits);
    (id37st_last_read_value) = (c_hw_flt_8_24_undef);
  }
  { // Node ID: 193 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id193out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 61 (NodeInputMappedReg)
    id61out_c_3_1 = getMappedRegValue<HWFloat<8,24> >("c_3_1");
  }
  { // Node ID: 224 (NodeFIFO)

    for(int i=0; i<10; i++)
    {
      id224out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 225 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id225out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 62 (NodeInputMappedReg)
    id62out_c_3_2 = getMappedRegValue<HWFloat<8,24> >("c_3_2");
  }
  { // Node ID: 226 (NodeFIFO)

    for(int i=0; i<8; i++)
    {
      id226out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 227 (NodeFIFO)

    for(int i=0; i<7; i++)
    {
      id227out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 63 (NodeInputMappedReg)
    id63out_c_3_3 = getMappedRegValue<HWFloat<8,24> >("c_3_3");
  }
  { // Node ID: 228 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id228out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 229 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id229out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 230 (NodeFIFO)

    for(int i=0; i<9; i++)
    {
      id230out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 64 (NodeInputMappedReg)
    id64out_c_3_4 = getMappedRegValue<HWFloat<8,24> >("c_3_4");
  }
  { // Node ID: 202 (NodeFIFO)

    for(int i=0; i<14; i++)
    {
      id202out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 203 (NodeFIFO)

    for(int i=0; i<159; i++)
    {
      id203out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 28 (NodeInputMappedReg)
    id28out_io_source_container_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_source_container_force_disabled");
  }
  { // Node ID: 204 (NodeFIFO)

    for(int i=0; i<64; i++)
    {
      id204out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 34 (NodeInput)

    (id34st_read_next_cycle) = (c_hw_fix_1_0_uns_bits);
    (id34st_last_read_value) = (c_hw_flt_8_24_undef);
  }
  { // Node ID: 205 (NodeFIFO)

    for(int i=0; i<45; i++)
    {
      id205out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 157 (NodeCounterV1)

    (id157st_count) = (c_hw_fix_49_0_uns_bits_1);
  }
  { // Node ID: 207 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id207out_output[i] = (c_hw_fix_48_0_uns_undef);
    }
  }
  { // Node ID: 161 (NodeInputMappedReg)
    id161out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
}

void RTMKernel::updateState() {
  { // Node ID: 0 (NodeInputMappedReg)
    id0out_io_controller_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_controller_force_disabled");
  }
  { // Node ID: 148 (NodeInputMappedReg)
    id148out_io_ppresult_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_ppresult_force_disabled");
  }
  { // Node ID: 4 (NodeInputMappedReg)
    id4out_io_p_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_p_force_disabled");
  }
  { // Node ID: 12 (NodeInputMappedReg)
    id12out_io_pp_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_pp_force_disabled");
  }
  { // Node ID: 42 (NodeInputMappedReg)
    id42out_io_scale_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_scale_force_disabled");
  }
  { // Node ID: 20 (NodeInputMappedReg)
    id20out_io_dvv_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_dvv_force_disabled");
  }
  { // Node ID: 49 (NodeInputMappedReg)
    id49out_c_0 = getMappedRegValue<HWFloat<8,24> >("c_0");
  }
  { // Node ID: 50 (NodeInputMappedReg)
    id50out_c_1_0 = getMappedRegValue<HWFloat<8,24> >("c_1_0");
  }
  { // Node ID: 51 (NodeInputMappedReg)
    id51out_c_1_1 = getMappedRegValue<HWFloat<8,24> >("c_1_1");
  }
  { // Node ID: 52 (NodeInputMappedReg)
    id52out_c_1_2 = getMappedRegValue<HWFloat<8,24> >("c_1_2");
  }
  { // Node ID: 53 (NodeInputMappedReg)
    id53out_c_1_3 = getMappedRegValue<HWFloat<8,24> >("c_1_3");
  }
  { // Node ID: 54 (NodeInputMappedReg)
    id54out_c_1_4 = getMappedRegValue<HWFloat<8,24> >("c_1_4");
  }
  { // Node ID: 55 (NodeInputMappedReg)
    id55out_c_2_0 = getMappedRegValue<HWFloat<8,24> >("c_2_0");
  }
  { // Node ID: 38 (NodeInputMappedReg)
    id38out_io_py_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_py_force_disabled");
  }
  { // Node ID: 56 (NodeInputMappedReg)
    id56out_c_2_1 = getMappedRegValue<HWFloat<8,24> >("c_2_1");
  }
  { // Node ID: 57 (NodeInputMappedReg)
    id57out_c_2_2 = getMappedRegValue<HWFloat<8,24> >("c_2_2");
  }
  { // Node ID: 58 (NodeInputMappedReg)
    id58out_c_2_3 = getMappedRegValue<HWFloat<8,24> >("c_2_3");
  }
  { // Node ID: 59 (NodeInputMappedReg)
    id59out_c_2_4 = getMappedRegValue<HWFloat<8,24> >("c_2_4");
  }
  { // Node ID: 60 (NodeInputMappedReg)
    id60out_c_3_0 = getMappedRegValue<HWFloat<8,24> >("c_3_0");
  }
  { // Node ID: 35 (NodeInputMappedReg)
    id35out_io_px_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_px_force_disabled");
  }
  { // Node ID: 61 (NodeInputMappedReg)
    id61out_c_3_1 = getMappedRegValue<HWFloat<8,24> >("c_3_1");
  }
  { // Node ID: 62 (NodeInputMappedReg)
    id62out_c_3_2 = getMappedRegValue<HWFloat<8,24> >("c_3_2");
  }
  { // Node ID: 63 (NodeInputMappedReg)
    id63out_c_3_3 = getMappedRegValue<HWFloat<8,24> >("c_3_3");
  }
  { // Node ID: 64 (NodeInputMappedReg)
    id64out_c_3_4 = getMappedRegValue<HWFloat<8,24> >("c_3_4");
  }
  { // Node ID: 28 (NodeInputMappedReg)
    id28out_io_source_container_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_source_container_force_disabled");
  }
  { // Node ID: 161 (NodeInputMappedReg)
    id161out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
}

void RTMKernel::preExecute() {
  { // Node ID: 2 (NodeInput)
    if(((needsToReadInput(m_controller))&(((getFlushLevel())<((4l)+(5)))|(!(isFlushingActive()))))) {
      (id2st_last_read_value) = (readInput<HWOffsetFix<32,0,TWOSCOMPLEMENT> >(m_controller));
    }
    id2out_data = (id2st_last_read_value);
  }
  { // Node ID: 10 (NodeInput)
    if(((needsToReadInput(m_p))&(((getFlushLevel())<((9l)+(5)))|(!(isFlushingActive()))))) {
      (id10st_last_read_value) = (readInput<HWFloat<8,24> >(m_p));
    }
    id10out_data = (id10st_last_read_value);
  }
  { // Node ID: 18 (NodeInput)
    if(((needsToReadInput(m_pp))&(((getFlushLevel())<((198l)+(5)))|(!(isFlushingActive()))))) {
      (id18st_last_read_value) = (readInput<HWFloat<8,24> >(m_pp));
    }
    id18out_data = (id18st_last_read_value);
  }
  { // Node ID: 48 (NodeInput)
    if(((needsToReadInput(m_scale))&(((getFlushLevel())<((198l)+(5)))|(!(isFlushingActive()))))) {
      (id48st_last_read_value) = (readInput<HWFloat<8,24> >(m_scale));
    }
    id48out_data = (id48st_last_read_value);
  }
  { // Node ID: 26 (NodeInput)
    if(((needsToReadInput(m_dvv))&(((getFlushLevel())<((210l)+(5)))|(!(isFlushingActive()))))) {
      (id26st_last_read_value) = (readInput<HWFloat<8,24> >(m_dvv));
    }
    id26out_data = (id26st_last_read_value);
  }
  { // Node ID: 40 (NodeInput)
    if(((needsToReadInput(m_py))&(((getFlushLevel())<((74l)+(5)))|(!(isFlushingActive()))))) {
      (id40st_last_read_value) = (readInput<HWFloat<8,24> >(m_py));
    }
    id40out_data = (id40st_last_read_value);
  }
  { // Node ID: 37 (NodeInput)
    if(((needsToReadInput(m_px))&(((getFlushLevel())<((134l)+(5)))|(!(isFlushingActive()))))) {
      (id37st_last_read_value) = (readInput<HWFloat<8,24> >(m_px));
    }
    id37out_data = (id37st_last_read_value);
  }
  { // Node ID: 34 (NodeInput)
    if(((needsToReadInput(m_source_container))&(((getFlushLevel())<((230l)+(5)))|(!(isFlushingActive()))))) {
      (id34st_last_read_value) = (readInput<HWFloat<8,24> >(m_source_container));
    }
    id34out_data = (id34st_last_read_value);
  }
}

void RTMKernel::runComputationCycle() {
  if (m_mappedElementsChanged) {
    m_mappedElementsChanged = false;
    updateState();
    std::cout << "RTMKernel: Mapped Elements Changed: Reloaded" << std::endl;
  }
  preExecute();
  execute0();
}

int RTMKernel::getFlushLevelStart() {
  return ((1l)+(3l));
}

}
