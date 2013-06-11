#include "stdsimheader.h"
//#define BOOST_NO_STD_LOCALE
//#include <boost/format.hpp>

//#include "QueueKernel.h"

namespace maxcompilersim {

void QueueKernel::execute0() {
  { // Node ID: 20 (NodeConstantRawBits)
  }
  { // Node ID: 3 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id4out_result;

  { // Node ID: 4 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id4in_a = id3out_io_controller_force_disabled;

    id4out_result = (not_fixed(id4in_a));
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 5 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id5in_enable = id4out_result;

    (id5st_read_next_cycle) = ((id5in_enable.getValueAsBool())&(!(((getFlushLevel())>=(4l))&(isFlushingActive()))));
    queueReadRequest(m_controller, id5st_read_next_cycle.getValueAsBool());
  }
  HWOffsetFix<1,0,UNSIGNED> id6out_o;

  { // Node ID: 6 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id6in_i = id5out_data;

    id6out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id6in_i));
  }
  HWRawBits<1> id10out_output;

  { // Node ID: 10 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id10in_input = id6out_o;

    id10out_output = (cast_fixed2bits(id10in_input));
  }
  { // Node ID: 7 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id8out_result;

  { // Node ID: 8 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id8in_a = id7out_io_x_force_disabled;

    id8out_result = (not_fixed(id8in_a));
  }
  HWRawBits<1> id11out_output;

  { // Node ID: 11 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id11in_input = id8out_result;

    id11out_output = (cast_fixed2bits(id11in_input));
  }
  HWRawBits<1> id9out_result;

  { // Node ID: 9 (NodeAnd)
    const HWRawBits<1> &id9in_a = id10out_output;
    const HWRawBits<1> &id9in_b = id11out_output;

    HWRawBits<1> id9x_1;

    (id9x_1) = (and_bits(id9in_a,id9in_b));
    id9out_result = (id9x_1);
  }
  HWOffsetFix<1,0,UNSIGNED> id12out_output;

  { // Node ID: 12 (NodeReinterpret)
    const HWRawBits<1> &id12in_input = id9out_result;

    id12out_output = (cast_bits2fixed<1,0,UNSIGNED>(id12in_input));
  }
  if ( (getFillLevel() >= (9l)))
  { // Node ID: 13 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id13in_enable = id12out_output;

    (id13st_read_next_cycle) = ((id13in_enable.getValueAsBool())&(!(((getFlushLevel())>=(9l))&(isFlushingActive()))));
    queueReadRequest(m_x, id13st_read_next_cycle.getValueAsBool());
  }
  { // Node ID: 39 (NodeFIFO)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id39in_input = id13out_data;

    id39out_output[(getCycle()+1)%2] = id39in_input;
  }
  { // Node ID: 14 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id15out_result;

  { // Node ID: 15 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id15in_a = id14out_io_y_force_disabled;

    id15out_result = (not_fixed(id15in_a));
  }
  if ( (getFillLevel() >= (9l)))
  { // Node ID: 16 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id16in_enable = id15out_result;

    (id16st_read_next_cycle) = ((id16in_enable.getValueAsBool())&(!(((getFlushLevel())>=(9l))&(isFlushingActive()))));
    queueReadRequest(m_y, id16st_read_next_cycle.getValueAsBool());
  }
  { // Node ID: 40 (NodeFIFO)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id40in_input = id16out_data;

    id40out_output[(getCycle()+1)%2] = id40in_input;
  }
  { // Node ID: 41 (NodeFIFO)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id41in_input = id5out_data;

    id41out_output[(getCycle()+6)%7] = id41in_input;
  }
  { // Node ID: 17 (NodeInputMappedReg)
  }
  { // Node ID: 38 (NodeTriAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id38in_a = id13out_data;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id38in_b = id16out_data;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id38in_c = id17out_a;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id38x_1;

    (id38x_1) = (add_fixed<32,0,TWOSCOMPLEMENT,TRUNCATE>((add_fixed<32,0,TWOSCOMPLEMENT,TRUNCATE>(id38in_a,id38in_b)),id38in_c));
    id38out_result[(getCycle()+1)%2] = (id38x_1);
  }
  { // Node ID: 45 (NodeConstantRawBits)
  }
  { // Node ID: 1 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (15l)))
  { // Node ID: 2 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id2in_enable = id45out_value;
    const HWOffsetFix<33,0,UNSIGNED> &id2in_max = id1out_value;

    HWOffsetFix<33,0,UNSIGNED> id2x_1;
    HWOffsetFix<1,0,UNSIGNED> id2x_2;
    HWOffsetFix<1,0,UNSIGNED> id2x_3;
    HWOffsetFix<33,0,UNSIGNED> id2x_4t_1e_1;

    id2out_count = (cast_fixed2fixed<32,0,UNSIGNED,TRUNCATE>((id2st_count)));
    (id2x_1) = (add_fixed<33,0,UNSIGNED,TRUNCATE>((id2st_count),(c_hw_fix_33_0_uns_bits_2)));
    (id2x_2) = (gte_fixed((id2x_1),id2in_max));
    (id2x_3) = (and_fixed((id2x_2),id2in_enable));
    id2out_wrap = (id2x_3);
    if((id2in_enable.getValueAsBool())) {
      if(((id2x_3).getValueAsBool())) {
        (id2st_count) = (c_hw_fix_33_0_uns_bits_1);
      }
      else {
        (id2x_4t_1e_1) = (id2x_1);
        (id2st_count) = (id2x_4t_1e_1);
      }
    }
    else {
    }
  }
  if ( (getFillLevel() >= (15l)) && (getFlushLevel() < (15l)|| !isFlushingActive() ))
  { // Node ID: 21 (NodePrintf)
    const HWOffsetFix<1,0,UNSIGNED> &id21in_condition = id20out_value;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id21in_arg0 = id39out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id21in_arg1 = id40out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id21in_arg2 = id41out_output[getCycle()%7];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id21in_arg3 = id17out_a;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id21in_arg4 = id38out_result[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id21in_arg5 = id2out_count;

    if((id21in_condition.getValueAsBool())) {
      const HWOffsetFix<32,0,TWOSCOMPLEMENT> &_format_arg_0 = id21in_arg0;
      const HWOffsetFix<32,0,TWOSCOMPLEMENT> &_format_arg_1 = id21in_arg1;
      const HWOffsetFix<32,0,TWOSCOMPLEMENT> &_format_arg_2 = id21in_arg2;
      const HWOffsetFix<32,0,TWOSCOMPLEMENT> &_format_arg_3 = id21in_arg3;
      const HWOffsetFix<32,0,TWOSCOMPLEMENT> &_format_arg_4 = id21in_arg4;
      const HWOffsetFix<32,0,UNSIGNED> &_format_arg_5 = id21in_arg5;
      simPrintf("", 21, format_string_QueueKernel_1("\nx=%d y=%d controller=%d a=%d sum=%d count=%d\n", _format_arg_0, _format_arg_1, _format_arg_2, _format_arg_3, _format_arg_4, _format_arg_5));
    }
    else {
      simPrintf("", 21, format_string_QueueKernel_2(""));
    }
  }
  HWOffsetFix<1,0,UNSIGNED> id22out_o;

  { // Node ID: 22 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id22in_i = id41out_output[getCycle()%7];

    id22out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id22in_i));
  }
  HWRawBits<1> id26out_output;

  { // Node ID: 26 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id26in_input = id22out_o;

    id26out_output = (cast_fixed2bits(id26in_input));
  }
  { // Node ID: 23 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id24out_result;

  { // Node ID: 24 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id24in_a = id23out_io_s_force_disabled;

    id24out_result = (not_fixed(id24in_a));
  }
  HWRawBits<1> id27out_output;

  { // Node ID: 27 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id27in_input = id24out_result;

    id27out_output = (cast_fixed2bits(id27in_input));
  }
  HWRawBits<1> id25out_result;

  { // Node ID: 25 (NodeAnd)
    const HWRawBits<1> &id25in_a = id26out_output;
    const HWRawBits<1> &id25in_b = id27out_output;

    HWRawBits<1> id25x_1;

    (id25x_1) = (and_bits(id25in_a,id25in_b));
    id25out_result = (id25x_1);
  }
  HWOffsetFix<1,0,UNSIGNED> id28out_output;

  { // Node ID: 28 (NodeReinterpret)
    const HWRawBits<1> &id28in_input = id25out_result;

    id28out_output = (cast_bits2fixed<1,0,UNSIGNED>(id28in_input));
  }
  if ( (getFillLevel() >= (15l)) && (getFlushLevel() < (15l)|| !isFlushingActive() ))
  { // Node ID: 29 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id29in_output_control = id28out_output;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id29in_data = id38out_result[getCycle()%2];

    bool id29x_1;

    (id29x_1) = ((id29in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(15l))&(isFlushingActive()))));
    if((id29x_1)) {
      writeOutput(m_s, id29in_data);
    }
  }
  { // Node ID: 33 (NodeConstantRawBits)
  }
  { // Node ID: 44 (NodeConstantRawBits)
  }
  { // Node ID: 31 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 32 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id32in_enable = id44out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id32in_max = id31out_value;

    HWOffsetFix<49,0,UNSIGNED> id32x_1;
    HWOffsetFix<1,0,UNSIGNED> id32x_2;
    HWOffsetFix<1,0,UNSIGNED> id32x_3;
    HWOffsetFix<49,0,UNSIGNED> id32x_4t_1e_1;

    id32out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id32st_count)));
    (id32x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id32st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id32x_2) = (gte_fixed((id32x_1),id32in_max));
    (id32x_3) = (and_fixed((id32x_2),id32in_enable));
    id32out_wrap = (id32x_3);
    if((id32in_enable.getValueAsBool())) {
      if(((id32x_3).getValueAsBool())) {
        (id32st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id32x_4t_1e_1) = (id32x_1);
        (id32st_count) = (id32x_4t_1e_1);
      }
    }
    else {
    }
  }
  { // Node ID: 43 (NodeFIFO)
    const HWOffsetFix<48,0,UNSIGNED> &id43in_input = id32out_count;

    id43out_output[(getCycle()+4)%5] = id43in_input;
  }
  if ( (getFillLevel() >= (4l)) && (getFlushLevel() < (4l)|| !isFlushingActive() ))
  { // Node ID: 34 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id34in_load = id33out_value;
    const HWOffsetFix<48,0,UNSIGNED> &id34in_data = id43out_output[getCycle()%5];

    bool id34x_1;

    (id34x_1) = ((id34in_load.getValueAsBool())&(!(((getFlushLevel())>=(4l))&(isFlushingActive()))));
    if((id34x_1)) {
      setMappedRegValue("current_run_cycle_count", id34in_data);
    }
  }
  { // Node ID: 36 (NodeInputMappedReg)
  }
  { // Node ID: 37 (NodeEq)
    const HWOffsetFix<48,0,UNSIGNED> &id37in_a = id32out_count;
    const HWOffsetFix<48,0,UNSIGNED> &id37in_b = id36out_run_cycle_count;

    id37out_result[(getCycle()+1)%2] = (eq_fixed(id37in_a,id37in_b));
  }
  if ( (getFillLevel() >= (1l)))
  { // Node ID: 35 (NodeFlush)
    const HWOffsetFix<1,0,UNSIGNED> &id35in_start = id37out_result[getCycle()%2];

    if((id35in_start.getValueAsBool())) {
      startFlushing();
    }
  }
};

};
