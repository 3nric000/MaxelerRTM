#include "stdsimheader.h"
//#define BOOST_NO_STD_LOCALE
//#include <boost/format.hpp>

//#include "QueueKernel.h"

namespace maxcompilersim {

void QueueKernel::execute0() {
  { // Node ID: 22 (NodeConstantRawBits)
  }
  { // Node ID: 0 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id1out_result;

  { // Node ID: 1 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id1in_a = id0out_io_controller_force_disabled;

    id1out_result = (not_fixed(id1in_a));
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 2 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id2in_enable = id1out_result;

    (id2st_read_next_cycle) = ((id2in_enable.getValueAsBool())&(!(((getFlushLevel())>=(4l))&(isFlushingActive()))));
    queueReadRequest(m_controller, id2st_read_next_cycle.getValueAsBool());
  }
  HWOffsetFix<1,0,UNSIGNED> id3out_o;

  { // Node ID: 3 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id3in_i = id2out_data;

    id3out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id3in_i));
  }
  HWRawBits<1> id7out_output;

  { // Node ID: 7 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id7in_input = id3out_o;

    id7out_output = (cast_fixed2bits(id7in_input));
  }
  { // Node ID: 4 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id5out_result;

  { // Node ID: 5 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id5in_a = id4out_io_x_force_disabled;

    id5out_result = (not_fixed(id5in_a));
  }
  HWRawBits<1> id8out_output;

  { // Node ID: 8 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id8in_input = id5out_result;

    id8out_output = (cast_fixed2bits(id8in_input));
  }
  HWRawBits<1> id6out_result;

  { // Node ID: 6 (NodeAnd)
    const HWRawBits<1> &id6in_a = id7out_output;
    const HWRawBits<1> &id6in_b = id8out_output;

    HWRawBits<1> id6x_1;

    (id6x_1) = (and_bits(id6in_a,id6in_b));
    id6out_result = (id6x_1);
  }
  HWOffsetFix<1,0,UNSIGNED> id9out_output;

  { // Node ID: 9 (NodeReinterpret)
    const HWRawBits<1> &id9in_input = id6out_result;

    id9out_output = (cast_bits2fixed<1,0,UNSIGNED>(id9in_input));
  }
  if ( (getFillLevel() >= (9l)))
  { // Node ID: 10 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id10in_enable = id9out_output;

    (id10st_read_next_cycle) = ((id10in_enable.getValueAsBool())&(!(((getFlushLevel())>=(9l))&(isFlushingActive()))));
    queueReadRequest(m_x, id10st_read_next_cycle.getValueAsBool());
  }
  { // Node ID: 42 (NodeFIFO)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id42in_input = id10out_data;

    id42out_output[(getCycle()+1)%2] = id42in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id11out_o;

  { // Node ID: 11 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id11in_i = id2out_data;

    id11out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id11in_i));
  }
  HWRawBits<1> id15out_output;

