/* functional: high. Registers a loaded relocation table in slot `index` (data base, entry table at table+4, pointer base after count*8 bytes), then for each 8-byte row whose target (base + ((row>>2)&0x3FFC)) has a nonzero byte at +3, clears the row's low bits (value & 0xFFFF000F). Draft verified against PAL asm; reloads of the slot tables each iteration are kept. */
extern void *D_001D55D0[];
extern u32 *D_001D55D8[];
extern u8 *D_001D55E0[];

void func_0038E1F8(s32 index, void *data, s32 *table)
{
    s32 count = *table;
    s32 i;

    D_001D55D0[index] = data;
    D_001D55D8[index] = (u32 *)(table + 1);
    D_001D55E0[index] = (u8 *)(table + 1) + count * 8;
    for (i = 0; i < count; i++) {
        u32 *row = D_001D55D8[index] + i * 2;
        u32 value = *row;
        u8 *ptr = D_001D55E0[index] + ((value >> 2) & 0x3FFC);
        if (ptr != 0 && ptr[3] != 0) {
            *row = value & 0xFFFF000F;
        }
    }
}
