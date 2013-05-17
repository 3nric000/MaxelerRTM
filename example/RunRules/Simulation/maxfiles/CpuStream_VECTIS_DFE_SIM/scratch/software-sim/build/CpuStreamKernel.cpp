#include "stdsimheader.h"
#include "CpuStreamKernel.h"

namespace maxcompilersim {

CpuStreamKernel::CpuStreamKernel(const std::string &instance_name) : 
  KernelManagerBlockSync(instance_name, 126, 2, 0, 0, "",1)
, c_hw_fix_1_0_uns_bits((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x0l))))
, c_hw_fix_32_0_uns_undef((HWOffsetFix<32,0,UNSIGNED>()))
, c_hw_fix_1_0_uns_bits_1((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x1l))))
, c_hw_fix_49_0_uns_bits((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x1000000000000l))))
, c_hw_fix_49_0_uns_bits_1((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000000l))))
, c_hw_fix_49_0_uns_bits_2((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000001l))))
, c_hw_fix_48_0_uns_undef((HWOffsetFix<48,0,UNSIGNED>()))
{
  { // Node ID: 17 (NodeInputMappedReg)
    registerMappedRegister("io_strout_force_disabled", Data(1));
  }
  { // Node ID: 0 (NodeInputMappedReg)
    registerMappedRegister("io_str_force_disabled", Data(1));
  }
  { // Node ID: 2 (NodeInput)
     m_str =  registerInput("str",0,5);
  }
  { // Node ID: 56 (NodeInputMappedReg)
    registerMappedRegister("delay_eq_0", Data(4));
  }
  { // Node ID: 57 (NodeInputMappedReg)
    registerMappedRegister("delay_eq_1", Data(7));
  }
  { // Node ID: 58 (NodeInputMappedReg)
    registerMappedRegister("delay_eq_2", Data(7));
  }
  { // Node ID: 23 (NodeOutput)
    m_strout = registerOutput("strout",0 );
  }
  { // Node ID: 27 (NodeConstantRawBits)
    id27out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 55 (NodeConstantRawBits)
    id55out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 25 (NodeConstantRawBits)
    id25out_value = (c_hw_fix_49_0_uns_bits);
  }
  { // Node ID: 28 (NodeOutputMappedReg)
    registerMappedRegister("current_run_cycle_count", Data(48));
  }
  { // Node ID: 30 (NodeInputMappedReg)
    registerMappedRegister("run_cycle_count", Data(48));
  }
  { // Node ID: 59 (NodeInputMappedReg)
    registerMappedRegister("ce_delay_eq_0", Data(7));
  }
  { // Node ID: 60 (NodeInputMappedReg)
    registerMappedRegister("ce_delay_eq_1", Data(7));
  }
  { // Node ID: 61 (NodeInputMappedReg)
    registerMappedRegister("ce_delay_eq_2", Data(7));
  }
  { // Node ID: 62 (NodeInputMappedReg)
    registerMappedRegister("ce_delay_eq_3", Data(7));
  }
  { // Node ID: 63 (NodeInputMappedReg)
    registerMappedRegister("ce_delay_eq_4", Data(7));
  }
  { // Node ID: 64 (NodeInputMappedReg)
    registerMappedRegister("ce_delay_eq_5", Data(7));
  }
  { // Node ID: 65 (NodeInputMappedReg)
    registerMappedRegister("ce_delay_eq_6", Data(7));
  }
  { // Node ID: 66 (NodeInputMappedReg)
    registerMappedRegister("ce_delay_eq_7", Data(7));
  }
}

void CpuStreamKernel::resetComputation() {
  resetComputationAfterFlush();
}

