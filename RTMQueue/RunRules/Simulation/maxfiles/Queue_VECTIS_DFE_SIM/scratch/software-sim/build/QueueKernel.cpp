#include "stdsimheader.h"
#include "QueueKernel.h"

namespace maxcompilersim {

QueueKernel::QueueKernel(const std::string &instance_name) : 
  KernelManagerBlockSync(instance_name, 15, 2, 0, 0, "",1)
, c_hw_fix_1_0_uns_bits((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x1l))))
, c_hw_fix_1_0_uns_bits_1((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x0l))))
, c_hw_fix_32_0_sgn_undef((HWOffsetFix<32,0,TWOSCOMPLEMENT>()))
, c_hw_fix_33_0_uns_bits((HWOffsetFix<33,0,UNSIGNED>(varint_u<33>(0x100000000l))))
, c_hw_fix_33_0_uns_bits_1((HWOffsetFix<33,0,UNSIGNED>(varint_u<33>(0x000000000l))))
, c_hw_fix_33_0_uns_bits_2((HWOffsetFix<33,0,UNSIGNED>(varint_u<33>(0x000000001l))))
, c_hw_fix_49_0_uns_bits((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x1000000000000l))))
, c_hw_fix_49_0_uns_bits_1((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000000l))))
, c_hw_fix_49_0_uns_bits_2((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000001l))))
, c_hw_fix_48_0_uns_undef((HWOffsetFix<48,0,UNSIGNED>()))
{
  { // Node ID: 20 (NodeConstantRawBits)
    id20out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 3 (NodeInputMappedReg)
    registerMappedRegister("io_controller_force_disabled", Data(1));
  }
  { // Node ID: 5 (NodeInput)
     m_controller =  registerInput("controller",0,5);
  }
  { // Node ID: 7 (NodeInputMappedReg)
    registerMappedRegister("io_x_force_disabled", Data(1));
  }
  { // Node ID: 13 (NodeInput)
     m_x =  registerInput("x",1,5);
  }
  { // Node ID: 14 (NodeInputMappedReg)
    registerMappedRegister("io_y_force_disabled", Data(1));
  }
  { // Node ID: 16 (NodeInput)
     m_y =  registerInput("y",2,5);
  }
  { // Node ID: 17 (NodeInputMappedReg)
    registerMappedRegister("a", Data(32));
  }
  { // Node ID: 45 (NodeConstantRawBits)
    id45out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 1 (NodeConstantRawBits)
    id1out_value = (c_hw_fix_33_0_uns_bits);
  }
  { // Node ID: 23 (NodeInputMappedReg)
    registerMappedRegister("io_s_force_disabled", Data(1));
  }
  { // Node ID: 29 (NodeOutput)
    m_s = registerOutput("s",0 );
  }
  { // Node ID: 33 (NodeConstantRawBits)
    id33out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 44 (NodeConstantRawBits)
    id44out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 31 (NodeConstantRawBits)
    id31out_value = (c_hw_fix_49_0_uns_bits);
  }
  { // Node ID: 34 (NodeOutputMappedReg)
    registerMappedRegister("current_run_cycle_count", Data(48));
  }
  { // Node ID: 36 (NodeInputMappedReg)
    registerMappedRegister("run_cycle_count", Data(48));
  }
}

void QueueKernel::resetComputation() {
  resetComputationAfterFlush();
}

