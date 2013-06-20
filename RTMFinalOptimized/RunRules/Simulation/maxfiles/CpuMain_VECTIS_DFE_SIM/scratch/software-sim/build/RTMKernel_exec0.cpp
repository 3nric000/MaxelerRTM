#include "stdsimheader.h"
//#define BOOST_NO_STD_LOCALE
//#include <boost/format.hpp>

//#include "RTMKernel.h"

namespace maxcompilersim {

void RTMKernel::execute0() {
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
  HWOffsetFix<1,0,UNSIGNED> id147out_o;

  { // Node ID: 147 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id147in_i = id2out_data;

    id147out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id147in_i));
  }
  { // Node ID: 164 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id164in_input = id147out_o;

    id164out_output[(getCycle()+158)%159] = id164in_input;
  }
  HWRawBits<1> id151out_output;

  { // Node ID: 151 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id151in_input = id164out_output[getCycle()%159];

    id151out_output = (cast_fixed2bits(id151in_input));
  }
  { // Node ID: 148 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id149out_result;

  { // Node ID: 149 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id149in_a = id148out_io_ppresult_force_disabled;

    id149out_result = (not_fixed(id149in_a));
  }
  HWRawBits<1> id152out_output;

  { // Node ID: 152 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id152in_input = id149out_result;

    id152out_output = (cast_fixed2bits(id152in_input));
  }
  HWRawBits<1> id150out_result;

  { // Node ID: 150 (NodeAnd)
    const HWRawBits<1> &id150in_a = id151out_output;
    const HWRawBits<1> &id150in_b = id152out_output;

    HWRawBits<1> id150x_1;

    (id150x_1) = (and_bits(id150in_a,id150in_b));
    id150out_result = (id150x_1);
  }
  HWOffsetFix<1,0,UNSIGNED> id153out_output;

  { // Node ID: 153 (NodeReinterpret)
    const HWRawBits<1> &id153in_input = id150out_result;

    id153out_output = (cast_bits2fixed<1,0,UNSIGNED>(id153in_input));
  }
  { // Node ID: 206 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id206in_input = id153out_output;

    id206out_output[(getCycle()+88)%89] = id206in_input;
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
    const HWOffsetFix<1,0,UNSIGNED> &id5in_a = id4out_io_p_force_disabled;

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
    queueReadRequest(m_p, id10st_read_next_cycle.getValueAsBool());
  }
  { // Node ID: 174 (NodeFIFO)
    const HWFloat<8,24> &id174in_input = id10out_data;

    id174out_output[(getCycle()+2)%3] = id174in_input;
  }
  { // Node ID: 208 (NodeFIFO)
    const HWFloat<8,24> &id208in_input = id174out_output[getCycle()%3];

    id208out_output[(getCycle()+9)%10] = id208in_input;
  }
  { // Node ID: 209 (NodeFIFO)
    const HWFloat<8,24> &id209in_input = id208out_output[getCycle()%10];

    id209out_output[(getCycle()+2)%3] = id209in_input;
  }
  { // Node ID: 210 (NodeFIFO)
    const HWFloat<8,24> &id210in_input = id209out_output[getCycle()%3];

    id210out_output[(getCycle()+2)%3] = id210in_input;
  }
  { // Node ID: 211 (NodeFIFO)
    const HWFloat<8,24> &id211in_input = id210out_output[getCycle()%3];

    id211out_output[(getCycle()+7)%8] = id211in_input;
  }
  { // Node ID: 212 (NodeFIFO)
    const HWFloat<8,24> &id212in_input = id211out_output[getCycle()%8];

    id212out_output[(getCycle()+6)%7] = id212in_input;
  }
  { // Node ID: 213 (NodeFIFO)
    const HWFloat<8,24> &id213in_input = id212out_output[getCycle()%7];

    id213out_output[(getCycle()+5)%6] = id213in_input;
  }
  { // Node ID: 214 (NodeFIFO)
    const HWFloat<8,24> &id214in_input = id213out_output[getCycle()%6];

    id214out_output[(getCycle()+8)%9] = id214in_input;
  }
  { // Node ID: 215 (NodeFIFO)
    const HWFloat<8,24> &id215in_input = id214out_output[getCycle()%9];

    id215out_output[(getCycle()+3)%4] = id215in_input;
  }
  { // Node ID: 216 (NodeFIFO)
    const HWFloat<8,24> &id216in_input = id215out_output[getCycle()%4];

    id216out_output[(getCycle()+10)%11] = id216in_input;
  }
  { // Node ID: 163 (NodePO2FPMult)
    const HWFloat<8,24> &id163in_floatIn = id216out_output[getCycle()%11];

    id163out_floatOut[(getCycle()+1)%2] = (mul_float(id163in_floatIn,(c_hw_flt_8_24_2_0val)));
  }
  { // Node ID: 170 (NodeFIFO)
    const HWFloat<8,24> &id170in_input = id163out_floatOut[getCycle()%2];

    id170out_output[(getCycle()+142)%143] = id170in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id11out_o;

  { // Node ID: 11 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id11in_i = id2out_data;

    id11out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id11in_i));
  }
  { // Node ID: 166 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id166in_input = id11out_o;

    id166out_output[(getCycle()+158)%159] = id166in_input;
  }
  HWRawBits<1> id15out_output;

  { // Node ID: 15 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id15in_input = id166out_output[getCycle()%159];

    id15out_output = (cast_fixed2bits(id15in_input));
  }
  { // Node ID: 167 (NodeFIFO)
    const HWRawBits<1> &id167in_input = id15out_output;

    id167out_output[(getCycle()+31)%32] = id167in_input;
  }
  { // Node ID: 12 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id13out_result;

  { // Node ID: 13 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id13in_a = id12out_io_pp_force_disabled;

    id13out_result = (not_fixed(id13in_a));
  }
  HWRawBits<1> id16out_output;

  { // Node ID: 16 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id16in_input = id13out_result;

    id16out_output = (cast_fixed2bits(id16in_input));
  }
  HWRawBits<1> id14out_result;

  { // Node ID: 14 (NodeAnd)
    const HWRawBits<1> &id14in_a = id167out_output[getCycle()%32];
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
  if ( (getFillLevel() >= (198l)))
  { // Node ID: 18 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id18in_enable = id17out_output;

    (id18st_read_next_cycle) = ((id18in_enable.getValueAsBool())&(!(((getFlushLevel())>=(198l))&(isFlushingActive()))));
    queueReadRequest(m_pp, id18st_read_next_cycle.getValueAsBool());
  }
  HWOffsetFix<1,0,UNSIGNED> id41out_o;

  { // Node ID: 41 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id41in_i = id2out_data;

    id41out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id41in_i));
  }
  { // Node ID: 168 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id168in_input = id41out_o;

    id168out_output[(getCycle()+158)%159] = id168in_input;
  }
  HWRawBits<1> id45out_output;

  { // Node ID: 45 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id45in_input = id168out_output[getCycle()%159];

    id45out_output = (cast_fixed2bits(id45in_input));
  }
  { // Node ID: 42 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id43out_result;

  { // Node ID: 43 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id43in_a = id42out_io_scale_force_disabled;

    id43out_result = (not_fixed(id43in_a));
  }
  HWRawBits<1> id46out_output;

  { // Node ID: 46 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id46in_input = id43out_result;

    id46out_output = (cast_fixed2bits(id46in_input));
  }
  HWRawBits<1> id44out_result;

  { // Node ID: 44 (NodeAnd)
    const HWRawBits<1> &id44in_a = id45out_output;
    const HWRawBits<1> &id44in_b = id46out_output;

    HWRawBits<1> id44x_1;

    (id44x_1) = (and_bits(id44in_a,id44in_b));
    id44out_result = (id44x_1);
  }
  HWOffsetFix<1,0,UNSIGNED> id47out_output;

  { // Node ID: 47 (NodeReinterpret)
    const HWRawBits<1> &id47in_input = id44out_result;

    id47out_output = (cast_bits2fixed<1,0,UNSIGNED>(id47in_input));
  }
  { // Node ID: 169 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id169in_input = id47out_output;

    id169out_output[(getCycle()+31)%32] = id169in_input;
  }
  if ( (getFillLevel() >= (198l)))
  { // Node ID: 48 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id48in_enable = id169out_output[getCycle()%32];

    (id48st_read_next_cycle) = ((id48in_enable.getValueAsBool())&(!(((getFlushLevel())>=(198l))&(isFlushingActive()))));
    queueReadRequest(m_scale, id48st_read_next_cycle.getValueAsBool());
  }
  { // Node ID: 65 (NodeMul)
    const HWFloat<8,24> &id65in_a = id18out_data;
    const HWFloat<8,24> &id65in_b = id48out_data;

    id65out_result[(getCycle()+8)%9] = (mul_float(id65in_a,id65in_b));
  }
  { // Node ID: 68 (NodeSub)
    const HWFloat<8,24> &id68in_a = id170out_output[getCycle()%143];
    const HWFloat<8,24> &id68in_b = id65out_result[getCycle()%9];

    id68out_result[(getCycle()+12)%13] = (sub_float(id68in_a,id68in_b));
  }
  HWOffsetFix<1,0,UNSIGNED> id19out_o;

  { // Node ID: 19 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id19in_i = id2out_data;

    id19out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id19in_i));
  }
  { // Node ID: 171 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id171in_input = id19out_o;

    id171out_output[(getCycle()+158)%159] = id171in_input;
  }
  HWRawBits<1> id23out_output;

  { // Node ID: 23 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id23in_input = id171out_output[getCycle()%159];

    id23out_output = (cast_fixed2bits(id23in_input));
  }
  { // Node ID: 20 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id21out_result;

  { // Node ID: 21 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id21in_a = id20out_io_dvv_force_disabled;

    id21out_result = (not_fixed(id21in_a));
  }
  HWRawBits<1> id24out_output;

  { // Node ID: 24 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id24in_input = id21out_result;

    id24out_output = (cast_fixed2bits(id24in_input));
  }
  HWRawBits<1> id22out_result;

  { // Node ID: 22 (NodeAnd)
    const HWRawBits<1> &id22in_a = id23out_output;
    const HWRawBits<1> &id22in_b = id24out_output;

    HWRawBits<1> id22x_1;

    (id22x_1) = (and_bits(id22in_a,id22in_b));
    id22out_result = (id22x_1);
  }
  { // Node ID: 172 (NodeFIFO)
    const HWRawBits<1> &id172in_input = id22out_result;

    id172out_output[(getCycle()+43)%44] = id172in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id25out_output;

  { // Node ID: 25 (NodeReinterpret)
    const HWRawBits<1> &id25in_input = id172out_output[getCycle()%44];

    id25out_output = (cast_bits2fixed<1,0,UNSIGNED>(id25in_input));
  }
  if ( (getFillLevel() >= (210l)))
  { // Node ID: 26 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id26in_enable = id25out_output;

    (id26st_read_next_cycle) = ((id26in_enable.getValueAsBool())&(!(((getFlushLevel())>=(210l))&(isFlushingActive()))));
    queueReadRequest(m_dvv, id26st_read_next_cycle.getValueAsBool());
  }
  { // Node ID: 49 (NodeInputMappedReg)
  }
  { // Node ID: 69 (NodeMul)
    const HWFloat<8,24> &id69in_a = id209out_output[getCycle()%3];
    const HWFloat<8,24> &id69in_b = id49out_c_0;

    id69out_result[(getCycle()+8)%9] = (mul_float(id69in_a,id69in_b));
  }
  { // Node ID: 50 (NodeInputMappedReg)
  }
  HWFloat<8,24> id70out_output;

  { // Node ID: 70 (NodeStreamOffset)
    const HWFloat<8,24> &id70in_input = id10out_data;

    id70out_output = id70in_input;
  }
  HWFloat<8,24> id71out_output;

  { // Node ID: 71 (NodeStreamOffset)
    const HWFloat<8,24> &id71in_input = id174out_output[getCycle()%3];

    id71out_output = id71in_input;
  }
  { // Node ID: 72 (NodeAdd)
    const HWFloat<8,24> &id72in_a = id70out_output;
    const HWFloat<8,24> &id72in_b = id71out_output;

    id72out_result[(getCycle()+12)%13] = (add_float(id72in_a,id72in_b));
  }
  { // Node ID: 73 (NodeMul)
    const HWFloat<8,24> &id73in_a = id50out_c_1_0;
    const HWFloat<8,24> &id73in_b = id72out_result[getCycle()%13];

    id73out_result[(getCycle()+8)%9] = (mul_float(id73in_a,id73in_b));
  }
  { // Node ID: 74 (NodeAdd)
    const HWFloat<8,24> &id74in_a = id69out_result[getCycle()%9];
    const HWFloat<8,24> &id74in_b = id73out_result[getCycle()%9];

    id74out_result[(getCycle()+12)%13] = (add_float(id74in_a,id74in_b));
  }
  { // Node ID: 51 (NodeInputMappedReg)
  }
  HWFloat<8,24> id75out_output;

  { // Node ID: 75 (NodeStreamOffset)
    const HWFloat<8,24> &id75in_input = id208out_output[getCycle()%10];

    id75out_output = id75in_input;
  }
  HWFloat<8,24> id76out_output;

  { // Node ID: 76 (NodeStreamOffset)
    const HWFloat<8,24> &id76in_input = id210out_output[getCycle()%3];

    id76out_output = id76in_input;
  }
  { // Node ID: 77 (NodeAdd)
    const HWFloat<8,24> &id77in_a = id75out_output;
    const HWFloat<8,24> &id77in_b = id76out_output;

    id77out_result[(getCycle()+12)%13] = (add_float(id77in_a,id77in_b));
  }
  { // Node ID: 78 (NodeMul)
    const HWFloat<8,24> &id78in_a = id51out_c_1_1;
    const HWFloat<8,24> &id78in_b = id77out_result[getCycle()%13];

    id78out_result[(getCycle()+8)%9] = (mul_float(id78in_a,id78in_b));
  }
  { // Node ID: 79 (NodeAdd)
    const HWFloat<8,24> &id79in_a = id74out_result[getCycle()%13];
    const HWFloat<8,24> &id79in_b = id78out_result[getCycle()%9];

    id79out_result[(getCycle()+12)%13] = (add_float(id79in_a,id79in_b));
  }
  { // Node ID: 52 (NodeInputMappedReg)
  }
  HWFloat<8,24> id80out_output;

  { // Node ID: 80 (NodeStreamOffset)
    const HWFloat<8,24> &id80in_input = id211out_output[getCycle()%8];

    id80out_output = id80in_input;
  }
  HWFloat<8,24> id81out_output;

  { // Node ID: 81 (NodeStreamOffset)
    const HWFloat<8,24> &id81in_input = id212out_output[getCycle()%7];

    id81out_output = id81in_input;
  }
  { // Node ID: 82 (NodeAdd)
    const HWFloat<8,24> &id82in_a = id80out_output;
    const HWFloat<8,24> &id82in_b = id81out_output;

    id82out_result[(getCycle()+12)%13] = (add_float(id82in_a,id82in_b));
  }
  { // Node ID: 83 (NodeMul)
    const HWFloat<8,24> &id83in_a = id52out_c_1_2;
    const HWFloat<8,24> &id83in_b = id82out_result[getCycle()%13];

    id83out_result[(getCycle()+8)%9] = (mul_float(id83in_a,id83in_b));
  }
  { // Node ID: 84 (NodeAdd)
    const HWFloat<8,24> &id84in_a = id79out_result[getCycle()%13];
    const HWFloat<8,24> &id84in_b = id83out_result[getCycle()%9];

    id84out_result[(getCycle()+12)%13] = (add_float(id84in_a,id84in_b));
  }
  { // Node ID: 53 (NodeInputMappedReg)
  }
  HWFloat<8,24> id85out_output;

  { // Node ID: 85 (NodeStreamOffset)
    const HWFloat<8,24> &id85in_input = id213out_output[getCycle()%6];

    id85out_output = id85in_input;
  }
  HWFloat<8,24> id86out_output;

  { // Node ID: 86 (NodeStreamOffset)
    const HWFloat<8,24> &id86in_input = id214out_output[getCycle()%9];

    id86out_output = id86in_input;
  }
  { // Node ID: 87 (NodeAdd)
    const HWFloat<8,24> &id87in_a = id85out_output;
    const HWFloat<8,24> &id87in_b = id86out_output;

    id87out_result[(getCycle()+12)%13] = (add_float(id87in_a,id87in_b));
  }
  { // Node ID: 88 (NodeMul)
    const HWFloat<8,24> &id88in_a = id53out_c_1_3;
    const HWFloat<8,24> &id88in_b = id87out_result[getCycle()%13];

    id88out_result[(getCycle()+8)%9] = (mul_float(id88in_a,id88in_b));
  }
  { // Node ID: 89 (NodeAdd)
    const HWFloat<8,24> &id89in_a = id84out_result[getCycle()%13];
    const HWFloat<8,24> &id89in_b = id88out_result[getCycle()%9];

    id89out_result[(getCycle()+12)%13] = (add_float(id89in_a,id89in_b));
  }
  { // Node ID: 54 (NodeInputMappedReg)
  }
  HWFloat<8,24> id90out_output;

  { // Node ID: 90 (NodeStreamOffset)
    const HWFloat<8,24> &id90in_input = id215out_output[getCycle()%4];

    id90out_output = id90in_input;
  }
  HWFloat<8,24> id91out_output;

  { // Node ID: 91 (NodeStreamOffset)
    const HWFloat<8,24> &id91in_input = id216out_output[getCycle()%11];

    id91out_output = id91in_input;
  }
  { // Node ID: 92 (NodeAdd)
    const HWFloat<8,24> &id92in_a = id90out_output;
    const HWFloat<8,24> &id92in_b = id91out_output;

    id92out_result[(getCycle()+12)%13] = (add_float(id92in_a,id92in_b));
  }
  { // Node ID: 93 (NodeMul)
    const HWFloat<8,24> &id93in_a = id54out_c_1_4;
    const HWFloat<8,24> &id93in_b = id92out_result[getCycle()%13];

    id93out_result[(getCycle()+8)%9] = (mul_float(id93in_a,id93in_b));
  }
  { // Node ID: 94 (NodeAdd)
    const HWFloat<8,24> &id94in_a = id89out_result[getCycle()%13];
    const HWFloat<8,24> &id94in_b = id93out_result[getCycle()%9];

    id94out_result[(getCycle()+12)%13] = (add_float(id94in_a,id94in_b));
  }
  { // Node ID: 55 (NodeInputMappedReg)
  }
  { // Node ID: 38 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id39out_result;

  { // Node ID: 39 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id39in_a = id38out_io_py_force_disabled;

    id39out_result = (not_fixed(id39in_a));
  }
  if ( (getFillLevel() >= (74l)))
  { // Node ID: 40 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id40in_enable = id39out_result;

    (id40st_read_next_cycle) = ((id40in_enable.getValueAsBool())&(!(((getFlushLevel())>=(74l))&(isFlushingActive()))));
    queueReadRequest(m_py, id40st_read_next_cycle.getValueAsBool());
  }
  HWFloat<8,24> id95out_output;

  { // Node ID: 95 (NodeStreamOffset)
    const HWFloat<8,24> &id95in_input = id40out_data;

    id95out_output = id95in_input;
  }
  { // Node ID: 183 (NodeFIFO)
    const HWFloat<8,24> &id183in_input = id40out_data;

    id183out_output[(getCycle()+2)%3] = id183in_input;
  }
  HWFloat<8,24> id96out_output;

  { // Node ID: 96 (NodeStreamOffset)
    const HWFloat<8,24> &id96in_input = id183out_output[getCycle()%3];

    id96out_output = id96in_input;
  }
  { // Node ID: 97 (NodeAdd)
    const HWFloat<8,24> &id97in_a = id95out_output;
    const HWFloat<8,24> &id97in_b = id96out_output;

    id97out_result[(getCycle()+12)%13] = (add_float(id97in_a,id97in_b));
  }
  { // Node ID: 98 (NodeMul)
    const HWFloat<8,24> &id98in_a = id55out_c_2_0;
    const HWFloat<8,24> &id98in_b = id97out_result[getCycle()%13];

    id98out_result[(getCycle()+8)%9] = (mul_float(id98in_a,id98in_b));
  }
  { // Node ID: 99 (NodeAdd)
    const HWFloat<8,24> &id99in_a = id94out_result[getCycle()%13];
    const HWFloat<8,24> &id99in_b = id98out_result[getCycle()%9];

    id99out_result[(getCycle()+12)%13] = (add_float(id99in_a,id99in_b));
  }
  { // Node ID: 56 (NodeInputMappedReg)
  }
  { // Node ID: 217 (NodeFIFO)
    const HWFloat<8,24> &id217in_input = id183out_output[getCycle()%3];

    id217out_output[(getCycle()+9)%10] = id217in_input;
  }
  HWFloat<8,24> id100out_output;

  { // Node ID: 100 (NodeStreamOffset)
    const HWFloat<8,24> &id100in_input = id217out_output[getCycle()%10];

    id100out_output = id100in_input;
  }
  { // Node ID: 218 (NodeFIFO)
    const HWFloat<8,24> &id218in_input = id217out_output[getCycle()%10];

    id218out_output[(getCycle()+4)%5] = id218in_input;
  }
  HWFloat<8,24> id101out_output;

  { // Node ID: 101 (NodeStreamOffset)
    const HWFloat<8,24> &id101in_input = id218out_output[getCycle()%5];

    id101out_output = id101in_input;
  }
  { // Node ID: 102 (NodeAdd)
    const HWFloat<8,24> &id102in_a = id100out_output;
    const HWFloat<8,24> &id102in_b = id101out_output;

    id102out_result[(getCycle()+12)%13] = (add_float(id102in_a,id102in_b));
  }
  { // Node ID: 103 (NodeMul)
    const HWFloat<8,24> &id103in_a = id56out_c_2_1;
    const HWFloat<8,24> &id103in_b = id102out_result[getCycle()%13];

    id103out_result[(getCycle()+8)%9] = (mul_float(id103in_a,id103in_b));
  }
  { // Node ID: 104 (NodeAdd)
    const HWFloat<8,24> &id104in_a = id99out_result[getCycle()%13];
    const HWFloat<8,24> &id104in_b = id103out_result[getCycle()%9];

    id104out_result[(getCycle()+12)%13] = (add_float(id104in_a,id104in_b));
  }
  { // Node ID: 57 (NodeInputMappedReg)
  }
  { // Node ID: 219 (NodeFIFO)
    const HWFloat<8,24> &id219in_input = id218out_output[getCycle()%5];

    id219out_output[(getCycle()+7)%8] = id219in_input;
  }
  HWFloat<8,24> id105out_output;

  { // Node ID: 105 (NodeStreamOffset)
    const HWFloat<8,24> &id105in_input = id219out_output[getCycle()%8];

    id105out_output = id105in_input;
  }
  { // Node ID: 220 (NodeFIFO)
    const HWFloat<8,24> &id220in_input = id219out_output[getCycle()%8];

    id220out_output[(getCycle()+6)%7] = id220in_input;
  }
  HWFloat<8,24> id106out_output;

  { // Node ID: 106 (NodeStreamOffset)
    const HWFloat<8,24> &id106in_input = id220out_output[getCycle()%7];

    id106out_output = id106in_input;
  }
  { // Node ID: 107 (NodeAdd)
    const HWFloat<8,24> &id107in_a = id105out_output;
    const HWFloat<8,24> &id107in_b = id106out_output;

    id107out_result[(getCycle()+12)%13] = (add_float(id107in_a,id107in_b));
  }
  { // Node ID: 108 (NodeMul)
    const HWFloat<8,24> &id108in_a = id57out_c_2_2;
    const HWFloat<8,24> &id108in_b = id107out_result[getCycle()%13];

    id108out_result[(getCycle()+8)%9] = (mul_float(id108in_a,id108in_b));
  }
  { // Node ID: 109 (NodeAdd)
    const HWFloat<8,24> &id109in_a = id104out_result[getCycle()%13];
    const HWFloat<8,24> &id109in_b = id108out_result[getCycle()%9];

    id109out_result[(getCycle()+12)%13] = (add_float(id109in_a,id109in_b));
  }
  { // Node ID: 58 (NodeInputMappedReg)
  }
  { // Node ID: 221 (NodeFIFO)
    const HWFloat<8,24> &id221in_input = id220out_output[getCycle()%7];

    id221out_output[(getCycle()+3)%4] = id221in_input;
  }
  { // Node ID: 222 (NodeFIFO)
    const HWFloat<8,24> &id222in_input = id221out_output[getCycle()%4];

    id222out_output[(getCycle()+2)%3] = id222in_input;
  }
  HWFloat<8,24> id110out_output;

  { // Node ID: 110 (NodeStreamOffset)
    const HWFloat<8,24> &id110in_input = id222out_output[getCycle()%3];

    id110out_output = id110in_input;
  }
  { // Node ID: 223 (NodeFIFO)
    const HWFloat<8,24> &id223in_input = id222out_output[getCycle()%3];

    id223out_output[(getCycle()+8)%9] = id223in_input;
  }
  HWFloat<8,24> id111out_output;

  { // Node ID: 111 (NodeStreamOffset)
    const HWFloat<8,24> &id111in_input = id223out_output[getCycle()%9];

    id111out_output = id111in_input;
  }
  { // Node ID: 112 (NodeAdd)
    const HWFloat<8,24> &id112in_a = id110out_output;
    const HWFloat<8,24> &id112in_b = id111out_output;

    id112out_result[(getCycle()+12)%13] = (add_float(id112in_a,id112in_b));
  }
  { // Node ID: 113 (NodeMul)
    const HWFloat<8,24> &id113in_a = id58out_c_2_3;
    const HWFloat<8,24> &id113in_b = id112out_result[getCycle()%13];

    id113out_result[(getCycle()+8)%9] = (mul_float(id113in_a,id113in_b));
  }
  { // Node ID: 114 (NodeAdd)
    const HWFloat<8,24> &id114in_a = id109out_result[getCycle()%13];
    const HWFloat<8,24> &id114in_b = id113out_result[getCycle()%9];

    id114out_result[(getCycle()+12)%13] = (add_float(id114in_a,id114in_b));
  }
  { // Node ID: 59 (NodeInputMappedReg)
  }
  HWFloat<8,24> id115out_output;

  { // Node ID: 115 (NodeStreamOffset)
    const HWFloat<8,24> &id115in_input = id223out_output[getCycle()%9];

    id115out_output = id115in_input;
  }
  { // Node ID: 116 (NodeAdd)
    const HWFloat<8,24> &id116in_a = id221out_output[getCycle()%4];
    const HWFloat<8,24> &id116in_b = id115out_output;

    id116out_result[(getCycle()+12)%13] = (add_float(id116in_a,id116in_b));
  }
  { // Node ID: 117 (NodeMul)
    const HWFloat<8,24> &id117in_a = id59out_c_2_4;
    const HWFloat<8,24> &id117in_b = id116out_result[getCycle()%13];

    id117out_result[(getCycle()+8)%9] = (mul_float(id117in_a,id117in_b));
  }
  { // Node ID: 192 (NodeFIFO)
    const HWFloat<8,24> &id192in_input = id117out_result[getCycle()%9];

    id192out_output[(getCycle()+13)%14] = id192in_input;
  }
  { // Node ID: 118 (NodeAdd)
    const HWFloat<8,24> &id118in_a = id114out_result[getCycle()%13];
    const HWFloat<8,24> &id118in_b = id192out_output[getCycle()%14];

    id118out_result[(getCycle()+12)%13] = (add_float(id118in_a,id118in_b));
  }
  { // Node ID: 60 (NodeInputMappedReg)
  }
  { // Node ID: 35 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id36out_result;

  { // Node ID: 36 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id36in_a = id35out_io_px_force_disabled;

    id36out_result = (not_fixed(id36in_a));
  }
  if ( (getFillLevel() >= (134l)))
  { // Node ID: 37 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id37in_enable = id36out_result;

    (id37st_read_next_cycle) = ((id37in_enable.getValueAsBool())&(!(((getFlushLevel())>=(134l))&(isFlushingActive()))));
    queueReadRequest(m_px, id37st_read_next_cycle.getValueAsBool());
  }
  HWFloat<8,24> id119out_output;

  { // Node ID: 119 (NodeStreamOffset)
    const HWFloat<8,24> &id119in_input = id37out_data;

    id119out_output = id119in_input;
  }
  { // Node ID: 193 (NodeFIFO)
    const HWFloat<8,24> &id193in_input = id37out_data;

    id193out_output[(getCycle()+2)%3] = id193in_input;
  }
  HWFloat<8,24> id120out_output;

  { // Node ID: 120 (NodeStreamOffset)
    const HWFloat<8,24> &id120in_input = id193out_output[getCycle()%3];

    id120out_output = id120in_input;
  }
  { // Node ID: 121 (NodeAdd)
    const HWFloat<8,24> &id121in_a = id119out_output;
    const HWFloat<8,24> &id121in_b = id120out_output;

    id121out_result[(getCycle()+12)%13] = (add_float(id121in_a,id121in_b));
  }
  { // Node ID: 122 (NodeMul)
    const HWFloat<8,24> &id122in_a = id60out_c_3_0;
    const HWFloat<8,24> &id122in_b = id121out_result[getCycle()%13];

    id122out_result[(getCycle()+8)%9] = (mul_float(id122in_a,id122in_b));
  }
  { // Node ID: 123 (NodeAdd)
    const HWFloat<8,24> &id123in_a = id118out_result[getCycle()%13];
    const HWFloat<8,24> &id123in_b = id122out_result[getCycle()%9];

    id123out_result[(getCycle()+12)%13] = (add_float(id123in_a,id123in_b));
  }
  { // Node ID: 61 (NodeInputMappedReg)
  }
  { // Node ID: 224 (NodeFIFO)
    const HWFloat<8,24> &id224in_input = id193out_output[getCycle()%3];

    id224out_output[(getCycle()+9)%10] = id224in_input;
  }
  HWFloat<8,24> id124out_output;

  { // Node ID: 124 (NodeStreamOffset)
    const HWFloat<8,24> &id124in_input = id224out_output[getCycle()%10];

    id124out_output = id124in_input;
  }
  { // Node ID: 225 (NodeFIFO)
    const HWFloat<8,24> &id225in_input = id224out_output[getCycle()%10];

    id225out_output[(getCycle()+4)%5] = id225in_input;
  }
  HWFloat<8,24> id125out_output;

  { // Node ID: 125 (NodeStreamOffset)
    const HWFloat<8,24> &id125in_input = id225out_output[getCycle()%5];

    id125out_output = id125in_input;
  }
  { // Node ID: 126 (NodeAdd)
    const HWFloat<8,24> &id126in_a = id124out_output;
    const HWFloat<8,24> &id126in_b = id125out_output;

    id126out_result[(getCycle()+12)%13] = (add_float(id126in_a,id126in_b));
  }
  { // Node ID: 127 (NodeMul)
    const HWFloat<8,24> &id127in_a = id61out_c_3_1;
    const HWFloat<8,24> &id127in_b = id126out_result[getCycle()%13];

    id127out_result[(getCycle()+8)%9] = (mul_float(id127in_a,id127in_b));
  }
  { // Node ID: 128 (NodeAdd)
    const HWFloat<8,24> &id128in_a = id123out_result[getCycle()%13];
    const HWFloat<8,24> &id128in_b = id127out_result[getCycle()%9];

    id128out_result[(getCycle()+12)%13] = (add_float(id128in_a,id128in_b));
  }
  { // Node ID: 62 (NodeInputMappedReg)
  }
  { // Node ID: 226 (NodeFIFO)
    const HWFloat<8,24> &id226in_input = id225out_output[getCycle()%5];

    id226out_output[(getCycle()+7)%8] = id226in_input;
  }
  HWFloat<8,24> id129out_output;

  { // Node ID: 129 (NodeStreamOffset)
    const HWFloat<8,24> &id129in_input = id226out_output[getCycle()%8];

    id129out_output = id129in_input;
  }
  { // Node ID: 227 (NodeFIFO)
    const HWFloat<8,24> &id227in_input = id226out_output[getCycle()%8];

    id227out_output[(getCycle()+6)%7] = id227in_input;
  }
  HWFloat<8,24> id130out_output;

  { // Node ID: 130 (NodeStreamOffset)
    const HWFloat<8,24> &id130in_input = id227out_output[getCycle()%7];

    id130out_output = id130in_input;
  }
  { // Node ID: 131 (NodeAdd)
    const HWFloat<8,24> &id131in_a = id129out_output;
    const HWFloat<8,24> &id131in_b = id130out_output;

    id131out_result[(getCycle()+12)%13] = (add_float(id131in_a,id131in_b));
  }
  { // Node ID: 132 (NodeMul)
    const HWFloat<8,24> &id132in_a = id62out_c_3_2;
    const HWFloat<8,24> &id132in_b = id131out_result[getCycle()%13];

    id132out_result[(getCycle()+8)%9] = (mul_float(id132in_a,id132in_b));
  }
  { // Node ID: 133 (NodeAdd)
    const HWFloat<8,24> &id133in_a = id128out_result[getCycle()%13];
    const HWFloat<8,24> &id133in_b = id132out_result[getCycle()%9];

    id133out_result[(getCycle()+12)%13] = (add_float(id133in_a,id133in_b));
  }
  { // Node ID: 63 (NodeInputMappedReg)
  }
  { // Node ID: 228 (NodeFIFO)
    const HWFloat<8,24> &id228in_input = id227out_output[getCycle()%7];

    id228out_output[(getCycle()+3)%4] = id228in_input;
  }
  { // Node ID: 229 (NodeFIFO)
    const HWFloat<8,24> &id229in_input = id228out_output[getCycle()%4];

    id229out_output[(getCycle()+2)%3] = id229in_input;
  }
  HWFloat<8,24> id134out_output;

  { // Node ID: 134 (NodeStreamOffset)
    const HWFloat<8,24> &id134in_input = id229out_output[getCycle()%3];

    id134out_output = id134in_input;
  }
  { // Node ID: 230 (NodeFIFO)
    const HWFloat<8,24> &id230in_input = id229out_output[getCycle()%3];

    id230out_output[(getCycle()+8)%9] = id230in_input;
  }
  HWFloat<8,24> id135out_output;

  { // Node ID: 135 (NodeStreamOffset)
    const HWFloat<8,24> &id135in_input = id230out_output[getCycle()%9];

    id135out_output = id135in_input;
  }
  { // Node ID: 136 (NodeAdd)
    const HWFloat<8,24> &id136in_a = id134out_output;
    const HWFloat<8,24> &id136in_b = id135out_output;

    id136out_result[(getCycle()+12)%13] = (add_float(id136in_a,id136in_b));
  }
  { // Node ID: 137 (NodeMul)
    const HWFloat<8,24> &id137in_a = id63out_c_3_3;
    const HWFloat<8,24> &id137in_b = id136out_result[getCycle()%13];

    id137out_result[(getCycle()+8)%9] = (mul_float(id137in_a,id137in_b));
  }
  { // Node ID: 138 (NodeAdd)
    const HWFloat<8,24> &id138in_a = id133out_result[getCycle()%13];
    const HWFloat<8,24> &id138in_b = id137out_result[getCycle()%9];

    id138out_result[(getCycle()+12)%13] = (add_float(id138in_a,id138in_b));
  }
  { // Node ID: 64 (NodeInputMappedReg)
  }
  HWFloat<8,24> id139out_output;

  { // Node ID: 139 (NodeStreamOffset)
    const HWFloat<8,24> &id139in_input = id230out_output[getCycle()%9];

    id139out_output = id139in_input;
  }
  { // Node ID: 140 (NodeAdd)
    const HWFloat<8,24> &id140in_a = id228out_output[getCycle()%4];
    const HWFloat<8,24> &id140in_b = id139out_output;

    id140out_result[(getCycle()+12)%13] = (add_float(id140in_a,id140in_b));
  }
  { // Node ID: 141 (NodeMul)
    const HWFloat<8,24> &id141in_a = id64out_c_3_4;
    const HWFloat<8,24> &id141in_b = id140out_result[getCycle()%13];

    id141out_result[(getCycle()+8)%9] = (mul_float(id141in_a,id141in_b));
  }
  { // Node ID: 202 (NodeFIFO)
    const HWFloat<8,24> &id202in_input = id141out_result[getCycle()%9];

    id202out_output[(getCycle()+13)%14] = id202in_input;
  }
  { // Node ID: 142 (NodeAdd)
    const HWFloat<8,24> &id142in_a = id138out_result[getCycle()%13];
    const HWFloat<8,24> &id142in_b = id202out_output[getCycle()%14];

    id142out_result[(getCycle()+12)%13] = (add_float(id142in_a,id142in_b));
  }
  { // Node ID: 143 (NodeMul)
    const HWFloat<8,24> &id143in_a = id26out_data;
    const HWFloat<8,24> &id143in_b = id142out_result[getCycle()%13];

    id143out_result[(getCycle()+8)%9] = (mul_float(id143in_a,id143in_b));
  }
  { // Node ID: 144 (NodeAdd)
    const HWFloat<8,24> &id144in_a = id68out_result[getCycle()%13];
    const HWFloat<8,24> &id144in_b = id143out_result[getCycle()%9];

    id144out_result[(getCycle()+12)%13] = (add_float(id144in_a,id144in_b));
  }
  HWOffsetFix<1,0,UNSIGNED> id27out_o;

  { // Node ID: 27 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id27in_i = id2out_data;

    id27out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id27in_i));
  }
  { // Node ID: 203 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id203in_input = id27out_o;

    id203out_output[(getCycle()+158)%159] = id203in_input;
  }
  HWRawBits<1> id31out_output;

  { // Node ID: 31 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id31in_input = id203out_output[getCycle()%159];

    id31out_output = (cast_fixed2bits(id31in_input));
  }
  { // Node ID: 28 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id29out_result;

  { // Node ID: 29 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id29in_a = id28out_io_source_container_force_disabled;

    id29out_result = (not_fixed(id29in_a));
  }
  HWRawBits<1> id32out_output;

  { // Node ID: 32 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id32in_input = id29out_result;

    id32out_output = (cast_fixed2bits(id32in_input));
  }
  HWRawBits<1> id30out_result;

  { // Node ID: 30 (NodeAnd)
    const HWRawBits<1> &id30in_a = id31out_output;
    const HWRawBits<1> &id30in_b = id32out_output;

    HWRawBits<1> id30x_1;

    (id30x_1) = (and_bits(id30in_a,id30in_b));
    id30out_result = (id30x_1);
  }
  HWOffsetFix<1,0,UNSIGNED> id33out_output;

  { // Node ID: 33 (NodeReinterpret)
    const HWRawBits<1> &id33in_input = id30out_result;

    id33out_output = (cast_bits2fixed<1,0,UNSIGNED>(id33in_input));
  }
  { // Node ID: 204 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id204in_input = id33out_output;

    id204out_output[(getCycle()+63)%64] = id204in_input;
  }
  if ( (getFillLevel() >= (230l)))
  { // Node ID: 34 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id34in_enable = id204out_output[getCycle()%64];

    (id34st_read_next_cycle) = ((id34in_enable.getValueAsBool())&(!(((getFlushLevel())>=(230l))&(isFlushingActive()))));
    queueReadRequest(m_source_container, id34st_read_next_cycle.getValueAsBool());
  }
  { // Node ID: 145 (NodeAdd)
    const HWFloat<8,24> &id145in_a = id144out_result[getCycle()%13];
    const HWFloat<8,24> &id145in_b = id34out_data;

    id145out_result[(getCycle()+12)%13] = (add_float(id145in_a,id145in_b));
  }
  { // Node ID: 205 (NodeFIFO)
    const HWFloat<8,24> &id205in_input = id48out_data;

    id205out_output[(getCycle()+44)%45] = id205in_input;
  }
  { // Node ID: 146 (NodeMul)
    const HWFloat<8,24> &id146in_a = id145out_result[getCycle()%13];
    const HWFloat<8,24> &id146in_b = id205out_output[getCycle()%45];

    id146out_result[(getCycle()+8)%9] = (mul_float(id146in_a,id146in_b));
  }
  if ( (getFillLevel() >= (255l)) && (getFlushLevel() < (255l)|| !isFlushingActive() ))
  { // Node ID: 154 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id154in_output_control = id206out_output[getCycle()%89];
    const HWFloat<8,24> &id154in_data = id146out_result[getCycle()%9];

    bool id154x_1;

    (id154x_1) = ((id154in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(255l))&(isFlushingActive()))));
    if((id154x_1)) {
      writeOutput(m_ppresult, id154in_data);
    }
  }
  { // Node ID: 158 (NodeConstantRawBits)
  }
  { // Node ID: 231 (NodeConstantRawBits)
  }
  { // Node ID: 156 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 157 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id157in_enable = id231out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id157in_max = id156out_value;

    HWOffsetFix<49,0,UNSIGNED> id157x_1;
    HWOffsetFix<1,0,UNSIGNED> id157x_2;
    HWOffsetFix<1,0,UNSIGNED> id157x_3;
    HWOffsetFix<49,0,UNSIGNED> id157x_4t_1e_1;

    id157out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id157st_count)));
    (id157x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id157st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id157x_2) = (gte_fixed((id157x_1),id157in_max));
    (id157x_3) = (and_fixed((id157x_2),id157in_enable));
    id157out_wrap = (id157x_3);
    if((id157in_enable.getValueAsBool())) {
      if(((id157x_3).getValueAsBool())) {
        (id157st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id157x_4t_1e_1) = (id157x_1);
        (id157st_count) = (id157x_4t_1e_1);
      }
    }
    else {
    }
  }
  { // Node ID: 207 (NodeFIFO)
    const HWOffsetFix<48,0,UNSIGNED> &id207in_input = id157out_count;

    id207out_output[(getCycle()+4)%5] = id207in_input;
  }
  if ( (getFillLevel() >= (4l)) && (getFlushLevel() < (4l)|| !isFlushingActive() ))
  { // Node ID: 159 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id159in_load = id158out_value;
    const HWOffsetFix<48,0,UNSIGNED> &id159in_data = id207out_output[getCycle()%5];

    bool id159x_1;

    (id159x_1) = ((id159in_load.getValueAsBool())&(!(((getFlushLevel())>=(4l))&(isFlushingActive()))));
    if((id159x_1)) {
      setMappedRegValue("current_run_cycle_count", id159in_data);
    }
  }
  { // Node ID: 161 (NodeInputMappedReg)
  }
  { // Node ID: 162 (NodeEq)
    const HWOffsetFix<48,0,UNSIGNED> &id162in_a = id157out_count;
    const HWOffsetFix<48,0,UNSIGNED> &id162in_b = id161out_run_cycle_count;

    id162out_result[(getCycle()+1)%2] = (eq_fixed(id162in_a,id162in_b));
  }
  if ( (getFillLevel() >= (1l)))
  { // Node ID: 160 (NodeFlush)
    const HWOffsetFix<1,0,UNSIGNED> &id160in_start = id162out_result[getCycle()%2];

    if((id160in_start.getValueAsBool())) {
      startFlushing();
    }
  }
};

};
