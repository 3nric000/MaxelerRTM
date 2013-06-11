#include "stdsimheader.h"
//#include "linearKernel.h"
//#include "HWTypes.h"
//#include "KernelManagerBlockSync.h"

using namespace maxcompilersim;

// Templated Types used in the kernel
template class HWOffsetFix<32,0,TWOSCOMPLEMENT>;
template class HWRawBits<1>;
template class HWFloat<8,24>;
template class HWOffsetFix<1,0,UNSIGNED>;
template class HWOffsetFix<48,0,UNSIGNED>;
template class HWOffsetFix<49,0,UNSIGNED>;
template class HWOffsetFix<33,0,UNSIGNED>;
template class HWOffsetFix<32,0,UNSIGNED>;
// add. templates from the default formatter 


// Templated Methods/Functions
template HWOffsetFix<1,0,UNSIGNED>and_fixed<>(const HWOffsetFix<1,0,UNSIGNED> &a, const HWOffsetFix<1,0,UNSIGNED> &b );
template HWFloat<8,24>add_float<>(const HWFloat<8,24> &a, const HWFloat<8,24> &b );
template HWOffsetFix<1,0,UNSIGNED> cast_bits2fixed<1,0,UNSIGNED>(const HWRawBits<1> &a);
template HWOffsetFix<1,0,UNSIGNED>gte_fixed<>(const HWOffsetFix<49,0,UNSIGNED> &a, const HWOffsetFix<49,0,UNSIGNED> &b );
template HWRawBits<1> cast_fixed2bits<>(const HWOffsetFix<1,0,UNSIGNED> &a);
template HWOffsetFix<1,0,UNSIGNED>eq_fixed<>(const HWOffsetFix<48,0,UNSIGNED> &a, const HWOffsetFix<48,0,UNSIGNED> &b );
template HWOffsetFix<1,0,UNSIGNED> KernelManagerBlockSync::getMappedRegValue< HWOffsetFix<1,0,UNSIGNED> >(const std::string &name);
template HWRawBits<1>and_bits<>(const HWRawBits<1> &a,  const HWRawBits<1> &b );
template HWOffsetFix<32,0,TWOSCOMPLEMENT> KernelManagerBlockSync::readInput< HWOffsetFix<32,0,TWOSCOMPLEMENT> >(const t_port_number port_number);
template HWOffsetFix<33,0,UNSIGNED>add_fixed<33,0,UNSIGNED,TRUNCATE>(const HWOffsetFix<33,0,UNSIGNED> &a, const HWOffsetFix<33,0,UNSIGNED> &b );
template HWOffsetFix<1,0,UNSIGNED> cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(const HWOffsetFix<32,0,TWOSCOMPLEMENT> &a);
template HWFloat<8,24>sub_float<>(const HWFloat<8,24> &a, const HWFloat<8,24> &b );
template void KernelManagerBlockSync::writeOutput< HWFloat<8,24> >(const t_port_number port_number, const HWFloat<8,24> &value);
template HWOffsetFix<32,0,UNSIGNED> cast_fixed2fixed<32,0,UNSIGNED,TRUNCATE>(const HWOffsetFix<33,0,UNSIGNED> &a);
template HWOffsetFix<1,0,UNSIGNED>gte_fixed<>(const HWOffsetFix<33,0,UNSIGNED> &a, const HWOffsetFix<33,0,UNSIGNED> &b );
template HWOffsetFix<48,0,UNSIGNED> cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>(const HWOffsetFix<49,0,UNSIGNED> &a);
template HWFloat<8,24> KernelManagerBlockSync::getMappedRegValue< HWFloat<8,24> >(const std::string &name);
template HWFloat<8,24>mul_float<>(const HWFloat<8,24> &a, const HWFloat<8,24> &b );
template HWOffsetFix<48,0,UNSIGNED> KernelManagerBlockSync::getMappedRegValue< HWOffsetFix<48,0,UNSIGNED> >(const std::string &name);
template HWOffsetFix<49,0,UNSIGNED>add_fixed<49,0,UNSIGNED,TRUNCATE>(const HWOffsetFix<49,0,UNSIGNED> &a, const HWOffsetFix<49,0,UNSIGNED> &b );
template HWOffsetFix<1,0,UNSIGNED>not_fixed<>(const HWOffsetFix<1,0,UNSIGNED> &a );
template HWFloat<8,24> KernelManagerBlockSync::readInput< HWFloat<8,24> >(const t_port_number port_number);
template void KernelManagerBlockSync::setMappedRegValue< HWOffsetFix<48,0,UNSIGNED> >(const std::string &name, const HWOffsetFix<48,0,UNSIGNED> & value);


// Additional Code
std::string linearKernel::format_string_linearKernel_1 (const char* _format_arg_format_string, const HWOffsetFix<32,0,UNSIGNED> &_format_arg_0, const HWFloat<8,24> &_format_arg_1)
{return ( boost::format(_format_arg_format_string)% _format_arg_0 % _format_arg_1 ).str();}
std::string linearKernel::format_string_linearKernel_2 (const char* _format_arg_format_string)
{return ( boost::format(_format_arg_format_string)).str();}

