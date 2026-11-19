/* functional: high. State machine of a spark-emitter effect (sibling of func_L01_0046BF78): state 0 emits c[0x13] sparks around its position each frame and, every 10th frame of the global counter, an extra particle burst via func_003D4D00; state 1 drifts, fades and flickers; frees itself when its life runs out. */
typedef struct {
    u8 zero[16];
    s32 w10;
    s32 w14;
    u8 b18;
    u8 b19;
    s16 h1A;
    f32 f1C;
    s32 w20;
} Burst_46EEA0;

extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003C4C18(void *, f32);
extern s32 func_0013D3E0(void);
extern void func_003D4D00(void *, s32, void *, void *, f32);
extern u8 D_001A4BE0[];
extern s32 D_L01_001DFB40;
extern u8 *D_L01_00221180[];
extern u8 *D_L01_001E0278;

void func_L01_0046EEA0(u8 *o) {
    u8 *c = o + 0x20;
    vu0_v4 t;
    Burst_46EEA0 b;
    f32 f;
    f32 sc;
    s32 i;
    s32 r;
    s32 hero;

    if (c[0x14] == 0) {
        i = 0;
        if (c[0x13] != 0) {
            do {
                t = *(vu0_v4 *)(o + 0x10);
                func_003C4C18(&t, 0.05f);
                sc = 1.0f;
                if (*(s16 *)(o + 0xA) < 8) {
                    sc = (f32)*(s16 *)(o + 0xA) * 0.125f;
                }
                i++;
                func_L01_0046ECB8(&t, 0, 1, *(s16 *)(c + 0x10), c[0x13], c[0x15], *(s32 *)(c + 0x18), *(f32 *)(c + 0x1C), sc);
            } while (i < c[0x13]);
        }
        if (func_0038CB00((s16 *)(o + 0xA)) != 0) {
            func_003CD250((Obj *)o);
        }
        hero = *(s32 *)(D_001A4BE0 + 0x25C0);
        r = D_L01_001DFB40 + c[0x17];
        b.w10 = hero;
        b.w14 = 0x10000;
        b.b18 = 2;
        b.b19 = 1;
        b.h1A = 0x820;
        b.f1C = 1.0f;
        b.w20 = 0;
        qzero(b.zero);
        if (r % 10 == 0) {
            func_003D4D00(o + 0x10, 0x10, (void *)hero, &b, 0.2f);
        }
    } else if (c[0x14] == 1) {
        vec_add_ab(o + 0x10, o + 0x10, o + 0x20);
        f = ((f32)c[0x15] - (f32)*(s16 *)(o + 0xA)) / (f32)c[0x15];
        *(s32 *)(o + 4) = func_0038DBD8((c[0x16] << 24) | 0x4060, 0x8FAFFF, f);
        if (f < 0.6f) {
            *(f32 *)(o + 0xC) = *(f32 *)(o + 0xC) + 10836.001f;
        } else {
            *(f32 *)(o + 0xC) = *(f32 *)(o + 0xC) - 20160.0f;
        }
        r = func_0013D3E0();
        o[2] = D_L01_00221180[0][r & 7];
        if (((o - D_L01_001E0278) >> 6) & 1) {
            o[8] = o[8] + 1;
        } else {
            o[8] = o[8] - 1;
        }
        if (func_0038CB00((s16 *)(o + 0xA)) != 0) {
            func_003CD250((Obj *)o);
        }
    }
}
