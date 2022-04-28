#include "include/kernel.hpp"
#include "include/memory.hpp"
#include "include/timer.hpp"
#include "include/shell.hpp"
#include "include/driver/"
#include "include/disks.hpp"
#include "include/driver/acpi.hpp"
#include "include/interrupts.hpp"
#include "include/arch.hpp"
#include "include/e820.hpp"

extern "C"
{

    void _init();

    void kernel_main()
    {
        arch::enable_sse();

        interrupt::install_idt();
        interrupt::install_isrs();
        interrupt::remap_irqs();
        interrupt::install_irqs();
        interrupt::enable_interrupts();

        e820::finalize_memory_detection();

        init_memory_manager();

        install_timer();
        // acpi::init();
        keyboard::install_driver();
        disks::detect_disks();

        _init();

        init_shell();

        return;
    }
}
