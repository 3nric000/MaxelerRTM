#include "stdsimheader.h"
//#define BOOST_NO_STD_LOCALE
//#include <boost/format.hpp>

//#include "cpu_mainKernel.h"

namespace maxcompilersim {

void cpu_mainKernel::execute0() {
  { // Node ID: 111 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id112out_result;

  { // Node ID: 112 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id112in_a = id111out_io_pp_force_disabled;

    id112out_result = (not_fixed(id112in_a));
  }
  HWRawBits<1> id115out_output;

  { // Node ID: 115 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id115in_input = id112out_result;

    id115out_output = (cast_fixed2bits(id115in_input));
  }
  HWOffsetFix<1,0,UNSIGNED> id116out_output;

  { // Node ID: 116 (NodeReinterpret)
    const HWRawBits<1> &id116in_input = id115out_output;

    id116out_output = (cast_bits2fixed<1,0,UNSIGNED>(id116in_input));
  }
  { // Node ID: 0 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id1out_result;

  { // Node ID: 1 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id1in_a = id0out_io_p_force_disabled;

    id1out_result = (not_fixed(id1in_a));
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 2 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id2in_enable = id1out_result;

    (id2st_read_next_cycle) = ((id2in_enable.getValueAsBool())&(!(((getFlushLevel())>=(4l))&(isFlushingActive()))));
    queueReadRequest(m_p, id2st_read_next_cycle.getValueAsBool());
  }
  { // Node ID: 156 (NodeFIFO)
    const HWFloat<8,24> &id156in_input = id2out_data;

    id156out_output[(getCycle()+1044)%1045] = id156in_input;
  }
  { // Node ID: 161 (NodeFIFO)
    const HWFloat<8,24> &id161in_input = id156out_output[getCycle()%1045];

    id161out_output[(getCycle()+1044)%1045] = id161in_input;
  }
  { // Node ID: 162 (NodeFIFO)
    const HWFloat<8,24> &id162in_input = id161out_output[getCycle()%1045];

    id162out_output[(getCycle()+1044)%1045] = id162in_input;
  }
  { // Node ID: 163 (NodeFIFO)
    const HWFloat<8,24> &id163in_input = id162out_output[getCycle()%1045];

    id163out_output[(getCycle()+1044)%1045] = id163in_input;
  }
  { // Node ID: 164 (NodeFIFO)
    const HWFloat<8,24> &id164in_input = id163out_output[getCycle()%1045];

    id164out_output[(getCycle()+564)%565] = id164in_input;
  }
  { // Node ID: 165 (NodeFIFO)
    const HWFloat<8,24> &id165in_input = id164out_output[getCycle()%565];

    id165out_output[(getCycle()+84)%85] = id165in_input;
  }
  { // Node ID: 166 (NodeFIFO)
    const HWFloat<8,24> &id166in_input = id165out_output[getCycle()%85];

    id166out_output[(getCycle()+84)%85] = id166in_input;
  }
  { // Node ID: 167 (NodeFIFO)
    const HWFloat<8,24> &id167in_input = id166out_output[getCycle()%85];

    id167out_output[(getCycle()+84)%85] = id167in_input;
  }
  { // Node ID: 168 (NodeFIFO)
    const HWFloat<8,24> &id168in_input = id167out_output[getCycle()%85];

    id168out_output[(getCycle()+84)%85] = id168in_input;
  }
  { // Node ID: 169 (NodeFIFO)
    const HWFloat<8,24> &id169in_input = id168out_output[getCycle()%85];

    id169out_output[(getCycle()+35)%36] = id169in_input;
  }
  { // Node ID: 170 (NodeFIFO)
    const HWFloat<8,24> &id170in_input = id169out_output[getCycle()%36];

    id170out_output[(getCycle()+2)%3] = id170in_input;
  }
  { // Node ID: 171 (NodeFIFO)
    const HWFloat<8,24> &id171in_input = id170out_output[getCycle()%3];

    id171out_output[(getCycle()+9)%10] = id171in_input;
  }
  { // Node ID: 172 (NodeFIFO)
    const HWFloat<8,24> &id172in_input = id171out_output[getCycle()%10];

    id172out_output[(getCycle()+2)%3] = id172in_input;
  }
  { // Node ID: 173 (NodeFIFO)
    const HWFloat<8,24> &id173in_input = id172out_output[getCycle()%3];

    id173out_output[(getCycle()+2)%3] = id173in_input;
  }
  { // Node ID: 174 (NodeFIFO)
    const HWFloat<8,24> &id174in_input = id173out_output[getCycle()%3];

    id174out_output[(getCycle()+7)%8] = id174in_input;
  }
  { // Node ID: 175 (NodeFIFO)
    const HWFloat<8,24> &id175in_input = id174out_output[getCycle()%8];

    id175out_output[(getCycle()+6)%7] = id175in_input;
  }
  { // Node ID: 176 (NodeFIFO)
    const HWFloat<8,24> &id176in_input = id175out_output[getCycle()%7];

    id176out_output[(getCycle()+5)%6] = id176in_input;
  }
  { // Node ID: 177 (NodeFIFO)
    const HWFloat<8,24> &id177in_input = id176out_output[getCycle()%6];

    id177out_output[(getCycle()+8)%9] = id177in_input;
  }
  { // Node ID: 178 (NodeFIFO)
    const HWFloat<8,24> &id178in_input = id177out_output[getCycle()%9];

    id178out_output[(getCycle()+3)%4] = id178in_input;
  }
  { // Node ID: 179 (NodeFIFO)
    const HWFloat<8,24> &id179in_input = id178out_output[getCycle()%4];

    id179out_output[(getCycle()+10)%11] = id179in_input;
  }
  { // Node ID: 180 (NodeFIFO)
    const HWFloat<8,24> &id180in_input = id179out_output[getCycle()%11];

    id180out_output[(getCycle()+103)%104] = id180in_input;
  }
  { // Node ID: 181 (NodeFIFO)
    const HWFloat<8,24> &id181in_input = id180out_output[getCycle()%104];

    id181out_output[(getCycle()+39)%40] = id181in_input;
  }
  { // Node ID: 127 (NodePO2FPMult)
    const HWFloat<8,24> &id127in_floatIn = id181out_output[getCycle()%40];

    id127out_floatOut[(getCycle()+1)%2] = (mul_float(id127in_floatIn,(c_hw_flt_8_24_2_0val)));
  }
  { // Node ID: 4 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id5out_result;

  { // Node ID: 5 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id5in_a = id4out_io_pp_value_force_disabled;

    id5out_result = (not_fixed(id5in_a));
  }
  if ( (getFillLevel() >= (5312l)))
  { // Node ID: 6 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id6in_enable = id5out_result;

    (id6st_read_next_cycle) = ((id6in_enable.getValueAsBool())&(!(((getFlushLevel())>=(5312l))&(isFlushingActive()))));
    queueReadRequest(m_pp_value, id6st_read_next_cycle.getValueAsBool());
  }
  { // Node ID: 60 (NodeSub)
    const HWFloat<8,24> &id60in_a = id127out_floatOut[getCycle()%2];
    const HWFloat<8,24> &id60in_b = id6out_data;

    id60out_result[(getCycle()+12)%13] = (sub_float(id60in_a,id60in_b));
  }
  { // Node ID: 7 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id8out_result;

  { // Node ID: 8 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id8in_a = id7out_io_dvv_value_force_disabled;

    id8out_result = (not_fixed(id8in_a));
  }
  if ( (getFillLevel() >= (5316l)))
  { // Node ID: 9 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id9in_enable = id8out_result;

    (id9st_read_next_cycle) = ((id9in_enable.getValueAsBool())&(!(((getFlushLevel())>=(5316l))&(isFlushingActive()))));
    queueReadRequest(m_dvv_value, id9st_read_next_cycle.getValueAsBool());
  }
  { // Node ID: 3 (NodeInputMappedReg)
  }
  { // Node ID: 61 (NodeMul)
    const HWFloat<8,24> &id61in_a = id172out_output[getCycle()%3];
    const HWFloat<8,24> &id61in_b = id3out_c_0;

    id61out_result[(getCycle()+8)%9] = (mul_float(id61in_a,id61in_b));
  }
  { // Node ID: 13 (NodeInputMappedReg)
  }
  HWFloat<8,24> id33out_output;

  { // Node ID: 33 (NodeStreamOffset)
    const HWFloat<8,24> &id33in_input = id169out_output[getCycle()%36];

    id33out_output = id33in_input;
  }
  HWFloat<8,24> id32out_output;

  { // Node ID: 32 (NodeStreamOffset)
    const HWFloat<8,24> &id32in_input = id170out_output[getCycle()%3];

    id32out_output = id32in_input;
  }
  { // Node ID: 62 (NodeAdd)
    const HWFloat<8,24> &id62in_a = id33out_output;
    const HWFloat<8,24> &id62in_b = id32out_output;

    id62out_result[(getCycle()+12)%13] = (add_float(id62in_a,id62in_b));
  }
  { // Node ID: 63 (NodeMul)
    const HWFloat<8,24> &id63in_a = id13out_c_1_0;
    const HWFloat<8,24> &id63in_b = id62out_result[getCycle()%13];

    id63out_result[(getCycle()+8)%9] = (mul_float(id63in_a,id63in_b));
  }
  { // Node ID: 64 (NodeAdd)
    const HWFloat<8,24> &id64in_a = id61out_result[getCycle()%9];
    const HWFloat<8,24> &id64in_b = id63out_result[getCycle()%9];

    id64out_result[(getCycle()+12)%13] = (add_float(id64in_a,id64in_b));
  }
  { // Node ID: 14 (NodeInputMappedReg)
  }
  HWFloat<8,24> id34out_output;

  { // Node ID: 34 (NodeStreamOffset)
    const HWFloat<8,24> &id34in_input = id171out_output[getCycle()%10];

    id34out_output = id34in_input;
  }
  HWFloat<8,24> id31out_output;

  { // Node ID: 31 (NodeStreamOffset)
    const HWFloat<8,24> &id31in_input = id173out_output[getCycle()%3];

    id31out_output = id31in_input;
  }
  { // Node ID: 65 (NodeAdd)
    const HWFloat<8,24> &id65in_a = id34out_output;
    const HWFloat<8,24> &id65in_b = id31out_output;

    id65out_result[(getCycle()+12)%13] = (add_float(id65in_a,id65in_b));
  }
  { // Node ID: 66 (NodeMul)
    const HWFloat<8,24> &id66in_a = id14out_c_1_1;
    const HWFloat<8,24> &id66in_b = id65out_result[getCycle()%13];

    id66out_result[(getCycle()+8)%9] = (mul_float(id66in_a,id66in_b));
  }
  { // Node ID: 67 (NodeAdd)
    const HWFloat<8,24> &id67in_a = id64out_result[getCycle()%13];
    const HWFloat<8,24> &id67in_b = id66out_result[getCycle()%9];

    id67out_result[(getCycle()+12)%13] = (add_float(id67in_a,id67in_b));
  }
  { // Node ID: 15 (NodeInputMappedReg)
  }
  HWFloat<8,24> id35out_output;

  { // Node ID: 35 (NodeStreamOffset)
    const HWFloat<8,24> &id35in_input = id174out_output[getCycle()%8];

    id35out_output = id35in_input;
  }
  HWFloat<8,24> id30out_output;

  { // Node ID: 30 (NodeStreamOffset)
    const HWFloat<8,24> &id30in_input = id175out_output[getCycle()%7];

    id30out_output = id30in_input;
  }
  { // Node ID: 68 (NodeAdd)
    const HWFloat<8,24> &id68in_a = id35out_output;
    const HWFloat<8,24> &id68in_b = id30out_output;

    id68out_result[(getCycle()+12)%13] = (add_float(id68in_a,id68in_b));
  }
  { // Node ID: 69 (NodeMul)
    const HWFloat<8,24> &id69in_a = id15out_c_1_2;
    const HWFloat<8,24> &id69in_b = id68out_result[getCycle()%13];

    id69out_result[(getCycle()+8)%9] = (mul_float(id69in_a,id69in_b));
  }
  { // Node ID: 70 (NodeAdd)
    const HWFloat<8,24> &id70in_a = id67out_result[getCycle()%13];
    const HWFloat<8,24> &id70in_b = id69out_result[getCycle()%9];

    id70out_result[(getCycle()+12)%13] = (add_float(id70in_a,id70in_b));
  }
  { // Node ID: 16 (NodeInputMappedReg)
  }
  HWFloat<8,24> id36out_output;

  { // Node ID: 36 (NodeStreamOffset)
    const HWFloat<8,24> &id36in_input = id176out_output[getCycle()%6];

    id36out_output = id36in_input;
  }
  HWFloat<8,24> id29out_output;

  { // Node ID: 29 (NodeStreamOffset)
    const HWFloat<8,24> &id29in_input = id177out_output[getCycle()%9];

    id29out_output = id29in_input;
  }
  { // Node ID: 71 (NodeAdd)
    const HWFloat<8,24> &id71in_a = id36out_output;
    const HWFloat<8,24> &id71in_b = id29out_output;

    id71out_result[(getCycle()+12)%13] = (add_float(id71in_a,id71in_b));
  }
  { // Node ID: 72 (NodeMul)
    const HWFloat<8,24> &id72in_a = id16out_c_1_3;
    const HWFloat<8,24> &id72in_b = id71out_result[getCycle()%13];

    id72out_result[(getCycle()+8)%9] = (mul_float(id72in_a,id72in_b));
  }
  { // Node ID: 73 (NodeAdd)
    const HWFloat<8,24> &id73in_a = id70out_result[getCycle()%13];
    const HWFloat<8,24> &id73in_b = id72out_result[getCycle()%9];

    id73out_result[(getCycle()+12)%13] = (add_float(id73in_a,id73in_b));
  }
  { // Node ID: 17 (NodeInputMappedReg)
  }
  HWFloat<8,24> id37out_output;

  { // Node ID: 37 (NodeStreamOffset)
    const HWFloat<8,24> &id37in_input = id178out_output[getCycle()%4];

    id37out_output = id37in_input;
  }
  HWFloat<8,24> id28out_output;

  { // Node ID: 28 (NodeStreamOffset)
    const HWFloat<8,24> &id28in_input = id179out_output[getCycle()%11];

    id28out_output = id28in_input;
  }
  { // Node ID: 74 (NodeAdd)
    const HWFloat<8,24> &id74in_a = id37out_output;
    const HWFloat<8,24> &id74in_b = id28out_output;

    id74out_result[(getCycle()+12)%13] = (add_float(id74in_a,id74in_b));
  }
  { // Node ID: 75 (NodeMul)
    const HWFloat<8,24> &id75in_a = id17out_c_1_4;
    const HWFloat<8,24> &id75in_b = id74out_result[getCycle()%13];

    id75out_result[(getCycle()+8)%9] = (mul_float(id75in_a,id75in_b));
  }
  { // Node ID: 76 (NodeAdd)
    const HWFloat<8,24> &id76in_a = id73out_result[getCycle()%13];
    const HWFloat<8,24> &id76in_b = id75out_result[getCycle()%9];

    id76out_result[(getCycle()+12)%13] = (add_float(id76in_a,id76in_b));
  }
  { // Node ID: 18 (NodeInputMappedReg)
  }
  HWFloat<8,24> id43out_output;

  { // Node ID: 43 (NodeStreamOffset)
    const HWFloat<8,24> &id43in_input = id168out_output[getCycle()%85];

    id43out_output = id43in_input;
  }
  HWFloat<8,24> id42out_output;

  { // Node ID: 42 (NodeStreamOffset)
    const HWFloat<8,24> &id42in_input = id180out_output[getCycle()%104];

    id42out_output = id42in_input;
  }
  { // Node ID: 77 (NodeAdd)
    const HWFloat<8,24> &id77in_a = id43out_output;
    const HWFloat<8,24> &id77in_b = id42out_output;

    id77out_result[(getCycle()+12)%13] = (add_float(id77in_a,id77in_b));
  }
  { // Node ID: 78 (NodeMul)
    const HWFloat<8,24> &id78in_a = id18out_c_2_0;
    const HWFloat<8,24> &id78in_b = id77out_result[getCycle()%13];

    id78out_result[(getCycle()+8)%9] = (mul_float(id78in_a,id78in_b));
  }
  { // Node ID: 79 (NodeAdd)
    const HWFloat<8,24> &id79in_a = id76out_result[getCycle()%13];
    const HWFloat<8,24> &id79in_b = id78out_result[getCycle()%9];

    id79out_result[(getCycle()+12)%13] = (add_float(id79in_a,id79in_b));
  }
  { // Node ID: 19 (NodeInputMappedReg)
  }
  HWFloat<8,24> id44out_output;

  { // Node ID: 44 (NodeStreamOffset)
    const HWFloat<8,24> &id44in_input = id167out_output[getCycle()%85];

    id44out_output = id44in_input;
  }
  { // Node ID: 182 (NodeFIFO)
    const HWFloat<8,24> &id182in_input = id181out_output[getCycle()%40];

    id182out_output[(getCycle()+69)%70] = id182in_input;
  }
  HWFloat<8,24> id41out_output;

  { // Node ID: 41 (NodeStreamOffset)
    const HWFloat<8,24> &id41in_input = id182out_output[getCycle()%70];

    id41out_output = id41in_input;
  }
  { // Node ID: 80 (NodeAdd)
    const HWFloat<8,24> &id80in_a = id44out_output;
    const HWFloat<8,24> &id80in_b = id41out_output;

    id80out_result[(getCycle()+12)%13] = (add_float(id80in_a,id80in_b));
  }
  { // Node ID: 81 (NodeMul)
    const HWFloat<8,24> &id81in_a = id19out_c_2_1;
    const HWFloat<8,24> &id81in_b = id80out_result[getCycle()%13];

    id81out_result[(getCycle()+8)%9] = (mul_float(id81in_a,id81in_b));
  }
  { // Node ID: 82 (NodeAdd)
    const HWFloat<8,24> &id82in_a = id79out_result[getCycle()%13];
    const HWFloat<8,24> &id82in_b = id81out_result[getCycle()%9];

    id82out_result[(getCycle()+12)%13] = (add_float(id82in_a,id82in_b));
  }
  { // Node ID: 20 (NodeInputMappedReg)
  }
  HWFloat<8,24> id45out_output;

  { // Node ID: 45 (NodeStreamOffset)
    const HWFloat<8,24> &id45in_input = id166out_output[getCycle()%85];

    id45out_output = id45in_input;
  }
  { // Node ID: 183 (NodeFIFO)
    const HWFloat<8,24> &id183in_input = id182out_output[getCycle()%70];

    id183out_output[(getCycle()+108)%109] = id183in_input;
  }
  HWFloat<8,24> id40out_output;

  { // Node ID: 40 (NodeStreamOffset)
    const HWFloat<8,24> &id40in_input = id183out_output[getCycle()%109];

    id40out_output = id40in_input;
  }
  { // Node ID: 83 (NodeAdd)
    const HWFloat<8,24> &id83in_a = id45out_output;
    const HWFloat<8,24> &id83in_b = id40out_output;

    id83out_result[(getCycle()+12)%13] = (add_float(id83in_a,id83in_b));
  }
  { // Node ID: 84 (NodeMul)
    const HWFloat<8,24> &id84in_a = id20out_c_2_2;
    const HWFloat<8,24> &id84in_b = id83out_result[getCycle()%13];

    id84out_result[(getCycle()+8)%9] = (mul_float(id84in_a,id84in_b));
  }
  { // Node ID: 85 (NodeAdd)
    const HWFloat<8,24> &id85in_a = id82out_result[getCycle()%13];
    const HWFloat<8,24> &id85in_b = id84out_result[getCycle()%9];

    id85out_result[(getCycle()+12)%13] = (add_float(id85in_a,id85in_b));
  }
  { // Node ID: 21 (NodeInputMappedReg)
  }
  HWFloat<8,24> id46out_output;

  { // Node ID: 46 (NodeStreamOffset)
    const HWFloat<8,24> &id46in_input = id165out_output[getCycle()%85];

    id46out_output = id46in_input;
  }
  { // Node ID: 184 (NodeFIFO)
    const HWFloat<8,24> &id184in_input = id183out_output[getCycle()%109];

    id184out_output[(getCycle()+108)%109] = id184in_input;
  }
  HWFloat<8,24> id39out_output;

  { // Node ID: 39 (NodeStreamOffset)
    const HWFloat<8,24> &id39in_input = id184out_output[getCycle()%109];

    id39out_output = id39in_input;
  }
  { // Node ID: 86 (NodeAdd)
    const HWFloat<8,24> &id86in_a = id46out_output;
    const HWFloat<8,24> &id86in_b = id39out_output;

    id86out_result[(getCycle()+12)%13] = (add_float(id86in_a,id86in_b));
  }
  { // Node ID: 87 (NodeMul)
    const HWFloat<8,24> &id87in_a = id21out_c_2_3;
    const HWFloat<8,24> &id87in_b = id86out_result[getCycle()%13];

    id87out_result[(getCycle()+8)%9] = (mul_float(id87in_a,id87in_b));
  }
  { // Node ID: 88 (NodeAdd)
    const HWFloat<8,24> &id88in_a = id85out_result[getCycle()%13];
    const HWFloat<8,24> &id88in_b = id87out_result[getCycle()%9];

    id88out_result[(getCycle()+12)%13] = (add_float(id88in_a,id88in_b));
  }
  { // Node ID: 22 (NodeInputMappedReg)
  }
  HWFloat<8,24> id47out_output;

  { // Node ID: 47 (NodeStreamOffset)
    const HWFloat<8,24> &id47in_input = id164out_output[getCycle()%565];

    id47out_output = id47in_input;
  }
  { // Node ID: 185 (NodeFIFO)
    const HWFloat<8,24> &id185in_input = id184out_output[getCycle()%109];

    id185out_output[(getCycle()+108)%109] = id185in_input;
  }
  HWFloat<8,24> id38out_output;

  { // Node ID: 38 (NodeStreamOffset)
    const HWFloat<8,24> &id38in_input = id185out_output[getCycle()%109];

    id38out_output = id38in_input;
  }
  { // Node ID: 89 (NodeAdd)
    const HWFloat<8,24> &id89in_a = id47out_output;
    const HWFloat<8,24> &id89in_b = id38out_output;

    id89out_result[(getCycle()+12)%13] = (add_float(id89in_a,id89in_b));
  }
  { // Node ID: 90 (NodeMul)
    const HWFloat<8,24> &id90in_a = id22out_c_2_4;
    const HWFloat<8,24> &id90in_b = id89out_result[getCycle()%13];

    id90out_result[(getCycle()+8)%9] = (mul_float(id90in_a,id90in_b));
  }
  { // Node ID: 91 (NodeAdd)
    const HWFloat<8,24> &id91in_a = id88out_result[getCycle()%13];
    const HWFloat<8,24> &id91in_b = id90out_result[getCycle()%9];

    id91out_result[(getCycle()+12)%13] = (add_float(id91in_a,id91in_b));
  }
  { // Node ID: 23 (NodeInputMappedReg)
  }
  HWFloat<8,24> id53out_output;

  { // Node ID: 53 (NodeStreamOffset)
    const HWFloat<8,24> &id53in_input = id163out_output[getCycle()%1045];

    id53out_output = id53in_input;
  }
  { // Node ID: 186 (NodeFIFO)
    const HWFloat<8,24> &id186in_input = id185out_output[getCycle()%109];

    id186out_output[(getCycle()+588)%589] = id186in_input;
  }
  HWFloat<8,24> id52out_output;

  { // Node ID: 52 (NodeStreamOffset)
    const HWFloat<8,24> &id52in_input = id186out_output[getCycle()%589];

    id52out_output = id52in_input;
  }
  { // Node ID: 92 (NodeAdd)
    const HWFloat<8,24> &id92in_a = id53out_output;
    const HWFloat<8,24> &id92in_b = id52out_output;

    id92out_result[(getCycle()+12)%13] = (add_float(id92in_a,id92in_b));
  }
  { // Node ID: 93 (NodeMul)
    const HWFloat<8,24> &id93in_a = id23out_c_3_0;
    const HWFloat<8,24> &id93in_b = id92out_result[getCycle()%13];

    id93out_result[(getCycle()+8)%9] = (mul_float(id93in_a,id93in_b));
  }
  { // Node ID: 94 (NodeAdd)
    const HWFloat<8,24> &id94in_a = id91out_result[getCycle()%13];
    const HWFloat<8,24> &id94in_b = id93out_result[getCycle()%9];

    id94out_result[(getCycle()+12)%13] = (add_float(id94in_a,id94in_b));
  }
  { // Node ID: 24 (NodeInputMappedReg)
  }
  HWFloat<8,24> id54out_output;

  { // Node ID: 54 (NodeStreamOffset)
    const HWFloat<8,24> &id54in_input = id162out_output[getCycle()%1045];

    id54out_output = id54in_input;
  }
  { // Node ID: 187 (NodeFIFO)
    const HWFloat<8,24> &id187in_input = id186out_output[getCycle()%589];

    id187out_output[(getCycle()+1068)%1069] = id187in_input;
  }
  HWFloat<8,24> id51out_output;

  { // Node ID: 51 (NodeStreamOffset)
    const HWFloat<8,24> &id51in_input = id187out_output[getCycle()%1069];

    id51out_output = id51in_input;
  }
  { // Node ID: 95 (NodeAdd)
    const HWFloat<8,24> &id95in_a = id54out_output;
    const HWFloat<8,24> &id95in_b = id51out_output;

    id95out_result[(getCycle()+12)%13] = (add_float(id95in_a,id95in_b));
  }
  { // Node ID: 96 (NodeMul)
    const HWFloat<8,24> &id96in_a = id24out_c_3_1;
    const HWFloat<8,24> &id96in_b = id95out_result[getCycle()%13];

    id96out_result[(getCycle()+8)%9] = (mul_float(id96in_a,id96in_b));
  }
  { // Node ID: 97 (NodeAdd)
    const HWFloat<8,24> &id97in_a = id94out_result[getCycle()%13];
    const HWFloat<8,24> &id97in_b = id96out_result[getCycle()%9];

    id97out_result[(getCycle()+12)%13] = (add_float(id97in_a,id97in_b));
  }
  { // Node ID: 25 (NodeInputMappedReg)
  }
  HWFloat<8,24> id55out_output;

  { // Node ID: 55 (NodeStreamOffset)
    const HWFloat<8,24> &id55in_input = id161out_output[getCycle()%1045];

    id55out_output = id55in_input;
  }
  { // Node ID: 188 (NodeFIFO)
    const HWFloat<8,24> &id188in_input = id187out_output[getCycle()%1069];

    id188out_output[(getCycle()+1068)%1069] = id188in_input;
  }
  HWFloat<8,24> id50out_output;

  { // Node ID: 50 (NodeStreamOffset)
    const HWFloat<8,24> &id50in_input = id188out_output[getCycle()%1069];

    id50out_output = id50in_input;
  }
  { // Node ID: 98 (NodeAdd)
    const HWFloat<8,24> &id98in_a = id55out_output;
    const HWFloat<8,24> &id98in_b = id50out_output;

    id98out_result[(getCycle()+12)%13] = (add_float(id98in_a,id98in_b));
  }
  { // Node ID: 99 (NodeMul)
    const HWFloat<8,24> &id99in_a = id25out_c_3_2;
    const HWFloat<8,24> &id99in_b = id98out_result[getCycle()%13];

    id99out_result[(getCycle()+8)%9] = (mul_float(id99in_a,id99in_b));
  }
  { // Node ID: 100 (NodeAdd)
    const HWFloat<8,24> &id100in_a = id97out_result[getCycle()%13];
    const HWFloat<8,24> &id100in_b = id99out_result[getCycle()%9];

    id100out_result[(getCycle()+12)%13] = (add_float(id100in_a,id100in_b));
  }
  { // Node ID: 26 (NodeInputMappedReg)
  }
  HWFloat<8,24> id56out_output;

  { // Node ID: 56 (NodeStreamOffset)
    const HWFloat<8,24> &id56in_input = id156out_output[getCycle()%1045];

    id56out_output = id56in_input;
  }
  { // Node ID: 189 (NodeFIFO)
    const HWFloat<8,24> &id189in_input = id188out_output[getCycle()%1069];

    id189out_output[(getCycle()+1068)%1069] = id189in_input;
  }
  HWFloat<8,24> id49out_output;

  { // Node ID: 49 (NodeStreamOffset)
    const HWFloat<8,24> &id49in_input = id189out_output[getCycle()%1069];

    id49out_output = id49in_input;
  }
  { // Node ID: 101 (NodeAdd)
    const HWFloat<8,24> &id101in_a = id56out_output;
    const HWFloat<8,24> &id101in_b = id49out_output;

    id101out_result[(getCycle()+12)%13] = (add_float(id101in_a,id101in_b));
  }
  { // Node ID: 102 (NodeMul)
    const HWFloat<8,24> &id102in_a = id26out_c_3_3;
    const HWFloat<8,24> &id102in_b = id101out_result[getCycle()%13];

    id102out_result[(getCycle()+8)%9] = (mul_float(id102in_a,id102in_b));
  }
  { // Node ID: 103 (NodeAdd)
    const HWFloat<8,24> &id103in_a = id100out_result[getCycle()%13];
    const HWFloat<8,24> &id103in_b = id102out_result[getCycle()%9];

    id103out_result[(getCycle()+12)%13] = (add_float(id103in_a,id103in_b));
  }
  { // Node ID: 27 (NodeInputMappedReg)
  }
  HWFloat<8,24> id57out_output;

  { // Node ID: 57 (NodeStreamOffset)
    const HWFloat<8,24> &id57in_input = id2out_data;

    id57out_output = id57in_input;
  }
  HWFloat<8,24> id48out_output;

  { // Node ID: 48 (NodeStreamOffset)
    const HWFloat<8,24> &id48in_input = id189out_output[getCycle()%1069];

    id48out_output = id48in_input;
  }
  { // Node ID: 159 (NodeFIFO)
    const HWFloat<8,24> &id159in_input = id48out_output;

    id159out_output[(getCycle()+1068)%1069] = id159in_input;
  }
  { // Node ID: 104 (NodeAdd)
    const HWFloat<8,24> &id104in_a = id57out_output;
    const HWFloat<8,24> &id104in_b = id159out_output[getCycle()%1069];

    id104out_result[(getCycle()+12)%13] = (add_float(id104in_a,id104in_b));
  }
  { // Node ID: 105 (NodeMul)
    const HWFloat<8,24> &id105in_a = id27out_c_3_4;
    const HWFloat<8,24> &id105in_b = id104out_result[getCycle()%13];

    id105out_result[(getCycle()+8)%9] = (mul_float(id105in_a,id105in_b));
  }
  { // Node ID: 106 (NodeAdd)
    const HWFloat<8,24> &id106in_a = id103out_result[getCycle()%13];
    const HWFloat<8,24> &id106in_b = id105out_result[getCycle()%9];

    id106out_result[(getCycle()+12)%13] = (add_float(id106in_a,id106in_b));
  }
  { // Node ID: 107 (NodeMul)
    const HWFloat<8,24> &id107in_a = id9out_data;
    const HWFloat<8,24> &id107in_b = id106out_result[getCycle()%13];

    id107out_result[(getCycle()+8)%9] = (mul_float(id107in_a,id107in_b));
  }
  { // Node ID: 108 (NodeAdd)
    const HWFloat<8,24> &id108in_a = id60out_result[getCycle()%13];
    const HWFloat<8,24> &id108in_b = id107out_result[getCycle()%9];

    id108out_result[(getCycle()+12)%13] = (add_float(id108in_a,id108in_b));
  }
  { // Node ID: 10 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id11out_result;

  { // Node ID: 11 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id11in_a = id10out_io_source_container_value_force_disabled;

    id11out_result = (not_fixed(id11in_a));
  }
  if ( (getFillLevel() >= (5336l)))
  { // Node ID: 12 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id12in_enable = id11out_result;

    (id12st_read_next_cycle) = ((id12in_enable.getValueAsBool())&(!(((getFlushLevel())>=(5336l))&(isFlushingActive()))));
    queueReadRequest(m_source_container_value, id12st_read_next_cycle.getValueAsBool());
  }
  { // Node ID: 109 (NodeAdd)
    const HWFloat<8,24> &id109in_a = id108out_result[getCycle()%13];
    const HWFloat<8,24> &id109in_b = id12out_data;

    id109out_result[(getCycle()+12)%13] = (add_float(id109in_a,id109in_b));
  }
  if ( (getFillLevel() >= (5353l)) && (getFlushLevel() < (5353l)|| !isFlushingActive() ))
  { // Node ID: 117 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id117in_output_control = id116out_output;
    const HWFloat<8,24> &id117in_data = id109out_result[getCycle()%13];

    bool id117x_1;

    (id117x_1) = ((id117in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(5353l))&(isFlushingActive()))));
    if((id117x_1)) {
      writeOutput(m_pp, id117in_data);
    }
  }
  { // Node ID: 121 (NodeConstantRawBits)
  }
  { // Node ID: 190 (NodeConstantRawBits)
  }
  { // Node ID: 119 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 120 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id120in_enable = id190out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id120in_max = id119out_value;

    HWOffsetFix<49,0,UNSIGNED> id120x_1;
    HWOffsetFix<1,0,UNSIGNED> id120x_2;
    HWOffsetFix<1,0,UNSIGNED> id120x_3;
    HWOffsetFix<49,0,UNSIGNED> id120x_4t_1e_1;

    id120out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id120st_count)));
    (id120x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id120st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id120x_2) = (gte_fixed((id120x_1),id120in_max));
    (id120x_3) = (and_fixed((id120x_2),id120in_enable));
    id120out_wrap = (id120x_3);
    if((id120in_enable.getValueAsBool())) {
      if(((id120x_3).getValueAsBool())) {
        (id120st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id120x_4t_1e_1) = (id120x_1);
        (id120st_count) = (id120x_4t_1e_1);
      }
    }
    else {
    }
  }
  { // Node ID: 160 (NodeFIFO)
    const HWOffsetFix<48,0,UNSIGNED> &id160in_input = id120out_count;

    id160out_output[(getCycle()+4)%5] = id160in_input;
  }
  if ( (getFillLevel() >= (4l)) && (getFlushLevel() < (4l)|| !isFlushingActive() ))
  { // Node ID: 122 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id122in_load = id121out_value;
    const HWOffsetFix<48,0,UNSIGNED> &id122in_data = id160out_output[getCycle()%5];

    bool id122x_1;

    (id122x_1) = ((id122in_load.getValueAsBool())&(!(((getFlushLevel())>=(4l))&(isFlushingActive()))));
    if((id122x_1)) {
      setMappedRegValue("current_run_cycle_count", id122in_data);
    }
  }
  { // Node ID: 124 (NodeInputMappedReg)
  }
  { // Node ID: 125 (NodeEq)
    const HWOffsetFix<48,0,UNSIGNED> &id125in_a = id120out_count;
    const HWOffsetFix<48,0,UNSIGNED> &id125in_b = id124out_run_cycle_count;

    id125out_result[(getCycle()+1)%2] = (eq_fixed(id125in_a,id125in_b));
  }
  if ( (getFillLevel() >= (1l)))
  { // Node ID: 123 (NodeFlush)
    const HWOffsetFix<1,0,UNSIGNED> &id123in_start = id125out_result[getCycle()%2];

    if((id123in_start.getValueAsBool())) {
      startFlushing();
    }
  }
};

};