  { // Node ID: 15 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id15in_input = id11out_o;

    id15out_output = (cast_fixed2bits(id15in_input));
  }
  { // Node ID: 12 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id13out_result;

  { // Node ID: 13 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id13in_a = id12out_io_y_force_disabled;

    id13out_result = (not_fixed(id13in_a));
  }
  HWRawBits<1> id16out_output;

  { // Node ID: 16 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id16in_input = id13out_result;

    id16out_output = (cast_fixed2bits(id16in_input));
  }
  HWRawBits<1> id14out_result;

  { // Node ID: 14 (NodeAnd)
    const HWRawBits<1> &id14in_a = id15out_output;
    const HWRawBits<1> &id14in_b = id16out_output;

    HWRawBits<1> id14x_1;

    (id14x_1) = (and_bits(id14in_a,id14in_b));
    id14out_result = (id14x_1);
  }
  HWOffsetFix<1,0,UNSIGNED> id17out_output;

  { // Node ID: 17 (NodeReinterpret)
    const HWRawBits<1> &id17in_input = id14out_result;

    id17out_output = (cast_bits2fixed<1,0,UNSIGNED>(id17in_input));
  }
  if ( (getFillLevel() >= (9l)))
  { // Node ID: 18 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id18in_enable = id17out_output;

    (id18st_read_next_cycle) = ((id18in_enable.getValueAsBool())&(!(((getFlushLevel())>=(9l))&(isFlushingActive()))));
    queueReadRequest(m_y, id18st_read_next_cycle.getValueAsBool());
  }
  { // Node ID: 43 (NodeFIFO)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id43in_input = id18out_data;

    id43out_output[(getCycle()+1)%2] = id43in_input;
  }
  { // Node ID: 44 (NodeFIFO)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id44in_input = id2out_data;

    id44out_output[(getCycle()+6)%7] = id44in_input;
  }
  { // Node ID: 19 (NodeInputMappedReg)
  }
  { // Node ID: 41 (NodeTriAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id41in_a = id10out_data;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id41in_b = id18out_data;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id41in_c = id19out_a;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id41x_1;

    (id41x_1) = (add_fixed<32,0,TWOSCOMPLEMENT,TRUNCATE>((add_fixed<32,0,TWOSCOMPLEMENT,TRUNCATE>(id41in_a,id41in_b)),id41in_c));
    id41out_result[(getCycle()+1)%2] = (id41x_1);
  }
  if ( (getFillLevel() >= (15l)) && (getFlushLevel() < (15l)|| !isFlushingActive() ))
  { // Node ID: 23 (NodePrintf)
    const HWOffsetFix<1,0,UNSIGNED> &id23in_condition = id22out_value;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id23in_arg0 = id42out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id23in_arg1 = id43out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id23in_arg2 = id44out_output[getCycle()%7];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id23in_arg3 = id19out_a;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id23in_arg4 = id41out_result[getCycle()%2];

    if((id23in_condition.getValueAsBool())) {
      const HWOffsetFix<32,0,TWOSCOMPLEMENT> &_format_arg_0 = id23in_arg0;
      const HWOffsetFix<32,0,TWOSCOMPLEMENT> &_format_arg_1 = id23in_arg1;
      const HWOffsetFix<32,0,TWOSCOMPLEMENT> &_format_arg_2 = id23in_arg2;
      const HWOffsetFix<32,0,TWOSCOMPLEMENT> &_format_arg_3 = id23in_arg3;
      const HWOffsetFix<32,0,TWOSCOMPLEMENT> &_format_arg_4 = id23in_arg4;
      simPrintf("", 23, format_string_QueueKernel_1("\nx=%d y=%d controller=%d a=%d sum=%d\n", _format_arg_0, _format_arg_1, _format_arg_2, _format_arg_3, _format_arg_4));
    }
    else {
      simPrintf("", 23, format_string_QueueKernel_2(""));
    }
  }
  { // Node ID: 25 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id26out_result;

  { // Node ID: 26 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id26in_a = id25out_io_s_force_disabled;

    id26out_result = (not_fixed(id26in_a));
  }
  HWRawBits<1> id29out_output;

  { // Node ID: 29 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id29in_input = id26out_result;

    id29out_output = (cast_fixed2bits(id29in_input));
  }
  HWOffsetFix<1,0,UNSIGNED> id30out_output;

  { // Node ID: 30 (NodeReinterpret)
    const HWRawBits<1> &id30in_input = id29out_output;

    id30out_output = (cast_bits2fixed<1,0,UNSIGNED>(id30in_input));
  }
  if ( (getFillLevel() >= (15l)) && (getFlushLevel() < (15l)|| !isFlushingActive() ))
  { // Node ID: 31 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id31in_output_control = id30out_output;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id31in_data = id41out_result[getCycle()%2];

    bool id31x_1;

    (id31x_1) = ((id31in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(15l))&(isFlushingActive()))));
    if((id31x_1)) {
      writeOutput(m_s, id31in_data);
    }
  }
  { // Node ID: 35 (NodeConstantRawBits)
  }
  { // Node ID: 46 (NodeConstantRawBits)
  }
  { // Node ID: 33 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 34 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id34in_enable = id46out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id34in_max = id33out_value;

    HWOffsetFix<49,0,UNSIGNED> id34x_1;
    HWOffsetFix<1,0,UNSIGNED> id34x_2;
    HWOffsetFix<1,0,UNSIGNED> id34x_3;
    HWOffsetFix<49,0,UNSIGNED> id34x_4t_1e_1;

    id34out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id34st_count)));
    (id34x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id34st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id34x_2) = (gte_fixed((id34x_1),id34in_max));
    (id34x_3) = (and_fixed((id34x_2),id34in_enable));
    id34out_wrap = (id34x_3);
    if((id34in_enable.getValueAsBool())) {
      if(((id34x_3).getValueAsBool())) {
        (id34st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id34x_4t_1e_1) = (id34x_1);
        (id34st_count) = (id34x_4t_1e_1);
      }
    }
    else {
    }
  }
  { // Node ID: 45 (NodeFIFO)
    const HWOffsetFix<48,0,UNSIGNED> &id45in_input = id34out_count;

    id45out_output[(getCycle()+4)%5] = id45in_input;
  }
  if ( (getFillLevel() >= (4l)) && (getFlushLevel() < (4l)|| !isFlushingActive() ))
  { // Node ID: 36 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id36in_load = id35out_value;
    const HWOffsetFix<48,0,UNSIGNED> &id36in_data = id45out_output[getCycle()%5];

    bool id36x_1;

    (id36x_1) = ((id36in_load.getValueAsBool())&(!(((getFlushLevel())>=(4l))&(isFlushingActive()))));
    if((id36x_1)) {
      setMappedRegValue("current_run_cycle_count", id36in_data);
    }
  }
  { // Node ID: 38 (NodeInputMappedReg)
  }
  { // Node ID: 39 (NodeEq)
    const HWOffsetFix<48,0,UNSIGNED> &id39in_a = id34out_count;
    const HWOffsetFix<48,0,UNSIGNED> &id39in_b = id38out_run_cycle_count;

    id39out_result[(getCycle()+1)%2] = (eq_fixed(id39in_a,id39in_b));
  }
  if ( (getFillLevel() >= (1l)))
  { // Node ID: 37 (NodeFlush)
    const HWOffsetFix<1,0,UNSIGNED> &id37in_start = id39out_result[getCycle()%2];

    if((id37in_start.getValueAsBool())) {
      startFlushing();
    }
  }
};

};
