#include "stdsimheader.h"
#include "cpu_mainKernel.h"

namespace maxcompilersim {

cpu_mainKernel::cpu_mainKernel(const std::string &instance_name) : 
  KernelManagerBlockSync(instance_name, 9501, 2, 0, 0, "",1)
, c_hw_fix_1_0_uns_bits((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x0l))))
, c_hw_flt_8_24_undef((HWFloat<8,24>()))
, c_hw_flt_8_24_2_0val((HWFloat<8,24>(varint_u<32>(0x40000000l))))
, c_hw_fix_1_0_uns_bits_1((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x1l))))
, c_hw_fix_49_0_uns_bits((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x1000000000000l))))
, c_hw_fix_49_0_uns_bits_1((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000000l))))
, c_hw_fix_49_0_uns_bits_2((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000001l))))
, c_hw_fix_48_0_uns_undef((HWOffsetFix<48,0,UNSIGNED>()))
{
  { // Node ID: 111 (NodeInputMappedReg)
    registerMappedRegister("io_pp_force_disabled", Data(1));
  }
  { // Node ID: 0 (NodeInputMappedReg)
    registerMappedRegister("io_p_force_disabled", Data(1));
  }
  { // Node ID: 2 (NodeInput)
     m_p =  registerInput("p",0,5);
  }
  { // Node ID: 4 (NodeInputMappedReg)
    registerMappedRegister("io_pp_value_force_disabled", Data(1));
  }
  { // Node ID: 6 (NodeInput)
     m_pp_value =  registerInput("pp_value",1,5);
  }
  { // Node ID: 7 (NodeInputMappedReg)
    registerMappedRegister("io_dvv_value_force_disabled", Data(1));
  }
  { // Node ID: 9 (NodeInput)
     m_dvv_value =  registerInput("dvv_value",2,5);
  }
  { // Node ID: 3 (NodeInputMappedReg)
    registerMappedRegister("c_0", Data(32));
  }
  { // Node ID: 13 (NodeInputMappedReg)
    registerMappedRegister("c_1_0", Data(32));
  }
  { // Node ID: 14 (NodeInputMappedReg)
    registerMappedRegister("c_1_1", Data(32));
  }
  { // Node ID: 15 (NodeInputMappedReg)
    registerMappedRegister("c_1_2", Data(32));
  }
  { // Node ID: 16 (NodeInputMappedReg)
    registerMappedRegister("c_1_3", Data(32));
  }
  { // Node ID: 17 (NodeInputMappedReg)
    registerMappedRegister("c_1_4", Data(32));
  }
  { // Node ID: 18 (NodeInputMappedReg)
    registerMappedRegister("c_2_0", Data(32));
  }
  { // Node ID: 19 (NodeInputMappedReg)
    registerMappedRegister("c_2_1", Data(32));
  }
  { // Node ID: 20 (NodeInputMappedReg)
    registerMappedRegister("c_2_2", Data(32));
  }
  { // Node ID: 21 (NodeInputMappedReg)
    registerMappedRegister("c_2_3", Data(32));
  }
  { // Node ID: 22 (NodeInputMappedReg)
    registerMappedRegister("c_2_4", Data(32));
  }
  { // Node ID: 23 (NodeInputMappedReg)
    registerMappedRegister("c_3_0", Data(32));
  }
  { // Node ID: 24 (NodeInputMappedReg)
    registerMappedRegister("c_3_1", Data(32));
  }
  { // Node ID: 25 (NodeInputMappedReg)
    registerMappedRegister("c_3_2", Data(32));
  }
  { // Node ID: 26 (NodeInputMappedReg)
    registerMappedRegister("c_3_3", Data(32));
  }
  { // Node ID: 27 (NodeInputMappedReg)
    registerMappedRegister("c_3_4", Data(32));
  }
  { // Node ID: 10 (NodeInputMappedReg)
    registerMappedRegister("io_source_container_value_force_disabled", Data(1));
  }
  { // Node ID: 12 (NodeInput)
     m_source_container_value =  registerInput("source_container_value",3,5);
  }
  { // Node ID: 117 (NodeOutput)
    m_pp = registerOutput("pp",0 );
  }
  { // Node ID: 121 (NodeConstantRawBits)
    id121out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 190 (NodeConstantRawBits)
    id190out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 119 (NodeConstantRawBits)
    id119out_value = (c_hw_fix_49_0_uns_bits);
  }
  { // Node ID: 122 (NodeOutputMappedReg)
    registerMappedRegister("current_run_cycle_count", Data(48));
  }
  { // Node ID: 124 (NodeInputMappedReg)
    registerMappedRegister("run_cycle_count", Data(48));
  }
}

