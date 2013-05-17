#include "stdsimheader.h"
//#define BOOST_NO_STD_LOCALE
//#include <boost/format.hpp>

//#include "CpuStreamKernel.h"

namespace maxcompilersim {

void CpuStreamKernel::execute0() {
  { // Node ID: 17 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id18out_result;

  { // Node ID: 18 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id18in_a = id17out_io_strout_force_disabled;

    id18out_result = (not_fixed(id18in_a));
  }
  HWRawBits<1> id21out_output;

  { // Node ID: 21 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id21in_input = id18out_result;

    id21out_output = (cast_fixed2bits(id21in_input));
  }
  HWOffsetFix<1,0,UNSIGNED> id22out_output;

  { // Node ID: 22 (NodeReinterpret)
    const HWRawBits<1> &id22in_input = id21out_output;

    id22out_output = (cast_bits2fixed<1,0,UNSIGNED>(id22in_input));
  }
  { // Node ID: 0 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id1out_result;

  { // Node ID: 1 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id1in_a = id0out_io_str_force_disabled;

    id1out_result = (not_fixed(id1in_a));
  }
  if ( (getFillLevel() >= ((id62out_ce_delay_eq_3).getValueAsLong())))
  { // Node ID: 2 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id2in_enable = id1out_result;

    (id2st_read_next_cycle) = ((id2in_enable.getValueAsBool())&(!(((getFlushLevel())>=((id60out_ce_delay_eq_1).getValueAsLong()))&(isFlushingActive()))));
    queueReadRequest(m_str, id2st_read_next_cycle.getValueAsBool());
  }
  { // Node ID: 56 (NodeInputMappedReg)
  }
  HWOffsetFix<32,0,UNSIGNED> id40out_output;

  { // Node ID: 40 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id40in_input = id2out_data;
    const HWOffsetFix<4,0,UNSIGNED> &id40in_current_depth0 = id56out_delay_eq_0;

    long id40x_1;

    id40out_output = (id40sta_store[(id40st_store_idx)]);
    (id40sta_store[(id40st_store_idx)]) = id40in_input;
    switch(((long)((id40st_store_idx)==(id40st_store_idx_max)))) {
      case 0l:
        id40x_1 = ((id40st_store_idx)+(1l));
        break;
      case 1l:
        id40x_1 = (0l);
        break;
      default:
        id40x_1 = (long());
        break;
    }
    (id40st_store_idx) = (id40x_1);
  }
  { // Node ID: 57 (NodeInputMappedReg)
  }
  HWOffsetFix<32,0,UNSIGNED> id46out_output;

  { // Node ID: 46 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id46in_input = id40out_output;
    const HWOffsetFix<7,0,UNSIGNED> &id46in_current_depth0 = id57out_delay_eq_1;

    long id46x_1;

    id46out_output = (id46sta_store[(id46st_store_idx)]);
    (id46sta_store[(id46st_store_idx)]) = id46in_input;
    switch(((long)((id46st_store_idx)==(id46st_store_idx_max)))) {
      case 0l:
        id46x_1 = ((id46st_store_idx)+(1l));
        break;
      case 1l:
        id46x_1 = (0l);
        break;
      default:
        id46x_1 = (long());
        break;
    }
    (id46st_store_idx) = (id46x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id45out_output;

  { // Node ID: 45 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id45in_input = id46out_output;
    const HWOffsetFix<4,0,UNSIGNED> &id45in_current_depth0 = id56out_delay_eq_0;

    long id45x_1;

    id45out_output = (id45sta_store[(id45st_store_idx)]);
    (id45sta_store[(id45st_store_idx)]) = id45in_input;
    switch(((long)((id45st_store_idx)==(id45st_store_idx_max)))) {
      case 0l:
        id45x_1 = ((id45st_store_idx)+(1l));
        break;
      case 1l:
        id45x_1 = (0l);
        break;
      default:
        id45x_1 = (long());
        break;
    }
    (id45st_store_idx) = (id45x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id3out_output;

  { // Node ID: 3 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id3in_input = id45out_output;

    id3out_output = id3in_input;
  }
  { // Node ID: 52 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id52in_input = id45out_output;

    id52out_output[(getCycle()+1)%2] = id52in_input;
  }
  { // Node ID: 54 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id54in_input = id52out_output[getCycle()%2];

    id54out_output[(getCycle()+1)%2] = id54in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id4out_output;

  { // Node ID: 4 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id4in_input = id54out_output[getCycle()%2];

    id4out_output = id4in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id5out_output;

  { // Node ID: 5 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id5in_input = id46out_output;

    id5out_output = id5in_input;
  }
  { // Node ID: 49 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id49in_input = id5out_output;

    id49out_output[(getCycle()+1)%2] = id49in_input;
  }
  { // Node ID: 33 (NodeTriAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id33in_a = id3out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id33in_b = id4out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id33in_c = id49out_output[getCycle()%2];

    HWOffsetFix<32,0,UNSIGNED> id33x_1;

    (id33x_1) = (add_fixed<32,0,UNSIGNED,TRUNCATE>((add_fixed<32,0,UNSIGNED,TRUNCATE>(id33in_a,id33in_b)),id33in_c));
    id33out_result[(getCycle()+1)%2] = (id33x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id6out_output;

  { // Node ID: 6 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id6in_input = id54out_output[getCycle()%2];

    id6out_output = id6in_input;
  }
  HWOffsetFix<32,0,UNSIGNED> id41out_output;

  { // Node ID: 41 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id41in_input = id6out_output;
    const HWOffsetFix<4,0,UNSIGNED> &id41in_current_depth0 = id56out_delay_eq_0;

    long id41x_1;

    id41out_output = (id41sta_store[(id41st_store_idx)]);
    (id41sta_store[(id41st_store_idx)]) = id41in_input;
    switch(((long)((id41st_store_idx)==(id41st_store_idx_max)))) {
      case 0l:
        id41x_1 = ((id41st_store_idx)+(1l));
        break;
      case 1l:
        id41x_1 = (0l);
        break;
      default:
        id41x_1 = (long());
        break;
    }
    (id41st_store_idx) = (id41x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id7out_output;

  { // Node ID: 7 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id7in_input = id40out_output;

    id7out_output = id7in_input;
  }
  { // Node ID: 51 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id51in_input = id7out_output;

    id51out_output[(getCycle()+5)%6] = id51in_input;
  }
  { // Node ID: 34 (NodeTriAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id34in_a = id33out_result[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id34in_b = id41out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id34in_c = id51out_output[getCycle()%6];

    HWOffsetFix<32,0,UNSIGNED> id34x_1;

    (id34x_1) = (add_fixed<32,0,UNSIGNED,TRUNCATE>((add_fixed<32,0,UNSIGNED,TRUNCATE>(id34in_a,id34in_b)),id34in_c));
    id34out_result[(getCycle()+1)%2] = (id34x_1);
  }
  HWOffsetFix<32,0,UNSIGNED> id8out_output;

  { // Node ID: 8 (NodeStreamOffset)
    const HWOffsetFix<32,0,UNSIGNED> &id8in_input = id52out_output[getCycle()%2];

    id8out_output = id8in_input;
  }
  { // Node ID: 58 (NodeInputMappedReg)
  }
  HWOffsetFix<32,0,UNSIGNED> id47out_output;

  { // Node ID: 47 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id47in_input = id8out_output;
    const HWOffsetFix<7,0,UNSIGNED> &id47in_current_depth0 = id58out_delay_eq_2;

    long id47x_1;

    id47out_output = (id47sta_store[(id47st_store_idx)]);
    (id47sta_store[(id47st_store_idx)]) = id47in_input;
    switch(((long)((id47st_store_idx)==(id47st_store_idx_max)))) {
      case 0l:
        id47x_1 = ((id47st_store_idx)+(1l));
        break;
      case 1l:
        id47x_1 = (0l);
        break;
      default:
        id47x_1 = (long());
        break;
    }
    (id47st_store_idx) = (id47x_1);
  }
  { // Node ID: 35 (NodeAdd)
    const HWOffsetFix<32,0,UNSIGNED> &id35in_a = id34out_result[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id35in_b = id47out_output;

    id35out_result[(getCycle()+1)%2] = (add_fixed<32,0,UNSIGNED,TONEAR>(id35in_a,id35in_b));
  }
  if ( (getFillLevel() >= (126l)) && (getFlushLevel() < (126l)|| !isFlushingActive() ))
  { // Node ID: 23 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id23in_output_control = id22out_output;
    const HWOffsetFix<32,0,UNSIGNED> &id23in_data = id35out_result[getCycle()%2];

    bool id23x_1;

    (id23x_1) = ((id23in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(126l))&(isFlushingActive()))));
    if((id23x_1)) {
      writeOutput(m_strout, id23in_data);
    }
  }
  { // Node ID: 27 (NodeConstantRawBits)
  }
  { // Node ID: 55 (NodeConstantRawBits)
  }
  { // Node ID: 25 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= ((id63out_ce_delay_eq_4).getValueAsLong())))
  { // Node ID: 26 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id26in_enable = id55out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id26in_max = id25out_value;

    HWOffsetFix<49,0,UNSIGNED> id26x_1;
    HWOffsetFix<1,0,UNSIGNED> id26x_2;
    HWOffsetFix<1,0,UNSIGNED> id26x_3;
    HWOffsetFix<49,0,UNSIGNED> id26x_4t_1e_1;

    id26out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id26st_count)));
    (id26x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id26st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id26x_2) = (gte_fixed((id26x_1),id26in_max));
    (id26x_3) = (and_fixed((id26x_2),id26in_enable));
    id26out_wrap = (id26x_3);
    if((id26in_enable.getValueAsBool())) {
      if(((id26x_3).getValueAsBool())) {
        (id26st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id26x_4t_1e_1) = (id26x_1);
        (id26st_count) = (id26x_4t_1e_1);
      }
    }
    else {
    }
  }
  { // Node ID: 53 (NodeFIFO)
    const HWOffsetFix<48,0,UNSIGNED> &id53in_input = id26out_count;

    id53out_output[(getCycle()+4)%5] = id53in_input;
  }
  if ( (getFillLevel() >= ((id64out_ce_delay_eq_5).getValueAsLong())) && (getFlushLevel() < ((id64out_ce_delay_eq_5).getValueAsLong())|| !isFlushingActive() ))
  { // Node ID: 28 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id28in_load = id27out_value;
    const HWOffsetFix<48,0,UNSIGNED> &id28in_data = id53out_output[getCycle()%5];

    bool id28x_1;

    (id28x_1) = ((id28in_load.getValueAsBool())&(!(((getFlushLevel())>=((id61out_ce_delay_eq_2).getValueAsLong()))&(isFlushingActive()))));
    if((id28x_1)) {
      setMappedRegValue("current_run_cycle_count", id28in_data);
    }
  }
  { // Node ID: 30 (NodeInputMappedReg)
  }
  { // Node ID: 31 (NodeEq)
    const HWOffsetFix<48,0,UNSIGNED> &id31in_a = id26out_count;
    const HWOffsetFix<48,0,UNSIGNED> &id31in_b = id30out_run_cycle_count;

    id31out_result[(getCycle()+1)%2] = (eq_fixed(id31in_a,id31in_b));
  }
  if ( (getFillLevel() >= ((id65out_ce_delay_eq_6).getValueAsLong())))
  { // Node ID: 29 (NodeFlush)
    const HWOffsetFix<1,0,UNSIGNED> &id29in_start = id31out_result[getCycle()%2];

    if((id29in_start.getValueAsBool())) {
      startFlushing();
    }
  }
  { // Node ID: 59 (NodeInputMappedReg)
  }
  { // Node ID: 60 (NodeInputMappedReg)
  }
  { // Node ID: 61 (NodeInputMappedReg)
  }
  { // Node ID: 62 (NodeInputMappedReg)
  }
  { // Node ID: 63 (NodeInputMappedReg)
  }
  { // Node ID: 64 (NodeInputMappedReg)
  }
  { // Node ID: 65 (NodeInputMappedReg)
  }
  { // Node ID: 66 (NodeInputMappedReg)
  }
};

};
