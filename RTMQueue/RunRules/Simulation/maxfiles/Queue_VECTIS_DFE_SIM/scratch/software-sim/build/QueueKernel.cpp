#include "stdsimheader.h"
#include "QueueKernel.h"

namespace maxcompilersim {

QueueKernel::QueueKernel(const std::string &instance_name) : 
  KernelManagerBlockSync(instance_name, 15, 2, 0, 0, "",1)
, c_hw_fix_1_0_uns_bits((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x1l))))
, c_hw_fix_1_0_uns_bits_1((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x0l))))
, c_hw_fix_32_0_sgn_undef((HWOffsetFix<32,0,TWOSCOMPLEMENT>()))
, c_hw_fix_49_0_uns_bits((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x1000000000000l))))
, c_hw_fix_49_0_uns_bits_1((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000000l))))
, c_hw_fix_49_0_uns_bits_2((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000001l))))
, c_hw_fix_48_0_uns_undef((HWOffsetFix<48,0,UNSIGNED>()))
{
  { // Node ID: 22 (NodeConstantRawBits)
    id22out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 0 (NodeInputMappedReg)
    registerMappedRegister("io_controller_force_disabled", Data(1));
  }
  { // Node ID: 2 (NodeInput)
     m_controller =  registerInput("controller",0,5);
  }
  { // Node ID: 4 (NodeInputMappedReg)
    registerMappedRegister("io_x_force_disabled", Data(1));
  }
  { // Node ID: 10 (NodeInput)
     m_x =  registerInput("x",1,5);
  }
  { // Node ID: 12 (NodeInputMappedReg)
    registerMappedRegister("io_y_force_disabled", Data(1));
  }
  { // Node ID: 18 (NodeInput)
     m_y =  registerInput("y",2,5);
  }
  { // Node ID: 19 (NodeInputMappedReg)
    registerMappedRegister("a", Data(32));
  }
  { // Node ID: 25 (NodeInputMappedReg)
    registerMappedRegister("io_s_force_disabled", Data(1));
  }
  { // Node ID: 31 (NodeOutput)
    m_s = registerOutput("s",0 );
  }
  { // Node ID: 35 (NodeConstantRawBits)
    id35out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 46 (NodeConstantRawBits)
    id46out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 33 (NodeConstantRawBits)
    id33out_value = (c_hw_fix_49_0_uns_bits);
  }
  { // Node ID: 36 (NodeOutputMappedReg)
    registerMappedRegister("current_run_cycle_count", Data(48));
  }
  { // Node ID: 38 (NodeInputMappedReg)
    registerMappedRegister("run_cycle_count", Data(48));
  }
}

void QueueKernel::resetComputation() {
  resetComputationAfterFlush();
}

void QueueKernel::resetComputationAfterFlush() {
  { // Node ID: 0 (NodeInputMappedReg)
    id0out_io_controller_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_controller_force_disabled");
  }
  { // Node ID: 2 (NodeInput)

    (id2st_read_next_cycle) = (c_hw_fix_1_0_uns_bits_1);
    (id2st_last_read_value) = (c_hw_fix_32_0_sgn_undef);
  }
  { // Node ID: 4 (NodeInputMappedReg)
    id4out_io_x_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_x_force_disabled");
  }
  { // Node ID: 10 (NodeInput)

    (id10st_read_next_cycle) = (c_hw_fix_1_0_uns_bits_1);
    (id10st_last_read_value) = (c_hw_fix_32_0_sgn_undef);
  }
  { // Node ID: 42 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id42out_output[i] = (c_hw_fix_32_0_sgn_undef);
    }
  }
  { // Node ID: 12 (NodeInputMappedReg)
    id12out_io_y_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_y_force_disabled");
  }
  { // Node ID: 18 (NodeInput)

    (id18st_read_next_cycle) = (c_hw_fix_1_0_uns_bits_1);
    (id18st_last_read_value) = (c_hw_fix_32_0_sgn_undef);
  }
  { // Node ID: 43 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id43out_output[i] = (c_hw_fix_32_0_sgn_undef);
    }
  }
  { // Node ID: 44 (NodeFIFO)

    for(int i=0; i<7; i++)
    {
      id44out_output[i] = (c_hw_fix_32_0_sgn_undef);
    }
  }
  { // Node ID: 19 (NodeInputMappedReg)
    id19out_a = getMappedRegValue<HWOffsetFix<32,0,TWOSCOMPLEMENT> >("a");
  }
  { // Node ID: 25 (NodeInputMappedReg)
    id25out_io_s_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_s_force_disabled");
  }
  { // Node ID: 34 (NodeCounterV1)

    (id34st_count) = (c_hw_fix_49_0_uns_bits_1);
  }
  { // Node ID: 45 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id45out_output[i] = (c_hw_fix_48_0_uns_undef);
    }
  }
  { // Node ID: 38 (NodeInputMappedReg)
    id38out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
}

void QueueKernel::updateState() {
  { // Node ID: 0 (NodeInputMappedReg)
    id0out_io_controller_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_controller_force_disabled");
  }
  { // Node ID: 4 (NodeInputMappedReg)
    id4out_io_x_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_x_force_disabled");
  }
  { // Node ID: 12 (NodeInputMappedReg)
    id12out_io_y_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_y_force_disabled");
  }
  { // Node ID: 19 (NodeInputMappedReg)
    id19out_a = getMappedRegValue<HWOffsetFix<32,0,TWOSCOMPLEMENT> >("a");
  }
  { // Node ID: 25 (NodeInputMappedReg)
    id25out_io_s_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_s_force_disabled");
  }
  { // Node ID: 38 (NodeInputMappedReg)
    id38out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
}

void QueueKernel::preExecute() {
  { // Node ID: 2 (NodeInput)
    if(((needsToReadInput(m_controller))&(((getFlushLevel())<((4l)+(5)))|(!(isFlushingActive()))))) {
      (id2st_last_read_value) = (readInput<HWOffsetFix<32,0,TWOSCOMPLEMENT> >(m_controller));
    }
    id2out_data = (id2st_last_read_value);
  }
  { // Node ID: 10 (NodeInput)
    if(((needsToReadInput(m_x))&(((getFlushLevel())<((9l)+(5)))|(!(isFlushingActive()))))) {
      (id10st_last_read_value) = (readInput<HWOffsetFix<32,0,TWOSCOMPLEMENT> >(m_x));
    }
    id10out_data = (id10st_last_read_value);
  }
  { // Node ID: 18 (NodeInput)
    if(((needsToReadInput(m_y))&(((getFlushLevel())<((9l)+(5)))|(!(isFlushingActive()))))) {
      (id18st_last_read_value) = (readInput<HWOffsetFix<32,0,TWOSCOMPLEMENT> >(m_y));
    }
    id18out_data = (id18st_last_read_value);
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
