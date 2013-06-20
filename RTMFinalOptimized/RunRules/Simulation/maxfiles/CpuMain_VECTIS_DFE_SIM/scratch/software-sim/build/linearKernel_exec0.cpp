#include "stdsimheader.h"
//#define BOOST_NO_STD_LOCALE
//#include <boost/format.hpp>

//#include "linearKernel.h"

namespace maxcompilersim {

void linearKernel::execute0() {
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
  HWOffsetFix<1,0,UNSIGNED> id137out_o;

  { // Node ID: 137 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id137in_i = id2out_data;

    id137out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id137in_i));
  }
  { // Node ID: 154 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id154in_input = id137out_o;

    id154out_output[(getCycle()+111)%112] = id154in_input;
  }
  HWRawBits<1> id141out_output;

  { // Node ID: 141 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id141in_input = id154out_output[getCycle()%112];

    id141out_output = (cast_fixed2bits(id141in_input));
  }
  { // Node ID: 138 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id139out_result;

  { // Node ID: 139 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id139in_a = id138out_io_ppresult_force_disabled;

    id139out_result = (not_fixed(id139in_a));
  }
  HWRawBits<1> id142out_output;

  { // Node ID: 142 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id142in_input = id139out_result;

    id142out_output = (cast_fixed2bits(id142in_input));
  }
  HWRawBits<1> id140out_result;

  { // Node ID: 140 (NodeAnd)
    const HWRawBits<1> &id140in_a = id141out_output;
    const HWRawBits<1> &id140in_b = id142out_output;

    HWRawBits<1> id140x_1;

    (id140x_1) = (and_bits(id140in_a,id140in_b));
    id140out_result = (id140x_1);
  }
  HWOffsetFix<1,0,UNSIGNED> id143out_output;

  { // Node ID: 143 (NodeReinterpret)
    const HWRawBits<1> &id143in_input = id140out_result;

    id143out_output = (cast_bits2fixed<1,0,UNSIGNED>(id143in_input));
  }
  { // Node ID: 192 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id192in_input = id143out_output;

    id192out_output[(getCycle()+127)%128] = id192in_input;
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
  { // Node ID: 160 (NodeFIFO)
    const HWFloat<8,24> &id160in_input = id10out_data;

    id160out_output[(getCycle()+2)%3] = id160in_input;
  }
  { // Node ID: 194 (NodeFIFO)
    const HWFloat<8,24> &id194in_input = id160out_output[getCycle()%3];

    id194out_output[(getCycle()+9)%10] = id194in_input;
  }
  { // Node ID: 195 (NodeFIFO)
    const HWFloat<8,24> &id195in_input = id194out_output[getCycle()%10];

    id195out_output[(getCycle()+2)%3] = id195in_input;
  }
  { // Node ID: 196 (NodeFIFO)
    const HWFloat<8,24> &id196in_input = id195out_output[getCycle()%3];

    id196out_output[(getCycle()+2)%3] = id196in_input;
  }
  { // Node ID: 197 (NodeFIFO)
    const HWFloat<8,24> &id197in_input = id196out_output[getCycle()%3];

    id197out_output[(getCycle()+7)%8] = id197in_input;
  }
  { // Node ID: 198 (NodeFIFO)
    const HWFloat<8,24> &id198in_input = id197out_output[getCycle()%8];

    id198out_output[(getCycle()+6)%7] = id198in_input;
  }
  { // Node ID: 199 (NodeFIFO)
    const HWFloat<8,24> &id199in_input = id198out_output[getCycle()%7];

    id199out_output[(getCycle()+5)%6] = id199in_input;
  }
  { // Node ID: 200 (NodeFIFO)
    const HWFloat<8,24> &id200in_input = id199out_output[getCycle()%6];

    id200out_output[(getCycle()+8)%9] = id200in_input;
  }
  { // Node ID: 201 (NodeFIFO)
    const HWFloat<8,24> &id201in_input = id200out_output[getCycle()%9];

    id201out_output[(getCycle()+3)%4] = id201in_input;
  }
  { // Node ID: 202 (NodeFIFO)
    const HWFloat<8,24> &id202in_input = id201out_output[getCycle()%4];

    id202out_output[(getCycle()+10)%11] = id202in_input;
  }
  { // Node ID: 153 (NodePO2FPMult)
    const HWFloat<8,24> &id153in_floatIn = id202out_output[getCycle()%11];

    id153out_floatOut[(getCycle()+1)%2] = (mul_float(id153in_floatIn,(c_hw_flt_8_24_2_0val)));
  }
  HWOffsetFix<1,0,UNSIGNED> id11out_o;

  { // Node ID: 11 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id11in_i = id2out_data;

    id11out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id11in_i));
  }
  { // Node ID: 156 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id156in_input = id11out_o;

    id156out_output[(getCycle()+55)%56] = id156in_input;
  }
  HWRawBits<1> id15out_output;

  { // Node ID: 15 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id15in_input = id156out_output[getCycle()%56];

    id15out_output = (cast_fixed2bits(id15in_input));
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
  if ( (getFillLevel() >= (64l)))
  { // Node ID: 18 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id18in_enable = id17out_output;

    (id18st_read_next_cycle) = ((id18in_enable.getValueAsBool())&(!(((getFlushLevel())>=(64l))&(isFlushingActive()))));
    queueReadRequest(m_pp, id18st_read_next_cycle.getValueAsBool());
  }
  { // Node ID: 59 (NodeSub)
    const HWFloat<8,24> &id59in_a = id153out_floatOut[getCycle()%2];
    const HWFloat<8,24> &id59in_b = id18out_data;

    id59out_result[(getCycle()+12)%13] = (sub_float(id59in_a,id59in_b));
  }
  { // Node ID: 189 (NodeFIFO)
    const HWFloat<8,24> &id189in_input = id59out_result[getCycle()%13];

    id189out_output[(getCycle()+142)%143] = id189in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id19out_o;

  { // Node ID: 19 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id19in_i = id2out_data;

    id19out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id19in_i));
  }
  { // Node ID: 157 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id157in_input = id19out_o;

    id157out_output[(getCycle()+111)%112] = id157in_input;
  }
  HWRawBits<1> id23out_output;

  { // Node ID: 23 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id23in_input = id157out_output[getCycle()%112];

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
  HWOffsetFix<1,0,UNSIGNED> id25out_output;

  { // Node ID: 25 (NodeReinterpret)
    const HWRawBits<1> &id25in_input = id22out_result;

    id25out_output = (cast_bits2fixed<1,0,UNSIGNED>(id25in_input));
  }
  { // Node ID: 158 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id158in_input = id25out_output;

    id158out_output[(getCycle()+90)%91] = id158in_input;
  }
  if ( (getFillLevel() >= (210l)))
  { // Node ID: 26 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id26in_enable = id158out_output[getCycle()%91];

    (id26st_read_next_cycle) = ((id26in_enable.getValueAsBool())&(!(((getFlushLevel())>=(210l))&(isFlushingActive()))));
    queueReadRequest(m_dvv, id26st_read_next_cycle.getValueAsBool());
  }
  { // Node ID: 41 (NodeInputMappedReg)
  }
  { // Node ID: 60 (NodeMul)
    const HWFloat<8,24> &id60in_a = id195out_output[getCycle()%3];
    const HWFloat<8,24> &id60in_b = id41out_c_0;

    id60out_result[(getCycle()+8)%9] = (mul_float(id60in_a,id60in_b));
  }
  { // Node ID: 42 (NodeInputMappedReg)
  }
  HWFloat<8,24> id61out_output;

  { // Node ID: 61 (NodeStreamOffset)
    const HWFloat<8,24> &id61in_input = id10out_data;

    id61out_output = id61in_input;
  }
  HWFloat<8,24> id62out_output;

  { // Node ID: 62 (NodeStreamOffset)
    const HWFloat<8,24> &id62in_input = id160out_output[getCycle()%3];

    id62out_output = id62in_input;
  }
  { // Node ID: 63 (NodeAdd)
    const HWFloat<8,24> &id63in_a = id61out_output;
    const HWFloat<8,24> &id63in_b = id62out_output;

    id63out_result[(getCycle()+12)%13] = (add_float(id63in_a,id63in_b));
  }
  { // Node ID: 64 (NodeMul)
    const HWFloat<8,24> &id64in_a = id42out_c_1_0;
    const HWFloat<8,24> &id64in_b = id63out_result[getCycle()%13];

    id64out_result[(getCycle()+8)%9] = (mul_float(id64in_a,id64in_b));
  }
  { // Node ID: 65 (NodeAdd)
    const HWFloat<8,24> &id65in_a = id60out_result[getCycle()%9];
    const HWFloat<8,24> &id65in_b = id64out_result[getCycle()%9];

    id65out_result[(getCycle()+12)%13] = (add_float(id65in_a,id65in_b));
  }
  { // Node ID: 43 (NodeInputMappedReg)
  }
  HWFloat<8,24> id66out_output;

  { // Node ID: 66 (NodeStreamOffset)
    const HWFloat<8,24> &id66in_input = id194out_output[getCycle()%10];

    id66out_output = id66in_input;
  }
  HWFloat<8,24> id67out_output;

  { // Node ID: 67 (NodeStreamOffset)
    const HWFloat<8,24> &id67in_input = id196out_output[getCycle()%3];

    id67out_output = id67in_input;
  }
  { // Node ID: 68 (NodeAdd)
    const HWFloat<8,24> &id68in_a = id66out_output;
    const HWFloat<8,24> &id68in_b = id67out_output;

    id68out_result[(getCycle()+12)%13] = (add_float(id68in_a,id68in_b));
  }
  { // Node ID: 69 (NodeMul)
    const HWFloat<8,24> &id69in_a = id43out_c_1_1;
    const HWFloat<8,24> &id69in_b = id68out_result[getCycle()%13];

    id69out_result[(getCycle()+8)%9] = (mul_float(id69in_a,id69in_b));
  }
  { // Node ID: 70 (NodeAdd)
    const HWFloat<8,24> &id70in_a = id65out_result[getCycle()%13];
    const HWFloat<8,24> &id70in_b = id69out_result[getCycle()%9];

    id70out_result[(getCycle()+12)%13] = (add_float(id70in_a,id70in_b));
  }
  { // Node ID: 44 (NodeInputMappedReg)
  }
  HWFloat<8,24> id71out_output;

  { // Node ID: 71 (NodeStreamOffset)
    const HWFloat<8,24> &id71in_input = id197out_output[getCycle()%8];

    id71out_output = id71in_input;
  }
  HWFloat<8,24> id72out_output;

  { // Node ID: 72 (NodeStreamOffset)
    const HWFloat<8,24> &id72in_input = id198out_output[getCycle()%7];

    id72out_output = id72in_input;
  }
  { // Node ID: 73 (NodeAdd)
    const HWFloat<8,24> &id73in_a = id71out_output;
    const HWFloat<8,24> &id73in_b = id72out_output;

    id73out_result[(getCycle()+12)%13] = (add_float(id73in_a,id73in_b));
  }
  { // Node ID: 74 (NodeMul)
    const HWFloat<8,24> &id74in_a = id44out_c_1_2;
    const HWFloat<8,24> &id74in_b = id73out_result[getCycle()%13];

    id74out_result[(getCycle()+8)%9] = (mul_float(id74in_a,id74in_b));
  }
  { // Node ID: 75 (NodeAdd)
    const HWFloat<8,24> &id75in_a = id70out_result[getCycle()%13];
    const HWFloat<8,24> &id75in_b = id74out_result[getCycle()%9];

    id75out_result[(getCycle()+12)%13] = (add_float(id75in_a,id75in_b));
  }
  { // Node ID: 45 (NodeInputMappedReg)
  }
  HWFloat<8,24> id76out_output;

  { // Node ID: 76 (NodeStreamOffset)
    const HWFloat<8,24> &id76in_input = id199out_output[getCycle()%6];

    id76out_output = id76in_input;
  }
  HWFloat<8,24> id77out_output;

  { // Node ID: 77 (NodeStreamOffset)
    const HWFloat<8,24> &id77in_input = id200out_output[getCycle()%9];

    id77out_output = id77in_input;
  }
  { // Node ID: 78 (NodeAdd)
    const HWFloat<8,24> &id78in_a = id76out_output;
    const HWFloat<8,24> &id78in_b = id77out_output;

    id78out_result[(getCycle()+12)%13] = (add_float(id78in_a,id78in_b));
  }
  { // Node ID: 79 (NodeMul)
    const HWFloat<8,24> &id79in_a = id45out_c_1_3;
    const HWFloat<8,24> &id79in_b = id78out_result[getCycle()%13];

    id79out_result[(getCycle()+8)%9] = (mul_float(id79in_a,id79in_b));
  }
  { // Node ID: 80 (NodeAdd)
    const HWFloat<8,24> &id80in_a = id75out_result[getCycle()%13];
    const HWFloat<8,24> &id80in_b = id79out_result[getCycle()%9];

    id80out_result[(getCycle()+12)%13] = (add_float(id80in_a,id80in_b));
  }
  { // Node ID: 46 (NodeInputMappedReg)
  }
  HWFloat<8,24> id81out_output;

  { // Node ID: 81 (NodeStreamOffset)
    const HWFloat<8,24> &id81in_input = id201out_output[getCycle()%4];

    id81out_output = id81in_input;
  }
  HWFloat<8,24> id82out_output;

  { // Node ID: 82 (NodeStreamOffset)
    const HWFloat<8,24> &id82in_input = id202out_output[getCycle()%11];

    id82out_output = id82in_input;
  }
  { // Node ID: 83 (NodeAdd)
    const HWFloat<8,24> &id83in_a = id81out_output;
    const HWFloat<8,24> &id83in_b = id82out_output;

    id83out_result[(getCycle()+12)%13] = (add_float(id83in_a,id83in_b));
  }
  { // Node ID: 84 (NodeMul)
    const HWFloat<8,24> &id84in_a = id46out_c_1_4;
    const HWFloat<8,24> &id84in_b = id83out_result[getCycle()%13];

    id84out_result[(getCycle()+8)%9] = (mul_float(id84in_a,id84in_b));
  }
  { // Node ID: 85 (NodeAdd)
    const HWFloat<8,24> &id85in_a = id80out_result[getCycle()%13];
    const HWFloat<8,24> &id85in_b = id84out_result[getCycle()%9];

    id85out_result[(getCycle()+12)%13] = (add_float(id85in_a,id85in_b));
  }
  { // Node ID: 47 (NodeInputMappedReg)
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
  HWFloat<8,24> id86out_output;

  { // Node ID: 86 (NodeStreamOffset)
    const HWFloat<8,24> &id86in_input = id40out_data;

    id86out_output = id86in_input;
  }
  { // Node ID: 169 (NodeFIFO)
    const HWFloat<8,24> &id169in_input = id40out_data;

    id169out_output[(getCycle()+2)%3] = id169in_input;
  }
  HWFloat<8,24> id87out_output;

  { // Node ID: 87 (NodeStreamOffset)
    const HWFloat<8,24> &id87in_input = id169out_output[getCycle()%3];

    id87out_output = id87in_input;
  }
  { // Node ID: 88 (NodeAdd)
    const HWFloat<8,24> &id88in_a = id86out_output;
    const HWFloat<8,24> &id88in_b = id87out_output;

    id88out_result[(getCycle()+12)%13] = (add_float(id88in_a,id88in_b));
  }
  { // Node ID: 89 (NodeMul)
    const HWFloat<8,24> &id89in_a = id47out_c_2_0;
    const HWFloat<8,24> &id89in_b = id88out_result[getCycle()%13];

    id89out_result[(getCycle()+8)%9] = (mul_float(id89in_a,id89in_b));
  }
  { // Node ID: 90 (NodeAdd)
    const HWFloat<8,24> &id90in_a = id85out_result[getCycle()%13];
    const HWFloat<8,24> &id90in_b = id89out_result[getCycle()%9];

    id90out_result[(getCycle()+12)%13] = (add_float(id90in_a,id90in_b));
  }
  { // Node ID: 48 (NodeInputMappedReg)
  }
  { // Node ID: 203 (NodeFIFO)
    const HWFloat<8,24> &id203in_input = id169out_output[getCycle()%3];

    id203out_output[(getCycle()+9)%10] = id203in_input;
  }
  HWFloat<8,24> id91out_output;

  { // Node ID: 91 (NodeStreamOffset)
    const HWFloat<8,24> &id91in_input = id203out_output[getCycle()%10];

    id91out_output = id91in_input;
  }
  { // Node ID: 204 (NodeFIFO)
    const HWFloat<8,24> &id204in_input = id203out_output[getCycle()%10];

    id204out_output[(getCycle()+4)%5] = id204in_input;
  }
  HWFloat<8,24> id92out_output;

  { // Node ID: 92 (NodeStreamOffset)
    const HWFloat<8,24> &id92in_input = id204out_output[getCycle()%5];

    id92out_output = id92in_input;
  }
  { // Node ID: 93 (NodeAdd)
    const HWFloat<8,24> &id93in_a = id91out_output;
    const HWFloat<8,24> &id93in_b = id92out_output;

    id93out_result[(getCycle()+12)%13] = (add_float(id93in_a,id93in_b));
  }
  { // Node ID: 94 (NodeMul)
    const HWFloat<8,24> &id94in_a = id48out_c_2_1;
    const HWFloat<8,24> &id94in_b = id93out_result[getCycle()%13];

    id94out_result[(getCycle()+8)%9] = (mul_float(id94in_a,id94in_b));
  }
  { // Node ID: 95 (NodeAdd)
    const HWFloat<8,24> &id95in_a = id90out_result[getCycle()%13];
    const HWFloat<8,24> &id95in_b = id94out_result[getCycle()%9];

    id95out_result[(getCycle()+12)%13] = (add_float(id95in_a,id95in_b));
  }
  { // Node ID: 49 (NodeInputMappedReg)
  }
  { // Node ID: 205 (NodeFIFO)
    const HWFloat<8,24> &id205in_input = id204out_output[getCycle()%5];

    id205out_output[(getCycle()+7)%8] = id205in_input;
  }
  HWFloat<8,24> id96out_output;

  { // Node ID: 96 (NodeStreamOffset)
    const HWFloat<8,24> &id96in_input = id205out_output[getCycle()%8];

    id96out_output = id96in_input;
  }
  { // Node ID: 206 (NodeFIFO)
    const HWFloat<8,24> &id206in_input = id205out_output[getCycle()%8];

    id206out_output[(getCycle()+6)%7] = id206in_input;
  }
  HWFloat<8,24> id97out_output;

  { // Node ID: 97 (NodeStreamOffset)
    const HWFloat<8,24> &id97in_input = id206out_output[getCycle()%7];

    id97out_output = id97in_input;
  }
  { // Node ID: 98 (NodeAdd)
    const HWFloat<8,24> &id98in_a = id96out_output;
    const HWFloat<8,24> &id98in_b = id97out_output;

    id98out_result[(getCycle()+12)%13] = (add_float(id98in_a,id98in_b));
  }
  { // Node ID: 99 (NodeMul)
    const HWFloat<8,24> &id99in_a = id49out_c_2_2;
    const HWFloat<8,24> &id99in_b = id98out_result[getCycle()%13];

    id99out_result[(getCycle()+8)%9] = (mul_float(id99in_a,id99in_b));
  }
  { // Node ID: 100 (NodeAdd)
    const HWFloat<8,24> &id100in_a = id95out_result[getCycle()%13];
    const HWFloat<8,24> &id100in_b = id99out_result[getCycle()%9];

    id100out_result[(getCycle()+12)%13] = (add_float(id100in_a,id100in_b));
  }
  { // Node ID: 50 (NodeInputMappedReg)
  }
  { // Node ID: 207 (NodeFIFO)
    const HWFloat<8,24> &id207in_input = id206out_output[getCycle()%7];

    id207out_output[(getCycle()+3)%4] = id207in_input;
  }
  { // Node ID: 208 (NodeFIFO)
    const HWFloat<8,24> &id208in_input = id207out_output[getCycle()%4];

    id208out_output[(getCycle()+2)%3] = id208in_input;
  }
  HWFloat<8,24> id101out_output;

  { // Node ID: 101 (NodeStreamOffset)
    const HWFloat<8,24> &id101in_input = id208out_output[getCycle()%3];

    id101out_output = id101in_input;
  }
  { // Node ID: 209 (NodeFIFO)
    const HWFloat<8,24> &id209in_input = id208out_output[getCycle()%3];

    id209out_output[(getCycle()+8)%9] = id209in_input;
  }
  HWFloat<8,24> id102out_output;

  { // Node ID: 102 (NodeStreamOffset)
    const HWFloat<8,24> &id102in_input = id209out_output[getCycle()%9];

    id102out_output = id102in_input;
  }
  { // Node ID: 103 (NodeAdd)
    const HWFloat<8,24> &id103in_a = id101out_output;
    const HWFloat<8,24> &id103in_b = id102out_output;

    id103out_result[(getCycle()+12)%13] = (add_float(id103in_a,id103in_b));
  }
  { // Node ID: 104 (NodeMul)
    const HWFloat<8,24> &id104in_a = id50out_c_2_3;
    const HWFloat<8,24> &id104in_b = id103out_result[getCycle()%13];

    id104out_result[(getCycle()+8)%9] = (mul_float(id104in_a,id104in_b));
  }
  { // Node ID: 105 (NodeAdd)
    const HWFloat<8,24> &id105in_a = id100out_result[getCycle()%13];
    const HWFloat<8,24> &id105in_b = id104out_result[getCycle()%9];

    id105out_result[(getCycle()+12)%13] = (add_float(id105in_a,id105in_b));
  }
  { // Node ID: 51 (NodeInputMappedReg)
  }
  HWFloat<8,24> id106out_output;

  { // Node ID: 106 (NodeStreamOffset)
    const HWFloat<8,24> &id106in_input = id209out_output[getCycle()%9];

    id106out_output = id106in_input;
  }
  { // Node ID: 107 (NodeAdd)
    const HWFloat<8,24> &id107in_a = id207out_output[getCycle()%4];
    const HWFloat<8,24> &id107in_b = id106out_output;

    id107out_result[(getCycle()+12)%13] = (add_float(id107in_a,id107in_b));
  }
  { // Node ID: 108 (NodeMul)
    const HWFloat<8,24> &id108in_a = id51out_c_2_4;
    const HWFloat<8,24> &id108in_b = id107out_result[getCycle()%13];

    id108out_result[(getCycle()+8)%9] = (mul_float(id108in_a,id108in_b));
  }
  { // Node ID: 178 (NodeFIFO)
    const HWFloat<8,24> &id178in_input = id108out_result[getCycle()%9];

    id178out_output[(getCycle()+13)%14] = id178in_input;
  }
  { // Node ID: 109 (NodeAdd)
    const HWFloat<8,24> &id109in_a = id105out_result[getCycle()%13];
    const HWFloat<8,24> &id109in_b = id178out_output[getCycle()%14];

    id109out_result[(getCycle()+12)%13] = (add_float(id109in_a,id109in_b));
  }
  { // Node ID: 52 (NodeInputMappedReg)
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
  HWFloat<8,24> id110out_output;

  { // Node ID: 110 (NodeStreamOffset)
    const HWFloat<8,24> &id110in_input = id37out_data;

    id110out_output = id110in_input;
  }
  { // Node ID: 179 (NodeFIFO)
    const HWFloat<8,24> &id179in_input = id37out_data;

    id179out_output[(getCycle()+2)%3] = id179in_input;
  }
  HWFloat<8,24> id111out_output;

  { // Node ID: 111 (NodeStreamOffset)
    const HWFloat<8,24> &id111in_input = id179out_output[getCycle()%3];

    id111out_output = id111in_input;
  }
  { // Node ID: 112 (NodeAdd)
    const HWFloat<8,24> &id112in_a = id110out_output;
    const HWFloat<8,24> &id112in_b = id111out_output;

    id112out_result[(getCycle()+12)%13] = (add_float(id112in_a,id112in_b));
  }
  { // Node ID: 113 (NodeMul)
    const HWFloat<8,24> &id113in_a = id52out_c_3_0;
    const HWFloat<8,24> &id113in_b = id112out_result[getCycle()%13];

    id113out_result[(getCycle()+8)%9] = (mul_float(id113in_a,id113in_b));
  }
  { // Node ID: 114 (NodeAdd)
    const HWFloat<8,24> &id114in_a = id109out_result[getCycle()%13];
    const HWFloat<8,24> &id114in_b = id113out_result[getCycle()%9];

    id114out_result[(getCycle()+12)%13] = (add_float(id114in_a,id114in_b));
  }
  { // Node ID: 53 (NodeInputMappedReg)
  }
  { // Node ID: 210 (NodeFIFO)
    const HWFloat<8,24> &id210in_input = id179out_output[getCycle()%3];

    id210out_output[(getCycle()+9)%10] = id210in_input;
  }
  HWFloat<8,24> id115out_output;

  { // Node ID: 115 (NodeStreamOffset)
    const HWFloat<8,24> &id115in_input = id210out_output[getCycle()%10];

    id115out_output = id115in_input;
  }
  { // Node ID: 211 (NodeFIFO)
    const HWFloat<8,24> &id211in_input = id210out_output[getCycle()%10];

    id211out_output[(getCycle()+4)%5] = id211in_input;
  }
  HWFloat<8,24> id116out_output;

  { // Node ID: 116 (NodeStreamOffset)
    const HWFloat<8,24> &id116in_input = id211out_output[getCycle()%5];

    id116out_output = id116in_input;
  }
  { // Node ID: 117 (NodeAdd)
    const HWFloat<8,24> &id117in_a = id115out_output;
    const HWFloat<8,24> &id117in_b = id116out_output;

    id117out_result[(getCycle()+12)%13] = (add_float(id117in_a,id117in_b));
  }
  { // Node ID: 118 (NodeMul)
    const HWFloat<8,24> &id118in_a = id53out_c_3_1;
    const HWFloat<8,24> &id118in_b = id117out_result[getCycle()%13];

    id118out_result[(getCycle()+8)%9] = (mul_float(id118in_a,id118in_b));
  }
  { // Node ID: 119 (NodeAdd)
    const HWFloat<8,24> &id119in_a = id114out_result[getCycle()%13];
    const HWFloat<8,24> &id119in_b = id118out_result[getCycle()%9];

    id119out_result[(getCycle()+12)%13] = (add_float(id119in_a,id119in_b));
  }
  { // Node ID: 54 (NodeInputMappedReg)
  }
  { // Node ID: 212 (NodeFIFO)
    const HWFloat<8,24> &id212in_input = id211out_output[getCycle()%5];

    id212out_output[(getCycle()+7)%8] = id212in_input;
  }
  HWFloat<8,24> id120out_output;

  { // Node ID: 120 (NodeStreamOffset)
    const HWFloat<8,24> &id120in_input = id212out_output[getCycle()%8];

    id120out_output = id120in_input;
  }
  { // Node ID: 213 (NodeFIFO)
    const HWFloat<8,24> &id213in_input = id212out_output[getCycle()%8];

    id213out_output[(getCycle()+6)%7] = id213in_input;
  }
  HWFloat<8,24> id121out_output;

  { // Node ID: 121 (NodeStreamOffset)
    const HWFloat<8,24> &id121in_input = id213out_output[getCycle()%7];

    id121out_output = id121in_input;
  }
  { // Node ID: 122 (NodeAdd)
    const HWFloat<8,24> &id122in_a = id120out_output;
    const HWFloat<8,24> &id122in_b = id121out_output;

    id122out_result[(getCycle()+12)%13] = (add_float(id122in_a,id122in_b));
  }
  { // Node ID: 123 (NodeMul)
    const HWFloat<8,24> &id123in_a = id54out_c_3_2;
    const HWFloat<8,24> &id123in_b = id122out_result[getCycle()%13];

    id123out_result[(getCycle()+8)%9] = (mul_float(id123in_a,id123in_b));
  }
  { // Node ID: 124 (NodeAdd)
    const HWFloat<8,24> &id124in_a = id119out_result[getCycle()%13];
    const HWFloat<8,24> &id124in_b = id123out_result[getCycle()%9];

    id124out_result[(getCycle()+12)%13] = (add_float(id124in_a,id124in_b));
  }
  { // Node ID: 55 (NodeInputMappedReg)
  }
  { // Node ID: 214 (NodeFIFO)
    const HWFloat<8,24> &id214in_input = id213out_output[getCycle()%7];

    id214out_output[(getCycle()+3)%4] = id214in_input;
  }
  { // Node ID: 215 (NodeFIFO)
    const HWFloat<8,24> &id215in_input = id214out_output[getCycle()%4];

    id215out_output[(getCycle()+2)%3] = id215in_input;
  }
  HWFloat<8,24> id125out_output;

  { // Node ID: 125 (NodeStreamOffset)
    const HWFloat<8,24> &id125in_input = id215out_output[getCycle()%3];

    id125out_output = id125in_input;
  }
  { // Node ID: 216 (NodeFIFO)
    const HWFloat<8,24> &id216in_input = id215out_output[getCycle()%3];

    id216out_output[(getCycle()+8)%9] = id216in_input;
  }
  HWFloat<8,24> id126out_output;

  { // Node ID: 126 (NodeStreamOffset)
    const HWFloat<8,24> &id126in_input = id216out_output[getCycle()%9];

    id126out_output = id126in_input;
  }
  { // Node ID: 127 (NodeAdd)
    const HWFloat<8,24> &id127in_a = id125out_output;
    const HWFloat<8,24> &id127in_b = id126out_output;

    id127out_result[(getCycle()+12)%13] = (add_float(id127in_a,id127in_b));
  }
  { // Node ID: 128 (NodeMul)
    const HWFloat<8,24> &id128in_a = id55out_c_3_3;
    const HWFloat<8,24> &id128in_b = id127out_result[getCycle()%13];

    id128out_result[(getCycle()+8)%9] = (mul_float(id128in_a,id128in_b));
  }
  { // Node ID: 129 (NodeAdd)
    const HWFloat<8,24> &id129in_a = id124out_result[getCycle()%13];
    const HWFloat<8,24> &id129in_b = id128out_result[getCycle()%9];

    id129out_result[(getCycle()+12)%13] = (add_float(id129in_a,id129in_b));
  }
  { // Node ID: 56 (NodeInputMappedReg)
  }
  HWFloat<8,24> id130out_output;

  { // Node ID: 130 (NodeStreamOffset)
    const HWFloat<8,24> &id130in_input = id216out_output[getCycle()%9];

    id130out_output = id130in_input;
  }
  { // Node ID: 131 (NodeAdd)
    const HWFloat<8,24> &id131in_a = id214out_output[getCycle()%4];
    const HWFloat<8,24> &id131in_b = id130out_output;

    id131out_result[(getCycle()+12)%13] = (add_float(id131in_a,id131in_b));
  }
  { // Node ID: 132 (NodeMul)
    const HWFloat<8,24> &id132in_a = id56out_c_3_4;
    const HWFloat<8,24> &id132in_b = id131out_result[getCycle()%13];

    id132out_result[(getCycle()+8)%9] = (mul_float(id132in_a,id132in_b));
  }
  { // Node ID: 188 (NodeFIFO)
    const HWFloat<8,24> &id188in_input = id132out_result[getCycle()%9];

    id188out_output[(getCycle()+13)%14] = id188in_input;
  }
  { // Node ID: 133 (NodeAdd)
    const HWFloat<8,24> &id133in_a = id129out_result[getCycle()%13];
    const HWFloat<8,24> &id133in_b = id188out_output[getCycle()%14];

    id133out_result[(getCycle()+12)%13] = (add_float(id133in_a,id133in_b));
  }
  { // Node ID: 134 (NodeMul)
    const HWFloat<8,24> &id134in_a = id26out_data;
    const HWFloat<8,24> &id134in_b = id133out_result[getCycle()%13];

    id134out_result[(getCycle()+8)%9] = (mul_float(id134in_a,id134in_b));
  }
  { // Node ID: 135 (NodeAdd)
    const HWFloat<8,24> &id135in_a = id189out_output[getCycle()%143];
    const HWFloat<8,24> &id135in_b = id134out_result[getCycle()%9];

    id135out_result[(getCycle()+12)%13] = (add_float(id135in_a,id135in_b));
  }
  HWOffsetFix<1,0,UNSIGNED> id27out_o;

  { // Node ID: 27 (NodeCast)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id27in_i = id2out_data;

    id27out_o = (cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(id27in_i));
  }
  { // Node ID: 190 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id190in_input = id27out_o;

    id190out_output[(getCycle()+111)%112] = id190in_input;
  }
  HWRawBits<1> id31out_output;

  { // Node ID: 31 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id31in_input = id190out_output[getCycle()%112];

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
  { // Node ID: 191 (NodeFIFO)
    const HWRawBits<1> &id191in_input = id30out_result;

    id191out_output[(getCycle()+110)%111] = id191in_input;
  }
  HWOffsetFix<1,0,UNSIGNED> id33out_output;

  { // Node ID: 33 (NodeReinterpret)
    const HWRawBits<1> &id33in_input = id191out_output[getCycle()%111];

    id33out_output = (cast_bits2fixed<1,0,UNSIGNED>(id33in_input));
  }
  if ( (getFillLevel() >= (230l)))
  { // Node ID: 34 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id34in_enable = id33out_output;

    (id34st_read_next_cycle) = ((id34in_enable.getValueAsBool())&(!(((getFlushLevel())>=(230l))&(isFlushingActive()))));
    queueReadRequest(m_source_container, id34st_read_next_cycle.getValueAsBool());
  }
  { // Node ID: 136 (NodeAdd)
    const HWFloat<8,24> &id136in_a = id135out_result[getCycle()%13];
    const HWFloat<8,24> &id136in_b = id34out_data;

    id136out_result[(getCycle()+12)%13] = (add_float(id136in_a,id136in_b));
  }
  if ( (getFillLevel() >= (247l)) && (getFlushLevel() < (247l)|| !isFlushingActive() ))
  { // Node ID: 144 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id144in_output_control = id192out_output[getCycle()%128];
    const HWFloat<8,24> &id144in_data = id136out_result[getCycle()%13];

    bool id144x_1;

    (id144x_1) = ((id144in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(247l))&(isFlushingActive()))));
    if((id144x_1)) {
      writeOutput(m_ppresult, id144in_data);
    }
  }
  { // Node ID: 148 (NodeConstantRawBits)
  }
  { // Node ID: 217 (NodeConstantRawBits)
  }
  { // Node ID: 146 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 147 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id147in_enable = id217out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id147in_max = id146out_value;

    HWOffsetFix<49,0,UNSIGNED> id147x_1;
    HWOffsetFix<1,0,UNSIGNED> id147x_2;
    HWOffsetFix<1,0,UNSIGNED> id147x_3;
    HWOffsetFix<49,0,UNSIGNED> id147x_4t_1e_1;

    id147out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id147st_count)));
    (id147x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id147st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id147x_2) = (gte_fixed((id147x_1),id147in_max));
    (id147x_3) = (and_fixed((id147x_2),id147in_enable));
    id147out_wrap = (id147x_3);
    if((id147in_enable.getValueAsBool())) {
      if(((id147x_3).getValueAsBool())) {
        (id147st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id147x_4t_1e_1) = (id147x_1);
        (id147st_count) = (id147x_4t_1e_1);
      }
    }
    else {
    }
  }
  { // Node ID: 193 (NodeFIFO)
    const HWOffsetFix<48,0,UNSIGNED> &id193in_input = id147out_count;

    id193out_output[(getCycle()+4)%5] = id193in_input;
  }
  if ( (getFillLevel() >= (4l)) && (getFlushLevel() < (4l)|| !isFlushingActive() ))
  { // Node ID: 149 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id149in_load = id148out_value;
    const HWOffsetFix<48,0,UNSIGNED> &id149in_data = id193out_output[getCycle()%5];

    bool id149x_1;

    (id149x_1) = ((id149in_load.getValueAsBool())&(!(((getFlushLevel())>=(4l))&(isFlushingActive()))));
    if((id149x_1)) {
      setMappedRegValue("current_run_cycle_count", id149in_data);
    }
  }
  { // Node ID: 151 (NodeInputMappedReg)
  }
  { // Node ID: 152 (NodeEq)
    const HWOffsetFix<48,0,UNSIGNED> &id152in_a = id147out_count;
    const HWOffsetFix<48,0,UNSIGNED> &id152in_b = id151out_run_cycle_count;

    id152out_result[(getCycle()+1)%2] = (eq_fixed(id152in_a,id152in_b));
  }
  if ( (getFillLevel() >= (1l)))
  { // Node ID: 150 (NodeFlush)
    const HWOffsetFix<1,0,UNSIGNED> &id150in_start = id152out_result[getCycle()%2];

    if((id150in_start.getValueAsBool())) {
      startFlushing();
    }
  }
};

};
