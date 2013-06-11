#include "stdsimheader.h"
#include "linearKernel.h"

namespace maxcompilersim {

linearKernel::linearKernel(const std::string &instance_name) : 
  KernelManagerBlockSync(instance_name, 247, 2, 0, 0, "",1)
, c_hw_fix_1_0_uns_bits((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x1l))))
, c_hw_fix_33_0_uns_bits((HWOffsetFix<33,0,UNSIGNED>(varint_u<33>(0x100000000l))))
, c_hw_fix_33_0_uns_bits_1((HWOffsetFix<33,0,UNSIGNED>(varint_u<33>(0x000000000l))))
, c_hw_fix_33_0_uns_bits_2((HWOffsetFix<33,0,UNSIGNED>(varint_u<33>(0x000000001l))))
, c_hw_fix_1_0_uns_bits_1((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x0l))))
, c_hw_fix_32_0_sgn_undef((HWOffsetFix<32,0,TWOSCOMPLEMENT>()))
, c_hw_flt_8_24_undef((HWFloat<8,24>()))
, c_hw_flt_8_24_2_0val((HWFloat<8,24>(varint_u<32>(0x40000000l))))
, c_hw_fix_1_0_uns_undef((HWOffsetFix<1,0,UNSIGNED>()))
, c_hw_bit_1_undef((HWRawBits<1>()))
, c_hw_fix_49_0_uns_bits((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x1000000000000l))))
, c_hw_fix_49_0_uns_bits_1((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000000l))))
, c_hw_fix_49_0_uns_bits_2((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000001l))))
, c_hw_fix_48_0_uns_undef((HWOffsetFix<48,0,UNSIGNED>()))
{
  { // Node ID: 140 (NodeConstantRawBits)
    id140out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 223 (NodeConstantRawBits)
    id223out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 1 (NodeConstantRawBits)
    id1out_value = (c_hw_fix_33_0_uns_bits);
  }
  { // Node ID: 3 (NodeInputMappedReg)
    registerMappedRegister("io_controller_force_disabled", Data(1));
  }
  { // Node ID: 5 (NodeInput)
     m_controller =  registerInput("controller",0,5);
  }
  { // Node ID: 7 (NodeInputMappedReg)
    registerMappedRegister("io_p_force_disabled", Data(1));
  }
  { // Node ID: 13 (NodeInput)
     m_p =  registerInput("p",1,5);
  }
  { // Node ID: 15 (NodeInputMappedReg)
    registerMappedRegister("io_pp_force_disabled", Data(1));
  }
  { // Node ID: 21 (NodeInput)
     m_pp =  registerInput("pp",2,5);
  }
  { // Node ID: 23 (NodeInputMappedReg)
    registerMappedRegister("io_dvv_force_disabled", Data(1));
  }
  { // Node ID: 29 (NodeInput)
     m_dvv =  registerInput("dvv",3,5);
  }
  { // Node ID: 44 (NodeInputMappedReg)
    registerMappedRegister("c_0", Data(32));
  }
  { // Node ID: 45 (NodeInputMappedReg)
    registerMappedRegister("c_1_0", Data(32));
  }
  { // Node ID: 46 (NodeInputMappedReg)
    registerMappedRegister("c_1_1", Data(32));
  }
  { // Node ID: 47 (NodeInputMappedReg)
    registerMappedRegister("c_1_2", Data(32));
  }
  { // Node ID: 48 (NodeInputMappedReg)
    registerMappedRegister("c_1_3", Data(32));
  }
  { // Node ID: 49 (NodeInputMappedReg)
    registerMappedRegister("c_1_4", Data(32));
  }
  { // Node ID: 50 (NodeInputMappedReg)
    registerMappedRegister("c_2_0", Data(32));
  }
  { // Node ID: 41 (NodeInputMappedReg)
    registerMappedRegister("io_py_force_disabled", Data(1));
  }
  { // Node ID: 43 (NodeInput)
     m_py =  registerInput("py",6,5);
  }
  { // Node ID: 51 (NodeInputMappedReg)
    registerMappedRegister("c_2_1", Data(32));
  }
  { // Node ID: 52 (NodeInputMappedReg)
    registerMappedRegister("c_2_2", Data(32));
  }
  { // Node ID: 53 (NodeInputMappedReg)
    registerMappedRegister("c_2_3", Data(32));
  }
  { // Node ID: 54 (NodeInputMappedReg)
    registerMappedRegister("c_2_4", Data(32));
  }
  { // Node ID: 55 (NodeInputMappedReg)
    registerMappedRegister("c_3_0", Data(32));
  }
  { // Node ID: 38 (NodeInputMappedReg)
    registerMappedRegister("io_px_force_disabled", Data(1));
  }
  { // Node ID: 40 (NodeInput)
     m_px =  registerInput("px",5,5);
  }
  { // Node ID: 56 (NodeInputMappedReg)
    registerMappedRegister("c_3_1", Data(32));
  }
  { // Node ID: 57 (NodeInputMappedReg)
    registerMappedRegister("c_3_2", Data(32));
  }
  { // Node ID: 58 (NodeInputMappedReg)
    registerMappedRegister("c_3_3", Data(32));
  }
  { // Node ID: 59 (NodeInputMappedReg)
    registerMappedRegister("c_3_4", Data(32));
  }
  { // Node ID: 31 (NodeInputMappedReg)
    registerMappedRegister("io_source_container_force_disabled", Data(1));
  }
  { // Node ID: 37 (NodeInput)
     m_source_container =  registerInput("source_container",4,5);
  }
  { // Node ID: 143 (NodeInputMappedReg)
    registerMappedRegister("io_ppresult_force_disabled", Data(1));
  }
  { // Node ID: 149 (NodeOutput)
    m_ppresult = registerOutput("ppresult",0 );
  }
  { // Node ID: 153 (NodeConstantRawBits)
    id153out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 222 (NodeConstantRawBits)
    id222out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 151 (NodeConstantRawBits)
    id151out_value = (c_hw_fix_49_0_uns_bits);
  }
  { // Node ID: 154 (NodeOutputMappedReg)
    registerMappedRegister("current_run_cycle_count", Data(48));
  }
  { // Node ID: 156 (NodeInputMappedReg)
    registerMappedRegister("run_cycle_count", Data(48));
  }
}

