#include "stdsimheader.h"
//#include "QueueKernel.h"
//#include "HWTypes.h"
//#include "KernelManagerBlockSync.h"

using namespace maxcompilersim;

// Templated Types used in the kernel
template class HWOffsetFix<32,0,TWOSCOMPLEMENT>;
template class HWRawBits<1>;
template class HWOffsetFix<1,0,UNSIGNED>;
template class HWOffsetFix<48,0,UNSIGNED>;
template class HWOffsetFix<49,0,UNSIGNED>;
template class HWOffsetFix<33,0,UNSIGNED>;
template class HWOffsetFix<32,0,UNSIGNED>;
// add. templates from the default formatter 


// Templated Methods/Functions
template HWOffsetFix<1,0,UNSIGNED>and_fixed<>(const HWOffsetFix<1,0,UNSIGNED> &a, const HWOffsetFix<1,0,UNSIGNED> &b );
template HWOffsetFix<1,0,UNSIGNED> cast_bits2fixed<1,0,UNSIGNED>(const HWRawBits<1> &a);
template HWOffsetFix<1,0,UNSIGNED>gte_fixed<>(const HWOffsetFix<49,0,UNSIGNED> &a, const HWOffsetFix<49,0,UNSIGNED> &b );
template HWRawBits<1> cast_fixed2bits<>(const HWOffsetFix<1,0,UNSIGNED> &a);
template HWOffsetFix<1,0,UNSIGNED>eq_fixed<>(const HWOffsetFix<48,0,UNSIGNED> &a, const HWOffsetFix<48,0,UNSIGNED> &b );
template HWOffsetFix<1,0,UNSIGNED> KernelManagerBlockSync::getMappedRegValue< HWOffsetFix<1,0,UNSIGNED> >(const std::string &name);
template HWOffsetFix<32,0,TWOSCOMPLEMENT> KernelManagerBlockSync::readInput< HWOffsetFix<32,0,TWOSCOMPLEMENT> >(const t_port_number port_number);
template HWRawBits<1>and_bits<>(const HWRawBits<1> &a,  const HWRawBits<1> &b );
template HWOffsetFix<33,0,UNSIGNED>add_fixed<33,0,UNSIGNED,TRUNCATE>(const HWOffsetFix<33,0,UNSIGNED> &a, const HWOffsetFix<33,0,UNSIGNED> &b );
template HWOffsetFix<1,0,UNSIGNED> cast_fixed2fixed<1,0,UNSIGNED,TONEAR>(const HWOffsetFix<32,0,TWOSCOMPLEMENT> &a);
template HWOffsetFix<32,0,UNSIGNED> cast_fixed2fixed<32,0,UNSIGNED,TRUNCATE>(const HWOffsetFix<33,0,UNSIGNED> &a);
template HWOffsetFix<32,0,TWOSCOMPLEMENT>add_fixed<32,0,TWOSCOMPLEMENT,TRUNCATE>(const HWOffsetFix<32,0,TWOSCOMPLEMENT> &a, const HWOffsetFix<32,0,TWOSCOMPLEMENT> &b );
template void KernelManagerBlockSync::writeOutput< HWOffsetFix<32,0,TWOSCOMPLEMENT> >(const t_port_number port_number, const HWOffsetFix<32,0,TWOSCOMPLEMENT> &value);
template HWOffsetFix<1,0,UNSIGNED>gte_fixed<>(const HWOffsetFix<33,0,UNSIGNED> &a, const HWOffsetFix<33,0,UNSIGNED> &b );
template HWOffsetFix<48,0,UNSIGNED> cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>(const HWOffsetFix<49,0,UNSIGNED> &a);
template HWOffsetFix<48,0,UNSIGNED> KernelManagerBlockSync::getMappedRegValue< HWOffsetFix<48,0,UNSIGNED> >(const std::string &name);
template HWOffsetFix<49,0,UNSIGNED>add_fixed<49,0,UNSIGNED,TRUNCATE>(const HWOffsetFix<49,0,UNSIGNED> &a, const HWOffsetFix<49,0,UNSIGNED> &b );
template HWOffsetFix<32,0,TWOSCOMPLEMENT> KernelManagerBlockSync::getMappedRegValue< HWOffsetFix<32,0,TWOSCOMPLEMENT> >(const std::string &name);
template HWOffsetFix<1,0,UNSIGNED>not_fixed<>(const HWOffsetFix<1,0,UNSIGNED> &a );
template void KernelManagerBlockSync::setMappedRegValue< HWOffsetFix<48,0,UNSIGNED> >(const std::string &name, const HWOffsetFix<48,0,UNSIGNED> & value);


// Additional Code
std::string QueueKernel::format_string_QueueKernel_1 (const char* _format_arg_format_string, const HWOffsetFix<32,0,TWOSCOMPLEMENT> &_format_arg_0, const HWOffsetFix<32,0,TWOSCOMPLEMENT> &_format_arg_1, const HWOffsetFix<32,0,TWOSCOMPLEMENT> &_format_arg_2, const HWOffsetFix<32,0,TWOSCOMPLEMENT> &_format_arg_3, const HWOffsetFix<32,0,TWOSCOMPLEMENT> &_format_arg_4, const HWOffsetFix<32,0,UNSIGNED> &_format_arg_5)
{return ( boost::format(_format_arg_format_string)% _format_arg_0 % _format_arg_1 % _format_arg_2 % _format_arg_3 % _format_arg_4 % _format_arg_5 ).str();}
std::string QueueKernel::format_string_QueueKernel_2 (const char* _format_arg_format_string)
{return ( boost::format(_format_arg_format_string)).str();}

