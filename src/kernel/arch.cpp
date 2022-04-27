#include "include/arch.hpp"

extern "C" {

void _arch_enable_sse();

}
void arch::enable_sse(){
    _arch_enable_sse();
}