void CpuStreamKernel::resetComputationAfterFlush() {
  { // Node ID: 17 (NodeInputMappedReg)
    id17out_io_strout_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_strout_force_disabled");
  }
  { // Node ID: 0 (NodeInputMappedReg)
    id0out_io_str_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_str_force_disabled");
  }
  { // Node ID: 2 (NodeInput)

    (id2st_read_next_cycle) = (c_hw_fix_1_0_uns_bits);
    (id2st_last_read_value) = (c_hw_fix_32_0_uns_undef);
  }
  { // Node ID: 56 (NodeInputMappedReg)
    id56out_delay_eq_0 = getMappedRegValue<HWOffsetFix<4,0,UNSIGNED> >("delay_eq_0");
  }
  { // Node ID: 40 (NodeFIFO)
    const HWOffsetFix<4,0,UNSIGNED> &id40in_current_depth0 = id56out_delay_eq_0;

    (id40st_store_idx) = (0l);
    (id40st_store_idx_max) = (((1l)+(id40in_current_depth0.getValueAsLong()))-(1l));
  }
  { // Node ID: 57 (NodeInputMappedReg)
    id57out_delay_eq_1 = getMappedRegValue<HWOffsetFix<7,0,UNSIGNED> >("delay_eq_1");
  }
  { // Node ID: 46 (NodeFIFO)
    const HWOffsetFix<7,0,UNSIGNED> &id46in_current_depth0 = id57out_delay_eq_1;

    (id46st_store_idx) = (0l);
    (id46st_store_idx_max) = (((3l)+(id46in_current_depth0.getValueAsLong()))-(1l));
  }
  { // Node ID: 45 (NodeFIFO)
    const HWOffsetFix<4,0,UNSIGNED> &id45in_current_depth0 = id56out_delay_eq_0;

    (id45st_store_idx) = (0l);
    (id45st_store_idx_max) = (((1l)+(id45in_current_depth0.getValueAsLong()))-(1l));
  }
  { // Node ID: 52 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id52out_output[i] = (c_hw_fix_32_0_uns_undef);
    }
  }
  { // Node ID: 54 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id54out_output[i] = (c_hw_fix_32_0_uns_undef);
    }
  }
  { // Node ID: 49 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id49out_output[i] = (c_hw_fix_32_0_uns_undef);
    }
  }
  { // Node ID: 41 (NodeFIFO)
    const HWOffsetFix<4,0,UNSIGNED> &id41in_current_depth0 = id56out_delay_eq_0;

    (id41st_store_idx) = (0l);
    (id41st_store_idx_max) = (((1l)+(id41in_current_depth0.getValueAsLong()))-(1l));
  }
  { // Node ID: 51 (NodeFIFO)

    for(int i=0; i<6; i++)
    {
      id51out_output[i] = (c_hw_fix_32_0_uns_undef);
    }
  }
  { // Node ID: 58 (NodeInputMappedReg)
    id58out_delay_eq_2 = getMappedRegValue<HWOffsetFix<7,0,UNSIGNED> >("delay_eq_2");
  }
  { // Node ID: 47 (NodeFIFO)
    const HWOffsetFix<7,0,UNSIGNED> &id47in_current_depth0 = id58out_delay_eq_2;

    (id47st_store_idx) = (0l);
    (id47st_store_idx_max) = (((3l)+(id47in_current_depth0.getValueAsLong()))-(1l));
  }
  { // Node ID: 26 (NodeCounterV1)

    (id26st_count) = (c_hw_fix_49_0_uns_bits_1);
  }
  { // Node ID: 53 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id53out_output[i] = (c_hw_fix_48_0_uns_undef);
    }
  }
  { // Node ID: 30 (NodeInputMappedReg)
    id30out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
  { // Node ID: 59 (NodeInputMappedReg)
    id59out_ce_delay_eq_0 = getMappedRegValue<HWOffsetFix<7,0,UNSIGNED> >("ce_delay_eq_0");
  }
  { // Node ID: 60 (NodeInputMappedReg)
    id60out_ce_delay_eq_1 = getMappedRegValue<HWOffsetFix<7,0,UNSIGNED> >("ce_delay_eq_1");
  }
  { // Node ID: 61 (NodeInputMappedReg)
    id61out_ce_delay_eq_2 = getMappedRegValue<HWOffsetFix<7,0,UNSIGNED> >("ce_delay_eq_2");
  }
  { // Node ID: 62 (NodeInputMappedReg)
    id62out_ce_delay_eq_3 = getMappedRegValue<HWOffsetFix<7,0,UNSIGNED> >("ce_delay_eq_3");
  }
  { // Node ID: 63 (NodeInputMappedReg)
    id63out_ce_delay_eq_4 = getMappedRegValue<HWOffsetFix<7,0,UNSIGNED> >("ce_delay_eq_4");
  }
  { // Node ID: 64 (NodeInputMappedReg)
    id64out_ce_delay_eq_5 = getMappedRegValue<HWOffsetFix<7,0,UNSIGNED> >("ce_delay_eq_5");
  }
  { // Node ID: 65 (NodeInputMappedReg)
    id65out_ce_delay_eq_6 = getMappedRegValue<HWOffsetFix<7,0,UNSIGNED> >("ce_delay_eq_6");
  }
  { // Node ID: 66 (NodeInputMappedReg)
    id66out_ce_delay_eq_7 = getMappedRegValue<HWOffsetFix<7,0,UNSIGNED> >("ce_delay_eq_7");
  }
}

