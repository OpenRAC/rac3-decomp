/* functional: high. Written from the PAL assembly (no draft). Phoenix controller update: state 0 registers the object's parts (func_L01_0044ED88) and links each of the 12 slot entries whose class is 0x18DD or 0x18EB to the matching sub-block; the rest of the time it chooses the next state (9, 3 or 0xD) from the game mode D_001D545C (== 3 or not), flag bytes D_00142CBE/D_00142754, bit masks in D_00142C14/D_00142C18, D_001426F4 and a height compare, calling the helper routines. */
/* localdecomp:start func_L03_00398500 */
extern u8 *D_001DF99C;
extern s32 D_001D545C;
extern u8 D_00142CBE[];
extern u32 D_00142C14[];
extern u8 D_00142754[];
extern u32 D_00142C18[];
extern u8 D_001426F4[];
extern f32 D_001A4C64;
extern void func_L01_0044ED88(void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_L01_0044F888(void *, s32, s32, void *, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L03_00398D50(void *);
extern void func_L03_00398DA0(void *, s32, s32);
extern void func_L03_00398A78(void *);
extern void func_L03_00398760(void *);
extern void func_L03_00398BF0(void *);
void func_L03_00398500(u8 *o) {
    u8 *v, *e, *end, *t, *p;
    s32 cls;
    if (o[0x20] != 0) return;
    v = *(u8 **)(o + 0x68);
    *(f32 *)(v + 0x4E0) = *(f32 *)(o + 0x14);
    func_L01_0044ED88(o, v, 0xC, *(s32 *)(v + 0x4C4), *(s32 *)(v + 0x4C0), -1, 7, 0);
    end = v + 0x3C0;
    e = v;
    do {
        if (e[0x4C] == 0) {
            t = D_001DF99C + (*(s16 *)(e + 0x48) << 8);
            cls = *(s16 *)(t + 0xAA);
            if (cls == 0x18DD || cls == 0x18EB) {
                p = *(u8 **)(t + 0x68);
                func_L01_0044F888(v, 0, *(s16 *)(e + 0x48), v + (p[0] << 7) + 0x3C0 + (p[1] << 5), 0x80);
            }
        }
        e += 0x50;
    } while (e < end);
    if (D_001D545C == 3) {
        s32 gotoA = 0;
        if (D_00142CBE[0] != 0 && (D_00142C14[0] & 0x400000) == 0) gotoA = 1;
        else if (D_00142754[0] != 0 && (D_00142C18[0] & 0x1000000) == 0) gotoA = 1;
        if (gotoA) {
            func_L03_00398D50(o);
            func_L01_004450F0(o, 9, -1);
        } else {
            func_L03_00398DA0(o, 0, -1);
            func_L03_00398DA0(o, 1, -1);
            func_L01_004450F0(o, 1, -1);
        }
        *(s32 *)(v + 0x4E8) = -1;
        *(s16 *)(v + 0x4EC) = -1;
    } else if (D_001426F4[0] != 0) {
        func_L03_00398A78(o);
        if (D_001A4C64 < *(f32 *)(o + 0x14)) {
            func_L03_00398DA0(o, 0, 1);
            func_L03_00398DA0(o, 1, -1);
            func_L01_004450F0(o, 3, -1);
        } else {
            func_L03_00398D50(o);
            func_L01_004450F0(o, 9, -1);
        }
    } else {
        func_L03_00398760(o);
        func_L03_00398BF0(o);
        func_L01_004450F0(o, 0xD, -1);
    }
}
/* localdecomp:end func_L03_00398500 */
