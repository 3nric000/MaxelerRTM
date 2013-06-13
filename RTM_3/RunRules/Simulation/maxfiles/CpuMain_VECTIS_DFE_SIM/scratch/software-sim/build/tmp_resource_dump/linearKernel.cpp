#include "stdsimheader.h"
#include "linearKernel.h"

namespace maxcompilersim {

linearKernel::linearKernel(const std::string &instance_name) : 
  KernelManagerBlockSync(instance_name, 247, 2, 0, 0, "",1)
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
  { // Node ID: 138 (NodeInputMappedReg)
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
  { // Node ID: 20 (NodeInputMappedReg)
    registerMappedRegister("io_dvv_force_disabled", Data(1));
  }
  { // Node ID: 26 (NodeInput)
     m_dvv =  registerInput("dvv",3,5);
  }
  { // Node ID: 41 (NodeInputMappedReg)
    registerMappedRegister("c_0", Data(32));
  }
  { // Node ID: 42 (NodeInputMappedReg)
    registerMappedRegister("c_1_0", Data(32));
  }
  { // Node ID: 43 (NodeInputMappedReg)
    registerMappedRegister("c_1_1", Data(32));
  }
  { // Node ID: 44 (NodeInputMappedReg)
    registerMappedRegister("c_1_2", Data(32));
  }
  { // Node ID: 45 (NodeInputMappedReg)
    registerMappedRegister("c_1_3", Data(32));
  }
  { // Node ID: 46 (NodeInputMappedReg)
    registerMappedRegister("c_1_4", Data(32));
  }
  { // Node ID: 47 (NodeInputMappedReg)
    registerMappedRegister("c_2_0", Data(32));
  }
  { // Node ID: 38 (NodeInputMappedReg)
    registerMappedRegister("io_py_force_disabled", Data(1));
  }
  { // Node ID: 40 (NodeInput)
     m_py =  registerInput("py",6,5);
  }
  { // Node ID: 48 (NodeInputMappedReg)
    registerMappedRegister("c_2_1", Data(32));
  }
  { // Node ID: 49 (NodeInputMappedReg)
    registerMappedRegister("c_2_2", Data(32));
  }
  { // Node ID: 50 (NodeInputMappedReg)
    registerMappedRegister("c_2_3", Data(32));
  }
  { // Node ID: 51 (NodeInputMappedReg)
    registerMappedRegister("c_2_4", Data(32));
  }
  { // Node ID: 52 (NodeInputMappedReg)
    registerMappedRegister("c_3_0", Data(32));
  }
  { // Node ID: 35 (NodeInputMappedReg)
    registerMappedRegister("io_px_force_disabled", Data(1));
  }
  { // Node ID: 37 (NodeInput)
     m_px =  registerInput("px",5,5);
  }
  { // Node ID: 53 (NodeInputMappedReg)
    registerMappedRegister("c_3_1", Data(32));
  }
  { // Node ID: 54 (NodeInputMappedReg)
    registerMappedRegister("c_3_2", Data(32));
  }
  { // Node ID: 55 (NodeInputMappedReg)
    registerMappedRegister("c_3_3", Data(32));
  }
  { // Node ID: 56 (NodeInputMappedReg)
    registerMappedRegister("c_3_4", Data(32));
  }
  { // Node ID: 28 (NodeInputMappedReg)
    registerMappedRegister("io_source_container_force_disabled", Data(1));
  }
  { // Node ID: 34 (NodeInput)
     m_source_container =  registerInput("source_container",4,5);
  }
  { // Node ID: 144 (NodeOutput)
    m_ppresult = registerOutput("ppresult",0 );
  }
  { // Node ID: 148 (NodeConstantRawBits)
    id148out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 217 (NodeConstantRawBits)
    id217out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 146 (NodeConstantRawBits)
    id146out_value = (c_hw_fix_49_0_uns_bits);
  }
  { // Node ID: 149 (NodeOutputMappedReg)
    registerMappedRegister("current_run_cycle_count", Data(48));
  }
  { // Node ID: 151 (NodeInputMappedReg)
    registerMappedRegister("run_cycle_count", Data(48));
  }
}

void linearKernel::resetComputation() {
  resetComputationAfterFlush();
}

void linearKernel::resetComputationAfterFlush() {
  { // Node ID: 0 (NodeInputMappedReg)
    id0out_io_controller_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_controller_force_disabled");
  }
  { // Node ID: 2 (NodeInput)

    (id2st_read_next_cycle) = (c_hw_fix_1_0_uns_bits);
    (id2st_last_read_value) = (c_hw_fix_32_0_sgn_undef);
  }
  { // Node ID: 154 (NodeFIFO)

    for(int i=0; i<111; i++)
    {
      id154out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 138 (NodeInputMappedReg)
    id138out_io_ppresult_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_ppresult_force_disabled");
  }
  { // Node ID: 192 (NodeFIFO)

    for(int i=0; i<129; i++)
    {
      id192out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 4 (NodeInputMappedReg)
    id4out_io_p_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_p_force_disabled");
  }
  { // Node ID: 10 (NodeInput)

    (id10st_read_next_cycle) = (c_hw_fix_1_0_uns_bits);
    (id10st_last_read_value) = (c_hw_flt_8_24_undef);
  }
  { // Node ID: 160 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id160out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 194 (NodeFIFO)

    for(int i=0; i<10; i++)
    {
      id194out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 195 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id195out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 196 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id196out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 197 (NodeFIFO)

    for(int i=0; i<8; i++)
    {
      id197out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 198 (NodeFIFO)

    for(int i=0; i<7; i++)
    {
      id198out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 199 (NodeFIFO)

    for(int i=0; i<6; i++)
    {
      id199out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 200 (NodeFIFO)

    for(int i=0; i<9; i++)
    {
      id200out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 201 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id201out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 202 (NodeFIFO)

    for(int i=0; i<11; i++)
    {
      id202out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 156 (NodeFIFO)

    for(int i=0; i<56; i++)
    {
      id156out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 12 (NodeInputMappedReg)
    id12out_io_pp_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_pp_force_disabled");
  }
  { // Node ID: 18 (NodeInput)

    (id18st_read_next_cycle) = (c_hw_fix_1_0_uns_bits);
    (id18st_last_read_value) = (c_hw_flt_8_24_undef);
  }
  { // Node ID: 189 (NodeFIFO)

    for(int i=0; i<143; i++)
    {
      id189out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 157 (NodeFIFO)

    for(int i=0; i<111; i++)
    {
      id157out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 20 (NodeInputMappedReg)
    id20out_io_dvv_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_dvv_force_disabled");
  }
  { // Node ID: 158 (NodeFIFO)

    for(int i=0; i<92; i++)
    {
      id158out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 26 (NodeInput)

    (id26st_read_next_cycle) = (c_hw_fix_1_0_uns_bits);
    (id26st_last_read_value) = (c_hw_flt_8_24_undef);
  }
  { // Node ID: 41 (NodeInputMappedReg)
    id41out_c_0 = getMappedRegValue<HWFloat<8,24> >("c_0");
  }
  { // Node ID: 42 (NodeInputMappedReg)
    id42out_c_1_0 = getMappedRegValue<HWFloat<8,24> >("c_1_0");
  }
  { // Node ID: 43 (NodeInputMappedReg)
    id43out_c_1_1 = getMappedRegValue<HWFloat<8,24> >("c_1_1");
  }
  { // Node ID: 44 (NodeInputMappedReg)
    id44out_c_1_2 = getMappedRegValue<HWFloat<8,24> >("c_1_2");
  }
  { // Node ID: 45 (NodeInputMappedReg)
    id45out_c_1_3 = getMappedRegValue<HWFloat<8,24> >("c_1_3");
  }
  { // Node ID: 46 (NodeInputMappedReg)
    id46out_c_1_4 = getMappedRegValue<HWFloat<8,24> >("c_1_4");
  }
  { // Node ID: 47 (NodeInputMappedReg)
    id47out_c_2_0 = getMappedRegValue<HWFloat<8,24> >("c_2_0");
  }
  { // Node ID: 38 (NodeInputMappedReg)
    id38out_io_py_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_py_force_disabled");
  }
  { // Node ID: 40 (NodeInput)

    (id40st_read_next_cycle) = (c_hw_fix_1_0_uns_bits);
    (id40st_last_read_value) = (c_hw_flt_8_24_undef);
  }
  { // Node ID: 169 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id169out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 48 (NodeInputMappedReg)
    id48out_c_2_1 = getMappedRegValue<HWFloat<8,24> >("c_2_1");
  }
  { // Node ID: 203 (NodeFIFO)

    for(int i=0; i<11; i++)
    {
      id203out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 204 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id204out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 49 (NodeInputMappedReg)
    id49out_c_2_2 = getMappedRegValue<HWFloat<8,24> >("c_2_2");
  }
  { // Node ID: 205 (NodeFIFO)

    for(int i=0; i<9; i++)
    {
      id205out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 206 (NodeFIFO)

    for(int i=0; i<6; i++)
    {
      id206out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 50 (NodeInputMappedReg)
    id50out_c_2_3 = getMappedRegValue<HWFloat<8,24> >("c_2_3");
  }
  { // Node ID: 207 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id207out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 208 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id208out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 209 (NodeFIFO)

    for(int i=0; i<8; i++)
    {
      id209out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 51 (NodeInputMappedReg)
    id51out_c_2_4 = getMappedRegValue<HWFloat<8,24> >("c_2_4");
  }
  { // Node ID: 178 (NodeFIFO)

    for(int i=0; i<14; i++)
    {
      id178out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 52 (NodeInputMappedReg)
    id52out_c_3_0 = getMappedRegValue<HWFloat<8,24> >("c_3_0");
  }
  { // Node ID: 35 (NodeInputMappedReg)
    id35out_io_px_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_px_force_disabled");
  }
  { // Node ID: 37 (NodeInput)

    (id37st_read_next_cycle) = (c_hw_fix_1_0_uns_bits);
    (id37st_last_read_value) = (c_hw_flt_8_24_undef);
  }
  { // Node ID: 179 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id179out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 53 (NodeInputMappedReg)
    id53out_c_3_1 = getMappedRegValue<HWFloat<8,24> >("c_3_1");
  }
  { // Node ID: 210 (NodeFIFO)

    for(int i=0; i<11; i++)
    {
      id210out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 211 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id211out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 54 (NodeInputMappedReg)
    id54out_c_3_2 = getMappedRegValue<HWFloat<8,24> >("c_3_2");
  }
  { // Node ID: 212 (NodeFIFO)

    for(int i=0; i<9; i++)
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
  { // Node ID: 55 (NodeInputMappedReg)
    id55out_c_3_3 = getMappedRegValue<HWFloat<8,24> >("c_3_3");
  }
  { // Node ID: 214 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id214out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 215 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id215out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 216 (NodeFIFO)

    for(int i=0; i<8; i++)
    {
      id216out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 56 (NodeInputMappedReg)
    id56out_c_3_4 = getMappedRegValue<HWFloat<8,24> >("c_3_4");
  }
  { // Node ID: 188 (NodeFIFO)

    for(int i=0; i<14; i++)
    {
      id188out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 190 (NodeFIFO)

    for(int i=0; i<111; i++)
    {
      id190out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 28 (NodeInputMappedReg)
    id28out_io_source_container_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_source_container_force_disabled");
  }
  { // Node ID: 191 (NodeFIFO)

    for(int i=0; i<112; i++)
    {
      id191out_output[i] = (c_hw_bit_1_undef);
    }
  }
  { // Node ID: 34 (NodeInput)

    (id34st_read_next_cycle) = (c_hw_fix_1_0_uns_bits);
    (id34st_last_read_value) = (c_hw_flt_8_24_undef);
  }
  { // Node ID: 147 (NodeCounterV1)

    (id147st_count) = (c_hw_fix_49_0_uns_bits_1);
  }
  { // Node ID: 193 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id193out_output[i] = (c_hw_fix_48_0_uns_undef);
    }
  }
  { // Node ID: 151 (NodeInputMappedReg)
    id151out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
}

void linearKernel::updateState() {
  { // Node ID: 0 (NodeInputMappedReg)
    id0out_io_controller_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_controller_force_disabled");
  }
  { // Node ID: 138 (NodeInputMappedReg)
    id138out_io_ppresult_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_ppresult_force_disabled");
  }
  { // Node ID: 4 (NodeInputMappedReg)
    id4out_io_p_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_p_force_disabled");
  }
  { // Node ID: 12 (NodeInputMappedReg)
    id12out_io_pp_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_pp_force_disabled");
  }
  { // Node ID: 20 (NodeInputMappedReg)
    id20out_io_dvv_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_dvv_force_disabled");
  }
  { // Node ID: 41 (NodeInputMappedReg)
    id41out_c_0 = getMappedRegValue<HWFloat<8,24> >("c_0");
  }
  { // Node ID: 42 (NodeInputMappedReg)
    id42out_c_1_0 = getMappedRegValue<HWFloat<8,24> >("c_1_0");
  }
  { // Node ID: 43 (NodeInputMappedReg)
    id43out_c_1_1 = getMappedRegValue<HWFloat<8,24> >("c_1_1");
  }
  { // Node ID: 44 (NodeInputMappedReg)
    id44out_c_1_2 = getMappedRegValue<HWFloat<8,24> >("c_1_2");
  }
  { // Node ID: 45 (NodeInputMappedReg)
    id45out_c_1_3 = getMappedRegValue<HWFloat<8,24> >("c_1_3");
  }
  { // Node ID: 46 (NodeInputMappedReg)
    id46out_c_1_4 = getMappedRegValue<HWFloat<8,24> >("c_1_4");
  }
  { // Node ID: 47 (NodeInputMappedReg)
    id47out_c_2_0 = getMappedRegValue<HWFloat<8,24> >("c_2_0");
  }
  { // Node ID: 38 (NodeInputMappedReg)
    id38out_io_py_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_py_force_disabled");
  }
  { // Node ID: 48 (NodeInputMappedReg)
    id48out_c_2_1 = getMappedRegValue<HWFloat<8,24> >("c_2_1");
  }
  { // Node ID: 49 (NodeInputMappedReg)
    id49out_c_2_2 = getMappedRegValue<HWFloat<8,24> >("c_2_2");
  }
  { // Node ID: 50 (NodeInputMappedReg)
    id50out_c_2_3 = getMappedRegValue<HWFloat<8,24> >("c_2_3");
  }
  { // Node ID: 51 (NodeInputMappedReg)
    id51out_c_2_4 = getMappedRegValue<HWFloat<8,24> >("c_2_4");
  }
  { // Node ID: 52 (NodeInputMappedReg)
    id52out_c_3_0 = getMappedRegValue<HWFloat<8,24> >("c_3_0");
  }
  { // Node ID: 35 (NodeInputMappedReg)
    id35out_io_px_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_px_force_disabled");
  }
  { // Node ID: 53 (NodeInputMappedReg)
    id53out_c_3_1 = getMappedRegValue<HWFloat<8,24> >("c_3_1");
  }
  { // Node ID: 54 (NodeInputMappedReg)
    id54out_c_3_2 = getMappedRegValue<HWFloat<8,24> >("c_3_2");
  }
  { // Node ID: 55 (NodeInputMappedReg)
    id55out_c_3_3 = getMappedRegValue<HWFloat<8,24> >("c_3_3");
  }
  { // Node ID: 56 (NodeInputMappedReg)
    id56out_c_3_4 = getMappedRegValue<HWFloat<8,24> >("c_3_4");
  }
  { // Node ID: 28 (NodeInputMappedReg)
    id28out_io_source_container_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_source_container_force_disabled");
  }
  { // Node ID: 151 (NodeInputMappedReg)
    id151out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
}

void linearKernel::preExecute() {
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
    if(((needsToReadInput(m_pp))&(((getFlushLevel())<((64l)+(5)))|(!(isFlushingActive()))))) {
      (id18st_last_read_value) = (readInput<HWFloat<8,24> >(m_pp));
    }
    id18out_data = (id18st_last_read_value);
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
