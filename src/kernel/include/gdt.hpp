#ifndef GDT_HPP
#define GDT_HPP

    #include "types.hpp"

    class GlobalDescriptorTable
    {
        public:

            class SegmentDescriptor
            {
                private:
                    tus limit_lo;
                    tus base_lo;
                    tuc base_hi;
                    tuc type;
                    tuc limit_hi;
                    tuc base_vhi;

                public:
                    SegmentDescriptor(tui base, tui limit, tuc type);
                    tui Base();
                    tui Limit();
            } __attribute__((packed));

        private:
            SegmentDescriptor nullSegmentSelector;
            SegmentDescriptor unusedSegmentSelector;
            SegmentDescriptor codeSegmentSelector;
            SegmentDescriptor dataSegmentSelector;

        public:

            GlobalDescriptorTable();
            ~GlobalDescriptorTable();

            tus CodeSegmentSelector();
            tus DataSegmentSelector();
    };

#endif
