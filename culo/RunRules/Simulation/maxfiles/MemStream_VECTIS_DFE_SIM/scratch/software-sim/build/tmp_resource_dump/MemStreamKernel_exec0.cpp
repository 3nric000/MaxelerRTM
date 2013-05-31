#include "stdsimheader.h"
//#define BOOST_NO_STD_LOCALE
//#include <boost/format.hpp>

//#include "MemStreamKernel.h"

namespace maxcompilersim {

void MemStreamKernel::execute0() {
  { // Node ID: 10 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id11out_result;

  { // Node ID: 11 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id11in_a = id10out_io_s_force_disabled;

    id11out_result = (not_fixed(id11in_a));
  }
  HWRawBits<1> id14out_output;

  { // Node ID: 14 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id14in_input = id11out_result;

    id14out_output = (cast_fixed2bits(id14in_input));
  }
  HWOffsetFix<1,0,UNSIGNED> id15out_output;

  { // Node ID: 15 (NodeReinterpret)
    const HWRawBits<1> &id15in_input = id14out_output;

    id15out_output = (cast_bits2fixed<1,0,UNSIGNED>(id15in_input));
  }
  { // Node ID: 0 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id1out_result;

  { // Node ID: 1 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id1in_a = id0out_io_x_force_disabled;

    id1out_result = (not_fixed(id1in_a));
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 2 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id2in_enable = id1out_result;

    (id2st_read_next_cycle) = ((id2in_enable.getValueAsBool())&(!(((getFlushLevel())>=(4l))&(isFlushingActive()))));
    queueReadRequest(m_x, id2st_read_next_cycle.getValueAsBool());
  }
  { // Node ID: 3 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id4out_result;

  { // Node ID: 4 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id4in_a = id3out_io_y_force_disabled;

    id4out_result = (not_fixed(id4in_a));
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 5 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id5in_enable = id4out_result;

    (id5st_read_next_cycle) = ((id5in_enable.getValueAsBool())&(!(((getFlushLevel())>=(4l))&(isFlushingActive()))));
    queueReadRequest(m_y, id5st_read_next_cycle.getValueAsBool());
  }
  { // Node ID: 6 (NodeInputMappedReg)
  }
  { // Node ID: 26 (NodeTriAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id26in_a = id2out_data;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id26in_b = id5out_data;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id26in_c = id6out_a;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id26x_1;

    (id26x_1) = (add_fixed<32,0,TWOSCOMPLEMENT,TRUNCATE>((add_fixed<32,0,TWOSCOMPLEMENT,TRUNCATE>(id26in_a,id26in_b)),id26in_c));
    id26out_result[(getCycle()+1)%2] = (id26x_1);
  }
  if ( (getFillLevel() >= (10l)) && (getFlushLevel() < (10l)|| !isFlushingActive() ))
  { // Node ID: 16 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id16in_output_control = id15out_output;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id16in_data = id26out_result[getCycle()%2];

    bool id16x_1;

    (id16x_1) = ((id16in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(10l))&(isFlushingActive()))));
    if((id16x_1)) {
      writeOutput(m_s, id16in_data);
    }
  }
  { // Node ID: 20 (NodeConstantRawBits)
  }
  { // Node ID: 28 (NodeConstantRawBits)
  }
  { // Node ID: 18 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 19 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id19in_enable = id28out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id19in_max = id18out_value;

    HWOffsetFix<49,0,UNSIGNED> id19x_1;
    HWOffsetFix<1,0,UNSIGNED> id19x_2;
    HWOffsetFix<1,0,UNSIGNED> id19x_3;
    HWOffsetFix<49,0,UNSIGNED> id19x_4t_1e_1;

    id19out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id19st_count)));
    (id19x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id19st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id19x_2) = (gte_fixed((id19x_1),id19in_max));
    (id19x_3) = (and_fixed((id19x_2),id19in_enable));
    id19out_wrap = (id19x_3);
    if((id19in_enable.getValueAsBool())) {
      if(((id19x_3).getValueAsBool())) {
        (id19st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id19x_4t_1e_1) = (id19x_1);
        (id19st_count) = (id19x_4t_1e_1);
      }
    }
    else {
    }
  }
  { // Node ID: 27 (NodeFIFO)
    const HWOffsetFix<48,0,UNSIGNED> &id27in_input = id19out_count;

    id27out_output[(getCycle()+4)%5] = id27in_input;
  }
  if ( (getFillLevel() >= (4l)) && (getFlushLevel() < (4l)|| !isFlushingActive() ))
  { // Node ID: 21 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id21in_load = id20out_value;
    const HWOffsetFix<48,0,UNSIGNED> &id21in_data = id27out_output[getCycle()%5];

    bool id21x_1;

    (id21x_1) = ((id21in_load.getValueAsBool())&(!(((getFlushLevel())>=(4l))&(isFlushingActive()))));
    if((id21x_1)) {
      setMappedRegValue("current_run_cycle_count", id21in_data);
    }
  }
  { // Node ID: 23 (NodeInputMappedReg)
  }
  { // Node ID: 24 (NodeEq)
    const HWOffsetFix<48,0,UNSIGNED> &id24in_a = id19out_count;
    const HWOffsetFix<48,0,UNSIGNED> &id24in_b = id23out_run_cycle_count;

    id24out_result[(getCycle()+1)%2] = (eq_fixed(id24in_a,id24in_b));
  }
  if ( (getFillLevel() >= (1l)))
  { // Node ID: 22 (NodeFlush)
    const HWOffsetFix<1,0,UNSIGNED> &id22in_start = id24out_result[getCycle()%2];

    if((id22in_start.getValueAsBool())) {
      startFlushing();
    }
  }
};

};
