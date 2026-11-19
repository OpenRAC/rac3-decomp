/* functional: high. near-miss (14 words regalloc) */
/* localdecomp:start func_L07_003BA970 */
extern u8 *D_L07_001DF41C;
extern u8 *D_L07_001DF420;
void func_L07_003BA970(u8 *obj) {
    extern void func_L07_003A8D70(u8 *);
    extern void func_L07_003B94E0(u8 *);
    extern void func_L07_003BCD80(u8 *);
    extern void func_L07_003C86D0(u8 *);
    extern void func_L07_003BE368(u8 *);
    extern void func_L07_003B0530(u8 *);
    extern void func_L07_00351148(u8 *);
    extern void func_L07_003CCDF8(u8 *);
    extern void func_L07_003D2BE0(u8 *);
    extern void func_L07_003B98E0(u8 *);
    extern void func_L07_003E34D8(u8 *);
    extern void func_L01_00459C50(s32, u8 *);
    extern void func_L01_004AA760(s32, u8 *);
    extern void func_L01_004450F0(u8 *, s32, s32);
    u8 *state = *(u8 **)(obj + 0x68);
    u8 *m;
    state[0xAE] = 0;
    for (m = D_L07_001DF41C; m < D_L07_001DF420; m += 0x100) {
        if (m[0xB0] == *(s32 *)(state + 0x4C)) continue;
        switch (*(s16 *)(m + 0xAA)) {
        case 0x1982: func_L07_003A8D70(m); break;
        case 0x1A4A: func_L07_003B94E0(m); break;
        case 0x19D2: case 0x1A85: case 0x1D88: func_L07_003BCD80(m); break;
        case 0x19BD: case 0x1ADB: case 0x1D8A: func_L07_003C86D0(m); break;
        case 0x19BE: case 0x1A9B: case 0x1D89: func_L07_003BE368(m); break;
        case 0x19DA: func_L07_003B0530(m); break;
        case 0x161E: func_L07_00351148(m); break;
        case 0x1769: case 0x1B36: case 0x1D8B: func_L07_003CCDF8(m); break;
        case 0x1C34: func_L07_003D2BE0(m); break;
        case 0x1A58: func_L07_003B98E0(m); break;
        case 0x1E26: func_L07_003E34D8(m); break;
        }
    }
    if (state[0xB0]) func_L01_00459C50(10, obj);
    func_L01_004AA760(0, obj);
    func_L01_004AA760(1, obj);
    func_L01_004450F0(obj, 0, -1);
}
/* localdecomp:end func_L07_003BA970 */
