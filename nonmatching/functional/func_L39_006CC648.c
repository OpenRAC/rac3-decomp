/* functional: high. Table-driven (D_L39_0047F0C0, 29 entries) field extractor: kind 1-3 read u16 at 0x20/22/24, 4-9 s32 at 0x28..0x3C; same loads, mask/shift and stores as retail; only register allocation/loop shape differs. */
typedef struct E_0047F0C0 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
} E_0047F0C0;
extern E_0047F0C0 D_L39_0047F0C0[];

void func_L39_006CC648(s32 *dst, u8 *src) {
    s32 i;
    u32 v;
    u32 mask;
    s32 shift;
    s32 b;

    for (i = 0; i < 29; i++) {
        v = 0xFFFFFF;
        switch (D_L39_0047F0C0[i].f4) {
        case 1: v = *(u16 *)(src + 0x20); break;
        case 2: v = *(u16 *)(src + 0x22); break;
        case 3: v = *(u16 *)(src + 0x24); break;
        case 4: v = *(s32 *)(src + 0x28); break;
        case 5: v = *(s32 *)(src + 0x2C); break;
        case 6: v = *(s32 *)(src + 0x30); break;
        case 7: v = *(s32 *)(src + 0x34); break;
        case 8: v = *(s32 *)(src + 0x38); break;
        case 9: v = *(s32 *)(src + 0x3C); break;
        }
        if (v != 0xFFFFFF) {
            mask = D_L39_0047F0C0[i].f8;
            shift = -1;
            for (b = 0; b < 32; b++) {
                if ((((long)(u32)D_L39_0047F0C0[i].f8 >> b) & 1) != 0) {
                    shift = b;
                    break;
                }
            }
            if (shift >= 0) {
                dst[D_L39_0047F0C0[i].f0] = (s32)((v & mask) >> shift);
            }
        } else {
            dst[D_L39_0047F0C0[i].f0] = 0;
        }
    }
}
