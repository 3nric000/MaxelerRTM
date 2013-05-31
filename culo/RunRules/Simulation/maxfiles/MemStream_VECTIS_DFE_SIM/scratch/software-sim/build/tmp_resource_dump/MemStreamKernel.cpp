#include "stdsimheader.h"
#include "MemStreamKernel.h"

namespace maxcompilersim {

MemStreamKernel::MemStreamKernel(const std::string &instance_name) : 
  KernelManagerBlockSync(instance_name, 10, 2, 0, 0, "",1)
, c_hw_fix_1_0_uns_bits((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x0l))))
, c_hw_fix_32_0_sgn_undef((HWOffsetFix<32,0,TWOSCOMPLEMENT>()))
, c_hw_fix_1_0_uns_bits_1((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x1l))))
, c_hw_fix_49_0_uns_bits((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x1000000000000l))))
, c_hw_fix_49_0_uns_bits_1((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000000l))))
, c_hw_fix_49_0_uns_bits_2((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000001l))))
, c_hw_fix_48_0_uns_undef((HWOffsetFix<48,0,UNSIGNED>()))
{
  { // Node ID: 10 (NodeInputMappedReg)
    registerMappedRegister("io_s_force_disabled", Data(1));
  }
  { // Node ID: 0 (NodeInputMappedReg)
    registerMappedRegister("io_x_force_disabled", Data(1));
  }
  { // Node ID: 2 (NodeInput)
     m_x =  registerInput("x",0,5);
  }
  { // Node ID: 3 (NodeInputMappedReg)
    registerMappedRegister("io_y_force_disabled", Data(1));
  }
  { // Node ID: 5 (NodeInput)
     m_y =  registerInput("y",1,5);
  }
  { // Node ID: 6 (NodeInputMappedReg)
    registerMappedRegister("a", Data(32));
  }
  { // Node ID: 16 (NodeOutput)
    m_s = registerOutput("s",0 );
  }
  { // Node ID: 20 (NodeConstantRawBits)
    id20out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 28 (NodeConstantRawBits)
    id28out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 18 (NodeConstantRawBits)
    id18out_value = (c_hw_fix_49_0_uns_bits);
  }
  { // Node ID: 21 (NodeOutputMappedReg)
    registerMappedRegister("current_run_cycle_count", Data(48));
  }
  { // Node ID: 23 (NodeInputMappedReg)
    registerMappedRegister("run_cycle_count", Data(48));
  }
}

void MemStreamKernel::resetComputation() {
  resetComputationAfterFlush();
}

void MemStreamKernel::resetComputationAfterFlush() {
  { // Node ID: 10 (NodeInputMappedReg)
    id10out_io_s_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_s_force_disabled");
  }
  { // Node ID: 0 (NodeInputMappedReg)
    id0out_io_x_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_x_force_disabled");
  }
  { // Node ID: 2 (NodeInput)

    (id2st_read_next_cycle) = (c_hw_fix_1_0_uns_bits);
    (id2st_last_read_value) = (c_hw_fix_32_0_sgn_undef);
  }
  { // Node ID: 3 (NodeInputMappedReg)
    id3out_io_y_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_y_force_disabled");
  }
  { // Node ID: 5 (NodeInput)

    (id5st_read_next_cycle) = (c_hw_fix_1_0_uns_bits);
    (id5st_last_read_value) = (c_hw_fix_32_0_sgn_undef);
  }
  { // Node ID: 6 (NodeInputMappedReg)
    id6out_a = getMappedRegValue<HWOffsetFix<32,0,TWOSCOMPLEMENT> >("a");
  }
  { // Node ID: 19 (NodeCounterV1)

    (id19st_count) = (c_hw_fix_49_0_uns_bits_1);
  }
  { // Node ID: 27 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id27out_output[i] = (c_hw_fix_48_0_uns_undef);
    }
  }
  { // Node ID: 23 (NodeInputMappedReg)
    id23out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
}

void MemStreamKernel::updateState() {
  { // Node ID: 10 (NodeInputMappedReg)
    id10out_io_s_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_s_force_disabled");
  }
  { // Node ID: 0 (NodeInputMappedReg)
    id0out_io_x_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_x_force_disabled");
  }
  { // Node ID: 3 (NodeInputMappedReg)
    id3out_io_y_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_y_force_disabled");
  }
  { // Node ID: 6 (NodeInputMappedReg)
    id6out_a = getMappedRegValue<HWOffsetFix<32,0,TWOSCOMPLEMENT> >("a");
  }
  { // Node ID: 23 (NodeInputMappedReg)
    id23out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
}

void MemStreamKernel::preExecute() {
  { // Node ID: 2 (NodeInput)
    if(((needsToReadInput(m_x))&(((getFlushLevel())<((4l)+(5)))|(!(isFlushingActive()))))) {
      (id2st_last_read_value) = (readInput<HWOffsetFix<32,0,TWOSCOMPLEMENT> >(m_x));
    }
    id2out_data = (id2st_last_read_value);
  }
  { // Node ID: 5 (NodeInput)
    if(((needsToReadInput(m_y))&(((getFlushLevel())<((4l)+(5)))|(!(isFlushingActive()))))) {
      (id5st_last_read_value) = (readInput<HWOffsetFix<32,0,TWOSCOMPLEMENT> >(m_y));
    }
    id5out_data = (id5st_last_read_value);
  }
}

void MemStreamKernel::runComputationCycle() {
  if (m_mappedElementsChanged) {
    m_mappedElementsChanged = false;
    updateState();
    std::cout << "MemStreamKernel: Mapped Elements Changed: Reloaded" << std::endl;
  }
  preExecute();
  execute0();
}

int MemStreamKernel::getFlushLevelStart() {
  return ((1l)+(3l));
}

}