void cpu_mainKernel::resetComputation() {
  resetComputationAfterFlush();
}

void cpu_mainKernel::resetComputationAfterFlush() {
  { // Node ID: 111 (NodeInputMappedReg)
    id111out_io_pp_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_pp_force_disabled");
  }
  { // Node ID: 0 (NodeInputMappedReg)
    id0out_io_p_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_p_force_disabled");
  }
  { // Node ID: 2 (NodeInput)

    (id2st_read_next_cycle) = (c_hw_fix_1_0_uns_bits);
    (id2st_last_read_value) = (c_hw_flt_8_24_undef);
  }
  { // Node ID: 156 (NodeFIFO)

    for(int i=0; i<1045; i++)
    {
      id156out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 161 (NodeFIFO)

    for(int i=0; i<1045; i++)
    {
      id161out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 162 (NodeFIFO)

    for(int i=0; i<1045; i++)
    {
      id162out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 163 (NodeFIFO)

    for(int i=0; i<1045; i++)
    {
      id163out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 164 (NodeFIFO)

    for(int i=0; i<565; i++)
    {
      id164out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 165 (NodeFIFO)

    for(int i=0; i<85; i++)
    {
      id165out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 166 (NodeFIFO)

    for(int i=0; i<85; i++)
    {
      id166out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 167 (NodeFIFO)

    for(int i=0; i<85; i++)
    {
      id167out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 168 (NodeFIFO)

    for(int i=0; i<85; i++)
    {
      id168out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 169 (NodeFIFO)

    for(int i=0; i<36; i++)
    {
      id169out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 170 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id170out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 171 (NodeFIFO)

    for(int i=0; i<10; i++)
    {
      id171out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 172 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id172out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 173 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id173out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 174 (NodeFIFO)

    for(int i=0; i<8; i++)
    {
      id174out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 175 (NodeFIFO)

    for(int i=0; i<7; i++)
    {
      id175out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 176 (NodeFIFO)

    for(int i=0; i<6; i++)
    {
      id176out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 177 (NodeFIFO)

    for(int i=0; i<9; i++)
    {
      id177out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 178 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id178out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 179 (NodeFIFO)

    for(int i=0; i<11; i++)
    {
      id179out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 180 (NodeFIFO)

    for(int i=0; i<104; i++)
    {
      id180out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 181 (NodeFIFO)

    for(int i=0; i<40; i++)
    {
      id181out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 4 (NodeInputMappedReg)
    id4out_io_pp_value_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_pp_value_force_disabled");
  }
  { // Node ID: 6 (NodeInput)

    (id6st_read_next_cycle) = (c_hw_fix_1_0_uns_bits);
    (id6st_last_read_value) = (c_hw_flt_8_24_undef);
  }
  { // Node ID: 7 (NodeInputMappedReg)
    id7out_io_dvv_value_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_dvv_value_force_disabled");
  }
  { // Node ID: 9 (NodeInput)

    (id9st_read_next_cycle) = (c_hw_fix_1_0_uns_bits);
    (id9st_last_read_value) = (c_hw_flt_8_24_undef);
  }
  { // Node ID: 3 (NodeInputMappedReg)
    id3out_c_0 = getMappedRegValue<HWFloat<8,24> >("c_0");
  }
  { // Node ID: 13 (NodeInputMappedReg)
    id13out_c_1_0 = getMappedRegValue<HWFloat<8,24> >("c_1_0");
  }
  { // Node ID: 14 (NodeInputMappedReg)
    id14out_c_1_1 = getMappedRegValue<HWFloat<8,24> >("c_1_1");
  }
  { // Node ID: 15 (NodeInputMappedReg)
    id15out_c_1_2 = getMappedRegValue<HWFloat<8,24> >("c_1_2");
  }
  { // Node ID: 16 (NodeInputMappedReg)
    id16out_c_1_3 = getMappedRegValue<HWFloat<8,24> >("c_1_3");
  }
  { // Node ID: 17 (NodeInputMappedReg)
    id17out_c_1_4 = getMappedRegValue<HWFloat<8,24> >("c_1_4");
  }
  { // Node ID: 18 (NodeInputMappedReg)
    id18out_c_2_0 = getMappedRegValue<HWFloat<8,24> >("c_2_0");
  }
  { // Node ID: 19 (NodeInputMappedReg)
    id19out_c_2_1 = getMappedRegValue<HWFloat<8,24> >("c_2_1");
  }
  { // Node ID: 182 (NodeFIFO)

    for(int i=0; i<70; i++)
    {
      id182out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 20 (NodeInputMappedReg)
    id20out_c_2_2 = getMappedRegValue<HWFloat<8,24> >("c_2_2");
  }
  { // Node ID: 183 (NodeFIFO)

    for(int i=0; i<109; i++)
    {
      id183out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 21 (NodeInputMappedReg)
    id21out_c_2_3 = getMappedRegValue<HWFloat<8,24> >("c_2_3");
  }
  { // Node ID: 184 (NodeFIFO)

    for(int i=0; i<109; i++)
    {
      id184out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 22 (NodeInputMappedReg)
    id22out_c_2_4 = getMappedRegValue<HWFloat<8,24> >("c_2_4");
  }
  { // Node ID: 185 (NodeFIFO)

    for(int i=0; i<109; i++)
    {
      id185out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 23 (NodeInputMappedReg)
    id23out_c_3_0 = getMappedRegValue<HWFloat<8,24> >("c_3_0");
  }
  { // Node ID: 186 (NodeFIFO)

    for(int i=0; i<589; i++)
    {
      id186out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 24 (NodeInputMappedReg)
    id24out_c_3_1 = getMappedRegValue<HWFloat<8,24> >("c_3_1");
  }
  { // Node ID: 187 (NodeFIFO)

    for(int i=0; i<1069; i++)
    {
      id187out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 25 (NodeInputMappedReg)
    id25out_c_3_2 = getMappedRegValue<HWFloat<8,24> >("c_3_2");
  }
  { // Node ID: 188 (NodeFIFO)

    for(int i=0; i<1069; i++)
    {
      id188out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 26 (NodeInputMappedReg)
    id26out_c_3_3 = getMappedRegValue<HWFloat<8,24> >("c_3_3");
  }
  { // Node ID: 189 (NodeFIFO)

    for(int i=0; i<1069; i++)
    {
      id189out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 27 (NodeInputMappedReg)
    id27out_c_3_4 = getMappedRegValue<HWFloat<8,24> >("c_3_4");
  }
  { // Node ID: 159 (NodeFIFO)

    for(int i=0; i<1069; i++)
    {
      id159out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 10 (NodeInputMappedReg)
    id10out_io_source_container_value_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_source_container_value_force_disabled");
  }
  { // Node ID: 12 (NodeInput)

    (id12st_read_next_cycle) = (c_hw_fix_1_0_uns_bits);
    (id12st_last_read_value) = (c_hw_flt_8_24_undef);
  }
  { // Node ID: 120 (NodeCounterV1)

    (id120st_count) = (c_hw_fix_49_0_uns_bits_1);
  }
  { // Node ID: 160 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id160out_output[i] = (c_hw_fix_48_0_uns_undef);
    }
  }
  { // Node ID: 124 (NodeInputMappedReg)
    id124out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
}

void cpu_mainKernel::updateState() {
  { // Node ID: 111 (NodeInputMappedReg)
    id111out_io_pp_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_pp_force_disabled");
  }
  { // Node ID: 0 (NodeInputMappedReg)
    id0out_io_p_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_p_force_disabled");
  }
  { // Node ID: 4 (NodeInputMappedReg)
    id4out_io_pp_value_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_pp_value_force_disabled");
  }
  { // Node ID: 7 (NodeInputMappedReg)
    id7out_io_dvv_value_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_dvv_value_force_disabled");
  }
  { // Node ID: 3 (NodeInputMappedReg)
    id3out_c_0 = getMappedRegValue<HWFloat<8,24> >("c_0");
  }
  { // Node ID: 13 (NodeInputMappedReg)
    id13out_c_1_0 = getMappedRegValue<HWFloat<8,24> >("c_1_0");
  }
  { // Node ID: 14 (NodeInputMappedReg)
    id14out_c_1_1 = getMappedRegValue<HWFloat<8,24> >("c_1_1");
  }
  { // Node ID: 15 (NodeInputMappedReg)
    id15out_c_1_2 = getMappedRegValue<HWFloat<8,24> >("c_1_2");
  }
  { // Node ID: 16 (NodeInputMappedReg)
    id16out_c_1_3 = getMappedRegValue<HWFloat<8,24> >("c_1_3");
  }
  { // Node ID: 17 (NodeInputMappedReg)
    id17out_c_1_4 = getMappedRegValue<HWFloat<8,24> >("c_1_4");
  }
  { // Node ID: 18 (NodeInputMappedReg)
    id18out_c_2_0 = getMappedRegValue<HWFloat<8,24> >("c_2_0");
  }
  { // Node ID: 19 (NodeInputMappedReg)
    id19out_c_2_1 = getMappedRegValue<HWFloat<8,24> >("c_2_1");
  }
  { // Node ID: 20 (NodeInputMappedReg)
    id20out_c_2_2 = getMappedRegValue<HWFloat<8,24> >("c_2_2");
  }
  { // Node ID: 21 (NodeInputMappedReg)
    id21out_c_2_3 = getMappedRegValue<HWFloat<8,24> >("c_2_3");
  }
  { // Node ID: 22 (NodeInputMappedReg)
    id22out_c_2_4 = getMappedRegValue<HWFloat<8,24> >("c_2_4");
  }
  { // Node ID: 23 (NodeInputMappedReg)
    id23out_c_3_0 = getMappedRegValue<HWFloat<8,24> >("c_3_0");
  }
  { // Node ID: 24 (NodeInputMappedReg)
    id24out_c_3_1 = getMappedRegValue<HWFloat<8,24> >("c_3_1");
  }
  { // Node ID: 25 (NodeInputMappedReg)
    id25out_c_3_2 = getMappedRegValue<HWFloat<8,24> >("c_3_2");
  }
  { // Node ID: 26 (NodeInputMappedReg)
    id26out_c_3_3 = getMappedRegValue<HWFloat<8,24> >("c_3_3");
  }
  { // Node ID: 27 (NodeInputMappedReg)
    id27out_c_3_4 = getMappedRegValue<HWFloat<8,24> >("c_3_4");
  }
  { // Node ID: 10 (NodeInputMappedReg)
    id10out_io_source_container_value_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_source_container_value_force_disabled");
  }
  { // Node ID: 124 (NodeInputMappedReg)
    id124out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
}

void cpu_mainKernel::preExecute() {
  { // Node ID: 2 (NodeInput)
    if(((needsToReadInput(m_p))&(((getFlushLevel())<((4l)+(5)))|(!(isFlushingActive()))))) {
      (id2st_last_read_value) = (readInput<HWFloat<8,24> >(m_p));
    }
    id2out_data = (id2st_last_read_value);
  }
  { // Node ID: 6 (NodeInput)
    if(((needsToReadInput(m_pp_value))&(((getFlushLevel())<((5312l)+(5)))|(!(isFlushingActive()))))) {
      (id6st_last_read_value) = (readInput<HWFloat<8,24> >(m_pp_value));
    }
    id6out_data = (id6st_last_read_value);
  }
  { // Node ID: 9 (NodeInput)
    if(((needsToReadInput(m_dvv_value))&(((getFlushLevel())<((5316l)+(5)))|(!(isFlushingActive()))))) {
      (id9st_last_read_value) = (readInput<HWFloat<8,24> >(m_dvv_value));
    }
    id9out_data = (id9st_last_read_value);
  }
  { // Node ID: 12 (NodeInput)
    if(((needsToReadInput(m_source_container_value))&(((getFlushLevel())<((5336l)+(5)))|(!(isFlushingActive()))))) {
      (id12st_last_read_value) = (readInput<HWFloat<8,24> >(m_source_container_value));
    }
    id12out_data = (id12st_last_read_value);
  }
}

void cpu_mainKernel::runComputationCycle() {
  if (m_mappedElementsChanged) {
    m_mappedElementsChanged = false;
    updateState();
    std::cout << "cpu_mainKernel: Mapped Elements Changed: Reloaded" << std::endl;
  }
  preExecute();
  execute0();
}

int cpu_mainKernel::getFlushLevelStart() {
  return ((1l)+(3l));
}

}