void CpuStreamKernel::updateState() {
  { // Node ID: 17 (NodeInputMappedReg)
    id17out_io_strout_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_strout_force_disabled");
  }
  { // Node ID: 0 (NodeInputMappedReg)
    id0out_io_str_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_str_force_disabled");
  }
  { // Node ID: 56 (NodeInputMappedReg)
    id56out_delay_eq_0 = getMappedRegValue<HWOffsetFix<4,0,UNSIGNED> >("delay_eq_0");
  }
  { // Node ID: 57 (NodeInputMappedReg)
    id57out_delay_eq_1 = getMappedRegValue<HWOffsetFix<7,0,UNSIGNED> >("delay_eq_1");
  }
  { // Node ID: 58 (NodeInputMappedReg)
    id58out_delay_eq_2 = getMappedRegValue<HWOffsetFix<7,0,UNSIGNED> >("delay_eq_2");
  }
  { // Node ID: 30 (NodeInputMappedReg)
    id30out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
  { // Node ID: 59 (NodeInputMappedReg)
    id59out_ce_delay_eq_0 = getMappedRegValue<HWOffsetFix<7,0,UNSIGNED> >("ce_delay_eq_0");
  }
  { // Node ID: 60 (NodeInputMappedReg)
    id60out_ce_delay_eq_1 = getMappedRegValue<HWOffsetFix<7,0,UNSIGNED> >("ce_delay_eq_1");
  }
  { // Node ID: 61 (NodeInputMappedReg)
    id61out_ce_delay_eq_2 = getMappedRegValue<HWOffsetFix<7,0,UNSIGNED> >("ce_delay_eq_2");
  }
  { // Node ID: 62 (NodeInputMappedReg)
    id62out_ce_delay_eq_3 = getMappedRegValue<HWOffsetFix<7,0,UNSIGNED> >("ce_delay_eq_3");
  }
  { // Node ID: 63 (NodeInputMappedReg)
    id63out_ce_delay_eq_4 = getMappedRegValue<HWOffsetFix<7,0,UNSIGNED> >("ce_delay_eq_4");
  }
  { // Node ID: 64 (NodeInputMappedReg)
    id64out_ce_delay_eq_5 = getMappedRegValue<HWOffsetFix<7,0,UNSIGNED> >("ce_delay_eq_5");
  }
  { // Node ID: 65 (NodeInputMappedReg)
    id65out_ce_delay_eq_6 = getMappedRegValue<HWOffsetFix<7,0,UNSIGNED> >("ce_delay_eq_6");
  }
  { // Node ID: 66 (NodeInputMappedReg)
    id66out_ce_delay_eq_7 = getMappedRegValue<HWOffsetFix<7,0,UNSIGNED> >("ce_delay_eq_7");
  }
}

void CpuStreamKernel::preExecute() {
  { // Node ID: 2 (NodeInput)
    if(((needsToReadInput(m_str))&(((getFlushLevel())<(((id59out_ce_delay_eq_0).getValueAsLong())+(5)))|(!(isFlushingActive()))))) {
      (id2st_last_read_value) = (readInput<HWOffsetFix<32,0,UNSIGNED> >(m_str));
    }
    id2out_data = (id2st_last_read_value);
  }
}

void CpuStreamKernel::runComputationCycle() {
  if (m_mappedElementsChanged) {
    m_mappedElementsChanged = false;
    updateState();
    std::cout << "CpuStreamKernel: Mapped Elements Changed: Reloaded" << std::endl;
  }
  preExecute();
  execute0();
}

int CpuStreamKernel::getFlushLevelStart() {
  return (((id66out_ce_delay_eq_7).getValueAsLong())+(3l));
}

}
