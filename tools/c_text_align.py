"""Trim one verified compiler padding word so a C function can start 4 mod 8."""
import os
import struct
from pathlib import Path


def trim_four_aligned_function(path, name, size):
    """Keep exactly SIZE C bytes; reject anything except one zero compiler alignment word.

    The stock checker must have reported MATCH before this function is called. Only the ELF
    section header changes: no C instruction, symbol, relocation, or game byte is rewritten.
    """
    from elftools.elf.elffile import ELFFile
    from elftools.elf.relocation import RelocationSection

    path = Path(path)
    data = bytearray(path.read_bytes())
    if data[:6] != b"\x7fELF\x01\x01" or size % 8 != 4:
        raise ValueError("requires little-endian ELF32 and a 4-mod-8 function size")
    section_headers = struct.unpack_from("<I", data, 32)[0]
    header_size = struct.unpack_from("<H", data, 46)[0]
    if header_size != 40:
        raise ValueError("not an ELF32 section-header table")

    with path.open("rb") as stream:
        elf = ELFFile(stream)
        if elf["e_machine"] != "EM_MIPS":
            raise ValueError("not a MIPS compiler object")
        sections = list(elf.iter_sections())
        if section_headers + len(sections) * header_size > len(data):
            raise ValueError("section headers extend beyond the object")
        index = next((i for i, section in enumerate(sections) if section.name == ".text"), None)
        if index is None:
            raise ValueError("no .text section")
        code = sections[index]
        if code["sh_addralign"] != 8 or code["sh_size"] != size + 4 or code.data()[size:] != b"\0" * 4:
            raise ValueError(".text is not one function plus one zero alignment word")
        if any(section["sh_flags"] & 2 and section["sh_size"] and section.name != ".text"
               for section in sections):
            raise ValueError("object has other allocated data")
        symbols = elf.get_section_by_name(".symtab")
        if symbols is None:
            raise ValueError("no symbol table")
        defined = list(symbols.iter_symbols())
        functions = [symbol for symbol in defined
                     if symbol["st_shndx"] == index and symbol["st_info"]["type"] == "STT_FUNC"]
        if len(functions) != 1 or functions[0].name != name or functions[0]["st_value"] != 0 \
                or functions[0]["st_size"] != size:
            raise ValueError(".text is not exactly the checked function")
        if any(symbol.name and symbol["st_shndx"] == index and symbol["st_value"] >= size
               for symbol in defined):
            raise ValueError("symbol in the alignment word")
        for section in sections:
            if isinstance(section, RelocationSection) and section["sh_info"] == index:
                if any(relocation["r_offset"] >= size for relocation in section.iter_relocations()):
                    raise ValueError("relocation in the alignment word")

    header = section_headers + index * header_size
    if header + 40 > len(data) or struct.unpack_from("<I", data, header + 20)[0] != size + 4 \
            or struct.unpack_from("<I", data, header + 32)[0] != 8:
        raise ValueError("invalid .text section header")
    struct.pack_into("<I", data, header + 20, size)
    struct.pack_into("<I", data, header + 32, 4)
    temporary = path.with_name(path.name + ".align4.tmp")
    temporary.write_bytes(data)
    try:
        with temporary.open("rb") as stream:
            code = ELFFile(stream).get_section_by_name(".text")
            if code["sh_size"] != size or code["sh_addralign"] != 4:
                raise ValueError("patched .text metadata did not round-trip")
        os.replace(temporary, path)
    finally:
        if temporary.exists():
            temporary.unlink()
