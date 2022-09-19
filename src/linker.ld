ENTRY(loader)

SECTIONS
{
	. = 1M  ;

	.text :
	{
		*(.text)
	}

	.data :
	{
        start_ctors = .;
        KEEP(*( .init_array ));
        KEEP(*(SORT_BY_INIT_PRIORITY( .init_array.* )));
        end_ctors = .;

		*(.data)
	}

	.bss :
	{
		*(.bss)
	}
}
