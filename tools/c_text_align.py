"""Trim one verified compiler padding word so a C function can start 4 mod 8."""
import os
import struct
from pathlib import Path


def _slice(data, offset, size):
    if offset < 0 or size < 0 or offset + size > len(data):
        raise ValueError("ELF section extends beyond the object")
    return data[offset:offset + size]


def _name(strings, offset):
    if offset >= len(strings):
        raise ValueError("invalid ELF string offset")
    end = strings.find(b"\0", offset)
    if end < 0:
        raise ValueError("unterminated ELF string")
    return strings[offset:end].decode("ascii")


def trim_four_aligned_function(path, name, size):
    """Keep exactly SIZE C bytes; reject anything except one zero compiler alignment word.

    The stock checker must report MATCH first. Only the ELF section header changes: no C
    instruction, symbol, relocation, or game byte is rewritten.
    """
    path = Path(path)
    data = bytearray(path.read_bytes())
    if len(data) < 52 or data[:7] != b"\x7fELF\x01\x01\x01" or size % 8 != 4:
        raise ValueError("requires little-endian ELF32 and a 4-mod-8 function size")
    if struct.unpack_from("<HH", data, 16) != (1, 8):
        raise ValueError("not a relocatable MIPS compiler object")
    section_headers = struct.unpack_from("<I", data, 32)[0]
    header_size, count, names_index = struct.unpack_from("<HHH", data, 46)
    if header_size != 40 or not count or names_index >= count:
        raise ValueError("not an ELF32 section-header table")
    _slice(data, section_headers, count * header_size)
    sections = [struct.unpack_from("<IIIIIIIIII", data, section_headers + i * header_size)
                for i in range(count)]
    names_section = sections[names_index]
    if names_section[1] != 3:
        raise ValueError("no section-name string table")
    names = _slice(data, names_section[4], names_section[5])
    named = [(_name(names, section[0]), index, section) for index, section in enumerate(sections)]
    text_sections = [(index, section) for section_name, index, section in named if section_name == ".text"]
    symbol_sections = [section for section_name, _, section in named if section_name == ".symtab"]
    if len(text_sections) != 1 or len(symbol_sections) != 1:
        raise ValueError("requires one .text and one .symtab section")
    text_index, code = text_sections[0]
    if code[1] != 1 or (code[2] & 6) != 6 or code[8] != 8 or code[5] != size + 4 \
            or _slice(data, code[4] + size, 4) != b"\0" * 4:
        raise ValueError(".text is not one function plus one zero alignment word")
    if any(section[2] & 2 and section[5] and index != text_index for _, index, section in named):
        raise ValueError("object has other allocated data")

    symbols = symbol_sections[0]
    if symbols[1] != 2 or symbols[9] != 16 or symbols[5] % 16 or symbols[6] >= count:
        raise ValueError("invalid ELF symbol table")
    strings_section = sections[symbols[6]]
    if strings_section[1] != 3:
        raise ValueError("invalid symbol-name string table")
    strings = _slice(data, strings_section[4], strings_section[5])
    _slice(data, symbols[4], symbols[5])
    functions = []
    for offset in range(symbols[4], symbols[4] + symbols[5], 16):
        string_at, value, width, info, _, section_index = struct.unpack_from("<IIIBBH", data, offset)
        if section_index != text_index:
            continue
        symbol_name = _name(strings, string_at)
        if symbol_name and value >= size:
            raise ValueError("symbol in the alignment word")
        if (info & 15) == 2:
            functions.append((symbol_name, value, width))
    if functions != [(name, 0, size)]:
        raise ValueError(".text is not exactly the checked function")

    for _, _, section in named:
        if section[1] not in (4, 9) or section[7] != text_index:
            continue
        record_size = 12 if section[1] == 4 else 8
        if section[9] != record_size or section[5] % record_size:
            raise ValueError("invalid .text relocations")
        _slice(data, section[4], section[5])
        for offset in range(section[4], section[4] + section[5], record_size):
            if struct.unpack_from("<I", data, offset)[0] >= size:
                raise ValueError("relocation in the alignment word")

    header = section_headers + text_index * header_size
    struct.pack_into("<I", data, header + 20, size)
    struct.pack_into("<I", data, header + 32, 4)
    temporary = path.with_name(path.name + ".align4.tmp")
    temporary.write_bytes(data)
    try:
        verified = temporary.read_bytes()
        if struct.unpack_from("<I", verified, header + 20)[0] != size or \
                struct.unpack_from("<I", verified, header + 32)[0] != 4:
            raise ValueError("patched .text metadata did not round-trip")
        os.replace(temporary, path)
    finally:
        if temporary.exists():
            temporary.unlink()
