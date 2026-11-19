/* functional: high. Same table walk as func_L39_006CC648 but kinds read s32 at 0x18 (kind 1) and 0x15C..0x178 (kinds 2-9); only codegen differs. */
typedef struct E_0047F0C0 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
} E_0047F0C0;
extern E_0047F0C0 D_L39_0047F0C0[];

void func_L39_006CC798(s32 *dst, u8 *src) {
    s32 i;
    u32 v;
    u32 mask;
    s32 shift;
    s32 b;

    for (i = 0; i < 29; i++) {
        v = 0xFFFFFF;
        switch (D_L39_0047F0C0[i].f4) {
        case 1: v = *(s32 *)(src + 0x18); break;
        case 2: v = *(s32 *)(src + 0x15C); break;
        case 3: v = *(s32 *)(src + 0x160); break;
        case 4: v = *(s32 *)(src + 0x164); break;
        case 5: v = *(s32 *)(src + 0x168); break;
        case 6: v = *(s32 *)(src + 0x16C); break;
        case 7: v = *(s32 *)(src + 0x170); break;
        case 8: v = *(s32 *)(src + 0x174); break;
        case 9: v = *(s32 *)(src + 0x178); break;
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