void linearKernel::resetComputation() {
  resetComputationAfterFlush();
}

void linearKernel::resetComputationAfterFlush() {
  { // Node ID: 2 (NodeCounterV1)

    (id2st_count) = (c_hw_fix_33_0_uns_bits_1);
  }
  { // Node ID: 3 (NodeInputMappedReg)
    id3out_io_controller_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_controller_force_disabled");
  }
  { // Node ID: 5 (NodeInput)

    (id5st_read_next_cycle) = (c_hw_fix_1_0_uns_bits_1);
    (id5st_last_read_value) = (c_hw_fix_32_0_sgn_undef);
  }
  { // Node ID: 7 (NodeInputMappedReg)
    id7out_io_p_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_p_force_disabled");
  }
  { // Node ID: 13 (NodeInput)

    (id13st_read_next_cycle) = (c_hw_fix_1_0_uns_bits_1);
    (id13st_last_read_value) = (c_hw_flt_8_24_undef);
  }
  { // Node ID: 164 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id164out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 199 (NodeFIFO)

    for(int i=0; i<10; i++)
    {
      id199out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 200 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id200out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 201 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id201out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 202 (NodeFIFO)

    for(int i=0; i<8; i++)
    {
      id202out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 203 (NodeFIFO)

    for(int i=0; i<7; i++)
    {
      id203out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 204 (NodeFIFO)

    for(int i=0; i<6; i++)
    {
      id204out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 205 (NodeFIFO)

    for(int i=0; i<9; i++)
    {
      id205out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 206 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id206out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 207 (NodeFIFO)

    for(int i=0; i<11; i++)
    {
      id207out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 160 (NodeFIFO)

    for(int i=0; i<56; i++)
    {
      id160out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 15 (NodeInputMappedReg)
    id15out_io_pp_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_pp_force_disabled");
  }
  { // Node ID: 21 (NodeInput)

    (id21st_read_next_cycle) = (c_hw_fix_1_0_uns_bits_1);
    (id21st_last_read_value) = (c_hw_flt_8_24_undef);
  }
  { // Node ID: 193 (NodeFIFO)

    for(int i=0; i<143; i++)
    {
      id193out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 161 (NodeFIFO)

    for(int i=0; i<114; i++)
    {
      id161out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 23 (NodeInputMappedReg)
    id23out_io_dvv_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_dvv_force_disabled");
  }
  { // Node ID: 162 (NodeFIFO)

    for(int i=0; i<89; i++)
    {
      id162out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 29 (NodeInput)

    (id29st_read_next_cycle) = (c_hw_fix_1_0_uns_bits_1);
    (id29st_last_read_value) = (c_hw_flt_8_24_undef);
  }
  { // Node ID: 44 (NodeInputMappedReg)
    id44out_c_0 = getMappedRegValue<HWFloat<8,24> >("c_0");
  }
  { // Node ID: 45 (NodeInputMappedReg)
    id45out_c_1_0 = getMappedRegValue<HWFloat<8,24> >("c_1_0");
  }
  { // Node ID: 46 (NodeInputMappedReg)
    id46out_c_1_1 = getMappedRegValue<HWFloat<8,24> >("c_1_1");
  }
  { // Node ID: 47 (NodeInputMappedReg)
    id47out_c_1_2 = getMappedRegValue<HWFloat<8,24> >("c_1_2");
  }
  { // Node ID: 48 (NodeInputMappedReg)
    id48out_c_1_3 = getMappedRegValue<HWFloat<8,24> >("c_1_3");
  }
  { // Node ID: 49 (NodeInputMappedReg)
    id49out_c_1_4 = getMappedRegValue<HWFloat<8,24> >("c_1_4");
  }
  { // Node ID: 50 (NodeInputMappedReg)
    id50out_c_2_0 = getMappedRegValue<HWFloat<8,24> >("c_2_0");
  }
  { // Node ID: 41 (NodeInputMappedReg)
    id41out_io_py_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_py_force_disabled");
  }
  { // Node ID: 43 (NodeInput)

    (id43st_read_next_cycle) = (c_hw_fix_1_0_uns_bits_1);
    (id43st_last_read_value) = (c_hw_flt_8_24_undef);
  }
  { // Node ID: 173 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id173out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 51 (NodeInputMappedReg)
    id51out_c_2_1 = getMappedRegValue<HWFloat<8,24> >("c_2_1");
  }
  { // Node ID: 208 (NodeFIFO)

    for(int i=0; i<11; i++)
    {
      id208out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 209 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id209out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 52 (NodeInputMappedReg)
    id52out_c_2_2 = getMappedRegValue<HWFloat<8,24> >("c_2_2");
  }
  { // Node ID: 210 (NodeFIFO)

    for(int i=0; i<9; i++)
    {
      id210out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 211 (NodeFIFO)

    for(int i=0; i<6; i++)
    {
      id211out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 53 (NodeInputMappedReg)
    id53out_c_2_3 = getMappedRegValue<HWFloat<8,24> >("c_2_3");
  }
  { // Node ID: 212 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id212out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 213 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id213out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 214 (NodeFIFO)

    for(int i=0; i<8; i++)
    {
      id214out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 54 (NodeInputMappedReg)
    id54out_c_2_4 = getMappedRegValue<HWFloat<8,24> >("c_2_4");
  }
  { // Node ID: 182 (NodeFIFO)

    for(int i=0; i<14; i++)
    {
      id182out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 55 (NodeInputMappedReg)
    id55out_c_3_0 = getMappedRegValue<HWFloat<8,24> >("c_3_0");
  }
  { // Node ID: 38 (NodeInputMappedReg)
    id38out_io_px_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_px_force_disabled");
  }
  { // Node ID: 40 (NodeInput)

    (id40st_read_next_cycle) = (c_hw_fix_1_0_uns_bits_1);
    (id40st_last_read_value) = (c_hw_flt_8_24_undef);
  }
  { // Node ID: 183 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id183out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 56 (NodeInputMappedReg)
    id56out_c_3_1 = getMappedRegValue<HWFloat<8,24> >("c_3_1");
  }
  { // Node ID: 215 (NodeFIFO)

    for(int i=0; i<11; i++)
    {
      id215out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 216 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id216out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 57 (NodeInputMappedReg)
    id57out_c_3_2 = getMappedRegValue<HWFloat<8,24> >("c_3_2");
  }
  { // Node ID: 217 (NodeFIFO)

    for(int i=0; i<9; i++)
    {
      id217out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 218 (NodeFIFO)

    for(int i=0; i<6; i++)
    {
      id218out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 58 (NodeInputMappedReg)
    id58out_c_3_3 = getMappedRegValue<HWFloat<8,24> >("c_3_3");
  }
  { // Node ID: 219 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id219out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 220 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id220out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 221 (NodeFIFO)

    for(int i=0; i<8; i++)
    {
      id221out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 59 (NodeInputMappedReg)
    id59out_c_3_4 = getMappedRegValue<HWFloat<8,24> >("c_3_4");
  }
  { // Node ID: 192 (NodeFIFO)

    for(int i=0; i<14; i++)
    {
      id192out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 194 (NodeFIFO)

    for(int i=0; i<114; i++)
    {
      id194out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 31 (NodeInputMappedReg)
    id31out_io_source_container_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_source_container_force_disabled");
  }
  { // Node ID: 195 (NodeFIFO)

    for(int i=0; i<109; i++)
    {
      id195out_output[i] = (c_hw_bit_1_undef);
    }
  }
  { // Node ID: 37 (NodeInput)

    (id37st_read_next_cycle) = (c_hw_fix_1_0_uns_bits_1);
    (id37st_last_read_value) = (c_hw_flt_8_24_undef);
  }
  { // Node ID: 196 (NodeFIFO)

    for(int i=0; i<114; i++)
    {
      id196out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 143 (NodeInputMappedReg)
    id143out_io_ppresult_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_ppresult_force_disabled");
  }
  { // Node ID: 197 (NodeFIFO)

    for(int i=0; i<126; i++)
    {
      id197out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 152 (NodeCounterV1)

    (id152st_count) = (c_hw_fix_49_0_uns_bits_1);
  }
  { // Node ID: 198 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id198out_output[i] = (c_hw_fix_48_0_uns_undef);
    }
  }
  { // Node ID: 156 (NodeInputMappedReg)
    id156out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
}

void linearKernel::updateState() {
  { // Node ID: 3 (NodeInputMappedReg)
    id3out_io_controller_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_controller_force_disabled");
  }
  { // Node ID: 7 (NodeInputMappedReg)
    id7out_io_p_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_p_force_disabled");
  }
  { // Node ID: 15 (NodeInputMappedReg)
    id15out_io_pp_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_pp_force_disabled");
  }
  { // Node ID: 23 (NodeInputMappedReg)
    id23out_io_dvv_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_dvv_force_disabled");
  }
  { // Node ID: 44 (NodeInputMappedReg)
    id44out_c_0 = getMappedRegValue<HWFloat<8,24> >("c_0");
  }
  { // Node ID: 45 (NodeInputMappedReg)
    id45out_c_1_0 = getMappedRegValue<HWFloat<8,24> >("c_1_0");
  }
  { // Node ID: 46 (NodeInputMappedReg)
    id46out_c_1_1 = getMappedRegValue<HWFloat<8,24> >("c_1_1");
  }
  { // Node ID: 47 (NodeInputMappedReg)
    id47out_c_1_2 = getMappedRegValue<HWFloat<8,24> >("c_1_2");
  }
  { // Node ID: 48 (NodeInputMappedReg)
    id48out_c_1_3 = getMappedRegValue<HWFloat<8,24> >("c_1_3");
  }
  { // Node ID: 49 (NodeInputMappedReg)
    id49out_c_1_4 = getMappedRegValue<HWFloat<8,24> >("c_1_4");
  }
  { // Node ID: 50 (NodeInputMappedReg)
    id50out_c_2_0 = getMappedRegValue<HWFloat<8,24> >("c_2_0");
  }
  { // Node ID: 41 (NodeInputMappedReg)
    id41out_io_py_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_py_force_disabled");
  }
  { // Node ID: 51 (NodeInputMappedReg)
    id51out_c_2_1 = getMappedRegValue<HWFloat<8,24> >("c_2_1");
  }
  { // Node ID: 52 (NodeInputMappedReg)
    id52out_c_2_2 = getMappedRegValue<HWFloat<8,24> >("c_2_2");
  }
  { // Node ID: 53 (NodeInputMappedReg)
    id53out_c_2_3 = getMappedRegValue<HWFloat<8,24> >("c_2_3");
  }
  { // Node ID: 54 (NodeInputMappedReg)
    id54out_c_2_4 = getMappedRegValue<HWFloat<8,24> >("c_2_4");
  }
  { // Node ID: 55 (NodeInputMappedReg)
    id55out_c_3_0 = getMappedRegValue<HWFloat<8,24> >("c_3_0");
  }
  { // Node ID: 38 (NodeInputMappedReg)
    id38out_io_px_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_px_force_disabled");
  }
  { // Node ID: 56 (NodeInputMappedReg)
    id56out_c_3_1 = getMappedRegValue<HWFloat<8,24> >("c_3_1");
  }
  { // Node ID: 57 (NodeInputMappedReg)
    id57out_c_3_2 = getMappedRegValue<HWFloat<8,24> >("c_3_2");
  }
  { // Node ID: 58 (NodeInputMappedReg)
    id58out_c_3_3 = getMappedRegValue<HWFloat<8,24> >("c_3_3");
  }
  { // Node ID: 59 (NodeInputMappedReg)
    id59out_c_3_4 = getMappedRegValue<HWFloat<8,24> >("c_3_4");
  }
  { // Node ID: 31 (NodeInputMappedReg)
    id31out_io_source_container_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_source_container_force_disabled");
  }
  { // Node ID: 143 (NodeInputMappedReg)
    id143out_io_ppresult_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_ppresult_force_disabled");
  }
  { // Node ID: 156 (NodeInputMappedReg)
    id156out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
}

void linearKernel::preExecute() {
  { // Node ID: 5 (NodeInput)
    if(((needsToReadInput(m_controller))&(((getFlushLevel())<((4l)+(5)))|(!(isFlushingActive()))))) {
      (id5st_last_read_value) = (readInput<HWOffsetFix<32,0,TWOSCOMPLEMENT> >(m_controller));
    }
    id5out_data = (id5st_last_read_value);
  }
  { // Node ID: 13 (NodeInput)
    if(((needsToReadInput(m_p))&(((getFlushLevel())<((9l)+(5)))|(!(isFlushingActive()))))) {
      (id13st_last_read_value) = (readInput<HWFloat<8,24> >(m_p));
    }
    id13out_data = (id13st_last_read_value);
  }
  { // Node ID: 21 (NodeInput)
    if(((needsToReadInput(m_pp))&(((getFlushLevel())<((64l)+(5)))|(!(isFlushingActive()))))) {
      (id21st_last_read_value) = (readInput<HWFloat<8,24> >(m_pp));
    }
    id21out_data = (id21st_last_read_value);
  }
  { // Node ID: 29 (NodeInput)
    if(((needsToReadInput(m_dvv))&(((getFlushLevel())<((210l)+(5)))|(!(isFlushingActive()))))) {
      (id29st_last_read_value) = (readInput<HWFloat<8,24> >(m_dvv));
    }
    id29out_data = (id29st_last_read_value);
  }
  { // Node ID: 43 (NodeInput)
    if(((needsToReadInput(m_py))&(((getFlushLevel())<((74l)+(5)))|(!(isFlushingActive()))))) {
      (id43st_last_read_value) = (readInput<HWFloat<8,24> >(m_py));
    }
    id43out_data = (id43st_last_read_value);
  }
  { // Node ID: 40 (NodeInput)
    if(((needsToReadInput(m_px))&(((getFlushLevel())<((134l)+(5)))|(!(isFlushingActive()))))) {
      (id40st_last_read_value) = (readInput<HWFloat<8,24> >(m_px));
    }
    id40out_data = (id40st_last_read_value);
  }
  { // Node ID: 37 (NodeInput)
    if(((needsToReadInput(m_source_container))&(((getFlushLevel())<((230l)+(5)))|(!(isFlushingActive()))))) {
      (id37st_last_read_value) = (readInput<HWFloat<8,24> >(m_source_container));
    }
    id37out_data = (id37st_last_read_value);
  }
}

void linearKernel::runComputationCycle() {
  if (m_mappedElementsChanged) {
    m_mappedElementsChanged = false;
    updateState();
    std::cout << "linearKernel: Mapped Elements Changed: Reloaded" << std::endl;
  }
  preExecute();
  execute0();
}

int linearKernel::getFlushLevelStart() {
  return ((1l)+(3l));
}

}