void QueueKernel::resetComputationAfterFlush() {
  { // Node ID: 3 (NodeInputMappedReg)
    id3out_io_controller_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_controller_force_disabled");
  }
  { // Node ID: 5 (NodeInput)

    (id5st_read_next_cycle) = (c_hw_fix_1_0_uns_bits_1);
    (id5st_last_read_value) = (c_hw_fix_32_0_sgn_undef);
  }
  { // Node ID: 7 (NodeInputMappedReg)
    id7out_io_x_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_x_force_disabled");
  }
  { // Node ID: 13 (NodeInput)

    (id13st_read_next_cycle) = (c_hw_fix_1_0_uns_bits_1);
    (id13st_last_read_value) = (c_hw_fix_32_0_sgn_undef);
  }
  { // Node ID: 39 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id39out_output[i] = (c_hw_fix_32_0_sgn_undef);
    }
  }
  { // Node ID: 14 (NodeInputMappedReg)
    id14out_io_y_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_y_force_disabled");
  }
  { // Node ID: 16 (NodeInput)

    (id16st_read_next_cycle) = (c_hw_fix_1_0_uns_bits_1);
    (id16st_last_read_value) = (c_hw_fix_32_0_sgn_undef);
  }
  { // Node ID: 40 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id40out_output[i] = (c_hw_fix_32_0_sgn_undef);
    }
  }
  { // Node ID: 41 (NodeFIFO)

    for(int i=0; i<7; i++)
    {
      id41out_output[i] = (c_hw_fix_32_0_sgn_undef);
    }
  }
  { // Node ID: 17 (NodeInputMappedReg)
    id17out_a = getMappedRegValue<HWOffsetFix<32,0,TWOSCOMPLEMENT> >("a");
  }
  { // Node ID: 2 (NodeCounterV1)

    (id2st_count) = (c_hw_fix_33_0_uns_bits_1);
  }
  { // Node ID: 23 (NodeInputMappedReg)
    id23out_io_s_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_s_force_disabled");
  }
  { // Node ID: 32 (NodeCounterV1)

    (id32st_count) = (c_hw_fix_49_0_uns_bits_1);
  }
  { // Node ID: 43 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id43out_output[i] = (c_hw_fix_48_0_uns_undef);
    }
  }
  { // Node ID: 36 (NodeInputMappedReg)
    id36out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
}

void QueueKernel::updateState() {
  { // Node ID: 3 (NodeInputMappedReg)
    id3out_io_controller_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_controller_force_disabled");
  }
  { // Node ID: 7 (NodeInputMappedReg)
    id7out_io_x_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_x_force_disabled");
  }
  { // Node ID: 14 (NodeInputMappedReg)
    id14out_io_y_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_y_force_disabled");
  }
  { // Node ID: 17 (NodeInputMappedReg)
    id17out_a = getMappedRegValue<HWOffsetFix<32,0,TWOSCOMPLEMENT> >("a");
  }
  { // Node ID: 23 (NodeInputMappedReg)
    id23out_io_s_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_s_force_disabled");
  }
  { // Node ID: 36 (NodeInputMappedReg)
    id36out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
}

void QueueKernel::preExecute() {
  { // Node ID: 5 (NodeInput)
    if(((needsToReadInput(m_controller))&(((getFlushLevel())<((4l)+(5)))|(!(isFlushingActive()))))) {
      (id5st_last_read_value) = (readInput<HWOffsetFix<32,0,TWOSCOMPLEMENT> >(m_controller));
    }
    id5out_data = (id5st_last_read_value);
  }
  { // Node ID: 13 (NodeInput)
    if(((needsToReadInput(m_x))&(((getFlushLevel())<((9l)+(5)))|(!(isFlushingActive()))))) {
      (id13st_last_read_value) = (readInput<HWOffsetFix<32,0,TWOSCOMPLEMENT> >(m_x));
    }
    id13out_data = (id13st_last_read_value);
  }
  { // Node ID: 16 (NodeInput)
    if(((needsToReadInput(m_y))&(((getFlushLevel())<((9l)+(5)))|(!(isFlushingActive()))))) {
      (id16st_last_read_value) = (readInput<HWOffsetFix<32,0,TWOSCOMPLEMENT> >(m_y));
    }
    id16out_data = (id16st_last_read_value);
  }
}

void QueueKernel::runComputationCycle() {
  if (m_mappedElementsChanged) {
    m_mappedElementsChanged = false;
    updateState();
    std::cout << "QueueKernel: Mapped Elements Changed: Reloaded" << std::endl;
  }
  preExecute();
  execute0();
}

int QueueKernel::getFlushLevelStart() {
  return ((1l)+(3l));
}

}
